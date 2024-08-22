#ifndef DLGSHOWDIR_H
#define DLGSHOWDIR_H

//(*Headers(dlgShowDir)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/treectrl.h>
//*)

class dlgShowDir: public wxDialog
{
	public:

		dlgShowDir(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~dlgShowDir();

		//(*Declarations(dlgShowDir)
		wxButton* Button1;
		wxTextCtrl* TextCtrl1;
		wxTreeCtrl* TreeCtrl1;
		//*)

	protected:

		//(*Identifiers(dlgShowDir)
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_TREECTRL1;
		//*)

	private:

		//(*Handlers(dlgShowDir)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
