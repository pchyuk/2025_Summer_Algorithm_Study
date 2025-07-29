students = set(range(1, 31))
submitted = set()

for _ in range(28):
    student_id = int(input())
    submitted.add(student_id)

not_submitted = students - submitted

not_submitted_list = sorted(list(not_submitted))

for i in range(2):
    print(not_submitted_list[i])
