//---------------------------------------------------------------------------

#ifndef SeaFeldH
#define SeaFeldH
//---------------------------------------------------------------------------
#include "ObjectGroup.h"
#include <vector>



class SeaFeld{


public:
	int playScreenW,playScreenH;
	int startScreenToBottom;
	int startScreenToTop; //the distance from the top PlayScreen to the top Frame
	int startScreenToLeft;//the distance from the left PlayScreen to the left Frame
	int startScreenToRight;
	int w,h;
	int pixelW;           //PixelW = PixelH the wide and heigh of the each point are the same

	std::vector<Object> matrix;

	void FeldInit(int &getW,int &getH);
	int XYIntoNum(int &x,int &y);   // transfer x,y into num of Vector
	int NumIntoX(int &num);
	int NumIntoY(int &num);
	Object GetObject(int i, int j);
	void InitObject();
	void CreatObject(int m, int n,int code,int dir,int scale);
	void DestoryObject(int m,int n);
	void DestoryObject(int num);

	void SerchNewTarget(int i);     /////对 matrix 中的每一个目标进行遍历，根据code，确定鲨鱼及其捕捉的对象。并且储存其对象的当前坐标和游动方向和速度。
	void Catch();     ////////////需要补充 如果需要输入参量
	void RunAway();   ////////////

	void KeepMoveObject(Object object,const char &c); //need to think over it!!!!!!!!!!!!!!!

	void Update();
	void Hai();
	void BigFish();
	void Fish();
	bool ifTarget(int i);
	bool ifTarget(int x,int y);
	void Move(int i);//Movement
	void noTargetMove(int i);
	void targetEat(int i);
	void targetMove(int i,double s);
	void Target(int i);
	bool Chased(int i);
};
#endif
