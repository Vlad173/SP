/* $g07 */
#include "code-gen.h"
using namespace std;
int tCG::p01(){ // S -> PROG
  string header ="/*  " + lex.Authentication()+"   */\n";
  header += "#include \"mlisp.h\"\n";
  header += declarations;
  header += "//________________ \n";
  S1->obj = header + S1->obj;
	return 0;}
int tCG::p02(){ //   PROG -> CALCS1
	S1->obj = "int main(){\n" + S1->obj
    + "std::cin.get();\nreturn 0;\n}\n";
	return 0;}
int tCG::p03(){ //   PROG -> DEFS
	S1->obj += "int main(){\n"
    "display(\"No calculations!\");newline();\n"
    "std::cin.get();\nreturn 0;\n}\n";
	return 0;}
int tCG::p04(){ //   PROG -> DEFS CALCS1
 	S1->obj = S1->obj + "int main(){\n" + S2->obj
    + "std::cin.get();\nreturn 0;\n}\n";
	return 0;}
int tCG::p05(){ // CALCS1 -> CALCS
//empty
	return 0;}
int tCG::p06(){ //  CALCS -> CALC
//empty
	return 0;}
int tCG::p07(){ //  CALCS -> CALCS CALC
	S1->obj += S2->obj;
	return 0;}
int tCG::p08(){ //   CALC -> E1
	S1->obj = "display("+S1->obj+"); newline();\n";
	return 0;}
int tCG::p09(){ //   CALC -> BOOL
	S1->obj = "display("+S1->obj+"); newline();\n";
	return 0;}
	
int tCG::p10(){ //   CALC -> STR
	S1->obj = "display("+S1->obj+"); newline();\n";	
	return 0;}
int tCG::p11(){ //   CALC -> DISPSET
	S1->obj +=";\n";
	return 0;}	
int tCG::p12(){ //     E1 -> E
//empty
	return 0;}
int tCG::p13(){ //      E -> $id
	S1->obj = decor(S1->name);
	return 0;}
int tCG::p14(){ //      E -> CONST
//empty
	return 0;}
int tCG::p15(){ //      E -> ADD
	return 0;}
int tCG::p16(){ //      E -> SUB
	return 0;}
int tCG::p17(){ //      E -> DIV
	return 0;}
int tCG::p18(){ //      E -> MUL
//empty
	return 0;}
int tCG::p19(){ //      E -> COND
	return 0;}
int tCG::p20(){ //      E -> CPROC
//empty
	return 0;}
int tCG::p21(){ //  CONST -> $zero
	S1->obj = S1->name;
	return 0;}
int tCG::p22(){ //  CONST -> $dec
	S1->obj = S1->name;
	return 0;}
int tCG::p23(){ //    ADD -> HADD E1 )
	S1->obj += S2->obj;
	S1->obj += ")";
	return 0;}
int tCG::p24(){ //   HADD -> ( +
	S1->count = 0;
	S1->obj = "(";
	return 0;}
int tCG::p25(){ //   HADD -> HADD E1
	S1->obj += S2->obj + " + ";
	return 0;}
int tCG::p26(){ //    SUB -> ( - E1 )
	S1->obj = "( -" +S3->obj + ")";
	return 0;}
int tCG::p27(){ //    DIV -> HDIV E1 )
	S1->obj += S2->obj + "";
	return 0;}
int tCG::p28(){ //   HDIV -> ( / E
	S1->obj = S3->obj + "/";
	return 0;}
int tCG::p29(){ //    MUL -> HMUL E1 )
	if(S1->count==0)
		S1->obj = S2->obj;
	else
		S1->obj += S2->obj ;
	S1->count =0;
	return 0;}
int tCG::p30(){ //   HMUL -> ( *
//empty
	return 0;}
int tCG::p31(){ //   HMUL -> HMUL E1
	S1->obj += S2->obj + " * ";
	++S1->count;
	return 0;}
int tCG::p32(){ //   COND -> HCOND ELSE )	
	S1->obj += S2->obj + ")";
	return 0;}
int tCG::p33(){ //  HCOND -> ( cond
	S1->obj = "(";
	S1->count = 0;
	return 0;}
int tCG::p34(){ //  HCOND -> HCOND CLAUS
	if(S1->count) S1->obj+="\n:";
	S1->obj+=S2->obj;
	++S1->count;
	return 0;}
