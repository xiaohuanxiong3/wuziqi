#ifndef WUZIQI_H
#define WUZIQI_H

class WuZiQi
{
		int	board[16][16];
		int GradeDN[16][16];
		int Grade[16][16];
	public:
		WuZiQi()
		{
			int i,j;
			for(i=1;i<=15;i++)
				for(j=1;j<=15;j++)
				{
					board[i][j]=0;
					GradeDN[i][j]=0;
					Grade[i][j]=0;
				}
		}
		void play(int);
		void print();
		bool judge(int a,int b);
		int GZ(int,int,int);
		void AI(int x);
		void chess(int i,int j,int x);
		int PG1(int a,int b,int x);
		int PG2(int a,int b,int x);
		int PG3(int a,int b,int x);
		int PG4(int a,int b,int x);
		int PG5(int a,int b,int x);
		int PG6(int a,int b,int x);
		int PG7(int a,int b,int x);
		int PG8(int a,int b,int x);
		
		int CW(int a,int b,int x);	//成五 个数 
		int WW(int a,int b,int x);  //伪五个数 
		int HS(int a,int b,int x);	//活四 个数
		int SS(int a,int b,int x);	//死四 个数
		int LHS(int a,int b,int x);	//活三 个数
		int THS(int a,int b,int x); //跳活三 
		int LHE(int a,int b,int x);	//连活二 个数
		int THE(int a,int b,int x); //跳活二 
		int DTHE(int a,int b,int x); //大跳活二 
		int SE(int a,int b,int x); //死二 
		int DZ(int a,int b,int x); //单子 
};

#endif
