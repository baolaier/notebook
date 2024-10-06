#pragma once
#include <GL/glew.h>

#define ASSERT(x) if(!(x)) __debugbreak();//宏命令，当执行到错误程序时产生中断，__debugbreak()为中断指令
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x,__FILE__,__LINE__))//#x把函数转化为string

//清空错误显示
void GLClearError();

//获取当前错误
bool GLLogCall(const char* function, const char* file, int line);