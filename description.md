# Progress report

## Not parallel programming

The program that did not use parallelization:
```
Reading time: 0 ms
Clockwise rotation time: 0 ms
Writing clockwise rotation time: 4145 ms
Counterclockwise rotation time: 0 ms
Writing counterclockwise rotation time: 1785 ms
Gauss filter time: 0 ms
Writing Gauss filter time: 2573 ms
Total execution time: 8504 ms
```
The program that use parallelization:
```
Reading time: 0 ms
Clockwise rotation time: 0 ms
Writing clockwise rotation time: 2727 ms
Counterclockwise rotation time: 0 ms
Writing counterclockwise rotation time: 1864 ms
Gauss filter time: 0 ms
Writing Gauss filter time: 2125 ms
Total execution time: 6716 ms
```
## Advantages of Dynamic Programming
1. Performance Optimization

    Elimination of Duplicate Calculations: By memorizing solutions to previously solved subproblems (memoization), dynamic programming avoids recalculating identical computations multiple times.
    Improved Efficiency: Storing intermediate results leads to substantial performance gains, particularly for recursive algorithms with overlapping subproblems.

2. Enhanced Development and Understanding

    Modularity: Complex tasks are easily divided into small independent subtasks that can be tackled separately.
    Code Clarity: The structured nature of dynamic programming makes code easier to understand and maintain.

3. Broad Applicability

    Wide Range of Applications: Dynamic programming finds use in various domains such as route optimization, network analysis, graph theory, cryptography, bioinformatics, etc.
    Versatility: The same algorithm can often be adapted to solve different types of problems under varying conditions.

4. Scalability Improvement

    Efficient Handling of Large Datasets: Breaking large problems into manageable pieces allows for better scalability compared to traditional methods.
    Feasible Solutions for NP-Hard Problems: Many computationally expensive problems become practically solvable through dynamic programming techniques.
