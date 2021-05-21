import random
N = int(input('Size of N: '))
M = int(input('Size of M: '))
Matrix = [[random.randrange(10) for i in range(M)] for j in range(N)]
print('before: ')
for i in  Matrix:
    for j in i:
        print(j, end="  ")
    print()

for i, row in enumerate(Matrix):
    max = min = 0
    for j, elem in enumerate(row):
        if elem > row[max]:
            max = j
        if elem < row[min]:
            min = j
    temp = row[0]
    row[0] = row[max]
    row[max] = temp
    temp1 = row[-1]
    row[-1] = row[min]
    row[min] = temp1

print('after: ')
for i in  Matrix:
    for j in i:
        print(j, end="  ")
    print()
