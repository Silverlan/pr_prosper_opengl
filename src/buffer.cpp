#include "pr_opengl.hpp"
#include <buffers/prosper_buffer.hpp>

class GLBuffer
	: public prosper::IBuffer
{
public:
	virtual ~GLBuffer() override;
private:
	virtual bool DoWrite(Offset offset,Size size,const void *data) const override;
	virtual bool DoRead(Offset offset,Size size,void *data) const override;
	virtual bool DoMap(Offset offset,Size size) const override;
	virtual bool DoUnmap() const override;

	GLuint m_buffer = GL_INVALID_VALUE;
	mutable void *m_mappedPtr = nullptr;
};

bool GLBuffer::DoMap(Offset offset,Size size) const
{
	m_mappedPtr = glMapBufferRange(m_buffer,offset,size,GL_MAP_WRITE_BIT);
	return m_mappedPtr;
}
bool GLBuffer::DoUnmap() const
{
	return glUnmapBuffer(m_buffer);
}

bool GLBuffer::DoWrite(Offset offset,Size size,const void *data) const
{
	auto *ptr = glMapBufferRange(m_buffer,offset,size,GL_MAP_WRITE_BIT);
	if(ptr == nullptr)
		return false;
	memcpy(ptr,data,size);
	return glUnmapBuffer(m_buffer);
}
bool GLBuffer::DoRead(Offset offset,Size size,void *data) const
{
	auto *ptr = glMapBufferRange(m_buffer,offset,size,GL_MAP_READ_BIT);
	if(ptr == nullptr)
		return false;
	memcpy(data,ptr,size);
	return glUnmapBuffer(m_buffer);
}

GLBuffer::~GLBuffer()
{
	glDeleteBuffers(1,&m_buffer);
}
