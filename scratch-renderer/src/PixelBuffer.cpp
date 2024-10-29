#include "PixelBuffer.h"

PixelBuffer::PixelBuffer(size_t width, size_t height)
	: Width{ width }, Height{ height }, _pBuffer { new Pixel[width * height] }
{}

PixelBuffer::~PixelBuffer()
{
	delete _pBuffer;
}

void PixelBuffer::Set(size_t x, size_t y, Pixel pixel)
{
	_pBuffer[x + y * Width] = pixel;
}

const Pixel* PixelBuffer::GetBuffer() const
{
	return _pBuffer;
}


