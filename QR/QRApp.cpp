/***************************************************************
 * Name:      QRApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Saif Ali Khan ()
 * Created:   2023-08-09
 * Copyright: Saif Ali Khan ()
 * License:
 **************************************************************/

#include "QRApp.h"

//(*AppHeaders
#include "QRMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(QRApp);

bool QRApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	QRFrame* Frame = new QRFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
