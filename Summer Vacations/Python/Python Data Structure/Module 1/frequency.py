sentance = input("Please Enter a sentance\n")
sentance = sentance.replace(" ","")

counted = ""

for char in sentance:
    if char not in counted:
        count = sentance.count(char)
        print(f"'{char}' : {count}")
        counted += char