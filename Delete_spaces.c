//Delete spaces in a string
#include<stdio.h>
#define MAX 1000
char inString[MAX],outString[MAX];
void main(){
  FILE *fptr;
  fptr=fopen("SpacelessString.txt","w");
  fclose(fptr);
  while(1){
    fptr=fopen("SpacelessString.txt","a");
    gets(inString);
    int i=0;
    while(inString[i]!='\0'){
        if(inString[i]!=' '){
            //printf("%c",inString[i]);
            fprintf(fptr,"%c",inString[i]);
        }
        i++;
    }
    fprintf(fptr,"\n");
   // printf("\n");
    fclose(fptr);
  }
}
