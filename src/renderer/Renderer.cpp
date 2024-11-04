module Renderer;
#include <glad/glad.h>
import <GLFW/glfw3.h>;
import Window;
import std;

namespace SpkSim {
	Renderer::Renderer() {

	}

	void Renderer::Initialize() {
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			throw std::exception("Failed to initialize Glad!");
		}

		glViewport(0, 0, Window::FrameWidth, Window::FrameHeight);

	}

	void Renderer::RenderFrame() {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	Renderer::~Renderer() {

	}
}