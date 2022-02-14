//====================================================================
// Simulation dynamischer Systeme mit PLAN
//====================================================================
// Projektbeschreibung:
//
//====================================================================
#include <vcl.h>
#pragma hdrstop
#include "Plan.h"

class TUser : public TPlan {
public:

void Init(){
       Scale(-1.5,4.5,0.0);
       double y=IntToY(0)-4.0;
       Scale(-1.5,4.5,-y/2);


       Reset();}

 void Reset(){
       Draw();}

       void Draw(){
       Clear();
       SetPen(Grau,3);
       MoveTo(0.0,0.0);LineTo(0.0,3.0);
       SetPen(Schwarz);SetBrush(Schwarz);
       Rectangle(-0.2,-4.0,0.4,4.0);
       Rectangle(-0.2,4.0,0.4,4.0);

       }

 };




//====================================================================
#pragma argsused
int main(int argc, char* argv[]){ TUser a; a.Execute(); return 0; }
//__________________________________________________________Ost08_____
