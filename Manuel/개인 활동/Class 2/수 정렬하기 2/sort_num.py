import sys

n = int(sys.stdin.readline())
numbers = []

for _ in range(n):
    numbers.append(int(sys.stdin.readline()))

for i in range(n):
    min_index = i
    for j in range(i + 1, n):
        if numbers[j] < numbers[min_index]:
            min_index = j
    numbers[i], numbers[min_index] = numbers[min_index], numbers[i]

for num in numbers:
    print(num)
