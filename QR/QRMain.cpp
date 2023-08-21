/***************************************************************
 * Name:      QRMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Saif Ali Khan ()
 * Created:   2023-08-09
 * Copyright: Saif Ali Khan ()
 * License:
 **************************************************************/

#include "QRMain.h"
#include <wx/msgdlg.h>
#include <climits>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "qrcodegen.hpp"

using std::uint8_t;
using qrcodegen::QrCode;
using qrcodegen::QrSegment;

//(*InternalHeaders(QRFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(QRFrame)
const long QRFrame::ID_STATICTEXT1 = wxNewId();
const long QRFrame::ID_TEXTCTRL1 = wxNewId();
const long QRFrame::ID_TEXTCTRL2 = wxNewId();
const long QRFrame::ID_STATICBITMAP1 = wxNewId();
const long QRFrame::ID_BUTTON1 = wxNewId();
const long QRFrame::ID_STATICTEXT2 = wxNewId();
const long QRFrame::ID_STATICTEXT3 = wxNewId();
const long QRFrame::ID_STATICTEXT4 = wxNewId();
const long QRFrame::ID_STATICTEXT5 = wxNewId();
const long QRFrame::ID_STATICTEXT6 = wxNewId();
const long QRFrame::ID_STATICTEXT7 = wxNewId();
const long QRFrame::ID_PANEL1 = wxNewId();
const long QRFrame::idMenuQuit = wxNewId();
const long QRFrame::idMenuAbout = wxNewId();
//*)

BEGIN_EVENT_TABLE(QRFrame,wxFrame)
    //(*EventTable(QRFrame)
    //*)
END_EVENT_TABLE()

QRFrame::QRFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(QRFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, _("Qr Code Generator by saifcore7"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(663,464));
    SetBackgroundColour(wxColour(35,35,35));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Save File Name"), wxPoint(24,40), wxSize(96,16), 0, _T("ID_STATICTEXT1"));
    StaticText1->SetForegroundColour(wxColour(255,255,255));
    wxFont StaticText1Font(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    txtSavefilename = new wxTextCtrl(this, ID_TEXTCTRL1, _("Qr Code Image0 1"), wxPoint(240,40), wxSize(144,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    txtSavefilename->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
    txtSavefilename->SetBackgroundColour(wxColour(38,38,38));
    wxFont txtSavefilenameFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    txtSavefilename->SetFont(txtSavefilenameFont);
    txtData = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(32,136), wxSize(150,168), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxNullBitmap, wxPoint(224,128), wxSize(175,175), wxBORDER_SIMPLE, _T("ID_STATICBITMAP1"));
    StaticBitmap1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_GRAYTEXT));
    btnGenerate = new wxButton(this, ID_BUTTON1, _("Generate"), wxPoint(168,384), wxSize(96,32), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    btnGenerate->SetForegroundColour(wxColour(255,128,128));
    btnGenerate->SetBackgroundColour(wxColour(41,41,41));
    wxFont btnGenerateFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    btnGenerate->SetFont(btnGenerateFont);
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(448,0), wxSize(216,464), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetBackgroundColour(wxColour(45,45,45));
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Hi there,"), wxPoint(72,160), wxSize(72,23), 0, _T("ID_STATICTEXT2"));
    StaticText2->SetForegroundColour(wxColour(253,253,253));
    wxFont StaticText2Font(14,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("and welcome to my Qr Code"), wxPoint(16,200), wxSize(160,16), 0, _T("ID_STATICTEXT3"));
    StaticText3->SetForegroundColour(wxColour(255,255,255));
    wxFont StaticText3Font(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText3->SetFont(StaticText3Font);
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Generator"), wxPoint(72,232), wxSize(72,18), 0, _T("ID_STATICTEXT4"));
    StaticText4->SetForegroundColour(wxColour(255,255,255));
    wxFont StaticText4Font(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText4->SetFont(StaticText4Font);
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Built in wxWidgets"), wxPoint(88,400), wxSize(104,16), 0, _T("ID_STATICTEXT5"));
    StaticText5->SetForegroundColour(wxColour(255,128,128));
    StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _("using C++"), wxPoint(128,424), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    StaticText6->SetForegroundColour(wxColour(128,128,255));
    StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _("Saif Ali Khan"), wxPoint(48,16), wxSize(128,25), 0, _T("ID_STATICTEXT7"));
    StaticText7->SetForegroundColour(wxColour(0,128,255));
    wxFont StaticText7Font(16,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText7->SetFont(StaticText7Font);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&QRFrame::OnbtnGenerateClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&QRFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&QRFrame::OnAbout);
    //*)
}

QRFrame::~QRFrame()
{
    //(*Destroy(QRFrame)
    //*)
}

void QRFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void QRFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void QRFrame::OnbtnGenerateClick(wxCommandEvent& event)
{
  wxString text = txtData->GetValue();
  const  QrCode::Ecc errCorLv1 = QrCode::Ecc::LOW;
  const QrCode qr = QrCode::encodeText(text.c_str(), errCorLv1);
  const int scale = 10;
  const int size = qr.getSize() * scale;
  const int byteWidth = (size + 7) / 8;
  char bitsChar[size*byteWidth];
  for (int y=0; y<size; y++){
    for (int xByte=0; xByte<byteWidth; xByte++) {
        char bitChar = 0x00;
        if (text != "") {for (int xBit=0; xBit<8; xBit++){
            int x = xByte *8 + xBit;
            int xModule = x / scale;
            int yModule = y / scale;
            bool black = qr.getModule(xModule, yModule);
            bitChar += black << (xBit % 8);
        } }
          bitsChar[y * byteWidth + xByte] = bitChar;
    }

  }
   wxBitmap *bitmap = new wxBitmap(bitsChar, size, size, 1);
   bitmap->SaveFile(txtSavefilename->GetValue() + ".png", wxBITMAP_TYPE_PNG, NULL);

   wxImage img = bitmap->ConvertToImage();
   wxBitmap mm = wxBitmap(img.Scale(160, 160, wxIMAGE_QUALITY_NORMAL));
   StaticBitmap1->SetBitmap(mm);
   this->Refresh();


}
