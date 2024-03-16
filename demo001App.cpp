/***************************************************************
 * Name:      demo001App.cpp
 * Purpose:   Code for Application Class
 * Author:    Mr. Arch Brooks (arch@archbrooks.us)
 * Created:   2024-03-16
 * Copyright: Mr. Arch Brooks (https://archbrooks.us)
 * License:
 **************************************************************/

#include "demo001App.h"

//(*AppHeaders
#include "demo001Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(demo001App);

bool demo001App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	demo001Frame* Frame = new demo001Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
