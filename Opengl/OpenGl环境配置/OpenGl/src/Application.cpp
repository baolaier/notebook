#include <GL\glew.h>
#include <GLFW/glfw3.h>
#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>//�ַ��������ṩ��ʱ��������ӿڷ��������ļ�һ�������ַ���



//����Shader�ṹ�壬ʹ��ParseShader���Է�������stringԴ��
struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

static ShaderProgramSource ParseShader(const std::string& filepath)
{
    std::ifstream stream(filepath);
    std::string line;
    enum class ShaderType//ö����
    {
        NONE = -1, VERTEX = 0,FRAGMENT=1
    };
    ShaderType type= ShaderType::NONE;
    std::stringstream ss[2];//���������ַ�������һ��ָ�򶥵���ɫ����һ��ָ��Ƭ����ɫ��
    while (getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos)//����string::npos��ʾ������λ�ã���仰��ʾ���ҵ�#shader
        {
            if (line.find("vertex") != std::string::npos)
            {
                //ģʽ����Ϊ������ɫ��
                type = ShaderType::VERTEX;
            }
            else if(line.find("fragment")!=std::string::npos)
            {
                //ģʽ����ΪƬ����ɫ��
                type = ShaderType::FRAGMENT;
            }
        }
        //�����#shader�ֶηŵ���Ӧ����ɫ��Դ����
        else
        {
            ss[(int)type] << line << '\n';
        }
    }
    return{ ss[0].str(),ss[1].str()};
}

static unsigned int CompileShader(unsigned int type,const std::string& source)//type��ʾ��ɫ�����ͣ�sourceΪ
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();//ָ��ͼ�ο�ʼ��ָ��,����д��&soutce[0]��c_str������nullΪ��β���ַ���ָ��
    glShaderSource(id, 1, &src, nullptr);//�� Shader �е�Դ��������Ϊ String ָ�����ַ��������е�Դ����
    glCompileShader(id);//����ʵ����ɫ�������д���

    //������������ڵ���
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);//����״̬
    if (result == GL_FALSE)//alt+f12
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);//��Ϣ��־����
        char *message =(char*)alloca(length * sizeof(char));//�μ�malloc
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile shader!" <<
            (type == GL_VERTEX_SHADER ? "vertex":"fragment")<<"shader!"<<std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);//ɾ�����shader
        return 0;
    }

    return id;
}
static int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)//create two shaders
{
    unsigned int program = glCreateProgram();//����һ������
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    //��������shader��program��
    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);
    glValidateProgram(program);

    //���Ӻ�shader�����ɾ��shader��������
    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;

}
    
int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(5);// �ڳ�ʼ��glfw�����ô�ֱͬ��������Ⱦ֡������ʾ��ˢ����ͬ��


    if (glewInit() != GLEW_OK)
        std::cout << "ERROR!" << std::endl;
    {//������ŷǳ���Ҫ����һ��������
        float positions[12] = {
            -0.5f, -0.5f,//0
             0.5f, -0.5f,//1
             0.5f,  0.5f,//2
            -0.5f,  0.5f,//3
        };//build buffer
        unsigned int indices[] = {
            0,1,2,
            0,3,2
        };//��������������

        unsigned int vao;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        VertexBuffer vb(positions, 4 * 2 * sizeof(float));


        glEnableVertexAttribArray(0);//����ͨ�ö����������飬����0Ϊ��������
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);//����ͨ�ö����������ݵ�����

        IndexBuffer ib(indices, 6 * sizeof(unsigned int));


        ShaderProgramSource source = ParseShader("res/shaders/Basic.shader");
        //   std::cout << source.VertexSource << std::endl;
        //   std::cout << source.FragmentSource << std::endl;

        unsigned int shader = CreateShader(source.VertexSource, source.FragmentSource);
        glUseProgram(shader);//��Ŀ����ɫ��

        int Location = glGetUniformLocation(shader, "u_color");
        ASSERT(Location != -1);//���locationΪ-1˵����ַ��Ч
        glUniform4f(Location, 0.0f, 0.1f, 0.2f, 0.3f);

        glUseProgram(0);//��Ŀ�����ɫ��
        vb.unbind();
        ib.unbind();//�������������

        float r = 0.0f;
        float increment = 0.5f;
        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

            glUseProgram(shader);//��Ŀ����ɫ��

            glUniform4f(Location, r, 0.3, 0.8, 1.0);

            vb.Bind();
            ib.Bind();//������������

            VertexArray va;


            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);//����ͨ�ö����������ݵ�����
            GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
            if (r > 1.0f)
            {
                increment = -0.1f;
            }
            else if (r < 0.0f)
            {
                increment = 0.1f;
            }
            r += increment;

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }
        glDeleteProgram(shader);
    }
    glfwTerminate();
    return 0;
}