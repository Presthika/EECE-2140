#include "SimulationEngine.h"
#include <iostream>
using namespace std;

SimulationEngine::SimulationEngine(float t, int steps, FleetManager& f)
    : fleet(f) {
    this->timeStep = t;
    this->totalSteps = steps;
    this->currentStep = 0;
}

void SimulationEngine::runStep() {
    if (timeStep <= 0) {
        cout << "Invalid time step. Must be greater than 0." << endl;
        return;
    }

    currentStep++;
    cout << "--- Step " << currentStep << " of " << totalSteps << " ---" << endl;

    for (int i = 0; i < fleet.getDroneCount(); i++) {
        fleet.getDrone(i).updatePosition(timeStep);
    }

    for (int i = 0; i < fleet.getDroneCount(); i++) {
        for (int j = i + 1; j < fleet.getDroneCount(); j++) {
            if (fleet.getDrone(i).detectCollision(fleet.getDrone(j))) {
                cout << "Warning: Collision detected between Drone "
                     << fleet.getDrone(i).getID() << " and Drone "
                     << fleet.getDrone(j).getID() << endl;
            }
        }
    }

    displayStatus();
}

void SimulationEngine::runFullSimulation() {
    if (totalSteps <= 0) {
        cout << "Error: No simulation steps set." << endl;
        return;
    }

    cout << "Starting simulation..." << endl;
    while (currentStep < totalSteps) {
        runStep();
    }
    cout << "Simulation complete." << endl;
}

void SimulationEngine::displayStatus() {
    cout << "Current Step: " << currentStep << "/" << totalSteps << endl;
    cout << "Drones in fleet: " << fleet.getDroneCount() << endl;
    for (int i = 0; i < fleet.getDroneCount(); i++) {
        cout << "Drone " << fleet.getDrone(i).getID()
             << " - Position: " << fleet.getDrone(i).getPosition() << endl;
    }
}

