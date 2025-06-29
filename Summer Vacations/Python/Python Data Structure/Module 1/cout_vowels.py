name = input("Please Enter your Name : ")
vowels="aeiouAEIOU"

count=0

for char in name:
    if char in vowels:
        count = count + 1
    
print("Vowels is Name : ",count)