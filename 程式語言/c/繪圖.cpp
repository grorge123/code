#include <graphics.h>
#include <conio.h>
void main()
{
 int gd=9, gm=2;
 initgraph(&gd,&gm,"c:\\tc");
 setcolor(11);
 line(0,240,639,240);
 line(320,0,320,479);
 setcolor(14);
 circle(320,240,200);
 getch();
 closegraph();
}
