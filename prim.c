#include <Python.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#define MAX 1000000

double gettimeofday_sec()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + (double)tv.tv_usec*1e-6;
}

static PyObject *
prim(PyObject *self, PyObject *args)
{
  int n;
  if(!PyArg_ParseTuple(args, "i", &n))
    return NULL;
  
  double start,end;
  start = gettimeofday_sec();
  
  int i, j;
  int p[n];

  for(i=0 ; i<n ; i++) p[i] = 0;
  p[0] = 1;
  
  for(i=2 ; i<=n/2 ; i++){
    for(j=2 ; i*j<=n ; j++){
      if(p[i*j-1] == 0)
        p[i*j-1] = 1;
    }
  }
  
  end = gettimeofday_sec();
  return Py_BuildValue("d", end - start);
}

static PyMethodDef methods[] = {
	{"prim", prim, METH_VARARGS},
	{NULL, NULL}
};

PyDoc_STRVAR(api_doc, "Python3 API sample.\n");

static struct PyModuleDef cmodule = {
   PyModuleDef_HEAD_INIT,
   "c",   /* name of module */
   api_doc, /* module documentation, may be NULL */
   -1,       /* size of per-interpreter state of the module,
                or -1 if the module keeps state in global variables. */
   methods
};

PyInit_c(void)
{
	return PyModule_Create(&cmodule);
}