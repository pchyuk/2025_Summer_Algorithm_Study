word = input()
result = ""

for char in word:
    if char.islower():
        result += char.upper()
    elif char.isupper():
        result += char.lower()
    else:
        result += char

print(result)