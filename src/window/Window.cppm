module;
export module Window;
import <GLFW/glfw3.h>;
import std;

namespace SpkSim {
	export class Window {
	public:
		Window();
		~Window();

		void Initialize();
		bool Update();

		static int FrameWidth, FrameHeight;
	private:
		GLFWwindow* m_pWindow{};
	};
}