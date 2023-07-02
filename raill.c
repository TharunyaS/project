#include<stdio.h>
#include<string.h>

void encrypt(char msg[], key);
void decrypt(char cip[], key);
int main()
{
    char msg[100],cip[100];
    int key;
    printf("Enter plaintext: ");
    scanf("%s", msg);
    printf("Enter key: ");
    scanf("%d", &key);
    encrypt(msg,key);
    printf("Enter Ciphertext: ");
    scanf("%s", cip);
    decrypt(cip,key);
}

void encrypt(char msg[], int key)
{
 int i,j,r=0,c=0,k=-1;
 int mlen=strlen(msg);
 char en[key][mlen];
 for(i=0; i<key; i++)
   for(j=0; j<mlen; j++)
      en[i][j]='\n';
  
 for(i=0; i<mlen; i++)
 {
   en[r][c++]=msg[i];
   if(r==0||r==key-1)
      k=k*-1;
   r=r+k;
 }
 
 printf("Encryption: ");
 for(r=0; r<key; r++)
   for(c=0; c<mlen; c++)
     if(en[r][c]!='\n')
       printf("%c",en[r][c]);
 printf("\n");
}

void decrypt(char cip[], int key)
{
 int i,j,r=0,c=0,k=-1,m=0;
 int clen=strlen(cip);
 char de[key][clen];
 for(i=0; i<key; i++)
   for(j=0; j<clen; j++)
      de[i][j]='\n';
    
 for(i=0; i<clen; i++)
 {
   de[r][c++]='*';
   if(r==0||r==key-1)
      k=k*-1;
   r=r+k;
 }
 
 for(r=0; r<key; r++)
   for(c=0; c<clen; c++)
     if(de[r][c]=='*')
       de[r][c]=cip[m++];
 r=0,c=0,k=-1;
    
 printf("Decryption: ");
 for(i=0; i<clen; i++)
 {
   printf("%c",de[r][c++]);
   if(r==0||r==key-1)
      k=k*-1;
   r=r+k;
 }
 printf("\n");
}