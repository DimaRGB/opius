object MainForm: TMainForm
  Left = 0
  Top = 219
  Caption = 'Flight Data Processing'
  ClientHeight = 362
  ClientWidth = 784
  Color = clBtnFace
  Constraints.MinHeight = 400
  Constraints.MinWidth = 800
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  WindowState = wsMaximized
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object ListBox2: TListBox
    Left = 246
    Top = 200
    Width = 121
    Height = 97
    Align = alCustom
    ItemHeight = 13
    TabOrder = 0
  end
  object Pages: TPageControl
    Left = 0
    Top = 24
    Width = 784
    Height = 338
    ActivePage = TabSheet5
    Align = alClient
    Constraints.MinWidth = 50
    Style = tsFlatButtons
    TabOrder = 1
    object TabSheet1: TTabSheet
      BorderWidth = 1
      Caption = 'Flight Data'
      ImageIndex = 1
      object atrMemo: TMemo
        Left = 0
        Top = 0
        Width = 774
        Height = 305
        Align = alClient
        BorderStyle = bsNone
        Color = clInfoBk
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clInfoText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Lines.Strings = (
          'Choose files to open using '#39'Open..'#39' buttons'
          'and press '#39'Processing'#39' button to launch Flight Data Processing.'
          ''
          #1042#1099#1073#1077#1088#1080#1090#1077' '#1092#1072#1081#1083#1099' '#1076#1083#1103' '#1086#1090#1082#1088#1099#1090#1080#1103' '#1089' '#1087#1086#1084#1086#1097#1100#1102' '#1082#1085#1086#1087#1086#1082' '#39'Open..'#39
          
            #1080' '#1085#1072#1078#1084#1080#1090#1077' '#1082#1085#1086#1087#1082#1091' '#39'Processing'#39' '#1076#1083#1103' '#1079#1072#1087#1091#1089#1082#1072' '#1054#1073#1088#1072#1073#1086#1090#1082#1080' '#1055#1086#1083#1077#1090#1085#1086#1081' '#1048#1085#1092 +
            #1086#1088#1084#1072#1094#1080#1080'.'
          ''
          #1042#1082#1083#1072#1076#1082#1072' '#39'Flight Data'#39' ('#1055#1086#1083#1077#1090#1085#1072#1103' '#1048#1085#1092#1086#1088#1084#1072#1094#1080#1103') '#1089#1086#1076#1077#1088#1078#1080#1090':'
          'File-copy attributes - '#1040#1090#1088#1080#1073#1091#1090#1099' '#1092#1072#1081#1083#1072'-'#1082#1086#1087#1080#1080'; '
          'Flight identification data - '#1054#1087#1086#1079#1085#1072#1074#1072#1090#1077#1083#1100#1085#1099#1077' '#1076#1072#1085#1085#1099#1077';'
          'Flight attributes - '#1040#1090#1088#1080#1073#1091#1090#1099' '#1087#1086#1083#1077#1090#1072';')
        ParentFont = False
        ReadOnly = True
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      BorderWidth = 1
      Caption = 'Parameter Codes'
      ImageIndex = 2
      object Splitter4: TSplitter
        Left = 0
        Top = 30
        Width = 774
        Height = 3
        Cursor = crVSplit
        Align = alTop
        Color = clHighlight
        ParentColor = False
        ResizeStyle = rsUpdate
        ExplicitTop = 33
        ExplicitWidth = 272
      end
      object paramGrid: TStringGrid
        Left = 0
        Top = 33
        Width = 774
        Height = 272
        Align = alClient
        BorderStyle = bsNone
        Color = clBtnFace
        ColCount = 1
        DefaultColWidth = 50
        DefaultRowHeight = 20
        FixedCols = 0
        RowCount = 1
        FixedRows = 0
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSizing, goColSizing]
        TabOrder = 0
        RowHeights = (
          20)
      end
      object paramMemo: TMemo
        Left = 0
        Top = 0
        Width = 774
        Height = 30
        Align = alTop
        BorderStyle = bsNone
        Color = clInfoBk
        Constraints.MinHeight = 30
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clInfoText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Lines.Strings = (
          #1050#1086#1076#1099' '#1087#1072#1088#1072#1084#1077#1090#1088#1086#1074'.'
          #1055#1077#1095#1072#1090#1100' '#1082#1086#1076#1086#1074' '#1087#1072#1088#1072#1084#1077#1090#1088#1086#1074' '#1082#1072#1076#1088#1072' '#1092#1072#1081#1083#1072' '#1082#1086#1087#1080#1080'.')
        ParentFont = False
        ReadOnly = True
        TabOrder = 1
      end
    end
    object TabSheet3: TTabSheet
      BorderWidth = 1
      Caption = 'Analog Parameters'
      ImageIndex = 3
      object Splitter2: TSplitter
        Left = 320
        Top = 0
        Height = 305
        Color = clHighlight
        ParentColor = False
        ResizeStyle = rsUpdate
        ExplicitLeft = 200
      end
      object anlgGrid: TStringGrid
        Left = 323
        Top = 0
        Width = 451
        Height = 305
        Align = alClient
        BorderStyle = bsNone
        ColCount = 1
        DefaultColWidth = 50
        DefaultRowHeight = 20
        FixedCols = 0
        RowCount = 1
        FixedRows = 0
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSizing, goColSizing]
        TabOrder = 0
        RowHeights = (
          20)
      end
      object anlgMemo: TMemo
        Left = 0
        Top = 0
        Width = 320
        Height = 305
        Align = alLeft
        BorderStyle = bsNone
        Color = clInfoBk
        Constraints.MinWidth = 200
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clInfoText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Lines.Strings = (
          #1040#1085#1072#1083#1086#1075#1086#1074#1099#1077' '#1055#1072#1088#1072#1084#1077#1090#1088#1099':'
          #1042#1099#1074#1086#1076' '#1092#1080#1079#1080#1095#1077#1089#1082#1080#1093' '#1079#1085#1072#1095#1077#1085#1080#1081' '
          #1072#1085#1072#1083#1086#1075#1086#1074#1099#1093' '#1087#1072#1088#1072#1084#1077#1090#1088#1086#1074'.')
        ParentFont = False
        ReadOnly = True
        ScrollBars = ssVertical
        TabOrder = 1
      end
    end
    object TabSheet4: TTabSheet
      BorderWidth = 1
      Caption = 'Single Commands'
      ImageIndex = 4
      object Splitter3: TSplitter
        Left = 250
        Top = 0
        Height = 305
        Color = clHighlight
        ParentColor = False
        ResizeStyle = rsUpdate
        ExplicitLeft = 200
        ExplicitTop = 3
      end
      object snglMemo: TMemo
        Left = 0
        Top = 0
        Width = 250
        Height = 305
        Align = alLeft
        BorderStyle = bsNone
        Color = clInfoBk
        Constraints.MinWidth = 200
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clInfoText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Lines.Strings = (
          #1056#1072#1079#1086#1074#1099#1077' '#1050#1086#1084#1072#1085#1076#1099':'
          #1042#1099#1074#1086#1076' '#1079#1085#1072#1095#1077#1085#1080#1081' '#1088#1072#1079#1086#1074#1099#1093' '
          #1082#1086#1084#1072#1085#1076'.')
        ParentFont = False
        ReadOnly = True
        ScrollBars = ssVertical
        TabOrder = 0
      end
      object snglGrid: TStringGrid
        Left = 253
        Top = 0
        Width = 521
        Height = 305
        Align = alClient
        BorderStyle = bsNone
        ColCount = 1
        DefaultColWidth = 50
        DefaultRowHeight = 20
        FixedCols = 0
        RowCount = 1
        FixedRows = 0
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSizing, goColSizing]
        TabOrder = 1
      end
    end
    object TabSheet5: TTabSheet
      BorderWidth = 1
      Caption = 'Graphics'
      ImageIndex = 2
      object Splitter1: TSplitter
        Left = 100
        Top = 0
        Height = 305
        Color = clHighlight
        ParentColor = False
        ResizeStyle = rsUpdate
        ExplicitLeft = 296
        ExplicitTop = 32
      end
      object checkListChannel: TCheckListBox
        Left = 0
        Top = 0
        Width = 100
        Height = 305
        OnClickCheck = checkListChannelClickCheck
        Align = alLeft
        BorderStyle = bsNone
        Color = clInfoBk
        Constraints.MinWidth = 100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clInfoText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object Panel2: TPanel
        Left = 103
        Top = 0
        Width = 671
        Height = 305
        Align = alClient
        BevelOuter = bvNone
        TabOrder = 1
        object Chart: TChart
          Left = 0
          Top = 0
          Width = 671
          Height = 280
          Title.Text.Strings = (
            '')
          View3D = False
          Align = alClient
          BevelOuter = bvNone
          TabOrder = 0
          PrintMargins = (
            15
            33
            15
            33)
          ColorPaletteIndex = 1
        end
        object Panel3: TPanel
          Left = 0
          Top = 280
          Width = 671
          Height = 25
          Align = alBottom
          BevelOuter = bvNone
          TabOrder = 1
          DesignSize = (
            671
            25)
          object Label2: TLabel
            Left = 98
            Top = 4
            Width = 25
            Height = 13
            Caption = 'Scale'
          end
          object Label3: TLabel
            Left = 198
            Top = 4
            Width = 31
            Height = 13
            Caption = 'Offset'
          end
          object ChannelBox: TComboBox
            Left = 6
            Top = 1
            Width = 78
            Height = 22
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -12
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
          end
          object CSpinEdit1: TCSpinEdit
            Left = 124
            Top = 1
            Width = 61
            Height = 22
            TabOrder = 1
          end
          object CSpinEdit2: TCSpinEdit
            Left = 231
            Top = 1
            Width = 59
            Height = 22
            TabOrder = 2
          end
          object Button1: TButton
            Left = 307
            Top = 0
            Width = 39
            Height = 25
            Caption = 'Scale'
            TabOrder = 3
          end
          object Button2: TButton
            Left = 352
            Top = 0
            Width = 50
            Height = 25
            Caption = 'Default'
            TabOrder = 4
          end
          object Button3: TButton
            Left = 608
            Top = 0
            Width = 58
            Height = 25
            Anchors = [akTop, akRight]
            Caption = 'Default all'
            TabOrder = 5
          end
          object Button4: TButton
            Left = 552
            Top = 0
            Width = 50
            Height = 25
            Anchors = [akTop, akRight]
            Caption = 'Scale all'
            TabOrder = 6
          end
        end
      end
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 784
    Height = 24
    Align = alTop
    BevelOuter = bvNone
    Color = clMenu
    ParentBackground = False
    TabOrder = 2
    object fcPanel: TPanel
      Left = 0
      Top = 0
      Width = 392
      Height = 24
      Align = alLeft
      Alignment = taLeftJustify
      BevelOuter = bvNone
      BorderWidth = 4
      BorderStyle = bsSingle
      Caption = 'fcPanel'
      Color = clInfoBk
      Ctl3D = False
      Font.Charset = ANSI_CHARSET
      Font.Color = clHighlight
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentBackground = False
      ParentCtl3D = False
      ParentFont = False
      TabOrder = 0
      DesignSize = (
        390
        22)
      object fcButton: TSpeedButton
        Left = 302
        Top = 0
        Width = 90
        Height = 22
        Anchors = [akTop, akRight]
        Caption = 'Open File-Copy'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        OnClick = openButtonClick
      end
    end
    object cPanel: TPanel
      Left = 392
      Top = 0
      Width = 392
      Height = 24
      Align = alClient
      Alignment = taRightJustify
      BevelOuter = bvNone
      BorderWidth = 4
      BorderStyle = bsSingle
      Caption = 'cPanel'
      Color = clInfoBk
      Ctl3D = False
      Font.Charset = ANSI_CHARSET
      Font.Color = clHighlight
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentBackground = False
      ParentCtl3D = False
      ParentFont = False
      TabOrder = 1
      object cButton: TSpeedButton
        Tag = 1
        Left = 0
        Top = 0
        Width = 90
        Height = 22
        Caption = 'Open Cyclogram'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        OnClick = openButtonClick
      end
    end
  end
  object openDialog: TOpenDialog
    Options = [ofFileMustExist, ofEnableSizing]
    Left = 472
    Top = 24
  end
end
