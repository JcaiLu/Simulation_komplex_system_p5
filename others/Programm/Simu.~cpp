//====================================================================
// Simulation dynamischer Systeme mit PLAN
//====================================================================
// Projektbeschreibung:
//
//====================================================================
#include <vcl.h>
#pragma hdrstop
#include "Plan.h"
#include "TIntFeld.h "

//====================================================================
//========================================================================





class TUser : public TPlan {
   TIntFeld Feld, HFeld,R,B,Energy;
//   double Wiese;
   double Raeuber;
   double Beute;
   double W;
   int NR,NB,DB,DR,Zy,BR,RR,BSE,RSE;
   bool xx;

public:
   void Init(){
      ProgrammName="ZA Raeuber-Beute Simulation";
      Feld.Size(100,100);
      R.Size(100,100);
      B.Size(100,100);
      Energy.Size(100,100);
      InsertTaste(0,"+DichteB","Erhoehen die Populationsdichte der Beute bei der Geburt");
      InsertTaste(1,"-DichteB","Reduzieren die Populationsdichte der Beute bei der Geburt");
      InsertTaste(2,"+DichteR","Erhoehen die Populationsdichte des Raeubers bei der Geburt");
      InsertTaste(3,"-DichteR","Reduzieren die Populationsdichte des Raeubers bei der Geburt");
      InsertTaste(4,"+WieseE","Erhoehen die Energie der Wiese bei der Geburt");
      InsertTaste(5,"-WieseE","Reduzieren die Energie der Wiese bei der Geburt");
      InsertTaste(6,"+Zyklus W","Erhoehen den Wachstumszyklus der Wiese");
      InsertTaste(7,"-Zyklus W","Reduzieren den Wachstumszyklus der Wiese");
      InsertTaste(8,"+Geburtenrate B","Erhoehen die Geburtenrate der Beute");
      InsertTaste(9,"-Geburtenrate B","Reduziehen die Geburtenrate der Beute");
      InsertTaste(10,"+Geburtenrate R","Erhoehen die Geburtenrate des Raeubers");
      InsertTaste(11,"-Geburtenrate R","Reduziehen die Geburtenrate des Raeubers");
      InsertTaste(12,"+MinE FP B","Erhoehen Minimal Energie der Beute bei der Fortpflanzung");
      InsertTaste(13,"-MinE FP B","Reduzieren Minimal Energie der Beute bei der Fortpflanzung");
      InsertTaste(14,"+MinE FP R","Erhoehen Minimal Energie des Raeubers bei der Fortpflanzung");
      InsertTaste(15,"-MinE FP R","Reduzieren Minimal Energie des Raeubers bei der Fortpflanzung");
      InsertTaste(16,"Wiese ein/aus");
      InsertTaste(17,"Plot ein/aus");
      Plot0->Size(0,0,450,350);
      Plot0->Titel="Anzahl von Beide";
      Plot0->Achse(0,0.0,450.0);
      Plot0->Achse(0,"Zeit");
      Plot0->Achse(1,0.0,3000.0);
      Plot0->Achse(1,"Anzahl");
      Plot0->Kurve0->SetPen(Hellblau,3);
      Plot0->Kurve1->SetPen(Hellrot,3);
      Reset();
   }

   void Run(){
      R=B=0;
      HFeld=Feld; Feld=0;
      int k;
      k=CallRunCount%Zy;
      if(k==0) Energy=W;
      BGeburt();
      RGeburt();
      Number();

      if(!Plot0->Kurve1->LineTo(CallRunCount,NR)) Plot0->MoveAchse(0);
      Plot0->Kurve0->LineTo(CallRunCount,NB);
      Plot0->Kurve1->LineTo(CallRunCount,NR);
      SetText(Schwarz,20);
      SetBrush(Weiss);
      SetPen(Weiss);
      Rectangle(380,350,50,30);
      Rectangle(380,380,50,30);
      Rectangle(380,410,50,30);
      Rectangle(380,440,50,30);
      Rectangle(380,470,50,30);
      Rectangle(380,500,50,30);
      Rectangle(380,530,50,30);
      Rectangle(380,560,50,30);
      Text(380,350,DB);
      Text(380,380,DR);
      Text(380,410,W);
      Text(380,440,Zy);
      Text(380,470,BR);
      Text(380,500,RR);
      Text(380,530,BSE);
      Text(380,560,RSE);
      Move();
      Draw();
      CallRun=true;
}

