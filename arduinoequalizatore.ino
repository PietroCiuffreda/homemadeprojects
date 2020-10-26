#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 7, 6, 3, 2);
float vuMeters[16]; //le barre del display (16)
int valanalog=0;  //pin analogico Arduino (A0)
int strobe=4; //controllo circuito integrato
int reset=5;
int valorifreq[7];  //le 7 frequenze dell'integrato
byte vuMeter[8][8]; //matrice 8x8


void setup()
{
  for (int j=0; j<=7; j++) //inizializzazione matrice 8x8
  {
    for (int i=0; i<=7; i++)
    {
    if (i<=j)
    {
      vuMeter[j][7-i] = 14;
    }
    else
    { 
      vuMeter[j][7-i]=0;}
    }
    }
   for (int i=0; i<=7; i++)
   {
   lcd.createChar(i, vuMeter[i]); //viene creato un glyph per l'uso sul diplay LCD (c'è bisogno di un array di 8 byte per ogni glyph; i->carattere che verrà creato da 0 a 7, vuMeter->i dati del pixel da caricare 
   } 
lcd.begin(16,2); //altezza e larghezza del display
for (int i=0;i<=7;i++)
{
  lcd.setCursor(i,0); //cursore della matrice su una riga tra 0 e 7 e sulla 0esima colonna
  lcd.write(i);  //restituisce il valore dei byte scritti
  lcd.setCursor(i,1);
  lcd.write(7);
  pinMode(valanalog, INPUT);
  pinMode(strobe, OUTPUT);
  pinMode(reset, OUTPUT);
  analogReference(DEFAULT); //pin A0 a 5V
  digitalWrite(reset, LOW); //reset a massa
  digitalWrite(strobe, HIGH); //alimentazione di strobe
  }
}

void loop()
{
  digitalWrite(reset, HIGH);
  digitalWrite(reset, LOW);
  for (int i=0; i<7; i++)
  {
    digitalWrite(strobe, LOW);
    delayMicroseconds(5);
    valorifreq[i]=analogRead(valanalog); //metto nell'array i valori letti da valanalog
    digitalWrite(strobe, HIGH);
  }
  for (int i=0;i<=15;i++)
  {
    switch (i)
    {
      case 0:
      vuMeters[i]=valorifreq[0]/64;
      break;
      case 1:
      vuMeters[i]=(valorifreq[0]/64+valorifreq[1]/64)/2;
      break;
      case 2:
      vuMeters[i]=valorifreq[1]/64;
      break;      
      case 3:
      vuMeters[i]=(valorifreq[1]/64+valorifreq[2]/64)/2;
      break;
      case 4:
      vuMeters[i]=valorifreq[2]/64;
      break;
      case 5:
      vuMeters[i]=(valorifreq[1]/64+valorifreq[2]/64+valorifreq[3]/64)/3;
      break;
      case 6:
      vuMeters[i]=(valorifreq[2]/64+valorifreq[3]/64+valorifreq[4]/64)/3;
      break;
      case 7:
      vuMeters[i]=random(2)+valorifreq[3]/64;
      break;
      case 8:
      vuMeters[i]=random(2)+valorifreq[3]/64;
      break;
      case 9:
      vuMeters[i]=(valorifreq[2]/64+valorifreq[3]/64+valorifreq[4]/64)/3;
      break;
      case 10:
      vuMeters[i]=(valorifreq[3]/64+valorifreq[4]/64+valorifreq[5]/64)/3;
      break;
      case 11:
      vuMeters[i]=valorifreq[4]/64;
      break;
      case 12:
      vuMeters[i]=(valorifreq[4]/64+valorifreq[5]/64)/2;
      break;
      case 13:
      vuMeters[i]=valorifreq[5]/64;
      break;
      case 14:
      vuMeters[i]=(valorifreq[5]/64+valorifreq[6]/64)/2;
      break;
      case 15:
      vuMeters[i]=valorifreq[6]/64;
      break;    
  }

  if (i>7)
  {
    lcd.setCursor(vuMeters[i],i);
    lcd.write(7);   
    lcd.setCursor(vuMeters[i],0); 
    lcd.write(i-8); //scrive il carattere dell'altezza meno otto
  }
  else
  {
    lcd.setCursor(vuMeters[i],1);
    lcd.write(i); //scrive l'altezza se è minore di 7
    lcd.setCursor(vuMeters[i],0);
    lcd.write(32);  //unico caso non contemplato
  }
  delay(1);

  }
}
