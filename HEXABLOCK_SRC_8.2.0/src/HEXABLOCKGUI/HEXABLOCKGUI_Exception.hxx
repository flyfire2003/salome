// Copyright (C) 2009-2016  CEA/DEN, EDF R&D
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

#ifndef __HEXABLOCKGUI_EXCEPTION_HXX__
#define __HEXABLOCKGUI_EXCEPTION_HXX__

#include "HEXABLOCKGUI_Export.hxx"

#include <string>
#include <exception>

namespace HEXABLOCK
{
  namespace GUI
  {
    class HEXABLOCK_EXPORT Exception : public std::exception
    {
    protected:
      std::string _what;
    public:
      Exception(const std::string& what);
      const char *what( void ) const throw ();
      virtual ~Exception() throw ();
    };
  }
}

#endif