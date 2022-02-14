//////////////////////////////////////////////////////////////////////
//                                                                  //
//    P L A N                                                       //
//    - Plot- und Animationsmanager -                               //
//                                                                  //
//    copyright: Prof. Ostermeyer                                   //
//               für Fa. SiDyS GmbH                                 //
//               1998 - 2008                                        //
//                                                                  //
//------------------------------------------------------------------//
//                                                                  //
//    Versionsfamilie 7                                             //
//                                                                  //
//==================================================================//
//                                                                  //
// Programm zur einfachen Simulation dynamischer Systeme            //
// unter Windows                                                    //
//                                                                  //
//  * Numerische Integration                                        //
//  * Grafische Animation                                           //
//  * komplexe 2D-und 3D-Plotdarstellungen                          //
//  * verschiedene Videomodi                                        //
//  * vollständiger math. Parser                                    //
//  * Fast-Fourier-Transformation                                   //
//  * umfangreiche Vektor- und Matrixoptionen                       //
//                                                                  //
//==================================================================//
//                                                                  //
//  Code entwickelt mit Borland C++ Builder 1 - 3 - 5   und         //
//                      Borland C++ Builder 2007                    //
//                                                                  //
//==================================================================//
// PLAN - Hauptdatei                                                //
// Entwicklung 7.0 Dez. 2007                                        //
//                                                                  //
//___Ostermeyer2007_________________________________________________//

#ifndef PlanH
#define PlanH

//#ifdef __DLL__                  // zur Definition von import/export
//  #define __Export  __declspec(dllexport)
//#else
//  #define __Export  __declspec(dllimport)
//#endif

#define __Export  __declspec(dllexport)

//====================================================================
// Headers
//====================================================================

#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include <StdCtrls.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <stdexcept>
#include <new>

//====================================================================
// C - Headers: nur für C++ Beginners
//====================================================================

#include <excpt.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <dir.h>
#include <string.h>

//====================================================================
// Oft genutzte Grundfarben in PLAN
// Mnemotechnik:
//     Schwarz/Weiss
//     sonstige Hauptfarben immer im Paar:
//              Gelb, Hellgelb etc.
//     Klar wird als Indikator für durchsichtig genutzt.
//     Alle Zeichenbefehle setzen bei Klar Pen oder Brush auf Clear!
//====================================================================

const TColor  Schwarz	  = clBlack;
const TColor  Weiss	      = clWhite;

const TColor  Grau	      = clGray;
const TColor  Hellgrau	  = clBtnFace;  // Windowfensterfarbe!
const TColor  Rot	      = clMaroon;
const TColor  Hellrot	  = clRed;
const TColor  Gelb        = (TColor)(0x0000D0FF);
const TColor  Hellgelb	  = clYellow;
const TColor  Gruen	      = clGreen;
const TColor  Hellgruen	  = clLime;
const TColor  Blau	      = clNavy;
const TColor  Hellblau	  = clBlue;
const TColor  Violett	  = clPurple;
const TColor  Hellviolett = clFuchsia;

const TColor  Klar	      = clTeal;     // Klar = durchsichtig als
                                        // gewöhnliche Farbe behandeln

//====================================================================
// mathematische Hilfsdefinitionen/-funktionen
//====================================================================

typedef	 double              real;     // nur für Kompatibilität zu
typedef  char*               pchar;    // älteren Versionen von PLAN

extern "C" real   __Export Signum(real z,real eps = 1.0e-20);
extern "C" real   __Export GradToRad(real grad);
extern "C" real   __Export RadToGrad(real radiant);

//====================================================================
// oft gebrauchte Farbverlaeufe, Argument geht von 0.0 - 100.0
//====================================================================

extern "C" TColor __Export SchwarzRotSkala(real t100);
extern "C" TColor __Export RotGelbSkala(real t100);
extern "C" TColor __Export GelbWeissSkala(real t100);
extern "C" TColor __Export WeissBlauSkala(real t100);
extern "C" TColor __Export FarbSkala(real t100);
extern "C" TColor __Export GrauSkala(real t100);
extern "C" TColor __Export RGBSkala(real r100, real g100, real b100);


//====================================================================
// Klasse PlanString
//====================================================================
// einfache Stringklasse in Anlehnung an die Klasse
// System::AnsiString bzw. string
// nur um:
// a) Probleme mit MEMMGR.LIB zu vermeiden
// b) feste real-Formate zu haben
//--------------------------------------------------------------------
// sollte gegen C** Standard getauscht werden
//====================================================================


