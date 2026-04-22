import heapq

def dijkstra(graph, start: int):
    
    # dist = {node: float('inf') for node in graph}
    # dist[start] = 0
    # heap = [(0, start)]
    # while heap:
    #     d, u = heapq.heappop(heap)
    #     if d > dist[u]:
    #         continue

    #     for v, weight in graph[u]:
    #         if dist[v] > weight + dist[u]:
    #             dist[v] = weight + dist[u]
    #             heapq.heappush(heap, (dist[v], v))
    # return dist
    dist = {node: float('inf') for node in graph}
    dist[start] = 0
    heap = [(0, start)]
    while heap:
        d, u = heapq.heappop(heap)
        if d > dist[u]:
            continue
        for v, weight in graph[u]:
            if dist[u] + weight < dist[v]:
                dist[v] = dist[u] + weight
                heapq.heappush(heap, (dist[v], v))
    return dist

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

if __name__ == "__main__":
    # n = 节点数, edges = [[u, v, weight], ...]
    graph = {
    'A': [('B', 1), ('C', 4)],
    'B': [('C', 2), ('D', 5)],
    'C': [('D', 1)],
    'D': []
}

    print(dijkstra(graph,'A'))