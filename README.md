# C-Programmeren Practica
Deze repository bevat mijn uitwerkingen van de programmeeropdrachten voor het vak C‑programmeren.

## Inhoud
Elke week stond een ander onderdeel van de C‑taal centraal. Onderstaand overzicht beschrijft per week welke onderwerpen zijn behandeld en de daarbij horende opdrachten.
Daarnaast wordt er een instructie gegeven over hoe deze repository gebruikt dient te worden.


## Weekoverzicht
### Week 1 — Basis van C
In deze week lag de focus op het kennismaken met de fundamenten van de C‑taal. De basis‑syntax en de eigenschappen van arrays kwamen aan bod. Daarnaast werd geoefend met het verwerken van gebruikersinvoer.

**Opdrachten:**
1. Belastingschijven 
2. Hoger-lager spelletje
3. Berekening van het beoordelen van een module
4. Bowlingscore berekening

### Week 2 — Strings
Deze week stond in het teken van strings in C, oftewel arrays van char. Ook werden de standaardfuncties uit de <string.h>‑bibliotheek geïntroduceerd. Voor het eerst werd een .txt‑bestand ingelezen en verwerkt.

**Opdrachten:**
1. Eigen kopieer string functie
2. Eigen kopieer string functie met controle
3. Key-value onderscheiden in een string
4. Wedstrijduitslagen 

### Week 3 — Pointers
Het thema van deze week was dynamisch geheugenbeheer met malloc, inclusief het correct vrijgeven van geheugen. Verder werden struct‑constructies en typedefs behandeld. Tot slot werd dieper ingegaan op het gebruik van pointers.

**Opdrachten:**
1. Doubles printen
2. Grootste getal
3. Schoolvak aanpassen
4. Team samenstellen

### Week 4 — Sockets
In week 4 werd geoefend met het opzetten van sockets. Hierbij werd gekeken naar hoe een socket wordt aangemaakt en hoe data tussen twee sockets kan worden uitgewisseld.

### Week 5 — 2D-array's
Deze week draaide om het gebruik van tweedimensionale arrays, toegepast in een opdracht waarin een sudoku moest worden verwerkt.

### Week 6 — Soorten lijsten
In deze week kwamen verschillende soorten arrays aan bod en werd besproken welk type het meest geschikt is in specifieke situaties. Daarnaast werd het concept van een gekoppelde lijst (linked list) geïntroduceerd.

**Opdrachten:**
1. Schoolvakken aanpassen
2. Sorteren van een linked list

### Week 7 — Functiepointers
In de laatste week werden functiepointers behandeld. Hierbij werd ook de werking van de standaardfunctie qsort besproken.

**Opdrachten:**
1. Studieresultaten sorteren
2. Van spanning of Fahrenheit naar Celsius


## Gebruik
Download het project lokaal door het te clonen via Git. 
Open de terminal en voer het volgende commando uit:

```
git clone https://github.com/isabelHaagse/C-Programmeren-Opdrachten.git
```

Nu staat de repository lokaal op de pc.
Open vervolgens de map in Visual Studio.

Stel daarna de week in die gerund moet worden door met de rechtermuisknop op de solution te klikken. Kies Configure Startup Projects, zet de Action bij de gewenste week op Start en zet de rest van de projecten op None.
Uncomment in runfile.c de functie die uitgevoerd moet worden en comment de overige functies uit.

Klik nu op Debug of Run. Let hierbij op dat sommige functies beter werken in x64 of x86.