class __Export PlanString {
    char *Buf;
    int Anz, MaxAnz;
    bool Add(char *s);
    bool Add(char c);
    bool Add(int n);
    bool Add(real z);
    bool AddSize(int n);
public:

//====================================================================
// Konstruktoren
//====================================================================

    PlanString(void):Buf(0),Anz(0),MaxAnz(0){;}
    PlanString(char *s);
    PlanString(int i);
    PlanString(real z);
    PlanString(const PlanString &s);
    ~PlanString(void);

//====================================================================
// wie AnsiString
//====================================================================


    char *c_str(void) const;
    int len(void);

    PlanString &operator << (const PlanString &s);
    PlanString &operator << (char *s);
    PlanString &operator << (char c);
    PlanString &operator << (int i);
    PlanString &operator << (real z);
    PlanString &operator =  (const PlanString &s);
    PlanString &operator =  (char *s);
    PlanString &operator =  (char c);
    PlanString &operator =  (int i);
    PlanString &operator =  (real z);
    PlanString &operator += (PlanString s);
    PlanString &operator += (char *s);
    PlanString &operator += (char c);
    PlanString &operator += (int i);
    PlanString &operator += (real x);
    PlanString operator  +  (PlanString s);
    PlanString operator  +  (char *s);
    PlanString operator  +  (char c);
    PlanString operator  +  (int i);
    PlanString operator  +  (real x);

//====================================================================
// Einfache Zugriffs- und Umwandlungsfunktionen
//====================================================================

    char &operator ()(int i);
    int  ToInt(void);
    real ToReal(void);
};

//====================================================================
// einfaches Meldungsfenster
//====================================================================

extern "C" int  __Export Meldung(PlanString s);

//====================================================================
// Klasse TVektor
//====================================================================
// einfache Realisierung mathematischer Vektoren
// - sollte auf Container umgeschrieben werden -
//====================================================================

class TMatrix;

class __Export TVektor {
private:
    friend class TMatrix;
    real *V; int N;
    bool error;
public:

//====================================================================
// Zugriff
//====================================================================

    bool Error(void) { return error;}
    void Reset(void) { error = false;}
    int  Zeilen(void) const { return N;}
    int  Spalten(void) const { return 1;}
    real Max(int von=0, int bis=0);
    real Min(int von=0, int bis=0);
    real &operator () (int i);
    real &operator [] (int i);

//====================================================================
// Mathematische Operationen
//====================================================================

    TVektor operator = (TVektor v);
    TVektor operator + (TVektor v);
    TVektor operator - (TVektor v);
    TVektor operator += (TVektor v);
    TVektor operator -= (TVektor v);
    friend TVektor operator * (real z, TVektor v);
    TVektor operator * (real z);
    TVektor operator *= (real z);
    TVektor operator / (real z);
    TVektor operator /= (real z);
    real    operator * (TVektor v);
    TVektor operator * (TMatrix m);
    friend real Norm(TVektor v);
    friend real MaxNorm(TVektor v);
    friend int EinheitsVektor(TVektor &v);
    real Winkel(int VonAchse, int NachAchse);  // radiant!
    friend void FFT(TVektor &v, bool on = true);
    friend int FFTSize(TVektor &v);

    bool  Size(int n) { return Resize(n);}
    bool  Size(TVektor &v){ return Resize(v);}
    void  Clear(void) { Flush();}
    void  Clear(real eps) { EpsFlush(eps);}

//====================================================================
// Entwicklerbaustelle
//====================================================================

    real *GetV(void) { return V;}
    bool  Resize(int n);
    bool  Resize(TVektor &v){return Resize(v.N);}
    void  Flush(void);
    void  EpsFlush(real eps = 1.0e-10);
    void __fastcall rfft(int tau,int tau_2,double *y,int direct);


//====================================================================
// Aufbau
//====================================================================

    TVektor(real x, real y, real z);
    TVektor(real x, real y);
    TVektor(int n);
    TVektor(void);
    TVektor(const TVektor &v);
    ~TVektor(void);
};

typedef TVektor* PVektor;

//====================================================================
// mathematische Hilfsfunktionen und Freundfunktionen mit Vektoren
//====================================================================

TVektor __Export operator * (real z, TVektor v);
real    __Export Norm(TVektor v);
real    __Export MaxNorm(TVektor v);
int     __Export EinheitsVektor(TVektor &v);
void    __Export FFT(TVektor &v, bool on);
int     __Export FFTSize(TVektor &v);
real    __Export FourierCos(int nr,TVektor &fkt,
                                      int von=0,int bis=0);
real    __Export FourierSin(int nr,TVektor &fkt,
                                      int von=0,int bis=0);


//====================================================================
// Klasse TMatrix
//====================================================================
// einfache Realisierung mathematischer Matrizen
// - sollte auf Container umgeschrieben werden -
//====================================================================


