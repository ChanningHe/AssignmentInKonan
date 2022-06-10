#k課題１：コレスキー分解 >　QR分解　> 固有値分解　>　LU分解 > 特異値分解


import numpy as np
A = np.array([
    [1,1,-1],
    [1,1,-1],
    [-1,-1,1]
])
trA= A.T

print(trA)
a_eig = np.linalg.eig(A*trA)
print(a_eig)