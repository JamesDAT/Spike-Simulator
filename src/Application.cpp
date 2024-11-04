module Application;

namespace SpkSim {
	Application::Application() {

	}

	void Application::Run() {
		m_window.Initialize();
		m_renderer.Initialize();

		MainLoop();
	}

	void Application::MainLoop() {
		while (m_window.Update()) {
			m_renderer.RenderFrame();
		}
	}

	Application::~Application() {

	}
}