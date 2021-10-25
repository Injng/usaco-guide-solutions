import sys

sys.stdin = open("square.in", "r")
sys.stdout= open("square.out", "w")

first = [int(x) for x in input().split(" ")]
second = [int(x) for x in input().split(" ")]
xvalues = [first[0], first[2], second[0], second[2]]
yvalues = [first[1], first[3], second[1], second[3]]

maxx = max(xvalues)
minx = min(xvalues)
maxy = max(yvalues)
miny = min(yvalues)
square = max(maxx - minx, maxy - miny)

print(square ** 2)
