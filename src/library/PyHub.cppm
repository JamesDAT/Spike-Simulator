/// <summary>
/// This testing code should outline the template for creating python modules and how they are implemented further
/// </summary>
module;
#include <Python.h>;
export module PyLibrary:PyHub;

import std;

namespace SpkSim {

    static PyObject* print_out(PyObject* self, PyObject* args) {
        const char* msg;
        if (!PyArg_ParseTuple(args, "s", &msg)) {
            return nullptr; // Error in argument parsing
        }
        std::cout << "Called from Python: " << msg << std::endl;
        Py_RETURN_NONE;
    }

    static PyMethodDef HubMethods[] = {
        {"print_out", print_out, METH_VARARGS, "Meta test function for cpp printing"},
        {nullptr, nullptr, 0, nullptr}
    };

    static struct PyModuleDef HubModuleDef = {
        PyModuleDef_HEAD_INIT,
        "hub",
        nullptr,
        -1,
        HubMethods
    };

    extern "C" {
        PyMODINIT_FUNC PyInit_Hub(void) {
            return PyModule_Create(&HubModuleDef);
        }
    }

    export class PyHub {
    public:
        PyHub() {}
        ~PyHub() {
            delete m_phubModule;
            delete m_psysModules;
        }

        void CreateHubModule() {

            m_phubModule = PyInit_Hub();
            if (m_phubModule == nullptr) {
                throw std::exception("Failed to get hub module");
            }

            m_psysModules = PyImport_GetModuleDict();
            PyDict_SetItemString(m_psysModules, "hub", m_phubModule);
        }
    private:
        PyObject* m_phubModule;
        PyObject* m_psysModules;
    };
}
