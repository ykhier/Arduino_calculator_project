#include <Keypad.h> 
#include <LiquidCrystal.h>
#define Row 4
#define Col 4
#define WhiteLed 10
#define YellowLed 9
#define RRBGLed 11
#define GRBGLed 13
#define BRBGLed 12


LiquidCrystal lcd(8, A1, A2, A3, A4, A5);


char mat[Row][Col] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','C'},
  {'*','0','=','/'}
};

char numberchar;// התו הנקלט
int fnumber=0;// מספר הראשון 
int secNumber=0;// מספר השני 
int number;// משתנה בפונקציה
float res;// התוצאה
int flag;//מתחיל לעבוד RGBled אם המשתמש לחץ על שווה אז המשתנה הופך לאפס ו
int cnt=0;// המשתנה הזה לתוצאה אם המשתמש רוצה להוסיף עוד פעולת חישבון על התוצאה 
int rev; // resrve
int cntclear=0;//enter number המשתנה הזה למחיקת ההדפסה  
int flag1=1;// המשתנה הזה להדפסה כשמפעילים את המסך

byte rowPin[Row] = {7,6,5,4}; // keypad חיבור השורות ל 
byte colPin[Col] = {3,2,1,0}; // keypad חיבור העומודות ל 

Keypad readchar1 = Keypad( makeKeymap(mat), rowPin, colPin, Row, Col);  
//lcd ל keypad משתמשים בזה כקלט תו מה 
void setup(){

	lcd.begin(16,2);// lcd אתחול
	//Serial.begin(9600);
    pinMode(WhiteLed, OUTPUT);
    pinMode(YellowLed, OUTPUT);
  	pinMode(RRBGLed, OUTPUT);
  	pinMode(GRBGLed, OUTPUT);
  	pinMode(BRBGLed, OUTPUT);
  
}
int func(){ 
  number=0;
  flag=1;
  for(;;){// לולאה אין סופית 
   numberchar = readchar1.getKey();
  if((numberchar>='0')&&(numberchar<='9')){
  if((numberchar - '0')%2==0){//אם הספרה אי זוגית מדליק את הלד הלבן
     digitalWrite(WhiteLed, HIGH);
     delay(150);
     digitalWrite(WhiteLed, LOW);
  	}else{// אחרת מדליק את הלד הצהוב
     digitalWrite(YellowLed, HIGH);
     delay(150);
     digitalWrite(YellowLed, LOW);
}
  number = number*10 + ((numberchar - '0'));
  lcd.print(numberchar);
  }
    else if(numberchar == '='){
      flag=0;
      digitalWrite(YellowLed, HIGH);
      digitalWrite(WhiteLed, HIGH);
      delay(150);
      digitalWrite(YellowLed, LOW);
      digitalWrite(WhiteLed, LOW);  
  	break;
  }
}
  return number;
}
void loop(){

  flag=1;
  int value = analogRead(A0);// מקבל מספר כלשהו
  /*Serial.println(value);*/
  if(value>1000){
    if(flag1==0){
    flag1=1;
    lcd.print("calculator");
    lcd.setCursor(0,1);
    lcd.print("by yosef & sami");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    cntclear++;
    lcd.print("Enter number");
    }
  numberchar = readchar1.getKey();// keypad קליטת תו מה 
 
  if(numberchar == '+' || numberchar == '-'|| numberchar == '*'|| numberchar == '/'|| numberchar == 'C'){	
      digitalWrite(YellowLed, HIGH);
      delay(100);
      digitalWrite(YellowLed, LOW);
      digitalWrite(WhiteLed, HIGH);
      delay(100);
      digitalWrite(WhiteLed, LOW);    
  }

  switch(numberchar){
  	//0-9
    case '0' ... '9':
    if(cntclear!=0){//C אם המשתמש לחץ על התו  
    lcd.clear();
    cntclear=0;
    lcd.setCursor(0,0);
    }
    if((numberchar - '0')%2==0){//אם הספרה אי זוגית מדליק את הלד הלבן
     digitalWrite(WhiteLed, HIGH);
     delay(100);
     digitalWrite(WhiteLed, LOW);
    }else{// אחרת מדליק את הלד הצהוב
     digitalWrite(YellowLed, HIGH);
     delay(100);
     digitalWrite(YellowLed, LOW);
    }
    
    lcd.setCursor(0,0);//  (0,0) מצביע על המקום 
    fnumber = fnumber * 10 + (numberchar - '0');
    lcd.print(fnumber);
    break;
    
  case '+':// פלוס
    if(cntclear!=0){//C אם המשתמש לחץ על התו  
    lcd.clear();
    cntclear=0;
    lcd.setCursor(0,0);
    }
    if(cnt==0){
    lcd.print("+");
    secNumber = func();
    res = (float)fnumber + secNumber; 
    lcd.setCursor(0,1);
    lcd.print(res);
    cnt++;
    }else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print((int)res);
    lcd.print("+");
    secNumber = func();
    res = (float)res+secNumber;
    lcd.setCursor(0,1);
    lcd.print(res);
    }
    break;
  
   case '-':// מינוס
    if(cntclear!=0){//C אם המשתמש לחץ על התו  
    lcd.clear();
    cntclear=0;
    lcd.setCursor(0,0);
    }
    if(cnt==0){
    lcd.print("-");
    secNumber = func();
    res = (float)fnumber - secNumber; 
    lcd.setCursor(0,1);
    lcd.print(res);
    cnt++;
    }else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print((int)res);
    lcd.print("-");
    secNumber = func();
    res = (float)res - secNumber;
    lcd.setCursor(0,1);
    lcd.print(res);
    }
    break;
    case '*':// כפל
    if(cntclear!=0){//C אם המשתמש לחץ על התו  
    lcd.clear();
    cntclear=0;
    lcd.setCursor(0,0);
    }
    if(cnt==0){
    lcd.print("*");
    secNumber = func();
    res = (float)fnumber * secNumber; 
    lcd.setCursor(0,1);
    lcd.print(res);
    cnt++;
    }else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print((int)res);
    lcd.print("*");
    secNumber = func();
    res = (float)res*secNumber;
    lcd.setCursor(0,1);
    lcd.print(res);
    }
    break;
    case '/': // חלקי
    if(cntclear!=0){//C אם המשתמש לחץ על התו  
    lcd.clear();
    cntclear=0;
    lcd.setCursor(0,0);
    }
    
    if(cnt==0){// אם המשתמש עושה חישוב של הפעם הראשונה
      
    lcd.print("/");
    secNumber = func();
    res = (float)fnumber / secNumber;
    cnt++;
    }else{//אם המשתמש רוצה לחשב עוד 
    lcd.clear();//מחיקה
    lcd.setCursor(0,0);
    lcd.print(res);
    lcd.print("/");
    secNumber = func();
    res = (float)res/secNumber;
    }
    if(secNumber==0){//אם המספר השני שווה ל אפס מדפיס יש שגיאה
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Please try again");
    lcd.setCursor(0,1);
    lcd.print("ERROR");
    }else{ 
  	lcd.setCursor(0,1);
    lcd.print(res);
    }
    break;
    case 'C':// C
    lcd.clear(); // מחיקה 
    cntclear++;
    lcd.print("Enter number");
    res=0;
    flag=1;
    fnumber=0;
    secNumber=0;
    cnt=0;
  } 
  if(flag==0){//אם המשתמש לחץ על שווה 
    if(res==0){// אם התוצאה שווה לאפס 
  digitalWrite(RRBGLed, HIGH);
  delay(150);
  digitalWrite(RRBGLed, LOW);  
  digitalWrite(GRBGLed, HIGH);
  delay(150);
  digitalWrite(GRBGLed, LOW);  
  digitalWrite(BRBGLed, HIGH);
  delay(150);
  digitalWrite(BRBGLed, LOW);
  }else if(res < 0){// אם התוצאה שלילית 
  for(int i=0;i<3;i++){
  digitalWrite(RRBGLed, HIGH);
  delay(100);
  digitalWrite(RRBGLed, LOW);
  delay(100);  
  }
  }else{//אחרת
    rev = res;
  if(rev>0){// אם התוצאה גדול מאפס
   while(rev!=0){
    if(rev%10==5){ // אם יש במספר ספרה 5 התנאי מתקיים
  digitalWrite(BRBGLed, HIGH);
  delay(100);
  digitalWrite(BRBGLed, LOW);
  delay(100);
  	}
      rev/=10;
   }  
  }
  }
  }
  }else{
  res=0;
  flag=1;
  fnumber=0;
  secNumber=0;
  cnt=0;
  flag1=0;
  lcd.clear();
  }
}