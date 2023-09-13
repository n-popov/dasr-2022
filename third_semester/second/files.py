first_filename, second_filename = 'data.csv', 'data.txt'

x1, x2 = tuple([[int(item) for item in
                 line.rstrip().split(',')] for line in
                    open(first_filename, 'r').readlines()])

# bad code, not closing file

with open(second_filename, 'r') as second_fd:
    lines = second_fd.readlines()
    lines = [[int(i) for i in line.strip().split()] for
             line in lines]
    y1, y2 = tuple([list(line) for line in zip(*lines)])

print(f'x1 = {x1}', f'x2 = {x2}',
      f'y1 = {y1}', f'y2 = {y2}', sep='\n')

inner_product = sum([(xi_1 - yi_1) * (xi_2 - yi_2) for
                     xi_1, yi_1, xi_2, yi_2 in
                     zip(x1, y1, x2, y2)])

print(f'Result is {inner_product}')
