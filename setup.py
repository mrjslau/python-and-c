from distutils.core import setup, Extension
MOD = "mods"
module1 = Extension("spam", sources = ["spammodule.c"])
module2 = Extension("noddy", sources = ["noddymodule.c"])

setup(name = MOD, ext_modules = [module1, module2])
