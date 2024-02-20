void Logic() {//(ฟังก์ชั่นเชี่ยย วุ่นวายชิบ555)ฟังก์ชั่นนี้คือฟังชั่นที่ใช้รันเกมทั้งหมด
    int prevX = tailX[0];//ส่วนของตรงนี้ถึงบรรทัดที่267เป็นการส่งค่าตำแหน่งของหัวให้หางอันที่1ในเฟรมต่อไป แล้วหางอันที่1ก็จะส่งตำแหน่งให้หางอันที่2 ต่อไปอีก อธิบายยาก ไว้ก่อนละกันน5555
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir) {//ที่เราบอกว่าพอรับwsadมาแล้วให้มันเดินซ้ายขวา จริงมันจะมาเดินเอาตรงนี้นี่แหละ
    case LEFT://ในเคสที่ไดเรคชั่นเป็น LEFT ก็ให้ตำแหน่งในแกนxของหัวงูขยับไปทางซ้ายเรื่อยๆ
        x--;
        break;
    case RIGHT:
        x++;//ไอ้นี่ก็ขวาเรื่อยๆ
        break;
    case UP:
        y--;//ไอ้นี่ก็ขึ้นเรื่อยๆ
        break;
    case DOWN:
        y++;//ไอ้นี่ก็ลงเรื่อยๆ
        break;
    default:
        break;
    }

    if (x >= width) x = 0; else if (x < 0) x = width - 1;//สองบรรทัดนี้คือทำให้เวลางูมันหลุดขอบมันจะกลับมาจากอีกฝั่ง โดยการเซ็ทค่าตำแหน่งของ x ให้กลับมาเป็น 0 หรือwidth - 1
    if (y >= height) y = 0; else if (y < 0) y = height - 1;//^ y ให้กลับมาเป็น 0 หรือheight - 1

    for (int i = 0; i < nTail; i++)//ตรงนี้คือการเช็คว่าตำแหน่งของหางชนกะตำแหน่งของหัวรึเปล่า ถ้าชน เซ็ทgameOverเป็นtrue
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;

    if (x == fruitX && y == fruitY) {//ตรงนี้คือกรณีที่ตำแหน่งหัวทับกะตำแหน่งผลไม้ธรรมดา
        score += 10;//ได้scoreเพิ่ม
        nTail++;//จำนวนหางบวก1
        fruitEat = true;//เปลี่ยนfruitEat = trueให้มันไปเข้าเงื่อนไขของgeneratefruit
    }

    if (x == MinusFruitX && y == MinusFruitY){//ตรงนี้คือกรณีที่ตำแหน่งหัวทับกะตำแหน่งผลไม้ลบ
        score -= 10;//scoreลด10
        nTail--;//หางลดลง1
        fruitEat = true;//เปลี่ยนfruitEat = trueให้มันไปเข้าเงื่อนไขของgeneratefruit
        if(nTail == 0)gameOver = true;
    }
    

    if (x == boostFruitX && y == boostFruitY) {//ตรงนี้คือกรณีที่ตำแหน่งหัวทับกะตำแหน่งผลบูส จะทำให้งูเป็นงูspeed
        score += 20;//ได้scoreเพิ่ม
        isBoosted = true;//ตัวแปลที่บอกว่างูspeedอยู่เปล่ากลายเป็นtrue
        boostDuration = 20;//ระยะเฟรมที่อยากให้มันspeed
        fruitEat = true;//เปลี่ยนfruitEat = trueให้มันไปเข้าเงื่อนไขของgeneratefruit
    }

    if (x == poisonFruitX && y == poisonFruitY) {//ตรงนี้คือกรณีที่ตำแหน่งหัวทับกะตำแหน่งผลไม้ที่เขียนโค้ดง่ายที่สุดในโลก ผลพิษ กินละตาย
        gameOver = true;//แค่นี้ก็ตายละ
        //ไม่ต้องเปลี่ยนfruitEatเป็นtrueเพราะมันตายอยู่ละะ
    }

    if (x == fatFruitX && y == fatFruitY) {//ตรงนี้คือกรณีที่ตำแหน่งหัวทับกะตำแหน่งผลอ้วน ทำให้งูยาวขึ้น2ช่อง
        score += 15;//ได้scoreเพิ่ม
        nTail += 2; // จำนวนหาง+2
        fruitEat = true;//เปลี่ยนfruitEat = trueให้มันไปเข้าเงื่อนไขของgeneratefruit
    }

    if (x == reverseFruitX && y == reverseFruitY) {//ตรงนี้คือกรณีที่ตำแหน่งหัวทับกะตำแหน่งผลมึน  ทำให้งูเดินกลับด้าน
        score += 30;//ได้scoreเพิ่ม
        isReversed = true;//ตัวแปลที่บอกว่างูมึนอยู่เปล่ากลายเป็นtrue
        reverseDuration = 30;//ระยะเฟรมที่อยากให้มันมึน
        fruitEat = true;//เปลี่ยนfruitEat = trueให้มันไปเข้าเงื่อนไขของgeneratefruit
    }

    if (isBoosted) {//อันนี้คือการลดเฟรมที่เราเซ็ทเลงไปเรื่อยๆเพื่อสร้างระยะเวลาที่จะทำให้งูกลับมาเป็นปกติ ใน1เฟรมโค้ดรัน1ครั้ง ถ้างูspeedอยู่
        boostDuration--;//ลดค่าเฟรมที่อยากให้speedลง1
        if (boostDuration == 0) {//ถ้าเกิดเฟรมเหลือ0
            isBoosted = false;//งูไม่speedละ
        }
    }

    if (isReversed) {//ทำงานเหมือนกันกับงูspeedแต่เป็นของผลมึน
        reverseDuration--;
        if (reverseDuration == 0) {
            isReversed = false;
        }
    }
     if (fruitEat)//อันนี้คือในกรณีที่งูกินผลไม้ ให้ลบผลทุกผลออกไปก่อน ถ้าไม่มีตรงนี้มันก็จะมีโอกาศที่ผลเดิมจะยังไม่หายแต่สร้างผลใหม่มาแล้วว
    {
    fruitX = 21;
    fruitY = 21;
    poisonFruitX =21;
    poisonFruitY =21;
    MinusFruitX = 21;
    MinusFruitY = 21;
    boostFruitX = 21;
    boostFruitY = 21;
    fatFruitX =21 ;
    fatFruitY = 21;
    reverseFruitX =21;
    reverseFruitY =21;
    }
     
}