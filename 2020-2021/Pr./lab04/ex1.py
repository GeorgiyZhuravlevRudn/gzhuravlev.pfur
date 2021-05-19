name = str(input('Your name: '))
age = str(input('Your age: '))
city = str(input('You live in: '))
def  Information(name, age, city):
    res = name+' '+age + ' '+city
    return res
print(Information(name, age, city))
