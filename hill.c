#include<stdio.h>
#include<math.h> 

float en[3][1], de[3][1], a[3][3], b[3][3], c[3][3], msg[3][1];
void encrypt();
void decrypt();
void inve();

int main()
{
 int i,j;
 char mes[3];
 printf("Enter key:\n");
 for(i=0;i<3;i++)
  for(j=0;j<3;j++)
    scanf("%f", &a[i][j]);
    c[i][j]=a[i][j];
 printf("Enter message: ");
 scanf("%s", mes);
 for(i=0;i<3;i++)
   msg[i][0]=mes[i]-97;
 encrypt();
 decrypt();
}

void encrypt()
{
 int i,j,k;
 for(i=0;i<3;i++)
  for(j=0;j<1;j++)
   for(k=0;k<3;k++)
    en[i][j]=en[i][j]+a[i][k]*msg[k][j];
 printf("The Encryption: ");
 for(i=0;i<3;i++)
   printf("%c", (char)(fmod(en[i][0],26)+97));
}

void decrypt()
{
 int i,j,k;
 inve();
 for(i=0;i<3;i++)
  for(j=0;j<1;j++)
   for(k=0;k<3;k++)
    de[i][j]=de[i][j]-b[i][k]*en[k][j];
 printf("\nDecryption: ");
 for(i=0;i<3;i++)
  printf("%c", (char)(fmod(de[i][0],26)+97));
}

void inve()
{
 printf("\nInverse: \n");
 int i,j,k;
 float p,q;
 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  { if(i==j)
    b[i][j]=1;
   else
    b[i][j]=0;
  }
 }
 for(k=0;k<3;k++)
 {
  for(i=0;i<3;i++)
  {
   p=c[i][k];
   q=c[k][k];
   for(j=0;j<3;j++)
   {
    if(i!=k)
    {
     c[i][j]=c[i][j]*q-p*c[k][j];
     b[i][j]=b[i][j]*q-p*b[k][j];
    }
   }
  }
 }
 for(i=0;i<3;i++)
  for(j=0;j<3;j++)
    b[i][j]=b[i][j]/c[i][j];
 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  {
   printf("%d",b[i][j]);
  }
  printf("\n");
 }
}