def fabconi(num):
    if(num==0 ):
        return 0
    elif(num==1):
        return 1
    return fabconi(num-1) + fabconi(num-2)

num=int(input("Enter an number : "))

result=fabconi(num)

print("The fabconi number is : ",result)