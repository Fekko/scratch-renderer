#include "Application.h"
#include "Logging.h"

using namespace ScratchRenderer;

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
	__INFO__("Hello world");

	const char* TITLE = "APP";
	constexpr int WIDTH = 1920;
	constexpr int HEIGHT = 1080;

	auto* app = new ScratchRenderer::Application(TITLE, WIDTH, HEIGHT);

	app->Run();

	__INFO__("Goodbye world");
	return 0;
}

