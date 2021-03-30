#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<string>
#include"WuZiQi.h"
using namespace std;
string W="○";
string B="●";


void WuZiQi::print()
{
	system("cls"); 
		int i,j;
//	int a=1,b=1,c=2;
//	if(!(a==b==c))
	for(j=0; j<=15; j++)
	cout<<setw(6)<<j;
	cout<<endl;
	cout<<setw(9)<<"|";
	for(j=0;j<15;j++)
		cout<<"-----|";
	cout<<endl;
	
	for(i=1;i<=15;i++)
	{	cout<<setw(6)<<i;
		cout<<setw(3)<<"|";
		for(j=1;j<=15;j++)
		{
			cout<<" ";
			if(board[i][j]==0)
				cout<<"  ";
			if(board[i][j]==1)
				cout<<B;
			if(board[i][j]==2)
				cout<<W;
			cout<<"  |";
		}
		cout<<endl;
		
		cout<<setw(9)<<"|";
		for(j=0;j<15;j++)
			cout<<"-----|";
		cout<<endl;
	}
}

bool WuZiQi::judge(int a,int b)
{
	int cnt1=0,cnt2=0,cnt3=0,cnt4=0,cnt5=0,cnt6=0,cnt7=0,cnt8=0;
		
		int A=a-1;
		int B=b-1;
		while(A>=1&&A<=15&&B>=1&&B<=15 &&board[A][B]==board[a][b])  //左上方连子个数 
		{
			cnt1++;
			A-=1;
			B-=1;
		}
		
		A=a+1;
		B=b+1;
		while(A>=1&&A<=15&&B>=1&&B<=15 &&board[A][B]==board[a][b])  //右下方连子个数 
		{
			cnt2++;
			A+=1;
			B+=1;
		}
		
		A=a-1;
		B=b+1;
		while(A>=1&&A<=15&&B>=1&&B<=15 &&board[A][B]==board[a][b])  //右上方连子个数 
		{
			cnt3++;
			A-=1;
			B+=1;
		}
		
		A=a+1;
		B=b-1;
		while(A>=1&&A<=15&&B>=1&&B<=15 &&board[A][B]==board[a][b])  //左下方连子个数 
		{
			cnt4++;
			A+=1;
			B-=1;
		} 
		
		B=b-1;
		A=a;
		while(A>=1&&A<=15&&B>=1&&B<=15 &&board[A][B]==board[a][b])  //左边连子个数 
		{
			cnt5++;
			B-=1;
		}
		
		B=b+1;
		A=a;
		while(A>=1&&A<=15&&B>=1&&B<=15 &&board[A][B]==board[a][b])  //右边连子个数 
		{
			cnt6++;
			B+=1;
		}
		
		A=a-1;
		B=b;
		while(A>=1&&A<=15&&B>=1&&B<=15 &&board[A][B]==board[a][b])  //上方连子个数 
		{
			cnt7++;
			A-=1;	
		}
		
		A=a+1;
		B=b;
		while(A>=1&&A<=15&&B>=1&&B<=15 &&board[A][B]==board[a][b])  //下方连子个数 
		{
			cnt8++;
			A+=1;
		} 
		
		if(cnt1+cnt2>=4 || cnt3+cnt4>=4 || cnt5+cnt6>=4 || cnt7+cnt8>=4)
			return true;
		return false;
}

void WuZiQi::chess(int i,int j,int x)
{
		if(x==1) //玩家执黑子 
			board[i][j]=1; //黑子标识为1	 
		else if(x==2)
			board[i][j]=2;  //白子标识为2
}

