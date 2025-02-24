#include <GL/glew.h> 
#include <GLFW/glfw3.h>
#include <stdio.h>

int main() {
    if (!glfwInit()) {
        fprintf(stderr, "Ошибка инициализации GLFW\n");
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Ошибка создания окна\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Ошибка инициализации GLEW\n");
        return -1;
    }

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // Ваш код рендеринга

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}