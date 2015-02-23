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

plt.errorbar(normal_t/4, normal_val, yerr=normal_err, color='blue')

plt.xlabel("$t$")
plt.ylabel("$\Delta E(t)$")

plt.errorbar(improved_t/4, improved_val, yerr=improved_err, color='red')

plt.xlabel("$t$")
plt.ylabel("$\Delta E(t)$")
plt.title("Results using $1^{st}$ and $2^{nd}$ order finite difference")
plt.savefig("comparison.png")