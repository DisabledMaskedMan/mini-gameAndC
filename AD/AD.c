#include <REGX52.H>
#include <SPI.H>
#include <LCD1602.H>
#include <Delay.H>

#define AD_XP_8		0x9C
#define AD_YP_8		0xDC
#define AD_BAT_8	0xAC
#define AD_AUX_8	0xEC

unsigned int DATA;

void main()
{
	LCD_Init();
	LCD_ShowString(1, 1, "ADJ");
	LCD_ShowString(1, 5, "NTC");
	LCD_ShowString(1, 9, "GR");
	while(1)
	{
		DATA = SPI_READ(AD_XP_8);
		LCD_ShowNum(2, 1, DATA, 3);
		DATA = SPI_READ(AD_YP_8);
		LCD_ShowNum(2, 5, DATA, 3);
		DATA = SPI_READ(AD_BAT_8);
		LCD_ShowNum(2, 9, DATA, 3);
		Delay(100);
	}
}
