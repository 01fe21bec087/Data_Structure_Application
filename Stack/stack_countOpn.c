/*
Author: Abhinav Sushil Pawar
Date: 19/05/2023
*/
/*
Stack is implemented using arrays
Constraint: maximum stack size if MAXSTACK = 10000
*/
#include<stdio.h>
#define MAXSTACK 10000
int stack[MAXSTACK];
int sp=-1;              //Stack pointer
int StackisEmpty()
{
    return(sp==-1);
}
int StackisFull(int n)
{
    if(sp==n-1)
        return 1;
    else
        return 0;
}

void write_random_to_file(FILE* fptr,char inputfile[],int n)//(file_ptr,file_name,source_array,array_size)
{
    fptr=fopen(inputfile,"w");
    if(fptr==NULL)
    {
        printf("'%s' File creation error!\n",inputfile);
    }
    else
    {
        printf("'%s' File created successfully\n",inputfile);
        for(int i=0;i<n;i++)
        {
            int random=rand()%200;
            fprintf(fptr,"%d\n",random);        //Store random numbers to file
        }
        printf("Entered %d random numbers in file successfully\n",n);
    }
    fclose(fptr);
}
void pushfromfile(FILE* fptr,char inputfile[],int n)
{
    if(fptr==NULL)
    {
        printf("'%s' File reading error!\n",inputfile);
    }
    else if(feof(fptr))
    {
        printf("Reached end of the file '%s'\n",inputfile);
    }
    else
    {
        printf("'%s' File reading successfully\n",inputfile);
        if(StackisFull(n))                //stack is full
        {
            printf("Stack overflow\n");
            return;
        }
        sp++;
        fscanf(fptr,"%d",&stack[sp]);    //Loading data pointed by file ptr to stack
        printf("%d pushed, top=%d\n",stack[sp],sp);//stack[%d]=%d\n",sp,stack[sp]);
    }
}
int pop()
{
    if(StackisEmpty())     //isempty
    {
        printf("Stack underflow\n");
        return;
    }
    int item=stack[sp];     //1st extract the data, then decrement pointer
    sp--;
    printf("%d popped; top=%d\n",item,sp);
    return item;
}
void append_num_to_file(FILE* fptr,char filename[],int data)       //(file_ptr,file_name,source_array,array_size)
{
    if(fptr==NULL)
        printf("'%s' File creation/opening error!\n",filename);
    else
        fprintf(fptr,"%d\n",data);
}
void append_string_to_file(FILE* fptr,char filename[],char data[])
{
    if(fptr==NULL)
        printf("'%s' File creation/opening error!\n",filename);
    else
        fprintf(fptr,"%s\n",data);
}
void flush(FILE* fptr, char filename[])     //clear a file
{
    fptr=fopen(filename,"w");
    fclose(fptr);
    printf("Clearing '%s' file...\n",filename);
}
void display()
{
    if(StackisEmpty())      //empty stack => nothing to display
    {
        printf("Stack underflow\n");
        return;
    }
    printf("Displaying stack: ");
    for(int i=sp;i>-1;i--)      //displaying using seek-alike operation
    {
        printf("%d ",stack[i]);
    }
}

void main()
{
    FILE *fpinput;
    FILE *fpPush;
    FILE *fpPop;
    FILE *fpStack;
    FILE *fpOpn;
    FILE *fpCountOpn;
    char inputfile[]="Inputfile.txt",stackfile[]="stackfile.txt",pushlog[]="Pushlog.txt",poplog[]="Poplog.txt",opfile[]="OperationsFile.txt",countfile[]="OperationsCount.txt";
    int n,choice=-1,prevchoice=-1;
    int pushcount=0,popcount=0;
    char caution;
    fpinput=fopen(inputfile,"r");       //opening all necessary files
    fpPush=fopen(pushlog,"a");
    fpPop=fopen(poplog,"a");
    fpOpn=fopen(opfile,"a");
    fpCountOpn=fopen(countfile,"a");
    while(1)
    {
        if(choice==2 || choice==3)      //required for count operation file
            prevchoice=choice;          //update previous choice as push or pop only
        printf("\n\nEnter choice:\n 0:Clear all files \n 1:Generate random numbers \n 2:Push \n 3:Pop \n 4:Display stack \n 5:Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0: flush(fpinput,inputfile);       //clear all files
                    flush(fpStack,stackfile);
                    flush(fpPush,pushlog);
                    flush(fpPop,poplog);
                    flush(fpOpn,opfile);
                    flush(fpCountOpn,countfile);
                    printf("\n");
                    break;
            case 1: printf("Enter number of random numbers to write to file (range): ");
                    scanf("%d",&n);
                    write_random_to_file(fpinput,inputfile,n);
                    break;
            case 2: pushfromfile(fpinput,inputfile,n);              //push
                    append_num_to_file(fpPush,pushlog,stack[sp]);
                    append_string_to_file(fpOpn,opfile,"Push");
                    pushcount++;
                    break;
            case 3: append_num_to_file(fpPop,poplog,stack[sp]);     //pop
                    append_string_to_file(fpOpn,opfile,"Pop");
                    pop();
                    popcount++;
                    break;
            case 4: display();
                    break;
            case 5: printf("Exiting...\n");
                    goto exit;      //before exiting close all files
            default:printf("Invalid choice... \n");
        }
        if(prevchoice!=choice)
        {
            if(prevchoice==2)       //push
            {
                append_string_to_file(fpCountOpn,countfile,"Number of elements pushed: ");
                append_num_to_file(fpCountOpn,countfile,pushcount);
                pushcount=0;
            }
            else if(prevchoice==3)  //pop
            {
                append_string_to_file(fpCountOpn,countfile,"Number of elements popped: ");
                append_num_to_file(fpCountOpn,countfile,popcount);
                popcount=0;
            }
        }
    }
    exit:
    fclose(fpinput);
    fclose(fpPush);
    fclose(fpPop);
    fclose(fpOpn);
    fclose(fpCountOpn);

    fpStack=fopen(stackfile,"a");       //copying the stack to stack file
    for(int i=sp;i>-1;i--)
    {
        append_num_to_file(fpStack,stackfile,stack[i]);
    }
    fclose(fpStack);
}
