#taking input and type casting
b = int(input("Enter number of times you want to run : "))

#taking input
a = input("Enter a number in int : ")
print(type(a))

c = float(input("Enter value"))

#type casting        
a= int(a)
print(type(a))

#even odd
if(a == 0):
    print('Zero')
elif a % 2 == 0:
    print('Even')
else :
    print('Odd')

#for float value input 
x = c % 2
if(c == 0):
    print('Zero')
elif x == 0:
    print(x) 
    print('Even')
else :
    print(x)
    print('Odd')
