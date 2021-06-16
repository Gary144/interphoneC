
#include "vs1003.h"

	 
//unsigned char record[600]={0};

/*
   调试放歌的时候，记录的，没有整理的文件

   	q = sizeof(music);                         //计算数据长度
 
		Vs1003_XDCS_0;                             //拉低，选中
//	Vs1003_XCS_1;
		for(i=0;i<q;i++)                           //开始放歌
		{	
       VS_Send_Dat(music[i]);                   //循环送数据
			 delay_us(300); //调节这个时间，可以调节说话的速度
		}
	  flush_buffer();   //
		Vs1003_XDCS_1;    //拉高


*/

 
 void delay_us(uint32_t us)
{
    uint32_t delay = (HAL_RCC_GetHCLKFreq() / 4000000 * us);
    while (delay--)
    {
        ;
    }
}



//SPI的写
void vs1003_spi_write(uchar ucSendData)
{
	uchar ucCount;
	uchar ucMaskCode;
 // while(Vs1003_DREQ_Read==0);
	ucMaskCode = 0x80;
	for(ucCount=0; ucCount<8; ucCount++)
	{
		Macro_Set_CLK_Low();

		if(ucMaskCode & ucSendData)
		{
			Macro_Set_SI_High();
		}
		else
		{
			Macro_Set_SI_Low();
		}

		Macro_Set_CLK_High();
		ucMaskCode >>= 1;
	}
	delay_us(10);
		
}

void vs1003_wr_command(unsigned char addr,unsigned char hdat,unsigned char ldat )
{ 
	
//  Vs1003_DREQ_1;
  while(!Vs1003_DREQ_Read);	
	Vs1003_XCS_0;
  vs1003_spi_write(0x02);
  vs1003_spi_write(addr);
  vs1003_spi_write(hdat);
  vs1003_spi_write(ldat);   
	Vs1003_XCS_1;
}

unsigned char vs1003_spi_readbyte()
{ 
	unsigned char ucReadData;
	unsigned char ucCount;
	
     Vs1003_MOSI_1;
	for(ucCount=0; ucCount<8; ucCount++)
	{
		ucReadData <<= 1;
			//降低时钟频率
		Vs1003_SCLK_0;

		if(Vs1003_MISO_Read)
		{
			ucReadData |= 0x01;
		}
		Macro_Set_CLK_High();

	}
	return(ucReadData);
}



unsigned int vs1003read(unsigned char addr)
{
	unsigned int temp;
	unsigned char temp1;
	Vs1003_XDCS_1;
	Vs1003_XCS_0;//XCS = 0
	 
	vs1003_spi_write(0x03);
	delay_us(1);
	vs1003_spi_write(addr);
	temp=  vs1003_spi_readbyte();
	temp=temp<<8;
	temp1= vs1003_spi_readbyte();
	temp=temp|temp1;;
	Vs1003_XCS_1;    
	return temp;
}



void vs1003init(void)
{
		Vs1003_RST_0;
		HAL_Delay(100);
		Vs1003_XDCS_1;
		Vs1003_XCS_1;
		Vs1003_RST_1;
		HAL_Delay(2);
		vs1003_wr_command(0x00,0x08,0x04);
		HAL_Delay(2);
//	Vs1003_DREQ_1;
		while(!Vs1003_DREQ_Read);
		vs1003_wr_command(0x03,0x98,0x00);
		HAL_Delay(2);
		vs1003_wr_command(0x05,0xbb,0x81);
		HAL_Delay(2);
		vs1003_wr_command(0x02,0x00,0x55);
		HAL_Delay(2);
		vs1003_wr_command(0x0b,0x01,0x01);   // 音量

		HAL_Delay(10);
		vs1003_spi_write(0);
		vs1003_spi_write(0);
		vs1003_spi_write(0);
		vs1003_spi_write(0);
		do 
		{
			vs1003_wr_command(0x0b,0x01,0x01);   // 音量
		}while(vs1003read(0x0b)!=0x0101);	
}



void ceshi(uint8_t x)
{		
	    vs1003init();
			vs1003_wr_command(SPI_MODE,0x08,0x20);
			while(!Vs1003_DREQ_Read);
			Vs1003_XDCS_0;
			Vs1003_XCS_1;
			//向vs1003发送正弦测试命令：0x53 0xef 0x6e n 0x00 0x00 0x00 0x00
			//其中n = 0x24, 设定vs1003所产生的正弦波的频率值，具体计算方法见vs1003的datasheet
			vs1003_spi_write(0x53);    
			vs1003_spi_write(0xef);     
			vs1003_spi_write(0x6e);     
			vs1003_spi_write(0x74);   
			vs1003_spi_write(0x00);    
			vs1003_spi_write(0x00);
			vs1003_spi_write(0x00);
			vs1003_spi_write(0x00);
			HAL_Delay(10);		
}

void vs1003_sendmusicdat(unsigned char dat) 
{ 
   while(!(Vs1003_DREQ_Read));  //VS1003的DREQ为高才能写入数据
   vs1003_spi_write(dat);//通过SPI向VS1003写入一个字节的音频数据
}
 
void flush_buffer() 
{
	unsigned int i;
	Vs1003_XDCS_0;	   //打开数据片选，即开启SDI传输
	for(i=0;i<2048;i++)
	{
		vs1003_spi_write(0);
	}
		Vs1003_XCS_1;        //关闭数据片选
}



//void VS_Set_Vol(unsigned char volx)
//{
//			u16 volt=0; 			//暂存音量值
//			volt=254-volx;			//取反一下,得到最大值,表示最大的表示 
//			volt<<=8;
//			volt+=254-volx;			//得到音量设置后大小
//			vs1003_wr_command(SPI_VOL,volt/256,volt%256);//设音量 
//}















