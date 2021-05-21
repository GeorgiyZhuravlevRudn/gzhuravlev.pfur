import random
higher = 0
s = 0
N = int(input('Size of a matrix: '))
Matrix = [[random.randrange(10) for i in range(N)] for j in range(N)]
for i in range(N):
    for j in range(i+1, N):
        if Matrix[i][j] <= 0:
           continue
        if Matrix[i][j] > 0:
            higher += 1
            s += Matrix[i][j]

for i in  Matrix:
    for j in i:
        print(j, end="  ")
    print()
print('Sum:', s)
print('num_of_el:', higher)
