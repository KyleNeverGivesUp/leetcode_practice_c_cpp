from collections import deque
def dijkstra(graph, s, t):
    if s not in visited:
        queue = deque([s])
        visited.append(s)
        



if __name__ == "__main__":
    # n = 节点数, edges = [[u, v, weight], ...]
    n = 5
    edges = [[0,1,2],[0,2,4],[1,2,1],[1,3,7],[2,4,3],[3,4,1]]

    # graph = {i:[] for i in range(n)}
    # for u, v, w in edges:
    #     graph[u].append((v, w))
    # print(graph)

    visited = []

    graph = {i : [] for i in range(n)}
    for u, v, w in edges:
        graph[u].append((v, w))
    print(graph)

    