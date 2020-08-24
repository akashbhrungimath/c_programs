def my_input():
    a=int(input("Enter the first number="))
    b=int(input("Enter the second number="))
    return a,b
    
def my_add(a,b):
    s=a+b
    return s
    
def my_output(x,y,s):
    print("%d + %d is %d"%(x,y,s))

def main():
    x,y=my_input()
    s=my_add(x,y)
    my_output(x,y,s)
    
main()