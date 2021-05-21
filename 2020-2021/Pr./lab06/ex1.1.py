import matplotlib.pyplot as plt

labels = ['None', 'Towards Data Science', 'The Reality Project',
          'Noteworthy - The Journal Blog', 'Engineering @ Feature Labs']
sizes = [40, 40, 5.5, 10.5, 4]
# fig = plt.figure(figsize=(19, 10))
plt.title('Percentage of Words by Publication')

plt.pie(sizes, autopct='%.3f', shadow=True,startangle=-90,radius = 1)
plt.legend(loc='upper right', labels = labels)
# fig.savefig('pie.png')
plt.show()
