# Heuristic Search Implementation of 8 Queens
## States
<blockquote>n (between 0 and 8) queens on the board, one in each of the n leftmost columns.</blockquote>

## Initial State
<blockquote>No queens on the board.</blockquote>

## Actions
<blockquote>Add queen in the leftmost empty column.</blockquote>

## Path Cost g(n)
<blockquote>For every queen added to the board, cost of 1 step is incurred plus a cost of number of conflicting pairs.</blockquote>

## Heuristic Cost h(n)
<blockquote>For every queen added to the board, heuristic cost is number of conflicting pairs.</blockquote>

## Expansion 
<blockquote>Based on minimum of f(n) = g(n)+h(n)</blockquote>

## Goal Test
<blockquote>8 queens on board in non-attacking positions.</blockquote>
