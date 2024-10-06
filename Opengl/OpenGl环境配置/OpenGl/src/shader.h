#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>//�ַ��������ṩ��ʱ��������ӿڷ��������ļ�һ�������ַ���
#include <string>

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
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };
    ShaderType type = ShaderType::NONE;
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
            else if (line.find("fragment") != std::string::npos)
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
    return{ ss[0].str(),ss[1].str() };
}

static unsigned int CompileShader(unsigned int type, const std::string& source)//type��ʾ��ɫ�����ͣ�sourceΪ
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
        char* message = (char*)alloca(length * sizeof(char));//�μ�malloc
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile shader!" <<
            (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "shader!" << std::endl;
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
