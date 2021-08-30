#ifndef			LCD_INTERFACE_H
#define			LCD_INTERFACE_H

#define		CONTROL_PORT    PORTC
#define		LCD_RS			PIN4
#define		LCD_RW			PIN5
#define		LCD_EN			PIN6

#define		DATA_PORT		PORTD

void	LCD_init(void);
void	LCD_WriteChar(u8 Data);
void	LCD_CMD(u8 CMD);
void    LCD_SendCMD4(u8 cmd);
void    LCD_WriteChar4(u8 Data);
void    LCD_GOTOXY(u8 LINE_NUM,u8 POSITION);
void    LCD_WriteSTring(u8 * ptr);
void	LCD_ReadSensor(u16 Read);

#endif