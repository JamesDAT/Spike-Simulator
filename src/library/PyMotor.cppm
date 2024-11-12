module;
#include <Python.h>
export module PyLibrary:PyMotor;
import std;

namespace SpkSim {
    static PyObject* run(PyObject* self, PyObject* args) {
        int port, velocity;
        int acceleration = 1000; // deg/sec

        // Parse the three integers from args
        if (!PyArg_ParseTuple(args, "iii", &port, &velocity, &acceleration)) {
            return nullptr; // Return null if parsing failed
        }

        Py_RETURN_NONE;
    }

    static PyMethodDef Methods[] = {
        {"run", run, METH_VARARGS, "Run motor in a given port"},
        {nullptr, nullptr, 0, nullptr} // signal end of array
    };

    static struct PyModuleDef ModuleDef = {
        PyModuleDef_HEAD_INIT,
        "motor",
        "",
        -1,
        Methods
    };

    export PyMODINIT_FUNC Motor_Init() {
        PyObject* pymod = PyModule_Create(&ModuleDef);
        if (pymod == nullptr) return nullptr;

        return pymod;
    }

	export class PyMotor {
	public:
		PyMotor() {}
		~PyMotor() {
			delete m_pmotorModule;
			delete m_psysModules;
		}

		void CreateMotorModule() {
			m_pmotorModule = Motor_Init();
			if (m_pmotorModule == nullptr) {
				throw std::exception("Failed to get motor module");
			}

			m_psysModules = PyImport_GetModuleDict();
			PyDict_SetItemString(m_psysModules, "motor", m_pmotorModule);
		}
	private:
		PyObject* m_pmotorModule;
		PyObject* m_psysModules;
	};
}