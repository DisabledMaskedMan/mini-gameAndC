#include <REGX52.H>
#include "I2C.h"

#define AT24C02_ADDRESS		0xA0

void AT24C02_Write(unsigned char Address, unsigned char Data)
{
	I2C_Start();
	
	I2C_SendByte(AT24C02_ADDRESS);
	I2C_ReceiveAck();
	I2C_SendByte(Address);
	I2C_ReceiveAck();
	I2C_SendByte(Data);
	I2C_ReceiveAck();
	
	I2C_End();
}

unsigned char AT24C02_Read(unsigned char Address)
{
	unsigned char Data = 0x00;
	I2C_Start();
	
	I2C_SendByte(AT24C02_ADDRESS);
	I2C_ReceiveAck();
	I2C_SendByte(Address);
	I2C_ReceiveAck();
	
	I2C_Start();
	
	I2C_SendByte(AT24C02_ADDRESS | 0x01);
	I2C_ReceiveAck();
	Data = I2C_ReceiveByte();
	I2C_SendAck(1);
	
	I2C_End();
	return Data;
}