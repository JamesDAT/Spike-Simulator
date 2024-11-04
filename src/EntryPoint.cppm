module;
export module EntryPoint;
import Application;
import std;

export int main(int argc, char** argv) {
	std::unique_ptr app = std::make_unique<SpkSim::Application>();
	try {
		app->Run();
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
}