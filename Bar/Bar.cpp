#define GLFW_DLL
#define GLEW_DLL

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main()
{

    glfwInit();

    if (!glfwInit()) {
        fprintf(stderr, "flFw ERROR: \n");
        return -1;

    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1.0);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0.0);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* MyWindow;

    MyWindow = glfwCreateWindow(512, 512, "Baobab", NULL, NULL);

    if (!MyWindow) {
        glfwTerminate();
        return -2;
    }

    glfwMakeContextCurrent(MyWindow);

    glewInit();

    GLenum ret = glewInit();
    if (GLEW_OK != ret) {
        fprintf(stderr, "GLEW ERROR: \n", glewGetErrorString(ret));
        return -3;

    }

    while (!glfwWindowShouldClose(MyWindow)) {

        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.0, 1.0, 1.0, 1.0);

        glColor3f(0.3, 1.0, 1.0);
        glBegin(GL_TRIANGLES);
        glVertex3f(0, 0.5, 0);
        glVertex3f(0.5, -0.5, 0);
        glVertex3f(-0.5, -0.5, 0);
        glEnd();

        glfwSwapBuffers(MyWindow);
        glfwPollEvents();

    }

    glfwTerminate();
}