class __Export TMatrix {
	real **V; int N,M;      // Datenfeld , Groesse
    bool error;
    friend class TVektor;
public:

//====================================================================
// Zugriff
//====================================================================

    bool Error(void) { return error;}
    void Reset(void) { error = false;}
    int  Zeilen(void) const { return N;}
    int  Spalten(void) const { return M;}
    real &operator () (int i, int j);
    TVektor operator [] (int i);

//====================================================================
// Mathematische Operationen
//====================================================================

    TMatrix operator =  (TMatrix m);
    TMatrix operator +  (TMatrix m);
    TMatrix operator -  (TMatrix m);
    TMatrix operator += (TMatrix m);
    TMatrix operator -= (TMatrix m);
    TMatrix operator *  (TMatrix m);
    TMatrix operator *= (TMatrix m);
    TVektor operator *  (TVektor v);
    friend TVektor operator * (TVektor v, TMatrix m);
    friend TVektor operator *= (TVektor v, TMatrix m);
    TMatrix operator *  (real z);
    TMatrix operator *= (real z);
    TMatrix operator /  (real z);
    TMatrix operator /= (real z);
    friend TMatrix operator * (real z, TMatrix m);
    TMatrix operator ^ (int i);
    TMatrix operator ^ (char c);
    TMatrix operator ^ (char *c);

//====================================================================
// Spezielle Matrizen
//====================================================================

    friend TMatrix EinheitsMatrix(int size);
                    // erzeugt Einheitsmatrix (size)x(size)
    friend TMatrix DrehMatrix(real rad);
    				// erzeugt 2x2 Drehmatrix
    friend TMatrix DrehMatrix(int Achse, real rad);
    				// erzeugt 3x3 Drehmatrix

//====================================================================
// Entwicklerbaustelle
//====================================================================
    bool  Size(int n, int m) { return Resize(n,m);}
    bool  Size(TMatrix &m){ return Resize(m.N,m.M);}
    void  Clear(void){Flush();}
    void  Clear(real eps){ EpsFlush(eps);}


    bool  Resize(int n, int m);
    bool  Resize(TMatrix &m){ return Resize(m.N,m.M);}
    void  Flush(void);
    void  EpsFlush(real eps = 1.0e-10);
    real  **AllocMatrix(int n, int m);
    real  **GetV(void) { return V; }
    int pivot(int n, real **matrix, real **inverse,
    	real* s = 0, real* cond = 0);

//====================================================================
// Aufbau
//====================================================================

    						// speziell 3x3 - Matrizen
    TMatrix(real xx, real xy, real xz,
            real yx, real yy, real yz,
            real zx, real zy, real zz);
    						// speziell 2x2 - Matrizen
    TMatrix(real xx, real xy, real yx, real yy);
    TMatrix(int n,int m);
    TMatrix(void);
    TMatrix(TMatrix &m);
    ~TMatrix(void){Resize(0,0);}
};

TMatrix __Export EinheitsMatrix(int size);
    				// erzeugt Einheitsmatrix (size)x(size)
TMatrix __Export DrehMatrix(real rad);
    				// erzeugt 2x2 Drehmatrix
TMatrix __Export DrehMatrix(int Achse, real rad);
    				// erzeugt 3x3 Drehmatrix um Achse 0,1,2

typedef TMatrix* PMatrix;

//====================================================================
// Klasse TInterpolation
//====================================================================
//   Set(x,y)    Setzt Wertepaar, sortiert autom. x-Wert nach Grösse!
//               Return-Wert: neue Anzahl von Datenpaaren
//   Get(x)      liefert Interpolationswert y = y(x) nach vorhandener
//               Tabelle
//               Return-Wert: Wert y
//   Clear()     löscht die Tabelle
//====================================================================


class __Export TInterpolation {
    real *xx,*yy;
    int anz,size;
    int Resize(int n);
public:
    TInterpolation(void);
    int  Set(real x, real y);
    real Get(real x);
    void Clear(void);
};


//====================================================================
// Klasse TKurve
//====================================================================
// Kurven in 2D- und 3D-Plots
// nutzt die Klasse TPlotForm, die nicht aus der DLL
// exportiert wird!
//====================================================================

class __Export TKurve {
public:

//=== Gestaltung Kurven, Flaechen und Marker

