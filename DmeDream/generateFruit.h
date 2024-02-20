void generateFruit(){ //ฟังก์ชั่นนี้เป็นฟังก์ชั่นสำหรับกำหนดผลไม้ลูกที่1ขึ้นมา
    if(fruitEat){ //ถ้าเกิดว่างูกินผลไม้ไม่ว่าจะผลอะไร fruitEat = true แล้วก็จะเข้าเงื่อนไขนี้
    int gf = rand()%100+1;//สุ่มค่าขึ้นมาค่านึงตั้งแต่1->100
    if(gf <= 30){ //ถ้าค่าที่สุ่มมาน้อยกว่าหรือเท่ากับ30(30%)
    fruitX = rand() % width;//เซ็ตให้ตำแหน่งของผลไม้ปกติrandomเกิดตามแกน x y
    fruitY = rand() % height;//^
    fruit1 = "fruit";//กำหนดให้ตัวแปรfruit1เป็นผลไม้ธรรมดา
    }
    if(gf <= 50 && gf >30){//เหมือนกันเลยแต่เป็นของผลไม้speed (20%)
    boostFruitX = rand() % width;
    boostFruitY = rand() % height;
    fruit1 = "boost";
    }
    if(gf <=65 && gf > 50){//เหมือนกันเลยแต่เป็นของผลไม้พิส(15%)
    poisonFruitX = rand() % width;
    poisonFruitY = rand() % height;
    fruit1 = "poison";
    }
    if (gf <=80 && gf > 65)//เหมือนกันเลยแต่เป็นของผลไม้อ้วน(15%)
    {
    fatFruitX = rand() % width;
    fatFruitY = rand() % height;
    fruit1 = "fat";
    }
    if (gf <= 90 && gf > 80)//เหมือนกันเลยแต่เป็นของผลไม้มึน(10%)
    {
    reverseFruitX = rand() % width;
    reverseFruitY = rand() % height;
    fruit1 = "reverse";
    }
    if (gf <= 100 && gf > 90)//เหมือนกันเลยแต่เป็นของผลไม้ลบ(10%)
    {
    MinusFruitX = rand() % width;
    MinusFruitY = rand() % height;
    fruit1 = "Minus";
    }
    }
}

void generateFruit2(){//หลังจากกำหนดผลไม้1ขึ้นมาแล้วก็จะมาที่ฟังก์ชั่นนี้เพื่อกำหนดผลไม้2 (ทำงานเหมือนกันเลยแค่มีการเช็คว่าผลไม้ซ้ำรึเปล่า)
    if(fruitEat){//หลังจากสร้างผลไม้1 ในฟังก์ชั่นของผลไม้1ยังไม่ได้เปลี่ยน fruitEat ให้เป็นfalse เพราะงั้นก็จะรันตรงนี้ต่อได้เลย
    int gf = rand()%100+1;//สุ่มค่าขึ้นมาค่านึงเหมือนเดิม
    if(gf <= 30 && fruit1 != "fruit"){//ถ้าgfน้อยกว่าเท่ากับ30 เช็คว่าผลไม้1ใช่ผลปกติมั้ยถ้าไม่ใช่สร้างผลปกติ
    fruitX = rand() % width;
    fruitY = rand() % height;
    }
    else if (gf <= 30 && fruit1 == "fruit")//ถ้าผลไม้1เป็นผลปกติ
    generateFruit2();//สุ่มผล2ใหม่
    

    if(gf <= 50 && gf >30 && fruit1 != "boost"){//เหมือนกันเลยแต่เป็นของผลไม้speed
    boostFruitX = rand() % width;
    boostFruitY = rand() % height;
    }
    else if (gf <= 50 && gf >30 && fruit1 == "boost")
    generateFruit2();
    

    if(gf <=65 && gf > 50 && fruit1 != "poison"){//เหมือนกันเลยแต่เป็นของผลไม้พิษ
    poisonFruitX = rand() % width;
    poisonFruitY = rand() % height;
    }
    else if (gf <=65 && gf > 50 && fruit1 == "poison")
    generateFruit2();
    

    if (gf <=80 && gf > 65 && fruit1 != "fat")//เหมือนกันเลยแต่เป็นของผลไม้อ้วน
    {
    fatFruitX = rand() % width;
    fatFruitY = rand() % height;
    }
    else if (gf <=80 && gf > 65 && fruit1 == "fat") generateFruit2();

    if (gf <= 90 && gf > 80 && fruit1 != "reverse")//เหมือนกันเลยแต่เป็นของผลไม้มึน
    {
    reverseFruitX = rand() % width;
    reverseFruitY = rand() % height;
    }
    else if (gf <= 90 && gf > 80 && fruit1 == "reverse") generateFruit2();

    if (gf <= 100 && gf > 90 && fruit1 != "Minus")//เหมือนกันเลยแต่เป็นของผลไม้ลบ
    {
    MinusFruitX = rand() % width;
    MinusFruitY = rand() % height;
    }
    else if(gf <= 100 && gf > 90 && fruit1 == "Minus") generateFruit2();

    fruitEat = false ;//ถ้าสุ่มผลที่2เสร็จเปลี่ยนfruitEat เป็น false
    }  

}