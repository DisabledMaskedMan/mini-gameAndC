#include <REGX52.H>

sbit AD_CS = P3^5;
sbit AD_DIN = P3^4;
sbit AD_DCLK = P3^6;
sbit AD_DOUT = P3^7;

/**
  * @brief  ZPT2046读取AD值
  * @param  Command 命令字，范围：头文件内定义的宏，结尾的数字表示转换的位数
  * @retval AD转换后的数字量，范围：8位为0~255，12位为0~4095
  */
unsigned int SPI_READ(unsigned char command)
{
	unsigned char i;
	unsigned int Data = 0x00;
	AD_CS = 1;
	AD_DCLK = 0;
	AD_CS = 0;
	for(i = 0; i < 8; i++)
	{
		AD_DIN = command & (0x80 >> i);
		AD_DCLK = 1;
		AD_DCLK = 0;
	}
	for(i = 0; i < 16; i++)
	{
		AD_DCLK = 1;
		AD_DCLK = 0;
		if(AD_DOUT)
			Data |= (0x8000 >> i);
	}
	AD_CS = 1;
	return Data >> 8;
}