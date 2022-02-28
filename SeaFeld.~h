//---------------------------------------------------------------------------

#ifndef SeaFeldH
#define SeaFeldH
//---------------------------------------------------------------------------
#include "ObjectGroup.h"
#include <vector>






class SeaFeld{

public:

    int PlayScreenW,PlayScreenH;
    int StartScreenToBottom;
    int StartScreenToTop;//the distance from the top PlayScreen to the top Frame
    int PixelW; //PixelW = PixelH the wide and heigh of the each point are the same
    int StartScreenToLeft;//the distance from the left PlayScreen to the left Frame
    int StartScreenToRight;
    int W,H;
    int StartPointX, StartPointY; //the Startpoint in real pixel

    void FeldInit(int &GetW,int &GetH);

    std::vector<Object> Matrix;
    int xyIntoNum(int &x,int &y);   // transfer x,y into num of Vector
    int numIntoX(int &num);
    int numIntoY(int &num);
    Object getObject(int i, int j);
    void InitObject();

    void creatObject(int m, int n,int code);



};



#endif
