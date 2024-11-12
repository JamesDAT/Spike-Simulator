#include <Python.h>
#include <iostream>
#include <string>
#include <thread>
#include <future>
#include <functional>

// Function with no parameters and no return type
static PyObject* no_params_no_return(PyObject* self, PyObject* args) {
    std::cout << "C++: Function with no parameters and no return type called." << std::endl;
    Py_RETURN_NONE;  // This is the equivalent of returning `None` in Python.
}

// Function returning an integer
static PyObject* return_integer(PyObject* self, PyObject* args) {
    int result = 42;
    return PyLong_FromLong(result);  // Return an integer to Python
}

// Function that takes an integer parameter and returns an integer
static PyObject* square_integer(PyObject* self, PyObject* args) {
    int number;
    if (!PyArg_ParseTuple(args, "i", &number)) {  // Parse an integer argument
        return nullptr;
    }
    int result = number * number;
    return PyLong_FromLong(result);  // Return the square as an integer
}

// Function that takes a string parameter and returns a string
static PyObject* greet_user(PyObject* self, PyObject* args) {
    const char* name;
    if (!PyArg_ParseTuple(args, "s", &name)) {  // Parse a string argument
        return nullptr;
    }
    std::string greeting = "Hello, " + std::string(name) + "!";
    return PyUnicode_FromString(greeting.c_str());  // Return greeting as a Python string
}

static PyObject* process_boolean(PyObject* self, PyObject* args) {
    int result1, result2, result3;
    int flag;  // Boolean values are usually represented as ints in the Python API

    // Parse the boolean argument from args
    if (!PyArg_ParseTuple(args, "p", &flag)) {  // "p" is for parsing a boolean as an integer (0 or 1)
        return nullptr; // Return null if parsing failed
    }

    // Perform calculations based on the boolean flag
    if (flag) {
        result1 = 10;
        result2 = 20;
        result3 = 30;
    }
    else {
        result1 = -10;
        result2 = -20;
        result3 = -30;
    }

    // Create a Python tuple with the three integer results
    return PyTuple_Pack(3, PyLong_FromLong(result1), PyLong_FromLong(result2), PyLong_FromLong(result3));
}

// usage involves name values, by calling in python process_data(integer_val=15, double_val=10): etc
// Function that takes an integer, a double, and a string, with default values
static PyObject* process_data(PyObject* self, PyObject* args, PyObject* kwargs) {
    // Define default values
    int integer_val = 10;        // Default integer
    double double_val = 1.5;     // Default double
    const char* str_val = "Hello";  // Default string

    // Define keyword arguments
    static const char* kwlist[] = { "integer_val", "double_val", "str_val", nullptr };

    // Parse the arguments with defaults if not provided
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "|ids", const_cast<char**>(kwlist),
        &integer_val, &double_val, &str_val)) {
        return nullptr; // Argument parsing failed
    }

    // Output the values (in practice, replace this with your processing logic)
    std::cout << "Integer Value: " << integer_val << std::endl;
    std::cout << "Double Value: " << double_val << std::endl;
    std::cout << "String Value: " << str_val << std::endl;

    // Return None
    Py_RETURN_NONE;
}

// Function that accepts an async Python function and calls it asynchronously
static PyObject* async_callback(PyObject* self, PyObject* args) {
    PyObject* py_callback;

    // Parse a callable (function) object
    if (!PyArg_ParseTuple(args, "O", &py_callback)) {
        return nullptr;
    }

    // Check if the object is callable
    if (!PyCallable_Check(py_callback)) {
        PyErr_SetString(PyExc_TypeError, "Parameter must be callable");
        return nullptr;
    }

    // Increment the reference count for the callback to use it in a new thread
    Py_INCREF(py_callback);

    // Run the callback in a separate thread asynchronously
    std::thread([py_callback]() {
        // Acquire the GIL (Global Interpreter Lock) for this thread
        PyGILState_STATE gstate = PyGILState_Ensure();

        // Call the Python function with no arguments
        PyObject* result = PyObject_CallObject(py_callback, nullptr);

        // Check for errors
        if (result == nullptr) {
            PyErr_Print();  // Print error to stderr
        }
        else {
            // Release the result
            Py_DECREF(result);
        }

        // Release the GIL and the function reference
        PyGILState_Release(gstate);
        Py_DECREF(py_callback);
        }).detach();  // Detach thread so it runs independently

    Py_RETURN_NONE;
}

// Method definition table
static PyMethodDef MyMethods[] = {
    {"no_params_no_return", no_params_no_return, METH_NOARGS, "Function with no parameters and no return value"},
    {"return_integer", return_integer, METH_NOARGS, "Function that returns an integer"},
    {"square_integer", square_integer, METH_VARARGS, "Function that squares an integer parameter and returns an integer"},
    {"greet_user", greet_user, METH_VARARGS, "Function that takes a string parameter and returns a greeting"},
    {"process_data", (PyCFunction)process_data, METH_VARARGS | METH_KEYWORDS, "Process data with integer, double, and string parameters."},
    {"process_boolean", process_boolean, METH_VARARGS, "Process a boolean and return a tuple of three integers."},
    {"async_callback", async_callback, METH_VARARGS, "Function that takes an async callback and runs it asynchronously"},
    {nullptr, nullptr, 0, nullptr}  // Sentinel
};

// Module definition
static struct PyModuleDef MyModule = {
    PyModuleDef_HEAD_INIT,
    "mymodule",
    nullptr,
    -1,
    MyMethods
};

extern "C" {
    PyMODINIT_FUNC PyInit_mymodule(void) {
        return PyModule_Create(&MyModule);
    }
}