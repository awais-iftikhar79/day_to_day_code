num=int(input("Enter a number : "))

count=0
num = abs(num)

for  digits in str(num):
    count += 1

print(f"The number of digits in number is : {count}")