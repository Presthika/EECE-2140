#include "SimulationEngine.h"
#include <iostream>
using namespace std;

SimulationEngine:: SimulationEngine(float t)
{
    this->timeStep = t;
}

void SimulationEngine:: runStep()
{
    if (timeStep <= 0)
    {
        cout << "Invalid time step. Time step must be greater than 0." << endl;
        return;
    }
    cout << "Running simulation step with time step: " << timeStep << " seconds." << endl;
}

void SimulationEngine:: displayStatus()
{
    cout << "Displaying simulation status..." << endl;
}