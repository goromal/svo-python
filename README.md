# python-svo

Python wrapper for the (modified) standalone C++ SVO implementation by ETH Zurich, found [here](https://github.com/goromal/svo). Designed to work with a monocular camera setup.

## Installation

Clone the repository and build the underlying svo library with accompanying Python bindings:

```bash
git clone --recurse-submodules https://github.com/goromal/svo-python.git
cd svo-python/pylib
cmake ..
make
```

## Usage

To import the python bindings, include the following lines in your python script (substituting the correct path to the pylib folder):

```python
#!/usr/bin/python3
import sys
sys.path.insert(1, '/path/to/pylib')
from svo_mono import MonocularSVO
```
