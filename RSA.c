#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findGCD(int n1, int n2) 
{
	int i, gcd;
	for(i = 1; i <= n1 && i <= n2; ++i) 
 {
		if(n1 % i == 0 && n2 % i == 0)
			gcd = i;
	}
	return gcd;
}

int powMod(int a, int b, int n)
{
 if (b==0) 
   return a;
 else
   return (((int)pow(a,b))%n);
}

int main() 
{
	int p,q;
	int n,phin;
	int data, cipher, decrypt;
	printf("Enter any two prime numbers: ");
	scanf("%d %d", &p, &q);
	n = p * q;
	phin = (p - 1) * (q - 1);

	int e = 0;
	for (e = 5; e <= 100; e++) 
 {
		if (findGCD(phin, e) == 1)
			break;
	}
	
	int d = 0;
	for (d = e + 1; d <= 100; d++) 
 {
		if ( ((d * e) % phin) == 1)
			break;
	}

	printf("Value of e: %d\nValue of d: %d\n", e, d);
	printf("Enter some numerical data: ");
	scanf("%d", &data);
	cipher = powMod(data, e, n);
	printf("The cipher text is: %d\n", cipher);
	decrypt = powMod(cipher, d, n);
	printf("The decrypted text is: %d\n", decrypt);
	return 0;
}