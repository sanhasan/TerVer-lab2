import numpy as np
import matplotlib.pyplot as plt

N = 100000

np.random.seed(2026)

U = np.random.uniform(0, 1, N)
V = np.random.uniform(0, 1, N)

X = np.sqrt(-2 * np.log(V)) * np.cos(2 * np.pi * U)
Y = np.sqrt(-2 * np.log(V)) * np.sin(2 * np.pi * U)

fig, axes = plt.subplots(1, 2, figsize=(12, 5))

ax = axes[0]

ax.hist(X, bins=50, density=True, color='blue')

ax.set_title('X')
ax.grid(alpha=0.3)

ax = axes[1]

ax.hist(Y, bins=50, density=True, color='red')

ax.set_title('Y')
ax.grid(alpha=0.3)

plt.tight_layout()

plt.savefig("graphic", dpi=150)

plt.show()