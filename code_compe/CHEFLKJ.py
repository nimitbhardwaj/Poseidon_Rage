from collections import Counter
n = raw_input()
n, q = n.split()
n = int(n)
q = int(q)
dum_lis = raw_input()
dum_lis = dum_lis.split()
lis = []
for i in range(n):
    lis.append(int(dum_lis[i]))
for i in range(q):
    vals = raw_input().split()
    if vals[0] == '1':
        lis[int(vals[1]) - 1] = int(vals[2])
    else:
        dum_lis = lis[int(vals[1]) - 1 : int(vals[2])]
        print dum_lis
        dat = Counter(dum_lis).most_common()
        if dat[0][1] > len(dum_lis) / 2:
            print 'Yes'
        else:
            print 'No'

