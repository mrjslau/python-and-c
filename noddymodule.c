#include <Python.h>

typedef struct{
  PyObject_HEAD
  /* Type-specific fields go here.*/
}noddy_NoddyObject;

static PyTypeObject noddy_NoddyType ={
  PyVarObject_HEAD_INIT(NULL, 0)
  "noddy.Noddy",              /*tp_name*/
  sizeof(noddy_NoddyObject),  /*tp_basicsize*/
  0,                          /*tp_itemsize*/
  0,                          /*tp_dealloc*/
  0,                          /*tp_print*/
  0,                          /*tp_getattr*/
  0,                          /*tp_setattr*/
  0,                          /*tp_reserved*/
  0,                          /*tp_repr*/
  0,                          /*tp_as_number*/
  0,                          /*tp_as_sequence*/
  0,                          /*tp_as_mapping*/
  0,                          /*tp_hash */
  0,                          /*tp_call*/
  0,                          /*tp_str*/
  0,                          /*tp_getattro*/
  0,                          /*tp_setattro*/
  0,                          /*tp_as_buffer*/ 
  Py_TPFLAGS_DEFAULT,         /*tp_flags*/
  "Noddy objects",            /* tp_doc */
};

static struct PyModuleDef noddymodule = {
  PyModuleDef_HEAD_INIT, 
  "noddy",                    // name of module
  "New type",                 // module documentation
  -1,                         // size of per- interpreter state
  NULL, NULL, NULL, NULL, NULL
};

PyMODINIT_FUNC PyInit_noddy(void) {
  PyObject* m;

  // Creation of new type object
  noddy_NoddyType.tp_new = PyType_GenericNew;             // GenericNew creates new object in memory
  if (PyType_Ready(&noddy_NoddyType)< 0) return NULL;     // Ready inits new type 
  // ---------------------------

  m = PyModule_Create(&noddymodule);
  if(m == NULL) return NULL;
  Py_INCREF(&noddy_NoddyType);
  PyModule_AddObject(m, "Noddy", (PyObject*)&noddy_NoddyType);
  return m;
}