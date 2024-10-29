#pragma once

#include "Pixel.h"
#include "Logging.h"

class PixelBuffer
{
public:
	PixelBuffer(size_t width, size_t height);
	~PixelBuffer();

	void Set(size_t x, size_t y, Pixel pixel);
	const Pixel* GetBuffer() const;

	const size_t Width{};
	const size_t Height{};

private:
	Pixel* _pBuffer{};
};