    void SetPen(TColor f, int size=1);
    void SetMarker(TColor f, int typ=0);
    void SetPlaneColor(TColor up, TColor down = Grau);
    void SetShadow(bool on = true);

//=== Abfragen User
    bool InAchse0(real x);
    bool InAchse1(real y);
    bool InAchse2(real z);
    bool InFeld(real x, real y, real z=0.0);

//=== Punkte ( = Marker)
    bool Point(void);            // Marker am letzten Punkt
    bool Point(real x, real y);
    bool Point(real x, real y, real z);

//=== 2D Linien
    bool MoveTo(real x, real y, bool ma = false);
    bool LineTo(real x, real y, bool ma = false);

//=== 3D Linien
    bool MoveTo(real x, real y, real z, bool ma = false);
    bool LineTo(real x, real y, real z, bool ma = false);

//=== 2D - Polygon
    bool PolyLine(TVektor &x,TVektor &y, int anz=0);

//=== 2,5D Polygon (z = konst.)
    bool PolyLine(TVektor &x,TVektor &y, real z,
                  int anz=0);

//=== 3D Polygon
    bool PolyLine(TVektor &x,TVektor &y,TVektor &z,int anz=0);

//=== Flächen fuer 2D und 3D Darstellung
    bool Plane(TMatrix &m, TVektor &x, TVektor &z,
               int xanz=0, int zanz=0);

    void Reset(void);

//=== nur für alte Versionen :
    __property int Size = {read = Linesize, write=Linesize};
    __property TColor Color = {read=LineColor,write=LineColor};

private:

//=== Plotzuordnung und Defaultein stellungen
    int PlotN;
    void Default(void);
    int  Linesize, Pointtyp, Planetyp;

//=== Hilfspunkte für MoveTo- LineTo-Befehle
    TPoint ThisPoint,LastPoint;
    bool LastPointVisible;

//== Visibilität fuer PolyLine und Hilfsfelder
    TPoint *IPoint[2];
    TPoint Triangle[4];
    real zAlt;
    int IAnz;
    bool ISize(int i);

//=== Daten
    TColor LineColor;
    TColor PointColor;
    TColor PlaneColor;
    TColor PlaneDownColor;
    bool   Shadow;
    TRect FeldZ;
    bool Neu, Shadow3d;

//=== Hilfsfunktionen Visibilität
    int  CrossZ(TPoint &a, TPoint &b, TPoint &c);
    // prueft, ob Pixelpkt y unter Pixellinie y1, y2 liegt
    bool IsUnder(TPoint &y1, TPoint &y2, TPoint &y);

    bool DrawMarker(int i, int j);
    void DrawRectanglePlane(TPoint &a, TPoint &b, TPoint &c,TPoint &d);
    void DrawTrianglePlane(TPoint &a, TPoint &b, TPoint &c);
public:
    TKurve(int plotno);


};

typedef TKurve* PKurve;

//====================================================================
// Klasse TPlot
//====================================================================
// 2D- und 3D-Plots
// nutzt die Klasse TPlotForm, die nicht aus der DLL
// exportiert wird!
//====================================================================

class __Export TPlot {

public:
//====================================================================
//  Grundfunktionen Plot
//====================================================================

    void  Size(void);                       // Plotgroesse
    void  Size(int x, int y, int w, int h);
    void  Achse(int Nr, PlanString s);      // Achsenbeschriftung
    void  Achse(int Nr, real von, real bis);// Achsenwerte
    void  MoveAchse(int Nr);                // schiebt Achse Nr.
                                            // um Achsenintervall
                                            // n. rechts weiter
    void  Clear(void);                      // neuzeichnen
    void  Reset(void);                      // + kurven resetten
    void  Show(void);                       // Plot sichtbar machen
    void  Hide(void);                       // Plot unsichtbar machen
    void  SetVisible(bool on);
    bool  GetVisible(void);
    void  Layout(int typ = 0);              // 5 Varianten mgl

//====================================================================
//  Properties
//====================================================================

    __property PlanString Titel      = {read=GetTitel,
                                        write=SetTitel};
    __property PlanString Untertitel = {read=GetUnterTitel,
                                        write=SetUnterTitel};

    __property bool TitelVisible     = {read=GetTitelVisible,
                                        write=SetTitelVisible};
    __property bool TextVisible      = {read=GetTextVisible,
                                        write=SetTextVisible};
    __property bool ZahlenVisible    = {read=GetZahlenVisible,
                                        write=SetZahlenVisible};
    __property bool Visible          = {read=GetVisible,
                                        write=SetVisible};
    __property TColor TitelColor     = {read=GetTitelColor,
                                        write=SetTitelColor};
    __property TColor TextColor      = {read=GetTextColor,
                                        write=SetTextColor};
    __property TColor ZahlenColor    = {read=GetZahlenColor,
                                        write=SetZahlenColor};
    __property TColor AchsenColor    = {read=GetAchsenColor,
                                        write=SetAchsenColor};
    __property TColor FeldColor      = {read=GetFeldColor,
                                        write=SetFeldColor};
    __property TColor PlotColor      = {read=GetPlotColor,
                                        write=SetPlotColor};