int WuZiQi::PG1(int a,int b,int x)
{
	chess(a,b,x);
	int cnt1=0;
	int flag1=1;	
		
		int A=a-1;
		int B=b-1;
		while(A>=1&&A<=15&&B>=1&&B<=15 &&board[A][B]==board[a][b])  //左上方连子个数 
		{
			cnt1++;
			A-=1;
			B-=1;
		}
		if( A>=1 && A<=15 && B>=1 && B<=15 && board[A][B]==0 )
				flag1=2;
	board[a][b]=0;		 
	return flag1*10+cnt1;  //将要返回的两个数据做成一个二位数! 
}
int WuZiQi::PG2(int a,int b,int x)
{
	chess(a,b,x);
	int cnt1=0;
	int flag1=1;	
		
		int A=a+1;
		int B=b+1;
		while(A>=1&&A<=15&&B>=1&&B<=15 &&board[A][B]==board[a][b])  //右下方连子个数 
		{
			cnt1++;
			A+=1;
			B+=1;
		}
		if( A>=1 && A<=15 && B>=1 && B<=15 && board[A][B]==0 )
				flag1=2;
		board[a][b]=0;		 
		return flag1*10+cnt1;  //将要返回的两个数据做成一个二位数!
}
int WuZiQi::PG3(int a,int b,int x)
{
	chess(a,b,x);
	int cnt1=0;
	int flag1=1;
	
	    int A=a-1;
		int B=b+1;
		while(A>=1&&A<=15&&B>=1&&B<=15 &&board[A][B]==board[a][b])  //右上方连子个数 
		{
			cnt1++;
			A-=1;
			B+=1;
		}
		if( A>=1 && A<=15 && B>=1 && B<=15 && board[A][B]==0 )
				flag1=2;
	board[a][b]=0;			
	return flag1*10+cnt1;
}
int WuZiQi::PG4(int a,int b,int x)
{
	chess(a,b,x);
	int cnt1=0;
	int flag1=1;
	
	int	A=a+1;
	int	B=b-1;
		while(A>=1&&A<=15&&B>=1&&B<=15 &&board[A][B]==board[a][b])  //左下方连子个数 
		{
			cnt1++;
			A+=1;
			B-=1;
		} 
		if( A>=1 && A<=15 && B>=1 && B<=15 && board[A][B]==0 )
				flag1=2;
	board[a][b]=0;
		return flag1*10+cnt1;
}
int WuZiQi::PG5(int a,int b,int x)
{
	chess(a,b,x);
	int cnt1=0;
	int flag1=1;
	
	int	B=b-1;
	int	A=a;
		while(A>=1&&A<=15&&B>=1&&B<=15 && board[A][B]==board[a][b])  //左边连子个数 
		{
			cnt1++;
			B-=1;
		}
		if( A>=1 && A<=15 && B>=1 && B<=15 && board[A][B]==0 )
			flag1=2;
		board[a][b]=0;
		return flag1*10+cnt1;
}
int WuZiQi::PG6(int a,int b,int x)
{
	chess(a,b,x);
	int cnt1=0;
	int flag1=1;
	
	int	B=b+1;
	int	A=a;
		while(A>=1&&A<=15&&B>=1&&B<=15 &&board[A][B]==board[a][b])  //右边连子个数 
		{
			cnt1++;
			B+=1;
		}
		if( A>=1 && A<=15 && B>=1 && B<=15 && board[A][B]==0 )
			flag1=2;
	
	board[a][b]=0;
	return flag1*10+cnt1;
}
int WuZiQi::PG7(int a,int b,int x)
{
	chess(a,b,x);
	int cnt1=0;
	int flag1=1;
	
	int	A=a-1;
	int	B=b;
		while(A>=1&&A<=15&&B>=1&&B<=15 &&board[A][B]==board[a][b])  //上方连子个数 
		{
			cnt1++;
			A-=1;	
		}
		if( A>=1 && A<=15 && B>=1 && B<=15 && board[A][B]==0 )
			flag1=2;
			
		board[a][b]=0;
		return flag1*10+cnt1;
}
int WuZiQi::PG8(int a,int b,int x)
{
		chess(a,b,x);
	int cnt1=0;
	int flag1=1;
	
	int	A=a+1;
	int	B=b;
		while(A>=1&&A<=15&&B>=1&&B<=15 &&board[A][B]==board[a][b])  //下方连子个数 
		{
			cnt1++;
			A+=1;
		} 
		if( A>=1 && A<=15 && B>=1 && B<=15 && board[A][B]==0 )
			flag1=2;
			
	board[a][b]=0;
	return flag1*10+cnt1;
}

void WuZiQi::play(int flag)
{
	if(flag==1)
	{
		int a,b;
		cout<<"执黑下棋!请输入要下棋的位置:";
		cin>>a>>b;
		while(a<1 || a>15 || b<1 || b>15 || board[a][b]!=0 )  //输入有效性检测! 
		{
			cout<<"输入错误位置!请重新输入:";
			cin>>a>>b;
		}
		
		chess(a,b,1);
		
		if(judge(a,b))
		{
			cout<<"执黑胜利!\n";
			return;
		}  
		
		AI(2);
		
		print();
		
		for(a=1;a<=15;a++)
			for(b=1;b<=15;b++)
			{
				if(board[a][b]==2)
					if(judge(a,b))
					{
						cout<<"电脑胜利!\n";
						return;
					}
			}
		
		play(flag);
	}
	else if(flag==2)
	{
		int a,b;
		AI(1);
		
		print();
		
		for(a=1;a<=15;a++)
			for(b=1;b<=15;b++)
			{
				if(board[a][b]==1)
					if(judge(a,b))
					{
						cout<<"电脑胜利!\n";
						return;
					}
			}
			
		cout<<"执白下棋!请输入要下棋的位置:";
		cin>>a>>b;
		while(a<1 || a>15 || b<1 || b>15 || board[a][b]!=0 )  //输入有效性检测! 
		{
			cout<<"输入错误位置!请重新输入:";
			cin>>a>>b;
		}
		
		chess(a,b,2);
		
		if(judge(a,b))
		{
			cout<<"执白胜利!\n";
			return;
		}  
		play(flag);
	}
}

