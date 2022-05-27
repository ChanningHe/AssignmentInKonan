#LU分解

import numpy as np

#  Ax = y を解く
#  A = LUとおくと，  L(Ux) = y  Ux = bとおく  Lb = y 
#  bが解けたら，Ux = bを解く．結果，xが求まる   

n = 100	#行列のサイズ
A = np.random.rand(n, n)
y = np.random.rand(n)
#A = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 10]])
#y = np.array([3, 3, 4])

x = np.linalg.solve(A, y) #とりあえず逆行列の関数を使って解を求めた
#print(x)

#LU分解  (http://hooktail.org/computer/index.php?LU%CA%AC%B2%F2)を参考にさせてもらいました
LU = A  # LU分解する行列にAの値を代入
for j in range(n):
	for i in range(j+1, n):
		LU[i][j] = LU[i][j] / LU[j][j]
		for k in range(j+1,n):
			LU[i][k] -= LU[i][j] * LU[j][k]
print(LU)	#行列の保存形式は講義資料と同じくLとUを同じ行列に保存している
#ここまでLU分解

#念のためL と Uを確認
U = np.triu(LU)   #上三角行列を作る関数
E = np.eye(n)	  #単位行列11
L = LU - U + E
print(L@U) #きちんと作れているか確認

x = np.empty(n) #とりあえず空の行列を作る
b = np.empty(n) #同上

#LU分解した行列を使って解を計算する部分
for i in range(n):  
	b[i] = y[i]
	for j in range(i):
		b[i] -= LU[i][j] * b[j]

for i in range(n-1, -1, -1):
	x[i] = b[i]
	for j in range(n-1, i, -1):
		x[i] -= LU[i][j] * x[j]
	x[i] /= LU[i][i]
	
print(x)  #解の表示