   void Move(){
      int i, j;
      for(i=0;i<Feld.N;i++) for(j=0;j<Feld.M;j++){
         int x,y;
         if(HFeld(i,j)>0){
            x=i+Ran(); y=j+Ran();
            if(x<0) x=99; if(x>99) x=0;
            if(y<0) y=99; if(y>99) y=0;
            if(R(x,y)==0) R(x,y)= HFeld(i,j)-10;
         }
         if(HFeld(i,j)<0){
            x=i+Ran(); y=j+Ran();
            if(x<0) x=99; if(x>99) x=0;
            if(y<0) y=99; if(y>99) y=0;
            if(B(x,y)==0) B(x,y)=HFeld(i,j)+10;
         }
      }
      for(i=0;i<Feld.N;i++) for(j=0;j<Feld.M;j++){
         if(R(i,j)>0&&B(i,j)==0) Feld(i,j)=R(i,j);
         else if(R(i,j)==0&&B(i,j)<0) {
            Feld(i,j)=B(i,j);
            if(Energy(i,j)>0) {Feld(i,j)-=Energy(i,j);Energy(i,j)=0;}
         }
         else if(R(i,j)>0&&B(i,j)<0) {Feld(i,j)=R(i,j);Feld(i,j)-=B(i,j);}
      }
   }

   int Ran(){
      return random(3)-1;
   }


   void BGeburt(){
         int i,j,l,m;
         for(i=0;i<Feld.N;i++) for(j=0;j<Feld.M;j++){
            if(HFeld(i,j)<-BSE){
               for(l=i-1;l<=i+1;l++)
               for(m=j-1;m<=j+1;m++){
                  if(HFeld(l,m)==0){
                     if(random(1000)<BR) {HFeld(l,m)=HFeld(i,j)*0.2; HFeld(i,j)*=0.8;}
                  }
               }
            }
         }
   }

   void RGeburt(){
         int i,j,l,m;
         for(i=0;i<Feld.N;i++) for(j=0;j<Feld.M;j++){
            if(HFeld(i,j)>RSE){
               for(l=i-1;l<=i+1;l++)
               for(m=j-1;m<=j+1;m++){
                  if(HFeld(l,m)==0){
                     if(random(1000)<RR) {HFeld(l,m)=HFeld(i,j)*0.2; HFeld(i,j)*=0.8;}
                  }
               }
            }
         }
   }

   int Number(){
      int i,j;
      NR=NB=0;
      for(i=0;i<HFeld.N;i++) for(j=0;j<HFeld.M;j++){
            if(HFeld(i,j)>0) NR+=1;
            if(HFeld(i,j)<0) NB+=1;
      }
   }

   void Reset(){
      Raeuber = 1000;
      Beute = -1000;
      W=150;
      DB=DR=40;
      Zy=40;
      BR=110;
      RR=110;
      BSE=800;
      RSE=800;
      xx=false;
      Energy=W;
      Feld =0;
      int i, j;
      for(i=0;i<Feld.N;i++) for(j=0;j<Feld.M;j++)
         if(random(1000)<DB) Feld(i,j)=Beute;
      for(i=0;i<Feld.N;i++) for(j=0;j<Feld.M;j++) {
         if(random(1000)<DR) Feld(i,j)=Raeuber;}
      Plot0->Reset();
      Plot0->Achse(0,0.0,350.0);
      SetText(Schwarz,20);
      SetBrush(Weiss);
      SetPen(Weiss);
      Rectangle(380,350,50,30);
      Rectangle(380,380,50,30);
      Rectangle(380,410,50,30);
      Rectangle(380,440,50,30);
      Rectangle(380,470,50,30);
      Rectangle(380,500,50,30);
      Rectangle(380,530,50,30);
      Rectangle(380,560,50,30);
      Text(0,350,"die Populationsdichte der Beute(бы): ");
      Text(380,350,DB);
      Text(0,380,"die Populationsdichte des Raeubers(бы): ");
      Text(380,380,DR);
      Text(0,410,"die Energie der Wiese bei der Geburt: ");
      Text(380,410,W);
      Text(0,440,"den Wachstumszyklus der Wiese: ");
      Text(380,440,Zy);
      Text(0,470,"die Geburtenrate der Beute(бы): ");
      Text(380,470,BR);
      Text(0,500,"die Geburtenrate des Raeubers(бы): ");
      Text(380,500,RR);
      Text(0,530,"Minimal Energie der Beute bei der Fortpflanzung: ");
      Text(380,530,BSE);
      Text(0,560,"Minimal Energie des Raeubers bei der Fortpflanzung: ");
      Text(380,560,RSE);
      Draw();
   }

