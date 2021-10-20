import sys

sys.stdin = open("teleport.in", "r")
sys.stdout = open("teleport.out", "w")

inputs = [int(x) for x in input().split(" ")]

dist1 = abs(inputs[0] - inputs[2]) + abs(inputs[1] - inputs[3])
dist2 = abs(inputs[0] - inputs[1])
dist3 = abs(inputs[0] - inputs[3]) + abs(inputs[1] - inputs[2])
paths = [dist1, dist2, dist3]
print(min(paths))
