#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <iostream>
#include "vec.h"
using namespace std;

void drawPixels(vector<vector<double>> points, double step) {
    glClear(GL_COLOR_BUFFER_BIT); // �����ɫ������
    glPointSize(step * 330.0f); // ���õ�Ĵ�С
    glBegin(GL_POINTS); // ��ʼ���Ƶ�


    // ����������ÿ����
    for (const auto& point : points) {
        cout << point[0] << "," << point[1] << "," << point[2] << endl;
        if (point[2] > 600) {
            glColor3f(0.9f, 1.0f, 0.9f); // ������ɫΪ��ɫ
        }
        else if (point[2] > 300)
        {
            glColor3f(0.6f, 1.0f, 0.6f); // ������ɫΪ��ɫ
        }
        else if (point[2] > -100) {
            glColor3f(0.3f, 1.0f, 0.3f); // ������ɫΪ��ɫ
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
            glColor3f(0.0f, 0.6f, 0.0f); // ������ɫΪ��ɫ
        }
        glVertex2i(point[0], point[1]); // ���Ƶ�
    }

    glEnd(); // ��������
}
int main() {

    double L = 8.75 * 0.254;
    double M = 8.75 * 0.254;
    const int WIDTH = L * 300;
    const int HEIGHT = M * 300;
    double step = L/499;

    // ��ʼ�� GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // ��������
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Pixel Drawing with Color Condition", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // ��ʼ�� GLEW
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    // ��������ϵͳ
    glOrtho(0, WIDTH, 0, HEIGHT, -1, 1); // ��������ͶӰ

    while (!glfwWindowShouldClose(window)) {
        drawPixels(points, step); // ��������

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}