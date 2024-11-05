module;
#include <Python.h>
export module PyLibrary:PyHub.Button;

namespace SpkSim {

    static PyObject* pressed(PyObject* self, PyObject* args) {
        int button;
        if (!PyArg_ParseTuple(args, "i", &button)) { // parse number argument
            return nullptr;
        }

        // check if button is pressed
        Py_RETURN_FALSE;
    }

    static PyMethodDef Methods[] = {
        {"pressed", pressed, METH_VARARGS, "This module allows you to react to buttons being pressed on the hub. You must first import the button module to use the buttons."},
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
    export PyMODINIT_FUNC Button_Init() {
        PyObject* pymod = PyModule_Create(&ModuleDef);
        if (pymod == nullptr) return nullptr;

        PyModule_AddIntConstant(pymod, "LEFT", 1);
        PyModule_AddIntConstant(pymod, "RIGHT", 2);

        return pymod;
    }
}