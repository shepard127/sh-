import cs50

height = 0
print("Enter please height pyramid: ", end="")
height = cs50.get_int()

while height < 0 or height > 23:
    print("Retry: ")
    height = cs50.get_int()

for i in range(1, height + 1):
    reshotka = probel = 0
    probel = height - i
    reshotka = height - probel
    
    for j in range(probel):
        print(" ", end="")
    
    for k in range(reshotka):
        print("#", end="")
        
    print("  ", end="")
    
    for p in range(reshotka):
        print("#", end="")
        
    print()