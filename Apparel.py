#lex_auth_012753087522512896330
#Start writing your code here
class Apparel:
	counter=100
	def __init__(self,price,item_type):
		self.__item_id=None
		Apparel.counter+=1
		if item_type=="Cotton":
			self.__item_id="C"+str(Apparel.counter)
		elif item_type=="Silk":
			self.__item_id="S"+str(Apparel.counter)
		else:
			print("Invalid 'item type'")
		self.__price=price
		self.__item_type=item_type
	def calculate_price(self):
		self.__price+=0.05*self.__price
	def get_item_id(self):
		return self.__item_id
	def get_price(self):
		return self.__price
	def get_item_type(self):
		return self.__item_type
	def set_price(self,price):
		self.__price=price

class Cotton(Apparel):
	def __init__(self,price,discount):
		super().__init__(price,"Cotton")
		self.__discount=discount
	def calculate_price(self):
		super().calculate_price()
		self.set_price(self.get_price()-self.__discount*self.get_price()/100)
		self.set_price(self.get_price()+self.get_price()*5/100)
	def get_discount(self):
		return self.__discount

class Silk(Apparel):
	def __init__(self,price):
		super().__init__(price,"Silk")
		self.__points=None
	def calculate_price(self):
		super().calculate_price()
		if self.get_price()>10000:
			self.__points=10
		else:
			self.__points=3
		self.set_price(self.get_price()+self.get_price()*10/100)
	def get_points(self):
		return self.__points

cot1=Cotton(1000,5)
sil1=Silk(9000)
cot1.calculate_price()
sil1.calculate_price()
print(cot1.get_price())
print(sil1.get_price())
