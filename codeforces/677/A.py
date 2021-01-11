n, h = map(int, input().split())
a = list(map(int, input().split()))
l = len([x for x in a if x <= h]);
print(l + 2 * (n - l))