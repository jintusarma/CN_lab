#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    char a[20];
    int count=0, i=0, j, l, k=0;
    // printf("Enter size: ");
    // scanf("%d", &l);
    printf("Enter the input string: ");
    scanf("%s", a);

    l = strlen(a);
    for(i=0; i < l; i++)
    if(a[i] == '1')
    {
        k = i;
        count = 0;
        while(a[k] == '1')
        {
            count += 1;
            k++;
            if(count == 5)
            {
                for(j = l + 1; j > k; j--)
                {
                    a[j] = a[j - 1];
                }
                a[k] = '0';
                l++;
                break;
            }
            i = k;
        }
    }
    printf("\n The bitstuffed string is %s", a);
    //getch();
}
