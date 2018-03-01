#include <Python.h>

//max (46). overflow
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

static PyObject * spam_system(PyObject *self, PyObject *args){
  const char *command;
  int sts;
  if (!PyArg_ParseTuple(args, "s", &command))
    return NULL;
  sts = system(command);
  if(sts<0){
    //PyErr_SetString(spamError, "System command failed");
    return NULL;
  }
  return Py_BuildValue("i", sts);
}

static PyObject * spam_multiply(PyObject *self, PyObject *args){
  int x, y;
  int sts;
  if (!PyArg_ParseTuple(args, "ii", &x, &y))
    return NULL;
  sts = x * y;
  return Py_BuildValue("i", sts);
}

static PyObject * spam_fibonacci(PyObject *self, PyObject *args){
  int x;
  int sts;
  if (!PyArg_ParseTuple(args, "i", &x))
    return NULL;
  sts = get_fibonacci(x);
  return Py_BuildValue("i", sts);
}

static PyMethodDef spamMethods[] = {
  {"system", spam_system, METH_VARARGS, "Execute a shell command."},
  {"multiply", spam_multiply, METH_VARARGS, "Multi"},
  {"fibonacci", spam_fibonacci, METH_VARARGS, "Fibo"},
  {NULL, NULL, 0, NULL} /* Sentinel */
};

static struct PyModuleDef spammodule = {
  PyModuleDef_HEAD_INIT,
  "spam", // name of module
  NULL, // module documentation
  -1, // size of per-interpreter state
  spamMethods
};

PyMODINIT_FUNC PyInit_spam (void){
  return PyModule_Create (&spammodule);
}

static PyObject *spamError;

PyMODINIT_FUNC PyInit_spam(void){
  PyObject *m = PyModule_Create(&spammodule);
  
  spamError = PyErr_NewException("spam.error", NULL, NULL);
  Py_INCREF(spamError);
  PyModule_AddObject(m, "error", spamError);
}
