import pyg4ometry

r = pyg4ometry.gdml.Reader("FILE.gdml")

reg = r.getRegistry()

pyg4ometry.convert.geant4Reg2Geant4USDStage(reg,"FILE.usda")
