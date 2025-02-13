def unique_list(my_list):
    print("Actula list is : ",my_list)
    unique=list(set(my_list))
    return unique 

my_list=[1,2,2,3,4,4,5,5,6,8,8,8,8]

result=unique_list(my_list)

print("Unique List is : ",result)