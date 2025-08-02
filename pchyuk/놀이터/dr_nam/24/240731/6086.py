n=int(input())
i=1
s=0
while True:
    s+=i
    i+=1
    if s>=n:
        break
print(s)