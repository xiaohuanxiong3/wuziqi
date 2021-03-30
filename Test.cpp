#include<iostream>
#include"WuZiQi.h"
using namespace std;

int main()
{
	system("color 30"); 
	WuZiQi game;
	
	game.print();
	int flag;
	cout<<"ÇëÑ¡ÔñÖ´ºÚ»¹ÊÇÖ´°×(Ö´ºÚÏÈÏÂ! 1:Ö´ºÚ,2:Ö´°×.):";
	cin>>flag;
	while(flag!=1 && flag!=2)
	{
		cout<<"ÇëÖØÐÂÊäÈë:(ÊäÈë1Ñ¡ÔñÖ´ºÚ,2Ñ¡ÔñÖ´°×):";
		cin>>flag;
	}
	game.play(flag);
	
	return 0;
}


