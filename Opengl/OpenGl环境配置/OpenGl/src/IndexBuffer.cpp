#include "IndexBuffer.h"
#include "Renderer.h"

IndexBuffer::IndexBuffer(const void* data, unsigned int size)
{
    glGenBuffers(1, &m_RendererID);//���ɻ�����������
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);//�󶨻�����
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);// ��������ʼ����������������ݴ洢
}
IndexBuffer::~IndexBuffer()
{
    GLCall(glDeleteBuffers(1, &m_RendererID));
}

void IndexBuffer::Bind()
{
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));//�󶨻�����
}
void IndexBuffer::unbind()
{
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}