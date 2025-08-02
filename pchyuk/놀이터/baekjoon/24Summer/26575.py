n=int(input())
for i in range(0,n):
    a,b,c=map(float, input().split())
    print("$","%.2f" %(a*b*c), sep='')