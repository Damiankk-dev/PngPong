//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TImage *paddleLeft;
    TImage *paddleRight;
    TTimer *timerPaddleLeftUp;
    TTimer *timerPaddleLeftDown;
    TTimer *timerPaddleRightDown;
    TTimer *timerPaddleRightUp;
    TShape *background;
    TImage *ball;
    TTimer *timerBall;
    TButton *startButton;
    TLabel *scoreHeader;
    TLabel *scores;
    TButton *repeatButton;
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall leftPaddleDown(TObject *Sender);
    void __fastcall leftPaddleUp(TObject *Sender);
    void __fastcall rightPaddleUp(TObject *Sender);
    void __fastcall rightPaddleDown(TObject *Sender);
    void __fastcall ballMove(TObject *Sender);
    void __fastcall startButtonClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall repeatButtonClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
