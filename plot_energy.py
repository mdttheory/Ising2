import numpy as np
import matplotlib.pyplot as plt
import math

def LINEAR_BLUR(data,n):
	if n==0:
		return data
	if n==1:
		data2=[]
		data2.append((data[0]+data[1])/2)
		for i in range(1,len(data)-1):
			data2.append((data[i-1]+data[i]+data[i+1])/3.0)
		data2.append((data[-2]+data[-1])/2)
		return data2
def FIND_SLOPE(ydata,xdata):
	slope_data=[]
	for i in range(1,len(ydata)-1):
		slope_data.append((ydata[i+1]-ydata[i-1])/(xdata[i+1]-xdata[i-1]))#(m(i+1)-m(i-1))/2*dt
	return slope_data

def FIND_MIN_INDEX(my_list): #found on stackoverflow
	val, idx = min((val, idx) for (idx, val) in enumerate(my_list))
	return val,idx

def FIND_MIDPOINT_VAL(data):
	length = len(data)
	mid = int(length/2)#round down b/c 0-indexed
	if length%2==0:#even
		return (data[mid]+data[mid-1])/2.0
	else:#odd
		return data[mid]



fig, ax = plt.subplots()
energy_data = []
heat_data = []
temp_data = []
energy_data2 = []
heat_data2 = []
temp_data2 = []
f = open("data/energy.txt")
value = 0
i = 0
for line in f:
	if i%2==1:
		energy_data.append(float(line))
	else:
		temp_data.append(float(line))
	i+=1

f.close()

energy_data2=LINEAR_BLUR(energy_data,1)

plt.title("energy vs temperature")
#plt.plot(temp_data,energy_data2)
plt.plot(temp_data,energy_data)
plt.show()

heat_data = FIND_SLOPE(energy_data,temp_data)#temp data is to determine dT

heat_data2=LINEAR_BLUR(heat_data,1)

plt.title("specific heat vs temperature")
#plt.plot(temp_data[1:-1],heat_data2)
plt.plot(temp_data[1:-1],heat_data)

plt.show()






