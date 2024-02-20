#include <iostream> 
#include <conio.h>
#include <windows.h>
#include <ctime>
using namespace std;

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