void Setup() { //ฟังก์ชั่นนี้มีไว้เซ็ตค่าของตัวแปรต่างๆว่าตอนเริ่มจะให้ค่าอะไรเป็นยังไง
    gameOver = false; //อันนี้กะให้เป็นfalseไว้เกมจะได้ยังไม่over
    dir = STOP; //อันนี้คือให้ทิศทางเป็นstopจนกว่าผู้เล่นจะกดwsad
    x = width / 2; //x y คือตำแหน่งของงูในเฟรมนั้นๆ ตอนแรกเราจะให้มันเริ่มที่กลางจอเลยเอากว้างกะยาวมาหาร2
    y = height / 2;//^^
    score = 0;//อันนี้เอาไว้เก็บแต้มของคนเล่น
    fruitEat = true;//อันนี้เพราะเราอยากให้มันสุ่มขึ้นมา2ผลเลยก็เลยเซ็ทเป็นtrue
    fruitX = 21;//ตั้งแต่บรรทัดนี้(32)จนถึงบรรทัดที่43 เราจะเซ็ทค่าของผลไม้ต่างๆให้เป็น21ไว้ก่อน ส่วนของที่วาดผลไม้จะรันถึงแค่20เลยทำให้ผลไม้ทุกผลยังไม่ถูกวาด
    fruitY = 21;//       ^
    poisonFruitX =21;//  ^
    poisonFruitY =21;//  ^
    MinusFruitX = 21;//  ^
    MinusFruitY = 21;//  ^
    boostFruitX = 21;//  ^
    boostFruitY = 21;//  ^
    fatFruitX =21 ;//    ^
    fatFruitY = 21;//    ^
    reverseFruitX =21;// ^
    reverseFruitY =21;// ^
    nTail =0;//อันนี้คือเราจะเซ็ทnTailกลับเป็น0ทุกคั้งที่restart
}