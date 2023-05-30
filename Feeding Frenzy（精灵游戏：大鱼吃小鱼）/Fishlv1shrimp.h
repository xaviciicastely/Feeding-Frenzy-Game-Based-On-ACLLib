#ifndef Fishlv2littlefish_h
#define Fishlv2littlefish_h
#include "FishBase.h"
#include "PlayerFish.h"
#include "math.h"

class Fishlv1shrimp :public FishBase
{
  private:	
    int score;
		int oldx, oldy;
		bool ifdangervalue;
		bool bfirst;
  public:
	  Fishlv1shrimp(int xx, int yy, int w, int h, int dxx, int dyy,int lv, ACL_Image *img1, ACL_Image *img2, rect r1,int score);
	  Fishlv1shrimp(Fishlv1shrimp &shrimp);
  	~Fishlv1shrimp();
		void ifdanger(PlayerFish &pfish,rect rr);
	  void move(rect rr);
	  int getscore();
		bool getifdanger();

};

#endif
