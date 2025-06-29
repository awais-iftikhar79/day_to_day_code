word = input("Please Enter a word \n")

reverse = word[::-1]

if word == reverse:
    print(f"The {word} is Plaindrome")
else:
    print(f"The {word} is not Plaindrome")