int WuZiQi::GZ(int a,int b,int x)
{
	int grades=0;
	int cw1=CW(a,b,x),hs1=HS(a,b,x),ss1=SS(a,b,x),lhs1=LHS(a,b,x),ths1=THS(a,b,x),lhe1=LHE(a,b,x),the1=THE(a,b,x),dthe1=DTHE(a,b,x),se1=SE(a,b,x),dz1=DZ(a,b,x),ww1=WW(a,b,x);
	int cw2=CW(a,b,3-x),hs2=HS(a,b,3-x),ss2=SS(a,b,3-x),lhs2=LHS(a,b,3-x),ths2=THS(a,b,3-x),lhe2=LHE(a,b,3-x),the2=THE(a,b,3-x),dthe2=DTHE(a,b,3-x),se2=SE(a,b,3-x),dz2=DZ(a,b,3-x),ww2=WW(a,b,3-x);
	if(cw1==1)
		grades+=13000;
		
	if(cw2==1)
		grades+=5000;
		
	if(hs1>=1)
		grades+=1200;
		
	if(hs2>=1)
		grades+=1100;
		
	if(ss1==2)
		grades+=1200;
	
	if(ww1==2)
		grades+=1200;
		
	if(ss2==2)
		grades+=1100;
		
	if(ww2==2)
		grades+=1200;
		
	if(ss1==1 && lhs1==1)
		grades+=1000;
		
	if(ww1==1 && lhs1==1)
		grades+=1000;
		
	if(ss2==1 && lhs2==1)
		grades+=900;
	
	if(ww2==1 && lhs2==1)
		grades+=900;
			
	if(ss1==1 && ths1==1)
		grades+=950;
	
	if(ww1==1 && ths1==1)
		grades+=950;
		
	if(ss2==1 && ths2==1)
		grades+=850;
	
	if(ww2==1 && ths2==1)
		grades+=850; 
		
	if(lhs1>=2)
		grades+=750;
		
	if(lhs2>=2)
		grades+=650;
			
	if(lhs1==1 && ths1==1)
		grades+=700;
	
	if(lhs2==1 && ths2==1)
		grades+=600;
			
	if( ths1>=2 )
		grades+=650;
	
	if( ths2>=2)
		grades+=550;
		
	grades+=lhs1*10 + lhs2*8+ ths1*7 +ths2*5 + lhe1*4 + lhe2*2 + the1*3  + dthe1*2 + dz1*0.5;
	
	
//	if(x==1)
//		cout<<a<<" "<<b<<"\t"<<"黑子"<<":"<<ths<<' '<<lhe<<' '<<the<<' '<<dthe<<' '<<dz<<' '<<grades<<endl;
	return grades;
}

void WuZiQi::AI(int t)  //1表示执黑子,2表示执白子. 
{
	
	int i,j,m,n,flag=0; 
	for(i=1;i<=15;i++)
		for(j=1;j<=15;j++)
			if( board[i][j] != 0 )
				flag=1;
	if(flag==0)
		chess(8,8,t);
	else if(flag==1)
	{
		for(i=1;i<=15;i++)  //
		{
			for(j=1;j<=15;j++)
			{
					if(board[i][j]!=0)
						{
							GradeDN[i][j]=0;
						}
					else if(board[i][j]==0)
						{
							GradeDN[i][j]=GZ(i,j,t);
						}
			}
		}
		int X=1,Y=1;	
			for(i=1;i<=15;i++) 
				for(j=1;j<=15;j++)
					if(GradeDN[i][j]>=GradeDN[X][Y])
						{
							X=i;
							Y=j;
						}
		chess(X,Y,t);
	}
}
		

int WuZiQi::CW(int a,int b,int x) //成五
{
	int cnt=0;
	int cnt1=PG1(a,b,x)%10,flag1=PG1(a,b,x)/10,cnt2=PG2(a,b,x)%10,flag2=PG2(a,b,x)/10,cnt3=PG3(a,b,x)%10,flag3=PG3(a,b,x)/10,cnt4=PG4(a,b,x)%10,flag4=PG4(a,b,x)/10	;
	int cnt5=PG5(a,b,x)%10,flag5=PG5(a,b,x)/10,cnt6=PG6(a,b,x)%10,flag6=PG6(a,b,x)/10,cnt7=PG7(a,b,x)%10,flag7=PG7(a,b,x)/10,cnt8=PG8(a,b,x)%10,flag8=PG8(a,b,x)/10	;
	if(cnt1+cnt2>=4)
		cnt++;
	if(cnt3+cnt4>=4)
		cnt++;
	if(cnt5+cnt6>=4)
		cnt++;
	if(cnt7+cnt8>=4) 
		cnt++;
	return cnt;
}
	 
int WuZiQi::HS(int a,int b,int x)	//活四 个数
{
	int cnt=0;
	int cnt1=PG1(a,b,x)%10,flag1=PG1(a,b,x)/10,cnt2=PG2(a,b,x)%10,flag2=PG2(a,b,x)/10,cnt3=PG3(a,b,x)%10,flag3=PG3(a,b,x)/10,cnt4=PG4(a,b,x)%10,flag4=PG4(a,b,x)/10	;
	int cnt5=PG5(a,b,x)%10,flag5=PG5(a,b,x)/10,cnt6=PG6(a,b,x)%10,flag6=PG6(a,b,x)/10,cnt7=PG7(a,b,x)%10,flag7=PG7(a,b,x)/10,cnt8=PG8(a,b,x)%10,flag8=PG8(a,b,x)/10	;
	if( cnt1+cnt2==3&&flag1==2&&flag2==2 )
		cnt++;
	if( cnt3+cnt4==3&&flag3==2&&flag4==2)
		cnt++;
	if( cnt5+cnt6==3&&flag5==2&&flag6==2)
		cnt++;
	if( cnt7+cnt8==3&&flag7==2&&flag8==2)
		cnt++;	
	return cnt;
}
int WuZiQi::SS(int a,int b,int x)	//死四 个数
{
	int cnt=0;
	int cnt1=PG1(a,b,x)%10,flag1=PG1(a,b,x)/10,cnt2=PG2(a,b,x)%10,flag2=PG2(a,b,x)/10,cnt3=PG3(a,b,x)%10,flag3=PG3(a,b,x)/10,cnt4=PG4(a,b,x)%10,flag4=PG4(a,b,x)/10	;
	int cnt5=PG5(a,b,x)%10,flag5=PG5(a,b,x)/10,cnt6=PG6(a,b,x)%10,flag6=PG6(a,b,x)/10,cnt7=PG7(a,b,x)%10,flag7=PG7(a,b,x)/10,cnt8=PG8(a,b,x)%10,flag8=PG8(a,b,x)/10	;
	if( cnt1+cnt2==3&&flag1*flag2==2 )
		cnt++;
	if( cnt3+cnt4==3&&flag3*flag4==2)
		cnt++;
	if( cnt5+cnt6==3&&flag5*flag6==2)
		cnt++;
	if( cnt7+cnt8==3&&flag7*flag8==2)
		cnt++;	
	return cnt;
}
int WuZiQi::LHS(int a,int b,int x)	//连活三 个数
{
	int cnt=0;
	int cnt1=PG1(a,b,x)%10,flag1=PG1(a,b,x)/10,cnt2=PG2(a,b,x)%10,flag2=PG2(a,b,x)/10,cnt3=PG3(a,b,x)%10,flag3=PG3(a,b,x)/10,cnt4=PG4(a,b,x)%10,flag4=PG4(a,b,x)/10	;
	int cnt5=PG5(a,b,x)%10,flag5=PG5(a,b,x)/10,cnt6=PG6(a,b,x)%10,flag6=PG6(a,b,x)/10,cnt7=PG7(a,b,x)%10,flag7=PG7(a,b,x)/10,cnt8=PG8(a,b,x)%10,flag8=PG8(a,b,x)/10	;
	if( cnt1+cnt2==2&&flag1==2&&flag2==2 )
		cnt++;
	if( cnt3+cnt4==2&&flag3==2&&flag4==2)
		cnt++;
	if( cnt5+cnt6==2&&flag5==2&&flag6==2)
		cnt++;
	if( cnt7+cnt8==2&&flag7==2&&flag8==2)
		cnt++;
	return cnt;
}

