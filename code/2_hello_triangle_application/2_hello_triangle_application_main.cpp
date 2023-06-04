#include "2_hello_triangle_application.hpp"

int main() {
    HelloTriangleApplication htapp;
    try {
        htapp.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}