/*
4/18 2h30min finish menu+move cursor+place piece
准备acm和校内数模竞赛，下周会加速写的QAQ
.h文件在最后会分开的 
*/
#include<time.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
const int LEN=15;
const int MAXN=LEN+1;
char title[30]="title Gobang  OmegaGO ver0.1";
int rec[MAXN][MAXN],score[MAXN][MAXN],init[MAXN][MAXN];
int sum=0,renum=0;
char ch[11][4]={"┌","┬","┐","├","┼","┤","└","┴","┘","○","●"};//4?
bool judge_game=1;
void startgame(int value[][MAXN]);
void empty(int value[][MAXN]); 
void single(int value[][MAXN]);
void train(int value[][MAXN]);
void introduce();
void about();
void Exit();
void mainmenu(int value[][MAXN]);
void victory();
void retract(int x1,int y1,int x2,int y2,int value[][MAXN]);
int position();
int nextplayer();
int win();
void printboard(int *x,int *y,int value[][MAXN],int player);
void multi();//
void robot();
void findscore();
void chessone();
void chessscore();
void initialize(); 
inline bool check(int x,int y){return x<=15&&x>=1&&y<=15&&y>=1;}
int main()
{
	initialize();
	startgame(init);
	return 0;
}
void initialize()
{
	init[1][1]=0;init[1][LEN]=2;
	init[LEN][1]=6;init[LEN][LEN]=8;
	for(int i=2;i<LEN;i++)
	{
		init[1][i]=1,init[i][1]=3;
		init[LEN][i]=7,init[i][LEN]=5;
		for(int j=2;j<LEN;j++)
		{
			init[i][j]=4;
		}
	}
}
void startgame(int value[][MAXN])
{
	empty(value);
	mainmenu(value);
}
void empty(int value[][MAXN])
{
	for(int i=1;i<=LEN;i++)for(int j=1;j<=LEN;j++)value[i][j]=init[i][j];
}
void mainmenu(int value[][MAXN])
{
	while(1)
	{
		system("cls");
		system(title);
		system("color 3f");
		system ("mode con cols=56 lines=20");
		printf("┌—————————————————————————┐\n");
		printf("│                  OmegaGo ver0.1                  │\n");
		printf("│[1] START                                         │\n");
		printf("│                                                  │\n");
		printf("│[2] TRAIN                                         │\n");
		printf("│                                                  │\n");
		printf("│[3] INTRODUCE                                     │\n");
		printf("│                                                  │\n");
		printf("│[4] ABOUT                                         │\n");
		printf("│                                                  │\n");
		printf("│[5] EXIT                                          │\n");
		printf("└—————————————————————————┘\n");
		char tmp,flag=0;
		while(tmp=getch())
		{
			switch(tmp)
			{
				case '1':single(value);flag=1;break;
				case '2':train(value);break;
				case '3':introduce();break;
				case '4':about();break;
				case '5':Exit();break;//flag
				default:break;
			}
		}
		if(flag==1)break;
	}
}
void introduce()
{
	
}
void about()
{
	
}
void Exit()
{
	exit(0);
}
void printboard(int x,int y,int value[][MAXN],int player)
{
	system("cls");
	if(player==1)
	{
		value[y][x]=9;
	}
	else if(player==2)
	{
		value[y][x]=10;
	}
	printf("     1 2 3 4 5 6 7 8 9 0 1 2 3 4 5\n");
	for(int i=1;i<=LEN;i++)
	{
		printf("    %d",i%10);
		for(int j=1;j<=LEN;j++)
		{
			printf("%s",ch[value[i][j]]);
			if(strcmp(ch[value[i][j]],"○")!=0&&strcmp(ch[value[i][j]],"●")!=0)printf(" ");
		}
		puts("");
	}
}
void goto_xy(int x, int y,int value[][MAXN])
{   
	system("cls");
    printboard(0,0,value,-1);
    x=2*x+3;
    y=y;
    HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos={x,y};
    SetConsoleCursorPosition(hOut, pos);
}
void retract(int x1,int y1,int x2,int y2,int value[][MAXN])
{
	
}
void single(int value[][MAXN])
{
	system("pause>nul 2>nul");       
	system("cls");
	system ("mode con cols=43 lines=20");   
	system("color 3f");
	system(title);
	printboard(0,0,value,-1);
	sum=0,renum=0;
	bool flag=1;
	memset(rec,0,sizeof rec);
	int nowx=8,nowy=8,tmp;
	goto_xy(nowx,nowy,value);
	int x1=-1,y1=-1,x2=-1,y2=-1;
	while(flag)
	{
		while(tmp=getch())
		{
			switch(tmp)
			{
			    case 72:
					if(check(nowx,nowy-1))
						goto_xy(nowx,--nowy,value);
					break; 
			    case 80:
					if(check(nowx,nowy+1))
						goto_xy(nowx,++nowy,value);
					break; 
				case 75:
					if(check(nowx-1,nowy))
						goto_xy(--nowx,nowy,value);
					break; 
				case 77:
					if(check(nowx+1,nowy))
						goto_xy(++nowx,nowy,value);
					break; 
				case 32:
					if(!(value[nowx][nowy]==9||value[nowx][nowy]==10))
					{
						printboard(nowx,nowy,value,1);
						rec[nowx][nowy]=1;
						x1=nowx;y1=nowy;
						sum++;
					}
					break;
				case 8:
					retract(x1,y1,x2,y2,value);
					printboard(nowx,nowy,value,-1);
					break;
				default:break;
			}
		}
	}
}
void train(int value[][MAXN])
{
	
}
























