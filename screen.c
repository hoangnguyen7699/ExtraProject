// this file contains screen functions. They are used to display
// sound levels on a PUTTY screen as a bar chart
#include <stdio.h>
#include "screen.h"
#include <string.h>
#include<stdlib.h>

void barChart(int *number_letters, char **duplicates, int number_of_duplicates){
	system("cls");
	printf("\033[8;90;60t");
	setColors(YELLOW);
	printf("\033[1;1H");
	printf("%d duplicates: ", number_of_duplicates);
	for(int i=0; i<number_of_duplicates; i++){
		printf("%s ",duplicates[i]);
	}
        for (int i=0; i<COL; i++){
                for (int j=0; j<number_letters[i]/3; j++){
			printf("\033[%d;%dH", 55-j, i+1); // j is row and i is column
			//printf("A");
                       	if(i%2==0) setColors(CYAN);
			else setColors(GREEN);
#ifdef UNICODE    // conditional compilation
			printf("%s", BAR);
#else
			printf("%c", '*');
#endif
	        }
        }
}

void clearScreen(void){
        printf("\033[2J");
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


