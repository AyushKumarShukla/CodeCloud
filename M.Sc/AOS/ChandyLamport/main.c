#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#define MAX_CANDIDATES 11

typedef struct node{
    int id;
    int state;
    bool recorded;
}Node;

typedef struct channel{
    int id;
    int from;
    int to;
    int buffer[MAX_CANDIDATES];
}Channel;

Node *Nodes = NULL;
Channel *Channels = NULL;
int cnum=3,chans=4;

void SendMarker(int recv){
    int i;
    if(!Nodes[recv].recorded){
        printf("NODE: %d STATE: %d\n",recv,Nodes[recv].state);
        Nodes[recv].recorded = true;
        for(i=0;i<chans;i++){
            if(Channels[i].from == recv || Channels[i].to != recv){
                sleep(1);
                printf("Sending Marker From %d to %d\n",recv, Channels[i].to);
                SendMarker(Channels[i].to);
            }
        }
    }
    else{
        printf("ALREADY RECORDED NODE %d: BUFFER INFO\n",recv);
        return;
    }


}

int main(void){
    int recorder,start,end;
    int i,j;
    
    printf("Enter the number of candidates: ");
    scanf("%d",&cnum);

    printf("Enter the number of channels: ");
    scanf("%d",&chans);
    
    Nodes = (Node*)malloc(cnum * sizeof(Channel));
    Channels = (Channel*)malloc(chans * sizeof(Channel));
    
    for(i=0;i<cnum;i++){
            Nodes[i].id = i;
            Nodes[i].state = i+i;
            Nodes[i].recorded = 0;
    }
    printf("Node Info: \n");
    
    for(i=0;i<cnum;i++){
        printf("(%d,%d,%d)\n",Nodes[i].id, Nodes[i].state, Nodes[i].recorded);
    }

    for(i=0;i<chans;i++){
        printf("Enter channel endpoints: ");
        scanf("%d%d",&start,&end);
        Channels[i].id = i;
        Channels[i].from = start;
        Channels[i].to = end;
    }
    printf("Channel Info:\n");
    for(i=0;i<chans;i++){
        printf("(%d,%d,%d)\n",Channels[i].id, Channels[i].from, Channels[i].to);
    }

    printf("Enter the recorder node:");
    scanf("%d",&recorder);
    
    //Marker Sending Rule: Send Marker Along All Channels Hitting The Node
    printf("RECORDER RECORDING STATE:\n");
    printf("(%d)\n",Nodes[recorder].state);
    Nodes[recorder].recorded = true;
    for(i=0;i<chans;i++){
        if(Channels[i].from == recorder || Channels[i].to == recorder)
            SendMarker(Channels[i].to);
    }
    
    return 0;
}
