sentence= "Hello ,My name is Awais Iftikhar"
vowels={"a",'e','i','o','u'}

vowel_coutn=0
constant_count=0

for char in sentence.lower():
    if char.isalpha:
        if char in vowels:
            vowel_coutn +=1
        else:
            constant_count +=1

print("Vowels : ",vowel_coutn)
print('constant : ',constant_count)            
