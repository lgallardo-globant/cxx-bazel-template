#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

#include <chrono>

class PIDController
{
private:
    // PID gains
    double kp_; // Proportional gain
    double ki_; // Integral gain
    double kd_; // Derivative gain

    // Internal state
    double previous_error_;
    double integral_;
    std::chrono::steady_clock::time_point last_time_;

public:
    // Constructor
    PIDController(double kp, double ki, double kd);

    // Method to compute the control output
    double compute(double setpoint, double current_value);

    // Reset the integral and previous error terms
    void reset();

    // Setters for PID gains
    void setKp(double kp);
    void setKi(double ki);
    void setKd(double kd);

    // Getters for PID gains
    double getKp() const;
    double getKi() const;
    double getKd() const;
};

#endif // PIDCONTROLLER_H
