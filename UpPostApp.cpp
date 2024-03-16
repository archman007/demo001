/***************************************************************
 * Name:      UpPostApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Mr. Arch Brooks (arch@archbrooks.us)
 * Created:   2024-03-12
 * Copyright: Mr. Arch Brooks (https://archbrooks.us)
 * License:
 **************************************************************/

#include "UpPostApp.h"

//(*AppHeaders
#include "UpPostMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(UpPostApp);

bool UpPostApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	UpPostFrame* Frame = new UpPostFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
