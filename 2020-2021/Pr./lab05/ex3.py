import matplotlib.pyplot as plt
import numpy as np
x = np.linspace(-10, 10, 41)
p1=1; n1=1; p2=2; n2=1; p3=1; n3=2
y = (x**n1+p1**n1)/x**n1
z = (x**n2+p2**n2)/x**n2
v = (x**n3+p3**n3)/x**n3
fig, ax = plt.subplots()
ax.plot(x, y, color='red', linestyle='--', label='p=1, n=1')
ax.plot(x, z, color='blue', linestyle='-', label='p=2, n=1')
ax.plot(x, v, color='green', linestyle='-.', label='p=1, n=2')
plt.legend(loc='upper right')
plt.xlabel('x')
plt.ylabel('f(x)')
plt.title(r'Graph f(x)=(x^n+p^n)/(x^n) ')
plt.show()
fig.savefig('graph.svg')