    __property int AchsenTyp         = {read=GetAchsenTyp,
                                        write=SetAchsenTyp};

    __property bool Plot2D           = {read=GetPlot2D,
                                        write=SetPlot2D};
    __property bool Plot3D           = {read=GetPlot3D,
                                        write=SetPlot3D};
    __property bool Steil            = {read=GetSteil,
                                        write=SetSteil};
    __property bool Flach            = {read=GetFlach,
                                        write=SetFlach};
    __property bool Links            = {read=GetLinks,
                                        write=SetLinks};
    __property bool Rechts           = {read=GetRechts,
                                        write=SetRechts};
    __property bool Fortsetzung      = {read=GetFortsetzung,
                                        write=SetFortsetzung};
    __property bool ClearMode        = {read=GetClearMode,
                                        write=SetClearMode};

    __property PKurve Kurve0 = {read=GetKurve0};
    __property PKurve Kurve1 = {read=GetKurve1};
    __property PKurve Kurve2 = {read=GetKurve2};
    __property PKurve Kurve3 = {read=GetKurve3};
    __property PKurve Kurve4 = {read=GetKurve4};
    __property PKurve Kurve5 = {read=GetKurve5};
    __property PKurve Kurve6 = {read=GetKurve6};
    __property PKurve Kurve7 = {read=GetKurve7};
    __property PKurve Kurve8 = {read=GetKurve8};
    __property PKurve Kurve9 = {read=GetKurve9};

//====================================================================
//   Setters und Getters für Properties
//====================================================================

public:
    void SetTitel(PlanString s);
    void SetUnterTitel(PlanString s);
    void SetTitelVisible(bool a);
    void SetTextVisible(bool a);
    void SetZahlenVisible(bool a);
    void SetTitelColor(TColor f);
    void SetTextColor(TColor f);
    void SetZahlenColor(TColor f);
    void SetAchsenColor(TColor f);
    void SetFeldColor(TColor f);
    void SetPlotColor(TColor f);
    PlanString GetTitel(void);
    PlanString GetUnterTitel(void);
    bool GetTitelVisible(void);
    bool GetTextVisible(void);
    bool GetZahlenVisible(void);
    TColor GetTitelColor(void);
    TColor GetTextColor(void);
    TColor GetZahlenColor(void);
    TColor GetAchsenColor(void);
    TColor GetFeldColor(void);
    TColor GetPlotColor(void);
    bool GetPlot2D(void);
    void SetPlot2D(bool a);
    bool GetPlot3D(void);
    void SetPlot3D(bool a);
    bool GetSteil(void);
    void SetSteil(bool a);
    bool GetFlach(void);
    void SetFlach(bool a);
    bool GetLinks(void);
    void SetLinks(bool a);
    bool GetRechts(void);
    void SetRechts(bool a);
    bool GetFortsetzung(void);
    void SetFortsetzung(bool a);
    bool GetClearMode(void);
    void SetClearMode(bool a);
    void SetAchsenTyp(int i);
    int  GetAchsenTyp(void);

//====================================================================
//  Getters für Plotkurven
//====================================================================

    PKurve GetKurve0(void);
    PKurve GetKurve1(void);
    PKurve GetKurve2(void);
    PKurve GetKurve3(void);
    PKurve GetKurve4(void);
    PKurve GetKurve5(void);
    PKurve GetKurve6(void);
    PKurve GetKurve7(void);
    PKurve GetKurve8(void);
    PKurve GetKurve9(void);

//====================================================================
//   Konstruktor und Destruktor
//====================================================================

    TPlot (int i = 0);
    ~TPlot(void);

private:
    int PlotN;
    PKurve Kurven[10];
};

typedef TPlot* PPlot;

//====================================================================
// Klasse TPlan
//====================================================================
// nutzt die Klasse TPlanForm, die nicht aus der DLL
// exportiert wird
// enthält den Funktionsumfang von PLAN
//--------------------------------------------------------------------
// Execute() führt PLAN aus
//====================================================================


