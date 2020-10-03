#include<graphics.h>
#include<time.h>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
using namespace std;
int endfunc(int e);
int main(){
    cout<<"\n\t Welcome to the 'CATCH  YOUR  ENEMY' Game\n";
    delay(3000);
    cout<<"\n\tUse arrow keys to move yourself and reach your enemy who has cloned you\n ";
    delay(4000);
    cout<<"\n\tBut as soon as you catch him he disappears and spawns at a different location , so go after him\n";
    delay(5000);
    cout<<"\n   Alert : Your Enemy has planted bombs outside the yellow boundary so, stay inside the boundary and catch your enemy.\n";
    delay(6000);
    cout<<"\n\tSO, LET'S BEGIN!!";
    delay(1000);
    int gd,gm,rx=200,ry=200,x,y,d/*dirction*/,f=1/*Food eaten*/,dir=1/*direction*/;
   // srand(time(NULL));
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");
    setfillstyle(8,1);//(style,color)
    x=200,y=200;

d=1;

delay(5000);
for(;;){

    setfillstyle(8,4);
    bar(0,0,640,480);
    setfillstyle(1,14);
    bar(0,0,640,10);
    bar(0,0,10,480);
    bar(0,480,640,470);
    bar(630,10,640,480);
   // food taken?
   if(x==rx && y==ry ){

        f=f+1;
    setfillstyle(8,4);
    bar(rx,ry,rx+10,ry+10);

    //make food
   do {
	rx = (1+rand()%630);
	ry = (1+rand()%470);
    }while(getpixel(rx,ry)!=0 && rx > 10 && ry > 10);
    rx=rx/10;
    rx=rx*10;
    ry=ry/10;
    ry=ry*10;
    setfillstyle(8,14);

    }
    bar(rx,ry,rx+10,ry+10);

    if(GetAsyncKeyState(VK_RIGHT)){d=1;}
    else if(GetAsyncKeyState(VK_LEFT)){ d=2;}
    else if(GetAsyncKeyState(VK_UP)){ d=3;}
   else if(GetAsyncKeyState(VK_DOWN)) {d=4;}
   else{d=0;}
    int n;


//Add endfunction() here.
