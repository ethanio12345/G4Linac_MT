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


#include "HistoManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

/*#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=*/
HistoManager * HistoManager::theInstance = 0;

HistoManager * HistoManager::GetInstance()
{
  if (!theInstance) theInstance = new HistoManager();
  return theInstance;
}

/*#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=*/
HistoManager::HistoManager()

{}

/*#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=*/

HistoManager::~HistoManager()
{}
/*#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=*/
void HistoManager::SetParametersForYprofile( int Nybin,int cxid, G4double max_edep, G4double min_edep, G4double max_y, G4double min_y){
this->max_edep=max_edep;
this->min_edep=min_edep;
this->max_y= max_y;
this->min_y=min_y;
this->Nybin=Nybin;
this->cxid=cyid;
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();    
// Open an output file
  //

  G4bool fileOpen = analysisManager->OpenFile("Data");
  if (! fileOpen) {
    G4cerr << "\n---> HistoManager::Book(): cannot open " 
           << analysisManager->GetFileName() << G4endl;
    return;
  }
this->TitleYprofile="y_profile";

analysisManager->CreateH2("YPROFILE", this->TitleYprofile, 10*this->Nybin, this->min_y/cm,this->max_y/cm,10*this->Nybin,this->min_edep,this->max_edep); 


}


/*#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=*/

void HistoManager::SetParametersForXprofile( int Nxbin,int cyid, G4double max_edep, G4double min_edep, G4double max_x, G4double min_x){
this->max_edep=max_edep;
this->min_edep=min_edep;
this->max_x= max_x;
this->min_x=min_x;
this->Nxbin=Nxbin;
this->cyid=cyid;
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();    
// Open an output file
  //

  G4bool fileOpen = analysisManager->OpenFile("Data");
  if (! fileOpen) {
    G4cerr << "\n---> HistoManager::Book(): cannot open " 
           << analysisManager->GetFileName() << G4endl;
    return;
  }

analysisManager->CreateH2("XPROFILE", this->TitleXprofile, 10*this->Nxbin, this->min_x/cm,this->max_x/cm,10*this->Nxbin,this->min_edep,this->max_edep); 


}

/*#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=*/

void HistoManager::SetParametersForDosimetricData2DheatMap( int Nxbin, int Nybin,G4double max_edep, G4double min_edep, G4double max_x, G4double min_x, G4double max_y, G4double min_y){
this->max_edep=max_edep;
this->max_x= max_x;
this->max_y=max_y;
this->min_edep=min_edep;
this->min_x=min_x;
this->min_y=min_y;
this->Nxbin=Nxbin;
this->Nybin=Nybin;
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();    
// Open an output file
  //

  G4bool fileOpen = analysisManager->OpenFile("Data");
  if (! fileOpen) {
    G4cerr << "\n---> HistoManager::Book(): cannot open " 
           << analysisManager->GetFileName() << G4endl;
    return;
  }

analysisManager->CreateP2("PROFILE_2D_HEAT_MAP", this->Title_Edep_2DHeatMap,
                          this->Nxbin, this->min_x/cm, this->max_x/cm,
                          this->Nybin, this->min_y/cm,this->max_y/cm);




}

/*#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=*/
void HistoManager::SetParametersForPhaseSpaceDataSpatialDistXY( G4String _title, int xbins,G4double max_x, G4double min_x,int ybins,G4double max_y, G4double min_y ){

this->max_x= max_x;
this-> min_x= min_x;
this->max_y= max_y;
this->min_y= min_y;
this->Nxbin= xbins;
this->Nybin= ybins;
this->spatialdistxy_title=_title;
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();    
// Open an output file
  //

  G4bool fileOpen = analysisManager->OpenFile("Data");
  if (! fileOpen) {
    G4cerr << "\n---> HistoManager::Book(): cannot open " 
           << analysisManager->GetFileName() << G4endl;
    return;
  }

analysisManager->CreateH2("SPATIALDISTXY",this->spatialdistxy_title, this->Nxbin, this->min_x,this->max_x, this->Nybin, this->min_y, this->max_y);

G4cout <<" create spatialdistxy" <<G4endl;

}

