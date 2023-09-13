word_entries = dict()
for word in input().split():
    word_entries[word] = word_entries.setdefault(word, 0) + 1
print(*[f'{num} {word}' for (word, num) in sorted(word_entries.items(), key=lambda x: (-x[1], x[0]))], sep='\n')