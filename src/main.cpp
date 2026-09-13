#include <iostream>
#include <glad/gl.h>
using namespace std;
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>


int main(int argc, char** argv)
{
    if (!glfwInit()) {
        return -1;
    }
    GLFWwindow* window = glfwCreateWindow(800, 600, "cpp_game_engine", NULL, NULL);
    if (!window) {
        //创建失败就退出
        glfwTerminate();
        return -1;
    }
    //激活上面创建的opengl上下文
    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glClearColor(49.f/255,77.f/255, 121.f/255,1.f);

        glfwSwapBuffers(window);

        glfwPollEvents();
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            break;
        }
    }

    glfwTerminate();
    return 0;
}
