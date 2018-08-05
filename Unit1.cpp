//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------






//---------------------------------------------------------------------------
//----Variant Functions------------------------------------------------------
//---------------------------------------------------------------------------
class ExcelInfo
{
    public:
    Variant vApp;
    Variant vBook;
};
//---------------------------------------------------------------------------
Variant EX_InitApp()
{
    Variant vApp;
    try
    {
        vApp=CreateOleObject("Excel.Application");
    }
    catch(...)
    {
        MessageBox(0, "Ошибка при открытии сервера Excel",
            "Ошибка", MB_OK);
        return 1;
    }
return vApp;
}
//---------------------------------------------------------------------------
void EX_ShowExcel(Variant &vApp)
{
    vApp.OlePropertySet("Visible",true);
}
//---------------------------------------------------------------------------
Variant EX_GetWorkBook(Variant &vApp, AnsiString &vasPath, int nReadOnly = true)
{
    Variant vBook, vBooks = vApp.OlePropertyGet("Workbooks");
    //vasPath = "D:\\Test.xlsx";

    vBooks.OleProcedure("Open", vasPath.c_str(), 0, nReadOnly);
    vBook = vBooks.OlePropertyGet("Item",1);
return vBook;
}
//---------------------------------------------------------------------------

Variant EX_GetSheet(Variant &vBook, int nNumber)
{
    Variant vSheets = vBook.OlePropertyGet("Worksheets");
return vSheets.OlePropertyGet("Item", nNumber);
}
//---------------------------------------------------------------------------
Variant EX_GetCell(Variant &vSheet, int nY, int nX)
{
	return vSheet.OlePropertyGet("Cells").OlePropertyGet("Item",nY,nX);
}
//---------------------------------------------------------------------------
AnsiString EX_GetValue(Variant &vCell)
{
    return VarToStr(vCell);
}
//---------------------------------------------------------------------------
void EX_SetValue(Variant &vSheet, int nY, int nX, char *sValue)
{
    Variant vCell = EX_GetCell(vSheet, nY, nX);
    vCell.OlePropertySet("Value", sValue);
}
//---------------------------------------------------------------------------
void EX_SetValue(Variant &vSheet, int nY, int nX, int nValue)
{
    Variant vCell = EX_GetCell(vSheet, nY, nX);
    vCell.OlePropertySet("Value", nValue);
}
//---------------------------------------------------------------------------
void EX_SetValue(Variant &vCell, char *sValue)
{
    vCell.OlePropertySet("Value", sValue);
}
//---------------------------------------------------------------------------
void EX_SetValue(Variant &vCell, int nValue)
{
    vCell.OlePropertySet("Value", nValue);
}
//---------------------------------------------------------------------------
void EX_SaveFile(Variant &vBook)
{
    vBook.OleProcedure("Save");
}
//---------------------------------------------------------------------------
void EX_CloseExFile(Variant &vApp)
{
    vApp.OleProcedure("Quit");
}
//---------------------------------------------------------------------------
void EX_SetCellColor(Variant &vCell, int nColor) //0-Black, 1-white, ?? 3-R, 4-G, 5-B, 6-Yellow, etc.
{
    vCell.OlePropertyGet("Interior").OlePropertySet("ColorIndex", nColor);
}
//---------------------------------------------------------------------------
ExcelInfo EX_OpenExcelFile(AnsiString &sPath, int nReadOnly = true)
{
    ExcelInfo eResult;
    eResult.vApp = EX_InitApp();
    eResult.vBook = EX_GetWorkBook(eResult.vApp, sPath, nReadOnly);
return eResult;
}
//---------------------------------------------------------------------------
//--End of Variant functions-------------------------------------------------
//---------------------------------------------------------------------------



