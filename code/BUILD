cc_binary(
    name = "1_vulkan_window",
    srcs = ["1_vulkan_window.cpp"],
    copts = ["-std=c++17"],
    # deps = [
    #     "//external/glfw",
    #     "//external/glm",
    #     "@rules_vulkan//vulkan:vulkan_cc_library"
    # ],
    linkopts=["-lglfw"," -lvulkan ","-ldl"," -lpthread ","-lX11"," -lXxf86vm ","-lXrandr ","-lXi"],
)