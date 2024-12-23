module;
#include <Python.h>
export module PyLibrary:PyHub.Port;

namespace SpkSim {
    static PyMethodDef Methods[] = {
        {nullptr, nullptr, 0, nullptr} // signal end of array
    };

    static struct PyModuleDef ModuleDef = {
        PyModuleDef_HEAD_INIT,
        "port",
        "This module contains constants that enables easy access to the ports on the SPIKE Prime hub. Use the constants in all functions that takes a port parameter.",
        -1,
        Methods
    };

    // create the Port module and assign the constants
    export PyMODINIT_FUNC Port_Init() {
        PyObject* pymod = PyModule_Create(&ModuleDef);
        if (pymod == nullptr) return nullptr;

        PyModule_AddIntConstant(pymod, "A", 0);
        PyModule_AddIntConstant(pymod, "B", 1);
        PyModule_AddIntConstant(pymod, "C", 2);
        PyModule_AddIntConstant(pymod, "D", 3);
        PyModule_AddIntConstant(pymod, "E", 4);
        PyModule_AddIntConstant(pymod, "F", 5);

        return pymod;
    }
}