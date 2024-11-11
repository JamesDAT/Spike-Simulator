module;

export module Simulation;
import RobotBase;
import std;

namespace SpkSim {
	export class Simulation {
	public:
		Simulation();
		~Simulation();

	private:
		std::unique_ptr<RobotBase> m_robotBase;
	};
}