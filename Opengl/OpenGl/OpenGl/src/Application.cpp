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
    glColor3f(1.0, 0.0, 0.0);   // ��ɫ
    glVertex2f(-0.5, -0.5);

    glColor3f(0.0, 1.0, 0.0);   // ��ɫ
    glVertex2f(0.5, -0.5);

    glColor3f(0.0, 0.0, 1.0);   // ��ɫ
    glVertex2f(0.0, 0.5);
    glEnd();

    glFlush();
}

void saveImage(const char* filename, int width, int height) {
    std::vector<unsigned char> pixels(width * height * 3);
    glReadPixels(0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels.data());

    stbi_flip_vertically_on_write(1); // ��תͼ��

    stbi_write_png(filename, width, height, 3, pixels.data(), width * 3);
}

int main(int argc, char* argv[]) {


    if (argc != 2) {
        std::cerr << "Usage: program_name save_path" << std::endl;
        return -1;
    }

    const char* save_path = argv[1];
    // ��ʼ�� GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // ��������
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Example", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // ��ʼ�� GLEW
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    while (!glfwWindowShouldClose(window)) {
        render();

        // ������Ⱦ���ΪͼƬ
        saveImage(save_path, 800, 600);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}