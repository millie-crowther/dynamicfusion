# CMake
sudo apt-get install cmake

#
# prerequisites for ceres
#

# google-glog + gflags
sudo apt-get install libgoogle-glog-dev
# BLAS & LAPACK
sudo apt-get install libatlas-base-dev
# Eigen3
sudo apt-get install libeigen3-dev
# SuiteSparse and CXSparse (optional)
# - If you want to build Ceres as a *static* library (the default)
#   you can use the SuiteSparse package in the main Ubuntu package
#   repository:
sudo apt-get install libsuitesparse-dev
sudo apt-get update
sudo apt-get install libsuitesparse-dev

# 
# ceres solver
#
if cd build/ceres-solver; then
    git pull
    cd ..
else
    cd build 
    git clone https://github.com/ceres-solver/ceres-solver.git
    cd ceres-solver
    cd build
    cmake ..
    make -j3
    sudo make install
    cd ../..
fi
cd ..

