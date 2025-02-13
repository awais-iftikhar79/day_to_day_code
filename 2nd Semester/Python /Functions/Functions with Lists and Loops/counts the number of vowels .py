def count_vowels(my_string):
    vowels="aeiouAEIUO"
    count=0
    for char in my_string:
        if char in vowels:
            count +=1
    return count

my_string=input("Enter a string :\n")

result=count_vowels(my_string)

print("Number of vowels character in your string is : ",result)
