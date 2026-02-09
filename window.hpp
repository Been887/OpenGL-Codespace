#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

GLFWwindow* window;

bool createWindow() {
    if(!glfwInit()) {
        std::cout << "glfw failed to initialise!" << std::endl;
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(500, 500, "window", NULL, NULL);
    if(!window) {
        std::cout << "glfw window failed to initialise!" << std::endl;
        return false;
    }

    glfwMakeContextCurrent(window);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    } 

    int bufferwidth, bufferheight;
    glfwGetFramebufferSize(window, &bufferwidth, &bufferheight);

    glViewport(0, 0, bufferwidth, bufferheight);
    return true;
}