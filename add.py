def my_input():
    a=float(input("Enter the first number="))
    b=float(input("Enter the second number="))
    return a,b
    
def my_add(a,b):
    s=a+b
    return s
    
def my_output(x,y,s):
    print("%f + %f is %f"%(x,y,s))

def main():
    x,y=my_input()
    s=my_add(x,y)
    my_output(x,y,s)
    
main()