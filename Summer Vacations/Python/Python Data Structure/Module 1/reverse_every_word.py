sentance = input("Please Enter a sentance\n")

words=sentance.split()
reverse_sentance = ""

for word in words:
    reverse_word=word[::-1]
    reverse_sentance += reverse_word + " "

print(reverse_sentance)
