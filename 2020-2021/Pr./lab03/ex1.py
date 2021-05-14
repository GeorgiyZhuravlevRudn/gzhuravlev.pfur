list1 = []
list2 = []
num_of_elements_list1 = int(input('Input a number of elements for  list1: '))
num_of_elements_list2 = int(input('Input a number of elements for  list2: '))
print("list1  elements ")
for i in range(num_of_elements_list1):
    k = int(input(f"element  { i } of list1  =  "))
    list1.append(k)
print("list2 elements ")
for i in range(num_of_elements_list2):
    k = int(input(f"element  { i } of list2  =  "))
    list2.append(k)
print("so, list 1 =", list1)
print("list 2 =", list2)
print("Sorting lists, so after sort there shouldn't be any elements from list2 in list1")
for i in list2:
    if i in list1:
        list1.remove(i)
    else:
        pass

print("so, list 1 =", list1)
print("list 2 =", list2)







