numbers = list(map(int, input().split()))

square_sum = 0
for num in numbers:
    square_sum += num ** 2

verification = square_sum % 10
print(verification)