class __Export TPlan {

//====================================================================
//   Setters und Getters für Properties
//====================================================================

public:
    void  SetInfo(PlanString s);
    void  SetBusy(PlanString s);
    void  SetProgrammName(PlanString s);
    void  SetTastenfeldName(PlanString s);
    void  SetProgrammInfo(PlanString s);
    bool  GetZoom(void);
    void  SetZoom(bool z);
    int   GetCallRunCount(void);
    int   GetCallRunTime(void);
    void  SetCallRunTime(int t);
    void  SetCallRun(bool on);
    bool  GetBMPFile(void);
    void  SetBMPFile(bool a);
    bool  GetBMPColor(void);
    void  SetBMPColor(bool a);
    bool  GetBMPSystem(void);
    void  SetBMPSystem(bool a);
    bool  GetBMPScreen(void);
    void  SetBMPScreen(bool a);
    void  SetBMPFileName(pchar s);
    void  SetVideoStatus(bool on);
    bool  GetVideoStatus(void);
    void  SetBMPEnabled(bool on);
    bool  GetBMPEnabled(void);
    int   GetCallFrameNo(void);
    void  SetVideoIntervall(int t);
    int   GetVideoIntervall(void);
    void  SetFrameFileName(pchar s);
    void  SetSelectEnabled(bool on);
    PPlot GetPlot0(void);
    PPlot GetPlot1(void);
    PPlot GetPlot2(void);
    PPlot GetPlot3(void);
    PPlot GetPlot4(void);
    PPlot GetPlot5(void);
    PPlot GetPlot6(void);
    PPlot GetPlot7(void);
    PPlot GetPlot8(void);
    PPlot GetPlot9(void);

//====================================================================
//   numerische Integration
//====================================================================

private:
    void  SetVerfahren(int typ);
    void  SetAnfangszeit(real a);
    void  SetEndzeit(real a);
    void  SetAnfangsschritt(real a);
    void  SetSchrittweite(real a);
    real  GetToleranz(void);
    void  SetToleranz(real a);
    void  SetMaxSchritt(int i);
    void  SetDGLOrdnung(int i);
    void  SetDGL1Ordnung(int i);

    static real ch[13];             // Daten RKF 7/8
    static real alph[13];
    static real beta[13][12];
    real eps, eds;
    real *XStateP, *XDStateP, *XdumP, **FPP;
    TVektor XState, XDState, Xdum;
    TMatrix FP;
    void DGLIntern(void);
    bool InitDGLDaten(void);
    bool CheckIntegration(void);
    bool DGLInit, DGLFertig, DGLFehler;
    bool DGLSchrittSteuerung, DGLBack;
    int  DGLVerfahren, DGLOrdnung, DGL1Ordnung;
    int  DGLMaxSchritt, DGLAktSchritt;
    real DGLToleranz;
    real DGLAnfangsSchritt, DGLSchritt, DGLTempSchritt;
    real DGLAnfangsZeit, DGLTempEndZeit, DGLEndZeit, DGLZeit;
    int   EinzelIntegrationsschritt(void);
    int   RKFSchritt(void);
    int   DifferenzSchritt(void);
    int   HeunSchritt(void);
    PPlot Plots[10];

public:

//====================================================================
//   Programm allgemein
//====================================================================

    __property PlanString  Info           = {write=SetInfo};
    __property PlanString  Busy           = {write=SetBusy};
    __property PlanString  ProgrammName   = {write=SetProgrammName};
    __property PlanString  TastenfeldName = {write=SetTastenfeldName};
    __property PlanString  ProgrammInfo   = {write=SetProgrammInfo};
    __property bool   Zoom                = {read=GetZoom,
                                             write=SetZoom};

//====================================================================
//  Plan Grundfunktionalität
//====================================================================

    virtual void  Init(void){;}
    virtual void  InitDraw(void){;}
    virtual void  Reset(void){;}
    virtual void  Run(void){;}
    virtual void  Finish(void){;}

    __property int  CallRunTime  = {read=GetCallRunTime,
                                    write=SetCallRunTime};
                                    
//    __property bool CallRun      = {write=SetCallRun};
//    __property int  CallRunCount = {read=GetCallRunCount};

    int  CallRunCount;
    bool CallRun;


//====================================================================
//   Usertasten
//====================================================================

    void  InsertTaste(int nr, pchar name, pchar info="");
    void  DeleteTaste(int nr);
    void  DeleteAllTasten(void);

    virtual void  RunTaste0(void){;}
    virtual void  RunTaste1(void){;}
    virtual void  RunTaste2(void){;}
    virtual void  RunTaste3(void){;}
    virtual void  RunTaste4(void){;}
    virtual void  RunTaste5(void){;}
    virtual void  RunTaste6(void){;}
    virtual void  RunTaste7(void){;}
    virtual void  RunTaste8(void){;}
    virtual void  RunTaste9(void){;}
    virtual void  RunTaste10(void){;}
    virtual void  RunTaste11(void){;}
    virtual void  RunTaste12(void){;}
    virtual void  RunTaste13(void){;}
    virtual void  RunTaste14(void){;}
    virtual void  RunTaste15(void){;}
    virtual void  RunTaste16(void){;}
    virtual void  RunTaste17(void){;}
    virtual void  RunTaste18(void){;}
    virtual void  RunTaste19(void){;}


//====================================================================
//   Erstellung von BMP Files
//====================================================================

