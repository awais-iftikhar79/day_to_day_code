list_a=[1,2,3,5,7]
list_b=[2,5,7,9,8,4]

set_a=set(list_a)
set_b=set(list_b)

union=set_a & set_b
unique_in_a=set_a-set_b
unique_in_b=set_b-set_a

print("Common elemnts are : ",union)
print('Unique Elemnets in list A is : ',unique_in_a)
print('Unique Elemnets in list B is : ',unique_in_b)