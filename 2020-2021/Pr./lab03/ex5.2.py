arr_1 = []
num_of_elements_arr_1 = int(input('Input a number of elements for  array: '))
for i in range(num_of_elements_arr_1):
    k = float(input(f"element  { i } of an array =  "))
    arr_1.append(k)
sr_ar = 0.0
print("before: ", arr_1)
for j in range(num_of_elements_arr_1):
    sr_ar += arr_1[j]
sr_ar /= num_of_elements_arr_1
for i in range (num_of_elements_arr_1):
    if(arr_1[i] == 0):
        arr_1[i] = sr_ar
    else:
        pass
print("sr_ar = ",  sr_ar)
print("after: ", arr_1)

