#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

void render() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);   // 红色
    glVertex2f(-0.5, -0.5);

    glColor3f(0.0, 1.0, 0.0);   // 绿色
    glVertex2f(0.5, -0.5);

    glColor3f(0.0, 0.0, 1.0);   // 蓝色
    glVertex2f(0.0, 0.5);
    glEnd();

    glFlush();
}

void saveImage(const char* filename, int width, int height) {
    std::vector<unsigned char> pixels(width * height * 3);
    glReadPixels(0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels.data());

    stbi_flip_vertically_on_write(1); // 翻转图像

    stbi_write_png(filename, width, height, 3, pixels.data(), width * 3);
}

int main(int argc, char* argv[]) {


    if (argc != 2) {
        std::cerr << "Usage: program_name save_path" << std::endl;
        return -1;
    }

    const char* save_path = argv[1];
    // 初始化 GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // 创建窗口
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Example", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // 初始化 GLEW
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    while (!glfwWindowShouldClose(window)) {
        render();

        // 保存渲染结果为图片
        saveImage(save_path, 800, 600);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}