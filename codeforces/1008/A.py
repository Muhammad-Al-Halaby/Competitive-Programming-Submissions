def isVowel(c):
    vowels = ["a", "o", "u", "i", "e"]
    return c in vowels
    
s = input()

for i in range(len(s) - 1):
    if(isVowel(s[i])): continue
    if(s[i] == 'n'): continue
    if(isVowel(s[i + 1])):   continue
    print("NO")
    quit()
    
if(not isVowel(s[-1]) and s[-1] != 'n'):
    print("NO")
    quit()
print("YES")