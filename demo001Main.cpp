/***************************************************************
 * Name:      demo001Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Mr. Arch Brooks (arch@archbrooks.us)
 * Created:   2024-03-16
 * Copyright: Mr. Arch Brooks (https://archbrooks.us)
 * License:
 **************************************************************/

#include "demo001Main.h"
#include <wx/msgdlg.h>
#include "dlgShowDir.h"

//(*InternalHeaders(demo001Frame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

// helper functions
enum wxbuildinfoformat
{
    short_f,
    long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f)
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

//(*IdInit(demo001Frame)
const long demo001Frame::idShowDir = wxNewId();
const long demo001Frame::idMenuQuit = wxNewId();
const long demo001Frame::idMenuAbout = wxNewId();
const long demo001Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(demo001Frame, wxFrame)
//(*EventTable(demo001Frame)
//*)
END_EVENT_TABLE()

demo001Frame::demo001Frame(wxWindow *parent, wxWindowID id)
{
    //(*Initialize(demo001Frame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    menShowDir = new wxMenuItem(Menu1, idShowDir, _("Show Dir\tAlt-S"), _("Show Directory"), wxITEM_NORMAL);
    Menu1->Append(menShowDir);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(idShowDir,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&demo001Frame::OnmenShowDirSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&demo001Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&demo001Frame::OnAbout);
    //*)
}

demo001Frame::~demo001Frame()
{
    //(*Destroy(demo001Frame)
    //*)
}

void demo001Frame::OnQuit(wxCommandEvent &event)
{
    Close();
}

void demo001Frame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void demo001Frame::OnmenShowDirSelected(wxCommandEvent& event)
{
    dlgShowDir dlg(NULL, wxID_ANY);
    if (dlg.ShowModal() == wxID_OK)
    {

    }
}
