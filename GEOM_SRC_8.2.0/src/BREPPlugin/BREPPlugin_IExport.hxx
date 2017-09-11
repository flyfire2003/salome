// Copyright (C) 2014-2016  CEA/DEN, EDF R&D, OPEN CASCADE
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
//
// See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
//

#ifndef _BREPPlugin_IExport_HXX_
#define _BREPPlugin_IExport_HXX_

#include "GEOM_Function.hxx"

#define EXPORTBREP_ARG_ORIGINAL   1
#define EXPORTBREP_ARG_FILENAME   2

class BREPPlugin_IExport
{
public:
  BREPPlugin_IExport( Handle(GEOM_Function) theFunction )
    : _func(theFunction) {}

  void SetOriginal( Handle( GEOM_Function ) theOriginal)
    { _func->SetReference( EXPORTBREP_ARG_ORIGINAL, theOriginal ); }
  Handle( GEOM_Function ) GetOriginal()
    { return _func->GetReference( EXPORTBREP_ARG_ORIGINAL ); }

  void SetFileName( const TCollection_AsciiString& theFileName )
    { _func->SetString( EXPORTBREP_ARG_FILENAME, theFileName ); }
  TCollection_AsciiString GetFileName()
    { return _func->GetString( EXPORTBREP_ARG_FILENAME ); }
  
private:
  Handle(GEOM_Function) _func;
};

#endif // _BREPPlugin_IExport_HXX_
