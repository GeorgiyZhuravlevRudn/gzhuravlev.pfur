
arr_1 = []
num_of_elements_arr_1 = int(input('Input a number of elements for  array: '))
for i in range(num_of_elements_arr_1):
    k = int(input(f"element  { i } of an array =  "))
    arr_1.append(k)
print("the largest number in array is ", max(arr_1))
print("normal array", arr_1)
print("reversed array", list(reversed(arr_1)))

