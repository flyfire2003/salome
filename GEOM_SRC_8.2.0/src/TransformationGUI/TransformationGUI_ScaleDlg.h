// Copyright (C) 2007-2016  CEA/DEN, EDF R&D, OPEN CASCADE
//
// Copyright (C) 2003-2007  OPEN CASCADE, EADS/CCR, LIP6, CEA/DEN,
// CEDRAT, EDF R&D, LEG, PRINCIPIA R&D, BUREAU VERITAS
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

// GEOM GEOMGUI : GUI for Geometry component
// File   : TransformationGUI_ScaleDlg.h
// Author : Lucien PIGNOLONI, Open CASCADE S.A.S.
//
#ifndef TRANSFORMATIONGUI_SCALEDLG_H
#define TRANSFORMATIONGUI_SCALEDLG_H

#include "GEOMBase_Skeleton.h"
#include "GEOM_GenericObjPtr.h"

class QCheckBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QPushButton;
class SalomeApp_DoubleSpinBox;

//=================================================================================
// class    : TransformationGUI_ScaleDlg
// purpose  :
//=================================================================================
class TransformationGUI_ScaleDlg : public GEOMBase_Skeleton
{ 
  Q_OBJECT

public:
  TransformationGUI_ScaleDlg( GeometryGUI*, QWidget* = 0,
                              bool = false, Qt::WindowFlags = 0 );
  ~TransformationGUI_ScaleDlg();

protected:
  // redefined from GEOMBase_Helper
  virtual GEOM::GEOM_IOperations_ptr createOperation();
  virtual bool                       isValid( QString& );
  virtual bool                       execute( ObjectList& );
  virtual void                       addSubshapesToStudy();
  virtual void                       restoreSubShapes( SALOMEDS::Study_ptr, SALOMEDS::SObject_ptr );
  virtual QList<GEOM::GeomObjPtr>    getSourceObjects();

private:
  void                               Init();
  void                               enterEvent( QEvent* );

private:
  QList<GEOM::GeomObjPtr>            myObjects;
  GEOM::GeomObjPtr                   myPoint;   /* Central Point */

  // to initialize the first selection field with a selected object on the dialog creation
  bool                               myInitial;
    
  QGroupBox*                         GroupBox1;
  QLabel*                            TextLabel1;
  QLabel*                            TextLabel2;
  QPushButton*                       PushButton1;
  QPushButton*                       PushButton2;
  QLineEdit*                         LineEdit1;
  QLineEdit*                         LineEdit2;
  QLabel*                            TextLabel3;
  QLabel*                            TextLabel4;
  QLabel*                            TextLabel5;
  SalomeApp_DoubleSpinBox*           SpinBox_FX;
  SalomeApp_DoubleSpinBox*           SpinBox_FY;
  SalomeApp_DoubleSpinBox*           SpinBox_FZ;
  QCheckBox*                         CheckBoxCopy;

private slots:
  void                               ClickOnOk();
  bool                               ClickOnApply();
  void                               ActivateThisDialog();
  void                               SelectionIntoArgument();
  void                               SetEditCurrentArgument();
  void                               ConstructorsClicked( int );
  void                               ValueChangedInSpinBox();
  void                               CreateCopyModeChanged();
  void                               SetDoubleSpinBoxStep( double );
};

#endif // TRANSFORMATIONGUI_SCALEDLG_H
