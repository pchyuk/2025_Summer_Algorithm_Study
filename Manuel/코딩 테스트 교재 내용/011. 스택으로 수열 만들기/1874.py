N = int(input())
A = [0] * N

for i in range(N):
    A[i] = int(input())

stack = []
num = 1
result = True
answer = ""

for i in range(N):
    number = A[i]
    if number >= num:
        while number >= num:
            stack.append(num)
            num += 1
            answer += "+\n"
        stack.pop()
        answer += "-\n"
    else:
        n = stack.pop()
        if n > number:
            print("NO")
            result = False
            break
        else:
            answer += "-\n"

if result:
    print(answer)