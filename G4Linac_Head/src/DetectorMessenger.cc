//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
/*
 *   AUTHOR:
 *
 *   Dr. Jaafar EL Bakkali, Assistant Professor of Nuclear Physics, Rabat, Morocco.
 *   e-mail: bahmedj@gmail.com

-------------------------------------------------------------------------------------------
 * For documentation
 * see http://G4Linac_MT.GitHub.com
 *
 * - 23/07/2017: public version 2.0
 *
--------------------------------------------------------------------------------------------
*/
#include "DetectorMessenger.hh"
#include "DetectorConstruction.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWith3Vector.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWith3VectorAndUnit.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithABool.hh"
/*#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#*/
DetectorMessenger::DetectorMessenger(DetectorConstruction* pDetectorConstruction)
: G4UImessenger(),fDetectorConstruction(pDetectorConstruction)
{
  H5PhaseSpaceDir = new G4UIdirectory("/Parameters/");
  H5PhaseSpaceZStopCmd = new G4UIcmdWithADoubleAndUnit("/Parameters/ZStop",this);  
  H5PhaseSpaceZStopCmd ->SetParameterName("ZStop",false);
  H5PhaseSpaceZStopCmd ->SetUnitCategory("Length");
  H5PhaseSpaceZStopCmd ->SetRange("");
  H5PhaseSpaceZStopCmd ->AvailableForStates(G4State_PreInit,G4State_Idle);
  H5PhaseSpaceNameCmd = new G4UIcmdWithAString("/Parameters/H5PhaseSpaceName",this);
  H5PhaseSpaceNameCmd ->SetParameterName("H5PhaseSpaceName",false);
  H5PhaseSpaceNameCmd ->SetDefaultValue("example");

  NameOfGeomFromTextFileCmd = new G4UIcmdWithAString("/Parameters/NameOfGeomFromTextFile",this);
  NameOfGeomFromTextFileCmd ->SetParameterName("NameOfGeomFromTextFile",false);
  NameOfGeomFromTextFileCmd ->SetDefaultValue("");


 GeomFromTextFlagCmd= new G4UIcmdWithABool("/Parameters/UseGeomFromText",this);  
 GeomFromTextFlagCmd->SetGuidance("enable or disable UseGeomFromText");
 GeomFromTextFlagCmd->SetParameterName("UseGeomFromText",false);
 GeomFromTextFlagCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

}
/*#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#*/
DetectorMessenger::~DetectorMessenger()
{
delete H5PhaseSpaceNameCmd;
delete H5PhaseSpaceZStopCmd;
delete NameOfGeomFromTextFileCmd;
delete GeomFromTextFlagCmd;
delete H5PhaseSpaceDir;    

}
/*#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#*/
void DetectorMessenger::SetNewValue(G4UIcommand* command,
                                          G4String newValue)
{       
if( command ==  H5PhaseSpaceZStopCmd)
{ fDetectorConstruction->SetH5PhaseSpaceZStop(H5PhaseSpaceZStopCmd->GetNewDoubleValue(newValue));}
else  if( command == H5PhaseSpaceNameCmd )
{ fDetectorConstruction->SetH5PhaseSpaceName(newValue);}
 else  if( command == NameOfGeomFromTextFileCmd )
{ fDetectorConstruction->SetNameOfGeomFromTextFile(newValue);}
  else  if( command == GeomFromTextFlagCmd ){
   fDetectorConstruction-> SetGeomFromTextFlag(GeomFromTextFlagCmd->GetNewBoolValue(newValue));
     }        
}
