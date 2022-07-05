// Error in this Program 

#include<stdio.h>
#include<string.h>

int main()
{
    char frame[50][50],str[50];
    char flag[10],esc[10];
    int i,j,k=0,n;

    strcpy(flag,"flag");

    strcpy(esc,"ecs");

    strcpy(frame[k+1],"flag");

    printf("Enter the no String\n");
    scanf("%d",&n);

    printf("Enter String\n");
    for(i=0;i<=n;i++)
    {
        gets(str[i]);
    }
    printf("\nYou Entered\t");
    for(i=0;i<=n;i++)
    {
        puts(str[i]);
    }

    for(i=1;i<=n;i++)
    {
        if(strcmp(str[i],flag) != 0 && strcmp(str[i],esc) )
            strcpy(frame[k++],str[i]);
        else
        {
            strcpy(frame[k++],"esc");
            strcpy(frame[k++],str[i]);
        }
    }

    strcpy(frame[k++],"flag");
    printf("\nByte stuffing at Sender's end\n");
    for(i=0;i<k;i++)
    {
        printf("%s\t",frame[i]);
    }
}