#ifndef PLANNER_H
#define PLANNER_H

#include "PIDController.h" // Include the PIDController header

class Planner
{
private:
    PIDController &pid_; // Reference to an external PIDController instance

public:
    // Constructor: accept a PIDController instance by reference
    Planner(PIDController &pid);

    // Method to plan and adjust based on the PIDController
    double plan(double setpoint, double current_value);

    // Method to reset the PIDController
    void reset();
};

#endif // PLANNER_H
