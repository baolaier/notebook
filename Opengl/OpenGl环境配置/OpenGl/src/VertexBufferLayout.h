#pragma once
#include <iostream>
#include <vector>
#include <GL/glew.h>


struct VertexBufferElement
{
	unsigned int type;
	unsigned int count;
	bool normalized;//是否被标准化了
};

class VertexBufferLayout//作为一个模板
{
private:
	std::vector<VertexBufferElement> m_Elements;
	unsigned int m_Stride;//步幅
public:
	VertexBufferLayout():m_Stride(0){}//声明把m_Stride初始化为0
	
	//自定义模式
	template<typename T>
	void Push(int count)
	{
		static_assert(false);
	}

	template<>
	void Push<float>(int count)
	{
		m_Elements.push_back({( GL_FLOAT, count ,false)});
		m_Stride += sizeof(GLfloat);
	} 

	template<>
	void Push<unsigned int>(int count)
	{
		m_Elements.push_back({( GL_UNSIGNED_INT, count ,false) });
		m_Stride += sizeof(GLuint);
	}

	template<>
	void Push<unsigned char>(int count)
	{
		m_Elements.push_back({( GL_UNSIGNED_BYTE, count ,true )});
		m_Stride += sizeof(GL_BYTE);
	}

	//使用GerElements()快速返回m_Elements值，其中inline为内联函数
	inline const std::vector<VertexBufferElement> GetElements()const { return m_Elements; }
	//使用GetStride()快速返回m_Stride值
	inline unsigned int GetStride() const { return m_Stride; }

};