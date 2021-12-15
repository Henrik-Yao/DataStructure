#include <iostream>
#include <cmath>
#include <malloc.h> 
#define maxSize 10000
using namespace std;

typedef struct{
    int *base;
    int *top;
    int stacksize;
}numStack;
typedef struct{
    char *base;
    char *top;
    int stacksize;
}oprStack;

int initnumStack(numStack *S){
    S->base=(int *)malloc(maxSize*sizeof(int));
    if(!S->base)
    exit(0);
    S->top=S->base;
    S->stacksize=maxSize;
    return 1;
}
int initoprStack(oprStack *S){
    S->base=(char *)malloc(maxSize*sizeof(char));
    if(!S->base)
    exit(0);
    S->top=S->base;
    S->stacksize=maxSize;
    return 1;
}

int isnumEmpty(numStack *S){
    if(S->base=S->top)
    return 1;
    return 0;
}

int pushnum(numStack *S,int e){//
   if(S->top-S->base==maxSize){
       return 0;
   }
    *(S->top)=e;
    S->top++;
    return 1;
}
int pushopr(oprStack *S,char e){//
   if(S->top-S->base==maxSize){
       return 0;
   }
    *(S->top)=e;
    S->top++;
    return 1;
}

int popnum(numStack *S,int *e){
    if(S->top==S->base)
        return false;
    S->top--;
    *e=*(S->top);
    return true;
}
int popopr(oprStack *S,char *e){
    if(S->top==S->base)
        return false;
    S->top--;
    *e=*(S->top);
    return true;
}

int gettopnum(numStack *S){
    return *(S->top-1);
}
char gettopopr(oprStack *S){
    return *(S->top-1);
}

char Precede(char c1,char c2){
    int i=0,j=0;
    char c[8][8]={
        {'>','>','<','<','<','>','>','<'},
        {'>','>','<','<','<','>','>','<'},
        {'>','>','>','>','<','>','>','<'},
        {'>','>','>','>','<','>','>','<'},
        {'<','<','<','<','<','=','0','<'},
        {'>','>','>','>','0','>','>','>'},
        {'<','<','<','<','<','0','=','<'},
        {'>','>','>','>','<','>','>','<'}};
        switch(c1){
            case '+': i=0;break;
            case '-': i=1;break;
            case '*': i=2;break;
            case '/': i=3;break;
            case '(': i=4;break;
            case ')': i=5;break;
            case '#': i=6;break;
            case '^': i=7;break;
        }
        switch(c2){
            case '+': j=0;break;
            case '-': j=1;break;
            case '*': j=2;break;
            case '/': j=3;break;
            case '(': j=4;break;
            case ')': j=5;break;
            case '#': j=6;break;
            case '^': j=7;break;
        }
        return c[i][j];
}

int opreate(int c1,char theta,int c2){
    switch(theta){
        case '+': return c1+c2;
        break;
        case '-': return c2-c1;
        break;
        case '*': return c1*c2;
        break;
        case '/': return c2/c1;
        break;
        case '^': 
        return pow(c2,c1);
        break;
    }
    return 0;
}

int EvaluateExpression(){
    oprStack OPTR;//ÔËËã·û
    numStack OPND;//Êý×Ö
    initoprStack(&OPTR);
    initnumStack(&OPND);
    char c,x,theta;
    int c1,c2;
    c=getchar();
    if(c=='\n'){
        return 0;
    }
    pushopr(&OPTR,'#');
    while(c!='\n'||gettopopr(&OPTR)!='#'){
        if(c>='0'&&c<='9') {
            int temp; 
            temp=c-'0';
        while(c>='0'&&c<='9'){
            c=getchar(); if(!(c>='0'&&c<='9')){break;}
            temp=temp*10+(c-'0');
        }
        pushnum(&OPND,temp);
        }
        else
        switch (Precede(gettopopr(&OPTR),c))
        {
        case '<':
        pushopr(&OPTR,c);
        c=getchar();
            break;
        case '=':
        popopr(&OPTR,&x);c=getchar();
        break;
        case '>':
        popopr(&OPTR,&theta);popnum(&OPND,&c1);popnum(&OPND,&c2);
        pushnum(&OPND,opreate(c1,theta,c2));
        default:
            break;
        }
    }
    cout<<gettopnum(&OPND)<<endl;
    return 1;
}

int main(){
    EvaluateExpression();
    return 0;
}

