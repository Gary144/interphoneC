#ifndef __vs1003_H
#define __vs1003_H

/*
  5V 
	GND 
	RST    PB0 
	MISO   PB1 
	MOSI   PB2 
	SCLK   PB10
	DREQ   PB11
	XCS    PA7
	XDCS   PA6
*/
#include "myfun.h"


#define uchar unsigned char 
#define uint unsigned int



//vs1003相关宏定义 
#define VS_WRITE_COMMAND 0x02
#define VS_READ_COMMAND 0x03
#define SPI_MODE        0x0   
#define SPI_STATUS      0x1   
#define SPI_BASS        0x2   
#define SPI_CLOCKF      0x3   
#define SPI_DECODE_TIME 0x4   
#define SPI_AUDATA      0x5   
#define SPI_WRAM        0x6   
#define SPI_WRAMADDR    0x7   
#define SPI_HDAT0       0x8   
#define SPI_HDAT1       0x9   
#define SPI_AIADDR      0xa   
#define SPI_VOL         0xb   
#define SPI_AICTRL0     0xc   
#define SPI_AICTRL1     0xd   
#define SPI_AICTRL2     0xe   
#define SPI_AICTRL3     0xf   
#define SM_DIFF         0x01   
#define SM_JUMP         0x02   
#define SM_RESET        0x04   
#define SM_OUTOFWAV     0x08   
#define SM_PDOWN        0x10   
#define SM_TESTS        0x20   
#define SM_STREAM       0x40   
#define SM_PLUSV        0x80   
#define SM_DACT         0x100   
#define SM_SDIORD       0x200   
#define SM_SDISHARE     0x400   
#define SM_SDINEW       0x800   
#define SM_ADPCM        0x1000   
#define SM_ADPCM_HP     0x2000 



#define Vs1003_RST_0  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET)
#define Vs1003_RST_1  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET)

#define Vs1003_MISO_0  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET)
#define Vs1003_MISO_1  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET)
#define Vs1003_MOSI_0  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET)
#define Vs1003_MOSI_1  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET)
#define Vs1003_SCLK_0  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET)
#define Vs1003_SCLK_1  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET)

#define Vs1003_DREQ_0  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET)
#define Vs1003_DREQ_1  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET)
#define Vs1003_XCS_0  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET)
#define Vs1003_XCS_1  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET)
#define Vs1003_XDCS_0  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET)
#define Vs1003_XDCS_1  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET)

#define Vs1003_DREQ_Read  HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11)
#define Vs1003_MISO_Read  HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1)

#define Mp3PutInReset()  { Vs1003_RST_0 ; }
#define Mp3ReleaseFromReset()  { Vs1003_RST_1; }

#define Mp3SelectControl()  { Vs1003_XCS_0 ; }
#define Mp3DeselectControl()  { Vs1003_XCS_1 ; }
 
#define Mp3SelectData()		{ Vs1003_XDCS_0; }
#define Mp3DeselectData()	{ Vs1003_XDCS_1; }


#define Macro_Set_SI_High()  	Vs1003_MOSI_1
#define Macro_Set_SI_Low()  	Vs1003_MOSI_0
#define Macro_Set_CLK_High()  Vs1003_SCLK_1
#define Macro_Set_CLK_Low()  	Vs1003_SCLK_0





void flush_buffer();
void vs1003_sendmusicdat(unsigned char dat); 
void ceshi(uint8_t x);
void vs1003init(void);
unsigned int vs1003read(unsigned char addr);
unsigned char vs1003_spi_readbyte();
void vs1003_wr_command(unsigned char addr,unsigned char hdat,unsigned char ldat );
void vs1003_spi_write(uchar ucSendData);
void delay_us(uint32_t us);


//extern unsigned char record[];



#endif