int WuZiQi::THS(int a,int b,int x)  //跳活三 
{
	int cnt=0;
	chess(a,b,x);
	if(a-4>=1 && b-4>=1 && a+1<=15 && b+1<=15 && board[a-1][b-1]==0 && board[a-2][b-2]==board[a][b] && board[a-3][b-3]==board[a][b]&& board[a-4][b-4]==0 && board[a+1][b+1]==0 ) //左上方跳活三 
			cnt++;
	if(a-4>=1 && b+4<=15 &&a+1<=15 && b-1>=1 && board[a-1][b+1]==0 && board[a-2][b+2]==board[a][b] && board[a-3][b+3]==board[a][b] && board[a-4][b+4]==0 && board[a+1][b-1]==0) //右上方
			cnt++;
	if( a+4<=15 && b-4>=1 && a-1>=1 &&b+1<=15 && board[a+1][b-1]==0 && board[a+2][b-2]==board[a][b] && board[a+3][b-3]==board[a][b] && board[a+4][b-4]==0 && board[a-1][b+1]==0)//左下方 
			cnt++;
	if( a+4<=15 && b+4<=15 && a-1>=1 && b-1>=1 && board[a+1][b+1]==0 && board[a+2][b+2]==board[a][b] && board[a+3][b+3]==board[a][b] && board[a+4][b+4]==0 && board[a-1][b-1]==0) //右下方 
			cnt++;
	if( b-4>=1 && b+1<=15 && board[a][b-1]==0 && board[a][b-2]==board[a][b] && board[a][b-3]==board[a][b] && board[a][b-4]==0 && board[a][b+1]==0)  //左边 
			cnt++;
	if( b+4<=15 && b-1>=1 &&board[a][b+1]==0 && board[a][b+2]==board[a][b] && board[a][b+3]==board[a][b] && board[a][b+4]==0 && board[a][b-1]==0) //右边 
			cnt++;
	if( a-4>=1 && a+1<=15 && board[a-1][b]==0 && board[a-2][b]==board[a][b] && board[a-3][b]==board[a][b] && board[a-4][b]==0 && board[a+1][b]==0) //上边 
			cnt++;
	if( a+4<=15 && a-1>=1 && board[a+1][b]==0 && board[a+2][b]==board[a][b] && board[a+3][b]==board[a][b] && board[a+4][b]==0 && board[a-1][b]==0)  //下边 
			cnt++;
			
	
	if(a-4>=1 && b-4>=1 && a+1<=15 && b+1<=15 && board[a-1][b-1]==board[a][b] && board[a-2][b-2]==0 && board[a-3][b-3]==board[a][b] && board[a-4][b-4]==0 && board[a+1][b+1]==0) //左上方跳活三 
			cnt++;
	if(a-4>=1 && b+4<=15 &&a+1<=15 && b-1>=1 && board[a-1][b+1]==board[a][b] && board[a-2][b+2]==0 && board[a-3][b+3]==board[a][b] && board[a-4][b+4]==0 && board[a+1][b-1]==0) //右上方
			cnt++;
	if( a+4<=15 && b-4>=1 && a-1>=1 &&b+1<=15 && board[a+1][b-1]==board[a][b] && board[a+2][b-2]==0 && board[a+3][b-3]==board[a][b] && board[a+4][b-4]==0 && board[a-1][b+1]==0)//左下方 
			cnt++;
	if( a+4<=15 && b+4<=15 && a-1>=1 && b-1>=1 && board[a+1][b+1]==board[a][b] && board[a+2][b+2]==0 && board[a+3][b+3]==board[a][b] && board[a+4][b+4]==0 && board[a-1][b-1]==0) //右下方 
			cnt++;
	if( b-4>=1 && b+1<=15 && board[a][b-1]==board[a][b] && board[a][b-2]==0 && board[a][b-3]==board[a][b] && board[a][b-4]==0 && board[a][b+1]==0)  //左边 
			cnt++;
	if( b+4<=15 && b-1>=1 && board[a][b+1]==board[a][b] && board[a][b+2]==0 && board[a][b+3]==board[a][b] && board[a][b+4]==0 && board[a][b-1]==0) //右边 
			cnt++;
	if( a-4>=1 && a+1<=15 && board[a-1][b]==board[a][b] && board[a-2][b]==0 && board[a-3][b]==board[a][b] && board[a-4][b]==0 && board[a+1][b]==0) //上边 
			cnt++;
	if( a+4<=15 &&  a-1>=1 && board[a+1][b]==board[a][b] && board[a+2][b]==0 && board[a+3][b]==board[a][b] && board[a+4][b]==0 && board[a-1][b]==0)  //下边 
			cnt++;
			
	if( a-2>=1 && b-2>=1 && a+3<=15 && b+3<=15 && board[a-2][b-2]==0 && board[a-1][b-1]==board[a][b] && board[a+1][b+1]==0 && board[a+2][b+2]==board[a][b] && board[a+3][b+3]==0 )
			cnt++;
	if( a-2>=1 && b+2<=15 && a+3<=15 && b-3>=1 && board[a-2][b+2]==0 && board[a-1][b+1]==board[a][b] && board[a+1][b-1]==0 && board[a+2][b-2]==board[a][b] && board[a+3][b-3]==0 )
			cnt++;
	if( a+2<=15 && b-2>=1 && a-3>=1 && b+3<=15 && board[a+2][b-2]==0 &&board[a+1][b-1]==board[a][b] && board[a-1][b+1]==0 && board[a-2][b+2]==board[a][b] && board[a-3][b+3]==0)
			cnt++;
	if( a+2<=15 && b+2<=15 && a-3>=1 && b-3>=1 && board[a+2][b+2]==0 && board[a+1][b+1]==board[a][b] && board[a-1][b-1]==0 && board[a-2][b-2]==board[a][b] && board[a-3][b-3]==0)
			cnt++;
	if( b-2>=1 && b+3<=15 && board[a][b-2]==0 && board[a][b-1]==board[a][b] && board[a][b+1]==0 && board[a][b+2]==board[a][b] && board[a][b+3]==0)
			cnt++;
	if( b+2<=15 && b-3>=1 &&board[a][b+2]==0 &&board[a][b+1]==board[a][b] && board[a][b-1]==0 &&board[a][b-2]==board[a][b] && board[a][b-3]==0)
			cnt++;
	if( a-2>=1 && a+3<=15 && board[a-2][b]==0 && board[a-1][b]==board[a][b] && board[a+1][b]==0 && board[a+2][b]==board[a][b] && board[a+3][b]==0)
			cnt++;
	if( a+2<=15 && a-3>=1 &&board[a+2][b]==0 && board[a+1][b]==board[a][b] && board[a-1][b]==0 && board[a-2][b]==board[a][b] && board[a-3][b]==0)
			cnt++;	
	board[a][b]==0;
	return cnt;
}

