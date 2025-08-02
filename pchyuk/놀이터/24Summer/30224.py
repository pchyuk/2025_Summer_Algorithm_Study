n=int(input())
cnt=0
if n%7==0: cnt=cnt+1
while n>0:
    if n%10==7:
        cnt=cnt+2
        break
    n=n//10
print(cnt)