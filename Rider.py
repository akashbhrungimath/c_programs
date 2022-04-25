#lex_auth_0127475574441738242319
#Start writing your code here
class Rider:
	def __init__(self,experience,trained_status):
		self.__experience=experience
		self.__trained_status=trained_status
	def rides_vehicle(self):
		print("rides vehicle")

class BikeRider(Rider):
	def __init__(self,experience,trained_status,race_license):
		self.__race_license=race_license
		super().__init__(experience,trained_status)
	def rides_in_dome(self):
		print("rides in dome")

class CycleRider(Rider):
	def rides_blindfolded(self):
		print("rides blindfolded")

akash=BikeRider(3,True,True)
rahul=CycleRider(3,True)
akash.rides_vehicle()
akash.rides_in_dome()
rahul.rides_vehicle()
rahul.rides_blindfolded()