   void Draw(){
      if(Feld.Size()==0) return;
      int i,j,w,h,ax,ay;
      w=GetMaxW()/Feld.M;
      h=GetMaxH()/Feld.N;
      if(w>h) w=h;
      if(w<3) w=3;
      ax=GetMaxW()-w*Feld.M;
      ay=(GetMaxH()-w*Feld.N)/2;
      if(ax<0) ax=0;
      if(ay<0) ay=0;
      SetPen(Schwarz,1); SetBrush(Hellgruen);
      Rectangle(ax,ay,w*Feld.M,w*Feld.N);
      for(i=0;i<Feld.N;i++) for(j=0;j<Feld.M;j++) {
         if(xx){
         if(Energy(i,j)==0){
         SetBrush(Weiss);
         Rectangle(ax+j*w, ay+i*w, w, w);}
         }
         if(Feld(i,j)>0){
         SetBrush(Hellrot);
         Rectangle(ax+j*w, ay+i*w, w, w);}
         if(Feld(i,j)<0){
         SetBrush(Hellblau);
         Rectangle(ax+j*w, ay+i*w, w, w);}
      }
   }
   void RunTaste0(){
      Raeuber = 1000;
      Beute = -1000;
      W=150;
      DB+=5;
      Zy=40;
      BR=20;
      RR=20;
      BSE=RSE=800;
      xx=false;
      Energy=W;
      Feld =0;
      int i, j;
      for(i=0;i<Feld.N;i++) for(j=0;j<Feld.M;j++)
         if(random(1000)<DB) Feld(i,j)=Beute;
      for(i=0;i<Feld.N;i++) for(j=0;j<Feld.M;j++) {
         if(random(1000)<DR) Feld(i,j)=Raeuber;}
      Plot0->Reset();
      Plot0->Achse(0,0.0,350.0);
      SetText(Schwarz,20);
      SetBrush(Weiss);
      SetPen(Weiss);
      Rectangle(380,350,50,30);
      Rectangle(380,380,50,30);
      Rectangle(380,410,50,30);
      Rectangle(380,440,50,30);
      Rectangle(380,470,50,30);
      Rectangle(380,500,50,30);
      Rectangle(380,530,50,30);
      Rectangle(380,560,50,30);
      Text(380,350,DB);
      Text(380,380,DR);
      Text(380,410,W);
      Text(380,440,Zy);
      Text(380,470,BR);
      Text(380,500,RR);
      Text(380,530,BSE);
      Text(380,560,RSE);
      Draw();
   }
   void RunTaste1(){
      Raeuber = 1000;
      Beute = -1000;
      W=150;
      if(DB>0) DB-=5;
      Zy=40;
      BR=20;
      RR=20;
      BSE=RSE=800;
      xx=false;
      Energy=W;
      Feld =0;
      int i, j;
      for(i=0;i<Feld.N;i++) for(j=0;j<Feld.M;j++)
         if(random(1000)<DB) Feld(i,j)=Beute;
      for(i=0;i<Feld.N;i++) for(j=0;j<Feld.M;j++) {
         if(random(1000)<DR) Feld(i,j)=Raeuber;}
      Plot0->Reset();
      Plot0->Achse(0,0.0,350.0);
      SetText(Schwarz,20);
      SetBrush(Weiss);
      SetPen(Weiss);
      Rectangle(380,350,50,30);
      Rectangle(380,380,50,30);
      Rectangle(380,410,50,30);
      Rectangle(380,440,50,30);
      Rectangle(380,470,50,30);
      Rectangle(380,500,50,30);
      Rectangle(380,530,50,30);
      Rectangle(380,560,50,30);
      Text(380,350,DB);
      Text(380,380,DR);
      Text(380,410,W);
      Text(380,440,Zy);
      Text(380,470,BR);
      Text(380,500,RR);
      Text(380,530,BSE);
      Text(380,560,RSE);
      Draw();
   }
   void RunTaste2(){
      Raeuber = 1000;
      Beute = -1000;
      W=150;
      DR+=5;
      Zy=40;
      BR=20;
      RR=20;
      BSE=RSE=800;
      xx=false;
      Energy=W;
      Feld =0;
      int i, j;
      for(i=0;i<Feld.N;i++) for(j=0;j<Feld.M;j++)
         if(random(1000)<DB) Feld(i,j)=Beute;
      for(i=0;i<Feld.N;i++) for(j=0;j<Feld.M;j++) {
         if(random(1000)<DR) Feld(i,j)=Raeuber;}
      Plot0->Reset();
      Plot0->Achse(0,0.0,350.0);
      SetText(Schwarz,20);
      SetBrush(Weiss);
      SetPen(Weiss);
      Rectangle(380,350,50,30);
      Rectangle(380,380,50,30);
      Rectangle(380,410,50,30);
      Rectangle(380,440,50,30);
      Rectangle(380,470,50,30);
      Rectangle(380,500,50,30);
      Rectangle(380,530,50,30);
      Rectangle(380,560,50,30);
      Text(380,350,DB);
      Text(380,380,DR);
      Text(380,410,W);
      Text(380,440,Zy);
      Text(380,470,BR);
      Text(380,500,RR);
      Text(380,530,BSE);
      Text(380,560,RSE);
      Draw();
   }
   void RunTaste3(){
      Raeuber = 1000;
      Beute = -1000;
      W=150;
      if(DR>0) DR-=5;
      Zy=40;
      BR=20;
      RR=20;
      BSE=RSE=800;
      xx=false;
      Energy=W;
      Feld =0;
      int i, j;
      for(i=0;i<Feld.N;i++) for(j=0;j<Feld.M;j++)
         if(random(1000)<DB) Feld(i,j)=Beute;
      for(i=0;i<Feld.N;i++) for(j=0;j<Feld.M;j++) {
         if(random(1000)<DR) Feld(i,j)=Raeuber;}
      Plot0->Reset();
      Plot0->Achse(0,0.0,350.0);
      SetText(Schwarz,20);
      SetBrush(Weiss);
      SetPen(Weiss);
      Rectangle(380,350,50,30);
      Rectangle(380,380,50,30);
      Rectangle(380,410,50,30);
      Rectangle(380,440,50,30);
      Rectangle(380,470,50,30);
      Rectangle(380,500,50,30);
      Rectangle(380,530,50,30);
      Rectangle(380,560,50,30);
      Text(380,350,DB);
      Text(380,380,DR);
      Text(380,410,W);
      Text(380,440,Zy);
      Text(380,470,BR);
      Text(380,500,RR);
      Text(380,530,BSE);
      Text(380,560,RSE);
      Draw();
   }
   void RunTaste4(){W+=10;}
   void RunTaste5(){if(W>0) W-=10;}
   void RunTaste6(){Zy+=10;}
   void RunTaste7(){if(Zy>=10) Zy-=10; if(Zy==0) Zy=1;}
   void RunTaste8(){BR+=5;}
   void RunTaste9(){if(BR>0) BR-=5;}
   void RunTaste10(){RR+=5;}
   void RunTaste11(){if(RR>0) RR-=5;}
   void RunTaste12(){BSE+=50;}
   void RunTaste13(){if(BSE>0) BSE-=50;}
   void RunTaste14(){RSE+=50;}
   void RunTaste15(){if(RSE>0) RSE-=50;}
   void RunTaste16(){xx=!xx;}
   void RunTaste17(){Plot0->Visible=!Plot0->Visible;}

};









//====================================================================
#pragma argsused
int main(int argc, char* argv[]){ TUser a; a.Execute(); return 0; }
//__________________________________________________________Ost08_____



