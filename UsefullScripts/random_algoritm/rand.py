from random import random, randint, randrange
from matplotlib import pyplot as plt

def rand_func(seed=100):
    los = (randint(10,1000) * seed + randint(10,1000)) % randint(1000,10000)
    return los

with open('data.txt','w+') as file:
    for i in range(30000):
        file.write(str(rand_func()%100)+' ')

with open('data.txt') as file:
    str_data = filter(lambda x:x!= "",file.readlines()[0].split(' '))
    int_data = [int(x) for x in str_data]
    plt.figure(1,figsize=(16,8))
    plt.hist(int_data,bins=100)
    plt.title("Distribution for cubes=100 n=30000")
    plt.savefig("rand100.png", format="png")
    # plt.show()
    int_data_short = int_data[:1000]
    plt.figure(2,figsize=(16,8))
    plt.hist(int_data_short,bins=100)
    plt.title("Distribution for cubes=100 n=1000")
    plt.savefig("rand100_short.png", format="png")
    plt.show()

"""
Conclusion:
By analizing small amout of data n<1000 we can see some of areas are more prefered than the others,
with n~30000 we see the same probability for exist each number. 
"""
