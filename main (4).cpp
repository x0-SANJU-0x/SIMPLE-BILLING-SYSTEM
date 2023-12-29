#include <iostream>
#include <string>
#include <fstream> 
#include<ctime>
using namespace std;
class product
{
    public:
    int stock,sum,cp,sp,total,quan,bill,summa;
    string id,name;
    product()
    {
        name="";
        id="";
        cp=0;
        sp=0;
        stock=0;
    }
    product(string a,string b,int c,int d,int e)
    {
        name=a;
        id=b;
        stock=c;
        cp=d;
        sp=e;
    }
    void getdetail()
    {
        cout<<"\n____________________________________\n";
        cout<<"ENTER THE PRODUCT NAME:";
        cin>>name;
        cout<<"ENTER THE PRODUCT ID:";
        cin>>id;
        cout<<"ENTER SELLING PRICE :";
        cin>>sp;
        cout<<"ENTER COST PRICE:";
        cin>>cp;
        cout<<"ENTER TOTAL NUMBER OF STOCKS ADDED:";
        cin>>stock;
    }
    void printdetail()
    {
        cout<<"\n --------------------------------";
        cout<<"\n|PRODUCT NAME  :"<<name               ;
        cout<<"\n|PRODUCT ID    :"<<id                 ;
        cout<<"\n|PRODUCT STOCK :"<<stock              ;
        cout<<"\n|PRODUCT CP    :"<<cp                 ;
        cout<<"\n|PRODUCT SP    :"<<sp                 ;
        cout<<"\n ---------------------------------";
    }
    void billy();
    void editdetail()
	{
	    string bax;
		cout<<"PRODUCT NAME:"<<name;
		cout<<"\nDO YOU WANT TO CHANGE THE STOCKS or PRICE?";
		cin>>bax;
        if(bax == "STOCKS"||"stocks"||"stock"||"STOCK")
        {
		cout<<"\nENTER THE STOCK:";
		cin>>stock;
        }
        else if(bax == "PRICE"||"price")
        {
		cout<<"ENTER THE CP:";
		cin>>cp;
		cout<<"ENTER THE SP:";
		cin>>sp;
        }
        else
        {
        cout<<"\nENTER THE STOCK:";
		cin>>stock;
        cout<<"ENTER THE CP:";
		cin>>cp;
		cout<<"ENTER THE SP:";
		cin>>sp;  
        }
	}
	friend void bill();
};
void product::billy()
    {
        cout<<name<<"\t\t"<<sp<<"\t\t"<<quan<<"\t\t"<<total<<"\n";
    }
