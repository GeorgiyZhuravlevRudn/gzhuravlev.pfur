arr_1 = []
arr_2 = []
arr_3 = []
num_of_elements_arr_1 = int(input('Input a number of elements for  arr_1: '))
num_of_elements_arr_2 = int(input('Input a number of elements for  arr_2: '))
num_of_elements_arr_3 = int(input('Input a number of elements for  arr_3: '))

for i in range(num_of_elements_arr_1):
    k = int(input(f"element  { i } of an arr_1 =  "))
    arr_1.append(k)

for i in range(num_of_elements_arr_2):
    k = int(input(f"element  { i } of an arr_2 =  "))
    arr_2.append(k)

for i in range(num_of_elements_arr_3):
    k = int(input(f"element  { i } of an arr_3 =  "))
    arr_3.append(k)


def sum_of(arr_sum, num):
    sum_of_arr = 0
    for i in range(num):
        sum_of_arr += arr_sum[i]
    return sum_of_arr


def mid_ar(arr_n, num):
    sr_ar = 0.0
    for i in range(num):
        sr_ar += arr_n[i]
    sr_ar /= num
    return sr_ar


print("Sum_of_arr_1:", sum_of(arr_1, num_of_elements_arr_1))
print("Sr_Ar_of_arr_1:", mid_ar(arr_1, num_of_elements_arr_1))
print("Sum_of_arr_2:", sum_of(arr_2, num_of_elements_arr_2))
print("Sr_Ar_of_arr_2:", mid_ar(arr_2, num_of_elements_arr_2))
print("Sum_of_arr_3:", sum_of(arr_3, num_of_elements_arr_3))
print("Sr_Ar_of_arr_3:", mid_ar(arr_3, num_of_elements_arr_3))
