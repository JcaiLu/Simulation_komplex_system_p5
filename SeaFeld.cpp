//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Plan.h"

#include "SeaFeld.h"
#include "ObjectGroup.h"
#include <vector>
//---------------------------------------------------------------------------

#pragma package(smart_init)

//---------------------------------------------------------------------------
//The Function FeldInit() is used to initialize a Object with Class SeaFeld.
//The following variable values are given.
//    1) pixelW;    the heigh and the width of each element in SeaFeld.
//    2) startScreenToLeft, startScreenToRight, startScreenToTop,startScreenToBottom
//(This is ez to understand :) )
//    3) playScreenW,playScreenH;    This describes how many rows and columns
//there are in the matrix.
//Input Type: (int)GetMaxW(),(int)GetMaxH()
//---------------------------------------------------------------------------

void SeaFeld::FeldInit(int &getW,int &getH){
	this->pixelW = 10;
	this->startScreenToLeft = (int)(getW*0.05);
	this->startScreenToRight = (int)(getW*0.5);
	this->startScreenToTop =(int)(getH*0.1);
	this->startScreenToBottom =(int)(getH*0.05);
	this->playScreenW = (int)((getW - this->startScreenToLeft - this->startScreenToRight)/this->pixelW);
	this->playScreenH = (int)((getH - this->startScreenToTop - this->startScreenToBottom)/this->pixelW);
	this->w = playScreenW;
	this->h = playScreenH;

}

//---------------------------------------------------------------------------
//The Function InitObject() is used to initialize the object in the matrix
//
//Beside all the object is initialized to the "Sea",the following variable
//values are also given.
//    1) x,y;  the coordiate of this object
//---------------------------------------------------------------------------

void SeaFeld::InitObject(){
	Object initObject(0);
	for(int j = 0; j < this->h; j++){          //initiazation the position of each element
		for(int i = 0; i < this->w; i++){
			//int k = this->XYIntoNum(i,j);
			initObject.xInPixel = this->startScreenToLeft+i*this->pixelW;
			initObject.yInPixel = this->startScreenToTop+j*this->pixelW;
			initObject.X = i;
			initObject.Y = j;
			this->matrix.push_back(initObject);
		}
	}

}

//---------------------------------------------------------------------------
//The Function Update() is the main and the most important program. It descirbes
//the flow chart of our Rules.
//
//---------------------------------------------------------------------------
void SeaFeld::Update(){

	for(int i = 0;i < this->matrix.size();i++){
		if (this->matrix[i].code == 3) {
			if(this->TargetLocation(this->matrix[i])){



			}
		}

	}


}

//---------------------------------------------------------------------------
//The following three Function are used to translate the X,Y to the Nummer of
//the Vector.
// Why?   Because this Vector is 1D, but the Matrix is 2D.
//Function GetObject() can be used to get a object at x,y.
//---------------------------------------------------------------------------

int SeaFeld::XYIntoNum(int &x,int &y){             // transfer x,y into num of Vector

    int num;
    num = this->w*y + x;
    return num;

}

int SeaFeld::NumIntoX(int &num){             // transfer x,y into num of Vector
    int x;
    x = num - this->w*((int)(num/this->w));
    return x;
}

int SeaFeld::NumIntoY(int &num){             // transfer x,y into num of Vector
    int y;
    y = num / this->w;
    return y;

}

Object SeaFeld::GetObject(int i, int j){
	int n = 0;
	n = j*this->w +i;
	return this->matrix[n];
}
//---------------------------------------------------------------------------
//The following Function are used to creat or destory a object according to
// the code in the SeaFeld.
//---------------------------------------------------------------------------
void SeaFeld::CreatObject(int m, int n,int code){  //
	 int num = this->XYIntoNum(m,n);
	 this->matrix[num].CopyOf(code);
}

void SeaFeld::DestoryObject(int m,int n){
	 int num = this->XYIntoNum(m,n);
	 this->matrix[num].CopyOf(0);

}

void SeaFeld::DestoryObject(int num){
	 this->matrix[num].CopyOf(0);

}

//---------------------------------------------------------------------------
//The following Function are used to realize a Movement of a object according
//to the given direction.
//---------------------------------------------------------------------------
void SeaFeld::Move(const Object &object){      //Movement

	 int xmin,xmax,ymin,ymax;
	 if(object.target[1]>=0){

		xmin= object.detectFeld[0];
		xmax= object.detectFeld[1];
		ymin= object.detectFeld[2];
		ymax= object.detectFeld[3];

		for(int j = ymin; j<=ymax;j++ ){
			for(int i = xmin;i<=xmax;i++){
				this->DestoryObject(i,j);
			}
		}
	 }


	 for (int i = 0; i < object.speed; i++) {
		 switch(object.direction)
		 {
			  case '0' : DestoryObject(object.X,object.Y+i);
						 break;

			  case '1' : DestoryObject(object.X,object.Y-i);
						 break;

			  case '2' : DestoryObject(object.X-i,object.Y);
						 break;

			  case '3' : DestoryObject(object.X+i,object.Y);
						 break;
		 }
	 }

	 ////////////////////对象复制  (这个OBJECT的信息复制到新的target的坐标上
}

void SeaFeld::MoveObject(Object object,const char &c){
	int oldNum = 0;
	oldNum = this->XYIntoNum(object.X,object.Y);
	int newX = 0;
	int newY = 0;
	int newNum = 0;
	switch(c){
		case 'w': if(object.Y == 0){
					  newX = object.X;
					  newY = this->h;

				  }else{
					  newX = object.X;
					  newY = object.Y-1;
				  }
				 break;
		case 's':if(object.Y == this->h){
					  newX = object.X;
					  newY = 0;

				  }else{
					  newX = object.X;
					  newY = object.Y+1;
				  }
				 break;
		  case 'a':if(object.X == 0){
					  newX = this->w;
					  newY = object.Y;

				  }else{
					  newX = object.X-1;
					  newY = object.Y;
				  }
				 break;
		  case 'd':if(object.X == this->w){
					  newX = 0;
					  newY = object.Y;

				  }else{
					  newX = object.X+1;
					  newY = object.Y;
				  }
				 break;

	}
	 newNum = this->XYIntoNum(newX,newY);
	 this->matrix[newNum].code = this->matrix[oldNum].code;
	 ////////////////////对象复制
	 this->DestoryObject(oldNum);
	 ///////////////////////////下面的两行不要了
	 this->matrix[newNum].CodeShapeUpdate();
	 this->matrix[oldNum].CodeShapeUpdate();

}




bool SeaFeld::TargetLocation(const Object &object){

	 int tx,ty,bx,by,num;
	 tx = object.detectFeld[0];
	 bx = object.detectFeld[1];
	 ty = object.detectFeld[2];
	 by = object.detectFeld[3];
	 int max = 0;
	 for(int j = ty; j<by+1;j++ ){
		 for(int i = tx;i<bx+1;i++){
			 num = this->XYIntoNum(i,j);
			 if(this->matrix[num].fishScale>max){
				 max =this->matrix[num].fishScale;
			 }
		 }
	 }

	 if(max == 0){
		 return false;
	 }else{
		 return true;
	 }
}
//////////// 需要补充


////////////需要补充
void SeaFeld::Catch(){

}
////////////需要补充
void SeaFeld::RunAway(){

}

void SeaFeld::KeepMoveObject(Object object,const char &c){

}

