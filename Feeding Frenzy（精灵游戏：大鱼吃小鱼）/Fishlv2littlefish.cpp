#include "Fishlv2littlefish.h"
#include "PlayerFish.h"
Fishlv2littlefish::Fishlv2littlefish(int xx, int yy, int w, int h, int dxx, int dyy, int lv, ACL_Image *img1, ACL_Image *img2, rect r1,int score):FishBase(xx,yy,w,h,dxx,dyy,lv,img1,img2,r1)
{
	this -> level = lv;
  this -> score = score;
	this -> oldx = dx;
	this -> oldy = dy;
	this -> bfirst = true;
}
Fishlv2littlefish::Fishlv2littlefish(Fishlv2littlefish &fish):FishBase(fish)
{
	this -> level = fish.level;
	this -> score = fish.score;
	this -> oldx = fish.dx;
	this -> oldy = fish.dy;
	this -> bfirst = true;
}

Fishlv2littlefish::~Fishlv2littlefish()
{
}
void Fishlv2littlefish::ifdanger(PlayerFish &pfish, rect rr)
{
	int cx = x + width / 2;
	int cy = y + height / 2;
	int rx = rr.x + rr.width / 2;
	int ry = rr.y + rr.height / 2;
	float distance = sqrt((cx - rx)*(cx - rx) + (cy - ry)*(cy - ry));
	if (distance < 300 && this->level <= pfish.getlevel())  
	{
		this -> ifdangervalue = true;
	}
	else
	{
		this -> ifdangervalue = false;
	}
}

void Fishlv2littlefish::move(rect rr)
{
	if (ifdangervalue) //遇到危险跑路
	{
		if (x < rr.x) dx = -abs(dx);
		else dx=abs(dx);
		
		if (y < rr.y) dy = -abs(dy);
		else dy=abs(dy);

		x += 1.5*level*dx;
		y += 1.5*level*dy;
	}
	else //未遇到危险，正常游弋
	{
		x += dx;
		y += dy;

	}
// 出界后重新进入
	if ((dx<0)&&(x<-width/2)) 
	{
		x = r.width-width/2;
	}
	if ((dx>0)&&(x>(r.width-width/2))) 
	{
		x = -width/2;
	}
	if ((dy<0)&&(y<-height/2)) 
	{
		y = r.height-height/2;
	}
	if ((dy>0)&&(y>(r.height-height/2))) 
	{
		y = -height/2;
	}
	
}
int Fishlv2littlefish::getscore()
{
	return score;
}
