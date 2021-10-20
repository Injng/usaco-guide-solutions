import sys

sys.stdin = open("buckets.in", "r")
sys.stdout = open("buckets.out", "w")

inputs = []
for i in range(10):
    inputs.append([char for char in input()])

indices = []
a = 0
b = 0
for x in inputs:
    a += 1
    for y in x:
        b += 1
        if y == "B":
            indices.append(a)
            indices.append(b)
        elif y == "L":
            indices.append(a)
            indices.append(b)
        else:
            pass
    b = 0

total = abs(indices[0] - indices[2]) + abs(indices[1] - indices[3]) - 1
print(total)

