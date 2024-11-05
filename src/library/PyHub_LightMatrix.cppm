module;
#include <Python.h>
export module PyLibrary:PyHub.Light_Matrix;

namespace SpkSim {

    static PyObject* clear(PyObject* self, PyObject* args) {
        Py_RETURN_NONE;
    }

    static PyObject* get_orientation(PyObject* self, PyObject* args) {
        return PyLong_FromLong(0); // placeholder
    }

    static PyObject* get_pixel(PyObject* self, PyObject* args) {
        //x: int, y: int
        return PyLong_FromLong(0); // placeholder
    }

    static PyObject* set_orientation(PyObject* self, PyObject* args) {
        //top: int
        return PyLong_FromLong(0); // placeholder
    }

    static PyObject* set_pixel(PyObject* self, PyObject* args) {
        //x: int. y: int, intensity: int
        Py_RETURN_NONE;
    }

    static PyObject* show(PyObject* self, PyObject* args) {
        //pixels: list[int]
        Py_RETURN_NONE;
    }

    static PyObject* show_image(PyObject* self, PyObject* args) {
        //image: int
        Py_RETURN_NONE;
    }

    static PyObject* write(PyObject* self, PyObject* args) {
        //text: str, intensity: int = 100, time_per_character: int = 500
        Py_RETURN_NONE;
    }

    static PyMethodDef Methods[] = {
        {"clear", clear, METH_NOARGS, "Switches off all of the pixels on the Light Matrix."},
        {"get_orientation", get_orientation, METH_NOARGS, "Retrieve the current orientation of the Light Matrix."},
        {"get_pixel", get_pixel, METH_VARARGS, "Retrieve the intensity of a specific pixel on the Light Matrix."},
        {"set_orientation", set_orientation, METH_VARARGS, "Change the orientation of the Light Matrix. All subsequent calls will use the new orientation."},
        {"set_pixel", set_pixel, METH_VARARGS, "Sets the brightness of one pixel (one of the 25 LEDs) on the Light Matrix."},
        {"show", show, METH_VARARGS, "Change all the lights at the same time."},
        {"show_image", show_image, METH_VARARGS, "Display one of the built in images on the display."},
        {"write", write, METH_VARARGS, "Displays text on the Light Matrix, one letter at a time, scrolling from right to left except if there is a single character to show which will not scroll"},

        {nullptr, nullptr, 0, nullptr} // signal end of array
    };

    static struct PyModuleDef ModuleDef = {
        PyModuleDef_HEAD_INIT,
        "light_matrix",
        "",
        -1,
        Methods
    };

