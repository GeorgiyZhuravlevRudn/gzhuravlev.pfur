first = int(input('please, input 1st number: '))
second = int(input('please, input 2nd number: '))
third = int(input('please, input 3rd number: '))

def max_of_3(first,second,third):
    if(first>=second and first>=third):
        return first
    if (second>=first and second>=third):
        return second
    return third
print(max_of_3(first, second, third))
