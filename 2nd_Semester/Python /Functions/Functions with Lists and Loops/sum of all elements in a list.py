def sum(my_list):
    sum=0
    for i in my_list:
        sum += i
    return sum

my_list=[1,2,3,4,5,6,7,8,9]

result = sum(my_list)

print("The sum of all elements in list is : ",result)
