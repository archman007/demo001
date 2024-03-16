/***************************************************************
 * Name:      demo001Main.h
 * Purpose:   Defines Application Frame
 * Author:    Mr. Arch Brooks (arch@archbrooks.us)
 * Created:   2024-03-16
 * Copyright: Mr. Arch Brooks (https://archbrooks.us)
 * License:
 **************************************************************/

#ifndef DEMO001MAIN_H
#define DEMO001MAIN_H

//(*Headers(demo001Frame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class demo001Frame: public wxFrame
{
    public:

        demo001Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~demo001Frame();

    private:

        //(*Handlers(demo001Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(demo001Frame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(demo001Frame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // DEMO001MAIN_H
