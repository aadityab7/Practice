a = int(input("Enter 1st value"))
b = int(input("Enter 2nd value"))
c = int(input("Enter 3rd value"))

if(a == b == c):
    print("All are equal")
else:
    if(a == b):
        print("a and b are equal")
    elif(a == c):
        print("a and c are equal")
    elif(b == c):
        print("b and c are equal")

    if(a > b) and (a > c) :
        print(a, "is greater")
    elif (b > c) and (b > a):
        print(b, "is greater")
    elif (c > a) and (c > b):
        print(c, "is greater")

    if(a < b) and (a < c):
        print(a, "is minimum")
    elif(b < c) and (b < a):
        print(b, "is minimum")
    elif(c < a) and (c < b):
        print(c, "is minimum")
