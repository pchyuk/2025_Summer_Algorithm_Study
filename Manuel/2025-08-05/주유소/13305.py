# 설명은 cpp 파일 참조

import sys

def solve():
    input = sys.stdin.readline

    N = int(input())
    road_len = list(map(int, input().split()))
    prices = list(map(int, input().split()))

    total_cost = 0
    current_min_price = prices[0]

    for i in range(N - 1):
        current_min_price = min(current_min_price, prices[i])
        total_cost += current_min_price * road_len[i]
    
    print(total_cost)

solve()