int tCG::p35(){ //  CLAUS -> HCLAUS E1 )
	if(S1->count) S1->obj+=",";
	S1->obj += S2->obj;
	return 0;}
int tCG::p36(){ // HCLAUS -> ( BOOL	
	S1->count = 0;
	S1->obj = S2->obj + " ? " ;
	return 0;}
int tCG::p37(){ // HCLAUS -> HCLAUS DISPSET
	//составные ветви cond, аналогичное в else
	if(S1->count) S1->obj+=",";
	S1->obj+=S2->obj;
	++S1->count;
	return 0;}
int tCG::p38(){ //   ELSE -> HELSE E1 )	
	if(S1->count) S1->obj+=",";
	S1->obj += S2->obj;
	return 0;}
int tCG::p39(){ //  HELSE -> ( else	
	S1->count = 0;
	S1->obj="\n: ";
	return 0;}
int tCG::p40(){ //  HELSE -> HELSE DISPSET
	if(S1->count) S1->obj+=",";
	S1->obj+=S2->obj;	
	++S1->count;
	return 0;}
int tCG::p41(){ //    HIF -> ( if BOOL
	S1->obj = ""+S3->obj+" ?";
	return 0;}
int tCG::p42(){ //  CPROC -> HCPROC )
	S1->obj+=")";
	return 0;}
int tCG::p43(){ // HCPROC -> ( $id
	S1->obj = decor(S2->name) + "(";
	S1->count = 0;
	return 0;}
int tCG::p44(){ // HCPROC -> HCPROC E
	if(S1->count) S1->obj += ", ";
	S1->obj += S2->obj;
	++(S1->count);
	return 0;}
int tCG::p45(){ //   BOOL -> $bool
	S1->obj = (S1->name=="#t" ? "true" : "false");
	return 0;}
int tCG::p46(){ //   BOOL -> CPRED
	return 0;}
int tCG::p47(){ //   BOOL -> REL
//empty
	return 0;}
int tCG::p48(){ //   BOOL -> AND
	return 0;}
int tCG::p49(){ //   BOOL -> ( not BOOL )
	S1->obj += "!(";	
	S1->obj += S3->obj;
	S1->obj += ")";
	return 0;}
int tCG::p50(){ //  CPRED -> HCPRED )	
	S1->obj += ")";
	return 0;}
int tCG::p51(){ // HCPRED -> ( $idq
	S1->obj = decor(S2->name) + "(";	
	S1->count = 0;
	return 0;}
int tCG::p52(){ // HCPRED -> HCPRED E
	if(S1->count) S1->obj += ", ";
	S1->obj += S2->obj;
	++(S1->count);
	return 0;}
int tCG::p53(){ //    REL -> HREL E1 )
	S1->obj += S2->obj;
	S1->obj += ")";
	return 0;}
int tCG::p54(){ //   HREL -> ( >= E
	S1->obj += "(" + S3->obj;	
 	S1->obj += " >= ";
	return 0;}
int tCG::p55(){ //   HREL -> ( = E
	S1->obj += "(" + S3->obj;	
 	S1->obj += " == ";
	return 0;}
int tCG::p56(){ //    AND -> HAND BOOL )
	S1->obj += S2->obj;
	return 0;}
int tCG::p57(){ //   HAND -> ( and
	return 0;}
int tCG::p58(){ //   HAND -> HAND BOOL
	S1->obj += S2->obj + " && ";
	return 0;}
int tCG::p59(){ //    STR -> $str
	S1->obj = S1->name;
	return 0;}
int tCG::p60(){ //    STR -> SIF
	return 0;}
int tCG::p61(){ //    SIF -> SIFTRUE STR )
	S1->obj += ":"+S2->obj;
	return 0;}
int tCG::p62(){ //SIFTRUE -> HIF STR
	S1->obj += S2->obj;
	return 0;}
int tCG::p63(){ //    SET -> HSET E1 )
	S1->obj += " = " + S2->obj ;
	return 0;}
int tCG::p64(){ //   HSET -> ( set! $id
	S1->obj += decor(S3->name);
	return 0;}
int tCG::p65(){ //DISPSET -> ( display E1 )
	S1->obj = "display("+S3->obj+")";
	return 0;}
int tCG::p66(){ //DISPSET -> ( display BOOL )
	S1->obj = "display("+S3->obj+")";
	return 0;}
int tCG::p67(){ //DISPSET -> ( display STR )
	S1->obj = "display("+S3->obj+")";
	return 0;}
