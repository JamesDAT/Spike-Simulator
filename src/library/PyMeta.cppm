module;
#include <Python.h>
export module PyLibrary:PyMeta;
import std;

namespace SpkSim {
    static PyObject* print(PyObject* self, PyObject* args) {
        const char* inputText;
        if (!PyArg_ParseTuple(args, "s", &inputText)) {
            return nullptr;
        }

        std::print("{}", inputText);

        Py_RETURN_NONE;
    }

    static PyObject* print_line(PyObject* self, PyObject* args) {
        const char* inputText;
        if (!PyArg_ParseTuple(args, "s", &inputText)) {
            return nullptr;
        }

        std::println("{}", inputText);

        Py_RETURN_NONE;
    }

    static PyMethodDef Methods[] = {
        {"print", print, METH_VARARGS, "Print to Stdout"},
        {"print_line", print_line, METH_VARARGS, "Print line to Stdout"},
        {nullptr, nullptr, 0, nullptr} // signal end of array
    };

    static struct PyModuleDef ModuleDef = {
        PyModuleDef_HEAD_INIT,
        "Meta",
        "",
        -1,
        Methods
    };

    export PyMODINIT_FUNC Meta_Init() {
        PyObject* pymod = PyModule_Create(&ModuleDef);
        if (pymod == nullptr) return nullptr;

        return pymod;
    }

    export class PyMeta {
    public:
        PyMeta() {}
        ~PyMeta() {
            delete m_pmetaModule;
            delete m_psysModules;
        }

        void CreateMetaModule() {
            m_pmetaModule = Meta_Init();
            if (m_pmetaModule == nullptr) {
                throw std::exception("Failed to get meta module");
            }

            m_psysModules = PyImport_GetModuleDict();
            PyDict_SetItemString(m_psysModules, "meta", m_pmetaModule);
        }

    private:
        PyObject* m_pmetaModule;
        PyObject* m_psysModules;
    };
}
