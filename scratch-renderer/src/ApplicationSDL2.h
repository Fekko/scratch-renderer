#pragma once

struct SDL_Renderer;
struct SDL_Window;
struct SDL_Texture;

namespace ScratchRenderer
{
	class ApplicationSDL2 final
	{
	public:

		ApplicationSDL2(const char* pName, int screenWidth, int screenHeight);
		~ApplicationSDL2();
		bool Initialize();
		void Render();
		void Run();
		void Stop();

	private:
		const int _screenWidth{};
		const int _screenHeight{};

		const char* _pName{};
		SDL_Renderer* _pRenderer{};
		SDL_Window* _pWindow{};

		bool _initialized{ false };
		bool _continue{ false };

		SDL_Texture* _pScreenTexture{};
		unsigned int* _pPixelBuffer{};
	};
}