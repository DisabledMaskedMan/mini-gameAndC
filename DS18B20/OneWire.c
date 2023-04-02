#include <REGX52.H>

sbit OneWire_DQ = P3^7;

unsigned char OneWire_Init()
{
	unsigned char AckBit = 0;
	unsigned char i;
	EA = 0;
	OneWire_DQ = 1;
	OneWire_DQ = 0;
	i = 247;while (--i);
	OneWire_DQ = 1;
	i = 39;while (--i);
	AckBit = OneWire_DQ;
	i = 247;while (--i);
	EA = 1;
	
	return AckBit;
}

void OneWire_WriteBit(unsigned char Bit)
{
	unsigned char i;
	EA = 0;
	OneWire_DQ = 0;
	i = 4;while (--i);
	OneWire_DQ = Bit;
	i = 24;while (--i);
	OneWire_DQ = 1;
	EA = 1;
}

unsigned char OneWire_ReadBit()
{
	unsigned char Bit;
	unsigned char i;
	EA = 0;
	OneWire_DQ = 0;
	i = 2;while (--i);
	OneWire_DQ = 1;
	i = 2;while (--i);
	Bit = OneWire_DQ;
	i = 24;while (--i);
	EA = 1;
	
	return Bit;
}

void OneWire_WriteByte(unsigned Byte)
{
	unsigned char i;
	for(i = 0; i < 8; i++)
	{
		OneWire_WriteBit(Byte & (0x01 << i));
	}
}

unsigned char OneWire_ReadByte()
{
	unsigned char Byte = 0x00;
	unsigned char i;
	for(i = 0; i < 8; i++)
	{
		if(OneWire_ReadBit())
			Byte |= (0x01 << i);
	}
	return Byte;
}