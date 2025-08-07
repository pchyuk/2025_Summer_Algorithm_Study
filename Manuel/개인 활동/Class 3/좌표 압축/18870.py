import sys

def main():
    input = sys.stdin.readline

    N = int(input())

    original_coords = list(map(int, input().split()))
    sorted_coords = sorted(list(set(original_coords)))

    coords_to_index = {val: index for index, val in enumerate(sorted_coords)}

    result = [str(coords_to_index[coord]) for coord in original_coords]
    print(" ".join(result))

main()