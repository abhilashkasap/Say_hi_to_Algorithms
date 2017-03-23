#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<conio.h>
#include<process.h>

void hit(char);

void delay(){
	int c,d;
	for(c = 0; c< 700; c++)
		for(d = 0; d < 700; d++)
		{
		}
}

int locx = 500,locy = 800;


int main()
{
	char c;
	while(1){
		if(kbhit()){
			c = getch();
			hit(c);
		} else {
			hit(c);
		}
	}
    SetCursorPos(500,500);

    return 0;

}

void hit(char c){
	if(c == 'w'){
		delay();
		if(locy == 1){
			locy = 800;
		}
		SetCursorPos(locx,locy--);
	} else if(c == 'd'){
		delay();
		if(locx == 1000){
			locx = 0;
		}
		SetCursorPos(locx++,locy);
	}
	else if(c == 's'){
		delay();
		if(locy == 800){
			locy = 1;
		}
		SetCursorPos(locx,locy++);
	}
	else
	if(c == 'a')
	{
		delay();
		if(locx==0)
		locx=1000;
		SetCursorPos(locx--,locy);
	
	}
	else
	{
	}
	
}
