x = input()
s = sum(list(map(int, x)))
c = 0
ans = []
i = len(x) - 1
while True:
    c += s
    ans.append(c % 10)
    c //= 10
    if i >= 0:
        s -= int(x[i])
    if i <= 0 and c == 0:
        break
    i -= 1
ans.reverse()
print(''.join(map(str, ans)))