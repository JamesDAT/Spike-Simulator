module;
export module Renderer;

namespace SpkSim {
	export class Renderer {
	public:
		Renderer();
		~Renderer();

		void Initialize();
		void RenderFrame();
	};
}