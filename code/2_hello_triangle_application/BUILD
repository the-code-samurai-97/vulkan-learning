#2
cc_library(
    name = "2_hello_triangle_application_lib",
    srcs = ["2_hello_triangle_application.cpp"],
    hdrs = ["2_hello_triangle_application.hpp"],
)
cc_binary(
    name = "2_hello_triangle_application",
    srcs = ["2_hello_triangle_application_main.cpp"],
    copts = ["-std=c++17"],
    linkopts=["-lglfw"," -lvulkan ","-ldl"," -lpthread ","-lX11"," -lXxf86vm ","-lXrandr ","-lXi"],
    deps = [":2_hello_triangle_application_lib"],
)