n=int(input())
b=list(map(int,input().split()))
sum=0
for i in range(0,n):
    sum+=b[i]
if sum>0: print("Right")
elif sum<0: print("Left")
else: print("Stay")