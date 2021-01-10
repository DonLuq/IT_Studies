from matplotlib import pyplot as plt

start_dataX = []
start_dataY = []
with open('start_data.txt','r') as file:
    for line in file.readlines():
        start_dataX.append(float(line.split(':')[0]))
        start_dataY.append(float(line.split(':')[1][:-1]))

dataX = []
dataY = []
with open('data.txt','r') as file:
    for line in file.readlines():
        dataX.append(float(line.split(':')[0]))
        dataY.append(float(line.split(':')[1][:-1]))

# print(dataX)
# print(dataY)

plt.figure(1)
plt.grid(True)
plt.plot(dataX,dataY)
plt.plot_date(start_dataX,start_dataY,xdate=False, fmt='x')
plt.show()




