from distutils.core import setup, Extension
MODN = "noddy"
MODS = "spam"

moduleNoddy = Extension(MODN, sources = ["noddymodule.c"])
setup(name = MODN, ext_modules = [moduleNoddy])

moduleSpam = Extension(MODS, sources = ["spammodule.c"])
setup(name = MODS, ext_modules = [moduleSpam])