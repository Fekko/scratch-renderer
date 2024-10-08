#include "Application_SDL2.h"
#include "FactoryContainer.h"
#include <iostream>

#include "Logging.h"

using namespace logging;


namespace A
{
	class Test
	{
	public:
		void static Function() {
			__INFO__("Hello FROM FUNCTION");
			return;
		}
	};
}


int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
	//FactoryContainer* fc = new FactoryContainer();

	//fc->Add<Logger>();
	//fc->Add<Application_SDL2>([](FactoryContainer& f) -> Application_SDL2* { return new Application_SDL2("APP", 800, 600, &f.Get<Logger>()); });

	//fc->Get<Application_SDL2>().Run();

	//delete fc;
	//fc = nullptr;

	// Example logs
	__INFO__("This is an info message");
	__WARN__("This is a want message");
	__ERROR__("This is a fatal message");
	A::Test::Function();

	return 0;
}

