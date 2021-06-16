#ifndef __LCDFONT_H
#define __LCDFONT_H 	   





typedef struct 
{
	unsigned char Index[2];	
	unsigned char Msk[24];
}typFNT_GB12; 

typedef struct 
{
	unsigned char Index[2];	
	unsigned char Msk[32];
}typFNT_GB16; 

typedef struct 
{
	unsigned char Index[2];	
	unsigned char Msk[72];
}typFNT_GB24; 
typedef struct 
{
	unsigned char Index[2];	
	unsigned char Msk[128];
}typFNT_GB32; 




extern const unsigned char ascii_1206[][12];
extern const unsigned char ascii_1608[][16];
extern const unsigned char ascii_2412[][48];
extern const unsigned char ascii_3216[][64];
extern const typFNT_GB12 tfont12[];

extern const typFNT_GB16 tfont16[];
extern const typFNT_GB24 tfont24[];
extern const typFNT_GB32 tfont32[];










#endif


