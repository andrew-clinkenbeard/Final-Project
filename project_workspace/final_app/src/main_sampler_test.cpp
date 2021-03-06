/*****************************************************************//**
 * @file main_sampler_test.cpp
 *
 * @brief Basic test of nexys4 ddr mmio cores
 *
 * @author p chu
 * @version v1.0: initial release
 *********************************************************************/

// #define _DEBUG
#include "chu_init.h"
#include "sseg_core.h"
#include "ps2_core.h"

SsegCore sseg(get_slot_addr(BRIDGE_BASE, S8_SSEG));
Ps2Core ps2(get_slot_addr(BRIDGE_BASE, S11_PS2));



char get_hex(Ps2Core *ps2_p)
{
	char ch;
	bool flag = false;
	do{


	if (ps2_p->get_kb_ch(&ch))
	{
		//uart.disp(ch);
	    //uart.disp(" ");
	    flag = true;
	} // end get_kb_ch()
	} while(!flag);

	return ch;
}
int get_numbers(char data)
{
	int number;
	switch(data){
		case '0':
			number = 0;
			break;
		case '1':
			number = 1;
			break;
		case '2':
			number = 2;
			break;
		case '3':
			number = 3;
			break;
		case '4':
			number = 4;
			break;
		case '5':
			number = 5;
			break;
		case '6':
			number = 6;
			break;
		case '7':
			number = 7;
			break;
		case '8':
			number = 8;
			break;
		case '9':
			number = 9;
			break;
		default:
			number = 0;
	}
	return number;

}


int math(char data[5])
{
	int number_1 = 0;
	int number_2 = 0;
	int result = 0;
	for (int i = 0; i < 5; i++)
	{
		if( (i==0) | (i==1))
		{
			if (i == 0)
			{
				number_1 = get_numbers(data[i]) * 10;
			}
			else
			{
				number_1 = number_1 + get_numbers(data[i]);
			}

		}
		else if ((i==3) | (i==4))
		{
			if (i == 3)
			{
				number_2 = get_numbers(data[i]) * 10;
			}
			else
			{
				number_2 = number_2 + get_numbers(data[i]);
			}
		}
	}
	switch(data[2]){
	case '+':
		result = number_1 + number_2;
		break;
	case '-':
		result = number_1 - number_2;
		break;
	case '*':
		result = number_1 * number_2;
		break;
	case '/':
		result = number_1 / number_2;
		break;
	default:
		result = number_1 + number_2;
		break;
	}
	uart.disp("\r\nresult ");
	uart.disp(result);
	uart.disp("\r\n");
	return result;
}

void display(int number, SsegCore *sseg_p)
{
	int sseg[8];
	for (int x = 0; x < 9; ++x)
	{
		sseg[x] = 0;
	}
	for(int i=0; i<5; i++)
	{
		sseg[i] = number % 10;
		number = number / 10;
//		uart.disp(sseg[i]);
//		uart.disp("\n\r");
	}
	for (int x = 0; x < 9; ++x)
	{
		sseg_p->write_1ptn(sseg_p->h2s(16), x);
	}
	for (int i = 0; i <9; i++)
	{
		sseg_p->write_1ptn(sseg_p->h2s(sseg[i]), i);
	}
	sseg_p->set_dp(0x00);
}

void calculator()
{
	char operations [5];
	int number;
	uart.disp("Enter 2 digit number:\r\n");
	operations[0] = get_hex(&ps2);
	operations[1] = get_hex(&ps2);
	uart.disp("\n\rEnter operation:");
	uart.disp("\r\n Addition: +");
	uart.disp("\r\n Subtraction: -");
	uart.disp("\r\n Multiplication: *");
	uart.disp("\r\n Divison: /\n\r");
	operations[2] = get_hex(&ps2);
	uart.disp("\n\rEnter 2 digit number:\r\n");
	operations[3] = get_hex(&ps2);
	operations[4] = get_hex(&ps2);
	uart.disp("\r\n\r\n\r\n");
	number = math(operations);
	display(number, &sseg);
}




int main() {
	char operations [5];
	int number;
	uart.disp("Enter 2 digit number:\r\n");
	operations[0] = get_hex(&ps2);
	operations[1] = get_hex(&ps2);
	uart.disp("\n\rEnter operation:");
	uart.disp("\r\n Addition: +");
	uart.disp("\r\n Subtraction: -");
	uart.disp("\r\n Multiplication: *");
	uart.disp("\r\n Divison: /");
	operations[2] = get_hex(&ps2);
	uart.disp("\n\rEnter 2 digit number:\r\n");
	operations[3] = get_hex(&ps2);
	operations[4] = get_hex(&ps2);
	number = math(operations);
	display(number, &sseg);

	uart.disp("Enter 2 digit number:\r\n");
	operations[0] = get_hex(&ps2);
	operations[1] = get_hex(&ps2);
	uart.disp("\n\rEnter operation:");
	uart.disp("\r\n Addition: +");
	uart.disp("\r\n Subtraction: -");
	uart.disp("\r\n Multiplication: *");
	uart.disp("\r\n Divison: /");
	operations[2] = get_hex(&ps2);
	uart.disp("\n\rEnter 2 digit number:\r\n");
	operations[3] = get_hex(&ps2);
	operations[4] = get_hex(&ps2);
	number = math(operations);
	display(number, &sseg);

	uart.disp("Enter 2 digit number:\r\n");
	operations[0] = get_hex(&ps2);
	operations[1] = get_hex(&ps2);
	uart.disp("\n\rEnter operation:");
	uart.disp("\r\n Addition: +");
	uart.disp("\r\n Subtraction: -");
	uart.disp("\r\n Multiplication: *");
	uart.disp("\r\n Divison: /");
	operations[2] = get_hex(&ps2);
	uart.disp("\n\rEnter 2 digit number:\r\n");
	operations[3] = get_hex(&ps2);
	operations[4] = get_hex(&ps2);
	number = math(operations);
	display(number, &sseg);

	uart.disp("Enter 2 digit number:\r\n");
	operations[0] = get_hex(&ps2);
	operations[1] = get_hex(&ps2);
	uart.disp("\n\rEnter operation:");
	uart.disp("\r\n Addition: +");
	uart.disp("\r\n Subtraction: -");
	uart.disp("\r\n Multiplication: *");
	uart.disp("\r\n Divison: /");
	operations[2] = get_hex(&ps2);
	uart.disp("\n\rEnter 2 digit number:\r\n");
	operations[3] = get_hex(&ps2);
	operations[4] = get_hex(&ps2);
	number = math(operations);
	display(number, &sseg);

	while(1){
		sleep_ms(1000);
	}

} //main

