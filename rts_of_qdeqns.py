from math import sqrt
import cmath

def my_input():
	a=int(input("Enter the value of a in the quadratic equation="))
	b=int(input("Enter the value of b in the quadratic equation="))
	c=int(input("Enter the value of c in the quadratic equation="))
	return a,b,c
	
def my_rts(a,b,c):
	z=(b**2)-(4*a*c)
	p=cmath.sqrt(z)/2*a
	x=(-b/2*a)+p
	y=(-b/2*a)-p
	return x,y,z
	
def my_output(x,y,z,a,b,c):
	print("the roots of the quadratic equation (%d)x^2 + (%d)x + (%d) are"%(a,b,c))
	print(x,y)
		
def main():
	a,b,c=my_input()
	x,y,z=my_rts(a,b,c)
	my_output(x,y,z,a,b,c)
	
main()