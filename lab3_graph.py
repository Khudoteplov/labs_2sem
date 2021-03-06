import numpy as np
import matplotlib.pyplot as plt


p = [10, 40, 100, 400, 1000, 4000, 10000, 40000, 100000]


plt.plot(p, [5,  22, 48,380.8, 1868 , 33243, 150785, 2211273, 13380856])
plt.title('Массив без аммортизации')
plt.yscale('log')
plt.xscale('log')
plt.show()


a = [10, 50, 100, 400, 1000, 4000, 10000, 40000, 100000, 1000000, 10000000, 40000000, 100000000]
plt.plot(a, [4, 6.8, 8, 12.56, 24.3, 64.4, 244.2, 875.9, 2206.7, 15765, 169487,586348,  1299303])
plt.yscale('log')
plt.xscale('log')
plt.title('Массив с аммортизацией')
plt.show()

plt.title('Стек на основе списка')
plt.plot([10, 100,1000, 4000, 10000, 100000, 1000000, 10000000, 100000000], [4, 22.625, 145, 574, 1130.1, 10301, 107987, 741555, 6767255])
g = [10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000]
plt.yscale('log')
plt.xscale('log')
plt.show()
plt.title('Массив постоянной длины')
plt.plot(g, [3, 3.64, 4.5, 51.1, 478.1, 3129.7, 29730, 298552 ])
plt.yscale('log')
plt.xscale('log')
plt.show()
