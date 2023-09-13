# def is_hexacedimal(value):
#     try:
#         _ = int(value, 16)
#     except ValueError:
#         return False
#     return True
#
# print(sum([int(item, 16) for item in
#            input().split() if is_hexacedimal(item)]))

def is_integer(value):
    try:
        int(value)
    except:
        return False
    return True

print(sum([int(item, 10) for item in
           input().split() if is_integer(item)]))