#include "VertexArray.h"

#include "Renderer.h"

VertexArray::VertexArray()
{
}

VertexArray::~VertexArray()
{
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	vb.Bind();
	const auto&
	GLCall(glEnableVertexAttribArray(0));

}