int tCG::p68(){ //DISPSET -> ( newline )
	S1->obj = "newline()";
	return 0;}
int tCG::p69(){ //DISPSET -> SET
	return 0;}
int tCG::p70(){ //   DEFS -> DEF
//empty
	return 0;}
int tCG::p71(){ //   DEFS -> DEFS DEF
	S1->obj+=S2->obj;
	return 0;}
int tCG::p72(){ //    DEF -> PRED
	return 0;}
int tCG::p73(){ //    DEF -> VAR
	return 0;}
int tCG::p74(){ //    DEF -> PROC
//empty
	return 0;}
int tCG::p75(){ //   PRED -> HPRED BOOL )
	S1->obj += "return " + S2->obj +";\n}\n";
	return 0;}
int tCG::p76(){ //  HPRED -> PDPAR )
	S1->obj += ")";
	declarations += S1->obj + ";\n";
	S1->obj += "{\n";
	return 0;}
int tCG::p77(){ //  PDPAR -> ( define ( $idq
	S1->obj = "bool " + decor(S4->name) + "(";
	S1->count=0;
	return 0;}
int tCG::p78(){ //  PDPAR -> PDPAR $id
	if(S1->count)S1->obj += ", ";
	S1->obj += "double " + decor(S2->name);
	++(S1->count);
	return 0;}
int tCG::p79(){ //    VAR -> VARINI )
		/*согласно правилам трансляции:
	Определения 
  глобальных переменных переносятся в начало 
 программы БЕЗ предварительных  объявлений.

тогда переменные будут определены в declarations
и повторное определение  как DEF не требуется
 */
	declarations += S1->obj;
	S1->obj = "";
	return 0;}
int tCG::p80(){ // VARINI -> HVAR CONST
	S1->obj += " = " + S2->obj + ";\n"; 
	return 0;}
int tCG::p81(){ //   HVAR -> ( define $id
	S1->obj = "double " + decor(S3->name);
	return 0;}
int tCG::p82(){ //   PROC -> HPROC LETLOC )
	S1->obj += S2->obj + "}\n";
	return 0;}
int tCG::p83(){ //   PROC -> HPROC E1 )
	S1->obj += "return "+S2->obj + ";}\n";
	return 0;}
int tCG::p84(){ //  HPROC -> PCPAR )
	S1->obj += ")";
	declarations += S1->obj + ";\n";
	S1->obj += "{\n";
	return 0;}
int tCG::p85(){ //  HPROC -> HPROC DISPSET
	S1->obj += S2->obj + ";\n";
	return 0;}
int tCG::p86(){ //  PCPAR -> ( define ( $id
	S1->obj += "double " + decor(S4->name) + "(";
	S1->count=0;
	return 0;}
int tCG::p87(){ //  PCPAR -> PCPAR $id
	if(S1->count)S1->obj += ", ";
	S1->obj += "double " + decor(S2->name);
	++(S1->count);
	return 0;}
int tCG::p88(){ // LETLOC -> HLETLOC E1 )
	S1->obj += "return " + S2->obj +";\n}//let\n";
	return 0;}
int tCG::p89(){ //HLETLOC -> LTVAR )
	S1->obj += ";\n";
	return 0;}
int tCG::p90(){ //HLETLOC -> HLETLOC DISPSET	
	S1->obj += S2->obj + ";\n";
	return 0;}
int tCG::p91(){ //  LTVAR -> ( let ( CPROC
	S1->obj = "{//let\n double " + S4->obj;
	return 0;}
int tCG::p92(){ //  LTVAR -> LTVAR CPROC
	S1->obj += ", " + S2->obj ;
	return 0;}
//_____________________
int tCG::p93(){return 0;} int tCG::p94(){return 0;} 
int tCG::p95(){return 0;} int tCG::p96(){return 0;} 
int tCG::p97(){return 0;} int tCG::p98(){return 0;} 
int tCG::p99(){return 0;} int tCG::p100(){return 0;} 
int tCG::p101(){return 0;} int tCG::p102(){return 0;} 
int tCG::p103(){return 0;} int tCG::p104(){return 0;} 
int tCG::p105(){return 0;} int tCG::p106(){return 0;} 
int tCG::p107(){return 0;} int tCG::p108(){return 0;} 
int tCG::p109(){return 0;} int tCG::p110(){return 0;} 


