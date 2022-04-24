#lex_auth_012751865474736128227
#Start writing your code here
class Customer:
	def __init__(self,customer_id,customer_name,address):
		self.__customer_id=customer_id
		self.__customer_name=customer_name
		self.__address=address
	def validate_customer_id(self):
		if len(str(self.__customer_id))==6 and str(self.__customer_id).startswith("1"):
			return True
		return False
	def get_customer_id(self):
		return self.__customer_id
	def get_customer_name(self):
		return self.__customer_name
	def get_address(self):
		return self.__address

class Freight:
	counter=200
	def __init__(self,recipient_customer,from_customer,weight,distance):
		self.__freight_id=None
		self.__recipient_customer=recipient_customer
		self.__from_customer=from_customer
		self.__weight=weight
		self.__distance=distance
		self.__freight_charge=None
	def validate_weight(self):
		if self.__weight%5==0:
			return True
		return False
	def validate_distance(self):
		if self.__distance>=500 and self.__distance<=5000:
			return True
		return False
	def forward_cargo(self):
		if self.__recipient_customer.validate_customer_id() and self.__from_customer.validate_customer_id() and self.validate_weight() 				and self.validate_distance():
			if Freight.counter>=200:
				self.__freight_id=Freight.counter
			else:
				Freight.counter=200
				self.__freight_id=Freight.counter
			Freight.counter+=2
			self.__freight_charge=(150*self.__weight)+(60*self.__distance)
		else:
			self.__freight_charge=0
	def get_freight_id(self):
		return self.__freight_id
	def get_recipient_customer(self):
		return self.__recipient_customer
	def get_from_customer(self):
		return self.__from_customer
	def get_weight(self):
		return self.__weight
	def get_distance(self):
		return self.__distance
	def get_freight_charge(self):
		return self.__freight_charge

cus1=Customer(100256,"akash","bmsce")
cus2=Customer(167800,"rahul","banashankari")
fre1=Freight(cus1,cus2,50,1500)
fre1.forward_cargo()
print(fre1.get_freight_id())
print(fre1.get_freight_charge())
print(cus1.get_customer_id())
