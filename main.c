#include<stdio.h>
#include<stdlib.h>
#include "process.h"
#include"screen.h"
#include<stdio.h>
#include<time.h>

int main(){
	int *o=total_array();
	int size=number_of_word_duplicate();
	char **array_duplicates= duplicates();
	int *out=malloc(sizeof(int)*52*3);
	int i1=0;
	int i2=-1;
	while(i1<52*3){
		if(i1%3==0) i2++;
		out[i1]=o[i2];
		i1++;
	}
        barChart(out, array_duplicates, size);
        resetColors();
        getchar();
}
