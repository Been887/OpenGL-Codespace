#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <iostream>
#include <vector>
#include <string.h>

GLuint VAO, VBO, EBO, shader;
GLuint UniformModel, UniformColourIn;

glm::mat4 model;
glm::vec4 colourIn;

const char* vshader = R"(
#version 330 core

layout(location=0) in vec3 aPos;
uniform mat4 model;

void main() {
gl_Position = model * vec4(aPos, 1.0);
})";

const char* fshader = R"(
#version 330 core

out vec4 colour;

void main() {
    colour = vec4(1.0, 0.0, 0.0, 1.0);
})";

void addshader(GLuint theprogram, const char* shadercode, GLenum shadertype) {
    GLuint theshader = glCreateShader(shadertype);

    const char* thecode[1] = {0};
    thecode[0] = shadercode;
    int codelength[1] = {0};
    codelength[0] = strlen(shadercode);

    glShaderSource(theshader, 1, thecode, codelength);

    GLchar eLog[1024] = {0};
    int result = 0;

    glCompileShader(theshader);
    glGetShaderiv(theshader, GL_COMPILE_STATUS, &result);
    if(!result) {
        glGetShaderInfoLog(theshader, 1024, nullptr, eLog);
        std::cout << eLog << std::endl;
    }

    glAttachShader(theprogram, theshader);
}

void CompileShaders() {
    shader = glCreateProgram();
    if(!shader) {
        std::cout << "failed to create shader program\n";
        return;
    }

    addshader(shader, vshader, GL_VERTEX_SHADER);
    addshader(shader, fshader, GL_FRAGMENT_SHADER);

    GLchar eLog[1024] = {0};
    int result = 0;

    glLinkProgram(shader);
    glGetProgramiv(shader, GL_LINK_STATUS, &result);
    if(!result) {
        glGetProgramInfoLog(shader, 1024, nullptr, eLog);
        std::cout << eLog << std::endl;
    }

    glValidateProgram(shader);
    glGetProgramiv(shader, GL_VALIDATE_STATUS, &result);
    if(!result) {
        glGetProgramInfoLog(shader, 1024, nullptr, eLog);
        std::cout << eLog;
    }

    UniformModel = glGetUniformLocation(shader, "model");
    UniformColourIn = glGetUniformLocation(shader, "colourIn");
}
