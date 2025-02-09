num=int(input("Enter a number of which you want factorial "))

fact=1
i=1

while i<=num:
    fact *= i
    i += 1

print("Factorial of your number is : ",fact)