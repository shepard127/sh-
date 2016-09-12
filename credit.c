#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main()
{
    long long int k;
    
    printf("Number: ");
    
    k = get_long_long();
    
    int result1 = 0;
    int result2 = 0;
    
    int buff = 0;
    
    bool flag = true;
    bool validity = true;
    
    char buffChar[2] = {'0', '0'};
    
    int amount = 0;
    
    while (k != 0)
    {
        if (flag)
        {
            result1 += k%10;
            
            buffChar[1] = buffChar[0];
            buffChar[0] = k%10;
            
            k/=10;
            flag = false;
        }
        else
        {
            buffChar[1] = buffChar[0];
            buffChar[0] = k%10;
            
            buff = (k%10) * 2;
            
            while (buff != 0)
            {
                result2 += buff%10;
                buff /= 10;
            }
            
            k/=10;
            
            flag = true;
        }
        amount++;
    }
    
    if ((result1 + result2)%10 != 0)
    {
        validity = false;
    }

    
    if (validity == false)
    {
        printf("INVALID\n");
    }
    else
    {
        switch(buffChar[0])
        {
            case 3: 
            {
                if ((buffChar[1] == 4 || buffChar[1] == 7) && amount == 15)
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            break;
            case 5:
            {
                if (amount == 16)
                {
                    switch(buffChar[1])
                    {
                        case 1: printf("MASTERCARD\n"); break;
                        case 2: printf("MASTERCARD\n"); break;
                        case 3: printf("MASTERCARD\n"); break;
                        case 4: printf("MASTERCARD\n"); break;
                        case 5: printf("MASTERCARD\n"); break;
                        default: printf("INVALID\n");
                    }
                }
                else
                {
                    printf("INVALID\n");
                }
            }break;
            case 4:
            {
                if (amount == 13 || amount == 16)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            } break;
            default: printf("INVALID\n");
        }
    }
    
    
    
    return 0;
}
