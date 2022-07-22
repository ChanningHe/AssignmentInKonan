import numpy as np

A1=[79,57,89,34,40,34,40,34,29,64]
A2=[47,67,17,55,50,67,77,32,85,3]
ans=[]

x1=np.array([[79,57,89,34,40,34,40,34,29,64], [47,67,17,55,50,67,77,32,85,3]])#A1,A2

x=np.cov(x1)

print(x)

x_eig = np.linalg.eig(x)
print("固有値 {} ", format(x_eig[0]))


print("固有ベクトル{}\n",format(x_eig[1]))

for i in range(1, 11):
    s=(A1[i-1]*(x_eig[1][0][0])+A2[i-1]*(x_eig[1][1][0]))
    print('学籍番号：'+str(i)+("")+str(s))
    ans.append(abs(s))

print(sorted(ans)

for j in range(1, 11):
    s=(A1[j-1]*(x_eig[1][0][1])+A2[j-1]*(x_eig[1][1][1]))
    print('学籍番号：'+str(j)+("")+str(s))
    ans.append(abs(s))

print(sorted(ans)