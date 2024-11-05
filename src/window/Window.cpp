module;
module Window;
import <GLFW/glfw3.h>;
import std;

namespace SpkSim {
	int Window::FrameHeight = 1080;
	int Window::FrameWidth = 1920;

	Window::Window() {

	}

	void Window::Initialize() {
		if (glfwInit() == GLFW_FALSE) {
			throw std::exception("Error Initializing GLFW!");
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
		m_pWindow = glfwCreateWindow(1920, 1080, "Spike Simulator", nullptr, nullptr);
		if (m_pWindow == nullptr) {
			throw std::exception("Error creating GLFW window!");
		}
		glfwMakeContextCurrent(m_pWindow);

		glfwSetWindowSizeCallback(m_pWindow, [](GLFWwindow* window, int width, int height)
			{
				FrameWidth = width;
				FrameHeight = height;
			}
		);
	}

	bool Window::Update() {
		glfwPollEvents();
		glfwSwapBuffers(m_pWindow);
		return !glfwWindowShouldClose(m_pWindow);
	}

	Window::~Window() {
		glfwTerminate();
		delete m_pWindow;
	}
}