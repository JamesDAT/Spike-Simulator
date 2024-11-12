module;
#include <Python.h>
export module PyLibrary:PyHub.Motion_Sensor;

namespace SpkSim {

	static PyObject* acceleration(PyObject* self, PyObject* args) {
		int x = 0, y = 0, z = 0;
		int isRaw = 0;

		return PyTuple_Pack(3, PyLong_FromLong(x), PyLong_FromLong(y), PyLong_FromLong(z));
	}

	static PyObject* tilt_angles(PyObject* self, PyObject* args) {
		int yaw = 0, pitch = 0, roll = 0;

		return PyTuple_Pack(3, PyLong_FromLong(yaw), PyLong_FromLong(pitch), PyLong_FromLong(roll));
	}

	static PyMethodDef Methods[] = {
		{"acceleration", acceleration, METH_VARARGS, "Returns a tuple containing x, y & z acceleration values as integers. The values are in mg (0.001 g)"},
		{"tilt_angles", tilt_angles, METH_NOARGS, "Returns a tuple containing yaw pitch and roll values as integers. Values are decidegrees"},
		{nullptr, nullptr, 0, nullptr} // signal end of array
	};

	static struct PyModuleDef ModuleDef = {
		PyModuleDef_HEAD_INIT,
		"motion_sensor",
		"",
		-1,
		Methods
	};

	export PyMODINIT_FUNC MotionSensor_Init() {
		PyObject* pymod = PyModule_Create(&ModuleDef);
		if (pymod == nullptr) return nullptr;

		return pymod;
	}
}