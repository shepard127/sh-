import sys
import cs50

module = 0

if len(sys.argv) != 2:
    print("error")
    exit(0)
    
else:
    KEY = (sys.argv[1])
    for i in range(len(KEY)):
        if not KEY[i].isalpha():
            print("the error that is introduced")
            exit(1)
            
print("plaintext: ", end="")
text = cs50.get_string()

SIZE = 26
print("ciphertext: ", end="")

for i in range(len(text)):
    
    keyIndex = module % len(KEY)
    
    if  text[i].isalpha:
        if text[i].isupper() and KEY[keyIndex].isupper():
            tmp = ((ord(text[i]) - ord('A')) + (ord(KEY[keyIndex]) - ord('A') )) % 26 + ord('A')
            print(chr(tmp), end='')
            module +=1 
        

        elif text[i].isupper() and KEY[keyIndex].islower():
            tmp = ((ord(text[i]) - ord('A')) + (ord(KEY[keyIndex]) - ord('a') )) % 26 + ord('A')
            print(chr(tmp), end='')
            module +=1 
        
        elif text[i].islower() and KEY[keyIndex].isupper():
            tmp = ((ord(text[i]) - ord('a')) + (ord(KEY[keyIndex]) - ord('A') )) % 26 + ord('a')
            print(chr(tmp), end='')
            module +=1 
        
        elif text[i].islower() and KEY[keyIndex].islower():
            tmp = ((ord(text[i]) - ord('a')) + (ord(KEY[keyIndex]) - ord('a') )) % 26 + ord('a')
            print(chr(tmp), end='')
            module +=1 
        else:
            print(text[i], sep='', end='')
print()