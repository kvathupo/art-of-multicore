## What?

Solutions to exercises in __The Art of Multiprocessor Programming__ (available for purchase 
[here](https://www.amazon.com/Art-Multiprocessor-Programming-Revised-Reprint/dp/0123973376)).

Using the following technology:

* C++ (gcc 10)
* Java (JDK 14)

## How do I start?

See a hint of how many threads can be run with `machine_check.cpp`. My machine can 
run `4` threads. How about yours?

## Compilation
### C++
1. Compile without thread sanitizers
```bash
g++ -std=c++17 -I ./include/ ./lib/*.cpp ./main/main.cpp -lpthread
```
### Java
1. Compile the includes into a jar
```bash
jar cf includes.jar include/*.java
```
2. Compile with correct classpath
```bash
javac -cp ".:includes.jar;" Main.java
```
