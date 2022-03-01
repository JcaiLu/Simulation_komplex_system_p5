//====================================================================
// Simulation dynamischer Systeme mit PLAN
//====================================================================
// Projektbeschreibung:
//
//====================================================================
#include <vcl.h>
#pragma hdrstop
#include "Plan.h"

class Tabelle{
    PlanString string;


public:
    Tabelle(){
    string = "";}

    void Set (PlanString s){
        string = s;}

        PlanString Get(){
        return string;}
};


class TUser :public TPlan {
Tabelle a;
Tabelle b;
Tabelle c;
Tabelle d;
Tabelle e;
Tabelle f;
Tabelle g;
Tabelle h;
Tabelle i;
public:

    void Init(){

/*      a.Set("a");
        b.Set("b") ;
        c.Set("c") ;
        d.Set("d") ;
        e.Set("e") ;
        f.Set("f") ;
        g.Set("g") ;
        h.Set("h") ;
        i.Set("i") ;            */
        Reset();
 }
    void Reset(){
        Text((int)(GetMaxW()*0.7),(int)(GetMaxH()*0.05),"Menge jedes Fisches");
        Rectangle (1050,100,500,400);
        Text(1220,130,"Hai");
        Text(1300,130,"Salmon");
        Text(1410,130,"Kleinfisch");
        Text(1060,210,"Lebendig");
        Text(1060,310,"Tot");
        Text(1060,420,"Insgesamt");
        MoveTo (1190,100);
        LineTo (1190,500);
        MoveTo (1290,100);
        LineTo (1290,500);
        MoveTo (1390,100);
        LineTo (1390,500);
        MoveTo (1050,190);
        LineTo (1550,190);
        MoveTo (1050,290);
        LineTo (1550,290);
        MoveTo (1050,390);
        LineTo (1550,390);
 /*     Text((int)(GetMaxW()*0.25),(int)(GetMaxH()*0.05),g.Get());
        Text((int)(GetMaxW()*0.25),(int)(GetMaxH()*0.05),h.Get());
        Text((int)(GetMaxW()*0.25),(int)(GetMaxH()*0.05),i.Get());   */
         }
  };

//====================================================================
#pragma argsused
int main(int argc, char* argv[]){ TUser a; a.Execute(); return 0; }
//__________________________________________________________Ost08_____

