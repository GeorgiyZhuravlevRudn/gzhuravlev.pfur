#Задание №2
name = input('Your name is: ')
surname = input('Your surname is: ')
age = int(input('Your age is: '))
weight = int(input('Your weight(in kg) is: '))
if age < 30 and 50 < weight < 120:
    print("you're in a good shape")
elif (30 < age < 40) and (weight < 50 or weight > 120):
    print("you're in a bad shape")
elif age > 40 and (weight < 50 or weight > 120):
    print("You need to go to a doctor")