int main()
{
    fstream bill;
    fstream save;
    int e=0,n=3,ch,sn=1,i,ch1,h=0,q,net=0,n0,no,cp,sp,stock;
    string user,pass,x,name,id;
    product obj[100];
   time_t now = time(0);
   tm *ltm = localtime(&now);
    obj[1]={"RULLED NOTE","8902901035094",25,40,55};
    obj[2]={"PONDS POWDER","8901030708152",30,10,15};
    obj[3]={"COMFORT BLACK","8901030856341",25,2,4};
    ifstream take("products.txt");
    take>>no;
    n=no;
    for(i=4;i<=no;i++)
    {
        take>>name;
        obj[i].name=name;
        take>>id;
        obj[i].id=id;
        take>>cp;
        obj[i].stock=cp;
        take>>sp;
        obj[i].cp=sp;
        take>>stock;
        obj[i].sp=stock;    
    }
    take.close();
    while(h==0)
    {
    e=0;
    cout<<"****************************";
    cout<<"\n---ENTER EXIT TO QUIT---";
    cout<<"\nENTER USERNAME:";
    cin>>user;
    cout<<"ENTER PASSWORD:";
    cin>>pass;
    cout<<"\n****************************";
    if(pass=="admin123")
    {
     while(e==0)
    {
        cout<<"\n_____________\n\n";
        cout<<"1)PRODUCT DETAILS\n";
        cout<<"2)ADD  PRODUCT\n";
        cout<<"3)EDIT PRODUCT\n";
        cout<<"4)CHECK STOCKS\n";
        cout<<"5)EXIT MAINMENU";
        cout<<"\n_____________\n";
        cout<<"ENTER CHOICE:";
    cin>>ch;
    switch(ch)
    {
        case 1:
        {
            cout<<"enter id";
            cin>>x;
            for(i=1;i<=n;i++)
            {
                try
                {
                if(obj[i].id == x)
                {
                    throw id;
                }
                }
            catch (string id)
            {
                obj[i].printdetail();
            }
            }
        break;
        }
        case 2:
        { 
            n++;
            obj[n].getdetail();
        bill.open("stock.txt",ios::out);
for(i=1;i<=n;i++)
{
	bill<<"\n --------------------------------";
        bill<<"\n|PRODUCT NAME  :"<<obj[i].name               ;
        bill<<"\n|PRODUCT ID    :"<<obj[i].id                 ;
        bill<<"\n|PRODUCT STOCK :"<<obj[i].stock              ;
        bill<<"\n|PRODUCT CP    :"<<obj[i].cp                 ;
        bill<<"\n|PRODUCT SP    :"<<obj[i].sp                 ;
        bill<<"\n ---------------------------------\n";
}
        bill.close(); 
            save.open("products.txt",ios::out);
            save<<n<<"\n";
             for(i=4;i<=n;i++)
             {
              save<<obj[i].name<<" "<<obj[i].id<<" "<< obj[i].stock<<" "<<obj[i].cp<<" "<< obj[i].sp<<"\n"; 
             }
            save.close();
	   break ;
        }
        case 3:
        {
	cout<<"ENTER THE PRODUCT ID :";
	cin>>x;
	for(i=1;i<=n;i++)
	{
		if(x==obj[i].id)
{
		obj[i].editdetail();
}
	}
	bill.open("stock.txt",ios::out);
for(i=1;i<=n;i++)
{
	bill<<"\n --------------------------------";
        bill<<"\n|PRODUCT NAME  :"<<obj[i].name               ;
        bill<<"\n|PRODUCT ID    :"<<obj[i].id                 ;
        bill<<"\n|PRODUCT STOCK :"<<obj[i].stock              ;
        bill<<"\n|PRODUCT CP    :"<<obj[i].cp                 ;
        bill<<"\n|PRODUCT SP    :"<<obj[i].sp                 ;
        bill<<"\n ---------------------------------\n";
}
        bill.close(); 
	 save.open("products.txt",ios::out);
            save<<n<<"\n";
             for(i=4;i<=n;i++)
             {
              save<<obj[i].name<<" "<<obj[i].id<<" "<< obj[i].stock<<" "<<obj[i].cp<<" "<< obj[i].sp<<"\n"; 
             }
            save.close();
            break ;
        }
        case 5:
        {
            e=1;
            break;
        }
        case 4:
        {
            
            cout << string(22, '\n');
            cout<<"-------STOCKS-------";
            for(i=1;i<=n;i++)
            {
                cout<<"\n"<<obj[i].name<<" = "<<obj[i].stock;
            }
            break;
        }
        default:
        {
            cout<<"ENTER A VALID OPTION";
        }
    }
    }    
    }
    else if(pass=="bill123")
    {
    e=0;
    while(e==0)
    { 
        x=1;
        cout<<"\n_____________\n\n";
        cout<<"1)NEW BILL\n";
        cout<<"2)MAINMENU";
        cout<<"\n_____________\n";
        cout<<"ENTER CHOICE:";
        cin>>ch1;
        switch(ch1)
        {
        case 1:
        {
            while(x!="0")
            {
        cout<<"\nENTER ID:";
        cin>>x;
        for(i=1;i<=n;i++)
        {
            if(x==obj[i].id)
            {
                cout<<"ENTER QUANTITY:";
                cin>>obj[i].quan;
                if(obj[i].stock>=obj[i].quan)
                {
                    obj[i].bill=1;
                    obj[i].stock= obj[i].stock-obj[i].quan;
                    obj[i].total=obj[i].quan*obj[i].sp;
                }
                else
                {
                    cout<<"AVAILABLE STOCK IS ONLY:"<<obj[i].stock;
                    cout<<"\nSTOCKS MUST BE ADDED TO"<<obj[i].name;
                }
            }
        }
            }
             save.open("products.txt",ios::out);
            save<<n<<"\n";
             for(i=4;i<=n;i++)
             {
              save<<obj[i].name<<" "<<obj[i].id<<" "<< obj[i].stock<<" "<<obj[i].cp<<" "<< obj[i].sp<<"\n"; 
             }
            save.close();
        cout << string(22, '\n');
        cout << "✸ DATE: "<<ltm->tm_mday<<"/"<< 1 + ltm->tm_mon<<"/"<< 1900 + ltm->tm_year;
        cout<<"\n___________________⫷ ⫸WELCOME TO MEPCO STORE⫷ ⫸__________________\n";
        cout<<"NAME\t\tCOST\t\tQUANTITY\t\tTOTAL\n";
        for(i=1;i<=n;i++)
        {
            if(obj[i].bill==1)
            {
                net=obj[i].total + net;
                obj[i].billy();
            }
        }
        cout<<"\n\t\t\t\t\t___________________";
        cout<<"\n\t\t\t\t\t|                 |";
        cout<<"\n\t\t\t\t\t|NET AMOUNT:"<<net<<"rs";
        cout<<"\n\t\t\t\t\t|_________________|";
        cout<<"\n__________________________THANK YOU__________________________\n\n";
         for(i=1;i<=n;i++)
         {
            obj[i].bill=0;
         }
        break;
        }
        case 2:
        {
            e=1;
            break;
        }
        }
    }
    }
    else if(pass=="exit"||"EXIT")
    {
        cout<<"\nতততততTHANK YOUততততত";
        h=1;
    }
    else
    {
        cout<<"INVALID PASSWORD PLS TRY AGAIN";
    }
    }
    return 0;
}

