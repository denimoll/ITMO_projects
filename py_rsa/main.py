import random

def binar(a,x,p):
	y = 1
	s = a
	x2 = bin(x)
	x2 = x2[2:]
	x2 = x2[::-1]
	for i in str(x2):
		if (i == '1'):
			y = (y*s)%p
		s = (s*s)%p
	return y



p = int(input("p = "))
q = int(input("q = "))
if (p<=1 or q<=1 or p==q): 
	print("bad parametrs")
	exit()
s1 = 0
s2 = 0
#for i in range(2,p):
#	if (p%i==0): s1+=1
#for i in range(2,q):
#	if (q%i==0): s2+=1
#if (s1!=0 or s2!=0):
#	print("bad parametrs")
#	exit()
for i in range(2,p):
	if (p%i==0): s1+=1
while s1!=0:
	p+=1
	s1=0
	for i in range(2,p):
		if (p%i==0): s1+=1
for i in range(2,q):
	if (q%i==0): s2+=1
while s2!=0:
	q+=1
	s2=0
	for i in range(2,q):
		if (q%i==0): s2+=1

n = p*q
fi = (p-1)*(q-1)
mas_e = []
for i in range(2,fi):
	s3 = 0
	for j in range(2,i):
		if (i%j==0): s3+=1
	if (s3==0):
		mas_e.append(i)
random.shuffle(mas_e)
e = mas_e[random.randint(0,len(mas_e))]
print()
for i in range(fi*2):
	if ((i*e)%fi==1 and i!=e):
		d = i
		continue

print("p = ", p, "q = ", q, "n = ", n, "fi = ", fi, "e = ", e, "d = ", d, "\n")
print("Открытая часть ключа (", e, ", ",n,")")
print("Закрытая часть ключа (", d, ",",n,")\n")

s = ''
x = str(input("введите x = "))
for letter in x:
	y = ord(letter)
	c = binar(y,e,n)
	s+=(chr(c))
print("Зашифрованная фраза - ", s)

ss = ''
for letter in s:
	y = ord(letter)
	z = binar(y,d,n)
	ss+=(chr(z))
print("Расшифрованная фраза - ", ss)

#x = int(input("введите число, которое хотели бы зашифровать. x = "))
#c = (x**e)%n
#print("Зашифрованное число c = ", c)
#x1 = (c**d)%n
#print("Для проверки проведем дешифрование и получим x = ", x1)
