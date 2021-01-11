n = input()
a = list(map(int, input().split()))
d = {}
mx = 0
ans = -1
for x in a:
    d[x] = d.get(x, 0) + 1
    if(d[x] > mx):
        mx = d[x]
        ans = x
print(ans)