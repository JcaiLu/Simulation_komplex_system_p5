//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Plan.h"

#include "SeaFeld.h"
#include "ObjectGroup.h"
#include <vector>
//---------------------------------------------------------------------------

#pragma package(smart_init)

void SeaFeld::FeldInit(int &getW,int &getH){
    this->pixelW = 20;
    this->startScreenToLeft = (int)(getW*0.05);
	this->startScreenToRight = (int)(getW*0.5);
    this->startScreenToTop =(int)(getH*0.1);
	this->startScreenToBottom =(int)(getH*0.05);
	this->playScreenW = (int)((getW - this->startScreenToLeft - this->startScreenToRight)/this->pixelW);
	this->playScreenH = (int)((getH - this->startScreenToTop - this->startScreenToBottom)/this->pixelW);
	this->w = playScreenW;
	this->h = playScreenH;


}

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

void SeaFeld::CreatObject(int m, int n,int code){  //
	 int num = this->XYIntoNum(m,n);
	 this->matrix[num].CopyOf(code);
}



Object SeaFeld::GetObject(int i, int j){
    int n = 0;
	n = j*this->w +i;
	return this->matrix[n];
}

void SeaFeld::InitObject(){
	Object initObject(0);
	for(int j = 0; j < this->h; j++){          //initiazation the position of each element
		for(int i = 0; i < this->w; i++){
			//int k = this->XYIntoNum(i,j);
			initObject.xInPixel = this->startScreenToLeft+i*this->pixelW;
			initObject.yInPixel = this->startScreenToTop+j*this->pixelW;
			initObject.x = i;
			initObject.y = j;
			this->matrix.push_back(initObject);
		}
	}

}

void SeaFeld::DestoryObject(int m,int n){
	 int num = this->XYIntoNum(m,n);
	 this->matrix[num].CopyOf(0);

}

void SeaFeld::DestoryObject(int num){
	 this->matrix[num].CopyOf(0);

}

void SeaFeld::MoveObject(Object object,const char &c){
	int oldNum = 0;
	oldNum = this->XYIntoNum(object.x,object.y);
	int newX = 0;
	int newY = 0;
	int newNum = 0;
	switch(c){
		case 'w': if(object.y == 0){
					  newX = object.x;
					  newY = this->h;

				  }else{
					  newX = object.x;
					  newY = object.y-1;
				  }
				 break;
		case 's':if(object.y == this->h){
					  newX = object.x;
					  newY = 0;

				  }else{
					  newX = object.x;
					  newY = object.y+1;
				  }
				 break;
		  case 'a':if(object.x == 0){
					  newX = this->w;
					  newY = object.y;

				  }else{
					  newX = object.x-1;
					  newY = object.y;
				  }
				 break;
		  case 'd':if(object.x == this->w){
					  newX = 0;
					  newY = object.y;

				  }else{
					  newX = object.x+1;
					  newY = object.y;
				  }
				 break;

	}
	 newNum = this->XYIntoNum(newX,newY);
	 this->matrix[newNum].code = this->matrix[oldNum].code;
	 this->DestoryObject(oldNum);
	 this->matrix[newNum].CodeShapeUpdate();
     this->matrix[oldNum].CodeShapeUpdate();

}

void SeaFeld::KeepMoveObject(Object object,const char &c){







}
