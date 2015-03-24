import numpy as np
import matplotlib.pyplot as plt
import math


fig, ax = plt.subplots()
mag_data = []
sus_data = []
f = open("data/mag.txt")
temp_val = 0
for line in f:
	for z in line.split():
		temp_val = float(z)
	mag_data.append(temp_val)

plt.plot(mag_data)
plt.show()
for i in range(1,len(mag_data)):
	sus_data.append((mag_data[i]-mag_data[i-1])/2.0)
plt.plot(sus_data)
plt.show()
f.close()





