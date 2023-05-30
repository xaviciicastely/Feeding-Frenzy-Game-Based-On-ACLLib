#ifndef Fishlv1shrimp_h
#define Fishlv1shrimp_h
#include "FishBase.h"
#include "PlayerFish.h"
#include "math.h"

class Fishlv2littlefish :public FishBase
{
  private:	
    int score;
		int oldx, oldy;
		bool ifdangervalue;
		bool bfirst;
  public:
	  Fishlv2littlefish(int xx, int yy, int w, int h, int dxx, int dyy,int lv, ACL_Image *img1, ACL_Image *img2, rect r1,int score);
	  Fishlv2littlefish(Fishlv2littlefish &shrimp);
  	~Fishlv2littlefish();
		void ifdanger(PlayerFish &pfish,rect rr);
	  void move(rect rr);
	  int getscore();
		bool getifdanger();

};

#endif
