n=int(input())
for i in range(0,n):
    pw=input()
    if len(pw) >= 6 and len(pw) <= 9:
        print("yes")
    else:
        print("no")