
cc_library(
    name = "validator_lib",
    srcs = ["validator.cpp"],  # Source file for the validator library
    hdrs = ["validator.hpp"],    # Header file for the validator library
    visibility = ["//visibility:public"],  # Make this library accessible to all packages
)

cc_library(
    name = "account_lib",
    srcs = ["account.cpp"],  # Source file for the account library
    hdrs = ["account.hpp"],    # Header file for the account library
    visibility = ["//visibility:public"],  # Make this library accessible to all packages
)

cc_library(
    name = "pid_controller_lib",
    srcs = ["PIDController.cpp"],  # Source file for the PID controller library
    hdrs = ["PIDController.h"],    # Header file for the PID controller library
    visibility = ["//visibility:public"],  # Make this library accessible to all packages
)

cc_library(
    name = "planner_lib",
    srcs = ["Planner.cpp"],
    hdrs = ["Planner.h"],
    deps = [":pid_controller_lib"],  # Depend on the PIDController library
    visibility = ["//visibility:public"],
)

cc_library(
    name = "hello_world_lib",
    srcs = ["hello_world.cpp"],
    hdrs = ["hello_world.h"],
    deps = [":pid_controller_lib"],  # Depend on the PID controller library
    visibility = ["//visibility:public"],  # Make the target visible to all packages
)

cc_library(
    name = "main_lib",
    srcs = ["main.cpp"],
    deps = [":hello_world_lib", ":pid_controller_lib", ":planner_lib"],  # Add PID dependency here
    visibility = ["//visibility:public"],  # Make the target visible to all packages
)

cc_binary(
    name = "hello_world",
    srcs = ["hello_world.cpp"],
    deps = [":main_lib", ":pid_controller_lib", ":planner_lib", ":account.lib", ":validator.lib"],  # Binary depends on main_lib and PID
)
