#include "2_hello_triangle_application.hpp"
#include <vector>
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
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    uint32_t glfwExtensionCount = 0;
    const char **glfwExtensions;

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;
    createInfo.enabledLayerCount = 0;
    if (VK_SUCCESS != vkCreateInstance(&createInfo, nullptr, &instance_)) {
        throw std::runtime_error("failed to create instance!");
    } else {
        std::cout << "vkCreateInstance created " << std::endl;
    }

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::vector<VkExtensionProperties> extensions(extensionCount);
    extensions.reserve(extensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount,
                                           extensions.data());
    std::cout << "available extensions:\n";

    for (const auto &extension : extensions) {
        std::cout << '\t' << extension.extensionName << '\n';
    }
}
void HelloTriangleApplication::mainLoop() {
    std::cout << " Vulkan mainLoop started" << std::endl;
    while (!glfwWindowShouldClose(window_)) {
        glfwPollEvents();
    }
}
void HelloTriangleApplication::cleanup() {
    std::cout << " Vulkan cleanup Initiated" << std::endl;
    vkDestroyInstance(instance_, nullptr);
    glfwDestroyWindow(window_);
    glfwTerminate();
}