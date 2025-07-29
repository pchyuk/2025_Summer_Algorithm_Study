import sys

n = int(sys.stdin.readline())
words = set()

for _ in range(n):
    word = sys.stdin.readline().strip()
    words.add(word)

word_list = list(words)

word_list.sort(key = lambda x: (len(x), x))

for word in word_list:
    print(word)
