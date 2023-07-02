#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
int main(){
    char P[100];
    char Q[100];
    int K;
    printf("Enter the plain text: ");
    scanf("%s",P);
    printf("Enter the key: ");
    scanf("%d",&K);
    int Ps = strlen(P), i, j,S; 
    for(i = 0;i < Ps ; i++)
    {
        if(isupper(P[i]))
        {
         S=(P[i]-65+K)%26;
         S=S+65;
         printf("%c",S);
        }
        if(islower(P[i]))
        {
         S=(P[i]-91+K)%26;
         S=S+91;
         printf("%c",S);
        }
        if(isdigit(P[i]))
        {
         S=(P[i]-46+K)%10;
         S=S+46;
         printf("%c",S);
        }
    } 
    printf("\n");
}