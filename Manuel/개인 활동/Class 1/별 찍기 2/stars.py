n = int(input())

for i in range(1, n + 1):
    num_stars = i
    num_spaces = n - i
    print(" " * num_spaces + "*" * num_stars)
