num_entries = dict()
for number in [int(elem) for elem in input().split()]:
    num_entries[number] = num_entries.setdefault(number, 0) + 1
print(max([number for number in num_entries if num_entries[number] == 1]))