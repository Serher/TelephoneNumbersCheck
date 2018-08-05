object Form1: TForm1
  Left = 862
  Top = 73
  Width = 394
  Height = 722
  Caption = 'Numbers'#39' Check'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 344
    Width = 247
    Height = 19
    Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090' '#1074#1099#1074#1077#1089#1090#1080' '#1074' '#1089#1090#1086#1083#1073#1080#1082' '#1085#1086#1084#1077#1088' :'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 16
    Top = 392
    Width = 118
    Height = 19
    Caption = #1061#1086#1076' '#1074#1099#1087#1086#1083#1085#1077#1085#1080#1103':'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 16
    Top = 304
    Width = 44
    Height = 19
    Caption = #1060#1072#1081#1083' :'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 16
    Top = 8
    Width = 115
    Height = 22
    Caption = #1048#1085#1089#1090#1088#1091#1082#1094#1080#1103' :'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clRed
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 16
    Top = 216
    Width = 87
    Height = 22
    Caption = #1054#1090#1084#1077#1090#1082#1080' :'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clRed
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Memo1: TMemo
    Left = 16
    Top = 416
    Width = 345
    Height = 185
    TabOrder = 3
  end
  object Button1: TButton
    Left = 16
    Top = 616
    Width = 345
    Height = 49
    Caption = #1047#1072#1087#1091#1089#1090#1080#1090#1100' '#1087#1088#1086#1074#1077#1088#1082#1091
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 64
    Top = 304
    Width = 201
    Height = 21
    TabOrder = 1
    OnChange = Edit1Change
  end
  object Button2: TButton
    Left = 280
    Top = 304
    Width = 81
    Height = 25
    Caption = #1054#1090#1082#1088#1099#1090#1100
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button2Click
  end
  object Edit2: TEdit
    Left = 280
    Top = 344
    Width = 81
    Height = 21
    TabOrder = 4
    Text = '10'
  end
  object Memo2: TMemo
    Left = 16
    Top = 32
    Width = 345
    Height = 177
    Lines.Strings = (
      '- '#1047#1072#1088#1072#1085#1077#1077' '#1074' '#1101#1082#1089#1077#1083#1077' '#1074' '#1087#1077#1088#1074#1086#1081' '#1089#1090#1088#1086#1095#1082#1077' '#1082#1072#1078#1076#1086#1075#1086' '#1089#1090#1086#1083#1073#1080#1082#1072' '#1089' '
      #1080#1085#1090#1077#1088#1077#1089#1091#1102#1097#1080#1084#1080' '#1085#1086#1084#1077#1088#1072#1084#1080' '#1087#1086#1089#1090#1072#1074#1080#1090#1100' '#1079#1085#1072#1082' '#1087#1083#1102#1089'.'
      ''
      '- '#1042' '#1087#1077#1088#1074#1086#1081' '#1089#1090#1088#1086#1095#1082#1077' '#1082#1072#1078#1076#1086#1075#1086' '#1089#1090#1086#1083#1073#1080#1082#1072' '#1089' '#1085#1086#1084#1077#1088#1072#1084#1080', '#1082#1086#1090#1086#1088#1099#1077
      #1089#1083#1077#1076#1091#1077#1090' '#1080#1089#1082#1083#1102#1095#1080#1090#1100', '#1087#1086#1089#1090#1072#1074#1080#1090#1100' '#1079#1085#1072#1082' '#1084#1080#1085#1091#1089'.'
      ''
      '- '#1042' '#1087#1088#1086#1075#1088#1072#1084#1084#1077' '#1086#1090#1082#1088#1099#1090#1100' '#1101#1082#1089#1077#1083#1100'-'#1092#1072#1081#1083'.'
      ''
      '- '#1059#1082#1072#1079#1072#1090#1100' '#1085#1086#1084#1077#1088' '#1089#1090#1086#1083#1073#1080#1082#1072', '#1082#1091#1076#1072' '#1073#1091#1076#1077#1090' '#1074#1099#1074#1077#1076#1077#1085' '#1088#1077#1079#1091#1083#1100#1090#1072#1090'. '
      #1044#1086#1083#1078#1077#1085' '#1073#1099#1090#1100' '#1086#1073#1103#1079#1072#1090#1077#1083#1100#1085#1086' '#1087#1086#1089#1083#1077#1076#1085#1080#1084' '#1074' '#1092#1072#1081#1083#1077' '#1080' '#1086#1073#1103#1079#1072#1090#1077#1083#1100#1085#1086' '
      #1087#1091#1089#1090#1099#1084'. '#1055#1086' '#1076#1077#1092#1086#1083#1090#1091' '#1077#1075#1086' '#1085#1086#1084#1077#1088' 10.'
      ''
      '- '#1047#1072#1087#1091#1089#1090#1080#1090#1100' '#1087#1088#1086#1074#1077#1088#1082#1091'.')
    ReadOnly = True
    TabOrder = 5
  end
  object Panel1: TPanel
    Left = 16
    Top = 240
    Width = 113
    Height = 17
    Caption = #1053#1086#1084#1077#1088' '#1076#1091#1073#1083#1080#1088#1091#1077#1090#1089#1103
    Color = clYellow
    TabOrder = 6
  end
  object Panel2: TPanel
    Left = 128
    Top = 240
    Width = 121
    Height = 17
    Caption = #1053#1086#1084#1077#1088' '#1080#1089#1082#1083#1102#1095#1077#1085
    Color = clLime
    TabOrder = 7
  end
  object Panel3: TPanel
    Left = 248
    Top = 240
    Width = 113
    Height = 17
    Caption = #1053#1086#1084#1077#1088' '#1085#1077#1082#1086#1088#1088#1077#1082#1090#1077#1085
    Color = clRed
    TabOrder = 8
  end
  object OpenDialog1: TOpenDialog
    Left = 328
    Top = 376
  end
end
