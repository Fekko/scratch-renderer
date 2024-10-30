#pragma once

#include "Pixel.h"

class PixelBuffer
{
public:
	PixelBuffer(size_t width, size_t height);
	PixelBuffer(const PixelBuffer& other);
	PixelBuffer(PixelBuffer&& other) noexcept;
	~PixelBuffer();
	PixelBuffer& operator=(const PixelBuffer& other);
    PixelBuffer& operator=(PixelBuffer&& other) noexcept;

	void Set(size_t x, size_t y, Pixel pixel);
	const Pixel* GetBuffer() const;

	const size_t Width{};
	const size_t Height{};

private:
	Pixel* _pBuffer{};
};