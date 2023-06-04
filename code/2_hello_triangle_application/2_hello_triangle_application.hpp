#pragma once
#include <vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

class HelloTriangleApplication{
public:
    ~HelloTriangleApplication();
    void run(){
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }
const uint32_t window_width_ = 800;
const uint32_t window_height_ = 600;
private:
    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();
    GLFWwindow* window_;
};