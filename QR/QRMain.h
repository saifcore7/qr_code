/***************************************************************
 * Name:      QRMain.h
 * Purpose:   Defines Application Frame
 * Author:    Saif Ali Khan ()
 * Created:   2023-08-09
 * Copyright: Saif Ali Khan ()
 * License:
 **************************************************************/

#ifndef QRMAIN_H
#define QRMAIN_H

//(*Headers(QRFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class QRFrame: public wxFrame
{
    public:

        QRFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~QRFrame();

    private:

        //(*Handlers(QRFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnbtnGenerateClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(QRFrame)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICBITMAP1;
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT7;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        //*)

        //(*Declarations(QRFrame)
        wxButton* btnGenerate;
        wxPanel* Panel1;
        wxStaticBitmap* StaticBitmap1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText6;
        wxStaticText* StaticText7;
        wxTextCtrl* txtData;
        wxTextCtrl* txtSavefilename;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // QRMAIN_H
