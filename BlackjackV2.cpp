//Blackjack.cpp
//Author:Lei Haoruo
 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string> //used to check input.
using namespace std;

double Deal(double a[13][4],int b[],int c[]);
void Show(int a,int b);
void Shuffle(double a[13][4]);
void Player(double a,double b,double c[13][4],int d[],int e[]);
void Computer(double a,double b,double c[13][4],int d[],int e[],int f);
void Judge(double a,double b,int c);
class mistake{};
char Check(); //check input.
int times;

int main()
{	double sum1,sum2,poker[13][4];int ran1[21],ran2[21];char choice;
  
    srand(time(NULL));
    for(;;) //run this game again and again.
    {times=0;ran1[21]=0;ran2[21]=0;sum1=0;sum2=0; //initial values.
    Shuffle(poker);
    Player(sum1,sum2,poker,ran1,ran2);
    cout<<endl<<endl<<"Try again?(y/n)：";choice=Check();
    if(choice=='y'||choice=='Y')continue;
	else if(choice=='n'||choice=='N')break;
    }
    
    return 0;
}

double Deal(double a[13][4],int b[],int c[])
{ 	double value;
  	do{b[times]=rand()%13;c[times]=rand()%4;}
  	while(a[b[times]][c[times]]==0);//make sure to get a different card each time.
  	Show(b[times],c[times]);
  	value=a[b[times]][c[times]];a[b[times]][c[times]]=0;
  	times+=1;
  	
  	return value; //return the number of the card.
}

void Show(int a,int b)//exhibit the figure on the card.
{	switch(b)
  	{case 0:cout<<"Heart";break; case 1:cout<<"Spade";break;
     case 2:cout<<"Club";break; case 3:cout<<"Diamond";break; }
    switch(a)
    {case 9:cout<<'J';break;  case 10:cout<<'Q';break;
     case 11:cout<<'K';break; case 12:cout<<'A';break;
     default:cout<<a+2;}
    cout<<' ';
}
  
void Shuffle(double a[13][4]) // initial the poker set.
{	int i,j;
    for( i=0;i<=8;++i)
  		for( j=0;j<4;++j)
      		a[i][j]=i+2;
  	for(i=9;i<12;++i)
    	for(j=0;j<4;++j) 
	  		a[i][j]=0.5;
 	for(j=0;j<4;++j)
    	a[12][j]=1;
}

void Player(double a,double b,double c[13][4],int d[],int e[])
{ 	char answer;int time_p=2;
  	cout<<"Player Phase:"<<endl<<"Player gets cards:" <<' ' ;
  	a+=Deal(c,d,e); a+=Deal(c,d,e); cout<<endl;
  	while(a<=21){cout<<endl<<"Another card?(y/n)：";
    	answer=Check();if(answer=='n'||answer=='N')break;
    	else if(answer=='y'||answer=='Y'){cout<<"Get another card：";
    		for(int i=0;i<times;++i)Show(d[i],e[i]);
    			a+=Deal(c,d,e);time_p+=1;}}
    			
  	if(a>21){cout<<endl<<"You Fail！";}
  	else Computer(b,a,c,d,e,time_p); 
}

void Computer(double a,double b,double c[13][4],int d[],int e[],int f)
{ 	cout<<endl<<"Computer Phase:"<<endl<<"Computer gets cards:"<<' ';
  	a+=Deal(c,d,e);a+=Deal(c,d,e);
  	while(a<=21&&a<b)
  		{cout<<endl<<"Get another card："; 
   		for(int i=f;i<times;++i)Show(d[i],e[i]);
   		a+=Deal(c,d,e);}
   		
  	if(a>21)cout<<endl<<"You Win!"; 
  	else Judge(a,b,f);
}

void Judge(double a,double b,int c)//make a judgement when sums are equal.
{ 	int d;
  	if(a==b){d=times-c; if(d>c)cout<<endl<<"You Fail！";
  			else {if(c=d)cout<<endl<<"Tie!"; 
			  		else cout<<endl<<"You Win！";} }  
	else cout<<endl<<"You Fail！";
}

char Check()
{	string ans;char answer;
	cin>>ans;  cin.sync();	answer=ans[0];
  	try{if(ans!="y"&&ans!="n"&&ans!="Y"&&ans!="N") 
		throw mistake();}
  	catch(mistake){cout<<"Wrong input!Enter y/Y/n/N"
				   <<endl<<"Try again:"; answer=Check();}
				   
  	return answer;
}

