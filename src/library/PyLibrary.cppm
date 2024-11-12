/// <summary>
/// This testing code should outline the template for creating python modules and how they are implemented further
/// </summary>
module;
#include <Python.h>
export module PyLibrary;
import :PyHub;
import :PyMeta;
import :PyMotor;
import :PyColor_Sensor;
import std;

namespace SpkSim {
	export class PyLibrary {
	public:
		PyLibrary() {

		}

		~PyLibrary() {

		}

		// initialize all the python modules
		void Run() {
			Py_Initialize();

			m_pyHub.CreateHubModule();
			m_pyMeta.CreateMetaModule();
			m_pyMotor.CreateMotorModule();
			m_pyColorSensor.CreateColorSensorModule();
			

			std::string scriptPath = "Test.py";
			FILE* pfile = fopen(scriptPath.c_str(), "r");

			if (pfile == nullptr) {
				throw std::exception("Unable to open python file");
			}

			PyRun_SimpleFile(pfile, scriptPath.c_str());
			Py_Finalize();
		}

	private:
		PyHub m_pyHub{};
		PyMeta m_pyMeta{};
		PyMotor m_pyMotor{};
		PyColor_Sensor m_pyColorSensor{};
	};
}