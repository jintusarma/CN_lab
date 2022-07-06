// To calculate 0's and 1's in any no's binary equivalent form in C

#include<stdio.h>
#include<math.h>

int bin(int number)
{
    int i=0,s=0;

    while(number)
    {
        s=s+ pow(2,i)*(number%10);
        number=number/10;
        i++;
    }

    return s;
}

void count(int n)
{
    int ptr0 = 0, ptr1 = 0;
    
    int dec = bin(n);

    while(dec > 0)
    {
        if(dec & 1)
            ptr1++;
        else
            ptr0++;

        dec= dec >> 1;
    }

    printf("No. of 0s in %d is : %d \n",n,ptr0);
    printf("No. of 1s in %d is : %d \n",n,ptr1);
}

int main()
{
    int num;
    scanf("%d",&num);
    
    count(num);
}
