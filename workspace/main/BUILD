cc_library(
    name = "hello_world_lib",
    srcs = ["hello_world.cpp"],
    hdrs = ["hello_world.h"],
    visibility = ["//visibility:public"],  # Make the target visible to all packages
)

cc_library(
    name = "main_lib",
    srcs = ["main.cpp"],
    deps = [":hello_world_lib"],
    visibility = ["//visibility:public"],  # Make the target visible to all packages
)

cc_binary(
    name = "hello_world",
    srcs = ["hello_world.cpp"],
    deps = [":main_lib"],
)