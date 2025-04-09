from functools import reduce

my_list=[1,2,5,34,6,4,67,34,7,64]
sum_of_all=reduce(lambda x ,y: x+y,my_list)

print("Sum of all number s in lis is : ",sum_of_all)