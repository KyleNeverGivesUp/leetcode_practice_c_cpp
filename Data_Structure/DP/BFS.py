from collections import deque 

"""
0 - 1 - 3
|   |
2   4
|   |
5---+
"""

def BFS(graph, s):
    queue = deque([s])
    visited.append(s)
    while queue:
        node = queue.popleft()
        for i in graph[node]:
            if i not in visited:
                visited.append(i)
                queue.append(i)

if __name__ == "__main__":
    graph = {
    0: [1, 2],
    1: [0, 3, 4],
    2: [0, 5],
    3: [1],
    4: [1, 5],
    5: [2, 4]
}
    visited = []
    BFS(graph, 0)
    print(visited)