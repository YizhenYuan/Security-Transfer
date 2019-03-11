#include<stdio.h>
#include<math.h>
typedef struct{
  double x;
  double y;
}point;
typedef struct{
  point center;
  double r;
}circle;
typedef struct{
  double k;
  double b;
}line;
point intersect(line a,line b){
  // input is the two lines
  // and the function returns the point where they intersect
  // what should return when they do not intersect?
  double x=(b.b-a.b)/(a.k-b.k);
  return (point){x,a.k*x+a.b};
}
void print_point(point a){
  printf("x=%.2f,y=%.2f\n",a.x,a.y);
}
line parallel(int k,point p){
  //input is a slope and point
  //return a line parallel to the slope and passing through the point
  return (line){k,p.y-k*p.x};
}
line mid_perpendicular_line(point a, point b){
  //input is two points
  //return the line ZHONGWEIXIAN
  double k=-1.0/((a.y-b.y)/(a.x-b.x));
  point mid=(point){(a.x+b.x)/2,(a.y+b.y)/2};
  return parallel(k,mid);
}
double distance_p_p(point a,point b){
  double x=a.x-b.x;
  double y=a.y-b.y;
  return sqrt(x*x+y*y);
}
circle get_circle(point a,point b,point c){
  point center=intersect(mid_perpendicular_line(a,b),mid_perpendicular_line(b,c));
  double r=distance_p_p(a,center);
  return (circle){center,r};
}
int main(){
  point a={0,0};
  point b={3,0};
  point c={0,4};
  print_point(get_circle(a,b,c).center);
}
  
