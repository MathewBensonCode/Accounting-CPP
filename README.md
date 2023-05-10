# Accounting Library in Cpp

[![CMake](https://github.com/MathewBensonCode/Accounting-CPP/actions/workflows/cmake.yml/badge.svg)](https://github.com/MathewBensonCode/Accounting-CPP/actions/workflows/cmake.yml)

This application is intended to record transactions from various types of Source Documents such as rreceipts.

The documents are to be scanned and the information extracted from them using Optical Character Recognition. The extracted data is then to be categorized based on the various types of transactions and data from the Harmonized System. 

## Configuration

To build the project, Create a folder outside of the source tree.

```
cd ..
mkdir accountappbuild
cmake -S <current-source-name> -B accountappbuild
cmake --build accountappbuild
```
