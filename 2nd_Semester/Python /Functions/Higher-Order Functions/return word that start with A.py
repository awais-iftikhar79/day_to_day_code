words_list=["Anas","Ali","Saad","Talha"]
words_with_A=list(filter(lambda x : x.lower().startswith('a'),words_list))

print("Words start with A are : ",words_with_A)