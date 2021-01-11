n = int(input())
a = []
for i in range(n):
    a.append(input())
a.reverse()

delSet = set()
for s in a:
    if(s in delSet): continue
    delSet.add(s)
    print(s)