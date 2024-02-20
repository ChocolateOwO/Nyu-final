#include <iostream> 
#include <conio.h>
#include <windows.h>
#include <ctime>
#include "setup.h"
#include "Logic.h"
#include "Input.h"
#include "generateFruit.h"
#include "funtiondrawgameover.h"
#include "funtiongameover.h"
#include "funtionstart.h"
#include "funtionwhenitstart.h"
using namespace std;

bool gameOver; //ตัวแปรนี้ไว้ใช้ปรับให้มันเป็น true กะ false ก็คือเกมจะเซ็ตไว้เป็นflaseก่อนแล้วถ้าเกิดเจออะไรที่ทำให้มันตายก็แค่เปลี่ยนตัวแปรนี้เป็นtrue เกมก็จะข้ามwhile loop ของระบบเกมทั้งหมดไป
bool restart = true;//ตัวแปรนี้จะเป็นตัวแปรที่อยู่ในwhile loop ที่ครอบwhile loop ของgameOverไว้อีกที เอาไว้สำหรับปุ่มเริ่มใหม่
const int width = 20; // -->> width กะ height มีไว้กำหนดขอบของเกมไม่ให้งูเดินเลยขอบ 
const int height = 20; // ----^^
int x, y, fruitX, fruitY,MinusFruitX,MinusFruitY, boostFruitX, boostFruitY, poisonFruitX, poisonFruitY, fatFruitX, fatFruitY, reverseFruitX, reverseFruitY, score;
// ^^บรรทัดบนนี้กำหนดตัวแปรส่วนใหญ่คือการระบุตำแหน่งของผลไม้แต่ละชนิดกะตัวงูยกเว้นscoreที่เอาไว้เก็บแต้มของคนเล่น
int tailX[200], tailY[200]; //สองอันนี้มีไว้เก็บว่าตอนนี้งูมีกี่หางแล้ว
int nTail; // อันนี้คือตัวแปรที่จะเพิ่มขึ้นถ้างูกินผลไม้เอาไว้ใส่แบบนี้ tailX[nTail](อันนี้แค่ประมาณนะเดี๋ยวข้างในจริงๆจะเป็นตัวk)
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN }; //อันนี้กำหนดทิศเอาไว้สำหรับให้งูเดิน 
eDirection dir; //อันนี้ก็คืออันบน^นั่นแหละะแค่ทำให้สั้นลง555
bool isBoosted = false; //อันนี้เอาไว้สำหรับผลไม้บูสความเร็ว มันจะคล้ายๆgameOver คือเราจะกำหนดมันเป็นtrue กะ false ถ้าเกิดงูกินผลนี้กะให้ค่านี้เป็นtrue แล้วมันก็จะเข้าคอนดิชั่นif
bool isReversed = false;//อันนี้เหมือนอันบนเลย แค่เป็นของผลรีเวิร์ส
int boostDuration ; //อันนี้คือตัวแปรที่จะบอกว่างูจะได้เราสถานะบูสกี่เฟรม
int reverseDuration ;  //อันนี้กะสถานะรีเวิร์สกี่เฟรม
bool fruitEat;//อันนี้เป็นตัวแปรที่จะบอกว่างูกินผลไม้ยัง มีไว้สำหรับระบบที่ผลไม้จะโผล่แค่2ผลแบบสุ่ม(ตอนแรกกะเลยไม่มี555)
string fruit1;//อันนี้คือเราไม่อยากให้ผลไม้2ผลที่ranมามันเป็นผลเดียวกันเลยมีตัวแปรนี้สำหรับบอกว่าผลไม้อันที่1คือผลอะไร
 bool STA = false;

int main() {//เกมมีแค่นี้แหละะ
srand(time(0));
    Setup();//ยัดฟังก์ชั่นsetเข้าไป กำหนดค่าของตัวแปรต่างๆ
    while(restart){//ถ้าคนเล่นยังไม่กดออกก็วนต่อไปป
    start();
    Gamesta();
    while (!gameOver) {//gameOverเป็นfalseอยู่ก็เล่นต่อไปป
        Draw();//สร้างmapขึ้นใหม่ในทุกๆเฟรม
        generateFruit();//สร้างผลไม้1ทุกครั้งที่กิน
        generateFruit2();//สร้างผลไม้2ทุกครั้งที่กิน
        Input();//รับinputเพื่อเดินในทุกๆเฟรม
        Logic();//ทำงานตามinputละกะLogicของเกม
        //Sleepคือการกำหนดความเร็วเฟรมยิงเฟรมผ่านไปเร็ว(ก็คือค่าในSleepยิ่งน้อย)งูก็จะดูเหมือนวิ่งไวขึ้นเท่านั้น
        if (isBoosted)//เช็คว่างูspeedอยู่ป่าว
            Sleep(20); // ถ้าspeedอยู่เพิ่มความเร็วของเฟรม
        else
            Sleep(100); // ถ้าไม่speedแล้ว ก็กลับมาความเร็วเฟรมปกติ
    }
    Rest();//วาดGAMEOVER
    GameOver();//รอดูว่าคนเล่นจะrestartหรือออก
    }
    return 0;
}