object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 479
  ClientWidth = 617
  Color = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 48
    Top = 64
    Width = 3
    Height = 13
    Color = clGradientInactiveCaption
    ParentColor = False
  end
  object Label2: TLabel
    Left = 432
    Top = 64
    Width = 158
    Height = 13
    Caption = #1060#1072#1084' '#1057#1091#1072#1085' '#1058#1093#1080#1077#1085'        '#1056#1048'-561220'
  end
  object Label3: TLabel
    Left = 8
    Top = 64
    Width = 28
    Height = 13
    Caption = 'Email:'
  end
  object VirtualStringTree1: TVirtualStringTree
    Left = 0
    Top = 95
    Width = 617
    Height = 384
    AccessibleName = 'Country'
    Align = alBottom
    Header.AutoSizeIndex = 0
    Header.Options = [hoColumnResize, hoDrag, hoShowSortGlyphs, hoVisible]
    TabOrder = 0
    TreeOptions.PaintOptions = [toShowButtons, toShowDropmark, toShowRoot, toShowTreeLines, toShowVertGridLines, toThemeAware, toUseBlendedImages, toFullVertGridLines]
    TreeOptions.SelectionOptions = [toFullRowSelect]
    OnAddToSelection = VirtualStringTree1AddToSelection
    OnGetText = VirtualStringTree1GetText
    Touch.InteractiveGestures = [igPan, igPressAndTap]
    Touch.InteractiveGestureOptions = [igoPanSingleFingerHorizontal, igoPanSingleFingerVertical, igoPanInertia, igoPanGutter, igoParentPassthrough]
    Columns = <
      item
        Position = 0
        Text = 'CustomerID'
        Width = 69
      end
      item
        Position = 1
        Text = 'Name'
        Width = 150
      end
      item
        Position = 2
        Text = 'Address'
        Width = 209
      end
      item
        Position = 3
        Text = 'City'
        Width = 84
      end
      item
        Position = 4
        Text = 'Country'
        Width = 101
      end>
  end
  object Button1: TButton
    Left = 216
    Top = 8
    Width = 185
    Height = 41
    Caption = 'Delete Entry'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 424
    Top = 8
    Width = 185
    Height = 41
    Caption = 'Delete Table'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 8
    Width = 185
    Height = 41
    Caption = 'Show Table'
    TabOrder = 3
    OnClick = Button3Click
  end
end
