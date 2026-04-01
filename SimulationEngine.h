#pragma once 
#include "FleetManager.h"

class SimulationEngine{
    private:
    float timeStep;
    int totalSteps;
    int currentStep;
    FleetManager& fleet;

    public:
    SimulationEngine(float timeStep, int totalSteps, FleetManager& fleet);
    void runStep();
    void runFullSimulation();
    void displayStatus();
    
};
