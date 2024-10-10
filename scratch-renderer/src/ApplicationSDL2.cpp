#include <sdl2/SDL.h>
#include <format>
#include "ApplicationSDL2.h" 
#include "Logging.h"

using namespace ScratchRenderer;

ApplicationSDL2::ApplicationSDL2(const char* pName, int screenWidth, int screenHeight) :
	_pName{ pName },
	_screenWidth{ screenWidth },
	_screenHeight{ screenHeight } {}

ApplicationSDL2::~ApplicationSDL2() {
	SDL_DestroyRenderer(_pRenderer);
	SDL_DestroyWindow(_pWindow);
	SDL_Quit();
}

bool ApplicationSDL2::Initialize() {
	if (_initialized) return true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		__ERROR__("SDL could not be initialized!\nSDL_Error: %s\n");
		return false;
	}

	_pWindow = SDL_CreateWindow(_pName,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		_screenWidth, _screenHeight,
		SDL_WINDOW_SHOWN);

	if (!_pWindow) {
		__ERROR__(std::format("Window could not be created!\nSDL_Error: %s\n", SDL_GetError()).c_str());
		return false;
	}

	_pRenderer = SDL_CreateRenderer(_pWindow, -1, SDL_RENDERER_ACCELERATED);
	if (!_pRenderer) {
		__ERROR__(std::format("Renderer could not be created!\nSDL_Error: %s\n", SDL_GetError()).c_str());
		return false;
	}

	_pScreenTexture = SDL_CreateTexture(_pRenderer,
		SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_STREAMING,
		_screenWidth,
		_screenHeight);

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
		SDL_SetRenderDrawColor(_pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

		// Clear screen
		SDL_RenderClear(_pRenderer);

		// Render
		Render();

		// Update screen
		SDL_RenderPresent(_pRenderer);
	}
}

void ApplicationSDL2::Stop() {
	_continue = false;
}

void ApplicationSDL2::Render() {
	int pitch{};

	SDL_LockTexture(_pScreenTexture,
		NULL,
		(void**)&_pPixelBuffer,
		&pitch);

	int x{};
	int y{};
	SDL_GetMouseState(&x, &y);

	unsigned char r = CHAR_MAX;
	unsigned char g = 0;
	unsigned char b = 0;
	unsigned char a = CHAR_MAX;
	unsigned int color = (r << 24) | (g << 16) | (b << 8)|(a);
	_pPixelBuffer[x + y*_screenWidth] = color;

	SDL_RenderCopy(_pRenderer, 
		_pScreenTexture, 
		NULL, 
		NULL);

	SDL_UnlockTexture(_pScreenTexture);
}