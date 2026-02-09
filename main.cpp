#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shader.hpp"
#include "graphics.hpp"
#include "window.hpp"

int main() {
    if(!createWindow()) {
        std::cout << "failed to create window!\n";
        return 0;
    }
    CompileShaders();
    loadSquare();

    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glClearColor(0.2, 0.2, 0.2, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader);
        glBindVertexArray(VAO);

        model = glm::mat4(1.0f);
        model = glm::scale(model, glm::vec3(0.5, 0.5, 1.0));

        //colourIn = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);

        glUniformMatrix4fv(UniformModel, 1, GL_FALSE, glm::value_ptr(model));

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        glBindVertexArray(0);
        glUseProgram(0);

        glfwSwapBuffers(window);
    }

    std::cout << "hello world" << std::endl;
    return 0;
}