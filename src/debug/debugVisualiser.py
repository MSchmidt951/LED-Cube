import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import axes3d
import numpy as np

##Settings
size = (5, 5, 5)
constUpdateRate = True

LEDcount = size[0] * size[1] * size[2]
LEDs = np.zeros((*size, 3))
cubeStates = [np.reshape(np.copy(LEDs).flatten(), (LEDcount, 3))]
cubeStateTime = np.array([0])

def parseLED(text):
    return np.array([
        strToCol(text, 0),
        strToCol(text, 1),
        strToCol(text, 2)
    ])
def strToCol(s, i):
    return int(s[2*i:2*i+2], 16) / 255

with open('debugData.txt', 'r') as file:
    for line in file:
        lineArr = line.split(',')
        currentState = np.copy(LEDs).reshape(LEDcount, 3)
        for i in range(LEDcount):
            currentState[i] = parseLED(lineArr[i+1])

        cubeStates = np.concatenate((cubeStates, [currentState]), axis=0)
        cubeStateTime = np.append(cubeStateTime, int(lineArr[0]))

plt.ion()
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

x = [i for i in range(size[0])] * size[1]*size[2]
y = [(i//size[0])%size[1] for i in range(LEDcount)]
z = [i//(size[0]*size[1]) for i in range(LEDcount)]

lastUpdate = 0
for i in range(1, len(cubeStates)):
    if constUpdateRate:
        plt.pause(.1)
    else:
        plt.pause((cubeStateTime[i] - lastUpdate)/2000)
    lastUpdate = cubeStateTime[i]
    ax.clear()
    ax.scatter(x, y, z, c=cubeStates[i], depthshade=False, s=100)
    fig.canvas.draw()
