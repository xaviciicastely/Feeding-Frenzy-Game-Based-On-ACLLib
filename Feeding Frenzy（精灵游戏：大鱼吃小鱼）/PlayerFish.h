#ifndef PlayerFish_h
#define PlayerFish_h
#include "FishBase.h"
#include "acllib.h"
class PlayerFish :public FishBase
{
	private:
		int score;
  public:
	PlayerFish(int xx, int yy, int w, int h, int dxx, int dyy, int lv,  ACL_Image *img1, ACL_Image *img2, rect r1);
	PlayerFish(PlayerFish &pfish);
	~PlayerFish();

	void move(int key);
	void move(rect r);
	bool iftouch(rect r1);
	int getscore();
	void setscore(int s);
	void addscore(int m);
	void upgrade(int uw, int uh, int ulv,ACL_Image *ulimg, ACL_Image *urimg);
};
#endif
