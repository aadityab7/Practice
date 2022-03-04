#we can directly write numbers inside args instead of variables
#range can take 3 args

#with one argument -> final value only
n = 10
for i in range(n):
    print(i)

#with two args -> initial and final value
m = 1
for i in range(m, n + 1):
    print(i)

#with three args -> initial , final and increment value
#printing table of user defined integer x : 
x = int(input("Enter number : "))
y = (x * 10) + 1
for i in range(x, y , x):
    print(x, "*", int(i / x) ,"=", i)

#another logic for table
i = 1
f = 11
for i in range(i, f):
    print(x, "*", i, "=", x * i)
    print("{} * {} = {}".format(x, i, x * i))

#print("{} * {} = {}".format(x, i, x * i)) is another way for
#writing the formatted string (i.e. include variables in output
#string)

count = 1
for i in range(x, y, x):
    print("{} * {} = {}".format(x, count, x * count))
    count  = count + 1
