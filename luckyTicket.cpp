//---------------------------------------------------------------------------

#include <vcl.h>
#include <random>
#pragma hdrstop

#include "luckyTicket.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int totalTrue = 0, totalFalse = 0, totalMirror = 0;
int totalTickets = 1000000;
int passArray[1000000];

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	int passArraySize = sizeof(passArray) / sizeof(int);
	for (int i = 0; i < passArraySize; i++){
		passArray[i] = i;
	}
}

void statistics_update() {

	Form1->Labeltrue->Caption = IntToStr(totalTrue) + " / " \
			+ FloatToStr(totalTrue*100/(totalTrue + totalFalse)) + "%";

	Form1->Labelfalse->Caption = IntToStr(totalFalse) + " / " \
			+ FloatToStr(totalFalse*100/(totalTrue + totalFalse)) + "%";

	String msg = "0";
	if (totalTrue + totalMirror > 0)
		msg = FloatToStr(totalMirror*100/(totalTrue + totalMirror));

	Form1->LabelMirror->Caption = IntToStr(totalMirror) + " / " \
			+ msg + "% от счастливых";

	Form1->LabelTotal->Caption = IntToStr(totalFalse + totalTrue) + " / " \
			" осталось " + totalTickets;
	return;
}

void ticket_check() {
	int num[6];
	for (int i = 0; i < 6; ++i) {
		TEdit *Edit = (TEdit *)Form1->FindComponent("Edit" + AnsiString(i + 1));
		num[i] = Edit->Text.ToInt();
	}

	int x = num[0] + num[1] + num[2];
	int y = num[3] + num[4] + num[5];
	String x_str = IntToStr(num[0]) + IntToStr(num[1]) + IntToStr(num[2]);
	String y_str = IntToStr(num[5]) + IntToStr(num[4]) + IntToStr(num[3]);


	if (x == y) {
		String msg = "";
		if (x_str == y_str) {
			msg = " / Зеркальный";
			totalMirror++;
		}

		Form1->Label2->Caption = "Счастливый билет" + msg;
		totalTrue++;
	}
	else {
	   Form1->Label2->Caption = "Не счастливый билет";
	   totalFalse++;
	}

	//Обновляем статистику
	statistics_update();
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	ticket_check();
}

//---------------------------------------------------------------------------
void __fastcall TForm1::randomButtonClick(TObject *Sender)
{

	if (totalTickets > 0) {

		//rand() устарела, генерирует плохо
		//RAND_MAX обычно равно 32767 для
		std::random_device r;
		std::default_random_engine e1(r());
		std::uniform_int_distribution<int> uniform_dist(0, totalTickets - 1);

		int number = uniform_dist(e1);
		int randomTicket = passArray[number];
		int a = 100000;
		for (int i=1; i<7; ++i) {
			TEdit *Edit = (TEdit *)FindComponent("Edit" + AnsiString(i));
			Edit->Text = IntToStr(randomTicket % (a*10) / a);
			a /= 10;
		}
		Label2->Caption = "";
		//Удаляем билет из массива
		for (long i = number; i < totalTickets; ++i){
		  passArray[i] = passArray[i + 1];
		}
		--totalTickets;

		ticket_check();
	}
	else {
		Label2->Caption = "Все билеты проданы.";
    }
}
//---------------------------------------------------------------------------

