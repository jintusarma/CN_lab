#include<stdio.h>
#include<string.h>

int main()
{
    int i=0,count=0;
    char databits[7];
    printf("Enter Data Bits : \n");
    scanf("%s",databits);

    printf("Databits before adding parity bit\t %s",databits);
    // printf("\nData Bits After adding parity bit : \n");

    for ( i = 0; i < strlen(databits); i++)
    {
        if(databits[i] == '1')
            count++;
    }
    
    if(count % 2 == 0)
        databits[7]='1';
    else
        databits[7]='0';

    printf("\nData Bits After adding parity bit :\t%s",databits);
}