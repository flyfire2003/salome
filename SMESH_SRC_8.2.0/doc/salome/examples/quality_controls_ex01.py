# Free Borders


import salome
salome.salome_init()
import GEOM
from salome.geom import geomBuilder
geompy = geomBuilder.New(salome.myStudy)

import SMESH, SALOMEDS
from salome.smesh import smeshBuilder
smesh =  smeshBuilder.New(salome.myStudy)

# create open shell: a box without one plane
box = geompy.MakeBox(0., 0., 0., 20., 20., 15.)
FaceList = geompy.SubShapeAll(box, geompy.ShapeType["FACE"])
FaceList.remove(FaceList[5])
box = geompy.MakeShell(FaceList)
idbox = geompy.addToStudy(box, "box")

# create a mesh
mesh = smesh.Mesh(box, "Mesh_free_borders")
algo = mesh.Segment()
algo.NumberOfSegments(5)
algo = mesh.Triangle()
algo.MaxElementArea(20.)
mesh.Compute() 

# criterion : free borders
aFilter = smesh.GetFilter(SMESH.EDGE, SMESH.FT_FreeBorders)
anIds = mesh.GetIdsFromFilter(aFilter)

# print the result
print "Criterion: Free borders Nb = ", len(anIds)
j = 1
for i in range(len(anIds)):
  if j > 20: j = 1; print ""
  print anIds[i],
  j = j + 1
  pass
print ""

# create a group
aGroup = mesh.GetMesh().CreateGroup(SMESH.EDGE, "Free borders")
aGroup.Add(anIds)

salome.sg.updateObjBrowser(True)
