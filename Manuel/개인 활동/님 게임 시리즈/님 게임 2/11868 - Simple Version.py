n = int(input())
stones = list(map(int, input().split()))

from functools import reduce
import operator

nim_sum = reduce(operator.xor, stones, 0)
print("koosaga" if nim_sum else "cubelover")