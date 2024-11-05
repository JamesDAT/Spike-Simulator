/// <summary>
/// This testing code should outline the template for creating python modules and how they are implemented further
/// </summary>
module;
#include <Python.h>
export module PyLibrary;
import :PyHub;
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
	};
}