# Задание №1
n = int(input('write a number that greater than 0 and less than 10 : '))
if n <= 0 or n >= 10:
    while n <= 0 or n >= 10:
        print("you're wrong")
        n = int(input('write a number that greater than 0 and less than 10 :'))
print('your number is correct , ' + 'here is sqrt of it = ', pow(n, 2))
