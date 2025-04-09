dict={
    "Python":90,
    "C++":88,
    "Java":80
}
print("Original dictionary is : ",dict)

dict["Python"]=95
print("After update of python : ",dict)

del dict["Java"]
print("After removing java : ",dict)