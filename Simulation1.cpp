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
	int x,a,b,c,j,s;
	int y0,y1,y2,y;
public:

	int getMW,getMH;
	std::vector<int> SumOfFish;
	std::vector<int> SumOfBigFish;
	std::vector<int> SumOfHai;
	SeaFeld Feld;
	static const char d = 'd';

	void Init(){
	getMW = GetMaxW();
	getMH = GetMaxH();
	Feld.FeldInit(getMW,getMH);
	Reset();
	DrawInit();
	ChartInit();

	////////Test
	Feld.InitObject();
	Feld.CreatObject(1,0,3,0,1);
	Feld.CreatObject(3,0,2,0,20);
	Feld.CreatObject(5,0,2,0,200);
	Feld.CreatObject(7,0,2,0,500);
	Feld.CreatObject(10,0,2,0,400);
	Feld.CreatObject(10,0,2,0,200);

	 Feld.Update();        //1-5   stop  at 5

	 int ccccc= Feld.matrix[5].target[0];
	 ccccc= Feld.matrix[5].target[1];

	 Feld.Update();        //5-7   stop at 7
	 Feld.Update();
	 FeldDraw(Feld);



	FeldDraw(Feld);
	////////Test
	}

	void Reset(){
		SetPen(Schwarz);SetBrush(Weiss); SetTextSize(30);                // adjust the size and color of the word
		Text((int)(GetMaxW()*0.25),(int)(GetMaxH()*0.05),"Feld of Sea");
		ChartReset();
	}

	void Run(){
		DrawInit();
		Feld.Update();
		FeldDraw(Feld);
		ChartRun();
		CallRun = false;

	}
