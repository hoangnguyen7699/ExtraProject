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
        barChart(o, array_duplicates, size);
        resetColors();
        getchar();
}
