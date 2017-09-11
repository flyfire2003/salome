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

// internal includes
#include "BREPPlugin_IOperations_i.hh"
#include "BREPPlugin_IOperations.hxx"

// KERNEL includes
#include <utilities.h>

//=============================================================================
/*!
 *   constructor:
 */
//=============================================================================
BREPPlugin_IOperations_i::BREPPlugin_IOperations_i( PortableServer::POA_ptr thePOA,
						    GEOM::GEOM_Gen_ptr theEngine,
						    BREPPlugin_IOperations* theImpl )
:GEOM_IOperations_i( thePOA, theEngine, theImpl )
{
  MESSAGE( "BREPPlugin_IOperations_i::BREPPlugin_IOperations_i" );
}

//=============================================================================
/*!
 *  destructor
 */
//=============================================================================
BREPPlugin_IOperations_i::~BREPPlugin_IOperations_i()
{
  MESSAGE( "BREPPlugin_IOperations_i::~BREPPlugin_IOperations_i" );
}

//=============================================================================
/*!
 *  ExportBREP
 *  Export a shape to BREP format
 *  \param theOriginal The shape to export
 *  \param theFileName The name of the exported file
 */
//=============================================================================
void BREPPlugin_IOperations_i::ExportBREP( GEOM::GEOM_Object_ptr theOriginal,
					   const char*           theFileName )
{
  // duplicate the original shape
  GEOM::GEOM_Object_var aGEOMObject = GEOM::GEOM_Object::_duplicate( theOriginal );

  //Set a not done flag
  GetOperations()->SetNotDone();

  //Get the reference shape
  Handle(GEOM_Object) anOriginal = GetObjectImpl( theOriginal );
  if (anOriginal.IsNull()) return;

  //Export the shape to the file
  GetOperations()->ExportBREP( anOriginal, theFileName );
}

//=============================================================================
/*!
 *  ImportBREP
 *  Import a shape from BREP format
 *  \param theFileName The name of the file to import
 *  \return List of GEOM_Objects, containing the created shape and propagation groups.
 */
//=============================================================================
GEOM::ListOfGO* BREPPlugin_IOperations_i::ImportBREP( const char* theFileName )
{
  GEOM::ListOfGO_var aSeq = new GEOM::ListOfGO;

  //Set a not done flag
  GetOperations()->SetNotDone();

  //Import the shape from the file
  Handle(TColStd_HSequenceOfTransient) aHSeq = GetOperations()->ImportBREP( theFileName );

  if( !GetOperations()->IsDone() || aHSeq.IsNull() )
    return aSeq._retn();

  // Copy created objects.
  Standard_Integer aLength = aHSeq->Length();
  aSeq->length( aLength );
  for( Standard_Integer i = 1; i <= aLength; i++ )
    aSeq[i-1] = GetObject( Handle(GEOM_Object)::DownCast( aHSeq->Value(i) ) );

  return aSeq._retn();
}

BREPPlugin_IOperations* BREPPlugin_IOperations_i::GetOperations()
{
  return (BREPPlugin_IOperations*)GetImpl();
}
