string=input("Enter a string :\n")
vowel="aeiouAEIOU"
count=0

for char in string:
    if char in vowel:
        count +=1

print("Vowels in string are : ",count)