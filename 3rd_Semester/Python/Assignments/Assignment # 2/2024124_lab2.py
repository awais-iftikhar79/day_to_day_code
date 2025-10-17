name="Awais Iftikhar"
reg="2024124"

splitted_name=name.split(' ')

first_name=splitted_name[0]
last_name=splitted_name[1]

even_indices=reg[0::2]
odd_indices=reg[1::2]

even_reversed=even_indices[::-1]

nested_structure=[first_name, last_name, even_indices, odd_indices]

nested_structure[2]=even_reversed

final_string=last_name.upper()+", "+first_name.upper()+" | @"+first_name+str(reg[-2:])+" | tag: "+even_reversed+" | reg: "+str(reg)+" | len: "+str(len(name.replace(" ", "")))

print(final_string)