while True:
    num_str = input()
    
    if num_str == "0":
        break
    
    reversed_num_str = num_str[::-1]
    
    if num_str == reversed_num_str:
        print("yes")
    else:
        print("no")
