## What?
An internal list of interesting topics for me to write about!

List:
* How do I use atomics for general classes, which need not be trivially copyable?
    * Use an atomic to a pointer to that object
* How to iterate through a container of unique pointers?
    * [Answer](https://stackoverflow.com/questions/20292682/iterating-through-vectorunique-ptrmytype-using-c11-for-loops)
* Why do I have to use `std::ref` for reference thread arguments?
    * [Answer](https://stackoverflow.com/questions/36341724/c-thread-taking-reference-argument-failed-compile)
* Why not sanitize for threads with locks?
    * [Answer](https://stackoverflow.com/questions/11172922/does-stdmutex-create-a-fence)
    * Memory Fence [definition](https://en.wikipedia.org/wiki/Memory_barrier)
