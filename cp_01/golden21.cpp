/*  EVS   */
#include "mlisp.h"
extern double a/*5*/ ;
	 extern double b/*5*/ ;
	 double fun/*6*/ (double x);
	 double golden__section__search/*10*/ (double a, double bz);
	 double golden__start/*18*/ (double a, double b);
	 extern double mphi/*27*/ ;
	 double __EVS__try/*28*/ (double a, double b
	 , double xa, double ya
	 , double xb, double yb);
	 bool close__enough_Q/*49*/ (double x, double y);
	 extern double tolerance/*51*/ ;
	 extern double total__iterations/*52*/ ;
	 extern double xmin/*53*/ ;
	 //________________ 
double a/*5*/ = 5.;
	 
double b/*5*/ = 7.;
	 
double fun/*6*/ (double x){
 x = (x - (109. / 110.));
	 return
 (exp((- x)) + sin(x));
	 }

double golden__section__search/*10*/ (double a, double bz){
 {
 double xmin(((a < b)
	? golden__start(a
	 , b)
	 
	: (golden__start(b
	 , a)
	 )));
	 newline();
	 return
 xmin;
	 }
}

double golden__start/*18*/ (double a, double b){
 total__iterations = 0.;
	 {
 double xa((a + (mphi * (b - a)))),
	 xb((b + (- (mphi * (b - a)))));
	 return
 __EVS__try(a
	 , b
	 , xa
	 , fun(xa)
	 , xb
	 , fun(xb))
	 ;
	 }
}

double mphi/*27*/ = ((3. - sqrt(5.)) * (1. / 2.0e0));
	 
double __EVS__try/*28*/ (double a, double b
	 , double xa, double ya
	 , double xb, double yb){
 return
 (close__enough_Q(a, b)
	? ((a + b) * 0.5e0)
	: (display("+"),
	 total__iterations = (total__iterations + 1.),
	 ((ya < yb)
	? b = xb,
	 xb = xa,
	 yb = ya,
	 xa = (a + (mphi * (b - a))),
	 __EVS__try(a
	 , b
	 , xa
	 , fun(xa)
	 , xb
	 , yb)
	 
	: (a = xa,
	 xa = xb,
	 ya = yb,
	 xb = (b - (mphi * (b - a))),
	 __EVS__try(a
	 , b
	 , xa
	 , ya
	 , xb
	 , fun(xb))
	 ))));
	 }

bool close__enough_Q/*49*/ (double x, double y){
 return (abs((x - y)) < tolerance);
	 }

double tolerance/*51*/ = 0.001e0;
	 
double total__iterations/*52*/ = 0.;
	 
double xmin/*53*/ = 0.;
	 int main(){
 display("Calculations!");
	 newline();
	 xmin = golden__section__search(a
	 , b)
	 ;
	 display("Interval=\t[");
	 display(a);
	 display(" , ");
	 display(b);
	 display("]\n");
	 display("Total number of iterations=");
	 display(total__iterations);
	 newline();
	 display("xmin=\t\t");
	 display(xmin);
	 newline();
	 display("f(xmin)=\t");
	 display(fun(xmin));
	 newline();
	 std::cin.get();
	 return 0;
	 }

