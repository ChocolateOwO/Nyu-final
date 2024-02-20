void start(){
        system("cls");//ลบหน้าเก่าในทุกๆเฟรม
for (int i = 0; i < width + 2; i++)//อันนี้คือวาดรั้วด้านบน
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) { // อันนี้คือการวาดพื้นที่ด้านใน20*20 i = แกน y ,j = แกนx
        for (int j = 0; j < width+2; j++) {
            if (j == 0)//อันนี้คือการวาดรั้วด้านซ้าย
                cout << "#";
            else if(i == (height/2)-1 && j == (width/2)-4) cout << "S";//ไอ่พวกนี้คือวาดคำว่าSNAKEGAME กลางจอ
            else if(i == (height/2)-1 && j == (width/2)-3) cout << "N";//^
            else if(i == (height/2)-1 && j == (width/2)-2) cout << "A";//^
            else if(i == (height/2)-1 && j == (width/2)-1) cout << "K";//^
            else if(i == (height/2)-1 && j == (width/2)) cout << "E";//^
            else if(i == (height/2)-1 && j == (width/2)+2) cout << "G";//^
            else if(i == (height/2)-1 && j == (width/2)+3) cout << "A";//^
            else if(i == (height/2)-1 && j == (width/2)+4) cout << "M";//^
            else if(i == (height/2)-1 && j == (width/2)+5) cout << "E";//^
            else if (j == width + 1)//อันนี้คือการวาดรั้วด้านขวา 
                cout << "#";
            else if (j > 0 && j < width + 1)cout << " ";//วาดช่องว่างตรงที่ไม่มีอะไร
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)//อันนี้คือวาดรั้วด้านล่าง
        cout << "#";
    cout << endl;
    cout << "Score:" << score << endl;//โชว์แต้มscore
Sleep(100);//กำหนดความเร็วเฟรม

}
