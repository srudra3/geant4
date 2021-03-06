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
//
//
//---------------------------------------------------------------------------
//
// ClassName:      G4HadronicParameters
//
// Author:         2018 Alberto Ribon
//
// Description:    Singleton to keep global hadronic parameters.
//
// Modified:
//
//----------------------------------------------------------------------------
//
#ifndef G4HadronicParameters_h
#define G4HadronicParameters_h 1

#include "globals.hh"
#include "G4Threading.hh"

class G4HadronicParametersMessenger;


class G4HadronicParameters {
  public:

    static G4HadronicParameters* Instance();
    ~G4HadronicParameters();

    G4double GetMaxEnergy() const;
    void SetMaxEnergy( const G4double val );
    // Getter/Setter for the upper limit for Geant4 hadronic physics, for any application.
    // Any hadronic model, physics list builder and constructor should use this method
    // instead of putting an arbitrary value in the code.
    // Any application which tries to use hadronic physics for an energy higher than this limit
    // will get a run-time crash, because no model is found.

    G4double GetMinEnergyTransitionFTF_Cascade() const;
    G4double GetMaxEnergyTransitionFTF_Cascade() const;
    void SetMinEnergyTransitionFTF_Cascade( const G4double val );
    void SetMaxEnergyTransitionFTF_Cascade( const G4double val );
    // Getter/Setter of the recommended energy limits, for physics lists, of the
    // transition region between the Fritiof (FTF) string model and the
    // intranuclear cascade model, either Bertini (BERT) or Binary (BIC). 

    G4double GetMinEnergyTransitionQGS_FTF() const;
    G4double GetMaxEnergyTransitionQGS_FTF() const;
    void SetMinEnergyTransitionQGS_FTF( const G4double val );
    void SetMaxEnergyTransitionQGS_FTF( const G4double val );
    // Getter/Setter of the recommended energy limits, for physics lists, of the
    // transition region between the two strings models - the Quark Gluon String (QGS)
    // model and the Fritiof (FTF) model.

    G4bool EnableBCParticles() const;
    void SetEnableBCParticles( G4bool val );
    // Baryons and mesons with c- and b- quarks may be enabled/disabled
    // This flag is used both by EM and hadronic physics constructors

    G4int GetVerboseLevel() const;
    void SetVerboseLevel( const G4int val );
    // Getter/Setter of the general verbosity level for hadronics.
  
  private:
    G4HadronicParameters();
    G4bool IsLocked() const;

    static G4HadronicParameters* sInstance;
    #ifdef G4MULTITHREADED
    static G4Mutex paramMutex;
    #endif

    G4HadronicParametersMessenger* fMessenger;

    G4double fMaxEnergy;
    G4double fMinEnergyTransitionFTF_Cascade;
    G4double fMaxEnergyTransitionFTF_Cascade;
    G4double fMinEnergyTransitionQGS_FTF;
    G4double fMaxEnergyTransitionQGS_FTF;
    G4int    fVerboseLevel;
    G4bool   fEnableBC;
};

inline G4double G4HadronicParameters::GetMaxEnergy() const { 
  return fMaxEnergy;
}

inline G4double G4HadronicParameters::GetMinEnergyTransitionFTF_Cascade() const { 
  return fMinEnergyTransitionFTF_Cascade;
}
inline G4double G4HadronicParameters::GetMaxEnergyTransitionFTF_Cascade() const { 
  return fMaxEnergyTransitionFTF_Cascade;
}

inline G4double G4HadronicParameters::GetMinEnergyTransitionQGS_FTF() const { 
  return fMinEnergyTransitionQGS_FTF;
}

inline G4double G4HadronicParameters::GetMaxEnergyTransitionQGS_FTF() const { 
  return fMaxEnergyTransitionQGS_FTF;
}

inline G4int G4HadronicParameters::GetVerboseLevel() const { 
  return fVerboseLevel;
}

inline G4bool G4HadronicParameters::EnableBCParticles() const {
  return fEnableBC;
}

#endif
