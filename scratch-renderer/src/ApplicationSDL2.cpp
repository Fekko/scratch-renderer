#include <sdl2/SDL.h>
#include <format>
#include "ApplicationSDL2.h" 
#include "Logging.h"
#include "Renderer.h"
#include "PixelBuffer.h"

using namespace ScratchRenderer;

ApplicationSDL2::ApplicationSDL2(const char* pName, int screenWidth, int screenHeight) :
	_pName{ pName },
	_screenWidth{ screenWidth },
	_screenHeight{ screenHeight } 
{}

ApplicationSDL2::~ApplicationSDL2() {
	SDL_DestroyTexture(_pTextureSDL);
	SDL_DestroyRenderer(_pRendererSDL);
	SDL_DestroyWindow(_pWindowSDL);
	SDL_Quit();
}

bool ApplicationSDL2::Initialize() {
	if (_initialized) return true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		__ERROR__("SDL could not be initialized!\nSDL_Error: %s\n");
		return false;
	}

	_pWindowSDL = SDL_CreateWindow(_pName,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		_screenWidth, _screenHeight,
		SDL_WINDOW_SHOWN);

	if (!_pWindowSDL) {
		__ERROR__(std::format("Window could not be created!\nSDL_Error: %s\n", SDL_GetError()).c_str());
		return false;
	}

	_pRendererSDL = SDL_CreateRenderer(_pWindowSDL, -1, SDL_RENDERER_ACCELERATED);
	if (!_pRendererSDL) {
		__ERROR__(std::format("Renderer could not be created!\nSDL_Error: %s\n", SDL_GetError()).c_str());
		return false;
	}

	_pTextureSDL = SDL_CreateTexture(_pRendererSDL,
		SDL_PIXELFORMAT_RGBA32,
		SDL_TEXTUREACCESS_STREAMING,
		_screenWidth,
		_screenHeight);

	_pRenderer = new Renderer();

	return _initialized = true;
}

void ApplicationSDL2::Run() {
	if (!Initialize()) return;

	_continue = true;
	while (_continue) {

		SDL_Event e;
		SDL_WaitEvent(&e);

		// User requests quit
		if (e.type == SDL_QUIT) {
			_continue = false;
		}

		// Initialize renderer color white for the background
		SDL_SetRenderDrawColor(_pRendererSDL, 0xFF, 0xFF, 0xFF, 0xFF);

		// Clear screen
		SDL_RenderClear(_pRendererSDL);
		Render();
		SDL_RenderCopy(_pRendererSDL, _pTextureSDL, NULL, NULL);
		SDL_RenderPresent(_pRendererSDL);
	}
}

void ApplicationSDL2::Stop() {
	_continue = false;
}

void ApplicationSDL2::Render() {
	PixelBuffer buffer = PixelBuffer(_screenWidth, _screenHeight);
	_pRenderer->Render(buffer);

	int texturePitch{};
	void* pTexturePixels{};
	SDL_LockTexture(_pTextureSDL,
		NULL,
		(void**)&pTexturePixels,
		&texturePitch);

	memcpy(pTexturePixels, buffer.GetBuffer(), texturePitch * _screenHeight);

	SDL_UnlockTexture(_pTextureSDL);
}