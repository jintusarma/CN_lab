#include<stdio.h>
#include<string.h>

void main(){  

 char frame[50][50],str[50][50];

 char flag[4];
 strcpy(flag,"flag");

 char esc[4];
 strcpy(esc,"esc");

 int i,j,k=0,n;
 strcpy(frame[k++],"flag");

 printf("Enter no. of strings in the data: ");
 scanf("%d",&n);

 printf("Enter Strings: \n");
 for(i=0;i<=n;i++)
   {
  gets(str[i]);
   }

 printf("You entered :\n");
 for(i=0;i<=n;i++)
  {
  puts(str[i]);
  }

 printf("\n");
 for(i=0;i<=n;i++)
   {
      if(strcmp(str[i],flag)!=0 && strcmp(str[i],esc)!=0)
            {
                   strcpy(frame[k++],str[i]);
            }
      else
         {
            strcpy(frame[k++],"esc");
            strcpy(frame[k++],str[i]);
         }
   }
 strcpy(frame[k++],"flag");
//frame[k++]='\0';

printf("Byte stuffing at sender side:\n\n");

for(i=0;i<k;i++)
  {
    printf("%s ",frame[i]);
  }
}