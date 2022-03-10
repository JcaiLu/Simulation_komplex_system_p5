//--------------------------------------------------------------------------


#include <vcl.h>
#include "Plan.h"
#include "SeaFeld.h"
#include "ObjectGroup.h"

//---------------------------------------------------------------------------




int Object::GetX(){
   return X;
}

int Object::GetY(){
   return Y;
}
void Object::ReadX(int value){
   this->X = value;
}

void Object::ReadY(int value){
   this->Y = value;
}



bool Object::IfFull(){
        if(this->degreeFull>0.8){
            return true;
        }else{
            return false;
        }
}


bool Object::IfLive(){
		if(this->degreeLife>0.8){
            return true;
        }else{
			return false;
        }
}

void Object::Objectencode(int t){
    switch(t){
		case 0 : break;
    }
}

void Object::CopyOf(int t){
	this->code = t;
	switch (this->code){
		case 0 :{
				for(int j =0;j<10;j++){
					  for(int i = 0;i <10;i++){
						  this->shape[i][j] = this->shapeSea[i][j];
					  }
				   }
				 }
				 break;
		case 1 :{
				 for(int j =0;j<10;j++){
					  for(int i = 0;i <10;i++){
						  this->shape[i][j] = this->shapeFish[i][j];
					  }
				  }
				 }
				 break;
		case 2 :{
				  for(int j =0;j<10;j++){
					  for(int i = 0;i <10;i++){
						  this->shape[i][j] = this->shapeBigFish[i][j];
					  }
					}
				 }
				 break;
		case 3 :{
				  for(int j =0;j<10;j++){
					  for(int i = 0;i <10;i++){
						  this->shape[i][j] = this->shapeHai[i][j];
					  }
				  }
				 }
				 break;
	}
}


void Object::CodeShapeUpdate(){
	switch (this->code){
		case 0 :{
				for(int j =0;j<10;j++){
					  for(int i = 0;i <10;i++){
						  this->shape[i][j] = this->shapeSea[i][j];
					  }
				   }
				 }
				 break;
		case 1 :{
				 for(int j =0;j<10;j++){
					  for(int i = 0;i <10;i++){
						  this->shape[i][j] = this->shapeFish[i][j];
					  }
				  }
				 }
				 break;
		case 2 :{
				  for(int j =0;j<10;j++){
					  for(int i = 0;i <10;i++){
						  this->shape[i][j] = this->shapeBigFish[i][j];
					  }
					}
				 }
				 break;
		case 3 :{
				  for(int j =0;j<10;j++){
					  for(int i = 0;i <10;i++){
						  this->shape[i][j] = this->shapeHai[i][j];
					  }
				  }
				 }
				 break;
	}
}

Object::Object(int px,int py,int c){
	this->X = px;
	this->Y = py;
	this->code = c;
	this->GetDetectRange();
	this->xInPixel = 0;
	this->yInPixel = 0;
	this->fishScale = 0;
	memset(this->shape,0,sizeof(this->shape)) ;

}

Object::Object(int c){
	this->code = c;
	this->GetDetectRange();
	this->xInPixel = 0;
	this->yInPixel = 0;
	this->X = 0;
	this->Y = 0;
	this->fishScale = 0;
	memset(this->shape,0,sizeof(this->shape)) ;
}
////////////////////////////////////////////////////////////////
void Object::GetDetectRange(){               	///ÐÞ¸ÄÌ½²â·¶Î§
	switch(this->code){
		case 0:this->detectRange = 0;
			   break;
		case 1:this->detectRange = 1;
			   break;
		case 2:this->detectRange = 2;
			   break;
		case 3:this->detectRange = 3;
			   break;
	}

}
//////////////////
//detectFeld[4] = {A,B,C,D}
//(A,C)..........
//...............
//..............
//...........(B,D)

void Object::GetDetectFeld(){
	 this->GetDetectRange();
	 int Range = this->detectRange;
	 this->detectFeld[0] = this->X - Range;
	 this->detectFeld[1] = this->X + Range;
	 this->detectFeld[2] = this->Y - Range;
	 this->detectFeld[3] = this->Y + Range;
}

































const int Object::shapeSea[10][10]={
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
};

const int Object::shapeHai[10][10]={
{1,0,0,0,1,1,0,0,0,0},
{1,0,0,1,1,1,1,0,0,0},
{1,0,1,1,1,1,1,1,0,0},
{1,1,1,1,1,1,1,1,1,0},
{1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,0},
{1,1,1,1,1,1,1,1,0,0},
{1,0,0,1,1,1,1,0,0,0},
{1,0,0,0,1,1,0,0,0,0},
};

const int Object::shapeBigFish[10][10]={
{0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,1,1,0,0,0,0},
{0,0,0,0,1,1,1,0,0,0},
{1,1,1,1,1,1,1,1,0,0},
{1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,0,0},
{0,0,0,0,1,1,1,0,0,0},
{0,0,0,0,1,1,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0},
};

const int Object::shapeFish[10][10]={
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0},
{1,0,1,1,1,1,0,0,0,0},
{1,1,0,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,0,0,0},
{1,0,0,1,1,1,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
};

