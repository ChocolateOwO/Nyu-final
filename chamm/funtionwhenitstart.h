void Gamesta(){
    cout << "Press H to Start or X to Exit." << endl;
    while (! STA) {//เราต้องการให้loopนีรันอยู่ตลอดในตอนที่gameOverไปแล้วเลยเซ็ทเป็นwhile(true)
        if (_kbhit()) {//ถ้ามีการกดปุ่ม
            char choice = _getch();//choice = ปุ่มที่กด
            if (choice == 'H' || choice == 'h') {//ถ้าปุ่มที่กดเป็นr
                STA = true;//เซ็ทเกมใหม่
                break;
            } else if (choice == 'x' || choice == 'X') {//ถ้าปุ่มที่กดเป็นx
                gameOver = true;
                restart = false;//ออกเกม
                break;
            }
        }
    }
}