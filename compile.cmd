del *.pyd
del SparseMatPy.cp310-win_amd64.pyd
rem rd /s /q build
mkdir build
cmake -S . -B build -G "Visual Studio 17 2022" -DPYBIND_EXPORT=ON -Dpybind11_DIR="C:/Program Files/Python310/Lib/site-packages/pybind11/share/cmake/pybind11"
cmake --build build --config release 
copy Release\SparseMatPy.cp310-win_amd64.pyd .
python cmagnet.py