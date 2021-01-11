n = int(input())

names = []
points = []
d = {}

for i in range(n):
    a = input().split()
    s = a[0]
    p = int(a[1])
    
    names.append(s)
    points.append(p)
    
    d[s] = d.get(s, 0) + p

mx = max(d.values())

winners = [k for k in d.keys() if d[k] == mx] 

d = {}
for i in range(n):
    d[names[i]] = d.get(names[i], 0) + points[i]
    if(names[i] in winners and d.get(names[i], 0) >= mx):
        print(names[i])
        quit()