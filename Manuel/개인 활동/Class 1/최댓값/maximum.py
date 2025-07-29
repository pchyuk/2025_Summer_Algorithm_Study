numbers = []

for _ in range(9):
    num = int(input())
    numbers.append(num)

max_value = max(numbers)
max_index = numbers.index(max_value) + 1

print(max_value)
print(max_index)