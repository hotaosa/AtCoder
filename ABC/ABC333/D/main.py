from collections import deque

def count_subtree_size(graph, s, parent):
    n = len(graph)
    used = {s}
    stack = deque()
    stack.append(s)
    while stack:
        u = stack.pop()
        for v in graph[u]:
            if v is not parent and not v in used:
                used.add(v)
                stack.append(v)
    return len(used)

def main():
    n = int(input())
    graph = [[] for _ in range(n)]
    for i in range(n - 1):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        graph[u].append(v)
        graph[v].append(u)

    subtree_sizes = [0]
    for s in graph[0]:
        subtree_sizes.append(count_subtree_size(graph, s, 0))
    subtree_sizes = sorted(subtree_sizes)
    print(sum(subtree_sizes[:-1], 1))

if __name__ == '__main__':
    main()
