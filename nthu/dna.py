dna = input()
res = []

import sys
if not dna:
    print()
    sys.exit()
i = 1
vowel = True if dna[0] == 'A' else False
cur_str = dna[0]
while i < len(dna):
    if vowel and dna[i] != 'A' or not vowel and dna[i] == 'A':
        cur_str = cur_str + dna[i]
        vowel = not vowel
    else:
        res.append(cur_str)
        cur_str = dna[i]
    i += 1

res.append(cur_str)
print(" ".join(res))
