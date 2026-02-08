#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader.hpp"
#include "graphics.hpp"
#include "window.hpp"

int main() {
    if(!glfwInit()) {
        std::cout << "glfw failed to initialise!";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(500, 500, "window", nullptr, nullptr);
    if(!window) {
        std::cout << "glfw window failed to initialise!";
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD\n";
        return -1;
    }

    int bufferwidth, bufferheight;
    glfwGetFramebufferSize(window, &bufferwidth, &bufferheight);

    glViewport(0, 0, bufferwidth, bufferheight);

    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glClearColor(0.2, 0.2, 0.2, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    std::cout << "hello world" << std::endl;
    return 0;
}