int WuZiQi::LHE(int a,int b,int x)	//连活二 个数
{
	int cnt=0;
	int cnt1=PG1(a,b,x)%10,flag1=PG1(a,b,x)/10,cnt2=PG2(a,b,x)%10,flag2=PG2(a,b,x)/10,cnt3=PG3(a,b,x)%10,flag3=PG3(a,b,x)/10,cnt4=PG4(a,b,x)%10,flag4=PG4(a,b,x)/10	;
	int cnt5=PG5(a,b,x)%10,flag5=PG5(a,b,x)/10,cnt6=PG6(a,b,x)%10,flag6=PG6(a,b,x)/10,cnt7=PG7(a,b,x)%10,flag7=PG7(a,b,x)/10,cnt8=PG8(a,b,x)%10,flag8=PG8(a,b,x)/10	;
	if( cnt1+cnt2==1 && flag1==2 && flag2==2 )
		cnt++;
	if( cnt3+cnt4==1 &&  flag3==2 && flag4==2 )
		cnt++;
	if( cnt5+cnt6==1 &&  flag5==2 && flag6==2 )
		cnt++;
	if( cnt7+cnt8==1 &&  flag7==2 && flag8==2 )
		cnt++;	
	return cnt;
}
int WuZiQi::THE(int a,int b,int x)
{
	int cnt=0;
	chess(a,b,x);
	if(a-3>=1 && b-3>=1 && a+1<=15 && b+1<=15 && board[a-1][b-1]==0 && board[a-2][b-2]==board[a][b] && board[a-3][b-3]==0 && board[a+1][b+1]==0) //左上方跳活二 
			cnt++;
	if(a-3>=1 && b+3<=15 && a+1<=15 && b-1>=1 && board[a-1][b+1]==0 && board[a-2][b+2]==board[a][b] && board[a-3][b+3]==0 && board[a+1][b-1]==0) //右上方
			cnt++;
	if( a+3<=15 && b-3>=1 && a-1>=1 && b+1<=15 && board[a+1][b-1]==0 && board[a+2][b-2]==board[a][b] && board[a+3][b-3]==0 && board[a-1][b+1]==0)//左下方 
			cnt++;
	if( a+3<=15 && b+3<=15 && a-1>=1 && b-1>=1 && board[a+1][b+1]==0 && board[a+2][b+2]==board[a][b] && board[a+3][b+3]==0 && board[a-1][b-1]==0) //右下方 
			cnt++;
	if( b-3>=1 && b+1<=15 && board[a][b-1]==0 && board[a][b-2]==board[a][b] && board[a][b-3]==0 && board[a][b+1]==0 )  //左边 
			cnt++;
	if( b+3<=15 && b-1>=1 && board[a][b+1]==0 && board[a][b+2]==board[a][b] && board[a][b+3]==0 && board[a][b-1]==0) //右边 
			cnt++;
	if( a-3>=1 && a+1<=15 && board[a-1][b]==0 && board[a-2][b]==board[a][b] && board[a-3][b]==0 && board[a+1][b]==0) //上边 
			cnt++;
	if( a+3<=15 && a-1>=1 && board[a+1][b]==0 && board[a+2][b]==board[a][b] && board[a+3][b]==0 && board[a-1][b]==0)  //下边 
			cnt++;
	board[a][b]==0;
	return cnt;
}

