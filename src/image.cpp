#include "pr_opengl.hpp"
#include <image/prosper_image.hpp>

class GLImage
	: public prosper::IImage
{
public:
	static std::shared_ptr<GLImage> Create(
		Context &context,const util::ImageCreateInfo &createInfo
	);

	virtual ~GLBuffer() override;
private:
	virtual bool DoWrite(Offset offset,Size size,const void *data) const override;
	virtual bool DoRead(Offset offset,Size size,void *data) const override;
	virtual bool DoMap(Offset offset,Size size) const override;
	virtual bool DoUnmap() const override;

	GLuint m_image = GL_INVALID_VALUE;
	mutable void *m_mappedPtr = nullptr;
};

std::shared_ptr<GLImage> GLImage::Create(
	Context &context,const util::ImageCreateInfo &createInfo
)
{
	GLuint texture;
	glGenTextures(1,&texture);

}

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
	glDeleteTextures(1,&m_image);
}
