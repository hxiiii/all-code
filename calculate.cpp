#include "calculate.h"
#include "menu.h"
#include "queue"
router::router()
{
    int i,j;
    for(i=0; i<20; i++)
        for(j=0; j<20; j++)
        {
            if(i==j)table[i][j]=0;
            else table[i][j]=INFINITY;
        }
    for(i=0; i<20; i++)
        router_info[i].num=0;
    size=0;
}

void router::calculate(router &G)
{
    int s;
    int v0=0;
    cout<<"\t\t-->Here is the information of all routers:"<<endl;
    cout<<"\t\t-------------------------------------------"<<endl;
    cout<<"\t\t|  router_number"<<"\t|  IP_address      |"<<endl;
    cout<<"\t\t-------------------------------------------"<<endl;

    for(int i=0;i<size;++i)
    {

        cout<<"\t\t    "<<router_info[i].num<<"\t\t\t|  "<<router_info[i].ip<<endl;
        //cout<<"\t\t-------------------------------------------"<<endl;
    }
    cout<<"\t\t-------------------------------------------"<<endl;
    cout<<"\t\t-->Please enter the router_number to query: ";
    cin>>s;
    for(int i=0;i<size;++i)
    {
        if(router_info[i].num==s)
        {
            v0=i;
            break;
        }
    }
    //start to calculate
    bool flag[20];//pending if this node has been calculated
    int dist[20];//distance
    int pre[20];//the number of parent
    //initialization
    for(int i=0;i<size;++i)
    {
        dist[i]=table[v0][i];
        flag[i]=false;
        if(dist[i]==INFINITY)
            pre[i]=-1;
        else
            pre[i]=v0;
    }
    dist[v0]=0;
    flag[v0]=true;//v0 has been calculated
    for(int i=1;i<size;++i)
    {
        int temp=INFINITY;
        int node=v0;//NOTICE:the number of v0 is node+1
        for(int j=0;j<size;++j)//to find the shortest node
        {
            if(flag[j]==false&&dist[j]<temp)
            {
                node=j;
                temp=dist[j];
            }
        }
        flag[node]=true;
        for(int k=0;k<size;++k)
        {
            if(flag[k]==false&&table[node][k]!=INFINITY)
            {
                if(table[node][k]+dist[node]<dist[k])
                {
                    dist[k]=table[node][k]+dist[node];
                    pre[k]=node;
                }
            }
        }
    }
    //dijkstra ends

    bool flag_node[20];
    for(int i=0;i<size;++i)
        flag_node[i]=true;
    for(int i=0;i<size;++i)
    {
        if(i==v0)
            continue;
        int k=i;
        int sum=0;
        for(int j=0;j<size;++j)
        {
            k=pre[k];
            if(k<0)
            {
                break;
            }
            for(int m=0;m<size;++m)
            {
                if(k==m)
                    flag_node[m]=false;
            }
            ++sum;
            if(k==v0)
                break;
        }
    }
    cout<<"\t\t----------------------------------------------"<<endl;
    queue<int> q;
    for(int i=0;i<size;++i)
    {
        if(i==v0)
            continue;
        if(flag_node[i]==false)
            continue;
        q.push(i);
        cout<<"\t\t\t";
        stack<int> ss;
        int d=i;
        for(int j=0;j<size;++j)
        {
            if(pre[d]<0)
            {
                continue;
            }
            d=pre[d];
            ss.push(d);
            if(d==v0)
            {
                int w=0;
                int sum=0;
                while(!ss.empty())
                {
                    cout<<router_info[ss.top()].num<<"->";
                    ss.pop();
                    sum++;
                    w++;
                }
                cout<<router_info[i].num<<endl;
                break;
            }
        }
    }

    cout<<endl;


    cout <<"\t\t-->Here is the information you need:"<<endl;
    cout<<"\t\t-------------------------------------------"<<endl;
    cout<<"\t\t| Destination IP  "<<"|  Next jump  |"<<"    Path |"<<endl;
    cout<<"\t\t-------------------------------------------"<<endl;
    int temp_num;
    for(int i=0;i<size;++i)
    {
        stack<int> s1;
        temp_num=i;
        if(i==v0)
            continue;
            if(pre[i]<0)
                continue;
        int count=0;
        while(count<size)
        {
            int c=temp_num;
            temp_num=pre[temp_num];
            s1.push(c);
            if(temp_num==v0)
            {
                //cout<<"\t\t   The destination IP is : "<<router_info[i].ip<<endl;
                //cout<<"\t\t   The next jump is  : "<<router_info[c].num<<endl;
                cout<<"\t\t   "<<router_info[i].ip<<"\t\t "<<router_info[c].num<<"\t   "<<router_info[v0].num;
                //cout<<"\t\t   path : ";
                //cout<<router_info[v0].num;
                while(1)
                {
                    cout<<"->";
                    cout<<router_info[s1.top()].num;
                    s1.pop();
                    if(s1.empty())
                        break;
                }
                cout<<endl;
                break;
            }
            count++;
        }
    }
    cout<<"\t\t-------------------------------------------"<<endl;
menu3(G);
}
