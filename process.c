#include "store.h"
#include "process.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int * array_started_letters(){
	int s=size();
        char **array_of_letters=get_array();
	int *all_letters=malloc(sizeof(int)*26);
	for(int i=0; i<26; i++){
		all_letters[i]=0;
	}
	for(int i=0; i<s; i++){
		all_letters[(int)array_of_letters[i][0]-65]++;
	}

	return all_letters;
}
int *array_letter(){
	int s=size();
        char **array_of_letters=get_array();
	int *all_letters=malloc(sizeof(int)*26);
	for(int i=0; i<26; i++){
                all_letters[i]=0;
        }
	for(int i=0; i<s; i++){
		for(int j=0; j<strlen(array_of_letters[i]); j++){
			all_letters[(int)array_of_letters[i][j]-65]++;
		}
	}
	return all_letters;
}
int number_of_word_duplicate(){
	int s=size();
        char **array_of_letters=get_array();
	int c=0;
        for(int i=0;i<s; i++){
                for(int j=i+1; j<s; j++){
                        if(strcmp(array_of_letters[i], array_of_letters[j])==0){
                                c++;
                        }

                }
        }
	return c;
}
int *total_array(){
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
        }
	return o;
}
char ** duplicates(){
	int s=size();
        char **array_of_letters=get_array();
	char **word_duplicates=malloc(sizeof(char*)*number_of_word_duplicate());
	int c=0;
	for(int i=0;i<s; i++){
		for(int j=i+1; j<s; j++){
			if(strcmp(array_of_letters[i], array_of_letters[j])==0){
				word_duplicates[c]=malloc(strlen(array_of_letters[j])*sizeof(char));
				strcpy(word_duplicates[c], array_of_letters[j]);
				c++;
			}

		}
	}
	return word_duplicates;
}
