//#pragma once
//#include <iostream>
//#include <sdl2/SDL.h>
//#include "IApplication.h"
//#include "Logger.h"
//
//class Application_SDL2 : IApplication
//{
//public:
//
//	Application_SDL2(const char* pName, int screenWidth, int screenHeight, Logger* pLogger):
//		_pName{ pName },
//		_screenWidth{ screenWidth },
//		_screenHeight{ screenHeight },
//		_pLogger{ pLogger }
//	{}
//
//	~Application_SDL2() {
//		SDL_DestroyRenderer(_pRenderer);
//		SDL_DestroyWindow(_pWindow);
//		SDL_Quit();
//	}
//
//	bool Initialize() {
//		if (_initialized) return true;
//
//		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//			_pLogger->Log("SDL could not be initialized!\nSDL_Error: %s\n");
//			return false;
//		}
//
//		_pWindow = SDL_CreateWindow(_pName,
//			SDL_WINDOWPOS_UNDEFINED,
//			SDL_WINDOWPOS_UNDEFINED,
//			_screenWidth, _screenHeight,
//			SDL_WINDOW_SHOWN);
//
//		if (!_pWindow) {
//			printf("Window could not be created!\nSDL_Error: %s\n", SDL_GetError());
//			return false;
//		}
//
//		_pRenderer = SDL_CreateRenderer(_pWindow, -1, SDL_RENDERER_ACCELERATED);
//		if (!_pRenderer) {
//			printf("Renderer could not be created!\nSDL_Error: %s\n", SDL_GetError());
//			return false;
//		}
//
//		_pLogger->Log("Hello world");
//
//		return _initialized = true;
//	}
//
//	void Run() {
//		Initialize();
//
//		_continue = true;
//		while (_continue) {
//
//			SDL_Event e;
//			SDL_WaitEvent(&e);
//
//			// User requests quit
//			if (e.type == SDL_QUIT) {
//				_continue = false;
//			}
//
//			// Initialize renderer color white for the background
//			SDL_SetRenderDrawColor(_pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
//
//			// Clear screen
//			SDL_RenderClear(_pRenderer);
//
//			// Update screen
//			SDL_RenderPresent(_pRenderer);
//		}
//	}
//
//	void Stop() {
//		_continue = false;
//	}
//
//private:
//	const int _screenWidth{};
//	const int _screenHeight{};
//
//	const char* _pName{};
//	SDL_Renderer* _pRenderer{};
//	SDL_Window* _pWindow{};
//	Logger* _pLogger{};
//
//	bool _initialized{ false };
//	bool _continue{ false };
//};
//
