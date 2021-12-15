#include<bits/stdc++.h>  
using namespace std;  
#define MVNum 100  
  
//边  
typedef struct ArcNode{  
    int adjvex;  
    struct ArcNode *nextarc;  
}ArcNode;  
  
//顶点  
typedef struct VNode{  
    char data;  
    ArcNode *firstarc;  
}VNode,AdjList;  
  
//邻接表  
typedef struct ALGraph{  
    AdjList vertices[MVNum];  
    int vexnum,arcnum;  
}ALGraph;  
  
int LocateVex(ALGraph G,char v){  
    //确定点v在G中的位置  
    for(int i = 0; i < G.vexnum;i++)  
        if(G.vertices[i].data == v)  
            return i;  
   return -1;  
}  
  
int CreateALG(ALGraph &G){  
    cin>>G.vexnum>>G.arcnum;  
    for(int i=0;i<G.vexnum;i++){  
        cin>>G.vertices[i].data;  
        G.vertices[i].firstarc=NULL;  
    }  
    for(int k=0;k<G.arcnum;k++){  
        char v1,v2;  
        cin>>v1>>v2;  
        int i=LocateVex(G,v1),j=LocateVex(G,v2);  
        ArcNode *p1=new ArcNode;  
        p1->adjvex=j;  
        p1->nextarc=G.vertices[i].firstarc;  
        G.vertices[i].firstarc=p1;  
        ArcNode *p2=new ArcNode;                  
        p2->adjvex=i;                          
        p2->nextarc= G.vertices[j].firstarc;    
        G.vertices[j].firstarc=p2;   
    }  
    return 1;  
}  
  
int main(){  
    ALGraph G;  
    CreateALG(G);  
    for(int i = 0 ; i < G.vexnum ;i++){  
        VNode temp = G.vertices[i];  
        ArcNode *p = temp.firstarc;  
        int sum=0;  
        while(p){  
            sum++;  
            p = p->nextarc;  
        }  
        if(i==G.vexnum-1){  
            cout<<sum<<endl;  
        }  
        else cout<<sum<<" ";   
    }  
    return 0;  
}  
