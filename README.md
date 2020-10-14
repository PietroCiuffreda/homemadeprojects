# homemadeprojects
Repository per i miei progetti realizzati principalmente con Arduino Uno (e non solo).
Al momento sono attivi tre semplici progetti:

1. Equalizzatore grafico tramite schermo LCD
2. Ripetitore infrarossi per telecomando
3. Regolazione e visualizzazione di un VUmeter tramite led *(in fase di test)

**Equalizzatore grafico**

Obbiettivo: realizzare un equalizzatore con Arduino UNO attraverso che possa raffigurare le frequenze di un qualsiasi input in ingresso audio (che sia una musica o voce) e visualizzando il tutto attraverso un display LCD 16x2. Chiaramente il progetto è solo a scopo illustrativo, non vuole andare a regolare le frequenze da equalizzare ma semplicemente visualizzarle per dare un'informazione quantitativa.

Materiali utilizzati : 

   - 2 Condensatori da 100 nF
   - 1 Condensatore da 10 nF
   - 1 Condensatore da 33 pF
   - 1 Audio Jack (3.5 mm)
   - 1 Trimmer (10 K)
   - 1 cavo jack - jack
   - Display LCD 16x2
   - 1 resistore da 200 KΩ
   - Integrato MSGEQ7
   - Arduino UNO
   - Breadboard
   
N.B. nella repository vegono inseriti per comodità di consultazione, oltre al codice sorgente, anche il datasheet dell'integrato MSGEQ7 (file https://github.com/PietroCiuffreda/homemadeprojects/blob/master/MSGEQ7.pdf), lo schema circuitale dello stesso (https://github.com/PietroCiuffreda/homemadeprojects/blob/master/schema%20MSGEQ7.png) e infine lo schema del display LCD con una legenda in modo da interpretare come ho collegato i vari pin all'Arduino. Qui https://github.com/PietroCiuffreda/homemadeprojects/blob/master/Equalizzatore%20Fritzing.png invece ho lasciato lo schema realizzato su Fritzing e qui una foto della realizzazione https://github.com/PietroCiuffreda/homemadeprojects/blob/master/photo_equalizzatore.jpg


**Ripetitore infrarossi per telecomando**

Obbiettivo: realizzare un ripetitore ad infrarossi per telecomando della televisione a casa di mia nonna. Dal momento che il decoder del digitale terrestre che si trova a casa di mia nonna si trova in una posizione non comodissima e quindi si è costretti ogni volta ad alzarsi dal letto per cambiare canale o aumentare/diminuire il volume della televisione ho pensato di realizzare con alcune cose che avevo già in casa un prototipo di ripetitore infrarossi.

Materiali utilizzati:

   - 1 batteria da 9 V
   - 1 potenziometro da 100 KΩ
   - 1 led verde
   - 3 diodi IR
   - 1 fototransistor ricevente IR
   - 1 transistor npn (PN2222)

N.B. il ripetitore può essere utilizzato anche su una basetta millefori per eventualmente essere saldato. Nella repository ho inserito il datasheet del PN2222 (file https://github.com/PietroCiuffreda/homemadeprojects/blob/master/PN2222-D.PDF), lo schema circuitale utilizzato (file https://github.com/PietroCiuffreda/homemadeprojects/blob/master/schema%20circuitale%20rip%20infrarosso.jpg) e la realizzazione dello stesso (file https://github.com/PietroCiuffreda/homemadeprojects/blob/master/ripinfraross.jpg).

**Regolazione e visualizzazione di un VUmeter tramite led**



*update 5/10/2020

N.B. sto avendo problemi con il microfono, probabilmente quello che sto utilizzando non è correttamente amplificato oppure c'è qualcosa che non fa bene contatto perché tutti i led rimangono sempre spenti.




## Authors

* **Pietro Ciuffreda** - [PietroCiuffreda](https://github.com/PietroCiuffreda)


## License

This project is licensed under the CC License - see the [LICENSE](LICENSE) file for details
