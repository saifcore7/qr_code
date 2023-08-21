/***************************************************************
 * Name:      QRApp.h
 * Purpose:   Defines Application Class
 * Author:    Saif Ali Khan ()
 * Created:   2023-08-09
 * Copyright: Saif Ali Khan ()
 * License:
 **************************************************************/

#ifndef QRAPP_H
#define QRAPP_H

#include <wx/app.h>

class QRApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // QRAPP_H
