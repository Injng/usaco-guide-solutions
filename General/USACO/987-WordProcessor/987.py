import sys

sys.stdin = open("word.in", "r")
file = open("word.out", "a")

inputnums = [int(x) for x in input().split(" ")]
wordlist = [word for word in input().split(" ")]
length = 0

for i in range(inputnums[0]):
    word = wordlist[i]
    length += len(word)
    if length <= inputnums[1]:
        if i != 0: 
            file.write(" ")
        file.write(word)
    else:
        file.write("\n" + word)
        length = len(word)
