#include "../main/Planner.h"
#include "../main/PIDController.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

// Mock class for PIDController
class MockPIDController : public PIDController
{
public:
    MockPIDController() : PIDController(0.0, 0.0, 0.0) {}

    // Mock the compute and reset methods
    MOCK_METHOD(double, compute, (double setpoint, double current_value), (override));
    MOCK_METHOD(void, reset, (), (override));
};

// Test case for Planner::plan
TEST(PlannerTest, PlanMethodCallsCompute)
{
    // Arrange: Create a mock PIDController and a Planner
    MockPIDController mock_pid;
    Planner planner(mock_pid);

    double setpoint = 100.0;
    double process_value = 50.0;
    double expected_control_signal = 25.0;

    // Expect the compute method to be called with the correct arguments
    EXPECT_CALL(mock_pid, compute(setpoint, process_value))
        .Times(1)
        .WillOnce(::testing::Return(expected_control_signal));

    // Act: Call the Planner's plan method
    double control_signal = planner.plan(setpoint, process_value);

    // Assert: Verify the returned control signal
    EXPECT_DOUBLE_EQ(control_signal, expected_control_signal);
}

// Test case for Planner::reset
TEST(PlannerTest, ResetMethodCallsReset)
{
    // Arrange: Create a mock PIDController and a Planner
    MockPIDController mock_pid;
    Planner planner(mock_pid);

    // Expect the reset method to be called once
    EXPECT_CALL(mock_pid, reset())
        .Times(1);

    // Act: Call the Planner's reset method
    planner.reset();
}
