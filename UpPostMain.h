/***************************************************************
 * Name:      UpPostMain.h
 * Purpose:   Defines Application Frame
 * Author:    Mr. Arch Brooks (arch@archbrooks.us)
 * Created:   2024-03-12
 * Copyright: Mr. Arch Brooks (https://archbrooks.us)
 * License:
 **************************************************************/

#ifndef UPPOSTMAIN_H
#define UPPOSTMAIN_H

//(*Headers(UpPostFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

//#include <wx/wx.h>
#include <wx/arrstr.h>
class UpPostFrame: public wxFrame
{
public:

    UpPostFrame(wxWindow* parent,wxWindowID id = -1);
    virtual ~UpPostFrame();
    void ReadFileLines(const wxString& filename);
    void strToFile(std::string, std::string entFfile);
//    std::ifstream file(filename.ToStdString());

private:

    //(*Handlers(UpPostFrame)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnmenProcPostsSelected(wxCommandEvent& event);
    //*)

    //(*Identifiers(UpPostFrame)
    static const long ID_MENUITEM1;
    static const long idMenuQuit;
    static const long idMenuAbout;
    static const long ID_STATUSBAR1;
    //*)

    //(*Declarations(UpPostFrame)
    wxMenuItem* menProcPosts;
    wxStatusBar* StatusBar1;
    //*)

    DECLARE_EVENT_TABLE()
};

#endif // UPPOSTMAIN_H
