list1 = []
sorted_list = []
num_of_elements_list1 = int(input('Input a number of elements for  list1: '))
print("list1  elements ")
for i in range(num_of_elements_list1):
    k = int(input(f"element  { i } of list1  =  "))
    list1.append(k)
print("Sorting lists, so after sort there should be  only unique elements from list1")
for i in list1:
    if list1.count(i) == 1:
        sorted_list.append(i)
    else:
        pass
print("so, before sorting = ", list1)
print("after sorting= ", sorted_list)







