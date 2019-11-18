
//一、关于打印类的一种优化
#inlcude <iostream>
using namespace std;


class Trace{
	
public:
   Trace(){ flage = 1 ;}
   void print( char *s){ if(flage) { printf("%s\n",s);} }
   void on(){ flage = 1;}
   void off(){ flage = 0;}
   
private:
   int flage;	
}


int main()
{
	return 0;
}

//二、继续优化，可以输出的文件做一些定制
//1.不仅仅是输出到stdout
//即思路为： print(arg)   ---->  fprintf(stdout,args); 做一个具体的转换
#include <iostream>
using namespace std;


class Trace{
public:
    Trace(){ flage = 0; f = stdout;  }
	Trace(FILE *fp){ flage =0 ; f = fp;}
	void print(char *s)
	{  if( falge ) fprintf(f,"%s",s ); }
	void on(){ flage =1 ;}
    void off(){ flage =0 ;}
private:
    int flage;
	FILE *f;
}

int main()
{
	//也可以自定定义往其他标准文件传
	Trace t(stderr);
	t.print("behin main()\n");
	
	return 0;
}

//三、不采用对象的方式，使用c的方式进行实现
#inlcude <stdio.h>

static int flage = 1; 

void on(){ flage =1;}
void off() { flage =0;}
void print(char *s)
{
	if(flage)
		
      printf("%s",s);	
}

int main()
{	 
	return 0;
}

//四 、第一章内容
//1.数据抽象 ---》 即可定义数据的属性（但是C也能做到）  --》但这些数据定义为黑匣子（C就无从涉猎了）
//2.面向对象





