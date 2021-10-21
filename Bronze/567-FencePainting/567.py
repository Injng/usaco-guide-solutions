import sys

sys.stdin = open("paint.in", "r")
sys.stdout = open("paint.out", "w")

john = [int(x) for x in input().split(" ")]
bessie = [int(x) for x in input().split(" ")]

if bessie[0] < john[0]:
    if bessie[1] < john[0]:
        print(bessie[1] - bessie[0] + john[1] - john[0])
    elif bessie[1] >= john[1]:
        print(bessie[1] - bessie[0])
    elif bessie[1] >= john[0] and bessie[1] < john[1]:
        print(john[1] - bessie[0])
elif bessie[0] >= john[1]:
    print(bessie[1] - bessie[0] + john[1] - john[0])
elif bessie[0] >= john[0] and bessie[0] < john[1]:
    if bessie[1] < john[1]:
        print(john[1] - john[0])
    elif bessie[1] >= john[1]:
        print(bessie[1] - john[0])

