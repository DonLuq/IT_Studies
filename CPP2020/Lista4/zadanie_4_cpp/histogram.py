#!/usr/bin/env python3
import pandas as pd
import sys
from matplotlib import pyplot as plt

with open(sys.argv[1]) as file:
    X = file.readlines()
    for i in range(0,len(X)):
        X[i] = float(X[i].replace("\n",""))
    num_bins = 100
    plt.hist(X, num_bins, facecolor='blue', alpha=0.5)
    plt.show()


# N = 10
# tab = []
# for i in range(0, N):
#     tab.append(0)
# with open(A) as file:
#     Data = file.readlines()
#     for element in Data:
#         print(element)
#         for i in range(0, N):
#             if float(element) > 1/N * i and float(element) < 1/N * (i+1):
#                 tab[i] += 1

# tab2 = []
# for i in range(0, N):
#     tab2.append(1/N*i)

# for i in tab2:
#     print(i)

# OB = plt.bar(tab2,tab)
# plt.show(OB)