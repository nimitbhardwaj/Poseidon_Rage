a = int(raw_input())
for i in range(0, a):
    t = 0
    val = raw_input()
    valarry = val.split()
    n, k, m = valarry
    n = int(n)
    k = int(k)
    m = int(m)
    if n >= m:
        print 0
    else:
        while n <= m:
            n *= k
            t += 1
        print t - 1
