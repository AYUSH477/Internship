import matplotlib.pyplot as plt
import numpy as np
from scipy import stats
with open('output/output1.txt') as f:
    lines = f.readlines()
    x = [line.split()[6] for line in lines]

with open('output/output2.txt') as f:
    lines = f.readlines()
    y = [line.split()[6] for line in lines]
with open('output/output3.txt') as f:
    lines = f.readlines()
    z = [line.split()[6] for line in lines]
val = 10
x = [float(a) for a in x]
y = [float(a) for a in y]
z = [float(a) for a in z]
fig1 = plt.figure()
plt.subplot(211)
Mean1 = np.mean(x)
Median1 = np.median(x)
sdev =  np.std(x)
Mean2 = np.mean(y)
Median2 = np.median(y)
sdev1 =  np.std(y)
Mean3 = np.mean(z)
Median3 = np.median(z)
plt.plot(x, len(x) * [val], ".", label = "Set-1; Mean: {:0.4f}, Median: {:0.4f}".format(Mean1, Median1))
plt.plot(y, len(y) * [val-5], ".", label = "Set-2; Mean: {:0.8f}, Median: {:0.8f}".format(Mean2, Median2))
plt.plot(z, len(z) * [val-10], ".", label = "Set-3; Mean: {:0.4f}, Median: {:0.4f}".format(Mean3, Median3))
plt.xlabel("Error")
plt.legend()
plt.subplot(212)
plt.plot(x, len(x) * [val], ".", label = "Set-1, std: {:0.8f}".format(sdev))
plt.plot(y, len(y) * [val-5], ".", label = "Set-2, std: {:0.8f}".format(sdev1))
plt.xlabel("Error")
plt.legend()
fig1.savefig('output/fig1.png')

