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


SLOPE_CUTOFF = 1.0

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

sus_data = FIND_SLOPE(mag_data,temp_data)#temp data is to determine dT

sus_slope_data = FIND_SLOPE(sus_data, temp_data)


###find critical temperature

#initialize lists
downward_slope_pts = [0]
upward_slope_pts = [0]
downward_t_pts = [0]
upward_t_pts = [0]
downward_sus_pts = [0]
upward_sus_pts = [0]
junk,bottom = FIND_MIN_INDEX(sus_data)
bottom += 1#bottom is the index in TEMP_DATA of the minimum sus
downward_slope_pts[0]=sus_slope_data[bottom-2]
upward_slope_pts[0]=downward_slope_pts[0]
downward_t_pts[0]=temp_data[bottom]
upward_t_pts[0]=downward_t_pts[0]
downward_sus_pts[0]=sus_data[bottom]
upward_sus_pts[0]=downward_sus_pts[0]
slope=0
flag_steep = False

#populate lists with ONLY datapts that are on the "steep portion" of the sus vs t plot
itr = bottom-2#itr is the index in sus_slope_data of the min sus
for dir in (-1,1):
	while(abs(slope)>SLOPE_CUTOFF or flag_steep==False):
		itr += dir
		slope = sus_slope_data[itr]
		if dir==1:
			upward_t_pts.append(temp_data[itr+2])
			upward_sus_pts.append(sus_data[itr+1])
			upward_slope_pts.append(sus_slope_data[itr])
		else:
			downward_t_pts.append(temp_data[itr+2])
			downward_sus_pts.append(sus_data[itr+1])
			downward_slope_pts.append(sus_slope_data[itr])
		if abs(slope)> SLOPE_CUTOFF:
			flag_steep = True
	flag_steep = False
	itr = bottom-2

print ("upward slope",upward_slope_pts)
print ("downward slope",downward_slope_pts)
print ("upward T",upward_t_pts)
print ("downward T",downward_t_pts)
print ("upward sus",upward_sus_pts)
print ("downward sus",downward_sus_pts)

#find y=mx+b for both upward/downward portions of sus vs t
avg_up_slope = sum(upward_slope_pts)/float(len(upward_slope_pts))
avg_down_slope = sum(downward_slope_pts)/float(len(downward_slope_pts))
mid_up_sus = FIND_MIDPOINT_VAL(upward_sus_pts)
mid_down_sus = FIND_MIDPOINT_VAL(downward_sus_pts)

Tcrit = (mid_down_sus-mid_up_sus)/(avg_up_slope-avg_down_slope)
print ("Tcrit",Tcrit)
print (mid_down_sus,mid_up_sus,avg_up_slope,avg_down_slope)

sus_data2=LINEAR_BLUR(sus_data,1)

plt.plot(temp_data[1:-1],sus_data2)
#plt.plot(temp_data[1:-1],sus_data)

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
	log_temp_data.append(math.log10(temp_data[i]))

plt.plot(log_temp_data,log_mag_data)
plt.show()

plt.plot(log_temp_data[1:-1],log_sus_data)
plt.show()





