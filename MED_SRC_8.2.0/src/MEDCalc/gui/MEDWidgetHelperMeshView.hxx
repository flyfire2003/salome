// Copyright (C) 2016  CEA/DEN, EDF R&D
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

#ifndef SRC_MEDCALC_GUI_MEDWIDGETHELPERMESHVIEW_HXX_
#define SRC_MEDCALC_GUI_MEDWIDGETHELPERMESHVIEW_HXX_

#include "MEDWidgetHelper.hxx"

class PresentationController;

class MEDWidgetHelperMeshView: public MEDWidgetHelper
{
  Q_OBJECT

public:
  MEDWidgetHelperMeshView(const PresentationController* presController,
                           MEDCALC::MEDPresentationManager_ptr presManager, int presId, const std::string & presName,
                           WidgetPresentationParameters * paramW);
  virtual ~MEDWidgetHelperMeshView();

  virtual void updateWidget(bool connect);
  virtual void releaseWidget();

  virtual std::string getPythonTag() const { return "MeshView"; }

protected slots:
  void onMeshModeChanged(int index);

protected:
  virtual void loadParametersFromEngine();

private:
  MEDCALC::MeshModeType _meshMode;
};

#endif /* SRC_MEDCALC_GUI_MEDWIDGETHELPERMESHVIEW_HXX_ */