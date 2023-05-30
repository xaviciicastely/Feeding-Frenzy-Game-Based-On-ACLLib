#ifndef FishBase_h
#define FishBase_h
#include"acllib.h"
class FishBase
{
  protected:
    int x, y;
    int width, height;
    int dx, dy;
    int level;
    ACL_Image *limg;//左转向图片
    ACL_Image *rimg;//右转向图片
    rect r;
  public:
    FishBase(int xx, int yy, int w, int h, int dxx, int dyy, int lv,  ACL_Image *img1, ACL_Image *img2,rect r1);
    FishBase(FishBase & base);
    virtual ~FishBase();
    virtual void move(rect r)=0;
    void paintfish(int width, int height);
		void paintfish();
    rect getRect();
    int getlevel();
};

#endif
