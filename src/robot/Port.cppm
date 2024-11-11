module;
export module Port;
import SensorBase;
import std;

namespace SpkSim {
	export class Port {
	public:

	private:
		std::shared_ptr<SensorBase> m_pconnectedSensor{};
	};
}