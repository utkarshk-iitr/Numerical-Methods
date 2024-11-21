from math import *

def f(x,y):
    a = (y*y-x*x)/(y*y+x*x)
    return a

h = 0.1
x = 0.4
z = int(x/h)

xs = [0]
ys = [1]

for i in range(z):
    k1 = h*f(xs[-1],ys[-1])
    k2 = h*f(xs[-1]+h/2,ys[-1]+k1/2)
    k3 = h*f(xs[-1]+h/2,ys[-1]+k2/2)
    k4 = h*f(xs[-1]+h,ys[-1]+k3)
    k = (k1+2*k2+2*k3+k4)/6
    xs.append(xs[-1]+h)
    ys.append(ys[-1]+k)

print(xs)
print(ys)
