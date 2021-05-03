# Задание №3 в-1
n1 = int(input('first natural number: '))
n2 = int(input('second natural number: '))
n3 = int(input('third natural number: '))

for i in range(1, 4):
    if n1 == i:
        print('first natural number is in [1;3] = ', n1)
    if n2 == i:
        print('second natural number is in [1;3] = ', n2)
    if n3 == i:
        print('third natural number is in [1;3] = ', n3)
# здесь последняя цифра - не включена в интервал -> 1;4( [1;4) )
# , чтобы получился нужный интервал
