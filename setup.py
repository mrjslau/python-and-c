from distutils.core import setup
from distutils.core import Extension
MOD = "spam"
module = Extension(MOD, sources = ["spammodule.c"])
setup(name = MOD, ext_modules = [module])
