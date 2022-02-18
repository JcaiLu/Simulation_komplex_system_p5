//---------------------------------------------------------------------------

#ifndef ObjectGroupH
#define ObjectGroupH
//---------------------------------------------------------------------------
class Object{


private:

    int Code;           //the code of animal
    int ShapeSea[20][20]; //the shape of the animal----in order to draw it
    int ShapeFish[20][20];
    int ShapeBigFish[20][20];
    int ShapeHai[20][20];

    double DegreeFull; //the degree of full
    double DegreeLife;//the Degreeof Life
    int X,Y;            //the location of this animal
    char Direction;    //w(up),s(down),a(left),d(right)
    float Speed;
       
public:
    
    void toDraw();
    void detectFeld();
    void judegObject();
    bool ifFull();
    bool ifLive();
    


};

/*
class Hai : public Object{    //��Ҫ��Ҫд����ĺ�����

};

class Firsch : public Object{

};
*/
#endif
