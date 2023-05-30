#include "FishBase.h"

FishBase::FishBase(int xx, int yy, int w, int h, int dxx, int dyy, int lv,  ACL_Image *img1, ACL_Image *img2, rect r1)
{
	x = xx;
	y = yy;
	width = w;
	height = h;
	dx = dxx;
	dy = dyy;
	limg = img1;
	rimg = img2;
	r = r1;
}
FishBase::FishBase(FishBase & fish)
{
	this -> x = fish.x;
	this -> y = fish.y;
	this -> width = fish.width;
	this -> height = fish.height;
	this -> dx = fish.dx;
	this -> dy = fish.dy;
  this -> level = fish.level;
	this -> limg = fish.limg;
	this -> limg = fish.rimg;
	this -> r = fish.r;
}
FishBase::~FishBase()
{

}

void FishBase::paintfish(int width, int height)
{
	if(dx>0)
	{
		putImageScale(rimg, x, y, width, height);
	}
	if(dx<0)
	{
		putImageScale(limg, x, y, width, height);
	}
}

void FishBase::paintfish()
{
	if(dx>0)
	{
		putImageScale(rimg, x, y, width, height);
	}
	if(dx<0)
	{
		putImageScale(limg, x, y, width, height);
	}
}

rect FishBase::getRect()
{
	rect r = {x, y, width, height};
	return r;
}

int FishBase::getlevel()
{
	return level;
}