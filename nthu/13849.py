students = []
while True:
    try:
        students.append(input())
    except EOFError as e:
        break

for student in students:
    items = student.split(",")
    first_fraction = items[1].split("/")
    second_fraction = items[2].split("/")
    final_score = (
        40 * (float(first_fraction[0]) / float(first_fraction[1]))
        + 60 * (float(second_fraction[0]) / float(second_fraction[1]))
        + float(items[3])
    )
    print(f'Student_Name:{items[0]},Final_Score:{final_score:.2f}')

