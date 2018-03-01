from distutils.core import setup, Extension
MOD = "spam"
module = Extension(MOD, sources = ["spammodule.c"])
setup(name = MOD, ext_modules = [module])
