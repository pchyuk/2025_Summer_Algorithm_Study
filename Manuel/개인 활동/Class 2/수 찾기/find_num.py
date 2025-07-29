import sys

def binary_search(arr, target):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high)
        if arr[mid] == target:
            return True
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return False

N = int(sys.stdin.readline())

A = list(map(int, sys.stdin.readline().split()))
A.sort()

M = int(sys.stdin.readline())
queries = list(map(int, sys.stdin.readline().split()))

for x in queries:
    if binary_search(A, x):
        print(1)
    else:
        print(0)
 