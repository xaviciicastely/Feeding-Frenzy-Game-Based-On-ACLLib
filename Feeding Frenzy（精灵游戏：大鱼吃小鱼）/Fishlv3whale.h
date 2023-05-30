#ifndef Fishlv3whale_h
#define Fishlv3whale_h
#include "FishBase.h"
#include "PlayerFish.h"
#include "math.h"

class Fishlv3whale :public FishBase
{
  private:	
    int score;
		int oldx, oldy;
		bool ifdangervalue;
		bool bfirst;
  public:
	  Fishlv3whale(int xx, int yy, int w, int h, int dxx, int dyy,int lv, ACL_Image *img1, ACL_Image *img2, rect r1,int score);
	  Fishlv3whale(Fishlv3whale &whale);
  	~Fishlv3whale();
		void ifdanger(PlayerFish &pfish,rect rr);
	  void move(rect rr);
	  int getscore();
		bool getifdanger();

};

#endif
