import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import axes3d
import numpy as np

size = (5, 5, 5)
LEDcount = size[0] * size[1] * size[2]
LEDs = np.zeros((*size, 3))
cubeStates = []

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
        currentState = np.copy(LEDs)
        for i in range(LEDcount):
            currentState[i//(size[0]*size[1]), (i//size[1])%size[1], i%size[0]] = parseLED(lineArr[i+1])
        currentState = np.reshape(currentState.flatten(), (LEDcount, 3))
        cubeStates.append((int(lineArr[0]), currentState))

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
#ax.set_xlabel('X')
#ax.set_ylabel('Y')
#ax.set_zlabel('Z')

x = [i for i in range(size[0])]*size[1]*size[2]
y = [(i//size[1])%size[1] for i in range(LEDcount)]
z = [i//(size[0]*size[1]) for i in range(LEDcount)]

ax.scatter(x, y, z, c=cubeStates[0][1], depthshade=False, s=100)
plt.show()

