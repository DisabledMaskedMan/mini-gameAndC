#ifndef __DS1302_H__
#define __DS1302_H__

extern char DS1302_Time[];

void DS1302_Init(void);
void DS1302_Write(unsigned char Command, char Data);
unsigned char DS1302_Read(unsigned char Command);
void DS1302_ReadTime();
void DS1302_SetTime();

#endif