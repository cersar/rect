#include<iostream>

using namespace std;


double max(double x,double y)
{
	return x>y?x:y;
}

double min(double x,double y)
{
	return x<y?x:y;
}

typedef struct point
{
	double x;
	double y;
};

class rect
{
public:
	point ul;
	point dr;
	rect(){};
	rect(double x1,double y1,double x2,double y2);
	int valid();
	double overlap(rect a);
	double area();	
};

rect::rect(double x1,double y1,double x2,double y2)
{
		ul.x=x1;
		ul.y=y1;
		dr.x=x2;
		dr.y=y2;
}

int rect::valid()
{
	if(ul.x<=dr.x&&ul.y>=dr.y)
		return 1;
	else
		return 0;
}

double rect::area()
{
	double S=0;
	S=abs(ul.x-dr.x)*abs(ul.y-dr.y);
	return S;
}

double rect::overlap(rect a)
{
	rect overlap_arc;
	overlap_arc.ul.x=max(ul.x,a.ul.x);
	overlap_arc.ul.y=min(ul.y,a.ul.y);
	overlap_arc.dr.x=min(dr.x,a.dr.x);
	overlap_arc.dr.y=max(dr.y,a.dr.y);
	if(overlap_arc.valid())
		return overlap_arc.area();
	else 
		return 0;
}

int main()
{

	rect a(1,1,2,0),b(1.5,0.5,2.5,-1);
	cout<<"the overlap area is : "<<a.overlap(b)<<endl;
}
