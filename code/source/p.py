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
sdev2 = np.std(z)
axis = np.array(["Comp_1","Comp_2","Comp_3"])
a = np.array([Mean1, Mean2, Mean3])
e = np.array([sdev, sdev1, sdev2])
a1 = np.array([Mean1, Mean2])
e1 = np.array([sdev, sdev1])
axis1 = np.array(["Comp_1","Comp_2"])
plt.errorbar(axis, a, e, linestyle='None', marker='.', capsize = 3)
plt.ylabel("Error")
plt.subplot(212)
plt.errorbar(axis1, a1, e1, linestyle='None', marker='.', capsize = 3)
plt.ylabel("Error")

fig1.savefig('output/fig1.png')

