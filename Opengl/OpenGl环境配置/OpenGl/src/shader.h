#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>//字符串流，提供临时输入输出接口方便像处理文件一样处理字符串
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
    enum class ShaderType//枚举类
    {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };
    ShaderType type = ShaderType::NONE;
    std::stringstream ss[2];//设置两个字符串流，一个指向顶点着色器，一个指向片段着色器
    while (getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos)//其中string::npos表示不存在位置，这句话表示能找到#shader
        {
            if (line.find("vertex") != std::string::npos)
            {
                //模式设置为顶点着色器
                type = ShaderType::VERTEX;
            }
            else if (line.find("fragment") != std::string::npos)
            {
                //模式设置为片段着色器
                type = ShaderType::FRAGMENT;
            }
        }
        //其余非#shader字段放到对应的着色器源码中
        else
        {
            ss[(int)type] << line << '\n';
        }
    }
    return{ ss[0].str(),ss[1].str() };
}

static unsigned int CompileShader(unsigned int type, const std::string& source)//type表示着色器类型，source为
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();//指向图形开始的指针,或者写成&soutce[0]，c_str返回以null为结尾的字符串指针
    glShaderSource(id, 1, &src, nullptr);//将 Shader 中的源代码设置为 String 指定的字符串数组中的源代码
    glCompileShader(id);//编译实际着色器的所有代码

    //检查程序错误，用于调试
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);//编译状态
    if (result == GL_FALSE)//alt+f12
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);//信息日志长度
        char* message = (char*)alloca(length * sizeof(char));//参见malloc
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile shader!" <<
            (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "shader!" << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);//删除这个shader
        return 0;
    }

    return id;
}
static int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)//create two shaders
{
    unsigned int program = glCreateProgram();//创建一个程序
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    //链接两个shader在program里
    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);
    glValidateProgram(program);

    //链接好shader后可以删除shader，不建议
    glDeleteShader(vs);
    glDeleteShader(fs);
    return program;

}
