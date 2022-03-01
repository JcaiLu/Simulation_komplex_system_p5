//====================================================================
// Simulation dynamischer Systeme mit PLAN
//====================================================================
// Projektbeschreibung:
//
//====================================================================
#include <vcl.h>
#pragma hdrstop
#include "Plan.h"
#include "ObjectGroup.h"
#include "SeaFeld.h"




class TUser : public TPlan{

public:

    int getMW,getMH;
	int xxxxx;
    SeaFeld Feld;
	static const char d = 'd';
    
    void Init(){

        getMW = GetMaxW();
        getMH = GetMaxH();
        Feld.FeldInit(getMW,getMH);
        Reset();
		DrawInit();
		Feld.InitObject();
		Feld.CreatObject(0,0,1);
		Feld.CreatObject(1,1,2);

	}

	void Reset(){
        SetPen(Schwarz);SetBrush(Weiss); SetTextSize(30);               // adjust the size and color of the word
		Text((int)(GetMaxW()*0.25),(int)(GetMaxH()*0.05),"Feld of Sea");
	}

	void Run(){
		DrawInit();
		FeldDraw(Feld);
		Feld.MoveObject(Feld.GetObject(0,0),d);

		CallRun = false;

	}

	void DrawInit(){
		SetBrush(TColor(RGB(0,255,255)));
		for(int y = 0; y < Feld.h; y++  ){     //Zeilen
			for(int x = 0; x < Feld.w; x++){          //Spalten
			int colorDiff =255-(float)y/(float)Feld.h*100;
			SetBrushColor(TColor(RGB(0,colorDiff,255)));
			//SetPenColor(Schwarz);
			SetPen(TColor(RGB(0,colorDiff,255)));
				Rectangle(Feld.startScreenToLeft+x*Feld.pixelW,Feld.startScreenToTop+y*Feld.pixelW,Feld.pixelW,Feld.pixelW);
			}
		}

	}

	void ObjectDraw(SeaFeld playFeld,Object t){
		for(int j = 0;j<playFeld.pixelW;j++){
			for(int i = 0;i <playFeld.pixelW;i++){
				if(t.shape[j][i] != 0){
					SetPixel(t.xInPixel+i,t.yInPixel+j,Schwarz);
				}
			}
		}
}
	 void FeldDraw(SeaFeld playFeld){
		 for(int j = 0;j<playFeld.h;j++){
			 for(int i = 0;i<playFeld.w;i++){
				 if(Feld.GetObject(i,j).code != 0 ){
					 ObjectDraw(Feld,Feld.GetObject(i,j));
				 }
			 }
		 }


	 }

 };



//====================================================================
#pragma argsused
int main(int argc, char* argv[]){ TUser a; a.Execute(); return 0; }
//__________________________________________________________Ost08_____



