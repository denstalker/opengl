#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int w_width = 640;
int w_height = 480;
void glfwWindowSizeCallback(GLFWwindow * pWindow, int width, int height)
{
    w_width = width;
    w_height = height;
    glViewport(0,0,w_width,w_height);
    std::cout << "W = " << w_width << " " << "H = " << w_height<< std::endl;
}
void glfwKeyCallback(GLFWwindow * pWindow, int key, int scancode,int action, int mode)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
    }
}

int main(void)
{
    GLFWwindow *window;
    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "GLFW init fail" << std::endl;
        return -1;
    }
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(w_width, w_height, "Hello OpenGL", NULL, NULL);
    if (!window)
    {
        std::cout << "GLFW window create failed" << std::endl;
        glfwTerminate();
        return -1;
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGL())
        while (!glfwWindowShouldClose(window))
        {
            std::cout << "Не удалось загрузить GLAD" << std::endl;
            return -1;
        }
    std::cout << "Renderer" << glGetString(GL_RENDERER) << std::endl;
    std::cout << "GL Version" << glGetString(GL_VERSION) << std::endl;
    std::cout << "OpenGL" << GLVersion.major << "." << GLVersion.minor << std::endl;
    //Зарегистрировать колбэк функции 
    glfwSetWindowSizeCallback(window,glfwWindowSizeCallback);
    glfwSetKeyCallback(window,glfwKeyCallback);


    glClearColor(0, 1, 1, 1);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
