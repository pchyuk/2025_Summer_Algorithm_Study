n = int(input())
numbers_str = input()
total_sum = 0

for char_digit in numbers_str:
    total_sum += int(char_digit)

print(total_sum)