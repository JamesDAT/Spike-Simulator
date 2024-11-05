module;
#include <Python.h>
export module PyLibrary:PyHub.Light;

namespace SpkSim {

    static PyObject* color(PyObject* self, PyObject* args) {
        //light: int, color: int

        // check if button is pressed
        Py_RETURN_FALSE;
    }

    static PyMethodDef Methods[] = {
        {"color", color, METH_VARARGS, "Change the color of a light on the hub."},
        {nullptr, nullptr, 0, nullptr} // signal end of array
    };

    static struct PyModuleDef ModuleDef = {
        PyModuleDef_HEAD_INIT,
        "light",
        "",
        -1,
        Methods
    };

    // create the module and assign the constants
    export PyMODINIT_FUNC Light_Init() {
        PyObject* pymod = PyModule_Create(&ModuleDef);
        if (pymod == nullptr) return nullptr;

        PyModule_AddIntConstant(pymod, "POWER", 0);
        PyModule_AddIntConstant(pymod, "CONNECT", 1);

        return pymod;
    }
}