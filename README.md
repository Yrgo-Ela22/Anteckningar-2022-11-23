# Anteckningar 2022-11-23

Implementering av strukten adc samt drivrutiner för AD-omvandlaren på mikrodator ATmega328P.

Filen adc.h innehåller deklaration av strukten adc samt associerade funktioner (drivrutiner för AD-omvandlaren).
Filen adc.c innehåller motsvarande funktionsdefinitioner.

I filen main.c används drivrutinerna för att kontrollera ljusstyrkan på multipla lysdioder lagrade i en vektor.