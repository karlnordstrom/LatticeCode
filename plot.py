#! /bin/python

import matplotlib.pyplot as plt
import numpy as np

normal = np.loadtxt('normal.txt', usecols=range(0,3))
improved = np.loadtxt('improved.txt', usecols=range(0,3))

normal_t = normal[:,0]
normal_val = normal[:,1]
normal_err = normal[:,2]

improved_t = improved[:,0]
improved_val = improved[:,1]
improved_err = improved[:,2]

plt.plot((0.,3.), (2.,2.), 'black')
plt.errorbar(normal_t/4-0.01, normal_val, yerr=normal_err, color='blue', linestyle='None', label="$1^{st}$ order")
plt.errorbar(improved_t/4+0.01, improved_val, yerr=improved_err, color='red', linestyle='None', label="$2^{nd}$ order")
plt.legend(loc=0, numpoints=1)
plt.xlabel("$t$")
plt.ylabel("$\Delta E(t)$")
plt.title("Results using $1^{st}$ and $2^{nd}$ order finite difference")


plt.savefig("comparison.png", dpi=300)
