#include "Planner.h"

// Constructor: Initialize Planner with a reference to an existing PIDController
Planner::Planner(PIDController &pid)
    : pid_(pid) {}

// Method to plan and adjust based on the PIDController
double Planner::plan(double setpoint, double current_value)
{
    // Use the PID controller to compute the control signal
    return pid_.compute(setpoint, current_value);
}

// Method to reset the PIDController
void Planner::reset()
{
    pid_.reset();
}
