# Copyright (C) 2013-2016  CEA/DEN, EDF R&D, OPEN CASCADE
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
#
# See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
#

SET(ATOMGEN_RESOURCES_FILES
  atomgen_run.png
  ATOMGEN.png
  ATOMGEN_en.xml
)

INSTALL(FILES ${ATOMGEN_RESOURCES_FILES} DESTINATION ${SALOME_ATOMGEN_INSTALL_RES_DATA})
SALOME_CONFIGURE_FILE(ATOMGENCatalog.xml.in ATOMGENCatalog.xml INSTALL ${SALOME_ATOMGEN_INSTALL_RES_DATA})
SALOME_CONFIGURE_FILE(SalomeApp.xml.in SalomeApp.xml INSTALL ${SALOME_ATOMGEN_INSTALL_RES_DATA})
