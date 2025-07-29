import sys

n = int(sys.stdin.readline())
size = list(map(int, sys.stdin.readline().split()))
T, P = map(int, sys.stdin.readline().split())

total_bundles = 0

for count in size:
    if count == 0:
        continue
    bundles_for_this_size = (count + T - 1) // T
    total_bundles += bundles_for_this_size

print(total_bundles)

pen_bundles = n // P
remaining_pens = n % P

print(pen_bundles, remaining_pens)