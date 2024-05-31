# Išankstinė egzamino užduotis

## Aprašymas

Programa, nuskaitanti į input.txt failą įvestą tekstą ir skaičiuojanti, kiek kartų ir kuriose eilutėse pasikartojo visi žodžiai. Į failą counter.txt išvedami tik tie žodžiai ir jų kiekiai, kurie pasikartojo daugiau nei 1 kartą, o į failą cross-reference.txt išvedami visi tie patys žodžiai bei visos eilutės, kuriose tie žodžiai yra. Taip pat programa tekste ieško visų tipų URL nuorodų, kurias vėliau išveda į atskirą failą url.txt.

## Naudojimosi instrukcija

1. Į failą input.txt įkelkite visą tekstą, kurį norite analizuoti.
2. Paleiskite programą.
3. Failuose counter.txt, cross-reference.txt ir url.txt galite apžvelgti visus programos rezultatus.

## Programos diegimo ir paleidimo instrukcija

1. Privaloma turėti įsidiegus "MinGW" kompiliatorių ir "Make" - automatizavimo įrankį, kuris kuria vykdomąsias programas (Šis įrankis dažniausiai būna automatiškai instaliuotas Linux ir MacOS sistemose). Atsisiųsti MinGW galite čia: [MinGW](https://sourceforge.net/projects/mingw/) Pamoka, kaip atsisiųsti "Make" Windows naudotojams: [Make](https://www.youtube.com/watch?v=j5gJJe_0zP4&t=171s)
2. Atsisiųskite programos šaltinio kodą iš mūsų repozitorijos.
3. Atsidarę terminalą, naviguokite į atsisiųstos programos aplanką.
5. Įvykdykite komandą: make
6. Tuomet terminale įrašykite ./main, kad paleistumėte norimą programą Linux sistemoje arba main.exe Windows sistemoje.