//------------------------------------------------------------------------------
void LeftDigitsOnly(AnsiString &str)
{
    AnsiString sTemp, sSymb;
    int nLen = str.Length();
    for(int i=1; i<=nLen; i++)
    {
        sSymb = str.SubString(i, 1);
        if(sSymb == "0" || sSymb == "1" || sSymb == "2" || sSymb == "3" || sSymb == "4" || sSymb == "5" || sSymb == "6" || sSymb == "7" || sSymb == "8" || sSymb == "9")
            sTemp += sSymb;
    }
    str = sTemp;
}
//------------------------------------------------------------------------------
int GetIsFixNeed(AnsiString &sNumber)
{
    if(sNumber.SubString(1, 1) == "7")
        return false;
return true;
}
//------------------------------------------------------------------------------
void FixTelNumber(AnsiString &sNumber)
{
    if(GetIsFixNeed(sNumber))
    {
        LeftDigitsOnly(sNumber);

        if(sNumber.SubString(1,1)!= "9" && sNumber.SubString(1,1)!= "4")
            sNumber.Delete(1,1);

        sNumber.Insert("7", 1);
    }
}
//------------------------------------------------------------------------------
int GetIsNumberPassedExcludeColumn(Variant &vSheet, AnsiString &sNumber, int nX)
{
    int nY = 2;
    Variant vCell = EX_GetCell(vSheet, nY, nX);
    AnsiString sValue = EX_GetValue(vCell);
    while(sValue != "")
    {
        FixTelNumber(sValue);
        if(sValue.Length()!=11)
            EX_SetCellColor(vCell, 3);// ??
        else
        {
            EX_SetValue(vCell, sValue.c_str());
            if(sNumber == sValue)
                return false;
        }
        vCell = EX_GetCell(vSheet, ++nY, nX);
        sValue = EX_GetValue(vCell);
    }
return nY;
}
//------------------------------------------------------------------------------
void CheckNumber(Variant &vSheet, AnsiString &sNumber, int nResultColumn, Variant &vNumCell)
{
    AnsiString sValue;
    int nY=1;
    for(int nX = 1; nX<nResultColumn; nX++)//Move on X-axis
    {
        sValue = EX_GetValue(EX_GetCell(vSheet, nY, nX));
        if(sValue == "-")
        {
            if(!GetIsNumberPassedExcludeColumn(vSheet, sNumber, nX))
            {
                EX_SetCellColor(vNumCell, 4);// Зеленый
                return;
            }
        }
    }

    int nFreeY = GetIsNumberPassedExcludeColumn(vSheet, sNumber, nResultColumn);
    if(nFreeY)
        EX_SetValue(vSheet, nFreeY, nResultColumn, sNumber.c_str());
    else
        EX_SetCellColor(vNumCell, 6);// Желтый
}
//------------------------------------------------------------------------------
void CheckColumn(Variant &vSheet, int nX, int nResultColumn)
{
    int nY = 2;
    Variant vCell = EX_GetCell(vSheet, nY, nX);
    AnsiString sValue = EX_GetValue(vCell);
    while(sValue != "")
    {
        FixTelNumber(sValue);
        if(sValue.Length()!=11)
            EX_SetCellColor(vCell, 3);// Красный
        else
        {
            EX_SetValue(vCell, sValue.c_str());
            CheckNumber(vSheet, sValue, nResultColumn, vCell);
        }
        vCell = EX_GetCell(vSheet, ++nY, nX);
        sValue = EX_GetValue(vCell);
    }
}
//------------------------------------------------------------------------------















//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    if(Form1->OpenDialog1->Execute())
    {
        Edit1->Text = Form1->OpenDialog1->FileName;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    if(Edit1->Text == "")
        return;

    Memo1->Lines->Add("Открытие файла");
    ExcelInfo eiFile = EX_OpenExcelFile(Edit1->Text, false);
    //EX_ShowExcel(eiFile.vApp);

    Memo1->Lines->Add("Файл открыт");

    Variant vBook = eiFile.vBook;
    Variant vSheet = EX_GetSheet(vBook, 1);
    int nResultColumn = StrToInt(Edit2->Text);

    Memo1->Lines->Add("Проверка начата");
    Memo1->Lines->Add("Это может занять несколько минут...");

    AnsiString sValue;
    for(int nX = 1; nX<nResultColumn; nX++)
    {
        sValue = EX_GetValue(EX_GetCell(vSheet, 1, nX));
        if(sValue == "+")
        {
            CheckColumn(vSheet, nX, nResultColumn);
            Memo1->Lines->Add("Проверен столбик номер " + IntToStr(nX));
        }
    }

    Memo1->Lines->Add("Проверка файла закончена");
    Memo1->Lines->Add("Результат в столбике номер " + IntToStr(nResultColumn));

    EX_SaveFile(vBook);
    EX_CloseExFile(eiFile.vApp);

    Memo1->Lines->Add("Файл сохранен");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Change(TObject *Sender)
{
    AnsiString sSub, vasPath = Edit1->Text;
    sSub = "\\";
    sSub.Insert("\\", 1);
    if(AnsiPos(sSub, vasPath))
        return;
        
    int nLen = vasPath.Length();
    while(nLen>1)
    {
        if(vasPath.SubString(nLen, 1) == '\\')
            vasPath.Insert('\\', nLen);
        nLen--;
    }
    Edit1->Text = vasPath;
}
//---------------------------------------------------------------------------


