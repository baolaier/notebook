#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <iostream>
#include "vec.h"
using namespace std;

void drawPixels(vector<vector<double>> points, double step) {
    glClear(GL_COLOR_BUFFER_BIT); // 清除颜色缓冲区
    glPointSize(step * 330.0f); // 设置点的大小
    glBegin(GL_POINTS); // 开始绘制点


    // 遍历并绘制每个点
    for (const auto& point : points) {
        cout << point[0] << "," << point[1] << "," << point[2] << endl;
        if (point[2] > 600) {
            glColor3f(0.9f, 1.0f, 0.9f); // 设置颜色为粉色
        }
        else if (point[2] > 300)
        {
            glColor3f(0.6f, 1.0f, 0.6f); // 设置颜色为红色
        }
        else if (point[2] > -100) {
            glColor3f(0.3f, 1.0f, 0.3f); // 设置颜色为绿色
        }
        else if (point[2] > -400)
        {
            glColor3f(0.0f, 0.9f, 0.0f);
        }
        else if (point[2] < -800)
        {
            glColor3f(0.0f, 0.7f, 0.0f);
        }
        else {
            glColor3f(0.0f, 0.6f, 0.0f); // 设置颜色为白色
        }
        glVertex2i(point[0], point[1]); // 绘制点
    }

    glEnd(); // 结束绘制
}
int main() {

    double L = 8.75 * 0.254;
    double M = 8.75 * 0.254;
    const int WIDTH = L * 300;
    const int HEIGHT = M * 300;
    double step = L/499;

    // 初始化 GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // 创建窗口
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Pixel Drawing with Color Condition", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // 初始化 GLEW
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    // 设置坐标系统
    glOrtho(0, WIDTH, 0, HEIGHT, -1, 1); // 设置正交投影

    while (!glfwWindowShouldClose(window)) {
        drawPixels(points, step); // 绘制像素

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}