//====================================================================
//Object_Draw, Feld_Draw
//====================================================================
	void DrawInit(){
		SetBrush(TColor(RGB(0,255,255)));
		for(int y = 0; y < Feld.h; y++  ){     //Zeilen
			for(int x = 0; x < Feld.w; x++){          //Spalten
				int colorDiff =255-(float)y/(float)Feld.h*100;
				SetBrush(TColor(RGB(0,colorDiff,255)));
				SetPen(Schwarz);
				//SetPen(TColor(RGB(0,colorDiff,255)));
				Rectangle(Feld.startScreenToLeft+x*Feld.pixelW,Feld.startScreenToTop+y*Feld.pixelW,Feld.pixelW,Feld.pixelW);
			}
		}

	}

	void ObjectDraw(SeaFeld playFeld,Object t){
		if(t.code != 0){
		for(int j = 0;j<playFeld.pixelW;j++){
			for(int i = 0;i <playFeld.pixelW;i++){
				if(t.shape[j][i] != 0){
					SetPixel(t.xInPixel+i,t.yInPixel+j,Schwarz);

				}
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
//====================================================================
//Chart
//====================================================================
	 void ChartInit(){
                Plot0->Size(GetMaxW()*0.55,GetMaxH()*0.08,getMW/2.5,getMH/2.3);
                Plot0->Titel="Number Of Fish";
                Plot0->Achse(0,"Time in Days [d]");
                Plot0->Achse(0,0.0,100);
                Plot0->Achse(1,0.0,1000);
                Plot0->Achse(1,"Number of Fish [n]");
                InsertTaste(0,"Shark");
                InsertTaste(1,"Salmon");
                InsertTaste(2,"Small Fish");
                Plot1->Size(GetMaxW()*0.55,GetMaxH()*0.53,getMW/2.5,getMH/2.3);
                Plot1->Titel="Changes Of Fish";
                Plot1->Achse(0,"Time in Days [d]");
                Plot1->Achse(1,"Changes of Fish [n/d] ");
                Plot1->Achse(0,0.0,100);
                Plot1->Achse(1,-500,500);
                ChartReset();
         }

	 void ChartReset(){
		 SetPen(Schwarz);SetBrush(Weiss); SetTextSize(30);               // adjust the size and color of the word
                 SetTextColor(Schwarz);
	     //	 Text((int)(GetMaxW()*0.73),(int)(GetMaxH()*0.05),"Living Fish");
                 SetTextSize(20);
                 SetTextColor(Hellrot);
                 Text((int)(GetMaxW()*0.90),(int)(GetMaxH()*0.02),"----- Shark");
                 SetTextColor(Gruen);
                 Text((int)(GetMaxW()*0.90),(int)(GetMaxH()*0.04),"----- Salmon");
                 SetTextColor(Gelb);
                 Text((int)(GetMaxW()*0.90),(int)(GetMaxH()*0.06),"----- Small Fish");
		 Plot0->Reset();
                 Plot0->Achse(0,0.0,100);
		 Plot1->Reset();
                 Plot1->Achse(0,0.0,100);
		 k0 = true ;
		 k1 = true ;
		 k2 = true ;
//		 x = 0;
		 s = 1;
		 SumOfFish.push_back(0);
		 SumOfBigFish.push_back(0);
		 SumOfHai.push_back(0);
	 }


	 void ChartRun(){
		 Plot0->Reset();
		 Plot1->Reset();
		 a = 0;
		 b = 0;
		 c = 0;
		 for (int i=0;i < Feld.matrix.size();i++){
			 if (Feld.matrix[i].code == 3){
				 a++;
			 }
			 if (Feld.matrix[i].code == 1){
				 b++;
			 }
			 if (Feld.matrix[i].code == 2){
				 c++;
			 }
		 }
		 SumOfFish.push_back(c);
		 SumOfBigFish.push_back(b);
		 SumOfHai.push_back(a);
		 s++;
		 j = 1 ;
		 if(k0){
			 Plot0->Kurve0->SetPen(Hellrot,3);
			 Plot1->Kurve3->SetPen(Hellrot,3);
		 }
		 if(k1){
			 Plot0->Kurve1->SetPen(Gruen,3);
			 Plot1->Kurve4->SetPen(Gruen,10);
		 }
		 if(k2){
			 Plot0->Kurve2->SetPen(Gelb,3);
			 Plot1->Kurve5->SetPen(Gelb,3);
		 }
		 for (int i = 0;i < s ;i++){
			 Plot0->Kurve0->LineTo(i,SumOfHai[i]);
			 Plot0->Kurve1->LineTo(i,SumOfBigFish[i]);
			 Plot0->Kurve2->LineTo(i,SumOfFish[i]);
			 if (j < s){
				 Plot1->Kurve3->LineTo(i,SumOfHai[j]-SumOfHai[i]);
				 Plot1->Kurve4->LineTo(i,SumOfBigFish[j]-SumOfBigFish[i]);
				 Plot1->Kurve5->LineTo(i,SumOfFish[j]-SumOfFish[i]);
				 j++;
			 }

		 }
                 if(s%100==0){
                        Plot0->MoveAchse(0);
                        Plot1->MoveAchse(0);
                 }

	 }

//====================================================================
//Tasten
//====================================================================
	 void RunTaste0(){
		 k0 = !k0 ;
                 Plot0->Kurve0->SetPen(Klar,10);
                 Plot1->Kurve3->SetPen(Klar,10);
	 }

	 void RunTaste1(){
		 k1 = !k1 ;
                 Plot0->Kurve1->SetPen(Klar,10);
                 Plot1->Kurve4->SetPen(Klar,10);
	 }

	 void RunTaste2(){
		 k2 = !k2 ;
                 Plot0->Kurve2->SetPen(Klar,10);
                 Plot1->Kurve5->SetPen(Klar,10);
	 }

	 void RunTaste3(){




	 }


 };



//====================================================================
#pragma argsused
int main(int argc, char* argv[]){ TUser a; a.Execute(); return 0; }
//__________________________________________________________Ost08_____



