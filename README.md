Iterative Deepening A* Search
===========
Choice of algorithm
-------------------
The IDA* algorithm has a some advantages compared to A* or other algorithms.
We will oten compare it to A* since they are similar in some points, and A*
  is one of the most well-known and used search algorithms (especially in games programming).

This algorithm can be used in some other contexts dealing with such graphs.
The graph can be expanded : the algorithm will work whatever the size. 
It is mostly a case of required computing power. 

The similarity of this algorithm with A* is due to the use of a heuristic
  function to determine the most promising node to visit next.

The main difference is that (as explained below) IDA* doesn't store the visited nodes.
A* uses its list of visited nodes to perform a kind of breadth-first search,
  whereas IDA* does a depth-first search in a breadth-first cumulative node visit order
  (see [https://en.wikipedia.org/wiki/Iterative_deepening_depth-first_search](https://en.wikipedia.org/wiki/Iterative_deepening_depth-first_search)). 


### Space complexity ###
The IDA* algorithm has a much lower space complexity (linear) compared to A* (exponential).
  This low space complexity makes IDA* suited to search huge graphs.

The downside to the lower space complexity is that visited nodes are not remembered,
  which means that they will very often be visited over and over again.
  Actually, every time the search boundaries are expanded, the previously visited
  nodes will be visited again (unless a solution is found in the meantime).
  However, Professor Alan Mackworth explains in [this video](https://youtu.be/5LMXQ1NGHwU)
  that this added "search overhead" doesn't add that much computing complexity,
  which makes it arguably more efficient.

### Completeness and optimality ###
Just like A*, IDA* is complete and optimal (according to Professor Alan Mackworth).

However, the implementation in this project isn't optimal,
  because of the way the boundaries are expanded.
  
The heuristic used is very simple (it returns the weight of the lowest weighted
  edge connected to the node). It is not a simple task (if even feasible ?) to find
  a better heuristic in a graph without any obvious structure/patterns.
  If it had been a grid, a good enough heuristic function would have been easier to find.

Results
-------
The results of this implementation are not always the shortest paths,
  because of the way the borders are expanded.

Following are a few examples of search outputs.
```
Root node number:
> 17
Goal node number:
> 7
Cost of the shortest path: 743
17 -> 26 weight : 108
26 -> 27 weight : 45
27 -> 30 weight : 47
30 -> 29 weight : 76
29 -> 24 weight : 54
24 -> 20 weight : 47
20 -> 18 weight : 80
18 -> 15 weight : 33
15 -> 9 weight : 63
9 -> 13 weight : 54
13 -> 7 weight : 67
```

```
Root node number:
> 59
Goal node number:
> 0
Cost of the shortest path: 1092
59 -> 53 weight : 61
53 -> 46 weight : 76
46 -> 45 weight : 60
45 -> 35 weight : 61
35 -> 32 weight : 30
32 -> 25 weight : 120
25 -> 21 weight : 152
21 -> 18 weight : 75
18 -> 15 weight : 33
15 -> 9 weight : 63
9 -> 13 weight : 54
13 -> 6 weight : 45
6 -> 0 weight : 147
```

Compilation
-----------
## Dependencies ##
* Boost(Graph)

## Build ##
### GNU/Linux ###
```
mkdir build
cd build
cmake ..
cmake --build .
```
