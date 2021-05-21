
import matplotlib.pyplot as plt
x = [1, 2, 3, 4, 5, 6, 7, 8, 9]
y = [12.5, 3.1, 55, 43.6, 54.9, 10, 15, 25, 50]
plt.plot(x, y, label='f(x)', linestyle='dotted', color='r', marker='D', linewidth='1.5')
plt.bar(x, y, label='Statistics', color='blue')
plt.xlabel('time')
plt.ylabel('speed')
plt.title('Statistics')

plt.legend(loc='upper right', labels=['line','graph'])
# fig.savefig('pie.png')
plt.show()


