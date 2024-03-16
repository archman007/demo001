/***************************************************************
 * Name:      UpPostMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Mr. Arch Brooks (arch@archbrooks.us)
 * Created:   2024-03-12
 * Copyright: Mr. Arch Brooks (https://archbrooks.us)
 * License:
 **************************************************************/

#include "UpPostMain.h"
#include <wx/msgdlg.h>
//#include <wx/wx.h>
#include <wx/arrstr.h>
#include <fstream>
#include <boost/algorithm/string.hpp>
//(*InternalHeaders(UpPostFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxArrayString lines;

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

//(*IdInit(UpPostFrame)
const long UpPostFrame::ID_MENUITEM1 = wxNewId();
const long UpPostFrame::idMenuQuit = wxNewId();
const long UpPostFrame::idMenuAbout = wxNewId();
const long UpPostFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(UpPostFrame,wxFrame)
    //(*EventTable(UpPostFrame)
    //*)
END_EVENT_TABLE()

UpPostFrame::UpPostFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(UpPostFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    menProcPosts = new wxMenuItem(Menu1, ID_MENUITEM1, _("Process Post"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(menProcPosts);
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

    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&UpPostFrame::OnmenProcPostsSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&UpPostFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&UpPostFrame::OnAbout);
    //*)


}

UpPostFrame::~UpPostFrame()
{
    //(*Destroy(UpPostFrame)
    //*)
}

void UpPostFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void UpPostFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void UpPostFrame::ReadFileLines(const wxString& filename)
{
    std::ifstream file(filename.ToStdString());

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            lines.Add(line);
        }
        file.close();
    }
    else
    {
//        wxLogError("Unable to open file '%s'", filename);
    }

}

void UpPostFrame::strToFile(std::string fname, std::string entFfile)
{
    std::ofstream outputFile(fname);

    if (outputFile.is_open())
    {
        outputFile << entFfile;
        outputFile.close();
        //std::cout << "Text file has been written successfully." << std::endl;
    }
    else
    {
        //std::cerr << "Error: Unable to open the file." << std::endl;
    }

}

void UpPostFrame::OnmenProcPostsSelected(wxCommandEvent& event)
{
    wxString filename(wxString("mem01.txt"));
    lines.clear();
//    ReadFileLines(filename);
    std::ifstream file(filename.ToStdString());

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            lines.Add(line, 1);
        }
        file.close();
    }
    else
    {
//        wxLogError("Unable to open file '%s'", filename);
    }

    std::string entText = "";
    int i = 0;
    while (i < lines.size())
    {
        std::string buf = lines[i].ToStdString();
        int ista = buf.find("[codesyntax lang=\"");
        if (ista > -1)
        {
            std::string pname = "";
            int ilast = buf.find_last_of("\"");
            pname = buf.substr(sizeof("[codesyntax lang=\"")-1,  (sizeof("[codesyntax lang=\"")-1 + (ilast - 2)));
            int ista2 = buf.find_first_of("\"");
            pname = buf.substr(ista2, (ilast - ista2));
            pname = '"' + pname;
            pname = pname + '"';
            std::string newbuf = "<pre class=\"EnlighterJSRAW\" data-enlighter-language=\"" + pname + "\">";
            boost::algorithm::replace_all(newbuf, "\"", "");
            lines[i] = newbuf;
            entText = entText + lines[i] + "\n";
            i++;
            pname = pname;
        }
        {

            entText = entText + lines[i] + "\n";
        }
        i++;
    }

    boost::algorithm::replace_all(entText, "[/codesyntax]", "</pre>");
    boost::algorithm::replace_all(entText, "bash", "\"bash\"");

    strToFile("mem02.txt", entText);

    lines;



}
