import sys

def calculate_gcd(a, b):
    if b == 0:
        return a
    return calculate_gcd(b, a % b)

num1, num2 = map(int, sys.stdin.readline().split())

gcd_value = calculate_gcd(num1, num2)
lcm_value = (num1 * num2) // gcd_value

print(gcd_value)
print(lcm_value)