import sys

def has_negative_cycle(n, edges):
    dist = [0] * (n + 1)

    for i in range(n - 1):
        for edge in edges:
            from_node, to_node, cost = edge
            if dist[from_node] + cost < dist[to_node]:
                dist[to_node] = dist[from_node] + cost
    
    for edge in edges:
        from_node, to_node, cost = edge
        if dist[from_node] + cost < dist[to_node]:
            return True
        
    return False

def main():
    input = sys.stdin.readline

    tc = int(input())

    for _ in range(tc):
        n, m, w = map(int, input().split())
        edges = []

        for _ in range(m):
            s, e, t = map(int, input().split())
            edges.append((s, e, t))
            edges.append((e, s, t))
        for _ in range(w):
            s, e, t = map(int, input().split())
            edges.append((s, e, -t))
        
        if has_negative_cycle(n, edges):
            print("YES")
        else:
            print("NO")

main()