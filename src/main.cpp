#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int g_windowSizeX = 640;
int g_windowSizeY = 480;

void glWindowSizeCallback(GLFWwindow* pwindowm, int width, int height){
    g_windowSizeX = width;
    g_windowSizeY = height;
    glViewport(0, 0, g_windowSizeX, g_windowSizeY);
}

void glfwKeyCallback(GLFWwindow* pwindow, int key, int scancode, int action, int mode){
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(pwindow, GL_TRUE);
    }
}

int main(void)
{
    GLFWwindow* pwindow;

    /* Initialize the library */
    if (!glfwInit()) {
        std::cout << "glfwInit - failed\n";
        return -1;
    }


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode pwindow and its OpenGL context */
    pwindow = glfwCreateWindow(g_windowSizeX, g_windowSizeY, "Battle-City", nullptr, nullptr);
    if (!pwindow)
    {
        std::cout << "glfwCreateWindow - failed\n";
        glfwTerminate();
        return -1;
    }

    glfwSetWindowSizeCallback(pwindow, glWindowSizeCallback);
    glfwSetKeyCallback(pwindow, glfwKeyCallback);

    /* Make the pwindow's context current */
    glfwMakeContextCurrent(pwindow);

    if(!gladLoadGL()){
	    std::cout << "Can't load GLAD!\n";
	    return -1;
    }

    std::cout << "Render: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

    glClearColor(1, 1, 0, 1);

    /* Loop until the user closes the pwindow */
    while (!glfwWindowShouldClose(pwindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pwindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
