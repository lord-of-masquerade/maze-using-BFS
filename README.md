# 🧭 Maze Solver using Breadth-First Search (BFS)

A grid-based maze solver implemented in C++ using the Breadth-First Search (BFS) algorithm to compute the shortest path from a start point to a destination.

This project focuses on **algorithmic correctness, path optimality, and state-space exploration**.

---

## Problem

Finding the shortest path in a maze is a foundational problem in computer science, relevant to:
- robotics navigation
- game AI
- network routing
- graph theory

The challenge is to explore all possible paths efficiently while guaranteeing the shortest solution.

This project studies how **BFS guarantees optimal paths** in an unweighted grid.

---

## Approach

The maze is modeled as a **2D grid**, where:
- `0` represents a blocked cell
- `1` represents a valid path

Each cell is treated as a node in a graph.
Edges exist between adjacent cells (up, down, left, right).

Breadth-First Search is chosen because:
- it explores level by level
- the first time the destination is reached is the shortest path

---

## Logic Flow

1. Initialize a queue for BFS traversal
2. Push the starting cell into the queue
3. Mark visited cells to avoid cycles
4. For each cell:
   - explore all valid neighboring cells
   - update distance from the start
5. Stop traversal when the destination is reached
6. Output the shortest distance or path

This mirrors real-world state exploration problems.

---

## Key Concepts Demonstrated

- Breadth-First Search (BFS)
- Graph representation using grids
- Queue-based traversal
- Distance tracking
- Visited-state optimization
- Shortest-path guarantee in unweighted graphs

---

## Limitations

- Maze must be static
- All edges have equal cost
- Diagonal movement not supported
- Memory usage increases with maze size

These constraints are intentional to preserve BFS clarity.

---

## Future Improvements

- Visualize the path traversal step-by-step
- Add path reconstruction instead of just distance
- Support weighted cells (upgrade to Dijkstra)
- Compare BFS with DFS performance
- Add maze generation algorithms

---

## Evolution Story

- v0.1 — Basic maze representation
- v0.2 — BFS traversal added
- v0.3 — Distance tracking implemented
- v0.4 — Output formatting and validation

Each stage represents a deeper understanding of graph traversal.

---

## Why BFS?

Unlike DFS, BFS:
- avoids deep unnecessary exploration
- guarantees the shortest path
- models real-world expansion processes

This makes it ideal for maze-solving problems.
