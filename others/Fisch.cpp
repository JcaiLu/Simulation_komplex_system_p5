#include<windows.h>
//====================================================================
//探测范围函数
//输入物种属性i，坐标X,Y，得到范围
//问题，变量名是否正确
//====================================================================
public:
	int DetectFeld[4];
	void detectFeld(int i, int X, int Y) {

		int HaiFeld = 400;
		int SalmonFeld = 80;
		int KleinfischFeld = 9;//待修改

		switch (i) {

		case'1':
			DetectFeld[0] = X - HaiFeld;
			DetectFeld[1] = X + HaiFeld;
			DetectFeld[2] = Y - HaiFeld;
			DetectFeld[3] = Y + HaiFeld;
			break;
		case'2':
			DetectFeld[0] = X - SalmonFeld;
			DetectFeld[1] = X + SalmonFeld;
			DetectFeld[2] = Y - SalmonFeld;
			DetectFeld[3] = Y + SalmonFeld;
			break;
		case'3':
			DetectFeld[0] = X - KleinfischFeld;
			DetectFeld[1] = X + KleinfischFeld;
			DetectFeld[2] = Y - KleinfischFeld;
			DetectFeld[3] = Y + KleinfischFeld;
			break;
		default:
			MessageBox(GetForegroundWindow(), "DetectFeld is wrong.", "Error Infomation", 2);
			break;
		};

	}；


		//====================================================================
		//判定最大鱼群函数
		//输入坐标范围数组DetectFeld，物种属性i，返回范围内最大鱼群坐标XMax,YMax,没有则最大鱼群坐标Ueber(不在坐标范围内的两个常数）；
		//i=0(hai),1(salmon),2(kleinfisch)
		// 问题，变量名是否正确，尤其xxx需要修改
		//====================================================================
public:
	int XMax, YMax, Ueber;

	void judegObject(int i, int DetectFeld[]) {
		int j = 0;
		int k = 0;
		int a, amax = 0;//用于比大小的临时变量；
		XMax = YMax = Ueber;
		if (i = 0) {
			for (j = DetectFeld[0]; j <= DetectFeld[1]; j++) {
				for (k = DetectFeld[2]; k <= DetectFeld[3]; k++) {
					a = xxx(i, j);//xxx(i,j)为I,J坐标内三文鱼群数量			
					if (amax < a) {
						amax = a;
						XMax = j;
						YMax = k;
					};
				};
			};
		};
		if (i = 1) {
			for (j = DetectFeld[0]; j <= DetectFeld[1]; j++) {
				for (k = DetectFeld[2]; k <= DetectFeld[3]; k++) {
					a = xxx(i, j);//xxx(i,j)为I,J坐标内小鱼群数量			
					if (amax < a) {
						amax = a;
						XMax = j;
						YMax = k;
					};
				};
			};
		}；
	};
	//====================================================================
	//鲨鱼追捕函数，没有问题则拓展至三文鱼函数
	// 输入坐标数组X,Y，最大鱼群坐标XMax,YMax,判定追捕或移动
	//i=0(hai),1(salmon),2(kleinfisch)
	// 问题，变量名是否正确，涉及到更新周期，暂且认为更新一周期时间变量名为Tupdate
	//变量名 v.Hai,v.Salmon,v.Kleinfisch为各种鱼的游速，Hai,40km/h, Salmon 15m/s,小鱼鱼群速度未定
	//暂时简化为一次更新内可x,y轴各走，之后换为速度稳定带方向移动
	//====================================================================
	void jagd(X, Y, XMax, Ymax) {
		if (XMax == Ueber) {
			//随机移动函数；
		};
		else if(X=Xmax&&Y=Ymax){
			//捕食函数;
			
		};
		else {//下次修改此处移动模式
			if (X - XMax > 0)
				X = X + Tupdate * v.Hai*(-1);
			else
				X= X + Tupdate * v.Hai;
			if (Y - YMax > 0)
				Y = Y + Tupdate * v.Hai*(-1);
			else
				Y = Y+ Tupdate * v.Hai;
		}；

	}；
}；

//====================================================================
//捕食函数，占用一次更新时间，调用更新前鱼群数据，输出鱼群数据
// 输入坐标数组X,Y
//i=0(hai),1(salmon),2(kleinfisch)
// 问题，变量名是否正确
//====================================================================


//====================================================================
//随机移动函数
//需要商议
//====================================================================


//====================================================================
//小鱼鱼群数据特性需商讨
//====================================================================