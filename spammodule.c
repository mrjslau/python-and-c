#include <Python.h> // Pulls Python API

static PyObject *spamError;

// **************** C functions ************************************
static int get_fibonacci(int x){
  int a = 1;
  int b = 1;
  for(int i = 2; i < x; i++){
    if(i % 2 == 0)
      b += a;
    else
      a += b;
  }
  return a > b ? a : b;
}
// ================ C functions ===================================

// **************** Python called methods *************************
// Terminal function
// ----------------------------- module --------- params ------- //
static PyObject * spam_system(PyObject *self, PyObject *args){
  const char *command;
  int sts;
// One of 3 conversion functions from Python to C. 
// Takes 1) params, 2) "s" - const char* type, 3) where is it saved
  if (!PyArg_ParseTuple(args, "s", &command))
    return NULL;
// Assigns result of function
  sts = system(command);
  if(sts < 0){
    //PyErr_SetString(spamError, "System command failed");
    return NULL;
  }
// Converts back to Python object ("i" integer type) and returns
  return Py_BuildValue("i", sts);
}

// Multiply function
static PyObject * spam_multiply(PyObject *self, PyObject *args){
  int x, y;
  int sts;
  if (!PyArg_ParseTuple(args, "ii", &x, &y))
    return NULL;
  sts = x * y;
  return Py_BuildValue("i", sts);
}

// Fibonacci function
static PyObject * spam_fibonacci(PyObject *self, PyObject *args){
  int x;
  int sts;
  if (!PyArg_ParseTuple(args, "i", &x))
    return NULL;
  if (x < 1){
    PyErr_SetString(spamError, "Fibonacci numbers are indexed from '1'");
    return NULL;
  }
  sts = get_fibonacci(x);
  return Py_BuildValue("i", sts);
}
// ================ Python called methods ==========================

// **************** Method list ************************************
static PyMethodDef spamMethods[] = {
// PythonName   - C function name - Args flag   -  Description
  {"system",      spam_system,      METH_VARARGS, "Execute a shell command."},
  {"multiply",    spam_multiply,    METH_VARARGS, "Multiply two integers"},
  {"fibonacci",   spam_fibonacci,   METH_VARARGS, "Get n-row fibonacci number (Max 46)"},
  {NULL,          NULL,             0,            NULL} /* Sentinel */
};
// ================ Method list ===================================

// **************** Module initialization *************************
// Structure
static struct PyModuleDef spammodule = {
  PyModuleDef_HEAD_INIT,
  "spam", // name of module
  NULL, // module documentation
  -1, // size of per-interpreter state
  spamMethods
};

// init 
// import spam - > initspam() calls PyInit_spam -> "module object is created"
PyMODINIT_FUNC PyInit_spam(void){
  PyObject *m = PyModule_Create(&spammodule);
  if(m == NULL) return NULL;

  spamError = PyErr_NewException("spam.error", NULL, NULL);
  Py_INCREF(spamError); 
  PyModule_AddObject(m, "error", spamError);
  return m;
}
// ================ Module initialization =========================