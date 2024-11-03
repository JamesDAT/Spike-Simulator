#include <iostream>
#include <string>
#include <Python.h>

static PyObject* cpp_function(PyObject* self, PyObject* args) {
    const char* msg;
    if (!PyArg_ParseTuple(args, "s", &msg)) {
        return nullptr; // Error in argument parsing
    }

    std::cout << "Called from Python: " << msg << std::endl;
    Py_RETURN_NONE;
}

// Method definition table
static PyMethodDef MyMethods[] = {
    {"cpp_function", cpp_function, METH_VARARGS, "A function that prints a message from Python."},
    {nullptr, nullptr, 0, nullptr} // Sentinel
};

// Module definition
static struct PyModuleDef mymodule = {
    PyModuleDef_HEAD_INIT,
    "mymodule",
    nullptr,
    -1,
    MyMethods
};

// Module initialization function with C linkage
extern "C" {
    PyMODINIT_FUNC PyInit_mymodule(void) {
        return PyModule_Create(&mymodule);
    }
}

int main() {
    // Initialize the Python Interpreter
    Py_Initialize();

    // Create the C++ module and add it to sys.modules
    PyObject* mymodule = PyInit_mymodule();
    if (mymodule != nullptr) {
        PyObject* sys_modules = PyImport_GetModuleDict();
        PyDict_SetItemString(sys_modules, "mymodule", mymodule);

        // Open the Python script and execute it
        const char* scriptPath = "Test.py"; // Update this to your script's path
        FILE* fp = fopen(scriptPath, "r");
        if (fp != nullptr) {
            PyRun_SimpleFile(fp, scriptPath);
            fclose(fp);
        }
        else {
            PyErr_Print(); // Print error if the file cannot be opened
        }

        Py_DECREF(mymodule);
    }
    else {
        PyErr_Print(); // Print error if the module could not be created
    }

    // Finalize the Python Interpreter
    Py_Finalize();
    return 0;
}

