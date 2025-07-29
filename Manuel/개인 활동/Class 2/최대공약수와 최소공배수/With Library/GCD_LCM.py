import sys
import math

num1, num2 = map(int, sys.stdin.readline().split())

gcd_value = math.gcd(num1, num2)

lcm_value = math.lcm(num1, num2)

print(gcd_value)
print(lcm_value)