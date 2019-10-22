#include "VertexArray.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_RendererID);
}


VertexArray::~VertexArray()
{
}

void VertexArray::AddBuffer(const VertexBuffer & vb, const VertexBufferLayout(&layout))
{
	vb.Bind();
	const auto &elements = layout.GetElements();
	unsigned int offset = 0;

	for(unsigned int i = 0; i < elements.size(); i++){
		const auto &element = elements[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)offset);
		offset += element.count * sizeof(VertexBufferElement::GetSizeOfType(element.type));
	}
}
