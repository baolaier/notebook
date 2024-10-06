#pragma once
#include <GL/glew.h>

#define ASSERT(x) if(!(x)) __debugbreak();//�������ִ�е��������ʱ�����жϣ�__debugbreak()Ϊ�ж�ָ��
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x,__FILE__,__LINE__))//#x�Ѻ���ת��Ϊstring

//��մ�����ʾ
void GLClearError();

//��ȡ��ǰ����
bool GLLogCall(const char* function, const char* file, int line);