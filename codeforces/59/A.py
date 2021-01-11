s = input()
up = len([c for c in s if c.isupper()])
low = len(s) - up
if(up > low):   s = s.upper();
else: s = s.lower();
print(s)