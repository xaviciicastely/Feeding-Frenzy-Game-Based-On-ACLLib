#include<iostream>
#include<stdio.h>
#include"acllib.h"
#include"FishBase.h"
#include"PlayerFish.h"
#include"Fishlv1shrimp.h"
#include"Fishlv2littlefish.h"
#include"Fishlv3whale.h"
#include<time.h>
#include<stdio.h>
#include<windows.h>

const int maxNum_shrimp = 100;
const int maxNum_littlefish = 20;
const int maxNum_whale = 5;
int nowNum_shrimp = 0;
int nowNum_littlefish = 0;
int nowNum_whale = 0;
const int winWidth = 1500, winHeight = 750;
int playerlv = 1;
int startgame = 0;
int ifgameover = 0;
Fishlv1shrimp *fishlv1shrimp[maxNum_shrimp] = { 0 };
Fishlv2littlefish *fishlv2littlefish[maxNum_littlefish] = { 0 };
Fishlv3whale *fishlv3whale[maxNum_whale] = { 0 };
PlayerFish *playerfish = NULL;
int NPCWidth = 30, NPCHeight = 30;
int PlayerWidth = 50, PlayerHeight = 50;
ACL_Image playerfish_left, playerfish_right;
ACL_Image playerfish2_left, playerfish2_right;
ACL_Image playerfish3_left, playerfish3_right;
ACL_Image fishlv1shrimp_left, fishlv1shrimp_right;
ACL_Image fishlv2littlefish_left, fishlv2littlefish_right;
ACL_Image fishlv3whale_left, fishlv3whale_right;
ACL_Image guibackground;
rect winRect;
void timerEvent(int id);
void createData_shrimp(Fishlv1shrimp **fishlv1shrimp);
void createData_littlefish(Fishlv2littlefish **fishlv2littlefish);
void createData_whale(Fishlv3whale **fishlv3whale);
void createData_player(PlayerFish **playerfish);
void keyEvent(int key, int event);
void mouseEvent(int mx, int my, int button, int event);
void paint();

int Setup()
{
	winRect.x = DEFAULT;
	winRect.y = DEFAULT;
	winRect.width = winWidth;
	winRect.height = winHeight;
	initWindow("Feeding Frenzy", DEFAULT, DEFAULT, winWidth, winHeight);
	srand((unsigned)time(NULL));
	loadImage("playerfish_left.jpg", &playerfish_left);
	loadImage("playerfish_right.jpg", &playerfish_right);
	loadImage("playerfish2_left.jpg", &playerfish2_left);
	loadImage("playerfish2_right.jpg", &playerfish2_right);
	loadImage("playerfish3_left.jpg", &playerfish3_left);
	loadImage("playerfish3_right.jpg", &playerfish3_right);
	loadImage("fishlv1shrimp_left.jpg", &fishlv1shrimp_left);
	loadImage("fishlv1shrimp_right.jpg", &fishlv1shrimp_right);
	loadImage("fishlv2littlefish_left.jpg", &fishlv2littlefish_left);
	loadImage("fishlv2littlefish_right.jpg", &fishlv2littlefish_right);
	loadImage("fishlv3whale_left.jpg", &fishlv3whale_left);
	loadImage("fishlv3whale_right.jpg", &fishlv3whale_right);
	loadImage("guibackground.jpg",&guibackground);
	createData_shrimp(fishlv1shrimp);
	createData_littlefish(fishlv2littlefish);
	createData_whale(fishlv3whale);
	createData_player(&playerfish);
	registerTimerEvent(timerEvent);
	registerKeyboardEvent(keyEvent);
	registerMouseEvent(mouseEvent);
	startTimer(0, 40);
	startTimer(1, 1000);
	PlaySound(TEXT("bgm.wav"), NULL,  SND_ASYNC | SND_LOOP | SND_NODEFAULT);//循环播放背景音乐
	return 0;
}

