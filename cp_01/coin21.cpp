/*  EVS   */
#include "mlisp.h"
extern double VARIANT/*4*/ ;
	 extern double LAST__DIGIT__OF__GROUP__NUMBER/*5*/ ;
	 extern double KINDS__OF__COINS/*6*/ ;
	 double first__denomination/*8*/ (double kinds__of__coins);
	 bool AND3_Q/*20*/ (double x_Q, double y_Q
	 , double z_Q);
	 bool AND2_Q/*24*/ (double x_Q, double y_Q);
	 double count__change/*28*/ (double amount);
	 bool pier_Q/*57*/ (double x_Q, double y_Q);
	 bool OR_Q/*62*/ (double x_Q, double y_Q);
	 double cc/*67*/ (double amount, double kinds__of__coins);
	 double denomination__list/*75*/ (double kinds__of__coins);
	 double GR__AMOUNT/*85*/ ();
	 //________________ 
double VARIANT/*4*/ = 9.;
	 
double LAST__DIGIT__OF__GROUP__NUMBER/*5*/ = 6.;
	 
double KINDS__OF__COINS/*6*/ = 7.;
	 
double first__denomination/*8*/ (double kinds__of__coins){
 return
 ((kinds__of__coins == 1.)
	? 1.
	: (((kinds__of__coins == 2.)
	? 2.
	: (((kinds__of__coins == 3.)
	? 3.
	: (((kinds__of__coins == 4.)
	? 5.
	: (((kinds__of__coins == 5.)
	? 10.
	: (((kinds__of__coins == 6.)
	? 15.
	: (((kinds__of__coins == 7.)
	? 20.
	: (0.))))))))))))));
	 }

bool AND3_Q/*20*/ (double x_Q, double y_Q
	 , double z_Q){
 return (1. == (x_Q
	? (y_Q
	? (z_Q
	? 1.
	: (0.))
	: (0.))
	: (0.)));
	 }

bool AND2_Q/*24*/ (double x_Q, double y_Q){
 return (1. == (x_Q
	? (y_Q
	? 1.
	: (0.))
	: (0.)));
	 }

double count__change/*28*/ (double amount){
 display("______");
	 newline();
	 display(" amount: ");
	 newline();
	 display("KINDS-OF-COINS: ");
	 display(KINDS__OF__COINS);
	 newline();
	 {
 double largest__coin(first__denomination(KINDS__OF__COINS));
	 display("largest-coin: ");
	 display(largest__coin);
	 newline();
	 return
 (AND3_Q((0. < amount), (0. < KINDS__OF__COINS)
	 , (0. < largest__coin))
	? display("List of coin denominations: "),
	 denomination__list(KINDS__OF__COINS),
	 display("count-change= "),
	 cc(amount
	 , KINDS__OF__COINS)
	 
	: (display("Improrer parametr value!"),
	 newline(),
	 display("count-change ="),
	 -1.));
	 }
}

bool pier_Q/*57*/ (double x_Q, double y_Q){
 return (!OR_Q(x_Q, y_Q));
	 }

bool OR_Q/*62*/ (double x_Q, double y_Q){
 return (!AND2_Q((!x_Q), (!y_Q)));
	 }

double cc/*67*/ (double amount, double kinds__of__coins){
 return
 ((amount == 0.)
	? 1.
	: ((pier_Q((amount < 0.), (kinds__of__coins == 0.))
	? (cc(amount
	 , (kinds__of__coins - 1.))
	  + cc((amount - first__denomination(kinds__of__coins))
	 , kinds__of__coins)
	 )
	: (0.))));
	 }

double denomination__list/*75*/ (double kinds__of__coins){
 return
 ((kinds__of__coins == 0.)
	? newline(),
	 0.
	: (display(first__denomination(kinds__of__coins)),
	 display(" "),
	 denomination__list((kinds__of__coins - 1.))));
	 }

double GR__AMOUNT/*85*/ (){
 return
 remainder(((100. * LAST__DIGIT__OF__GROUP__NUMBER) + VARIANT)
	 , 231.)
	 ;
	 }
int main(){
 display("Calculations!");
	 newline();
	 display("Variant ");
	 display(VARIANT);
	 newline();
	 newline();
	 display(count__change(100.));
	 newline();
	 display(count__change(GR__AMOUNT()));
	 newline();
	 KINDS__OF__COINS = 13.;
	 display(count__change(100.));
	 newline();
	 display("(c) Epaneshnikov V.S. 2021");
	 newline();
	 std::cin.get();
	 return 0;
	 }

