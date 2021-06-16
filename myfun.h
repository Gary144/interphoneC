
#ifndef __myfun_H
#define __myfun_H

#define SystemId 3 //�����豸ID��Ŀǰһ��������ID


#include "main.h"

 
#include "lcdfont.h"
#include "ips096.h"
#include "vs1003.h"
#include "stdio.h"
#include "string.h"


//����ָʾ��IO
#define led0(x) x? HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_RESET):HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_SET)
#define led0_Toggle HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13)



#define key0 HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_14)
#define key1 HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_13)
#define key2 HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)
extern uint8_t key0bit ;
extern uint8_t key1bit ;
extern uint8_t key2bit ;


extern TIM_HandleTypeDef htim4;

extern UART_HandleTypeDef huart1;


/*-------vs1003�õ��Ĳ���---------*/

extern uint8_t vs1003recinitbit;    //�Խ�ģʽ��ʱ�򣬳�ʼ����־λ��ֻ��ִ��һ��
extern uint8_t vs1003recstate ;      //¼��ģʽ״̬

extern unsigned char vs1003recdata[];
extern unsigned int vs1003recdatanum;
extern uint8_t guolvBit;
extern u8 loadingData[];

extern u8 play ;
extern uint16_t vs1003recTime ;
extern uint8_t vs1003rectimedelay ;


extern unsigned char vs1003upload[];
extern uint16_t vs1003uploabit ;

/*-------��ʱ���õ��Ĳ���---------*/
extern uint8_t timer4_ms ;
extern uint16_t testtime ;

/*-------���崮�ڽ�������---------*/
extern uint8_t uart1tab[7000] ;
extern uint16_t uart1tabnum ;



extern uint8_t testtab[7000];
extern uint16_t testtablen;
extern uint8_t soundbit;
extern uint8_t soundtwobit;

extern uint8_t SendBit ;


extern uint16_t zhongjiTime ;
extern uint8_t zhongjiBit ;




#endif
