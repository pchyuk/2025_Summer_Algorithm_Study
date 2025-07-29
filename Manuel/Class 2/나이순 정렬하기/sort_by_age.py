import sys

N = int(sys.stdin.readline())
members = []

for _ in range(N):
    age, name = sys.stdin.readline().split()
    members.append([int(age), name])

members.sort(key = lambda x : x[0])

for member in members:
    print(member[0], member[1])