void timerEvent(int id)
{
	switch (id)
	{
		case 0:
			for (int i = 0; i < nowNum_shrimp ; ++i)
			{
				if (fishlv1shrimp[i])
				{
					rect pr = playerfish->getRect();
					fishlv1shrimp[i] -> ifdanger(*playerfish,pr);//遇到危险跑路
					fishlv1shrimp[i] -> move(pr);
				}
			}
			for(int j=0; j< nowNum_littlefish ; ++j)
			{
				if (fishlv2littlefish[j])
				{
					rect pr = playerfish -> getRect();
					fishlv2littlefish[j] -> ifdanger(*playerfish,pr);//遇到危险跑路
					fishlv2littlefish[j] -> move(pr);
				}
			}
			for(int k=0; k< nowNum_whale ; ++k)
			{
				if (fishlv3whale[k])
				{
					rect pr = playerfish -> getRect();
					fishlv3whale[k] -> ifdanger(*playerfish,pr);//遇到危险跑路
					fishlv3whale[k] -> move(pr);
				}
			}
			break;

		case 1:
			if (nowNum_shrimp < maxNum_shrimp)
			{
				createData_shrimp(fishlv1shrimp);
			}
			if (nowNum_littlefish < maxNum_littlefish)
			{
				createData_littlefish(fishlv2littlefish);
			}
			if (nowNum_whale < maxNum_whale)
			{
				createData_whale(fishlv3whale);
			}
			break;
		}//end switch
	
		paint();
}

void createData_shrimp(Fishlv1shrimp **fishlv1shrimp)
{
	int x = rand() % winWidth - NPCWidth;
	if (x < 0)x = 0;
	int y = rand() % winHeight - NPCHeight;
	if (y < 0)y = 0;
	int dx = rand() % 5 + 1;
	int dy = rand() % 5 + 1;
	int t = rand() % 100;
	int lv=1;
	int score=1;
	if(t<25)
		fishlv1shrimp[nowNum_shrimp++] = new Fishlv1shrimp(x, y, NPCWidth, NPCHeight, dx, dy, lv, &fishlv1shrimp_left, &fishlv1shrimp_right, winRect, score);
}

void createData_littlefish(Fishlv2littlefish **fishlv2littlefish)
{
	int x = rand() % winWidth - NPCWidth;
	if (x < 0)x = 0;
	int y = rand() % winHeight - NPCHeight;
	if (y < 0)y = 0;
	int dx = rand() % 4 + 1;
	int dy = rand() % 4 + 1;
	int t = rand() % 100;
	int lv=2;
	int score=2;
	if(t<10)
		fishlv2littlefish[nowNum_littlefish++] = new Fishlv2littlefish(x, y, NPCWidth+50, NPCHeight+30, dx, dy, lv, &fishlv2littlefish_left, &fishlv2littlefish_right, winRect, score);
}

void createData_whale(Fishlv3whale **fishlv3whale)
{
	int x = rand() % winWidth - NPCWidth;
	if (x < 0)x = 0;
	int y = rand() % winHeight - NPCHeight;
	if (y < 0)y = 0;
	int dx = rand() % 2 + 1;
	int dy = rand() % 2 + 1;
	int t = rand() % 100;
	int lv=3;
	int score=5;
	if(t<5)
		fishlv3whale[nowNum_whale++] = new Fishlv3whale(x, y, NPCWidth+150, NPCHeight+100, dx, dy, lv, &fishlv3whale_left, &fishlv3whale_right, winRect, score);
}

void createData_player(PlayerFish **player)
{
	int x = rand() % winWidth - NPCWidth;
	if (x < 0)x = 0;
	int y = rand() % winHeight - NPCHeight;
	if (y < 0)y = 0;
	int dx = 5;
	int dy = 5;
	*player = new PlayerFish(x, y, PlayerWidth, PlayerHeight, dx, dy, playerlv, &playerfish_left, &playerfish_right, winRect);
	playerfish->setscore(0);
}

