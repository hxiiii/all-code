#include "menu.h"
#include "calculate.h"

void router::deleteVertex(router &G)
{
    int i,v;
    cout<<"\t\t-->Please enter the number of router :";
    cin>>i;
    v=getVertexPos(i);
    if(v==-1)
    {
        cout<<"\t\t-->E N T E R__E R R O R !"<<endl;
        menu3(G);
    }
    router_info[v]=router_info[size-1];
    for(i=0; i<size; i++)
    {
        table[i][v]=table[i][size-1];
        //if(table[v][i]>0&&table[v][i]<MaxValue)
    }
    size--;
    for(i=0; i<size; i++)
    {
        table[v][i]=table[size][i];
    }
    save();
    menu3(G);
}

void router::deleteEdge(router &G)
{
    int a,b;
    cout<<"\t\t-->Please enter the information of edge: "<<endl;
    cout<<"\t\t-->Please enter the source IP :";
    cin>>a;
    cout<<endl<<"\t\t-->Please enter the  destination IP: ";
    cin>>b;
    int v,t;
    v=getVertexPos(a);
    t=getVertexPos(b);
    if(v==-1)
    {
        cout<<"\t\t-->E N T E R__E R R O R !"<<endl;
        menu3(G);
    }
    else if(t==-1)
    {
        cout<<"\t\t--> E N T E R__E R R O R !"<<endl;
        menu3(G);
    }
    else if(table[v][t]>0&&table[v][t]<INFINITY)table[v][t]=table[t][v]=INFINITY;
    save();
    menu3(G);
}

void router::addVertex(router &G)
{
    int i;
    if(size>20)
    {
        cout<<"\t\t-->Table Full!"<<endl;
        menu3(G);
    }
    cout<<"\t\t-->Please enter the routing information :"<<endl;
    cout<<"\t\t-->IP: ";
    cin>>router_info[size].ip;
    cout<<"\t\t-->Number: ";
    cin>>router_info[size].num;
    for(i=0; i<size; i++)
    {
        table[size][i]=table[i][size]=INFINITY;
    }
    table[size][i]=0;
    size++;
    save();
    //system("pause");
    //menu3(G);
}

void router::addEdge(router &G)
{
    int a,b,c;
    cout<<"\t\t-->Please enter the information of edge : "<<endl;
    cout<<"\t\t-->Please enter the source IP :";
    cin>>a;
    cout<<"\t\t-->Please enter destination IP :";
    cin>>b;
    cout<<"\t\t-->Please enter the cost of the edge :";
    cin>>c;
    int v,t;
    v=getVertexPos(a);
    t=getVertexPos(b);
    if(v==-1)
    {
        cout<<"\t\t-->Wrong information of source IP!"<<endl;
        menu3(G);
    }
    else if(t==-1)
    {
        cout<<"\t\t-->Wrong information of source IP!"<<endl;
        menu3(G);
    }
    else if(v!=t)table[v][t]=table[t][v]=c;
    save();
    menu3(G);
}


void router::createVertices(router &G)
{
    int i=0,j,tag=1;
    cout<<"\t\t-->Please enter routing information :"<<endl;
    while(tag)
    {
        cout<<"\t\t-->IP: ";
        cin>>router_info[i++].ip;
        cout<<"\t\t-->Number: ";
        cin>>router_info[i++].num;
        cout<<"\t\t-->enter '0' to exit";
        cin>>tag;
        size++;
    }
    ofstream out("rout_info.txt");
    if(out.is_open())
    {
        for(j=0; j<i; j++)
            out<<router_info[j].ip<<" "<<router_info[j].num<<endl;;
    }
    out.close();
    menu2(G);
}

void router::createEdges(router &G)
{
    int i,j,count=0,tag=1;
    int a,b,c;
    int v,t;
    for(i=0; i<size; i++)
        for(j=0; j<size; j++)
        {
            if(i==j)table[i][j]=0;
            else table[i][j]=INFINITY;
        }
    cout<<"\t\t-->Please enter the path information :";
    while(tag)
    {
        cout<<endl<<"\t\t-->Please enter the source IP : ";
        cin>>a;
        cout<<endl<<"\t\t-->Please enter the destination IP : ";
        cin>>b;
        cout<<endl<<"\t\t-->Please enter the cost: ";
        cin>>c;
        cout<<endl<<"\t\t-->enter '0' to exit!  ";
        cin>>tag;
        v=getVertexPos(a);
        t=getVertexPos(b);
        if(v!=-1&&t!=-1)
        {
            table[v][t]=c;
            table[t][v]=c;
        }
    }
    ofstream out("rout_path.txt");
    if(out.is_open())
    {
        for(i=0; i<size; i++)
            for(j=0; j<size; j++)
            {
                out<<table[i][j]<<" ";
                count++;
                if(count%size==0)out<<endl;
            }
    }
    out.close();
    }

void router::createGraph(router &G)
{
    int i=0,j;
    char buff[255];
    int number;
    size=0;
    ifstream in("rout_info.txt");
    if(!in)
    {
        cout<<"\t\t-->O P E N__E R R O R !"<<endl;
        menu3(G);
        }
    while(!in.eof()&&size<=20)
    {
        in>>buff>>number;
        router_info[i].ip=buff;
        router_info[i].num=number;
        i++;
        size++;
    }
    size=size-1;
    in.close();
    ifstream fin("rout_path.txt");
    if(!fin)
    {
        cout<<"\t\t-->O P E N__E R R O R !"<<endl;
        menu3(G);
    }
    while(!fin.eof())
    {
        for(i=0; i<size; i++)
            for(j=0; j<size; j++)
            {
                fin>>table[i][j];
            }
    }
}

void router::save()
{
    int i,j,count=0;
    ofstream out("rout_info.txt");
    if(out.is_open())
    {
        for(i=0; i<size; i++)
            out<<router_info[i].ip<<" "<<router_info[i].num<<endl;
    }
    out.close();
    ofstream fout("rout_path.txt");
    if(fout.is_open())
    {
        for(i=0; i<size; i++)
            for(j=0; j<size; j++)
            {
                fout<<table[i][j]<<"\t";
                count++;
                if(count%size==0)fout<<endl;
            }
    }
    fout.close();
}
