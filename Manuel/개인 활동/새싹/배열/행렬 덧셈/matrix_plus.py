n, m = map(int, input().split())

matrix_a = []

for _ in range(n):
    row = list(map(int, input().split()))
    matrix_a.append(row)

matrix_b = []

for _ in range(n):
    row = list(map(int, input().split()))
    matrix_b.append(row)

result_matrix = [[0] * m for _ in range(n)]

for i in range(n):
    for j in range(m):
        result_matrix[i][j] = matrix_a[i][j] + matrix_b[i][j]

for i in range(n):
    print(" ".join(map(str, result_matrix[i])))