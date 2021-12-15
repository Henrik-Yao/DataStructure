#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct Node{
	int index;
	char name[10];
	int code;
	struct Node *next;
}Node,*Linklist;

int main()
{
	int n,m;
	cin>>n;

    Linklist head = (Linklist)malloc(sizeof(Node));
 
    Linklist p = head;
	for(int i=0;i<n;i++){
        scanf("%d,%[^,],%d",&p->index,p->name,&p->code);
        p->next = (Linklist)malloc(sizeof(Node));
        if(i==n-1){
            p->next = head;
        }else{
            p = p->next;
        }
	}

    cin>>m;
    p = head;
    Linklist q;
    while (n!=0)
    {
        for(int i=1;i<m;i++){
            q = p;
            p = p->next;
        }
        m = p->code;
        printf("%d,%s,%d\n",p->index,p->name,p->code);
        q->next = p->next;
        p = p->next;
        n--;
    }
    

    return 0;


}
