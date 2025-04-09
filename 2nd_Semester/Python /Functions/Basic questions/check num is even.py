def check_even(a):
    if a%2==0:
        return True
    else:
        return False

num=int(input("Enter a number to check it is even or not : "))

result=check_even(num)

print("Number is even : ",result)