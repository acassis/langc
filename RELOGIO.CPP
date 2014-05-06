#include<dos.h>
#include <string.h>
#include <stdlib.h>
int vartemp,i;
char varesc[25],timeValue[80],var[20];
//-----------------------------------------------------------------------
void testa()
{
  if(vartemp==0)
     strcpy(varesc,"Zero");
  if(vartemp==1)
     strcpy(varesc,"Um");
  else if(vartemp==2)
     strcpy(varesc,"D");
  else if(vartemp==3)
     strcpy(varesc,"Trˆs");
  else if(vartemp==4)
     strcpy(varesc,"Quatro");
  else if(vartemp==5)
     strcpy(varesc,"Cinco");
  else if(vartemp==6)
     strcpy(varesc,"Seis");
  else if(vartemp==7)
     strcpy(varesc,"Sete");
  else if(vartemp==8)
     strcpy(varesc,"Oito");
  else if(vartemp==9)
     strcpy(varesc,"Nove");
  else if(vartemp==10)
     strcpy(varesc,"Dez");
  else if(vartemp==11)
     strcpy(varesc,"Onze");
  else if(vartemp==12)
     strcpy(varesc,"Doze");
  else if(vartemp==13)
     strcpy(varesc,"Treze");
  else if(vartemp==14)
     strcpy(varesc,"Quatorze");
  else if(vartemp==15)
     strcpy(varesc,"Quinze");
  else if(vartemp==16)
     strcpy(varesc,"Desseis");
  else if(vartemp==17)
     strcpy(varesc,"Dezessete");
  else if(vartemp==18)
     strcpy(varesc,"Dezoito");
  else if(vartemp==19)
     strcpy(varesc,"Dezenove");
  else if(vartemp==20)
     strcpy(varesc,"Vinte");
  else if(vartemp==21)
     strcpy(varesc,"Vinte e Um");
  else if(vartemp==22)
     strcpy(varesc,"Vinte e Dois");
  else if(vartemp==23)
     strcpy(varesc,"Vinte e Trˆs");
  else if(vartemp==24)
     strcpy(varesc,"Vinte e Quatro");
  else if(vartemp==25)
     strcpy(varesc,"Vinte e Cinco");
  else if(vartemp==26)
     strcpy(varesc,"Vinte e Seis");
  else if(vartemp==27)
     strcpy(varesc,"Vinte e Sete");
  else if(vartemp==28)
     strcpy(varesc,"Vinte e Oito");
  else if(vartemp==29)
     strcpy(varesc,"Vinte e Nove");
  else if(vartemp==30)
     strcpy(varesc,"Trinta");
  else if(vartemp==31)
     strcpy(varesc,"Trinta e Um");
  else if(vartemp==32)
     strcpy(varesc,"Trinta e Dois");
  else if(vartemp==33)
     strcpy(varesc,"Trinta e Trˆs");
  else if(vartemp==34)
     strcpy(varesc,"Trinta e Quatro");
  else if(vartemp==35)
     strcpy(varesc,"Trinta e Cinco");
  else if(vartemp==36)
     strcpy(varesc,"Trinta e Seis");
  else if(vartemp==37)
     strcpy(varesc,"Trinta e Sete");
  else if(vartemp==38)
     strcpy(varesc,"Trinta e Oito");
  else if(vartemp==39)
     strcpy(varesc,"Trinta e Nove");
  else if(vartemp==40)
     strcpy(varesc,"Quarenta");
  else if(vartemp==41)
     strcpy(varesc,"Quarenta e Um");
  else if(vartemp==42)
     strcpy(varesc,"Quarenta e Dois");
  else if(vartemp==43)
     strcpy(varesc,"Quarenta e Trˆs");
  else if(vartemp==44)
     strcpy(varesc,"Quarenta e Quatro");
  else if(vartemp==45)
     strcpy(varesc,"Quarenta e Cinco");
  else if(vartemp==46)
     strcpy(varesc,"Quarenta e Seis");
  else if(vartemp==47)
     strcpy(varesc,"Quarenta e Sete");
  else if(vartemp==48)
     strcpy(varesc,"Quarenta e Oito");
  else if(vartemp==49)
     strcpy(varesc,"Quarenta e Nove");
  else if(vartemp==50)
     strcpy(varesc,"Cinquenta");
  else if(vartemp==51)
     strcpy(varesc,"Cinquenta e Um");
  else if(vartemp==52)
     strcpy(varesc,"Cinquenta e Dois");
  else if(vartemp==53)
     strcpy(varesc,"Cinquenta e Trˆs");
  else if(vartemp==54)
     strcpy(varesc,"Cinquenta e Quatro");
  else if(vartemp==55)
     strcpy(varesc,"Cinquenta e Cinco");
  else if(vartemp==56)
     strcpy(varesc,"Cinquenta e Seis");
  else if(vartemp==57)
     strcpy(varesc,"Cinquenta e Sete");
  else if(vartemp==58)
     strcpy(varesc,"Cinquenta e Oito");
  else if(vartemp==59)
     strcpy(varesc,"Cinquenta e Nove");
}

void showtime(char num[80])
{
	struct  time t;
	gettime(&t);
	int hours = t.ti_hour;
	vartemp=(hours>12) ? hours-12 : hours;
	testa();
	if(hours >= 12)
	   strcpy(timeValue," PM ");
	else strcpy(timeValue," AM ");
	itoa(vartemp,var,10);
	strcat(timeValue,var);
	vartemp=t.ti_min;
	if(vartemp<10)
	     strcpy(var,":0");
	else
	    strcpy(var,":");
	strcat(timeValue,var);
	itoa(vartemp,var,10);
	strcat(timeValue,var);
	vartemp=t.ti_sec;
	if(vartemp<10)
	  strcpy(var,":0");
	else strcpy(var,":");
	strcat(timeValue,var);
	itoa(vartemp,var,10);
	strcat(timeValue,var);
	strcpy(var,"  ");
	strcat(timeValue,var);
	if(hours>12)
	  vartemp=hours-12;
	else vartemp=hours;
	strcat(timeValue,varesc);
	if(vartemp>1){
	  if(vartemp==2)
	    strcpy(var,"uas horas ");
	  else strcpy(var," horas ");}
	else{
	  if(vartemp==0)
	    strcpy(var," hora ");
	  else strcpy(var,"a hora ");}
	strcat(timeValue,var);
	vartemp=t.ti_min;
	testa();
	strcat(timeValue,varesc);
	if(vartemp>1){
	  if(vartemp==2)
	    strcpy(var,"ois minutos ");
	  else strcpy(var," minutos ");}
	else strcpy(var," minuto ");
	strcat(timeValue,var);
	vartemp=t.ti_sec;
	testa();
	strcat(timeValue,varesc);
	if(vartemp>1){
	   if(vartemp==2)
	      strcpy(var,"ois segundos ");
	   else  strcpy(var," segundos ");}
	else strcpy(var," segundo ");
	strcat(timeValue,var);
	for(i=0;timeValue[1]!='\0';i++)
		    num[i]=timeValue[i];
}

//---------------------------------------------------------------------------

