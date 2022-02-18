//====================================================================
// Simulation dynamischer Systeme mit PLAN
//====================================================================
// Projektbeschreibung:
//
//====================================================================
#include <vcl.h>
#pragma hdrstop
#include "Plan.h"
#include "TIntFeld.h"
#include "ObjectGroup.h"


class TUser : public TPlan{

public:

    TIntFeld Feld;
    int PixelW; //PixelW = PixelH the wide and heigh of the each point are the same
    int PlayScreenW,PlayScreenH;
    int StartScreenToLeft;//the distance from the left PlayScreen to the left Frame
    int StartScreenToRight;
    int StartScreenToTop;//the distance from the top PlayScreen to the top Frame
    int StartScreenToBottom;





    void Init(){

        Reset();

        DrawInit();

    }

    void Reset(){
        PixelW = 20;
        StartScreenToLeft = (int)(GetMaxW()*0.05);
        StartScreenToRight = (int)(GetMaxW()*0.5);
        StartScreenToTop =(int)(GetMaxH()*0.1);
        StartScreenToBottom =(int)(GetMaxH()*0.05);
        PlayScreenW = (int)((GetMaxW() - StartScreenToLeft - StartScreenToRight)/PixelW);
        PlayScreenH = (int)((GetMaxH() - StartScreenToTop - StartScreenToBottom)/PixelW);
        Feld.Size(PlayScreenW,PlayScreenH);
        SetPen(Schwarz);SetBrush(Weiss); SetTextSize(30);               // adjust the size and color of the word
        Text((int)(GetMaxW()*0.25),(int)(GetMaxH()*0.05),"Feld of Sea");
    }

    void Run(){


    }

    void DrawInit(){


        SetBrush(TColor(RGB(0,255,255)));
        for(int y = 0; y < PlayScreenH; y++  ){     //Zeilen
            for(int x = 0; x < PlayScreenW; x++){          //Spalten
            int ColorDiff =255-(float)y/(float)PlayScreenH*100;
            SetBrush(TColor(RGB(0,ColorDiff,255)));
            SetPen(Schwarz);
            //SetPen(TColor(RGB(0,ColorDiff,255)));
                Rectangle(StartScreenToLeft+x*PixelW,StartScreenToTop+y*PixelW,PixelW,PixelW);
            }
        }

    }


 };



//====================================================================
#pragma argsused
int main(int argc, char* argv[]){ TUser a; a.Execute(); return 0; }
//__________________________________________________________Ost08_____

