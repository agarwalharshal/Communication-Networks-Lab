#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>

void sender(int data[100], int n)
{
    int sum = 0, checksum;
    for(int i = 0; i < n; i++)
    {
        sum+=data[i];
    }
    printf("\n Sum is: %d", sum);
    checksum = ~sum;
    printf("\n Checksum at Sender's side is: %d", checksum);
}
void receiver(int data[100], int n, int checksum)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    sum+=data[i];
    int errorDetection = ~(sum + checksum);
    printf("\n Error Detected is: %d", errorDetection);
    if(errorDetection == 0)
    printf("\n Message Accepted with no errors");
    else
    printf("\n Message Rejected");
}

int main()
{
    int arr[100], length = 0;
    char bitString[100], bitStuffedString[110];
    char choice;
    int count, j;
    char str[100];
    printf("\n Enter a choice:\n a) Sender Checksum\n b) Receiver Checksum\n c) Sender Bit Stuffing\n d) Receiver Bit Stuffing\n e) Sender Character Count\n f) Receiver Character Count\n");
    scanf("%c", &choice);
    switch(choice)
    {
        case 'a':   length = 0;
                    printf("\nEnter the number of elements in the array: ");
                    scanf("%d", &length);
                    printf("\nEnter the elements of the array: \n");
                    for(int i = 0; i < length; i++)
                    scanf("%d", &arr[i]);
                    sender(arr, length);
                    break;
                    
        case 'b':   int checksum;
                    length = 0;
                    printf("\nEnter the number of elements in the array: ");
                    scanf("%d", &length);
                    printf("\nEnter the elements of the array: \n");
                    for(int i = 0; i < length; i++)
                    scanf("%d", &arr[i]);
                    printf("\nEnter the checksum value: ");
                    scanf("%d", &checksum);
                    receiver(arr, length, checksum);
                    break;
                    
        case 'c':   
                    printf("\n Enter the bit string to be stuffed: \n");
                    scanf("%s", bitString);
                    count = 0, j = 0;
                    int i;
                    for(i = 0; bitString[i] != '\0'; i++)
                    {
                        if(bitString[i]=='1')
                        count++;
                        else
                        count = 0;
                        bitStuffedString[i+j] = bitString[i];
                        if(count == 5)
                        {
                            j++;
                            bitStuffedString[i+j] = '0';
                            count = 0;
                        }
                    }
                    bitStuffedString[i+j] = '\0';
                    printf("\n Resultant Bit Stuffed String is: %s", bitStuffedString);
                    break;
                    
        case 'd':   
                    printf("\n Enter the bit stuffed string: \n");
                    scanf("%s", bitStuffedString);
                    count = 0, j = 0;
                    for(int i = 0; bitStuffedString[i] != '\0'; i++)
                    {
                        if(bitStuffedString[i]=='1')
                        count++;
                        else
                        count = 0;
                        bitString[i-j] = bitStuffedString[i];
                        if(count == 5)
                        {
                            j++;
                            i++;
                            count = 0;
                        }
                    }
                    bitString[i-j] = '\0';
                    printf("\n Resultant Bit String is: %s", bitString);
                    break;
                    
        case 'e':   
                    printf("\n Enter the message to be transmitted: \n");
                    scanf("%s", str);
                    printf("\n Resultant data for transmission using character count is: %ld%s", strlen(str)+1, str);
                    break;
                    
        case 'f':   char data[100];
                    int x = 0, y = 0;
                    printf("\n Enter the received data: \n");
                    scanf("%s", str);
                    for(int i = 0; i < strlen(str); i++)
                    {
                        int j = ((int)str[i])-48;
                        x++;
                        i++;
                        while(i<j+y)
                        {
                            data[i-x] = str[i];
                            i++;
                        }
                        i--;
                        y = i+1;
                    }
                    printf("\n Data string is: %s", data);
                    break;
                    
        default:    printf("\n Please enter a valid choice");
    }
    getch();
}
