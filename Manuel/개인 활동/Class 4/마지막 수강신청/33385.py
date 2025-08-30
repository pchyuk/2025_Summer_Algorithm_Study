def solve():
    n, m = map(int, input().split())

    credits = []
    schedules = []

    for i in range(n):
        data = input().split()
        credit = int(data[0])
        lecture_count = int(data[1])

        time_list = []
        for j in range(lecture_count):
            day = data[2 + j * 2]
            time = int(data[3 + j * 2])
            time_list.append((day, time))
        
        credits.append(credit)
        schedules.append(time_list)
    
    for mask in range(1, 1 << n):
        selected_subjects = []
        total_credits = 0

        for i in range(n):
            if mask & (1 << i):
                selected_subjects.append(i)
                total_credits += credits[i]
        if total_credits < m:
            continue

        used_times = set()
        conflict = False

        for subject_idx in selected_subjects:
            for day, time in schedules[subject_idx]:
                if (day, time) in used_times:
                    conflict = True
                    break
                used_times.add((day, time))
            if conflict:
                break
        if not conflict:
            return "YES"
    return "NO"

print(solve())