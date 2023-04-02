#include <REGX52.H>
#include "OneWire.h"

#define DS18B20_SKIP_ROM			0xCC
#define DS18B20_CONVERT_T			0x44
#define DS18B20_READ_SCRATCHPAD 	0xBE

void DS18B20_ConvetT()
{
	OneWire_Init();
	OneWire_WriteByte(DS18B20_SKIP_ROM);
	OneWire_WriteByte(DS18B20_CONVERT_T);
}

float DS18B20_ReadT()
{
	float T;
	unsigned char Tlow;
	unsigned char Thigh;
	unsigned int tmp;
	OneWire_Init();
	OneWire_WriteByte(DS18B20_SKIP_ROM);
	OneWire_WriteByte(DS18B20_READ_SCRATCHPAD);
	Tlow = OneWire_ReadByte();
	Thigh = OneWire_ReadByte();
	tmp = (Thigh << 8) | Tlow;
	T = tmp / 16.0;
	return T;
}