#pragma once
#include <stdint.h>

struct SDL_Renderer;
struct SDL_Window;
struct SDL_Texture;

class Renderer;

namespace ScratchRenderer
{
	class Application final
	{
	public:

		Application(const char* pName, int screenWidth, int screenHeight);
		~Application();
		bool Initialize();
		void Render();
		void Run();
		void Stop();

	private:
		const char* _pName{};
		const int _screenWidth{};
		const int _screenHeight{};

		bool _initialized{ false };
		bool _continue{ false };

		SDL_Renderer* _pRendererSDL{};
		SDL_Window* _pWindowSDL{};
		SDL_Texture* _pTextureSDL{};

		Renderer* _pRenderer{};

		uint32_t* _pPixels{};
	};
}