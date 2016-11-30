s = input()
k = int(s)

result1 = result2 = buff = amount = 0

flag = validity = True

buffChar = [0, 0]

while k != 0:
    if flag == True:
        result1 += k%10
        result1 = int(result1)
        buffChar[1] = buffChar[0]
        buffChar[0] = k%10
        k/=10
        flag = False
        k = int(k)
    else:
        buffChar[1] = buffChar[0]
        buffChar[0] = k%10
        buff = (k%10)*2
        while buff != 0:
            result2 += int(buff%10)
            buff /= 10
        
        k/=10
        k = int(k)
        flag = True
    amount += 1
if (result1 + result2)%10 != 0:
    validity = False
if validity == False:
    print("INVALID")
    
else:
    if buffChar[0] == 3:
        if buffChar[1] == 4 or buffChar[1] == 7 and amount == 15:
            print("AMEX")
        else:
            print("INVALID")
   
    elif buffChar[0] == 5:
        if amount == 16:
            if buffChar[1]:
                print("MASTERCARD")
            elif buffChar[2]:
                print("MASTERCARD")
            elif buffChar[3]:
                print("MASTERCARD")
            elif buffChar[4]:
                print("MASTERCARD")
            elif buffChar[5]:
                print("MASTERCARD")
            else:
                print("INVALID")
        else:
            print("INVALID")
    elif buffChar[0] == 4:
        if amount == 13 or amount == 16:
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")