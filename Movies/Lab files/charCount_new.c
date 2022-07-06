//Correct code

#include<stdio.h>
#include<string.h>

int main(){

    char data[30], dstuff[30];
    int temp, j=0, x=0;
    printf("Enter data: ");
    scanf("%s", data);
    int d_len= strlen(data);
 
    for(int i=0; i<d_len; i++){

        temp = data[i] - '0';           

        if (temp<49)                    // if data[i] == 'a', then temp = 'a' - '0' = 49
        {
            printf("\nTemp: %d\n", temp);
        }
        
        else
        {
            dstuff[x] = temp + '0';         
            x++;
        }

    }

    dstuff[x] = '\0';
    
    printf("\nDestuffed data:");
    for(int i=0;dstuff[i]!='\0'; i++){
        printf("%c",dstuff[i]);
    }

    int z = 'a' - '0';
    printf("\n z = %d ", z);
}