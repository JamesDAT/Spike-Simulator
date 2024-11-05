module;
#include <Python.h>
export module PyLibrary:PyHub.Sound;

namespace SpkSim {

    static PyObject* beep(PyObject* self, PyObject* args) {
        // parameters will need to be implemented if sound is actually to play
        // for now sound isn't a goal, so this can just return
        Py_RETURN_NONE;
    }

    static PyObject* stop(PyObject* self, PyObject* args) {
        Py_RETURN_NONE;
    }

    static PyObject* volume(PyObject* self, PyObject* args) {
        Py_RETURN_NONE;
    }

    static PyMethodDef Methods[] = {
        {"beep", beep, METH_VARARGS, "Plays a beep sound from the hub"},
        {"stop", stop, METH_NOARGS, "Stops all noise from the hub"},
        {"volume", volume, METH_VARARGS, ""},
        {nullptr, nullptr, 0, nullptr} // signal end of array
    };

    static struct PyModuleDef ModuleDef = {
        PyModuleDef_HEAD_INIT,
        "hub",
        "This module contains constants that enables easy access to the ports on the SPIKE Prime hub. Use the constants in all functions that takes a port parameter.",
        -1,
        Methods
    };

    // create the module and assign the constants
    export PyMODINIT_FUNC Sound_Init() {
        PyObject* pymod = PyModule_Create(&ModuleDef);
        if (pymod == nullptr) return nullptr;

        PyModule_AddIntConstant(pymod, "ANY", -2);
        PyModule_AddIntConstant(pymod, "DEFAULT", -1);
        PyModule_AddIntConstant(pymod, "WAVEFORM_SINE", 1);
        PyModule_AddIntConstant(pymod, "WAVEFORM_SAWTOOTH", 3);
        PyModule_AddIntConstant(pymod, "WAVEFORM_SQUARE", 2);
        PyModule_AddIntConstant(pymod, "WAVEFORM_TRIANGLE", 1);

        return pymod;
    }
}