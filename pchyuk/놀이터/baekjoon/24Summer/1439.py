n=str(input())
a=0
b=0
if "01" in n:
    a=n.count("01")
elif "10" in n:
    b=n.count("10")
print(a if a<b else b)