/*#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=*/
void HistoManager::SetParametersForPhaseSpaceDataPhotonsEnergySpectrum( G4String _title, int EnergyBins,G4double max_energy, G4double min_energy){

this->EnergyBins=EnergyBins;
this->max_energy=max_energy;
this->min_energy=min_energy;
this->photons_energy_spectrum_title=_title;
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();    
// Open an output file
  //

  G4bool fileOpen = analysisManager->OpenFile("Data");
  if (! fileOpen) {
    G4cerr << "\n---> HistoManager::Book(): cannot open " 
           << analysisManager->GetFileName() << G4endl;
    return;
  }
G4cout<<" max energyyyyyyyyyyyyyy: :" << this->max_energy<<G4endl;
analysisManager->CreateH1("ESPECT",this->photons_energy_spectrum_title, this->EnergyBins, this->min_energy,this->max_energy);

G4cout <<" create espect spectrum" <<G4endl;

}
/*#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=*/
void HistoManager::SetParametersForDosimetricDataPdd( int Nzbin, G4double max_edep, G4double min_edep, G4double max_z, G4double min_z){
this->max_edep=max_edep;
this->max_z= max_z;
this->min_edep=min_edep;
this->min_z=min_z;
this->Nzbin=Nzbin;
    
  // Open an output file
  //
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();    
  analysisManager->SetVerboseLevel(2);
  G4bool fileOpen = analysisManager->OpenFile("Data");
  if (! fileOpen) {
    G4cerr << "\n---> HistoManager::Book(): cannot open " 
           << analysisManager->GetFileName() << G4endl;
    return;
  }
//G4cout <<"this->TitleEdepDistributionZ : " << this->TitleEdepDistributionZ<<G4endl;
//G4cout <<"this->Nzbin " << this->Nzbin<<G4endl;
//G4cout <<"this->Nzbin " << this->Nzbin<<G4endl;
//G4cout <<"this->min_z " << this->min_z/cm<<G4endl;
//G4cout <<"this->max_z " << this->max_z/cm<<G4endl;
//G4cout <<"this->min_edep " << this->min_edep<<G4endl;
//G4cout <<"this->max_edep " << this->max_edep<<G4endl;



analysisManager->CreateH2("PDD", this->TitleEdepDistributionZ, 10*this->Nzbin, this->min_z/cm,this->max_z/cm,10*this->Nzbin,this->min_edep,this->max_edep); 


 
      

  
}
/*#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=*/
void HistoManager::Book()
{
 

 
}


/*#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=*/
void HistoManager::Save()
{

  
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();    
  analysisManager->Write();
  analysisManager->CloseFile(); 
   
  G4cout << "\n----> Histograms  are saved\n" << G4endl;
      
  delete G4AnalysisManager::Instance();

}

/*#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=*/
void HistoManager::Fill_PDD( G4double z,G4double edep)
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance(); 
//G4cout<<edep/MeV<<";"<<z/cm<<G4endl;
  analysisManager->FillH2(0,z/cm,edep/MeV);
}

/*#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=*/
void HistoManager::Fill_XPROFILE( G4double x,G4double edep)
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance(); 
  analysisManager->FillH2(0,x/cm,edep/MeV);
}
/*#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=*/
void HistoManager::Fill_YPROFILE( G4double y,G4double edep)
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance(); 
  analysisManager->FillH2(0,y/cm,edep/MeV);
}
/*#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=*/

void HistoManager::Fill_Edep_2DHeatMap( G4double x, G4double y,G4double z)
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance(); 

  analysisManager->FillP2(0,x/cm,y/cm,z);
}
/*#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=*/
void HistoManager::SetTitleEdepDistributionZ(G4String _title)
{
  this->TitleEdepDistributionZ=_title;
}
/*#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=*/
void HistoManager::SetTitle_Edep_2DHeatMap(G4String _title)
{
  this->Title_Edep_2DHeatMap=_title;
}
/*#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=*/
void HistoManager::FillSpectrum (G4int ih, G4double _energy, G4double weight)
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance(); 

  analysisManager->FillH1(0, _energy, weight);
}
/*#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=*/
void HistoManager::Fill_spatialDistxy( G4double x, G4double y)
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance(); 

  analysisManager->FillH2(0,x/cm,y/cm);
}
