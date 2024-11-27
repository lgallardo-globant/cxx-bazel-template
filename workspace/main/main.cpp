// main/main.cpp
#include <iostream>
#include <chrono>
#include <thread>          // Include for std::this_thread::sleep_for
#include "PIDController.h" // Include the PID controller header

int main()
{
    // Initialize PID controller with example gains
    PIDController pid(1.0, 0.1, 0.05);

    // Define the setpoint and initial process value
    double setpoint = 100.0;     // Desired target value
    double process_value = 50.0; // Initial value of the system

    // Timing setup
    auto start_time = std::chrono::steady_clock::now();
    auto end_time = start_time + std::chrono::seconds(10); // 10-second duration

    // Simulate a control loop
    while (std::chrono::steady_clock::now() < end_time)
    {
        // Compute the control signal
        double control_signal = pid.compute(setpoint, process_value);

        // Simulate the system's response to the control signal
        // (For demonstration purposes, we add a fraction of the control signal to the process value)
        process_value += control_signal * 0.1;

        // Print the current state
        std::cout << "Time: "
                  << std::chrono::duration_cast<std::chrono::seconds>(
                         std::chrono::steady_clock::now() - start_time)
                         .count()
                  << "s, Process Value: " << process_value
                  << ", Control Signal: " << control_signal << std::endl;

        // Sleep for a short duration to simulate a control loop interval (e.g., 100ms)
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "Control loop ended after 10 seconds." << std::endl;

    return 0;
}
