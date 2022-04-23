#lex_auth_012751861844041728222
#Start writing your code here
class Parrot:
	__counter=7001
	def __init__(self,name,color):
		self.__name=name
		self.__color=color
		self.__unique_number=Parrot.__counter+1
		Parrot.__counter+=1
	def get_name(self):
		return self.__name
	def get_color(self):
		return self.__color
	def get_unique_number(self):
		return self.__unique_number

p1=Parrot("Chichu","Green")
print(p1.get_unique_number())
