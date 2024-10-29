#pragma once

#include <cstdint>

struct Pixel
{
	uint8_t R{};
	uint8_t G{};
	uint8_t B{};
	uint8_t A{};

	Pixel(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = uint8_t(255))
		: R{ red }, G{ green }, B{ blue }, A{ alpha }
	{}

	Pixel() : Pixel(255, 255, 255, 255)
	{}

};