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

mag_data2=LINEAR_BLUR(mag_data,1)

plt.plot(temp_data,mag_data2)
plt.show()

for i in range(1,len(mag_data)):
	sus_data.append((mag_data[i]-mag_data[i-1])/2.0)

sus_data2=LINEAR_BLUR(sus_data,1)

plt.plot(temp_data[1:],sus_data2)
plt.show()

log_mag_data = []
log_temp_data = []
log_sus_data = []

for i in range(0,len(mag_data2)):
	log_mag_data.append(math.log10(mag_data2[i]))
for i in range(0,len(sus_data2)):
	sus_data2[i]=abs(sus_data2[i])
	if sus_data2[i]<=0:
		sus_data2[i]=.0000001
	log_sus_data.append(math.log10(sus_data2[i]))
for i in range(0,len(temp_data)):
	log_temp_data.append(math.log10(temp_data[i]))

plt.plot(log_temp_data,log_mag_data)
plt.show()

plt.plot(log_temp_data[1:],log_sus_data)
plt.show()





