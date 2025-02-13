def sum_digits(num):
    sum=0
    
    while(num!=0):
        remainder=num%10
        sum += remainder
        num //= 10
    return sum

num=int(input("Enter a number : \n"))

result = sum_digits(num)

print("The sum of digits of given number is : ",result)