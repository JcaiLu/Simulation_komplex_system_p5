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
    bool k0,k1,k2;
    double x,phi ;
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
        Plot0->Size(GetMaxW()*0.55,GetMaxH()*0.08,700,900);
        Plot0->Achse(0,"Time in Days [d]");
        Plot0->Achse(0,0.0,100);
        Plot0->Achse(1,0,1000);
        Plot0->Achse(1,"Number of Fish [n]");
        Plot0->Kurve0->SetPen(Hellrot,3);
        Plot0->Kurve1->SetPen(Blau,3);
        Plot0->Kurve2->SetPen(Schwarz,3);
        InsertTaste(0,"Shark");
        InsertTaste(1,"Salmon");
        InsertTaste(2,"Small Fish");

	}


    	void Run(){
		DrawInit();
		FeldDraw(Feld);
		Feld.MoveObject(Feld.GetObject(0,0),d);

                x=0.0;
                Plot0->Reset();
                while(x<100){
                if(k0) Plot0->Kurve0->LineTo(x,500*sin(x-phi));
                if(k1) Plot0->Kurve1->LineTo(x,1000*cos(x+phi));
                if(k2) Plot0->Kurve2->LineTo(x,700*sin(x-phi));
                x+=2; }
                phi+=1;

                CallRun = true;


	}

	void Reset(){
        SetPen(Schwarz);SetBrush(Weiss); SetTextSize(30);               // adjust the size and color of the word
		Text((int)(GetMaxW()*0.25),(int)(GetMaxH()*0.05),"Feld of Sea");
                Text((int)(GetMaxW()*0.73),(int)(GetMaxH()*0.05),"Changes of Fish");
                Plot0->Reset();
                k0 = true ;
                k1 = true ;
                k2 = true ;
                x = 0.0;
                phi = 0.0;
	}
        void RunTaste0(){
             k0 = !k0 ; }
        void RunTaste1(){
             k1 = !k1 ; }
        void RunTaste2(){
             k2 = !k2 ; }


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



