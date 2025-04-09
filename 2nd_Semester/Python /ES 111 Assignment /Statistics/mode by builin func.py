import statistics as st

my_list=[1,2,2,2,3,3,3,3,4,4,6,6,6,6,6,6,6,6,6,1,1]
my_tuple=(2,3,3,4,4,4,4,4,4,7,8,8,9,9,5,6,1)

mode_value1=st.mode(my_list)
mode_value2=st.mode(my_tuple)

print("Mode of list is : ",mode_value1)
print("Mode of Tuple is : ",mode_value2)