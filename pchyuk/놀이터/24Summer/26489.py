count=0
while True:
    try:
        gum=input()
        count+=1
    except EOFError:
        break
    
print(count)