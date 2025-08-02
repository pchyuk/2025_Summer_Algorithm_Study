n=int(input())
sum=0
tri=0
for i in range(1,n+1):
    sum+=i
    tri+=i*i*i
print(sum)
print(sum*sum)
print(tri)