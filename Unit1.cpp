//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------

int ballVelocityX = 40;
int ballVelocityY = 40;
int pointLeft = 0;
int pointRight = 0;
bool leftScored = true;
bool rightScored = false;

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if ( Key == 0x41 ) timerPaddleLeftUp->Enabled = true;
   if ( Key == 0x5A ) timerPaddleLeftDown->Enabled = true;

   if ( Key == VK_UP ) timerPaddleRightUp->Enabled = true;
   if ( Key == VK_DOWN ) timerPaddleRightDown->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if ( Key == 0x41 ) timerPaddleLeftUp->Enabled = false;
   if ( Key == 0x5A ) timerPaddleLeftDown->Enabled = false;

   if ( Key == VK_UP ) timerPaddleRightUp->Enabled = false;
   if ( Key == VK_DOWN ) timerPaddleRightDown->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::leftPaddleDown(TObject *Sender)
{
    if (paddleLeft->Top < background->Height - paddleLeft->Height ) paddleLeft->Top += 20;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::leftPaddleUp(TObject *Sender)
{
    if ( paddleLeft->Top >= 0 ) paddleLeft->Top -= 20;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightPaddleDown(TObject *Sender)
{
    if (paddleRight->Top < background->Height - paddleRight->Height ) paddleRight->Top += 20;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightPaddleUp(TObject *Sender)
{
    if ( paddleRight->Top >= 0 ) paddleRight->Top -= 20;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::ballMove(TObject *Sender)
{
    ball->Left += -ballVelocityX;
    ball->Top += -ballVelocityY;
    //odbicie od do≥u
    if ( ball->Top >= background->Height -  ball->Height ) ballVelocityY = -ballVelocityY;
    //odbicie od gÛry
    if ( ball->Top <= 0 ) ballVelocityY = -ballVelocityY;

     //skucha
    if ( ball->Left > background->Width - ball->Width )
    { //punkt dla gracza lewego
        startButton->Visible = true;
        timerBall->Enabled = false;
        ball->Top = 284;
        ball->Left = 584;
        pointLeft++;
        leftScored = true;
        if ( pointLeft != 0 || pointRight != 0 ) repeatButton->Visible = true;
        scores->Caption = IntToStr(pointLeft) + " : " + IntToStr(pointRight);
        scores->Visible = true;
        scoreHeader->Visible = true;
    } //punkt dla gracza lewego
    else if ( ball->Left < 0 ){
        startButton->Visible = true;
        timerBall->Enabled = false;
        ball->Top = 284;
        ball->Left = 584;
        pointRight++;
        rightScored = true;
        if ( pointLeft != 0 || pointRight != 0 ) repeatButton->Visible = true;
        scores->Caption = IntToStr(pointLeft) + " : " + IntToStr(pointRight);
        scores->Visible = true;
        scoreHeader->Visible = true;
    }  //odbicie srodkiem lewego gracza
    else if ( ball->Top + ball->Height/2 > paddleLeft->Top &&
                ball->Top + ball->Height/2 < paddleLeft->Top + paddleLeft->Height &&
                ball->Left < paddleLeft->Left + paddleLeft->Width) {
        if ( ballVelocityX > 0)  ballVelocityX = -ballVelocityX;
        if (ball->Top + ball->Height/2 == paddleLeft->Top +  paddleLeft->Height/2){
            ballVelocityX *=2;
            if ( ballVelocityY < 0 )ballVelocityY -=5;
            else ballVelocityY +=5;
        } else {
            if ( ballVelocityY * ballVelocityY != ballVelocityX * ballVelocityX ) {
                if (ballVelocityX < 0) {
                    if ( ballVelocityY < 0 ) ballVelocityX = ballVelocityY;
                    else ballVelocityX = -ballVelocityY;
                } else {
                    if ( ballVelocityY > 0 ) ballVelocityX = ballVelocityY;
                    else ballVelocityX = -ballVelocityY;
                }
            }
		}
    } //odbicie srodkiem prawego gracza
    else if ( ball->Top + ball->Height/2 >= paddleRight->Top &&
                ball->Top + ball->Height/2 <= paddleRight->Top + paddleRight->Height &&
                ball->Left + ball->Width > paddleRight->Left ) {
        if ( ballVelocityX < 0)ballVelocityX = -ballVelocityX;
        if (ball->Top + ball->Height/2 == paddleRight->Top +  paddleRight->Height/2){
            ballVelocityX *=2;
            if ( ballVelocityY < 0 )ballVelocityY -=5;
            else ballVelocityY +=5;
        } else {
            if ( ballVelocityY * ballVelocityY != ballVelocityX * ballVelocityX ) {
                if (ballVelocityX < 0) {
                    if ( ballVelocityY < 0 ) ballVelocityX = ballVelocityY;
                    else ballVelocityX = -ballVelocityY;
                } else {
                    if ( ballVelocityY > 0 ) ballVelocityX = ballVelocityY;
                    else ballVelocityX = -ballVelocityY;
                }
            } 
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::startButtonClick(TObject *Sender)
{
    startButton->Visible = false;
    repeatButton->Visible = false;
    scores->Visible = false;
    scoreHeader->Visible = false;
    timerBall->Enabled = true;

    ballVelocityY = 10;
    if (leftScored) ballVelocityX = -10;
    if (rightScored) ballVelocityX = 10;
    if ( ballVelocityY < 0 ) ballVelocityY = 10;
    else ballVelocityY = 10;
    leftScored = false;
    rightScored = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
    repeatButton->Visible = false;
    AnsiString helloMessage = "Witaj w grze PingPong";
    helloMessage += sLineBreak;
    helloMessage += sLineBreak;
    helloMessage += "Sterowanie:";
    helloMessage += sLineBreak;
    helloMessage += "Gracz Lewy: A oraz Z";
    helloMessage += sLineBreak;
    helloMessage += "Gracz prawy: strza≥ka do gÛry oraz do do≥u";
    helloMessage += sLineBreak;
    helloMessage += sLineBreak;
    helloMessage += "Po odbiciu pi≥ki dok≥adnie úrodkiem paletki, zwiÍksza siÍ prÍdkoúÊ pi≥ki";
    helloMessage += sLineBreak;
    helloMessage += sLineBreak;
    helloMessage += "Mi≥ej zabawy!";
    ShowMessage(helloMessage);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::repeatButtonClick(TObject *Sender)
{
    if ( Application->MessageBoxA(
        "Czy na pewno rozpoczπc nowπ grÍ?", "Potwierdü",
        MB_YESNO | MB_ICONQUESTION) == IDYES )
    {
        pointLeft = 0;
        pointRight = 0;
        startButtonClick(Form1);
    }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    if ( Application->MessageBoxA(
        "Czy na pewno chcesz zamknπc?", "Potwierdü",
        MB_YESNO | MB_ICONQUESTION) == IDNO )
    {
        Action = caNone;
    } 
}
//---------------------------------------------------------------------------

