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
    #         if dist[u] + weight < dist[v]:
    #             dist[v] = dist[u] + weight
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
            if dist[v] > weight + dist[u]:
                dist[v] = weight + dist[u]
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

    # heap = [(1, 'A')]
    # heapq.heappush(heap, (1, 'A'))
    # print(dijkstra(graph, 'A'))
    from collections import Counter
    # print(Counter({'a':2, 'b':1, 'a':3}))
    a = [1, 2, 3]
    it = iter(a)
    
    # print(prev(it))
    b = (i*2 for i in range(1000000))  # 几乎不占内存
    next(b)
    # print(next(b))
    
    from collections import defaultdict
    d = defaultdict(dict)
    d["key"] = 2
    # print(d["key"])
    # print(d)
    # dummy = ListNode()
    # curr = dummy
    # print(f'dummy: {id(dummy)}')
    # print(f'curr: {id(curr)}')
    # import copy
    # curr2 = copy.copy(dummy)
    # print(f'curr2: {id(curr2)}')
    # curr3 = copy.deepcopy(dummy)
    # print(f'curr3: {id(curr3)}')
    # lst = [1, 2, 3, 4]
    lst = []
    # lst.remove(2)   # 删第一个值=2，lst=[1,3,2]，返回None
    # lst.pop(1)      # 删index=1，lst=[1,3,2]→[1,2]，返回3
    # lst.append(1)       # 删最后一个，返回该元素
    # lst.append(2)
    # lst.append(3)
    # lst.remove(2)
    lst.append(1)
    print(lst.pop())