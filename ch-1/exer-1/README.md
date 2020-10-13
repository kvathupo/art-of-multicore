# TODO
* [C++11 memory model](https://stackoverflow.com/questions/26787086/atomic-pointers-in-c-and-passing-objects-between-threads)
and how to use atomics with generic objects (mutex, atomic pointer, or make trivially constructible?).
# Exercise 1
### Terminology
* __Starvation:__ There exists a scenario where at least one thread is blocked,
and can never progress. 
* __Deadlock:__ There exists a scenario where at least two threads are blocked, 
and cannot progress until a condition is satisfied, but this condition
can't transpire. 

### `sol_1/`
Partially order the spoons. When needing to eat, each philosopher picks up 
the lowest order fork. 
- [ ] Starvation: Suppose there are 5 diners. If all but diner 4 (with the
highest and lowest ranked forks) are eating, there is a possibility diner
4 will starve. 
- [x] Deadlock: If two philosophers cannot eat, they merely wait until their
adjacent diners think.


## References
* [Lecture Notes](http://web.eecs.utk.edu/~mbeck/classes/cs560/560/notes/Dphil/lecture.html)
