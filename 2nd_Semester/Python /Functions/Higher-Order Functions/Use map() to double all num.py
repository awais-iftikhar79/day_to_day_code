def double(my_list):
    my_list=list(map(lambda x: x* 2,my_list))
    return my_list

my_list=[1,2,3,4,5,6,7,8]
print("Original list is : ",my_list)

result=double(my_list)
print("Double of all element in list is : ",result)
