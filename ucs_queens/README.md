# UCS Implementation of 8 Queens
## States
<blockquote>n (between 0 and 8) queens on the board, one in each of the n leftmost columns; also no queens attacking each other.</blockquote>

## Initial State
<blockquote>No queens on the board.</blockquote>

## Actions
<blockquote>Add queen in the leftmost empty column such that it does not attack any of the queens already on the board.</blockquote>

## Cost
<blockquote>For every queen added to the board, cost of 1 step is incurred.</blockquote>

## Goal Test
<blockquote>8 queens on board in non-attacking positions.</blockquote>

## Two variations of the code
1. ucs_queens.cpp: Stops at the first solution found. 
2. ucs_queens_all_sol.cpp: Searches for all solutions.

## Output files
1. ucs_queens_sol.txt: Output of ucs_queens.cpp
2. queens_all_sol.txt: Output of ucs_queens_all_sol.cpp