    __property bool BMPColor      = {read=GetBMPColor,
                                     write=SetBMPColor};
    __property bool BMPSystem     = {read=GetBMPSystem,
                                     write=SetBMPSystem};
    __property bool BMPScreen     = {read=GetBMPScreen,
                                     write=SetBMPScreen};
    __property pchar BMPFileName  = {write=SetBMPFileName};

    void  WriteToBMP(pchar s);
    void  ReadFromBMP(pchar s);
//====================================================================
//   Video
//====================================================================

    __property bool Video          = {read=GetVideoStatus,
                                      write=SetVideoStatus};
    __property bool BMPEnabled     = {read=GetBMPEnabled,
                                      write=SetBMPEnabled};
    __property int CallFrameCount  = {read=GetCallFrameNo};
    __property int CallFrameTime   = {read=GetVideoIntervall,
                                      write=SetVideoIntervall};
    __property pchar FrameFileName ={write=SetFrameFileName};

    void  SaveFrame(void);

    virtual void  ReadFrame(pchar s){;}
    virtual void  WriteFrame(pchar s){;}

//====================================================================
//   Mausevents Bildfläche
//====================================================================

    virtual void  BildMouseDown(int x, int y){;}
    virtual void  BildMouseMove(int x, int y, int leftdown){;}
    virtual void  BildMouseUp(int x, int y){;}
    virtual void  BildMouseClick(void){;}

//====================================================================
//   Ausschnittvergroesserung Bildfläche
//====================================================================

    __property bool Ausschnitt      = {write=SetSelectEnabled};
    virtual void  AusschnittDefiniert(int x, int y,
                                      int w, int h){;}
//====================================================================
//   Zeichenfläche und Clipregion
//====================================================================

    void  View(void);
    void  View(int x, int y, int w, int h);
    void  View(real x, real y, real w, real h);
    void  View(TRect &r);
    int   GetMaxW(void);
    int   GetMaxH(void);
    int   GetX(void);
    int   GetY(void);
    int   GetW(void);
    int   GetH(void);
    
    TRect GetViewRect(void);

//====================================================================
//   Skalierung
//====================================================================


    void  Scale(real xleft, real xright, real ybottom,
                 real ytop);
    void  Scale(real xleft, real xright, real ybottom);
    int   XToInt(real x);
    int   YToInt(real y);
    int   DXToInt(real dx);
    int   DYToInt(real dy);
    real  IntToX(int x);
    real  IntToY(int y);
    real  IntToDX(int dx);
    real  IntToDY(int dy);

//====================================================================
//   Zeichenmedien
//====================================================================

    void  SetPen(TColor f, int breite = 1); // fuer alte Versionen
    void  SetBrush(TColor f);               // fuer alte Versionen
    void  SetText(TColor f, int size = -1);
	bool  SavePenBrush(void);
    void  RestorePenBrush(void);

    void  SetPenColor(TColor f);
    void  SetBrushColor(TColor farbe);
    void  SetTextColor(TColor f);
    TColor  GetPenColor(void);
    TColor  GetBrushColor(void);
    TColor  GetTextColor(void);
    void  SetPenSize(int d);
    void  SetTextSize(int size=0);
    int   GetPenSize(void);
    int   GetTextSize(void);
    int   GetDefTextSize(void);
    bool  SaveMedia(void);
    void  RestoreMedia(void);

    __property TColor PenColor    = {read=GetPenColor,
                                     write=SetPenColor};
    __property TColor BrushColor  = {read=GetBrushColor,
                                     write=SetBrushColor};
    __property TColor TextColor   = {read=GetTextColor,
                                     write=SetTextColor};
    __property int PenSize        = {read=GetPenSize,
                                     write=SetPenSize};
    __property int TextSize       = {read=GetTextSize,
                                     write=SetTextSize};

//====================================================================
//   elementare Grafikbefehle
//====================================================================

    void  Clear(TColor farbe = Weiss);
    void  SetPixel(int x, int y, TColor f);
    void  SetPixel(real x, real y, TColor f);
    TColor  GetPixel(int x, int y);
    TColor  GetPixel(real x, real y);
    void  MoveTo(int x, int y);
    void  MoveTo(real x, real y);
    void  LineTo(int x, int y);
    void  LineTo(real x, real y);
    
