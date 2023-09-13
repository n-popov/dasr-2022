# filename = input()
# with open(filename, 'r') as fd:
#     words = fd.read().split() # whole file contents
#
# print(sorted(words, key=len)[-1])

print(sorted(open(input(), 'r').read().split(), key=len)[-1])
