from math import sqrt

def my_input():
	a=int(input("Enter the value of a in the quadratic equation="))
	b=int(input("Enter the value of b in the quadratic equation="))
	c=int(input("Enter the value of c in the quadratic equation="))
	return a,b,c
	
def my_rts(a,b,c):
	z=b**2-4*a*c
	if  z>0:
		x=(-b+sqrt(z))/2*a
		y=(-b-sqrt(z))/2*a
	elif z<0:
		x=complex((-b/2*a),(z/2*a))
		y=complex((-b/2*a),-(z/2*a))
	else:
		x=-b/2*a
		y=-b/2*a
	return x,y,z
	
def my_output(x,y,z,a,b,c):
	if z<0:
		print("the roots of the quadratic equation (%d)x^2 + (%d)x + (%d) are"%(a,b,c))
		print(x,y)
	else:
		print("the roots of the quadratic equation (%d)x^2 + (%d)x + (%d) are %f and %f"%(a,b,c,x,y))
	
def main():
	a,b,c=my_input()
	x,y,z=my_rts(a,b,c)
	my_output(x,y,z,a,b,c)
	
main()