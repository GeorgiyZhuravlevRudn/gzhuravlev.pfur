num=int(input('n= '))
sum_r= 0
for i in range (1, num):
    sum_r+=1.0/(i*(i+1))
    i+=1
print('Sum= ', sum_r)
