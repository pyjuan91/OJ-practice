from collections import defaultdict
from functools import cmp_to_key


def custom_compare(p1: tuple, p2: tuple):
    if p1[1] == p2[1]:
        if p1[0] < p2[0]:
            return -1
        else:
            return 1
    elif p1[1] > p2[1]:
        return -1
    else:
        return 1


genre_count = defaultdict(int)
genre_score = defaultdict(float)

while True:
    try:
        name, genres, score = input().split(",")
        for genre in genres.split("|"):
            genre_count[genre] += 1
            genre_score[genre] += float(score)
    except:
        break

li = []
for k, v in genre_score.items():
    li.append((k, v / genre_count[k]))

li.sort(key=cmp_to_key(custom_compare))

if len(li) < 10:
    for i in range(min(len(li), 3)):
        print(f"{li[i][0]},{li[i][1]:.2f}")
else:
    for i in range(min(len(li), 3)):
        print(f"{li[i][0]},{int(li[i][1]*100)/100:.2f}")
