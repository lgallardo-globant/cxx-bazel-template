#include "gtest/gtest.h"
#include "../main/hello_world.h"

TEST(HelloWorldTest, OutputTest) {
    // Since helloWorld outputs to stdout, you'd need to redirect stdout to test it properly.
    testing::internal::CaptureStdout();
    helloWorld();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Hello, World!\n");
}
