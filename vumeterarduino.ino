int v = 0; // variabile rilevata v che contiene il valore rilevato sulla porta 0 che è il segnale in uscita dal microfono
int i = 0; 
int t = 360;
/* ho stablito un valore di taratura (detto t) che varia ogni volta che si attiva il sistema e che viene ogni volta rilevato ed inserito nel sistema.
Le escursioni sono evidenziati su di una fila di 6 led che si illuminano in sequenza, in funzione della valore rilevato:
0 led = valore rilevato inferiore a t
1 led = valore rilevato compreso tra t e t+15
2 led = valore rilevato compreso tra t+11 e t +30 
3 led = valore rilevato compreso tra t+31 e t+45 
4 led = valore rilevato compreso tra t+46 e  t+60 
5 led = valore rilevato compreso tra t+61 e t+75 
6 led = valore rilevato superiore a t+75
*/
void setup()
{
 for (i = 7; i <= 12; i++) // porte di output
 pinMode(i, OUTPUT);
 Serial.begin(9600); //inizializzazione del monitor seriale
}
void loop()
{
 t = analogRead(A0); // rileva il valore (il volume) del suono
 Serial.println (t); // traccia di debug
 for (i = 7; i <= 12; i++)
 digitalWrite(i, LOW); // spegne tutti i led
 if (v >= t) 
 digitalWrite (12, HIGH); 
 if (v >= t + 16) 
 digitalWrite (11, HIGH); 
 if (v >= t + 31) 
 digitalWrite (10, HIGH); 
 if (v >= t + 46) 
 digitalWrite (9, HIGH);
 if (v >= t + 61) 
 digitalWrite (8, HIGH); 
 if (v >= t + 76) 
 digitalWrite (7, HIGH); 
}
