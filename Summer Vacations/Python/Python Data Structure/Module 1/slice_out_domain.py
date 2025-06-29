email = input("Please Enter your Email\n")
position = email.rfind("@")

print("Domain :",email[position+1:])