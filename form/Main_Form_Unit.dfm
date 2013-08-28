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
    ActivePage = TabSheet1
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
        Color = clWhite
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
        Color = clBtnFace
        Constraints.MaxHeight = 50
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
        Left = 200
        Top = 0
        Height = 305
        Color = clHighlight
        ParentColor = False
        ResizeStyle = rsUpdate
      end
      object anlgGrid: TStringGrid
        Left = 203
        Top = 0
        Width = 571
        Height = 305
        Align = alClient
        BorderStyle = bsNone
        ColCount = 1
        DefaultColWidth = 70
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
        Width = 200
        Height = 305
        Align = alLeft
        BorderStyle = bsNone
        Color = clBtnFace
        Constraints.MaxWidth = 350
        Constraints.MinWidth = 100
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
        Color = clBtnFace
        Constraints.MaxWidth = 250
        Constraints.MinWidth = 100
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
        OnMoved = Splitter1Moved
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
        Color = clBtnFace
        Constraints.MinWidth = 100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clInfoText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
        OnClick = checkListChannelClick
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
          Height = 264
          Title.Text.Strings = (
            '')
          View3D = False
          Align = alClient
          BevelOuter = bvNone
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
          PrintMargins = (
            15
            29
            15
            29)
          ColorPaletteIndex = 13
          object add_random_channel: TButton
            Left = 79
            Top = 0
            Width = 66
            Height = 21
            Hint = 'Add random channel to chart'
            Caption = 'Add random'
            ParentShowHint = False
            ShowHint = True
            TabOrder = 0
            OnClick = add_random_channelClick
          end
          object uncheck_all_channels: TButton
            Left = 6
            Top = 0
            Width = 67
            Height = 21
            Hint = 'Uncheck all channels in list'
            Caption = 'Uncheck all'
            ParentShowHint = False
            ShowHint = True
            TabOrder = 1
            OnClick = uncheck_all_channelsClick
          end
        end
        object Panel3: TPanel
          Left = 0
          Top = 264
          Width = 671
          Height = 41
          Align = alBottom
          BevelOuter = bvNone
          TabOrder = 1
          DesignSize = (
            671
            41)
          object channel_scale_n_offset: TGroupBox
            Left = 3
            Top = 1
            Width = 470
            Height = 40
            Anchors = [akLeft, akTop, akRight, akBottom]
            Caption = 'Channel scale and offset'
            TabOrder = 0
            DesignSize = (
              470
              40)
            object Label2: TLabel
              Left = 145
              Top = 16
              Width = 25
              Height = 13
              Anchors = [akTop, akRight, akBottom]
              Caption = 'Scale'
            end
            object Label3: TLabel
              Left = 242
              Top = 16
              Width = 31
              Height = 13
              Anchors = [akTop, akRight, akBottom]
              Caption = 'Offset'
            end
            object ChannelBox: TComboBox
              Left = 3
              Top = 13
              Width = 134
              Height = 22
              Hint = 'Channel to edit'
              Style = csDropDownList
              Anchors = [akLeft, akTop, akRight, akBottom]
              DropDownCount = 22
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              ParentShowHint = False
              ShowHint = True
              TabOrder = 0
              OnChange = ChannelBoxChange
            end
            object scale_edit: TEdit
              Left = 175
              Top = 12
              Width = 61
              Height = 21
              Anchors = [akTop, akRight, akBottom]
              TabOrder = 1
              Text = '1'
              OnEnter = scale_editEnter
              OnKeyPress = scale_editKeyPress
            end
            object offset_edit: TEdit
              Left = 280
              Top = 12
              Width = 50
              Height = 21
              Anchors = [akTop, akRight, akBottom]
              Ctl3D = True
              ParentCtl3D = False
              TabOrder = 2
              Text = '0'
              OnKeyPress = offset_editKeyPress
            end
            object Reset_btn: TBitBtn
              Left = 403
              Top = 12
              Width = 62
              Height = 21
              Hint = 'Reset current channel scale and offset'
              Anchors = [akTop, akRight, akBottom]
              Caption = 'Reset'
              Kind = bkAbort
              NumGlyphs = 2
              ParentShowHint = False
              ShowHint = True
              TabOrder = 3
            end
            object scale_btn: TBitBtn
              Left = 336
              Top = 12
              Width = 65
              Height = 21
              Hint = 'Scale current channle'
              Anchors = [akTop, akRight, akBottom]
              Caption = 'Scale'
              Glyph.Data = {
                DE010000424DDE01000000000000760000002800000024000000120000000100
                0400000000006801000000000000000000001000000000000000000000000000
                80000080000000808000800000008000800080800000C0C0C000808080000000
                FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
                3333333333333333333333330000333333333333333333333333F33333333333
                00003333344333333333333333388F3333333333000033334224333333333333
                338338F3333333330000333422224333333333333833338F3333333300003342
                222224333333333383333338F3333333000034222A22224333333338F338F333
                8F33333300003222A3A2224333333338F3838F338F33333300003A2A333A2224
                33333338F83338F338F33333000033A33333A222433333338333338F338F3333
                0000333333333A222433333333333338F338F33300003333333333A222433333
                333333338F338F33000033333333333A222433333333333338F338F300003333
                33333333A222433333333333338F338F00003333333333333A22433333333333
                3338F38F000033333333333333A223333333333333338F830000333333333333
                333A333333333333333338330000333333333333333333333333333333333333
                0000}
              ModalResult = 6
              NumGlyphs = 2
              ParentShowHint = False
              ShowHint = True
              TabOrder = 4
            end
          end
          object auto_scale_all_btn: TBitBtn
            Tag = 1
            Left = 474
            Top = 12
            Width = 113
            Height = 25
            Hint = 'Change auto scale all channels (ON/OFF)'
            Anchors = [akTop, akRight, akBottom]
            Caption = 'Auto Scale ON'
            Glyph.Data = {
              DE010000424DDE01000000000000760000002800000024000000120000000100
              0400000000006801000000000000000000001000000000000000000000000000
              80000080000000808000800000008000800080800000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3333333333333333333333330000333333333333333333333333F33333333333
              00003333344333333333333333388F3333333333000033334224333333333333
              338338F3333333330000333422224333333333333833338F3333333300003342
              222224333333333383333338F3333333000034222A22224333333338F338F333
              8F33333300003222A3A2224333333338F3838F338F33333300003A2A333A2224
              33333338F83338F338F33333000033A33333A222433333338333338F338F3333
              0000333333333A222433333333333338F338F33300003333333333A222433333
              333333338F338F33000033333333333A222433333333333338F338F300003333
              33333333A222433333333333338F338F00003333333333333A22433333333333
              3338F38F000033333333333333A223333333333333338F830000333333333333
              333A333333333333333338330000333333333333333333333333333333333333
              0000}
            ModalResult = 1
            NumGlyphs = 2
            ParentShowHint = False
            ShowHint = True
            TabOrder = 1
            OnClick = auto_scale_all_btnClick
          end
          object reset_all_btn: TBitBtn
            Left = 590
            Top = 12
            Width = 75
            Height = 25
            Hint = 'Reset all channels scale and offset'
            Anchors = [akTop, akRight, akBottom]
            Caption = 'Reset All'
            Kind = bkAbort
            NumGlyphs = 2
            ParentShowHint = False
            ShowHint = True
            TabOrder = 2
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
        Left = 284
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
        ExplicitLeft = 296
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
        Left = 5
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