int WuZiQi::DTHE(int a,int b,int x)
{
		int cnt=0;
		chess(a,b,x);
		if(a-4>=1 && b-4>=1 && a+1<=15 && b+1<=15 && board[a-1][b-1]==0 && board[a-2][b-2]==0 && board[a-3][b-3]==board[a][b] && board[a-4][b-4]==0 && board[a+1][b+1]==0) //左上方大跳活二 
			cnt++;
		if(a-4>=1 && b+4<=15 && a+1<=15 && b-1>=1 && board[a-1][b+1]==0 && board[a-2][b+2]==0 && board[a-3][b+3]==board[a][b] && board[a-4][b+4]==0 && board[a+1][b-1]==0) //右上方
			cnt++;
		if( a+4<=15 && b-4>=1 && a-1>=1 && b+1<=15 && board[a+1][b-1]==0 && board[a+2][b-2]==0 && board[a+3][b-3]==board[a][b] && board[a+4][b-4]==0 && board[a-1][b+1]==0)//左下方 
			cnt++;
		if( a+4<=15 && b+4<=15 && a-1>=1 && b-1>=1 && board[a+1][b+1]==0 && board[a+2][b+2]==0 && board[a+3][b+3]==board[a][b] && board[a+4][b+4]==0 && board[a-1][b-1]==0) //右下方 
			cnt++;
		if( b-4>=1 && b+1<=15 && board[a][b-1]==0 && board[a][b-2]==0 && board[a][b-3]==board[a][b] && board[a][b-4]==0 && board[a][b+1]==0)  //左边 
			cnt++;
		if( b+4<=15 && b-1>=1 && board[a][b+1]==0 && board[a][b+2]==0 && board[a][b+3]==board[a][b] && board[a][b+4]==0 && board[a][b-1]==0) //右边 
			cnt++;
		if( a-4>=1 && a+1<=15 && board[a-1][b]==0 && board[a-2][b]==0 && board[a-3][b]==board[a][b] && board[a-4][b]==0 && board[a+1][b]==0) //上边 
			cnt++;
		if( a+4<=15 && a-1>=1 && board[a+1][b]==0 && board[a+2][b]==0 && board[a+3][b]==board[a][b] && board[a+4][b]==0 && board[a-1][b]==0)  //下边 
			cnt++;
		board[a][b]=0;
		return cnt;
}

int WuZiQi::SE(int a,int b,int x) //死二 
{
	int cnt=0;
	int cnt1=PG1(a,b,x)%10,flag1=PG1(a,b,x)/10,cnt2=PG2(a,b,x)%10,flag2=PG2(a,b,x)/10,cnt3=PG3(a,b,x)%10,flag3=PG3(a,b,x)/10,cnt4=PG4(a,b,x)%10,flag4=PG4(a,b,x)/10	;
	int cnt5=PG5(a,b,x)%10,flag5=PG5(a,b,x)/10,cnt6=PG6(a,b,x)%10,flag6=PG6(a,b,x)/10,cnt7=PG7(a,b,x)%10,flag7=PG7(a,b,x)/10,cnt8=PG8(a,b,x)%10,flag8=PG8(a,b,x)/10	;
	if( cnt1+cnt2==1&&flag1*flag2==2 )
		cnt++;
	if( cnt3+cnt4==1&&flag3*flag4==2)
		cnt++;
	if( cnt5+cnt6==1&&flag5*flag6==2)
		cnt++;
	if( cnt7+cnt8==1&&flag7*flag8==2)
		cnt++;	
	return cnt;
} 
int WuZiQi::DZ(int a,int b,int x) //单子 
{
	int cnt=0;
	int cnt1=PG1(a,b,x)%10,flag1=PG1(a,b,x)/10,cnt2=PG2(a,b,x)%10,flag2=PG2(a,b,x)/10,cnt3=PG3(a,b,x)%10,flag3=PG3(a,b,x)/10,cnt4=PG4(a,b,x)%10,flag4=PG4(a,b,x)/10	;
	int cnt5=PG5(a,b,x)%10,flag5=PG5(a,b,x)/10,cnt6=PG6(a,b,x)%10,flag6=PG6(a,b,x)/10,cnt7=PG7(a,b,x)%10,flag7=PG7(a,b,x)/10,cnt8=PG8(a,b,x)%10,flag8=PG8(a,b,x)/10	;
	if( (cnt1+cnt2==0&&flag1==2&&flag2==2 ) && (cnt3+cnt4==0&&flag3==2 &&flag4==2) && (cnt5+cnt6==0&&flag5==2 && flag6==2 ) && (cnt7+cnt8==0&&flag7==2 && flag8==2))
		cnt++;	
	return cnt;
} 

