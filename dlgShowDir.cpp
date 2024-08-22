#include "dlgShowDir.h"

//(*InternalHeaders(dlgShowDir)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(dlgShowDir)
const long dlgShowDir::ID_TEXTCTRL1 = wxNewId();
const long dlgShowDir::ID_BUTTON1 = wxNewId();
const long dlgShowDir::ID_TREECTRL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(dlgShowDir,wxDialog)
	//(*EventTable(dlgShowDir)
	//*)
END_EVENT_TABLE()

dlgShowDir::dlgShowDir(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(dlgShowDir)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxSYSTEM_MENU|wxRESIZE_BORDER, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Text"), wxDefaultPosition, wxSize(456,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer4->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("Label"), wxDefaultPosition, wxSize(98,33), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer4->Add(Button1, 1, wxALL|wxEXPAND, 2);
	BoxSizer3->Add(BoxSizer4, 0, wxALL|wxEXPAND, 1);
	BoxSizer2->Add(BoxSizer3, 0, wxALL|wxEXPAND, 5);
	TreeCtrl1 = new wxTreeCtrl(this, ID_TREECTRL1, wxDefaultPosition, wxSize(952,268), wxTR_DEFAULT_STYLE, wxDefaultValidator, _T("ID_TREECTRL1"));
	TreeCtrl1->ExpandAll();
	BoxSizer2->Add(TreeCtrl1, 1, wxALL|wxEXPAND, 1);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
}

dlgShowDir::~dlgShowDir()
{
	//(*Destroy(dlgShowDir)
	//*)
}

