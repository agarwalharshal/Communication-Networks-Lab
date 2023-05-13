#include <stdio.h>
#include <conio.h> //console input/output
#include <math.h>
#include <string.h>

int i,j;

void sender(int b[100],int k) //b is not a bit string but an array of integers where each integer works as a frame/subunit
{
    int checksum,sum=0;
    printf("\n****SENDER****\n");
    for(i=0;i<k;i++)
        sum+=b[i];
    printf("SUM IS: %d",sum);
    checksum=~sum; //checksum = 1's complement of sum
    printf("\nSENDER's CHECKSUM IS:%d",checksum);
    int errorDetection = ~(checksum+sum); //errorDetection = 1's complement of (checksum+sum)
    printf("\nERROR DETECTION:%d",errorDetection);
    if(errorDetection==0)
        printf("\n\nACCEPTED");
    else
        printf("\n\nREJECTED");
}

int main()
{
    char str[100], bstr[100];
    int a[100],m,scheck;
    char choice;
    printf("\n.....YOUR OPTIONS....\n");
    printf("\na. Checksum\nb. Bit stuffing\nc. Character count\n");
    printf("\nEnter your choice:");
    scanf("%c",&choice);
    switch(choice)
    {
        //Checksum Calculation
            //m = 2
            //10101001  --> a[0]=169
            //00111001  --> a[1]=57
            //11100010  --> sum
            //00011101  --> checksum (1's complement of sum)
            //Data transmitted to Receiver is – 10101001 00111001 00011101
            //10101001  --> a[0]=169
            //00111001  --> a[1]=57
            //00011101  --> checksum
            //11111111  --> sumNew = sum+checksum   sum=a[0]+a[1]
            //00000000  --> errorDetection = 1's complement of sumNew   errorDetection=0 => no error
        case 'a':
        {
            printf("\nENTER SIZE OF THE STRING:");
            scanf("%d",&m);
            printf("\nENTER THE ELEMENTS OF THE ARRAY:");
            for(i=0;i<m;i++)
            scanf("%d",&a[i]);
            sender(a,m);
        }
        break;
           
        //Bit stuffing
            //110101111101011111101011111110    --> before bit stuffing
            //110101111100101111101010111110110 --> after bit stuffing
        case 'b':
        {
            int count=0;
            printf("Enter the bit string: ");
            scanf("%s",str);
            for(i=j=0; str[i]!='\0'; i++)
            {
                if(str[i]=='1')
                count++;
                else
                count=0;

                bstr[i+j]=str[i];
                if(count==5)
                {
                    j++;
                    bstr[i+j]='0';
                    count=0;
                }
            }
            bstr[i+j]='\0';
            printf("\nAfter Bit stuffing :  %s\n", bstr);
        }
        break;
           
        //Inserting character count code
            //"hello"   --> arr[]
            //strlen(arr)+1   --> 5+1 = 6
            //header = 6
            //transmitted frame = 6hello (6 characters in the frame including the header character)
        case 'c':
        {
            char arr[100]; int x,y;
            printf("\nENTER THE ELEMENTS OF THE ARRAY:");
            scanf("%s",arr);
            printf("\n Resultant Frame using character count = %d%s\n",strlen(arr)+1,arr);
        }
        break;
        default:
        printf("\nYou entered an invalid choice run program again");
    }
getch();
}
