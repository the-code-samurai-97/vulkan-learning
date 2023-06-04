#include "2_hello_triangle_application.hpp"

HelloTriangleApplication::~HelloTriangleApplication() {
    std::cout << "Destructor called" << std::endl;
    cleanup();
}
void HelloTriangleApplication::initWindow()

{
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    window_ = glfwCreateWindow(window_width_, window_height_, "Vulkan", nullptr,
                               nullptr);
}
void HelloTriangleApplication::initVulkan() {
    std::cout << " Vulkan Initiated" << std::endl;
}
void HelloTriangleApplication::mainLoop() {
    std::cout << " Vulkan mainLoop started" << std::endl;
    while (!glfwWindowShouldClose(window_)) {
        glfwPollEvents();
    }
}
void HelloTriangleApplication::cleanup() {
    std::cout << " Vulkan cleanup Initiated" << std::endl;
    glfwDestroyWindow(window_);
    glfwTerminate();
}