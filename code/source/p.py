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
plt.rcParams.update({'font.size': 5})
Mean1 = np.mean(x)
sdev =  np.std(x)
Mean2 = np.mean(y)
sdev1 =  np.std(y)
Mean3 = np.mean(z)
sdev2 = np.std(z)
axis = np.array(["Comp_1","Comp_2","Comp_3"])
a = np.array([Mean1, Mean2, Mean3])
e = np.array([sdev, sdev1, sdev2])
a1 = np.array([Mean1, Mean2])
e1 = np.array([sdev, sdev1])
axis1 = np.array(["Comp_1","Comp_2"])
plt.errorbar(axis, a, e, linestyle='None', marker='.', capsize = 3, label = "Comp_1. Mean: {} sd: {}\n Comp_2. Mean: {} sd: {}\n Comp_3. Mean: {} sd: {}\n ".format(Mean1,sdev, Mean2, sdev1, Mean3, sdev2))
plt.ylabel("Error")
plt.legend()
plt.subplot(212)
plt.errorbar(axis1, a1, e1, linestyle='None', marker='.', capsize = 3)
plt.ylabel("Error")

fig1.savefig('output/fig1.png')
