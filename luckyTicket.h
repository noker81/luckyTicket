//---------------------------------------------------------------------------

#ifndef luckyTicketH
#define luckyTicketH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TLabel *Label2;
	TButton *Button1;
	TButton *randomButton;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Labeltrue;
	TLabel *Labelfalse;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *LabelTotal;
	TLabel *Label8;
	TLabel *LabelMirror;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall randomButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
