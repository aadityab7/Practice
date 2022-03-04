a = int(input("Enter 1st value"))
b = int(input("Enter 2nd value"))
c = int(input("Enter 3rd value"))

max = a
min = a

if(b > max):
    max = b
if c > max :
    max = c

if(b < min):
    min = b
if c < min :
    min = c

print(max)
print(min)
