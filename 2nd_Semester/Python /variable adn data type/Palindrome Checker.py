string=input("Enter a palindrome word :\n")

reverse=string[::-1]

if(string==reverse):
    print("String is palindrome")
else:
    print("String is nopt palindrome")