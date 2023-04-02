#ifndef __I2C_H__
#define __I2C_H__

void I2C_Start();
void I2C_End();
void I2C_SendByte(unsigned char Data);
unsigned char I2C_ReceiveByte();
void I2C_SendAck(unsigned char Ack);
unsigned char I2C_ReceiveAck();

#endif