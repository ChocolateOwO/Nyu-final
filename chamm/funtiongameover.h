void GameOver() {//ฟังก์ชั่นนี้คือปุ่มrestart
    cout << "Game Over! Press R to Restart or X to Exit." << endl;
    while (true) {//เราต้องการให้loopนีรันอยู่ตลอดในตอนที่gameOverไปแล้วเลยเซ็ทเป็นwhile(true)
        if (_kbhit()) {//ถ้ามีการกดปุ่ม
            char choice = _getch();//choice = ปุ่มที่กด 
            if (choice == 'r' || choice == 'R') {//ถ้าปุ่มที่กดเป็นr
                Setup();//เซ็ทเกมใหม่
                return;//กลับไปเริ่มloopด้านบนใหม่
            } else if (choice == 'x' || choice == 'X') {//ถ้าปุ่มที่กดเป็นx
                restart = false;//ออกเกม
                return;
            }
        }
    }
}