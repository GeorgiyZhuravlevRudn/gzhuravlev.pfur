def  Information():
    name = str(input('Your name: '))
    age = int(input('Your age: '))
    city = str(input('You live in: '))
    res = name+' '+str(age) + ' '+city
    return res
print(Information())
