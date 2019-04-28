#include<stdio.h>
#include<stdlib.h>
#include "process.h"
#include<stdio.h>
#include<time.h>

int main(){
        /*int arr[52]; //for making a barchart
        srand(time(NULL));
        for(int i=0;i<52;i++){
                arr[i] = rand()%70 + 30;
        }*/
        int *arr=array_started_letters();
        int *arr2=array_letter();
        int *o=malloc(52*sizeof(int));
        int c1=0, c2=0;
        for(int i=0; i<52; i++){
                if(i%2==0){
                        o[i]=arr[c1];
                        c1++;
                }else{
                        o[i]=arr2[c2];
                        c2++;
                }
		printf("%d\n", o[i]);
        }
}


