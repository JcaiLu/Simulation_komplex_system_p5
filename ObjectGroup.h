//---------------------------------------------------------------------------

#ifndef ObjectGroupH
#define ObjectGroupH
//---------------------------------------------------------------------------
//int ShapeSea[20][20]; //the shape of the animal----in order to draw it


class Object{


public:
    Object(int px,int py,int c);
    Object(int c);
	Object();
    int code;           //the code of animal
    int xInPixel;
    int yInPixel;
    int x,y;         //the location of this animal
    int shape[20][20];

    double degreeFull; //the degree of full
    double degreeLife;//the Degreeof Life

    char Direction;    //w(up),s(down),a(left),d(right)
    float Speed;

public:
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
	void DetectFeld();
	void JudegObject();
	void DefShape();

static const int shapeSea[20][20];
static const int shapeFish[20][20];
static const int shapeBigFish[20][20];
static const int shapeHai[20][20];
};





class Hai : public Object{    //

};







#endif







