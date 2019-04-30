#include "store.h"
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
char ** get_array(){
	char ** word=malloc(size()*sizeof(char*));
	int i=0;
	char *ch=(char*)malloc(40); //max length each word is 40
	FILE *fp;
	fp=fopen("wlist.txt", "r");
        while(fscanf(fp, "%s", ch) != EOF){
		word[i]=malloc(strlen(ch)*sizeof(char));
		strcpy(word[i], ch);
		i++;
        }
	fclose(fp);
	return  word;

}
int size(){
	int i=0;
        char *ch=(char*)malloc(40);
        FILE *fp;
        fp=fopen("wlist.txt", "r");
        while(fscanf(fp, "%s", ch) != EOF){
                i++;
        }
        fclose(fp);
	return i;
}
