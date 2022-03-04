print("Welcome to Aaditya's CLI Calculator")
f = 0

def plus(x,y):
	return (x + y)

def sub(x, y):
	return (x - y)

def div(x, y):
	return (x / y)

def mod(x, y):
	return (x % y)

def mul(x, y):
	return (x * y)

while(f == 0):
	fl = 0
	flag = 0
	a = input("Enter the first value : ")
	b = input("Enter the second value : ")

	for i in a:
		if(i >= '0' and i <= '9'):
			continue
		elif(i == '.'):
			flag = 1
			continue
		else:
			print("Invalid number", a)
			fl = 1
			break

	for i in b:
		if(i >= '0' and i <= '9'):
			continue
		elif(i == '.'):
			flag = 1
			continue
		else:
			print("Invalid number",b)
			fl = 1
			break

	if(fl == 1):
		continue

	if(flag == 1):
		a = float(a)
		b = float(b)
	else:
		a = int(a)
		b = int(b)

	op = input("Enter a operator (+, -, *, /, %) for operation to be performed : ")

	if(op == '+'):
		c = plus(a,b)
	elif(op == '-'):
		c = sub(a,b) 
	elif(op == '/'):
		if(b == 0):
			print("Division by 0 NOT allowed")
			continue
		else:
			c = div(a, b)
	elif(op == '%'):
		if(b == 0):
			print("Division by 0 NOT allowed")
			continue
		else:
			c = mod(a, b)
	elif(op == '*'):
		c = mul(a, b)
	else:
		print("Invalid operator")
		continue


	if(flag != 1):
		c = int(c)
	
	print(a, op, b, "=", c)

	f = int(input("Enter 0 to use Calculator again : ")) 