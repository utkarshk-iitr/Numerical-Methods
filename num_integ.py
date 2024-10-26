from math import *

def f(x):
    a = x/sin(x)
    return a

a = 0.4
b = 1.6
n = 12
h = (b-a)/n

tr = f(a)+f(b)
for i in range(1,n):
    tr += 2*f(a+h*i)
print(tr*h/2)

obyt = tr
for i in range(1,n,2):
    obyt += 2*f(a+h*i)
print(obyt*h/3)

tby8 = tr
for i in range(1,n):
    if i%3!=0:
        tby8 += f(a+h*i)
print(tby8*3*h/8)