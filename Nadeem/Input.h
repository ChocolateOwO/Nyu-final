void Input() {//ฟังก์ชั่นนี้มีไว้รับinputในการเดิน wsadนั่นแหละะ
    if (_kbhit()) {//ไอ่_kbhit()เนี่ยหน้าที่ของมันคือการตรวจดูว่าคนเล่นได้กดคีย์บอร์ดมั้ย ถ้ากดก็เข้าคอนดิชั่น ถ้าไม่กดก็skipไป
        char choice = _getch(); //ไอ่_getch()คือการตรวจดูว่าสวิชที่คนเล่นกดคือสวิชอะไร
        //ไอ้พวกdir != RIGHT ,LEFT หรืออะไรเนี่ยเราใส่มาเพราไม่อยากให้งูมันเดินกลับหลัง180องศา เพราะมันจะชนหางตัวเองที่วิ่งมาตามมัน ก็เลยใส่ไว้ให้มันเดินได้แค่ซ้ายกะขวาของทางที่มันเดินอยู่
        if(choice == 'a' or choice == 'A'){//ถ้ากดตัว a
            if (dir  !=RIGHT){//เช็คก่อนว่ามันเดินขวาอยู่รึเปล่าถ้า ไม่ใช่ ไปต่อ 
                if (isReversed && dir != LEFT) dir = RIGHT;//อันนี้คือผลไม้มึนมันจะทำให้งูเดินคนละทางกะที่สั่งก็เลยใส่บรรทัดนี้มาในกรณีที่มันมึนอยู่
                else dir = LEFT;//ถ้าไม่มึนก็ให้มันเดินไปซ้ายตามปกติ
            }
        }
        if(choice == 'd' or choice == 'D'){
            if (dir != LEFT ) {//เหมือนกันแค่เดินขวา
                if (isReversed && dir != RIGHT) dir = LEFT;
                else dir = RIGHT;
            }
        }
        if(choice == 'w' or choice == 'W'){
            if (dir != DOWN) {//เหมือนกันแค่เดินขึ้น
            if (isReversed && dir != UP) dir = DOWN;
                else dir = UP;
            }
        }
            if(choice == 's' or choice == 'S'){
            if (dir != UP){ //เหมือนกันแค่เดินลง
                if (isReversed && dir != DOWN) dir = UP;
                else dir = DOWN;
                }
            }
        if(choice == 'x' or choice == 'X'){//ปุ่มออกเกม กดxปุ๊บเกมจบเลย
            gameOver = true;
        }
    }
}