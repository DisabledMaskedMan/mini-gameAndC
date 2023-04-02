#ifndef __OneWire_H__
#define __OneWire_H__

unsigned char OneWire_Init();
void OneWire_WriteBit(unsigned char Bit);
unsigned char OneWire_ReadBit();
void OneWire_WriteByte(unsigned Byte);
unsigned char OneWire_ReadByte();

#endif