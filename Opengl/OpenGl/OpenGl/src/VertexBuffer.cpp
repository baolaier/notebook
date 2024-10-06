#include "VertexBuffer.h"
#include "Renderer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
    glGenBuffers(1, &m_RendererID);//���ɻ�����������
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);//�󶨻�����
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);// ��������ʼ����������������ݴ洢
}
VertexBuffer::~VertexBuffer()
{
    GLCall(glDeleteBuffers(1, &m_RendererID));
}

void VertexBuffer::Bind()
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));//�󶨻�����
}
void VertexBuffer::unbind()
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}