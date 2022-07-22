import numpy as np
import time
import scipy.sparse as sparse
import scipy.io as io
import sys


A=io.mmread ('fidapm15.mtx').tocsr() 
B=io.mmread ('fidapm15.mtx').tocsc()
C=io.mmread ('fidapm15.mtx').tolil() 

print (io.mminfo('fidapm15.mtx'))

D=B.todense() 
print(sys.getsizeof (A))
print(sys.getsizeof (B))
print (sys.getsizeof (C))
print (sys.getsizeof (D))

start=time.time () 
X=A@A
elapsed_time=time.time()-start 
print ("Aの時間:")
print ('crcsparsematrix',elapsed_time)

start=time,time() 
X=В@В
elapsed_time=time. time()-start 
print ("Bの時間:")
print ('crcsparsematrix' , elapsed_time)

start=time,time() 
X=C@C
elapsed_time=time. time()-start 
print ("cの時間:")
print ('Icrcsparsematrix', elapsed_time)

start=time,time () 
X=D@D
elapsed_time=time.time()-start 
print ("Dの時間:")
print ('crcsparsematrix' , elapsed_time)