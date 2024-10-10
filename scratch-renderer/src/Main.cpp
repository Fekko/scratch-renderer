#include "ApplicationSDL2.h"
#include "FactoryContainer.h"
#include <iostream>

#include "Logging.h"

using namespace ScratchRenderer;

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
	__INFO__("Hello world");

	auto* app = new ScratchRenderer::ApplicationSDL2("APP", 800, 600);


	app->Run();

	__INFO__("Goodbye world");
	return 0;
}

