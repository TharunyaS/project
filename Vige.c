#include<stdio.h>
#include<string.h>


int main()
{
    int i,j;
    char msg[100],key[100];
    printf("Enter Plaintext: ");
    scanf("%s", msg);
    printf("Enter key: ");
    scanf("%s", key);
    int mlen=strlen(msg), klen=strlen(key);
    char nkey[mlen],emsg[mlen],dmsg[mlen];
    for(i=0;i<mlen;++i)
    {
     if(j==klen)
       j=0;
    
     nkey[i]=key[j];
     ++j;
    }
    nkey[i]='\0';
    for(i=0;i<mlen;i++)
    {
     emsg[i]=((msg[i]+nkey[i])%26) + 'A';
    }
    emsg[i]='\0';
    for(i=0;i<mlen;i++)
    {
     dmsg[i]=(((emsg[i]-nkey[i])+26)%26) + 'A';
    }
    dmsg[i]='\0';
    printf("key: %s\n", nkey);
    printf("Ciphertext: %s\n", emsg);
    printf("Plaintext: %s\n", dmsg);
}