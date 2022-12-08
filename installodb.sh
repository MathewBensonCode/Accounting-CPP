#! /bin/sh

mkdir build2-build
cd build2-build
curl -sSfO https://download.build2.org/0.15.0/build2-install-0.15.0.sh
shasum -a 256 -b build2-install-0.15.0.sh
sh build2-install-0.15.0.sh

cd ..

apt-get install gcc-11-plugin-dev

mkdir odb-build
cd odb-build

bpkg create -d odb-gcc-11 cc     \
  config.cxx=g++                  \
  config.cc.coptions=-O3          \
  config.bin.rpath=/usr/local/lib \
  config.install.root=/usr/local  \
  config.install.sudo=sudo

cd odb-gcc-11
bpkg build odb@https://pkg.cppget.org/1/beta
bpkg install odb

cd ..

bpkg create -d libodb-gcc-11 cc  \
  config.cxx=g++                  \
  config.cc.coptions=-O3          \
  config.install.root=/usr/local  \
  config.install.sudo=sudo

cd libodb-gcc-11
bpkg add https://pkg.cppget.org/1/beta
bpkg fetch
bpkg build libodb
bpkg build libodb-sqlite
bpkg install --all --recursive

