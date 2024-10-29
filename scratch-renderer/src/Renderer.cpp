#include "Renderer.h"
#include "PixelBuffer.h"

void Renderer::Render(PixelBuffer& buffer)
{
	for (unsigned int x{}; x < buffer.Width; ++x) {
		for (unsigned int y{}; y < buffer.Height; ++y) {
			buffer.Set(x, y, { uint8_t(255), uint8_t(0), uint8_t(0), uint8_t(255) });
		}
	}
}
