#! /bin/python

import matplotlib.pyplot as plt
import numpy as np

normal_1 = np.loadtxt('normal_1_imp.txt', usecols=range(0,3))
normal_2 = np.loadtxt('normal_2_imp.txt', usecols=range(0,3))
normal_4 = np.loadtxt('normal_4_imp.txt', usecols=range(0,3))

normal_t_1 = normal_1[:,0]
normal_val_1 = normal_1[:,1]
normal_err_1 = normal_1[:,2]

normal_t_2 = normal_2[:,0]
normal_val_2 = normal_2[:,1]
normal_err_2 = normal_2[:,2]

normal_t_4 = normal_4[:,0]
normal_val_4 = normal_4[:,1]
normal_err_4 = normal_4[:,2]

plt.plot((0.,3.), (4.,4.), 'black')
plt.plot((0.,3.), (1.,1.), 'blue')
plt.plot((0.,3.), (2.,2.), 'red')
plt.errorbar(normal_t_1/20-0.01, normal_val_1, yerr=normal_err_1, color='blue', linestyle='None', label="$\omega = 1$")
plt.errorbar(normal_t_2/20, normal_val_2, yerr=normal_err_2, color='red', linestyle='None', label="$\omega = 2$")
plt.errorbar(normal_t_4/20+0.01, normal_val_4, yerr=normal_err_4, color='black', linestyle='None', label="$\omega = 4$")
plt.xlim([0,1])
plt.ylim([0,5])
plt.legend(loc=1, numpoints=1)
plt.xlabel("$t$")
plt.ylabel("$\Delta E(t)$")
#plt.title("$\Delta E(t) = E_1 - E_0$ for varying $\omega$")


plt.savefig("omegas_imp.png", dpi=300)


