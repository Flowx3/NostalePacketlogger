//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.ComCtrls.hpp>
#include <string>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
	TPageControl *PageControl1;
	TTabSheet *Packetlogger;
	TTabSheet *TabSheet2;
	TImage *Image1;
	TLabel *Label1;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TEdit *Edit2;
	TButton *Button1;
	TEdit *Edit3;
	TButton *Button2;
	TMemo *Memo1;
	TPageControl *PageControl2;
	TTabSheet *TabSheet1;
	TListBox *ListBox1;
	TButton *Add;
	TButton *Remove;
	TEdit *Edit1;
	TTabSheet *TabSheet3;
	TListBox *ListBox2;
	TButton *Button5;
	TButton *Button6;
	TEdit *Edit4;
	TButton *Button3;
	TButton *Button4;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TButton *Button11;
	TLabel *Label3;
	TButton *Button12;
	TButton *Button13;
	TButton *Button14;
	TButton *Button15;
	TButton *Button16;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall AddClick(TObject *Sender);
    void __fastcall Button5Click(TObject *Sender);
    void __fastcall Button6Click(TObject *Sender);
    void __fastcall RemoveClick(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall Button14Click(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
	void __fastcall Button16Click(TObject *Sender);
private:	// Benutzer-Deklarationen
public:		// Benutzer-Deklarationen

	std::string userid;
	std::string lev;
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
