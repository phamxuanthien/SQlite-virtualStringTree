//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "sqlite3.h"
#include "Unit1.h"
#include "string.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VirtualTrees"
#pragma resource "*.dfm"

TForm1 *Form1;
sqlite3* Database;
int status;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
VirtualStringTree1->Clear();
sqlite3_open("Customer.db", &Database);
VirtualStringTree1->NodeDataSize = sizeof(TBaseNode);
char *errmsg;
sqlite3_stmt *pStatement;
int result = sqlite3_prepare_v2(Database,"SELECT CustomerID, Name, Address, City, Country FROM main",-1,&pStatement,NULL);
while(true)
{
	result = sqlite3_step(pStatement);
	if(result != SQLITE_ROW) break;

	int n = sqlite3_column_int(pStatement, 0);
	unsigned char *str = (unsigned char *)sqlite3_column_text(pStatement, 1);
	unsigned char *str1 = (unsigned char *)sqlite3_column_text(pStatement, 2);
	unsigned char *str2 = (unsigned char *)sqlite3_column_text(pStatement, 3);
	unsigned char *str3 = (unsigned char *)sqlite3_column_text(pStatement, 4);
	unsigned char *str4 = (unsigned char *)sqlite3_column_text(pStatement, 5);

	PVirtualNode entryNode = (PVirtualNode)VirtualStringTree1->AddChild(VirtualStringTree1->RootNode);
	TBaseNode *nodeData = (TBaseNode*)VirtualStringTree1->GetNodeData(entryNode);
	nodeData->CustomerID = n;
	nodeData->Name = (UnicodeString)(char*)str;
	nodeData->Address = (UnicodeString)(char*)str1;
	nodeData->City = (UnicodeString)(char*)str2;
	nodeData->Country = (UnicodeString)(char*)str3;
}

sqlite3_finalize(pStatement);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
sqlite3_stmt *pStatement;

PVirtualNode selectedNode = VirtualStringTree1->FocusedNode;
TBaseNode *nodeData = (TBaseNode*)VirtualStringTree1->GetNodeData(selectedNode);

int selectedNodeIndex = nodeData->CustomerID;

UnicodeString test = "DELETE FROM main WHERE CustomerID="+IntToStr(selectedNodeIndex);
wchar_t *wc = test.t_str();
char c[100];
wcstombs(c, wc, wcslen(wc)+1);
ShowMessage("An entry was deleted");
sqlite3_finalize(pStatement);
VirtualStringTree1->DeleteNode(selectedNode);
Label1->Caption ="";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
sqlite3_stmt *pStatement;
const char* c = "DELETE FROM main";
int result = sqlite3_prepare_v2(Database,c,-1,&pStatement,NULL);
result = sqlite3_step(pStatement);
ShowMessage("Table was deleted");
sqlite3_finalize(pStatement);
VirtualStringTree1->Clear();
Label1->Caption ="";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::VirtualStringTree1GetText(TBaseVirtualTree *Sender, PVirtualNode Node,
          TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText)

{
TBaseNode *nodeData = (TBaseNode*)Sender->GetNodeData(Node);
switch(Column)
{
	case 0: CellText = nodeData->CustomerID; break;
	case 1: CellText = nodeData->Name; break;
	case 2: CellText = nodeData->Address; break;
	case 3: CellText = nodeData->City; break;
	case 4: CellText = nodeData->Country; break;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::VirtualStringTree1AddToSelection(TBaseVirtualTree *Sender,
		  PVirtualNode Node)
{
sqlite3_stmt *pStatement;
if(!Node) return;

TBaseNode *nodeData = (TBaseNode*)Sender->GetNodeData(Node);

UnicodeString test = "SELECT Email FROM main WHERE CustomerID="+IntToStr(nodeData->CustomerID);
wchar_t *wc = test.t_str();
char c[100];
wcstombs(c, wc, wcslen(wc)+1);

int result = sqlite3_prepare_v2(Database,c,-1,&pStatement,NULL);
result = sqlite3_step(pStatement);
unsigned char *str = (unsigned char *)sqlite3_column_text(pStatement, 0);
unsigned char *str1 = (unsigned char *)sqlite3_column_text(pStatement, 1);
unsigned char *str2 = (unsigned char *)sqlite3_column_text(pStatement, 2);
unsigned char *str3 = (unsigned char *)sqlite3_column_text(pStatement, 3);
Label1->Caption = (UnicodeString)(char*)str;
sqlite3_finalize(pStatement);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
sqlite3_close(Database);
}
//---------------------------------------------------------------------------



