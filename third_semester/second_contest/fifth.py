word_entries = dict()
for word in input().split():
    word_entries[word] = word_entries.setdefault(word, 0) + 1

pairs =\
    [(entries, word) for (word, entries) in word_entries.items()]

sorted_words = sorted(pairs, key=lambda x: (-x[0], x[1]))

print(*[f'{num} {word}'
        for (num, word) in sorted_words], sep='\n')