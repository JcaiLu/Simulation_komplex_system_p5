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
	this->GetValueRange();
	this->xInPixel = 0;
	this->yInPixel = 0;
	this->fishScale = 0;
	memset(this->shape,0,sizeof(this->shape)) ;

}

Object::Object(int c){
	this->code = c;
	this->GetValueRange();
	this->xInPixel = 0;
	this->yInPixel = 0;
	this->X = 0;
	this->Y = 0;
	this->fishScale = 0;
	memset(this->shape,0,sizeof(this->shape)) ;
}
////////////////////////////////////////////////////////////////
void Object::GetValueRange(){               	///ÐÞ¸ÄÌ½²â·¶Î§
	switch(this->code){
		case 0:this->detectRange = 0;
			   this->warnRange = 0;
			   break;
		case 1:this->detectRange = 1;
			   this->warnRange = 2;
			   break;
		case 2:this->detectRange = 6;
			   this->warnRange = 6;
			   break;
		case 3:this->detectRange = 14;
			   this->warnRange = 12;
			   break;
	}

}
//////////////////
//detectFeld[4] = {A,B,C,D}
//(A,C)..........
//...............
//..............
//...........(B,D)

void Object::GetDetectFeld(){           //detecting Range
	 this->GetValueRange();
	 int Range = this->detectRange;
	 this->detectFeld[0] = this->X - Range;
	 this->detectFeld[1] = this->X + Range;
	 this->detectFeld[2] = this->Y - Range;
	 this->detectFeld[3] = this->Y + Range;
	 this->BoundaryTreatment(this->detectFeld);
}

void Object::GetWarnFeld(){            //Warning Range
	 this->GetValueRange();
	 int Range = this->warnRange;
	 this->warnFeld[0] = this->X - Range;
	 this->warnFeld[1] = this->X + Range;
	 this->warnFeld[2] = this->Y - Range;
	 this->warnFeld[3] = this->Y + Range;
	 this->BoundaryTreatment(this->warnFeld);
}


void Object::GetHuntFeld(){            //Hunting Range
	 int huntRange;
	 if(this->code == 3){
		 huntRange =2;
	 }else if(this->code == 2){
		 huntRange =1;
	 }
	 this->huntFeld[0] = this->X - huntRange;
	 this->huntFeld[1] = this->X + huntRange;
	 this->huntFeld[2] = this->Y - huntRange;
	 this->huntFeld[3] = this->Y + huntRange;
	 this->BoundaryTreatment(this->huntFeld);

}

void Object::GetPossibleFeld(){        //Possible Range
	 int possibleRange;
	 if(this->code == 2){
		 this->huntRange = 2;
	 }else if(this->code == 1){
		 this->huntRange =1;
	 }
	 this->possibleFeld[0] = this->X - possibleRange;
	 this->possibleFeld[1] = this->X + possibleRange;
	 this->possibleFeld[2] = this->Y - possibleRange;
	 this->possibleFeld[3] = this->Y + possibleRange;
	 this->BoundaryTreatment(this->possibleFeld);
}


void Object::BoundaryTreatment(int arr[]){      // this is used to avoid the object run out of SeaFeld
	SeaFeld *a;

	if(arr[0]<0){
		arr[0] = a->w+arr[0];
	}

	if(arr[1]>a->w){
		arr[1] = arr[1] - a->w;
	}

	if(arr[2]<0){
		arr[2] = 0;
	}

	if(arr[3]>0){
		arr[3] = a->h;
	}

	delete a;


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

