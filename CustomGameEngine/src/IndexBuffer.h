#pragma once

class IndexBuffer
{
public:
private:
	unsigned int m_RendererID;
	unsigned int m_Count;
public:
	IndexBuffer(const void *data, unsigned int count);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;
};

