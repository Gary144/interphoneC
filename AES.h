#ifndef _AES_H
#define _AES_H

#define RoundKeyLEN  300


void AES_Encrypt(char* pExpressText , char* pCipherText , char* pAeskey);
void AES_Decrypt(char* pExpressText , char* pCipherText , char* pAeskey);


char *encrypt(char *str, char *key);
char *decrypt(char *str, char *key , int len) ;


#endif
