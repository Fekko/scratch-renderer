#include "PixelBuffer.h"
#include <Utility>

PixelBuffer::PixelBuffer(size_t width, size_t height)
	: Width{ width }, Height{ height }, _pBuffer { new Pixel[width * height] }
{}

PixelBuffer::PixelBuffer(const PixelBuffer& other)
    : PixelBuffer{ other.Width, other.Height }
{}

PixelBuffer::PixelBuffer(PixelBuffer&& other) noexcept
    : Width{ other.Width }, Height{ other.Height }, _pBuffer{ other._pBuffer }
{}

PixelBuffer::~PixelBuffer()
{
	delete _pBuffer;
}

PixelBuffer& PixelBuffer::operator=(const PixelBuffer& other)
{
    if (this == &other) return *this;
    PixelBuffer temp(other);
    std::swap(_pBuffer, temp._pBuffer);
    return *this;
}


PixelBuffer& PixelBuffer::operator=(PixelBuffer&& other) noexcept
{
    PixelBuffer temp(std::move(other));
    std::swap(_pBuffer, temp._pBuffer);
    return *this;
}


void PixelBuffer::Set(size_t x, size_t y, Pixel pixel)
{
	_pBuffer[x + y * Width] = pixel;
}

const Pixel* PixelBuffer::GetBuffer() const
{
	return _pBuffer;
}


