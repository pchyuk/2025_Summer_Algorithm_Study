import sys

def main():
    input = sys.stdin.readline

    input_notes = list(map(int, input().split()))

    ascending_notes = [1, 2, 3, 4, 5, 6, 7, 8]
    descending_notes = [8, 7, 6, 5, 4, 3, 2, 1]

    is_ascending = True
    is_descending = True

    for i in range(8):
        if input_notes[i] != ascending_notes[i]:
            is_ascending = False
            break
    
    if not is_ascending:
        for i in range(8):
            if input_notes[i] != descending_notes[i]:
                is_descending = False
                break
    
    if is_ascending:
        print("ascending\n")
    elif is_descending:
        print("descending\n")
    else:
        print("mixed\n")

main()