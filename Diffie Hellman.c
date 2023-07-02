#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
 long long int g,p,a,b,x,y,ka,kb;
 printf("Enter Prime number: ");
 scanf("%lld", &p);
 printf("Enter alpha value: ");
 scanf("%lld", &g);
 printf("Enter private key of A: ");
 scanf("%lld", &a);
 printf("Enter private key of B: ");
 scanf("%lld", &b);
 x=power(g,a,p);
 y=power(g,b,p);
 ka=power(y,a,p);
 kb=power(x,b,p);
 printf("Public Key of A: %lld\n", x);
 printf("Public Key of B: %lld\n", y);
 printf("Private Key of A: %lld\n", ka);
 printf("Private Key of B: %lld\n", kb);
}

long long int power(long long int a, long long int b, long long int p)
{
 if(b==1)
   return a;
 else
   return (((long long int)pow(a,b))%p);
}