    void  Rectangle(int x, int y, int w, int h);
    void  Rectangle(real x, real y, real w, real h);
    void  Rectangle(TRect &r);
    void  Circle(int x, int y, int r);
    void  Circle(real x, real y, real r);
    void  Circle(int x, int y, int r1, int r2);
    void  Circle(real x, real y, real r1, real r2);

    void  Arc(int x, int y, real anfgrad, real endgrad,
                        int r);
    void  Arc(real x, real y, real anfgrad,real endgrad,
                        real r);
    void  Arc(int x, int y, int vx, int vy,
                        int nx, int ny, int r);
    void  Arc(real x, real y, real vx, real vy,
                        real nx, real ny, real r);
    void  Arc(int x, int y, real anfgrad, real endgrad,
                        int r1, int r2);
    void  Arc(real x, real y, real anfgrad, real endgrad,
                        real r1, real r2);

    void  ClearPoints(void);
    bool  SetPoint(int x, int y);
    bool  SetPoint(real x, real y);
    void  Poly(int von=0, int bis=0);
    void  Poly(TPoint *Punkte,int anz = 0);
    void  PolyBezier(int von=0, int bis=0);
    void  PolyBezier(TPoint *Punkte,int anz = 0);
    int   TextH(PlanString s);
    int   TextW(PlanString s);
    void  Text(int x, int y, PlanString s);
    void  Text(real x, real y, PlanString s);
    void  Text(int x, int y, PlanString s, real grad);
    void  Text(real x, real y, PlanString s, real grad);
    void  TextRect(int x, int y, int w, int h, PlanString s,
                             int center=0);
    void  TextRect(TRect &r, PlanString s,int center=0);
    void  TextRect(PlanString s,int center=0);

//====================================================================
//   fertige Grafikobjekte
//====================================================================

    void  LCD(int x, int y, TColor f,
                          int typ = 2);
    void  LCD(real x, real y, TColor f,
                          int typ = 2);
    void  Frame(int x, int y, int w, int h,
                          int thick=2,bool up=true);
    void  Frame(real x,real y,real w, real h,
                          int thick=2,bool up=true);
    void  Frame(TRect r,int thick=2,bool up=true);

//====================================================================
//   Numerische Integration
//====================================================================

    virtual void  DGL(void){;}

    real    &X1O(int i);
    real    &X1OP(int i);
    real    &X2O(int i);
    real    &X2OP(int i);
    real    &X2OPP(int i);

    void  Intervall(real von, real bis);
    void  InitIntegration(void);
    int   Integrationsschritt(int anz = 1);
    int   Integrationsschritt(real dt);

    __property int  Verfahren     = {read = DGLVerfahren,
                                     write = SetVerfahren};
    __property real Anfangszeit   = {read = DGLAnfangsZeit,
                                     write = SetAnfangszeit};
    __property real Endzeit       = {read = DGLEndZeit,
                                     write = SetEndzeit};
    __property real Anfangsschritt= {read = DGLAnfangsSchritt,
                                     write = SetAnfangsschritt};
    __property real Schrittweite  = {read = DGLSchritt,
                                     write = SetSchrittweite};
    __property real Toleranz      = {read = GetToleranz,
                                     write = SetToleranz};
    __property int  Schrittanzahl = {read = DGLAktSchritt};
    __property int  MaxSchritte   = {read = DGLMaxSchritt,
                                     write = SetMaxSchritt};
    __property int  GesamtOrdnung = {read = DGLOrdnung,
                                     write = SetDGLOrdnung};
    __property int  Gln1Ordnung   = {read = DGL1Ordnung,
                                     write = SetDGL1Ordnung};
    __property real Zeit          = {read = DGLZeit};
    __property bool Fertig        = {read = DGLFertig};
    __property bool Fehler        = {read = DGLFehler};

//====================================================================
//   Plots
//====================================================================

    __property PPlot Plot0        = {read=GetPlot0};
    __property PPlot Plot1        = {read=GetPlot1};
    __property PPlot Plot2        = {read=GetPlot2};
    __property PPlot Plot3        = {read=GetPlot3};
    __property PPlot Plot4        = {read=GetPlot4};
    __property PPlot Plot5        = {read=GetPlot5};
    __property PPlot Plot6        = {read=GetPlot6};
    __property PPlot Plot7        = {read=GetPlot7};
    __property PPlot Plot8        = {read=GetPlot8};
    __property PPlot Plot9        = {read=GetPlot9};

//====================================================================
//   Konstruktor
//====================================================================

protected:
    TPlan (void);
    ~TPlan(void);

//====================================================================
//   Ausführen von PLAN
//====================================================================
public:
    void  Execute(void);
};

//___Ostermeyer/2007__________________________________________________
#endif

