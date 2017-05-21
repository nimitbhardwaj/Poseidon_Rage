def dp(v,a,b,d):
    if a >= len(v) or b >= len(v[a]):
        return 0
    if d[a][b] != 0:
        return d[a][b]
    d[a][b]=int(v[a][b])+max(dp(v,a+1,b,d),dp(v,a+1,b+1,d))
    return d[a][b]
t = int(raw_input())
for k in range(t):
    n = int(raw_input())
    v=[]
    d=[[0 for a in range(n)]for b in range(n)]
    for i in range(n):
        a = raw_input()
        a = a.split()
        v.append(a)
    print dp(v,0,0,d)