int WuZiQi::WW(int a,int b,int x)
{
		int cnt=0;
		chess(a,b,x);
		if( (a-4>=1 && b-4>=1 && board[a-1][b-1]==0 && board[a-2][b-2]==board[a][b] && board[a-3][b-3]==board[a][b] && board[a-4][b-4]==board[a][b] ) || (a-4>=1 && b-4>=1 && board[a-1][b-1]==board[a][b] && board[a-2][b-2]==board[a][b] && board[a-3][b-3]==0 && board[a-4][b-4]==board[a][b])  || (a-1>=1 && b-1>=1 && a+3<=15 && b+3<=15 && board[a-1][b-1]==board[a][b] && board[a+1][b+1]==board[a][b] && board[a+2][b+2]==0 && board[a+3][b+3]==board[a][b] ) || (a-2>=1 && b-2>=1 && a+2<=15 && b+2<=15 && board[a-2][b-2]==board[a][b] && board[a-1][b-1]==board[a][b] && board[a+1][b+1]==0 && board[a+2][b+2]==board[a][b])  || (a-4>=1 && b-4>=1 && board[a-1][b-1]==board[a][b] && board[a-2][b-2]==0 && board[a-3][b-3]==board[a][b] && board[a-4][b-4]==board[a][b] ) || (a-3>=1 && b-3>=1 && a+1<=15 && b+1<=15 && board[a-1][b-1]==0 && board[a-2][b-2]==board[a][b] && board[a-3][b-3]==board[a][b] && board[a+1][b+1]==board[a][b] ) )//左上方大跳活二 
			cnt++;
		if( (a-4>=1 && b+4<=15 && board[a-1][b+1]==0 && board[a-2][b+2]==board[a][b] && board[a-3][b+3]==board[a][b] && board[a-4][b+4]==board[a][b] ) || (a-4>=1 && b+4<=15 && board[a-1][b+1]==board[a][b] && board[a-2][b+2]==board[a][b] && board[a-3][b+3]==0 && board[a-4][b+4]==board[a][b] ) || ( a-1>=1 && b+1<=15 && a+3<=15 && b-3>=1 && board[a-1][b+1]==board[a][b] && board[a+1][b-1]==board[a][b] && board[a+2][b+2]==0 && board[a+3][b+3]==board[a][b]) || (a-2>=1 && b+2<=15 && a+2<=15 && b-2>=1 && board[a-2][b+2]==board[a][b] && board[a-1][b+1]==board[a][b] && board[a+1][b-1]==0 && board[a+2][b-2]==board[a][b] ) || (a-4>=1 && b+4<=15 && board[a-1][b+1]==board[a][b] && board[a-2][b+2]==0 && board[a-3][b+3]==board[a][b] && board[a-4][b+4]==board[a][b] ) || (a-3>=1 && b+3<=15 && a+1<=15 && b-1>=1 && board[a-1][b+1]==0 && board[a-2][b+2]==board[a][b] && board[a-3][b+3]==board[a][b] && board[a+1][b-1]==board[a][b] ) )//右上方
			cnt++;
		if( (a+4<=15 && b-4>=1 && board[a+1][b-1]==0 && board[a+2][b-2]==board[a][b] && board[a+3][b-3]==board[a][b] && board[a+4][b-4]==board[a][b] ) || (a+4<=15 && b-4>=1 && board[a+1][b-1]==board[a][b] && board[a+2][b-2]==board[a][b] && board[a+3][b-3]==0 && board[a+4][b-4]==board[a][b] ) || (a+1<=15 && b-1>=1 && a-3>=1 && b+3<=15 && board[a+1][b-1]==board[a][b] && board[a-1][b+1]==board[a][b] && board[a-2][b+2]==0 && board[a-3][b+3]==board[a][b] ) || (a+2<=15 && b-2>=1 && a-2>=1 && b+2<=15 && board[a+2][b-2]==board[a][b] &&board[a+1][b-1]==board[a][b] && board[a-1][b+1]==0 && board[a-2][b+2]==board[a][b] ) || (a+4<=15 && b-4>=1 && board[a+1][b-1]==board[a][b] && board[a+2][b-2]==0 && board[a+3][b-3]==board[a][b] && board[a+4][b-4]==board[a][b] ) || (a+3<=15 && b-3>=1 && a-1>=1 && b+1<=15 && board[a+1][b-1]==0 && board[a+2][b-2]==board[a][b] && board[a+3][b-3]==board[a][b] && board[a-1][b+1]==board[a][b] ) )//左下方 
			cnt++;
		if( ( a+4<=15 && b+4<=15 && board[a+1][b+1]==0 && board[a+2][b+2]==board[a][b]&& board[a+3][b+3]==board[a][b] && board[a+4][b+4]==board[a][b] ) || (a+4<=15 && b+4<=15 && board[a+1][b+1]==board[a][b] && board[a+2][b+2]==board[a][b]&& board[a+3][b+3]==0 && board[a+4][b+4]==board[a][b] ) || (  a+1<=15 && b+1<=15 && a-3>=1 && b-3>=1 && board[a+1][b+1]==board[a][b] && board[a-1][b-1]==board[a][b] && board[a+2][b+2]==0 && board[a+3][b+3]==board[a][b]) || (a+2<=15 && b+2<=15 && a-2>=1 && b-2>=1 && board[a+2][b+2]==board[a][b] && board[a+1][b+1]==board[a][b] && board[a-1][b-1]==0 && board[a-2][b-2]==board[a][b] ) || (a+4<=15 && b+4<=15 && board[a+1][b+1]==board[a][b] && board[a+2][b+2]==0 && board[a+3][b+3]==board[a][b] && board[a+4][b+4]==board[a][b] ) || (a+3<=15 && b+3<=15 && a-1>=1 && b-1>=1 && board[a+1][b+1]==0 && board[a+2][b+2]==board[a][b] && board[a+3][b+3]==board[a][b] && board[a-1][b-1]==board[a][b] ) ) //右下方 
			cnt++;
		if( (b-4>=1 && board[a][b-1]==0 && board[a][b-2]==board[a][b] && board[a][b-3]==board[a][b] && board[a][b-4]==board[a][b] ) || (b-4>=1 && board[a][b-1]==board[a][b] && board[a][b-2]==board[a][b] && board[a][b-3]==0 && board[a][b-4]==board[a][b] ) ||( b-1>=1 && b+3<=15 && board[a][b-1]==board[a][b] && board[a][b+1]==board[a][b] && board[a][b+2]==0 && board[a][b+3]==board[a][b]) || (b-2>=1 && b+2<=15 && board[a][b-2]==board[a][b] && board[a][b-1]==board[a][b] && board[a][b+1]==0 && board[a][b+2]==board[a][b] ) || ( b-4>=1 && board[a][b-1]==board[a][b] && board[a][b-2]==0 && board[a][b-3]==board[a][b] && board[a][b-4]==board[a][b]) || (b-3>=1 && b+1<=15 && board[a][b-1]==0 && board[a][b-2]==board[a][b] && board[a][b-3]==board[a][b] && board[a][b+1]==board[a][b] ) )  //左边 
			cnt++;
		if( (b+4<=15 && board[a][b+1]==0 && board[a][b+2]==board[a][b] && board[a][b+3]==board[a][b] && board[a][b+4]==board[a][b] ) || (b+4<=15 && board[a][b+1]==board[a][b] && board[a][b+2]==board[a][b] && board[a][b+3]==0 && board[a][b+4]==board[a][b] ) || ( b+1<=15 && b-3>=1 && board[a][b+1]==board[a][b] && board[a][b-1]==board[a][b] && board[a][b-2]==0 && board[a][b-3]==board[a][b]) || (  b+2<=15 && b-2>=1 &&board[a][b+2]==board[a][b] &&board[a][b+1]==board[a][b] && board[a][b-1]==0 &&board[a][b-2]==board[a][b]) || ( b+4<=15 && board[a][b+1]==board[a][b] && board[a][b+2]==0 && board[a][b+3]==board[a][b] && board[a][b+4]==board[a][b]) || ( b+3<=15 && b-1>=1 && board[a][b+1]==0 && board[a][b+2]==board[a][b] && board[a][b+3]==board[a][b] && board[a][b-1]==board[a][b])  ) //右边 
			cnt++;
		if( (a-4>=1 && board[a-1][b]==0 && board[a-2][b]==board[a][b] && board[a-3][b]==board[a][b] && board[a-4][b]==board[a][b] ) || (a-4>=1 && board[a-1][b]==board[a][b] && board[a-2][b]==board[a][b] && board[a-3][b]==0 && board[a-4][b]==board[a][b] ) || (a-1>=1 && a+3<=15 && board[a-1][b]==board[a][b] && board[a+1][b]==board[a][b] && board[a+2][b]==0 && board[a+3][b]==board[a][b] ) || (a-2>=1 && a+2<=15 && board[a-2][b]==board[a][b] && board[a-1][b]==board[a][b] && board[a+1][b]==0 && board[a+2][b]==board[a][b] )  || (a-4>=1 && board[a-1][b]==board[a][b] && board[a-2][b]==0 && board[a-3][b]==board[a][b] && board[a-4][b]==board[a][b] )  || ( a-3>=1 && a+1<=15 && board[a-1][b]==0 && board[a-2][b]==board[a][b] && board[a-3][b]==board[a][b] && board[a+1][b]==board[a][b])  ) //上边 
			cnt++;
		if( (a+4<=15 && board[a+1][b]==0 && board[a+2][b]==board[a][b] && board[a+3][b]==board[a][b] && board[a+4][b]==board[a][b] ) || (a+4<=15 && board[a+1][b]==board[a][b] && board[a+2][b]==board[a][b] && board[a+3][b]==0 && board[a+4][b]==board[a][b]) || (a+1<=15 && a-3>=1 && board[a+1][b]==board[a][b] && board[a-1][b]==board[a][b] && board[a-2][b]==0 && board[a-3][b]==board[a][b] )  || (a+2<=15 && a-2>=1 &&board[a+2][b]==board[a][b] && board[a+1][b]==board[a][b] && board[a-1][b]==0 && board[a-2][b]==board[a][b] )  || (a+4<=15 && board[a+1][b]==board[a][b] && board[a+2][b]==0 && board[a+3][b]==board[a][b] && board[a+4][b]==board[a][b] ) || ( a+3<=15 && a-1>=1 && board[a+1][b]==0 && board[a+2][b]==board[a][b] && board[a+3][b]==board[a][b] && board[a-1][b]==board[a][b]) )  //下边 
			cnt++;
			
		board[a][b]=0;
		return cnt;
}
