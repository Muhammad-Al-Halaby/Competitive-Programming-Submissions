s=input()
if s == s[::-1] and s[:((len(s)-1)//2)] == s[:((len(s)-1)//2)][::-1] and s[(len(s)+3)//2-1:] == s[(len(s)+3)//2-1:][::-1]:
    print("Yes")
else:
    print("No")