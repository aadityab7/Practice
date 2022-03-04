a = int(input("Enter 1st value"))
b = int(input("Enter 2nd value"))
c = int(input("Enter 3rd value"))

if(a > b and a > c) :
    print(a, "is greater than", b, "and", c)
elif (b > c):
    print(b, "is greater")
else:
    print(c, "is greater")

if(a < b) and (a < c):
    print(a, "is minimum")
elif(b < c):
    print(b, "is minimum")
else:
    print(c, "is minimum")
