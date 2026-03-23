# 0 = unvisited, 1 = visited
def DFS(graph, s):
    if s not in visited:
        visited.append(s)
        for i in graph[s]:
            if i not in visited:
                DFS(graph, i)
        
            


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
    DFS(graph, 0)
    print(visited)
    
