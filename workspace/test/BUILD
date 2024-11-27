cc_test(
    name = "hello_world_test",
    srcs = ["hello_world_test.cpp"],
    deps = [
        "//main:hello_world_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "pid_controller_test",
    srcs = ["pid_controller_test.cpp"],  # Test source file
    deps = [
        "//main:pid_controller_lib",      # Depend on the PID controller library
        "@com_google_googletest//:gtest_main",  # Google Test main library
    ],
)
