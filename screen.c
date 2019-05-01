// this file contains screen functions. They are used to display
// sound levels on a PUTTY screen as a bar chart
#include <stdio.h>
#include "screen.h"
#include <string.h>
#include<stdlib.h>

void barChart(int *number_letters, char **duplicates, int number_of_duplicates){
	printf("\033[8;80;160t");
	clearScreen();

	//setColors2(WHITE, bg(RED));
	printf("\033[3;1H");
	printf("%d duplicated words: ", number_of_duplicates);
	for(int i=0; i<number_of_duplicates; i++){
		printf("%s ",duplicates[i]);
	}
	int i=0;
        while(i<COL*3){
                for (int j=0; j<number_letters[i]/3.5; j++){
			printf("\033[%d;%dH", 55-j, i+1); // j is row and i is column

                       	if(i%6==0 || i%6==1 || i%6==2) setColors(CYAN);
			else setColors(GREEN);
#ifdef UNICODE    // conditional compilation
			printf("%s", BAR);
#else
			printf("%c", '*');
#endif
	        }
		if(i%3==0 && number_letters[i]!=0){
			printf("\033[%d;%dH", 55-(int)(number_letters[i]/3.5)-1, i+1);
			printf("%d", number_letters[i]);
		}
		i++;
		int t1=1;
		int t2=0;
		while(t1<=52*3){
			printf("\033[56;%dH", t1);
			if(t1%3==2){
				char temp= t2+65;
                        	printf("%c", temp);
				if(t1%2==1) t2++;
			}else printf(" ");
			t1++;
		}
        }
}

void clearScreen(void){
        printf("\033[2J");
        fflush(stdout);
}

void setColors2(short bg, short fg){
	printf("\033[%d;%d;1m", bg, fg);
	fflush(stdout);
}

void setColors(short bg){
        printf("\033[%d;1m", bg);
        fflush(stdout);
}

void resetColors(void){
        printf("\033[0m");
        fflush(stdout);
}


