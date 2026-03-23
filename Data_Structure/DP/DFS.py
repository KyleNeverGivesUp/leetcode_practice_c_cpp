# 0 = unvisited, 1 = visited
def DFS_RECURSION(graph, s):
    if s not in visited:
        visited.append(s)
        for i in graph[s]:
            if i not in visited:
                DFS(graph, i)
        
            
def DFS_STACK(graph, s):
    stack = [s]
    while stack:
        node = stack.pop()
        if node not in visited:
            visited.append(node)
            for i in reversed(graph[node]):
                if i not in visited:
                    stack.append(i)


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
    # DFS_RECURSION(graph, 0)
    DFS_STACK(graph, 0)
    print(visited)
    
