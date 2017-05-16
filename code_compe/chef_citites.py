def fun(B, R, N):
    i = 0
    pro =1
    P =[]
    while i*R < N:
        pro = pro * B[i * R]
        i = i + 1
    ret = pro % 1000000007
    while pro >=10:
        pro = pro // 10
    P.append(pro)
    P.append(ret)
    return P

t = raw_input()
t = int(t)
A = raw_input()
A = A.split()
B=[]
for a in A:
    a = int(a)
    B.append(a)
q = raw_input()
q = int(q)
for i in range(1, q + 1):
    A = raw_input()
    A = A.split()
    if int(A[0]) ==1:
        p = int(A[1])
        f = int(A[2])
        B[p -1] = f
        A = []

    elif int(A[0]) == 2:
        R = int(A[1])
        P = fun(B, R, t)
        print "%d %d" % (int(P[0]), int(P[1]))
        A=[]
