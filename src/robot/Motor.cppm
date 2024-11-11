module;

export module Motor;
import SensorBase;
import glm;
import std;

namespace SpkSim {
	export class Motor : public SensorBase {
	public:
		Motor() {}
		~Motor() {}

		inline const auto& GetOffset() const {
			return offset;
		}

		inline const auto& GetRotation() const {
			return rotation;
		}

	private:
		glm::vec2 offset{ 0.f, 0.f }; // offset from center of robot the the motor
		glm::vec1 rotation{ 0.f }; // 2d rotation about the z axis

	};
}