void paint()
{
	beginPaint();
	clearDevice();
	if(startgame == 0)//初始界面
	{
		putImageScale(&guibackground, 0, 0 , 1500 , 750);
		setTextSize(100);
		setTextColor(WHITE);
		setTextBkColor(RGB(0,0,0));
		setTextFont("Viner Hand ITC");
		paintText(400, 625, "Click Here to Start Game!");
	}
	
	if(startgame == 1 && ifgameover != 1)//游戏界面
	{
		for (int i = 0; i < nowNum_shrimp; ++i)
		{
			if (fishlv1shrimp[i])
			{
				fishlv1shrimp[i]->paintfish();
			}
		}
		for (int j = 0; j < nowNum_littlefish; ++j)
		{
			if (fishlv2littlefish[j])
			{
				fishlv2littlefish[j]->paintfish();
			}
		}
		for (int k = 0; k < nowNum_whale; ++k)
		{
			if (fishlv3whale[k])
			{
				fishlv3whale[k]->paintfish();
			}
		}
		if (playerfish)
		{
			playerfish->paintfish();
			char txt1[10];
			char txt2[20];
			setTextFont("New Times Roman");
			setTextColor(BLACK);
			setTextBkColor(WHITE);
			sprintf_s(txt1, "Score: %d", playerfish->getscore());
			setTextSize(30);
			paintText(10, 10, txt1);
			sprintf_s(txt2, "Nowlevel: %d", playerfish->getlevel());
			setTextSize(30);
			paintText(10, 40, txt2);
			setTextSize(20);
			paintText(10, 70, "Operating Instructions:");
			setTextSize(20);
			paintText(10, 90, "w:up,s:down,a:left,d:right");
		}
	}
	if(ifgameover == 1)//游戏结束界面
	{
		putImageScale(&guibackground, 0, 0 , 1500 , 750);
		setTextSize(400);
		setTextColor(RED);
		setTextBkColor(BLACK);
		setTextFont("Viner Hand ITC");
		paintText(125, 300, "Game Over!");
	}
	endPaint();
}

void mouseEvent(int mx, int my, int button, int event)
{
	if (event != BUTTON_DOWN)
	{
		return;
	}
	if (button == LEFT_BUTTON && event == BUTTON_DOWN) 
	{
			if (mx > 400 && mx < 1100 && my > 600 && my < 725)//鼠标点击的是“开始游戏”
			{   
				startgame = 1;
			}
	}
}

void keyEvent(int key, int event)
{
	if (event != KEY_DOWN)
	{
		return;
	}
	if(playerfish)
	{
		playerfish->move(key);
		if(playerfish -> getscore() >=10 && playerfish -> getscore()<25 )
		{
			playerlv=2;
			playerfish -> upgrade(PlayerWidth+100, PlayerHeight+30, playerlv, &playerfish2_left, &playerfish2_right);
		}
		if(playerfish -> getscore() >= 25 && playerfish->getscore() <50)
		{
			playerlv=3;
			playerfish -> upgrade(PlayerWidth+200, PlayerHeight+80, playerlv, &playerfish3_left, &playerfish3_right);
		}
		if(playerfish -> getscore() >= 50)
		{
			playerlv=4;
			playerfish -> upgrade(PlayerWidth+200, PlayerHeight+80, playerlv, &playerfish3_left, &playerfish3_right);
		}	
	}
	for (int i = 0; i < nowNum_shrimp; ++i)
	{
		if (fishlv1shrimp[i])
		{
			if (playerfish->iftouch(fishlv1shrimp[i]->getRect()))
			{
				int s = fishlv1shrimp[i]->getscore();
				if (playerfish)playerfish->addscore(s);
				delete(fishlv1shrimp[i]);
				fishlv1shrimp[i] = NULL;
			}
		}
	}
	for (int j = 0; j < nowNum_littlefish; ++j)
	{
		if (fishlv2littlefish[j])
		{
			if (playerfish->iftouch(fishlv2littlefish[j]->getRect()))
			{
				if(fishlv2littlefish[j]->getlevel() <= playerfish->getlevel())
				{
					int s = fishlv2littlefish[j]->getscore();
					if (playerfish)playerfish->addscore(s);
					delete(fishlv2littlefish[j]);
					fishlv2littlefish[j] = NULL;
				}
				else
				{
					PlaySound(TEXT("gameover.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
					ifgameover = 1;
					
				}
			}
		}
	}
	for (int k = 0; k < nowNum_whale; ++k)
	{
		if (fishlv3whale[k])
		{
			if (playerfish->iftouch(fishlv3whale[k]->getRect()))
			{
				if(fishlv3whale[k]->getlevel() <= playerfish->getlevel())
				{
					int s = fishlv3whale[k]->getscore();
					if (playerfish)playerfish->addscore(s);
					delete(fishlv3whale[k]);
					fishlv3whale[k] = NULL;
				}
				else
				{
					PlaySound(TEXT("gameover.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
					ifgameover = 1;
				}
			}
		}
	}
	paint();
}