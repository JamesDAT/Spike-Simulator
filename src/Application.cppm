module;
export module Application;
import Window;
import Renderer;
import Simulation;
import PyLibrary;
import std;

namespace SpkSim {
	export class Application {
	public:
		Application();
		~Application();

		void Run();

	private:
		void MainLoop();

		Window m_window{};
		Renderer m_renderer{};
		PyLibrary m_pylib{};
		Simulation m_simulation{};
	};
}