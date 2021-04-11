# CPP-TPCC
TPCC benchmark test tool

## Build dynamical lib
1. Clone cpp-tpcc repository
   ```shell
   $ git clone <cpp-tpcc https/ssh repo url>
   ```
2. Build
   ```shell
   $ mkdir build
   $ cmake -DBUILD_DUCKDB_DRIVER=OFF ..
   $ make
   ```
## Build duckdb driver
1. Clone cpp-tpcc repository
   ```shell
   $ git clone <cpp-tpcc https/ssh repo url>
   ```
2. Build
   ```shell
   $ mkdir build
   $ cmake -DBUILD_DUCKDB_DRIVER=ON ..
   $ make
   ```

## Mock TPC-C data for duckdb
Loading data is not currently implemented here. I've implemented a [python driver](https://github.com/XuPeng-SH/py-tpcc/blob/master/README_DUCKDB.md) that can help to load TPCC data for duckdb.

## Execute TPC-C for duckdb

1. Follow above steps to build duckdb driver
2. Follow above steps to mock TPCC data
3. Execute
   ```shell
   $ cd build/duckdb
   $ ./duckdb-tpcc -num=1000 -path=/tmp/duckdb.tpcc -sf=1 -workers=8
   ```

## TODOS
1. data mock
2. report
3. more dirver
4. verifier
