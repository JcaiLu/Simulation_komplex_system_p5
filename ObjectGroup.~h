//---------------------------------------------------------------------------

#ifndef ObjectGroupH
#define ObjectGroupH
//---------------------------------------------------------------------------
//int ShapeSea[20][20]; //the shape of the animal----in order to draw it


class Object{


public:
    Object(int code);
    int ShapeSea[20][20];
    int ShapeBigFish[20][20];
    int ShapeFish[20][20];
    int ShapeHai[20][20];
    int Code;           //the code of animal

    int LocationInPixel[2];
    double DegreeFull; //the degree of full
    double DegreeLife;//the Degreeof Life

    char Direction;    //w(up),s(down),a(left),d(right)
    float Speed;

    int Shape[20][20];


    int X,Y;         //the location of this animal
    void detectFeld();
    void judegObject();
    bool ifFull();
    bool ifLive();
    int getX();
    int getY();

    void objectencode(int t);
    void objectDraw(int ColorNum);    //ColorNum is used to reload the color of sea
    void copyOf(Object t,int s);

};





class Hai : public Object{    //

};







#endif







