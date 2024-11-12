module;
#include <Python.h>
export module PyLibrary:PyColor_Sensor;
import std;

namespace SpkSim {

	static PyObject* rgbi(PyObject* self, PyObject* args) {
		int red = 0, green = 0, blue = 0, intensity = 0;
		int port = 0;

		if (!PyArg_ParseTuple(args, "i", &port)) {
			return nullptr; // Return null if parsing failed
		}

		return PyTuple_Pack(4, PyLong_FromLong(red), PyLong_FromLong(green), PyLong_FromLong(blue), PyLong_FromLong(intensity));
	}

	static PyMethodDef Methods[] = {
		{"rgbi", rgbi, METH_VARARGS, "Run motor in a given port"},
		{nullptr, nullptr, 0, nullptr} // signal end of array
	};

	static struct PyModuleDef ModuleDef = {
		PyModuleDef_HEAD_INIT,
		"color_sensor",
		"",
		-1,
		Methods
	};

	export PyMODINIT_FUNC ColorSensor_Init() {
		PyObject* pymod = PyModule_Create(&ModuleDef);
		if (pymod == nullptr) return nullptr;

		return pymod;
	}

	export class PyColor_Sensor {
	public:
		PyColor_Sensor() {}
		~PyColor_Sensor() {
			delete m_pcolorSensorModule;
			delete m_psysModules;
		}

		void CreateColorSensorModule() {
			m_pcolorSensorModule = ColorSensor_Init();
			if (m_pcolorSensorModule == nullptr) {
				throw std::exception("Failed to get motor module");
			}

			m_psysModules = PyImport_GetModuleDict();
			PyDict_SetItemString(m_psysModules, "color_sensor", m_pcolorSensorModule);
		}
	private:
		PyObject* m_pcolorSensorModule;
		PyObject* m_psysModules;
	};
}