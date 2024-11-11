module;
export module RobotBase;
import Port;
import glm;

namespace SpkSim {
	export class RobotBase {
	public:
		enum class BaseShape {
			Circle = 0,
			Square = 1,
			Triangle = 2
		};

		RobotBase() {}
		~RobotBase() {}

		inline const auto& GetPos() const {
			return position;
		}

		inline const auto& GetSize() const {
			return size;
		}

		inline const auto& GetRot() const {
			return rotation;
		}

		inline const auto& GetShape() const{
			return baseShape;
		}

		inline void SetPos(glm::vec2& inPos) {
			position = inPos;
		}
		
		inline void SetSize(glm::vec2& inSize) {
			size = inSize;
		}

		inline void SetRot(glm::vec1& inRot) {
			inRot = rotation;
		}

		inline void SetShape(BaseShape shape) {
			baseShape = shape;
		}

	private:
		glm::vec2 position{ 0.f, 0.f }; 
		glm::vec2 size{ 100.f, 100.f }; // size in mm
		glm::vec1 rotation{ 0.f };

		BaseShape baseShape = BaseShape::Square;
		Port portA{};
		Port portB{};
		Port portC{};
		Port portD{};
		Port portE{};
		Port portF{};
	};
}