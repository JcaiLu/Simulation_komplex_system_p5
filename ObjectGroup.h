//---------------------------------------------------------------------------

#ifndef ObjectGroupH
#define ObjectGroupH
//---------------------------------------------------------------------------
//int ShapeSea[20][20]; //the shape of the animal----in order to draw it


class Object{

private:
	void BoundaryTreatment(int arr[]);

public:
	Object(int px,int py,int c);
	Object(int c);
	Object();
	int code;           //the code of animal
	int xInPixel;
	int yInPixel;
	int X,Y;         //the location of this animal
	int shape[10][10];

	double degreeFull; //the degree of full
	double degreeLife;//the Degreeof Life

	int direction;    //0(up),1(down),2(left),3(right)
	float Speed;

	int GetX();
	int GetY();
	void ReadX(int value);
	void ReadY(int value);

	void Objectencode(int t);
	void ObjectDraw(int ColorNum);    //ColorNum is used to reload the color of sea
	void CopyOf(int t);
	void CodeShapeUpdate();

	bool IfFull();
	bool IfLive();
	void DefShape();

	static const int shapeSea[10][10];
	static const int shapeFish[10][10];
	static const int shapeBigFish[10][10];
	static const int shapeHai[10][10];
//---------------------------------------------------------------------------
//The following declaration is used to change the relevant range of the object.
//---------------------------------------------------------------------------
	int detectRange;
	int warnRange;
	int huntRange;
	int possibleRange;

	int warnFeld[4];
	int detectFeld[4];
	int huntFeld[4];
	int possibleFeld[4];

	void GetValueRange();

	void GetDetectFeld();
	void GetWarnFeld();
	void GetHuntFeld();
	void GetPossibleFeld();
//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
	int fishScale;
	/////////////Target Information
	int target[2];
	int targetDirection;
	int speed;

};













#endif







