/// <summary>
/// This testing code should outline the template for creating python modules and how they are implemented further
/// </summary>
module;
#include <Python.h>;
export module PyLibrary:PyHub;
import :PyHub.Port;
import :PyHub.Sound;
import :PyHub.Button;
import :PyHub.Light;
import :PyHub.Light_Matrix;

import std;

namespace SpkSim {

    static PyObject* device_uuid(PyObject* self, PyObject* args) {
        return PyUnicode_FromString("550e8400-e29b-41d4-a716-446655440000"); // filler UUID
    }

    static PyObject* hardware_id(PyObject* self, PyObject* args) {
        return PyUnicode_FromString("550e8400-e29b-41d4-a716-446655440000"); // filler id
    }

    static PyObject* power_off(PyObject* self, PyObject* args) {
        // should stop the simulation
        return PyLong_FromLong(0); // unknown what the real thing returns
    }

    static PyObject* temperature(PyObject* self, PyObject* args) {
        // 18C
        return PyLong_FromLong(180); // returns 180 Decidegrees celcius
    }

    // Register all the methods for the module
    static PyMethodDef HubMethods[] = {
        {"device_uuid", device_uuid, METH_NOARGS, "Retrieve the device id."},
        {"hardware_id", hardware_id, METH_NOARGS, "Retrieve the hardware id."},
        {"power_off", power_off, METH_NOARGS, "Turns off the hub."},
        {"temperature", temperature, METH_NOARGS, "Retrieve the hub temperature. Measured in decidegrees celsius (d°C) which is 1 / 10 of a degree celsius (°C)"},
        {nullptr, nullptr, 0, nullptr} // signal end of array
    };

    // Defines the module for importing into python
    static struct PyModuleDef HubModuleDef = {
        PyModuleDef_HEAD_INIT,
        "hub",
        nullptr,
        -1,
        HubMethods
    };

    // Creates the modules for python
    extern "C" {
        PyMODINIT_FUNC PyInit_Hub(void) {
            PyObject* pymod = PyModule_Create(&HubModuleDef);
            if (pymod == nullptr) return nullptr;

            // add the sub modules to the hub module 'pymod'
            PyModule_AddObject(pymod, "port", Port_Init());
            PyModule_AddObject(pymod, "sound", Sound_Init());
            PyModule_AddObject(pymod, "button", Button_Init());
            PyModule_AddObject(pymod, "light", Light_Init());
            PyModule_AddObject(pymod, "light_matrix", LightMatrix_Init());

            return pymod;
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
