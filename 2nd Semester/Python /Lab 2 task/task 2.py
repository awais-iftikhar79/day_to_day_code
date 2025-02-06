my_tuple=(4, 2, 9, 1, 8, 3)

max_num=max(my_tuple)
min_num=min(my_tuple)
sum_num=sum(my_tuple)

tuple_to_list=set(list(my_tuple))
list_to_touple=tuple(tuple_to_list)


print("Maximum number is : ",max_num)
print("Minimum number is : ",min_num)
print("Sum of ellemnts in list is : ",sum_num)
print("Original tuple is : ",my_tuple)
print("Tuple in sorted way is : ",list_to_touple)
