#include "PlayerFish.h"
#include "math.h"
#include "windows.h"
PlayerFish::PlayerFish(int xx, int yy, int w, int h, int dxx, int dyy, int lv,  ACL_Image *img1, ACL_Image *img2, rect r1)
:FishBase(xx,yy,w,h,dxx,dyy,lv,img1,img2,r1)
{
	level = lv;
}

PlayerFish::PlayerFish(PlayerFish &pfish):FishBase(pfish)
{
	level = pfish.level;
}

PlayerFish::~PlayerFish(){}

void PlayerFish::move(rect r1)
{
	x = r1.x;
	y = r1.y;
	if (x < r.x)
	{
		x = r.x;
	}

	if (x >(r.x + r.width - width))
	{
		x = (r.x + r.width - width);
	}

	if (y < r.y)
	{
		y = r.y;
	}
	if (y >(r.y + r.height - height))
	{	
		y = (r.y + r.height - height);
	}
}

void PlayerFish::move(int key)
{

	if (GetAsyncKeyState(65) & 0x8000)  	// 左边
	{
		dx = -abs(dx);//令dx小于零，加载左朝向图片
		x += 2 * level * dx;
		if (x < r.x)
		{	
			x = r.x;
		}
	}
	if (GetAsyncKeyState(87) & 0x8000)  	// 上面
	{
		y -= 2 * level * dy;
		if (y < 0) 
		{
			y = 0;
		}
	}
	if (GetAsyncKeyState(83) & 0x8000)  	// 下面
	{
		y += 2 * level * dy;
		if (y >(r.height - height)) 
		{	
			y = (r.height - height);
		}
	}
	if (GetAsyncKeyState(68) & 0x8000)  	// 右边
	{
		dx = abs(dx);//令dx大于零，加载右朝向图片
		x += 2 * level * dx;
		if (x >(r.width - width)) 
		{
			x = (r.width - width);
		}
	}
}


bool PlayerFish::iftouch(rect r2)
{
	rect r1 = { x,y, width, height };
	bool iftouchvalue = true;
	if (r1.x < r2.x && r1.x + r1.width >r2.x) 
	{
		if (r1.y > r2.y && r1.y<r2.y + r2.height)
		{
			return iftouchvalue = true;
		}
		if (r1.y <r2.y && r1.y + r1.height >r2.y)
		{
			return iftouchvalue = true;;
		}
	}
	else 
	{
		if (r1.x > r2.x && r2.x + r2.width > r1.x)
		{
			if (r1.y > r2.y && r1.y<r2.y + r2.height)
			{
				return iftouchvalue = true;;
			}
			if (r1.y <r2.y && r1.y + r1.height >r2.y)
			{
			  return iftouchvalue = true;
			}
		}
	}
	iftouchvalue = false;
	return iftouchvalue;
}

int PlayerFish::getscore()
{
	return score;
}

void PlayerFish::setscore(int s)
{
	score = s;
}

void PlayerFish::addscore(int m)
{
	score += m;
}

void PlayerFish::upgrade(int uw, int uh, int ulv,ACL_Image *ulimg, ACL_Image *urimg)
{
	width = uw;
	height =uh;
	level = ulv;
	limg = ulimg;
	rimg = urimg;
}


