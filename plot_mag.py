import numpy as np
import matplotlib.pyplot as plt
import math

measured_t_crit = 2.28
my_string = 'Critical Temperature = '+str(measured_t_crit)

def LINEAR_BLUR(data,n):
	if n==0:
		return data
	data2=[]
	for i in range(0,n):
		temp = 0
		for j in range(0,n+i+1):
			temp+=data[j]
		temp /= (i+n+1)
		data2.append(temp)
	for i in range(n,len(data)-n):
		temp = 0
		for j in range(-n,n+1):
			temp+=data[i+j]
		temp /= (2*n+1)
		data2.append(temp)
	for i in range(n-1,-1,-1):
		temp = 0
		for j in range(-(n+i+1),0):
			temp+=data[j]
		temp/=(i+n+1)
		data2.append(temp)
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
mag_data = []
sus_data = []
temp_data = []
mag_data2 = []
sus_data2 = []
temp_data2 = []
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

mag_data2=LINEAR_BLUR(mag_data,60)
plt.xlabel('Temperature (Natural Units)')
plt.ylabel('Magnetization (Natural Units)')
plt.title("Magnetization vs Temperature")
plt.plot(temp_data,mag_data2, 'k', label = 'Magnetization')
#plt.plot(temp_data,mag_data)
plt.plot((measured_t_crit,measured_t_crit), (0, 1), 'r', label = my_string) # Vertical line at critical temperature
plt.legend()
plt.show()

sus_data = FIND_SLOPE(mag_data2,temp_data)#temp data is to determine dT

sus_slope_data = FIND_SLOPE(sus_data, temp_data)


sus_data2=LINEAR_BLUR(sus_data,60)
plt.xlabel('Temperature (Natural Units)')
plt.ylabel('Susceptibility (Natural Units)')
plt.title("Susceptibility vs Temperature")
plt.plot(temp_data[1:-1],sus_data2, 'k', label = 'Susceptibility')
#plt.plot(temp_data[1:-1],sus_data)
plt.plot((measured_t_crit,measured_t_crit), (-3, 1), 'r', label = my_string) # Vertical line at critical temperature
plt.legend()
plt.show()

log_mag_data = []
log_temp_data = []
log_sus_data = []

for i in range(0,len(mag_data)):
	log_mag_data.append(math.log10(mag_data[i]))
for i in range(0,len(sus_data)):
	sus_data[i]=abs(sus_data[i])
	if sus_data[i]<=0:
		sus_data[i]=.0000001
	log_sus_data.append(math.log10(sus_data[i]))
for i in range(0,len(temp_data)):
	log_temp_data.append(math.log10(temp_data[i]-measured_t_crit))

plt.title("log magnetization vs log temperature")
plt.plot(log_temp_data,log_mag_data)
plt.show()

plt.title("log susceptibility vs log temperature")
plt.plot(log_temp_data[1:-1],log_sus_data)
plt.show()





