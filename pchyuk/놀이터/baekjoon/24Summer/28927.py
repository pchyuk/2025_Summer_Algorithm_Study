t1,e1,f1=map(int, input().split())
t2,e2,f2=map(int, input().split())
r1=t1*3+e1*20+f1*2*60
r2=t2*3+e2*20+f2*2*60
if r1>r2: print("Max")
elif r1<r2: print("Mel")
else: print("Draw")
