from setuptools import setup, Extension

if __name__ == '__main__':
    c = Extension('c', sources = ['prim.c'])
    setup(name = "api_sample", version = "0.0.0",
    	description = "Python3 API Sample",
    	packages = ['api_sample'], ext_modules = [c])