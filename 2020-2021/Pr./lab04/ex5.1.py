import math


def circle():
    r = float(input('R: '))
    s = math.pi * r**2
    return s


def rectangle():
    a = float(input('a = '))
    b = float(input('b = '))
    s = a*b
    return s


def square():
    a = float(input('a = '))
    s = a * a
    return s


def rhombus():
    what = input('sin or h?: ')
    if what == 'sin':
        a = float(input('a = '))
        alpha = float(input('angle = '))
        sina = math.sin(alpha)
        s = a * a * sina
        return s
    elif what == 'h':
        a = float(input('a = '))
        h = float(input('h = '))
        s = a * h
        return s


def trapeze():
    a = float(input('a = '))
    b = float(input('b = '))
    h = float(input('h = '))
    s = ((a + b) / 2) * h
    return s


def parallelogram():
    what = input('sin or h?: ')
    if what == 'sin':
        a = float(input('a = '))
        b = float(input('b = '))
        alpha = float(input('angle = '))
        sina = math.sin(alpha)
        s = a * b * sina
        return s
    elif what == 'h':
        a = float(input('a = '))
        h = float(input('h = '))
        s = a * h
        return s


def triangle():
    a = float(input('ab = '))
    b = float(input('bc = '))
    c = float(input('ac = '))
    p = (a + b + c) / 2
    return math.sqrt(p * (p - a) * (p - b) * (p - c))


choice = input("Circle(C), Rectangle(RT), Triangle(TG), Rhombus(RB), Square(S), Trapeze(TP),Parallelogram(PG) : ")
if choice == 'C':
    print("S circle: ", circle())

elif choice == 'RT':
    print("S rectangle: ", rectangle())

elif choice == 'TG':
    print("S triangle: ", triangle())

elif choice == 'RB':
    print("S rhombus: ", rhombus())

elif choice == 'S':
    print("S square: ", square())

elif choice == 'TP':
    print("S trapeze: ", trapeze())

elif choice == 'PG':
    print("S parallelogram: ", parallelogram())
