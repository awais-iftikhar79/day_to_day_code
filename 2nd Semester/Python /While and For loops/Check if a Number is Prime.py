num=int(input("Entr a number you want to check prime "))

i=2
check=0

while i<=num:
    if(num%i==0):
        check += 1
    i += 1

if check==1:
    print("The number is prime ")
else: 
    print("The number is not prime")    