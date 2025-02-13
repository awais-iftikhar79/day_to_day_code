def is_palindrome(my_string):
    temp_string=my_string[::-1]
    if(temp_string==my_string):
        print("The given string is palindrome ")
    else:
        print("The given string is not palindrome")

my_string=input("Enter a string : \n")

is_palindrome(my_string)