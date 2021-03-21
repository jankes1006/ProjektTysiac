object Form1: TForm1
  Left = 222
  Top = 142
  Width = 1246
  Height = 666
  Caption = 'Tysiac - rozgrywka'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object graczK1: TImage
    Left = 240
    Top = 440
    Width = 73
    Height = 97
    OnClick = graczK1Click
  end
  object graczK2: TImage
    Left = 312
    Top = 440
    Width = 73
    Height = 97
    OnClick = graczK2Click
  end
  object graczK3: TImage
    Left = 384
    Top = 440
    Width = 73
    Height = 97
    OnClick = graczK3Click
  end
  object graczK4: TImage
    Left = 456
    Top = 440
    Width = 73
    Height = 97
    OnClick = graczK4Click
  end
  object graczK5: TImage
    Left = 528
    Top = 440
    Width = 73
    Height = 97
    OnClick = graczK5Click
  end
  object graczK6: TImage
    Left = 600
    Top = 440
    Width = 73
    Height = 97
    OnClick = graczK6Click
  end
  object graczK7: TImage
    Left = 672
    Top = 440
    Width = 73
    Height = 97
    OnClick = graczK7Click
  end
  object graczK8: TImage
    Left = 744
    Top = 440
    Width = 73
    Height = 97
    OnClick = graczK8Click
  end
  object graczK9: TImage
    Left = 816
    Top = 440
    Width = 73
    Height = 97
    OnClick = graczK9Click
  end
  object graczK10: TImage
    Left = 888
    Top = 440
    Width = 73
    Height = 97
    OnClick = graczK10Click
  end
  object bot1K1: TImage
    Left = 1024
    Top = 240
    Width = 97
    Height = 11
  end
  object bot1K2: TImage
    Left = 1024
    Top = 229
    Width = 97
    Height = 11
  end
  object bot1K3: TImage
    Left = 1024
    Top = 218
    Width = 97
    Height = 11
  end
  object bot1K4: TImage
    Left = 1024
    Top = 207
    Width = 97
    Height = 11
  end
  object bot1K5: TImage
    Left = 1024
    Top = 196
    Width = 97
    Height = 11
  end
  object bot1K6: TImage
    Left = 1024
    Top = 185
    Width = 97
    Height = 11
  end
  object bot1K7: TImage
    Left = 1024
    Top = 174
    Width = 97
    Height = 11
  end
  object bot1K8: TImage
    Left = 1024
    Top = 163
    Width = 97
    Height = 11
  end
  object bot1K9: TImage
    Left = 1024
    Top = 152
    Width = 97
    Height = 11
  end
  object bot1K10: TImage
    Left = 1024
    Top = 80
    Width = 96
    Height = 71
  end
  object bot2K6: TImage
    Left = 72
    Top = 136
    Width = 97
    Height = 11
  end
  object bot2K5: TImage
    Left = 72
    Top = 125
    Width = 97
    Height = 11
  end
  object bot2K4: TImage
    Left = 72
    Top = 114
    Width = 97
    Height = 11
  end
  object bot2K3: TImage
    Left = 72
    Top = 103
    Width = 97
    Height = 11
  end
  object bot2K2: TImage
    Left = 72
    Top = 92
    Width = 97
    Height = 11
  end
  object bot2K1: TImage
    Left = 72
    Top = 80
    Width = 97
    Height = 11
  end
  object bot2K9: TImage
    Left = 72
    Top = 169
    Width = 97
    Height = 11
  end
  object bot2K8: TImage
    Left = 72
    Top = 158
    Width = 97
    Height = 11
  end
  object bot2K7: TImage
    Left = 72
    Top = 147
    Width = 97
    Height = 11
  end
  object bot2K10: TImage
    Left = 72
    Top = 180
    Width = 96
    Height = 71
  end
  object stolK1: TImage
    Left = 448
    Top = 144
    Width = 73
    Height = 97
  end
  object stolK2: TImage
    Left = 520
    Top = 144
    Width = 73
    Height = 97
  end
  object stolK3: TImage
    Left = 592
    Top = 144
    Width = 73
    Height = 97
  end
  object LicytacjaLabel: TLabel
    Left = 392
    Top = 16
    Width = 135
    Height = 25
    Caption = 'Kwota Licytacji:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object KwotaLicytacji: TLabel
    Left = 528
    Top = 16
    Width = 30
    Height = 24
    Caption = '100'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Meldunek: TLabel
    Left = 584
    Top = 16
    Width = 97
    Height = 25
    Caption = 'Meldunek: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object meldunekWartosc: TLabel
    Left = 680
    Top = 16
    Width = 7
    Height = 25
    Caption = '-'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object player1Label: TLabel
    Left = 424
    Top = 408
    Width = 82
    Height = 25
    Alignment = taCenter
    Caption = 'Player 1: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object punktyP1: TLabel
    Left = 560
    Top = 408
    Width = 41
    Height = 25
    Alignment = taCenter
    AutoSize = False
    Caption = '0'
    Color = clAppWorkSpace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object bot1Label: TLabel
    Left = 72
    Top = 264
    Width = 81
    Height = 25
    Caption = 'Bot 1     : '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object punktyB1: TLabel
    Left = 160
    Top = 264
    Width = 41
    Height = 25
    Alignment = taCenter
    AutoSize = False
    Caption = '0'
    Color = clAppWorkSpace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object bot2Label: TLabel
    Left = 1024
    Top = 48
    Width = 81
    Height = 25
    Caption = 'Bot 2     : '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object punktyB2: TLabel
    Left = 1104
    Top = 48
    Width = 41
    Height = 25
    Alignment = taCenter
    AutoSize = False
    Caption = '0'
    Color = clAppWorkSpace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object LicytacjaGraczLabel: TLabel
    Left = 520
    Top = 296
    Width = 82
    Height = 25
    Caption = 'Licytacja:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object zwyciezcaLicytacjiLabel: TLabel
    Left = 392
    Top = 56
    Width = 170
    Height = 25
    Caption = 'Zwyciezca licytacji: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object zwyciezcaLicytacjiKto: TLabel
    Left = 560
    Top = 56
    Width = 7
    Height = 25
    Caption = '-'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object punktyB1Calosc: TLabel
    Left = 208
    Top = 264
    Width = 49
    Height = 25
    Alignment = taCenter
    AutoSize = False
    Caption = '0'
    Color = clActiveCaption
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object punktyP1Calosc: TLabel
    Left = 608
    Top = 408
    Width = 49
    Height = 25
    Alignment = taCenter
    AutoSize = False
    Caption = '0'
    Color = clActiveCaption
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object punktyB2Calosc: TLabel
    Left = 1152
    Top = 48
    Width = 49
    Height = 25
    Alignment = taCenter
    AutoSize = False
    Caption = '0'
    Color = clActiveCaption
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object pasGracz: TButton
    Left = 464
    Top = 336
    Width = 97
    Height = 41
    Caption = 'Pasuj'
    TabOrder = 0
    OnClick = pasGraczClick
  end
  object podbicieGracz: TButton
    Left = 576
    Top = 336
    Width = 97
    Height = 41
    Caption = 'Podbij'
    TabOrder = 1
    OnClick = podbicieGraczClick
  end
  object nastepnaTura: TButton
    Left = 472
    Top = 96
    Width = 137
    Height = 33
    Caption = 'Nastepna Tura'
    TabOrder = 2
    OnClick = FormCreate
  end
end
