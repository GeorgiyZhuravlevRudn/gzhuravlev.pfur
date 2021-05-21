import math
sum_r = 0
i = 1
e = math.e
E = float(input('\nAccuracy: '))
formula = math.sqrt(i+1)/(i*e)
while (formula >=E):
    e *= math.e
    sum_r += formula
    i += 1
    formula = math.sqrt(i+1)/(i*e)
print('Сумма ряда: ', sum_r)