#ifndef __LCD_INIT_H
#define __LCD_INIT_H


#include "main.h"


//�����߶ȺͿ��
#define LCD_W 160
#define LCD_H 80

#define u8 unsigned char  
#define u16 unsigned int 
#define u32 unsigned long 


 

#define Lcd_Scl_Gpio    GPIOA
#define Lcd_Scl_GpioPin GPIO_PIN_5

#define Lcd_Sda_Gpio    GPIOA
#define Lcd_Sda_GpioPin GPIO_PIN_4

#define Lcd_Res_Gpio    GPIOA
#define Lcd_Res_GpioPin GPIO_PIN_3

#define Lcd_Dc_Gpio     GPIOA
#define Lcd_Dc_GpioPin  GPIO_PIN_2

#define Lcd_Cs_Gpio     GPIOA
#define Lcd_Cs_GpioPin  GPIO_PIN_1

#define Lcd_Blk_Gpio    GPIOA
#define Lcd_Blk_GpioPin GPIO_PIN_0





//-----------------IPS��Ļ�Ķ˿ڶ���---------------- 
#define LCD_SCLK_Clr()  HAL_GPIO_WritePin(Lcd_Scl_Gpio,Lcd_Scl_GpioPin,GPIO_PIN_RESET)//SCL=SCLK
#define LCD_SCLK_Set()  HAL_GPIO_WritePin(Lcd_Scl_Gpio,Lcd_Scl_GpioPin,GPIO_PIN_SET)

#define LCD_MOSI_Clr() HAL_GPIO_WritePin(Lcd_Sda_Gpio,Lcd_Sda_GpioPin,GPIO_PIN_RESET)//SDA=MOSI
#define LCD_MOSI_Set() HAL_GPIO_WritePin(Lcd_Sda_Gpio,Lcd_Sda_GpioPin,GPIO_PIN_SET)

#define LCD_RES_Clr()  HAL_GPIO_WritePin(Lcd_Res_Gpio,Lcd_Res_GpioPin,GPIO_PIN_RESET)//RES
#define LCD_RES_Set()  HAL_GPIO_WritePin(Lcd_Res_Gpio,Lcd_Res_GpioPin,GPIO_PIN_SET)

#define LCD_DC_Clr()   HAL_GPIO_WritePin(Lcd_Dc_Gpio,Lcd_Dc_GpioPin,GPIO_PIN_RESET)//DC
#define LCD_DC_Set()   HAL_GPIO_WritePin(Lcd_Dc_Gpio,Lcd_Dc_GpioPin,GPIO_PIN_SET)
 		     
#define LCD_CS_Clr()   HAL_GPIO_WritePin(Lcd_Cs_Gpio,Lcd_Cs_GpioPin,GPIO_PIN_RESET)//CS
#define LCD_CS_Set()   HAL_GPIO_WritePin(Lcd_Cs_Gpio,Lcd_Cs_GpioPin,GPIO_PIN_SET)

#define LCD_BLK_Clr()  HAL_GPIO_WritePin(Lcd_Blk_Gpio,Lcd_Blk_GpioPin,GPIO_PIN_RESET)//BLK
#define LCD_BLK_Set()  HAL_GPIO_WritePin(Lcd_Blk_Gpio,Lcd_Blk_GpioPin,GPIO_PIN_SET)




void Ips096_GPIO_Init(void);//��ʼ��GPIO
void LCD_Writ_Bus(u8 dat);//ģ��SPIʱ��
void LCD_WR_DATA8(u8 dat);//д��һ���ֽ�
void LCD_WR_DATA(u16 dat);//д�������ֽ�
void LCD_WR_REG(u8 dat);//д��һ��ָ��
void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2);//�������꺯��
void LCD_Init(void);//LCD��ʼ��




void LCD_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color);//ָ�����������ɫ
void LCD_DrawPoint(u16 x,u16 y,u16 color);//��ָ��λ�û�һ����
void LCD_DrawLine(u16 x1,u16 y1,u16 x2,u16 y2,u16 color);//��ָ��λ�û�һ����
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2,u16 color);//��ָ��λ�û�һ������
void Draw_Circle(u16 x0,u16 y0,u8 r,u16 color);//��ָ��λ�û�һ��Բ

void LCD_ShowChinese(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//��ʾ���ִ�
void LCD_ShowChinese12x12(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//��ʾ����12x12����
void LCD_ShowChinese16x16(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//��ʾ����16x16����
void LCD_ShowChinese24x24(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//��ʾ����24x24����
void LCD_ShowChinese32x32(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//��ʾ����32x32����

void LCD_ShowChar(u16 x,u16 y,u8 num,u16 fc,u16 bc,u8 sizey,u8 mode);//��ʾһ���ַ�
void LCD_ShowString(u16 x,u16 y,const u8 *p,u16 fc,u16 bc,u8 sizey,u8 mode);//��ʾ�ַ���
u32 mypow(u8 m,u8 n);//����
void LCD_ShowIntNum(u16 x,u16 y,u16 num,u8 len,u16 fc,u16 bc,u8 sizey);//��ʾ��������
void LCD_ShowFloatNum1(u16 x,u16 y,float num,u8 len,u16 fc,u16 bc,u8 sizey);//��ʾ��λС������

void LCD_ShowPicture(u16 x,u16 y,u16 length,u16 width,const u8 pic[]);//��ʾͼƬ


//������ɫ
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE           	 0x001F  
#define BRED             0XF81F
#define GRED 			       0XFFE0
#define GBLUE			       0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			     0XBC40 //��ɫ
#define BRRED 			     0XFC07 //�غ�ɫ
#define GRAY  			     0X8430 //��ɫ
#define DARKBLUE      	 0X01CF	//����ɫ
#define LIGHTBLUE      	 0X7D7C	//ǳ��ɫ  
#define GRAYBLUE       	 0X5458 //����ɫ
#define LIGHTGREEN     	 0X841F //ǳ��ɫ
#define LGRAY 			     0XC618 //ǳ��ɫ(PANNEL),���屳��ɫ
#define LGRAYBLUE        0XA651 //ǳ����ɫ(�м����ɫ)
#define LBBLUE           0X2B12 //ǳ����ɫ(ѡ����Ŀ�ķ�ɫ)




#endif





