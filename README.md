# Description
This program shows a way to optimise multiplication of two large matrices in c++.

The unoptimised multiplication is done using nested loops.
Optimisation is achieved using pointers to matrices.

For this example 2 matrices A and B, both of dimensions 1000x1000 are used.

Matrices A and B are initialised with 1's for simplicity.

Matrices look like following before multiplication

A and B

pos|0|1|...|dim-1
:---:|:---:|:---:|:---:|:---:
0|1|1|...|1
1|1|1|...|1
.|.|.|.|.
.|.|.|.|.
.|.|.|.|.
dim-1|1|1|...|1

matrix C

pos|0|1|...|dim-1
:---:|:---:|:---:|:---:|:---:
0|0|0|...|0
1|0|0|...|0
.|.|.|.|.
.|.|.|.|.
.|.|.|.|.
dim-1|0|0|...|0

statement `std::chrono::high_resolution_clock::now();` is used to get high resolution time value of execution of this statement which could be used before and after multiplication to get the time spent on multiplication.

## How to run
Clone the repository to local and then compile using any c++ compiler of your preference.

Here is an example of using GNU *g++* compiler.

In the root run
```
g++ -o result matrixMultiplicationOptimization.cpp
```
once the code is compiled get the output by running
```
.\result
```

You should now be able to see the time taken for execution of both non optimised and optimised multiplication in console.