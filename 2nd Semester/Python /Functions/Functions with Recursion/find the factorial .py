def factorial(num):
    if(num==1):
        return 1
    
    return num * factorial(num-1)

num=int(input("Enter a number of which you want factorial : \n"))

result=factorial(num)

print("factorial of given number is : ",result)