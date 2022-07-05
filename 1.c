#include<stdio.h>
#include<string.h>

int main()
{
    int a,i,j,k,cnt;
    char str[100];
    printf("Enter the bit");
    gets(str);
    for(i=0;i<strlen(str);i++)
    {
        cnt =0;
        for(j=i;j<=(i+5);j++)
        {
            if(str[j]=='1')
                cnt++;
        }
        if(cnt == 6)
        {
            a = strlen(str)+2;
            for(k=a;k>=(i+5);k--)
            {
                str[k] = str[k-1];
            }
        }
        str[i+5] = '0';
        i = i+5;
    }
    puts(str);
}