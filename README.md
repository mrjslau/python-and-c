# Python and C

\#1 task for Python course with C embedding, C objects and extending

## Prerequisites

## Running

Build C modules:
```
$ python3 setup.py build
$ python3 setup.py install
```
### Call C functions from Python
```
$ python3
>>>import spam
>>>spam.system("ls -l")
>>>spam.multiply(14, 10)
>>>spam.fibonacci(15)
<!--- to get a custom error: --->
>>>spam.fibonacci(-1)
```
### Create new object of new data type
```
$ python3
>>>import noddy
>>>myobj = noddy.Noddy()
```
### Calling Python functions from C code
```

```