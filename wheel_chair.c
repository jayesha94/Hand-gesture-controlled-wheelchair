#include<avr/io.h>
#include<util/delay.h>
#define LCD_DATA_PORT PORTB
#define LCD_CONT_PORT PORTD
#define LCD_RS PD0
#define LCD_RW PD1
#define LCD_EN PD2
#include<avr/lcd.h>
#include<avr/adc.h>
#include<avr/adxl335.h>
#define X_MIN 335
#define X_MAX 360
#define Y_MIN 335
#define Y_MAX 360
void main()
{
 DDRB=0XFF;
 DDRD=0X07;
 DDRC=0X0F;
 int x,y;
adc_init();
lcd_init();
 lcd_command_write(0X80);
 lcd_command_write("AUTOMATIC WHEEL CHAIR");
 _delay_ms(500);
 _delay_ms(500);
 _delay_ms(500);
 _delay_ms(500);
 while(1)
  {
   lcd_command_write(0X01);
    x=read_adxl335_x_value(0);
	lcd_number_write(x,10);
	lcd_string_write("    ");
	y=read_adxl335_x_value(1);
	lcd_number_write(y,10);
	lcd_command_write("0XC0");
	if(x>X_MAX)
	{
	 lcd_string_write("FORWARD");
	 PORTC=0X0A;
	 }
	 else if(x<X_MIN)
	 {
     lcd_string_write("REVERSE");
	 PORTC=0X05;
	 }
     else if(y>Y_MAX)
	 {
     lcd_string_write("RIGHT");
	 PORTC=0X08;
	 }
     else if(y<Y_MIN)
	 {
     lcd_string_write("LEFT");
	 PORTC=0X02;
	 }
	 else
	 {
     lcd_string_write("STOP");
	 PORTC=0X00;
	 }
	 _delay_ms(200);
	 }
	 }
