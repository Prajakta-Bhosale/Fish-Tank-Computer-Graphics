#include<iostream>
#include<graphics.h>

using namespace std;
int y=310;

void koch(int x1,int y1,int x2,int y2,int it)
{
	float angle=(60*3.14)/180;
	
	int x3=(2*x1+x2)/3;
	int y3=(2*y1+y2)/3;
	
	int x4=(x1+2*x2)/3;
	int y4=(y1+2*y2)/3;
	
	int x=x3+(x4-x3)*cos(angle)+(y4-y3)*sin(angle);
	int y=y3-(y4-y3)*sin(angle)+(x4-x3)*cos(angle);
	
	if(it>0)
	{
		koch(x1,y1,x3,y3,it-1);
		koch(x3,y3,x,y,it-1);
		koch(x,y,x4,y4,it-1);
		koch(x4,y4,x2,y2,it-1);
	}
	else
	{
		setcolor(2);
		line(x1,y1,x3,y3);
		line(x3,y3,x,y);
		line(x,y,x4,y4);
		line(x4,y4,x2,y2);
	}
}
int main()
{	
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	int flag1=0,k=0,temp=0;
	//fishes
	for(int i=0;i<320;i++)
	{	
		outtextxy(200,50,"Welcome to our Aquarium");
	
		//fish 1
		setcolor(14);
		line(150+i,250,190+i,290);
		line(150+i,250,90+i,310);
		line(90+i,270,150+i,330);
		line(190+i,290,150+i,330);
		line(90+i,310,90+i,270);
		circle(170+i,290,3);
		floodfill(140+i,270,14);
		floodfill(100+i,290,14);
		
		//fish 2
		if(i<320)
		{
		setcolor(12);
		arc(400-i,170,50,320,30);
		line(420-i,148,450-i,180);
		line(420-i,193,450-i,150);
		line(450-i,180,450-i,150);
		floodfill(445-i,160,12);
		floodfill(410-i,170,12);
		setcolor(0);
		arc(380-i,170,270,90,20);
		setcolor(0);
		circle(380-i,170,3);
		floodfill(380-i,170,0);
		//floodfill(100+i,290,14);
		}
		else
		{
		    //do changes here...
		}
		//oxygen tank
		setcolor(7);
		line(50,300,80,300);
		line(80,300,80,370);
		line(50,370,80,370);
		line(80,305,90,305);
		line(80,310,90,310);
		line(90,305,90,310);
		line(50,300,50,370);
		circle(65,335,6);
		floodfill(60,305,1);
		//bubbles
		
		setcolor(3);
		
		if(y<220&&flag1==0)
		{
			y=y+180;
			flag1=1;
		}
		if(y<310&&flag1==1)
		{
			y=y+180;
			flag1=2;
		}
		if(y<400&&flag1==2)
		{
			y=y+180;
		}
		circle(100,y-i,5);
		floodfill(100,y-i,3);
		y--;
		


		//---------------------Fish tank body-----------------------------------------
		
		//roof
		setcolor(6);
		line(50,10,550,10);
		line(50,10,10,100);
		line(550,10,590,100);
		line(10,100,590,100);
		
		//setfillstyle(SOLID_FILL,BROWN); 
		floodfill(300,20,BROWN);

		//tank
		int flag=0;
		setcolor(3);
		line(50,130,550,130);
		setlinestyle(3, 0, 1);
		if(temp<4)
		{ 
			for(int j=0;j<270;j+=7)
			{
				if(flag==0)
				{
					line(50+temp,130+j,550,130+j);
					flag=1;
				}	
				else
				{	
					line(55+temp,130+j,550,130+j);
					flag=0;
				}

			}
			temp++;
		}	
		else
		{	
			for(int j=0;j<270;j+=7)
			{
				if(flag==1)
				{	
					line(50,130+j,550,130+j);
					flag=0;
				}	
				else
				{	
					line(55,130+j,550,130+j);
					flag=1;
				}
			}
			temp=0;
		}
		setlinestyle(0, 0, 1);
 		setcolor(7);
		//line(50,100,550,100);
		line(50,100,50,400);
		line(50,400,550,400);
		line(550,100,550,400);
		//koch(550,400,50,400,5);
		//floodfill(300,400,3);
		delay(60);
	   /*setcolor(0);
		//fish 1
		line(150+i,250,190+i,290);
		line(150+i,250,90+i,310);
		line(90+i,270,150+i,330);
		line(190+i,290,150+i,330);
		line(90+i,310,90+i,270);
		circle(170+i,290,3);
		floodfill(140+i,270,14);
		floodfill(100+i,290,14);
		
		//fish 2
		if(i<320)
		{
		setcolor(0);
		arc(400-i,170,50,320,30);
		line(420-i,148,450-i,180);
		line(420-i,193,450-i,150);
		line(450-i,180,450-i,150);
		floodfill(445-i,160,0);
		floodfill(410-i,170,0);
		setcolor(0);
		arc(380-i,170,270,90,20);
	
		circle(380-i,170,3);
		floodfill(380-i,170,0);
		//floodfill(100+i,290,14);
		}
		else
		{
		    //do changes here...
		}
		if(y<220&&flag1==0)
		{
			y=y+180;
			flag1=1;
		}
		if(y<310&&flag1==1)
		{
			y=y+180;
			flag1=2;
		}
		if(y<400&&flag1==2)
		{
			y=y+180;
		}
		circle(100,y-i,5);
		floodfill(100,y-i,3);*/
		cleardevice();
	}
	//boundaryFill4(300,60, 6, 15);
	delay(2000);


	return 0;
}
