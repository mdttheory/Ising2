import numpy as np
import matplotlib.pyplot as plt
import math

def FIND_SLOPE(ydata,xdata):
	slope_data=[]
	for i in range(1,len(ydata)-1):
		slope_data.append((ydata[i+1]-ydata[i-1])/(xdata[i+1]-xdata[i-1]))#(m(i+1)-m(i-1))/2*dt
	return slope_data

def FIND_MIN_INDEX(my_list): #found on stackoverflow
	val, idx = min((val, idx) for (idx, val) in enumerate(my_list))
	return val,idx

mag_data = []
sus_data = []
temp_data = []
f = open("data/mag.txt")
value = 0
i = 0
for line in f:
	if i%2==1:
		for z in line.split():
			value = float(z)
		mag_data.append(value)
	else:
		temp_data.append(float(line))
	i+=1

f.close()

sus_data = FIND_SLOPE(mag_data,temp_data)#temp data is to determine dT

sus_slope_data = FIND_SLOPE(sus_data, temp_data)








