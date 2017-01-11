#include "menu.h"
#include "calculate.h"
void menu1(router &G)
{
    system("cls");
    int m=0;
    cout <<"\t\t|-------------W E L C O M E !-------------|"<<endl;
    cout <<"\t\t|>>>>>This is an initialization page<<<<<<|"<<endl;
    cout <<"\t\t|                                         |"<<endl;
    cout <<"\t\t|Initialization from:                     |"<<endl;
    cout <<"\t\t|                                         |"<<endl;
    cout <<"\t\t|  1: Keyboard                            |"<<endl;
    cout <<"\t\t|                                         |"<<endl;
    cout <<"\t\t|  2: File                                |"<<endl;
    cout <<"\t\t|------------Thanks for using!------------|"<<endl;
    cout <<"\t\t-->Your choice is :";
    while(m!=1||m!=2)
    {
    cin>>m;
    switch(m)
    {
    case 1:
        G.createVertices(G);
        G.createEdges(G);
        break;
    case 2:
        G.createGraph(G);
        cout <<"\t\t-->Initialization success !"<<endl;
        break;
    default:
        cout<<"\t\tW R O N G__E N T E R !"<<endl;
        cout <<"\t\t--> Please enter the correct number"<<endl;
        cout <<"\t\t-->Your choice is :";
    }
    if(m==1||m==2)break;
    }
}
void menu2(router &G)
{
    system("cls");
    int i=0,n=0,p=1;
    cout <<"\t\t|-------------W E L C O M E !-------------|"<<endl;
    cout <<"\t\t|                                         |"<<endl;
    cout <<"\t\t|  Function choices:                      |"<<endl;
    cout <<"\t\t|                                         |"<<endl;
    cout <<"\t\t|  1.Print the routing information base   |"<<endl;
    cout <<"\t\t|                                         |"<<endl;
    cout <<"\t\t|  2.Add a router                         |"<<endl;
    cout <<"\t\t|                                         |"<<endl;
    cout <<"\t\t|  3.Delete a router                      |"<<endl;
    cout <<"\t\t|                                         |"<<endl;
    cout <<"\t\t|  4.Exit the program                     |"<<endl;
    cout <<"\t\t|                                         |"<<endl;
    cout <<"\t\t|  Please enter the number your choose:   |"<<endl;
    cout <<"\t\t|------------Thanks for using!------------|"<<endl;
    cout <<"\t\t                                           "<<endl;
    //cout <<"\t\t--> Your choice is :";
    while(p)
    {
    cout <<"\t\t--> Your choice is :";
    cin >>i;
    if(i<1||i>4)
    {
        p=1;
        cout <<"\t\t--> Please enter the correct number"<<endl;
    }
    else p=0;
    }
    switch(i)
    {
        case 1:
            G.calculate(G);
            break;
        case 2:
            cout <<"\t\t-->Please choose the function you want:"<<endl;
            cout <<"\t\t-->1.Add router"<<endl<<"\t\t-->2.Add edge"<<endl;
            cout <<"\t\t-->Your choice is :";
            cin >>n;
            if(n==1)
            {
                G.addVertex(G);
                G.addEdge(G);
            }
            else if(n==2)G.addEdge(G);
            else cout <<"\t\tW R O N G__E N T E R !"<<endl;
            break;
        case 3:
            cout <<"\t\t-->Please choose the function you want:"<<endl;
            cout <<"\t\t-->1.Delete router"<<endl<<"\t\t-->2.Delete edge"<<endl;
            cout <<"\t\t-->Your choice is :";
            cin >>n;
            if(n==1)G.deleteVertex(G);
            else if(n==2)G.deleteEdge(G);
            else cout <<"\t\tW R O N G__E N T E R !"<<endl;
            break;
        case 4:
            exit(0);
        default:
        cout<<"\t\tW R O N G__E N T E R !"<<endl;
        cout <<"\t\t--> Please enter the correct number"<<endl;
        cout <<"\t\t-->Your choice is :";
    }
}
void menu3(router &G)
{
    int n;
    cout <<"\t\t-->Enter 1 to back to the main menu "<<endl<<"\t\t-->Enter 2 to exit"<<endl;
    cout <<"\t\t-->Your choice is :";
    cin >>n;
    if(n==1)
    menu2(G);
    else if(n==0)
        return;
    else cout<<"\t\t-->E N T E R__E R R O R !"<<endl;
}
