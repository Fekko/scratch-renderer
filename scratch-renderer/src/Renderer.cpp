#include "Renderer.h"
#include "PixelBuffer.h"

void Renderer::Render(PixelBuffer& buffer)
{
	for (unsigned int x{}; x < buffer.Width; ++x) {
		for (unsigned int y{}; y < buffer.Height; ++y) {
			auto r = uint8_t(x * 255 / buffer.Width );
			auto g = uint8_t(y * 255 / buffer.Height);
			buffer.Set(x, y, { r, g, uint8_t(0), uint8_t(255) });
		}
	}
}