    // create the module and assign the constants
    export PyMODINIT_FUNC LightMatrix_Init() {
        PyObject* pymod = PyModule_Create(&ModuleDef);
        if (pymod == nullptr) return nullptr;

        PyModule_AddIntConstant(pymod, "IMAGE_HEART", 1);
        PyModule_AddIntConstant(pymod, "IMAGE_HEART_SMALL", 2);
        PyModule_AddIntConstant(pymod, "IMAGE_HAPPY", 3);
        PyModule_AddIntConstant(pymod, "IMAGE_SMILE", 4);
        PyModule_AddIntConstant(pymod, "IMAGE_SAD", 5);
        PyModule_AddIntConstant(pymod, "IMAGE_CONFUSED", 6);
        PyModule_AddIntConstant(pymod, "IMAGE_ANGRY", 7);
        PyModule_AddIntConstant(pymod, "IMAGE_ASLEEP", 8);
        PyModule_AddIntConstant(pymod, "IMAGE_SURPRISED", 9);
        PyModule_AddIntConstant(pymod, "IMAGE_SILLY", 10);
        PyModule_AddIntConstant(pymod, "IMAGE_FABULOUS", 11);
        PyModule_AddIntConstant(pymod, "IMAGE_MEH", 12);
        PyModule_AddIntConstant(pymod, "IMAGE_YES", 13);
        PyModule_AddIntConstant(pymod, "IMAGE_NO", 14);
        PyModule_AddIntConstant(pymod, "IMAGE_CLOCK12", 15);
        PyModule_AddIntConstant(pymod, "IMAGE_CLOCK1", 16);
        PyModule_AddIntConstant(pymod, "IMAGE_CLOCK2", 17);
        PyModule_AddIntConstant(pymod, "IMAGE_CLOCK3", 18);
        PyModule_AddIntConstant(pymod, "IMAGE_CLOCK4", 19);
        PyModule_AddIntConstant(pymod, "IMAGE_CLOCK5", 20);
        PyModule_AddIntConstant(pymod, "IMAGE_CLOCK6", 21);
        PyModule_AddIntConstant(pymod, "IMAGE_CLOCK7", 22);
        PyModule_AddIntConstant(pymod, "IMAGE_CLOCK8", 23);
        PyModule_AddIntConstant(pymod, "IMAGE_CLOCK9", 24);
        PyModule_AddIntConstant(pymod, "IMAGE_CLOCK10", 25);
        PyModule_AddIntConstant(pymod, "IMAGE_CLOCK11", 26);
        PyModule_AddIntConstant(pymod, "IMAGE_ARROW_N", 27);
        PyModule_AddIntConstant(pymod, "IMAGE_ARROW_NE", 28);
        PyModule_AddIntConstant(pymod, "IMAGE_ARROW_E", 29);
        PyModule_AddIntConstant(pymod, "IMAGE_ARROW_SE", 30);
        PyModule_AddIntConstant(pymod, "IMAGE_ARROW_S", 31);
        PyModule_AddIntConstant(pymod, "IMAGE_ARROW_SW", 32);
        PyModule_AddIntConstant(pymod, "IMAGE_ARROW_W", 33);
        PyModule_AddIntConstant(pymod, "IMAGE_ARROW_NW", 34);
        PyModule_AddIntConstant(pymod, "IMAGE_GO_RIGHT", 35);
        PyModule_AddIntConstant(pymod, "IMAGE_GO_LEFT", 36);
        PyModule_AddIntConstant(pymod, "IMAGE_GO_UP", 37);
        PyModule_AddIntConstant(pymod, "IMAGE_GO_DOWN", 38);
        PyModule_AddIntConstant(pymod, "IMAGE_TRIANGLE", 39);
        PyModule_AddIntConstant(pymod, "IMAGE_TRIANGLE_LEFT", 40);
        PyModule_AddIntConstant(pymod, "IMAGE_CHESSBOARD", 41);
        PyModule_AddIntConstant(pymod, "IMAGE_DIAMOND", 42);
        PyModule_AddIntConstant(pymod, "IMAGE_DIAMOND_SMALL", 43);
        PyModule_AddIntConstant(pymod, "IMAGE_SQUARE", 44);
        PyModule_AddIntConstant(pymod, "IMAGE_SQUARE_SMALL", 45);
        PyModule_AddIntConstant(pymod, "IMAGE_RABBIT", 46);
        PyModule_AddIntConstant(pymod, "IMAGE_COW", 47);
        PyModule_AddIntConstant(pymod, "IMAGE_MUSIC_CROTCHET", 48);
        PyModule_AddIntConstant(pymod, "IMAGE_MUSIC_QUAVER", 49);
        PyModule_AddIntConstant(pymod, "IMAGE_MUSIC_QUAVERS", 50);
        PyModule_AddIntConstant(pymod, "IMAGE_PITCHFORK", 51);
        PyModule_AddIntConstant(pymod, "IMAGE_XMAS", 52);
        PyModule_AddIntConstant(pymod, "IMAGE_PACMAN", 53);
        PyModule_AddIntConstant(pymod, "IMAGE_TARGET", 54);
        PyModule_AddIntConstant(pymod, "IMAGE_TSHIRT", 55);
        PyModule_AddIntConstant(pymod, "IMAGE_ROLLERSKATE", 56);
        PyModule_AddIntConstant(pymod, "IMAGE_DUCK", 57);
        PyModule_AddIntConstant(pymod, "IMAGE_HOUSE", 58);
        PyModule_AddIntConstant(pymod, "IMAGE_TORTOISE", 59);
        PyModule_AddIntConstant(pymod, "IMAGE_BUTTERFLY", 60);
        PyModule_AddIntConstant(pymod, "IMAGE_STICKFIGURE", 61);
        PyModule_AddIntConstant(pymod, "IMAGE_GHOST", 62);
        PyModule_AddIntConstant(pymod, "IMAGE_SWORD", 63);
        PyModule_AddIntConstant(pymod, "IMAGE_GIRAFFE", 64);
        PyModule_AddIntConstant(pymod, "IMAGE_SKULL", 65);
        PyModule_AddIntConstant(pymod, "IMAGE_UMBRELLA", 66);
        PyModule_AddIntConstant(pymod, "IMAGE_SNAKE", 67);

        

        return pymod;
    }
}