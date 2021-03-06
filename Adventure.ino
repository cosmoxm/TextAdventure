/*
  Display.ino
  2013 Copyright (c) Seeed Technology Inc.  All right reserved.

  Author:Loovee
  2013-9-18

  Grove - Serial LCD RGB Backlight demo.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
const int pinButton = 8;
#include <Wire.h>
#include <avr/pgmspace.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
int box;
int sensorValue1;
int sensorValue2;
int Goldmuenzen;         // Die Waehrung (je mehr du hast desto besser)
int Defense;            // Deine Ruestung (Verteidigung)
int Attack;             // Dein Angriff/Schaden den du verursachst
int Health;             // Dein Leben (bei 0 bist du TOT)
int Glaube;            // Gott ist mit dir (oder auch nicht)
int Menge1;            // Sachen beim Haendler (begrenzt)
int Menge2;
int Menge3;
int Menge4;
int Menge5;
int Menge6;
int Menge7;
int Menge8;
int Menge9;
int Menge10;
int Menge11;
int Gegner1;           // ob der Gegner schon besiegt wurde
int Haendler1;         // ob der AnfangsHaendler aktiviert ist
int Gift;              // unnoetiges Zeug zum spaeteren Verkauf
int Ware;              // Dinge zum Verkaufen
int EnemyHealth;        // gegnerisches Leben
int EnemyDefense;       // gegnerische Ruestung
int EnemyAttack;        // gegnericher Schaden/Angriff
int EnemyGlaube;        // gegnerischer Segen Gottes
void setup() {
  pinMode(pinButton, INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Du bist ein Wand");
  lcd.setCursor(0, 1);
  lcd.print("erer im 11.Jhdt");
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Attack = 1;
  Defense = 0;
  Menge1 = 2;
  Menge2 = 1;
  Menge3 = 1;
  Menge4 = 1;
  Menge5 = 3;
  Menge6 = 2;
  Menge7 = 1;
  Menge8 = 1;
  Menge9 = 4;
  Menge10 = 1;
  Menge11 = 1;
  Gegner1 = 1;
  Haendler1 = 0;
  Health = 5;
  Gift = 0;
  Ware = 0;
  Goldmuenzen = 15;
  Glaube = 1;
  while (!digitalRead(pinButton)) {
    delay(100);
  }
  box = 0;
}

void loop()
{
  Serial.println(box, DEC);
  if ( box == 0 ) {
    Attack = 1;
    Defense = 0;
    Menge1 = 2;
    Menge2 = 1;
    Menge3 = 1;
    Menge4 = 1;
    Menge5 = 3;
    Menge6 = 2;
    Menge7 = 1;
    Menge8 = 1;
    Menge9 = 4;
    Menge10 = 1;
    Menge11 = 1;
    Gegner1 = 1;
    Haendler1 = 0;
    Health = 5;
    Gift = 0;
    Ware = 0;
    Goldmuenzen = 15;
    Glaube = 1;
    box = 1;
  }
  if ( box == 1 ) {
    lcd.clear();
    lcd.print(F("Du bist an einem"));
    lcd.setCursor(0, 1);
    lcd.print(F("Fluss im Wald"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 2;
  }
  if ( box == 2 ) {
    lcd.clear();
    lcd.print(F("Willst du am Flu"));
    lcd.setCursor(0, 1);
    lcd.print(F("ss entlang gehen"));
    sensorValue1 = analogRead(A0);
    sensorValue2 = analogRead(A1);
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    Serial.print(F("The X and Y coordinate is:"));
    Serial.print(sensorValue1, DEC);
    Serial.print(F(","));
    Serial.println(sensorValue2, DEC);
    Serial.println(F(" "));
    while (box == 2 ) {
      sensorValue1 = analogRead(A0);

      if ( sensorValue1 < 261 ) {
        box = 3;
      }
      else if ( sensorValue1 > 749 ) {
        box = 4;
      }
    }
  }
  if ( box == 3 ) {
    lcd.clear();
    lcd.print(F("Du bist an"));
    lcd.setCursor(0, 1);
    lcd.print(F("einer Bruecke"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 8;
  }
  if ( box == 4 ) {
    lcd.clear();
    lcd.print(F("Moechtest du in"));
    lcd.setCursor(0, 1);
    lcd.print(F("den Wald gehen"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while (box == 4 ) {
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 6;
      }
      else if ( sensorValue1 > 749 ) {
        box = 5 ;
      }
    }
  }
  if ( box == 6 ) {
    lcd.clear();
    lcd.print(F("Du gehst in"));
    lcd.setCursor(0, 1);
    lcd.print(F("den Wald"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 36;
  }
  if ( box == 5 ) {
    lcd.clear();
    lcd.print(F("Moechtest du"));
    lcd.setCursor(0, 1);
    lcd.print(F("dich ausruhen"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while (box == 5 ) {
      sensorValue1 = analogRead(A0);

      if ( sensorValue1 < 261 ) {
        box = 7;
      }
      else if ( sensorValue1 > 749 ) {
        box = 2;
      }
    }
  }
  if ( box == 7 ) {
    lcd.clear();
    lcd.print(F("Du setzt dich"));
    lcd.setCursor(0, 1);
    lcd.print(F("eine Weile hin"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    lcd.clear();
    lcd.print(F("Spaeter fuehlst du"));
    lcd.setCursor(0, 1);
    lcd.print(F("dich viel besser"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 2;
  }
  if ( box == 8 ) {
    lcd.clear();
    lcd.print(F("Willst du"));
    lcd.setCursor(0, 1);
    lcd.print(F("ruebergehen?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while (box == 8 ) {
      sensorValue1 = analogRead(A0);

      if ( sensorValue1 < 261 ) {
        box = 10;
      }
      else if ( sensorValue1 > 749 ) {
        box = 9;
      }
    }
  }
  if ( box == 9 ) {
    lcd.clear();
    lcd.print(F("Willst du am Fl"));
    lcd.setCursor(0, 1);
    lcd.print(F("uss entlangehen "));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while (box == 9 ) {
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 11;
      }
      else if ( sensorValue1 > 749 ) {
        box = 4;
      }
    }
  }
  if ( box == 10 ) {
    lcd.clear();
    lcd.print(F("Du betrittst de"));
    lcd.setCursor(0, 1);
    lcd.print(F("n Dunkel Wald"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 42;
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
  }
  if ( box == 11 ) {
    lcd.clear();
    lcd.print(F("Du kommst zu"));
    lcd.setCursor(0, 1);
    lcd.print(F("einem Wasserfall"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 12;
  }
  if ( box == 12 ) {
    lcd.clear();
    lcd.print(F("Du triffst auf"));
    lcd.setCursor(0, 1);
    lcd.print(F("einen Wanderer"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 13;
  }
  if ( box == 13 ) {
    lcd.clear();
    lcd.print(F("Du fragst"));
    lcd.setCursor(0, 1);
    lcd.print(F("ihn ob..."));

    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while (box == 13 ) {
      sensorValue1 = analogRead(A0);

      if ( sensorValue1 < 261 ) {
        box = 14;
      }
      else if ( sensorValue1 > 749 ) {
        box = 15;
      }
    }
  }
  if ( box == 14 ) {
    lcd.clear();
    lcd.print(F("er weis wo die n"));
    lcd.setCursor(0, 1);
    lcd.print(F("aechste Burg ist"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while (!digitalRead(pinButton) && box == 14) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 || sensorValue1 > 749 ) {
        box = 15;
      }
    }
    if ( box == 14 ) {
      box = 16;
    }
  }
  if ( box == 15 ) {
    lcd.clear();
    lcd.print(F("er weis was hint"));
    lcd.setCursor(0, 1);
    lcd.print(F("er dem Fluss ist"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while (!digitalRead(pinButton) && box == 15) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 || sensorValue1 > 749 ) {
        box = 14;
      }
    }
    if ( box == 15 ) {
      box = 18;
    }
  }
  if ( box == 16 ) {
    lcd.clear();
    lcd.print(F("Er zeigt dir"));
    lcd.setCursor(0, 1);
    lcd.print(F("den Weg"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 17;
  }
  if ( box == 18 ) {
    lcd.clear();
    lcd.print(F("Er zeigt dir"));
    lcd.setCursor(0, 1);
    lcd.print(F("den Weg"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 10;
  }
  if ( box == 17 ) {
    lcd.clear();
    lcd.print(F("Du kommst zu"));
    lcd.setCursor(0, 1);
    lcd.print(F("einer Burg"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 19;
  }
  if ( box == 19 ) {
    lcd.clear();
    lcd.print(F("Die Wachen lasse"));
    lcd.setCursor(0, 1);
    lcd.print(F("n dich passieren"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 20;
  }
  if ( box == 20 ) {
    lcd.clear();
    lcd.print(F("Du gehst"));
    lcd.setCursor(0, 1);
    lcd.print(F("hinein"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 21;
  }
  if ( box == 21 ) {
    lcd.clear();
    lcd.print(F("Du kommst zur"));
    lcd.setCursor(0, 1);
    lcd.print(F("Burg von"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 22;
  }
  if ( box == 22 ) {
    lcd.clear();
    lcd.print(F("Kaiser"));
    lcd.setCursor(0, 1);
    lcd.print(F("Friedrich"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 43;
  }
  if ( box == 23 ) {
    lcd.clear();
    lcd.print(F("Wohin willst"));
    lcd.setCursor(0, 1);
    lcd.print(F("du gehen?"));
    while ( box == 23 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 24;
      }
      if ( sensorValue1 > 749 ) {
        box = 27;
      }
    }
  }
  if ( box == 24 ) {
    lcd.clear();
    lcd.print(F("Norden"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 24 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 30;
      }
      if ( sensorValue1 > 749 ) {
        box = 27;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 25;
      }
    }
  }
  if ( box == 25 ) {
    lcd.clear();
    lcd.print(F("Du kommst zu"));
    lcd.setCursor(0, 1);
    lcd.print(F("einer Lichtung"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 26;
  }
  if ( box == 26 ) {
    lcd.clear();
    lcd.print(F("und siehst "));
    lcd.setCursor(0, 1);
    lcd.print(F("einen Haendler"));
    if ( Haendler1 == 0 ) {
      box = 33;
    }
    else if ( Haendler1 == 1 ) {
      box = 214;
    }
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
  }
  if ( box == 27 ) {
    lcd.clear();
    lcd.print(F("Sued-Ost"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 27 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 24;
      }
      if ( sensorValue1 > 749 ) {
        box = 30;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 28;
      }
    }
  }
  if ( box == 28 ) {
    lcd.clear();
    lcd.print(F("Du hast dich"));
    lcd.setCursor(0, 1);
    lcd.print(F("verlaufen und"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 29;
  }
  if ( box == 29 ) {
    lcd.clear();
    lcd.print(F("kommst zu"));
    lcd.setCursor(0, 1);
    lcd.print(F("einer Burg"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 19;
  }
  if ( box == 30 ) {
    lcd.clear();
    lcd.print(F("Westen"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 30 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 27;
      }
      if ( sensorValue1 > 749 ) {
        box = 24;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 31;
      }
    }
  }
  if ( box == 31 ) {
    lcd.clear();
    lcd.print(F("Du kommst zu"));
    lcd.setCursor(0, 1);
    lcd.print(F("einem Fluss"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 32;
  }
  if ( box == 32 ) {
    lcd.clear();
    lcd.print(F("mit einer"));
    lcd.setCursor(0, 1);
    lcd.print(F("Bruecke"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 8;
  }
  if ( box == 33 ) {
    lcd.clear();
    lcd.print(F("Er wird "));
    lcd.setCursor(0, 1);
    lcd.print(F("ueberfallen"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 34;
  }
  if ( box == 34 ) {
    if ( Haendler1 == 1 ) {
      lcd.clear();
      lcd.print(F("Moechtest du"));
      lcd.setCursor(0, 1);
      lcd.print(F("hingehen?"));
      while ( box == 34 ) {
        delay(100);
        sensorValue1 = analogRead(A0);
        if ( sensorValue1 < 261 ) {
          box = 214;
        }
        if ( sensorValue1 > 749 ) {
          box = 216;
        }
      }
    }
    else if ( Haendler1 == 0 ) {
      lcd.clear();
      lcd.print(F("Moechtest du"));
      lcd.setCursor(0, 1);
      lcd.print(F("ihm helfen"));
      while ( box == 34 ) {
        delay(100);
        sensorValue1 = analogRead(A0);
        if ( sensorValue1 < 261 ) {
          box = 35;
        }
        if ( sensorValue1 > 749 ) {
          box = 217;
        }
      }
    }
  }
  if ( box == 36 ) {
    if ( Haendler1 == 0 ) {
      lcd.clear();
      lcd.print(F("und hoerst Rufe"));
      lcd.setCursor(0, 1);
      lcd.print(F("aus Norden"));
    }
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 23;
  }
  if ( box == 35 ) {
    lcd.clear();
    lcd.print(F("Du hilfst ihm"));
    lcd.setCursor(0, 1);
    lcd.print(F("den Dieb"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 37;
    Haendler1 = 1;
  }
  if ( box == 37 ) {
    lcd.clear();
    lcd.print(F("zu ueberwael"));
    lcd.setCursor(0, 1);
    lcd.print(F("tigen und er"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 38;
  }
  if ( box == 38 ) {
    lcd.clear();
    lcd.print(F("schenkt dir ein"));
    lcd.setCursor(0, 1);
    lcd.print(F("paar Goldstuecke"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    Goldmuenzen += random(45, 76);
    Health -= 1;
    box = 39;
  }
  if ( box == 39 ) {
    lcd.clear();
    lcd.print(F("Auserdem zeigt"));
    lcd.setCursor(0, 1);
    lcd.print(F("er dir den"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 40;
  }
  if ( box == 40 ) {
    lcd.clear();
    lcd.print(F("Weg zur "));
    lcd.setCursor(0, 1);
    lcd.print(F("naechsten Burg"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 41;
  }
  if ( box == 41 ) {
    lcd.clear();
    lcd.print(F("Du gehst"));
    lcd.setCursor(0, 1);
    lcd.print(F("zur Burg"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 19;
  }
  if ( box == 43 ) {
    lcd.clear();
    lcd.print(F("Du gehst auf"));
    lcd.setCursor(0, 1);
    lcd.print(F("den Marktplatz"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 44;
  }
  if ( box == 44 ) {
    lcd.clear();
    lcd.print(F("Wohin moechtest"));
    lcd.setCursor(0, 1);
    lcd.print(F("du gehen?"));
    while ( box == 44 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 61;
      }
      if ( sensorValue1 > 749 ) {
        box = 45;
      }
    }
  }
  if ( box == 45 ) {
    lcd.clear();
    lcd.print(F("Zum Schmied"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 45 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 46;
      }
      if ( sensorValue1 > 749 ) {
        box = 62;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 48;
      }
    }
  }
  if ( box == 46 ) {
    lcd.clear();
    lcd.print(F("Zum"));
    lcd.setCursor(0, 1);
    lcd.print(F("Troedelladen"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 46 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 47;
      }
      if ( sensorValue1 > 749 ) {
        box = 45;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 49;
      }
    }
  }
  if ( box == 47 ) {
    lcd.clear();
    lcd.print(F("Zur Taverne"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 47 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 61;
      }
      if ( sensorValue1 > 749 ) {
        box = 46;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 50;
      }
    }
  }
  if ( box == 48 ) {
    lcd.clear();
    lcd.print(F("Du gehst zum"));
    lcd.setCursor(0, 1);
    lcd.print(F("Schmied"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 51;
  }
  if ( box == 49 ) {
    lcd.clear();
    lcd.print(F("Du gehst zum"));
    lcd.setCursor(0, 1);
    lcd.print(F("Troedelladen"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 63;
  }
  if ( box == 50 ) {
    lcd.clear();
    lcd.print(F("Du gehst zur"));
    lcd.setCursor(0, 1);
    lcd.print(F("Taverne"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 71;
  }
  if ( box == 51 ) {
    lcd.clear();
    lcd.print(F("Er fragt dich"));
    lcd.setCursor(0, 1);
    lcd.print(F("ob du etwas"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 52;
  }
  if ( box == 52 ) {
    lcd.clear();
    lcd.print(F("kaufen"));
    lcd.setCursor(0, 1);
    lcd.print(F("moechtest"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while (box == 52 ) {
      sensorValue1 = analogRead(A0);

      if ( sensorValue1 < 261 ) {
        box = 53;
      }
      else if ( sensorValue1 > 749 ) {
        box = 60 ;
      }
    }
  }
  if ( box == 53 ) {
    lcd.clear();
    lcd.print(F("Er bietet"));
    lcd.setCursor(0, 1);
    lcd.print(F("dir..."));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 53 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 55;
      }
      if ( sensorValue1 > 749 ) {
        box = 57;
      }
    }
  }
  if ( box == 55 ) {
    if ( Menge1 < 1 || Goldmuenzen < 15 ) {
      box = 56;
    }
    else if ( Menge1 > 0 ) {
      lcd.clear();
      lcd.print(F("Einen Dolch fuer"));
      lcd.setCursor(0, 1);
      lcd.print(F("15 Gold"));
      while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
        sensorValue1 = analogRead(A0);
      }
      while ( box == 55  ) {
        delay(100);
        sensorValue1 = analogRead(A0);
        if ( sensorValue1 < 261 ) {
          box = 56;
        }
        if ( sensorValue1 > 749 ) {
          box = 58;
        }
        if (digitalRead(pinButton)) {
          delay(100);
          box = 59;
          Goldmuenzen -= 15;
          Attack += 1;
          Menge1 -= 1;
        }
      }
    }
  }
  if ( box == 56 ) {
    if ( Menge2 < 1 || Goldmuenzen < 35 ) {
      box = 57;
    }
    else if ( Menge2 > 0 ) {
      lcd.clear();
      lcd.print(F("Eine Ruestung"));
      lcd.setCursor(0, 1);
      lcd.print(F("fuer 35 Gold"));
      while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
        sensorValue1 = analogRead(A0);
      }
      while ( box == 56  ) {
        delay(100);
        sensorValue1 = analogRead(A0);
        if ( sensorValue1 < 261 ) {
          box = 57;
        }
        if ( sensorValue1 > 749 ) {
          box = 55;
        }
        if (digitalRead(pinButton)) {
          delay(100);
          box = 59;
          Goldmuenzen -= 35;
          Defense += 2;
          Menge2 -= 1;
        }
      }
    }
  }
  if ( box == 57 ) {
    if ( Menge3 < 1 || Goldmuenzen < 40 ) {
      box = 58;
    }
    else if ( Menge3 > 0 ) {
      lcd.clear();
      lcd.print(F("Ein Schwert fuer"));
      lcd.setCursor(0, 1);
      lcd.print(F("40 Gold"));
      while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
        sensorValue1 = analogRead(A0);
      }
      while ( box == 57  ) {
        delay(100);
        sensorValue1 = analogRead(A0);
        if ( sensorValue1 < 261 ) {
          box = 58;
        }
        if ( sensorValue1 > 749 ) {
          box = 56;
        }
        if (digitalRead(pinButton)) {
          delay(100);
          box = 59;
          Goldmuenzen -= 40;
          Attack += 4;
          Menge3 -= 1;
        }
      }
    }
  }
  if ( box == 58 ) {
    lcd.clear();
    lcd.print(F("Doch nichts"));
    lcd.setCursor(0, 1);
    lcd.print(F("kaufen"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 58  ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 55;
      }
      if ( sensorValue1 > 749 ) {
        box = 57;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 60;
      }
    }
  }
  if ( box == 59 ) {
    lcd.clear();
    lcd.print(F("Moechtest du no"));
    lcd.setCursor(0, 1);
    lcd.print(F("ch etwas kaufen"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 59  ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 55;
      }
      if ( sensorValue1 > 749 ) {
        box = 60;
      }
    }
  }
  if ( box == 60 ) {
    lcd.clear();
    lcd.print(F("Du gehst zurueck"));
    lcd.setCursor(0, 1);
    lcd.print(F("zum Marktplatz"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 44;
  }
  if ( box == 61 ) {
    lcd.clear();
    lcd.print(F("In den Wald"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 61  ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 62;
      }
      if ( sensorValue1 > 749 ) {
        box = 47;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 125;
      }
    }
  }
  if ( box == 62 ) {
    lcd.clear();
    lcd.print(F("In den"));
    lcd.setCursor(0, 1);
    lcd.print(F("Dunkel Wald"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 62  ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 45;
      }
      if ( sensorValue1 > 749 ) {
        box = 61;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 10;
      }
    }
  }
  if ( box == 63 ) {
    lcd.clear();
    lcd.print(F("Der Verkaeufer"));
    lcd.setCursor(0, 1);
    lcd.print(F("fragt dich"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 64;
  }
  if ( box == 64 ) {
    lcd.clear();
    lcd.print(F("ob du etwas"));
    lcd.setCursor(0, 1);
    lcd.print(F("kaufen moechtest"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 64  ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 65;
      }
      if ( sensorValue1 > 749 ) {
        box = 60;
      }
    }
  }
  if ( box == 65 ) {
    lcd.clear();
    lcd.print(F("Er bietet"));
    lcd.setCursor(0, 1);
    lcd.print(F("dir..."));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 65  ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 68;
      }
      if ( sensorValue1 > 749 ) {
        box = 66;
      }
    }
  }
  if ( box == 66 ) {
    if ( Menge4 < 1 || Goldmuenzen < 30 ) {
      box = 67;
    }
    else if ( Menge1 > 0 ) {
      lcd.clear();
      lcd.print(F("Eine  Giftphiole"));
      lcd.setCursor(0, 1);
      lcd.print(F("fuer 30 Gold"));
      while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
        sensorValue1 = analogRead(A0);
      }
      while ( box == 66  ) {
        delay(100);
        sensorValue1 = analogRead(A0);
        if ( sensorValue1 < 261 ) {
          box = 67;
        }
        if ( sensorValue1 > 749 ) {
          box = 69;
        }
        if (digitalRead(pinButton)) {
          delay(100);
          box = 70;
          Goldmuenzen -= 30;
          Gift += 1;
          Menge4 -= 1;
        }
      }
    }
  }
  if ( box == 67 ) {
    if ( Menge5 < 1 || Goldmuenzen < 5 ) {
      box = 68;
    }
    else if ( Menge1 > 0 ) {
      lcd.clear();
      lcd.print(F("Einen Schnaps"));
      lcd.setCursor(0, 1);
      lcd.print(F("fuer 5 Gold"));
      while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
        sensorValue1 = analogRead(A0);
      }
      while ( box == 67  ) {
        delay(100);
        sensorValue1 = analogRead(A0);
        if ( sensorValue1 < 261 ) {
          box = 68;
        }
        if ( sensorValue1 > 749 ) {
          box = 66;
        }
        if (digitalRead(pinButton)) {
          delay(100);
          box = 70;
          Goldmuenzen -= 5;
          Ware += 1;
          Menge5 -= 1;
        }
      }
    }
  }
  if ( box == 68 ) {
    if ( Menge6 < 1 || Goldmuenzen < 15 ) {
      box = 69;
    }
    else if ( Menge1 > 0 ) {
      lcd.clear();
      lcd.print(F("Seltsame Pilze"));
      lcd.setCursor(0, 1);
      lcd.print(F("fuer 15 Gold"));
      while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
        sensorValue1 = analogRead(A0);
      }
      while ( box == 68  ) {
        delay(100);
        sensorValue1 = analogRead(A0);
        if ( sensorValue1 < 261 ) {
          box = 69;
        }
        if ( sensorValue1 > 749 ) {
          box = 66;
        }
        if (digitalRead(pinButton)) {
          delay(100);
          box = 70;
          Goldmuenzen -= 15;
          Ware += 2;
          Menge6 -= 1;
        }
      }
    }
  }
  if ( box == 69 ) {
    lcd.clear();
    lcd.print(F("Doch nichts"));
    lcd.setCursor(0, 1);
    lcd.print(F("kaufen"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 69  ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 66;
      }
      if ( sensorValue1 > 749 ) {
        box = 68;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 60;
      }
    }
  }
  if ( box == 70 ) {
    lcd.clear();
    lcd.print(F("Moechtest du no"));
    lcd.setCursor(0, 1);
    lcd.print(F("ch etwas kaufen"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 70  ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 66;
      }
      if ( sensorValue1 > 749 ) {
        box = 60;
      }
    }
  }
  if ( box == 71 ) {
    if ( Ware < 1 ) {
      box = 76;
    }
    else if ( Ware > 0 ) {
      lcd.clear();
      lcd.print(F("Eine verhuellte"));
      lcd.setCursor(0, 1);
      lcd.print(F("Person fragt"));
      while (digitalRead(pinButton)) {
        delay(100);
      }
      while (!digitalRead(pinButton)) {
        delay(100);
      }
      box = 72;
    }
  }
  if ( box == 72 ) {
    lcd.clear();
    lcd.print(F("dich ob du"));
    lcd.setCursor(0, 1);
    lcd.print(F("ihm etwas"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 73;
  }
  if ( box == 73 ) {
    lcd.clear();
    lcd.print(F("verkaufen"));
    lcd.setCursor(0, 1);
    lcd.print(F("kannst"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 74;
  }
  if ( box == 74 ) {
    lcd.clear();
    lcd.print(F("Willst du ihm"));
    lcd.setCursor(0, 1);
    lcd.print(F("etwas verkaufen?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 74  ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        Goldmuenzen += 10 * Ware;
        Ware = 0;
        box = 75;
      }
      if ( sensorValue1 > 749 ) {
        box = 76;
      }
    }
  }
  if ( box == 75 ) {
    lcd.clear();
    lcd.print(F("Du verkaufst"));
    lcd.setCursor(0, 1);
    lcd.print(F("ihm etwas"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 76;
  }
  if ( box == 76 ) {
    lcd.clear();
    lcd.print(F("Du gehst in"));
    lcd.setCursor(0, 1);
    lcd.print(F("die Taverne"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 77;
  }
  if ( box == 77 ) {
    lcd.clear();
    lcd.print(F("Er fragt dich"));
    lcd.setCursor(0, 1);
    lcd.print(F("ob du ein Bier"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 78;
  }
  if ( box == 78 ) {
    lcd.clear();
    lcd.print(F("haben und fuer"));
    lcd.setCursor(0, 1);
    lcd.print(F("20 Goldmuenzen"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 79;
  }
  if ( box == 79 ) {
    lcd.clear();
    lcd.print(F("uebernachten"));
    lcd.setCursor(0, 1);
    lcd.print(F("willst"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 79  ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        if ( Goldmuenzen < 20 ) {
          box = 80;
        }
        else if ( Goldmuenzen > 19 ) {
          box = 82;
          if ( Health < 6 ) {
            Health += 1;
          }
        }
      }
      if ( sensorValue1 > 749 ) {
        box = 60;
      }
    }
  }
  if ( box == 80 ) {
    lcd.clear();
    lcd.print(F("Du hast"));
    lcd.setCursor(0, 1);
    lcd.print(F("nicht genug"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 81;
  }
  if ( box == 81 ) {
    lcd.clear();
    lcd.print(F("Goldmuenzen"));
    lcd.setCursor(0, 1);
    lcd.print(F("und"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 60;
  }
  if ( box == 82 ) {
    lcd.clear();
    lcd.print(F("Du schlaefst"));
    lcd.setCursor(0, 1);
    lcd.print(F("dort und"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 60;
  }
  if ( box == 42 ) {
    lcd.clear();
    lcd.print(F("Es ist dunkel"));
    lcd.setCursor(0, 1);
    lcd.print(F("und unheimlich"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 83;
  }
  if ( box == 83 ) {
    lcd.clear();
    lcd.print(F("Du kommst zu"));
    lcd.setCursor(0, 1);
    lcd.print(F("einer Biegung"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 84;
  }
  if ( box == 84 ) {
    lcd.clear();
    lcd.print(F("Wohin willst"));
    lcd.setCursor(0, 1);
    lcd.print(F("du gehen?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 84 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 88;
      }
      if ( sensorValue1 > 749 ) {
        box = 85;
      }
    }
  }
  if ( box == 85 ) {
    lcd.clear();
    lcd.print(F("Nach rechts"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 85 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 86;
      }
      if ( sensorValue1 > 749 ) {
        box = 88;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 90;
      }
    }
  }
  if ( box == 86 ) {
    lcd.clear();
    lcd.print(F("Geradeaus"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 86 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 87;
      }
      if ( sensorValue1 > 749 ) {
        box = 85;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box =  119;
      }
    }
  }
  if ( box == 87 ) {
    lcd.clear();
    lcd.print(F("Nach links"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 87 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 88;
      }
      if ( sensorValue1 > 749 ) {
        box = 86;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 119;
      }
    }
  }
  if ( box == 88 ) {
    lcd.clear();
    lcd.print(F("Zurueck zur"));
    lcd.setCursor(0, 1);
    lcd.print(F("Bruecke"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 88 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 85;
      }
      if ( sensorValue1 > 749 ) {
        box = 87;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 89;
      }
    }
  }
  if ( box == 89 ) {
    lcd.clear();
    lcd.print(F("Du gehst zurueck"));
    lcd.setCursor(0, 1);
    lcd.print(F("zur Bruecke"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 9;
  }
  if ( box == 90 ) {
    lcd.clear();
    lcd.print(F("Du gehst nach"));
    lcd.setCursor(0, 1);
    lcd.print(F("rechts und"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 91;
  }
  if ( box == 91 ) {
    lcd.clear();
    lcd.print(F("hoerst ein"));
    lcd.setCursor(0, 1);
    lcd.print(F("Fiepen von links"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 92;
  }
  if ( box == 92 ) {
    lcd.clear();
    lcd.print(F("Wohin willst"));
    lcd.setCursor(0, 1);
    lcd.print(F("du gehen?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 92 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 93;
      }
      if ( sensorValue1 > 749 ) {
        box = 94;
      }
    }
  }
  if ( box == 93 ) {
    lcd.clear();
    lcd.print(F("Nach rechts"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 93 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 94;
      }
      if ( sensorValue1 > 749 ) {
        box = 95;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 83;
      }
    }
  }
  if ( box == 94 ) {
    lcd.clear();
    lcd.print(F("Nach links"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 94 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 95;
      }
      if ( sensorValue1 > 749 ) {
        box = 93;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 96;
      }
    }
  }
  if ( box == 95 ) {
    lcd.clear();
    lcd.print(F("Zurueck"));
    lcd.setCursor(0, 1);
    lcd.print(F("gehen"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 95 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 93;
      }
      if ( sensorValue1 > 749 ) {
        box = 94;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 83;
      }
    }
  }
  if ( box == 96 ) {
    if ( Gegner1 == 0 ) {
      box = 116;
    }
    if ( Gegner1 == 1 ) {
      lcd.clear();
      lcd.print(F("Du siehst eine"));
      lcd.setCursor(0, 1);
      lcd.print(F("Rattenmeute"));
      while (digitalRead(pinButton)) {
        delay(100);
      }
      while (!digitalRead(pinButton)) {
        delay(100);
      }
      box = 97;
    }
  }
  if ( box == 97 ) {
    lcd.clear();
    lcd.print(F("Sie greift"));
    lcd.setCursor(0, 1);
    lcd.print(F("dich an"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 98;
  }
  if ( box == 98 ) {
    lcd.clear();
    lcd.print(F("Was tust du?"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 98 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 101;
      }
      if ( sensorValue1 > 749 ) {
        box = 99;
      }
    }
  }
  if ( box == 99 ) {
    lcd.clear();
    lcd.print(F("Angreifen"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 99 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 100;
      }
      if ( sensorValue1 > 749 ) {
        box = 101;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box =  105;
      }
    }
  }
  if ( box == 100 ) {
    lcd.clear();
    lcd.print(F("Fliehen"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 100 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 101;
      }
      if ( sensorValue1 > 749 ) {
        box = 99;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 102;
        Health -= 1;
      }
    }
  }
  if ( box == 101 ) {
    lcd.clear();
    lcd.print(F("Beten"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 101 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 99;
      }
      if ( sensorValue1 > 749 ) {
        box = 100;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 113;
      }
    }
  }
  if ( box == 102 ) {
    if ( Health > 0 ) {
      lcd.clear();
      lcd.print(F("Du fliehst und"));
      lcd.setCursor(0, 1);
      lcd.print(F("kannst entkommen"));
      while (digitalRead(pinButton)) {
        delay(100);
      }
      while (!digitalRead(pinButton)) {
        delay(100);
      }
      box = 83;
    }
    if ( Health < 1 ) {
      box = 103;
    }
    if ( box ==  103 ) {
      lcd.clear();
      lcd.print(F("Die Ratten"));
      lcd.setCursor(0, 1);
      lcd.print(F("erwischen dich"));
      while (digitalRead(pinButton)) {
        delay(100);
      }
      while (!digitalRead(pinButton)) {
        delay(100);
      }
      box = 104;
    }
  }
  if ( box ==  104 ) {
    lcd.clear();
    lcd.print(F("Du bist"));
    lcd.setCursor(0, 1);
    lcd.print(F("tot!"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 0;
  }
  if ( box == 105 ) {
    lcd.clear();
    lcd.print(F("Du greifst"));
    lcd.setCursor(0, 1);
    lcd.print(F("die Ratten an"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 106;
  }
  if ( box == 106 ) {
    EnemyHealth = 2;
    EnemyDefense = 1;
    EnemyGlaube = 0;
    EnemyAttack = 3;
    box = 107;
  }
  if ( box == 107 ) {
    if ( EnemyAttack - Defense > 0 ) {
      Health -= EnemyAttack - Defense;
      if ( Health < 1 ) {
        box = 103;
      }
    }
    if ( Attack - EnemyDefense > 0 ) {
      EnemyHealth -= Attack - EnemyDefense;
      if ( EnemyHealth < 1 ) {
        box = 108;
      }
    }
  }
  if ( box == 108 ) {
    lcd.clear();
    lcd.print(F("Du besiegst"));
    lcd.setCursor(0, 1);
    lcd.print(F("die Ratten und"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 109;
  }
  if ( box == 109 ) {
    lcd.clear();
    lcd.print(F("findest eine"));
    lcd.setCursor(0, 1);
    lcd.print(F("Schatztruhe"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 110;
  }
  if ( box == 110 ) {
    lcd.clear();
    lcd.print(F("in der Schatz"));
    lcd.setCursor(0, 1);
    lcd.print(F("truhe ist eine"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 111;
  }
  if ( box == 111 ) {
    lcd.clear();
    lcd.print(F("Ritter"));
    lcd.setCursor(0, 1);
    lcd.print(F("ruestung"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 112;
  }
  if ( box == 112 ) {
    lcd.clear();
    lcd.print(F("Du legst die"));
    lcd.setCursor(0, 1);
    lcd.print(F("Ruestung an"));
    if ( Defense > 1 ) {
      Defense += 1;
    }
    else if ( Defense < 1 ) {
      Defense += 2;
    }
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 115;
  }
  if ( box == 113 ) {
    EnemyHealth = 2;
    EnemyDefense = 1;
    EnemyGlaube = 0;
    EnemyAttack = 3;
    box = 114;
  }
  if ( box == 114 ) {
    if ( EnemyAttack - Defense > 0 ) {
      Health -= EnemyAttack - Defense;
      if ( Health < 1 ) {
        box = 103;
      }
    }
    if ( Glaube - EnemyGlaube > 0 ) {
      EnemyHealth -= Glaube - EnemyGlaube;
      if ( EnemyHealth < 1 ) {
        box = 108;
      }
    }
  }
  if ( box == 115 ) {
    lcd.clear();
    lcd.print(F("Du gehst zurueck"));
    lcd.setCursor(0, 1);
    lcd.print(F("zur Biegung"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 92;
  }
  if ( box == 116 ) {
    lcd.clear();
    lcd.print(F("Du kommst zu"));
    lcd.setCursor(0, 1);
    lcd.print(F("einer Biegung"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 117;
  }
  if ( box == 117 ) {
    lcd.clear();
    lcd.print(F("Du erkennst sie"));
    lcd.setCursor(0, 1);
    lcd.print(F("wieder"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 118;
  }
  if ( box == 118 ) {
    lcd.clear();
    lcd.print(F("Du bist im"));
    lcd.setCursor(0, 1);
    lcd.print(F("Kreis gelaufen"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 92;
  }
  if ( box == 119 ) {
    lcd.clear();
    lcd.print(F("Du kommst zu"));
    lcd.setCursor(0, 1);
    lcd.print(F("einem Moor"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 120;
  }
  if ( box == 120 ) {
    lcd.clear();
    lcd.print(F("Willst du"));
    lcd.setCursor(0, 1);
    lcd.print(F("weitergehen?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 120 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 122;
      }
      if ( sensorValue1 > 749 ) {
        box = 121;
      }
    }
  }
  if ( box == 121 ) {
    lcd.clear();
    lcd.print(F("Willst du"));
    lcd.setCursor(0, 1);
    lcd.print(F("zurueckgehen?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 121 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 84;
      }
      if ( sensorValue1 > 749 ) {
        box = 120;
      }
    }
  }
  if ( box == 122 ) {
    lcd.clear();
    lcd.print(F("Du gehst weiter"));
    lcd.setCursor(0, 1);
    lcd.print(F("und"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    Health -= 1;
    if ( Health > 0 ) {
      box = 123;
    }
    if ( Health < 1 ) {
      box = 124;
    }
  }
  if ( box == 123 ) {
    lcd.clear();
    lcd.print(F("der Boden"));
    lcd.setCursor(0, 1);
    lcd.print(F("wird fester"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 125;
  }
  if ( box == 124 ) {
    lcd.clear();
    lcd.print(F("Du versinkst"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 104;
  }
  if ( box == 125 ) {
    lcd.clear();
    lcd.print(F("Du kommst zu"));
    lcd.setCursor(0, 1);
    lcd.print(F("einer Lichtung"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 126;
  }
  if ( box == 126 ) {
    lcd.clear();
    lcd.print(F("und siehst"));
    lcd.setCursor(0, 1);
    lcd.print(F("einen Haendler"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 127;
  }
  if ( box == 127 ) {
    lcd.clear();
    lcd.print(F("Willst du"));
    lcd.setCursor(0, 1);
    lcd.print(F("hingehen?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 127 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 128;
      }
      if ( sensorValue1 > 749 ) {
        box = 141;
      }
    }
  }
  if ( box == 128 ) {
    lcd.clear();
    lcd.print(F("Du gehst zu"));
    lcd.setCursor(0, 1);
    lcd.print(F("ihm hin"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 129;
  }
  if ( box == 129 ) {
    lcd.clear();
    lcd.print(F("Er bietet"));
    lcd.setCursor(0, 1);
    lcd.print(F("dir..."));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 129 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 130;
      }
      if ( sensorValue1 > 749 ) {
        box = 131;
      }
    }
  }
  if ( box == 130 ) {
    if ( Menge7 < 1 ) {
      box = 131;
    }
    if ( Menge7 > 0 ) {
      if ( Gift == 1 ) {
        box = 132;
      }
      else if ( Gift == 0 ) {
        lcd.clear();
        lcd.print(F("Ein Amulett"));
        lcd.setCursor(0, 1);
        lcd.print(F("fuer 50 Gold"));
        while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
          sensorValue1 = analogRead(A0);
        }
        while ( box == 130 ) {
          delay(100);
          sensorValue1 = analogRead(A0);
          if ( sensorValue1 < 261 ) {
            box = 131;
          }
          if ( sensorValue1 > 749 ) {
            box = 131;
          }
          if (digitalRead(pinButton)) {
            delay(100);
            box = 133;
            if ( Goldmuenzen < 50 ) {
              box = 137;
            }
          }
        }
      }
    }
  }
  if ( box == 131 ) {
    if ( Menge8 < 1 ) {
      box = 138;
    }
    if ( Menge8 > 0 ) {
      lcd.clear();
      lcd.print(F("Einen Trank"));
      lcd.setCursor(0, 1);
      lcd.print(F("und 25 Gold"));
      while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
        sensorValue1 = analogRead(A0);
      }
      while ( box == 131 ) {
        delay(100);
        sensorValue1 = analogRead(A0);
        if ( sensorValue1 < 261 ) {
          box = 130;
        }
        if ( sensorValue1 > 749 ) {
          box = 130;
        }
        if (digitalRead(pinButton)) {
          delay(100);
          box = 134;
          if ( Goldmuenzen < 25 ) {
            box = 137;
          }
        }
      }
    }
  }
  if ( box == 132 ) {
    lcd.clear();
    lcd.print(F("Fuer eine"));
    lcd.setCursor(0, 1);
    lcd.print(F("Giftphiole"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 132 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 131;
      }
      if ( sensorValue1 > 749 ) {
        box = 131;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 136;
      }
    }
  }
  if ( box == 133 ) {
    Menge7 -= 1;
    Goldmuenzen -= 50;
    Glaube += 2;
    lcd.clear();
    lcd.print(F("Du kaufst das"));
    lcd.setCursor(0, 1);
    lcd.print(F("Amulett"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 139;
  }
  if ( box == 134 ) {
    Menge8 -= 1;
    Goldmuenzen -= 25;
    Health = 6;
    lcd.clear();
    lcd.print(F("Du trinkst ihn"));
    lcd.setCursor(0, 1);
    lcd.print(F("und fuehlst dich"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 135;
  }
  if ( box == 135 ) {
    lcd.clear();
    lcd.print(F("sehr erfischt"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 139;
  }
  if ( box == 136 ) {
    Menge7 -= 1;
    Glaube += 2;
    Gift = 0;
    lcd.clear();
    lcd.print(F("Du kaufst das"));
    lcd.setCursor(0, 1);
    lcd.print(F("Amulett"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 139;
  }
  if ( box == 137 ) {
    lcd.clear();
    lcd.print(F("Du hast nicht"));
    lcd.setCursor(0, 1);
    lcd.print(F("genug Gold"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 139;
  }
  if ( box == 138 ) {
    lcd.clear();
    lcd.print(F("Doch nichts"));
    lcd.setCursor(0, 1);
    lcd.print(F("kaufen"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 138 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 130;
      }
      if ( sensorValue1 > 749 ) {
        box = 131;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 140;
      }
    }
  }
  if ( box == 139 ) {
    lcd.clear();
    lcd.print(F("Willst du noch"));
    lcd.setCursor(0, 1);
    lcd.print(F("etwas kaufen?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 139 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 130;
      }
      if ( sensorValue1 > 749 ) {
        box = 140;
      }
    }
  }
  if ( box == 140 ) {
    lcd.clear();
    lcd.print(F("Willst du"));
    lcd.setCursor(0, 1);
    lcd.print(F("weitergehen?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 140 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 141;
      }
      if ( sensorValue1 > 749 ) {
        box = 139;
      }
    }
  }
  if ( box == 138 ) {
    lcd.clear();
    lcd.print(F("Doch nichts"));
    lcd.setCursor(0, 1);
    lcd.print(F("kaufen"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 138 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 130;
      }
      if ( sensorValue1 > 749 ) {
        box = 131;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 140;
      }
    }
  }
  if ( box == 141 ) {
    lcd.clear();
    lcd.print(F("Willst du nach"));
    lcd.setCursor(0, 1);
    lcd.print(F("Norden gehen?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 141 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 143;
      }
      if ( sensorValue1 > 749 ) {
        box = 142;
      }
    }
  }
  if ( box == 142 ) {
    lcd.clear();
    lcd.print(F("Willst du nach"));
    lcd.setCursor(0, 1);
    lcd.print(F("Sueden gehen?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 142 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 199;
      }
      if ( sensorValue1 > 749 ) {
        box = 144;
      }
    }
  }
  if ( box == 143 ) {
    lcd.clear();
    lcd.print(F("Du gehst"));
    lcd.setCursor(0, 1);
    lcd.print(F("nach Norden"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 17;
  }
  if ( box == 144 ) {
    lcd.clear();
    lcd.print(F("Willst du nach"));
    lcd.setCursor(0, 1);
    lcd.print(F("Osten gehen?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 144 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 145;
      }
      if ( sensorValue1 > 749 ) {
        box = 127;
      }
    }
  }
  if ( box == 145 ) {
    lcd.clear();
    lcd.print(F("Du gehst"));
    lcd.setCursor(0, 1);
    lcd.print(F("nach Osten"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 146;
  }
  if ( box == 146 ) {
    lcd.clear();
    lcd.print(F("Es wird"));
    lcd.setCursor(0, 1);
    lcd.print(F("Dunkel"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 147;
  }
  if ( box == 147 ) {
    lcd.clear();
    lcd.print(F("Du hoerst"));
    lcd.setCursor(0, 1);
    lcd.print(F("Stimmen"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 148;
  }
  if ( box == 148 ) {
    lcd.clear();
    lcd.print(F("Willst du"));
    lcd.setCursor(0, 1);
    lcd.print(F("hingehen?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 148 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 149;
      }
      if ( sensorValue1 > 749 ) {
        box = 150;
      }
    }
  }
  if ( box == 149 ) {
    lcd.clear();
    lcd.print(F("Du gehst zu"));
    lcd.setCursor(0, 1);
    lcd.print(F("den Stimmen"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 153;
  }
  if ( box == 150 ) {
    lcd.clear();
    lcd.print(F("Willst du"));
    lcd.setCursor(0, 1);
    lcd.print(F("zurueckgehen?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 150 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 152;
      }
      if ( sensorValue1 > 749 ) {
        box = 151;
      }
    }
  }
  if ( box == 151 ) {
    lcd.clear();
    lcd.print(F("Willst du zu den"));
    lcd.setCursor(0, 1);
    lcd.print(F("Stimmen gehen?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 151 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 149;
      }
      if ( sensorValue1 > 749 ) {
        box = 150;
      }
    }
  }
  if ( box == 152 ) {
    lcd.clear();
    lcd.print(F("Du gehst"));
    lcd.setCursor(0, 1);
    lcd.print(F("zurueck"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 141;
  }
  if ( box == 153 ) {
    lcd.clear();
    lcd.print(F("Du siehst"));
    lcd.setCursor(0, 1);
    lcd.print(F("2 Raeuber"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 154;
  }
  if ( box == 154 ) {
    lcd.clear();
    lcd.print(F("Sie sitzen an"));
    lcd.setCursor(0, 1);
    lcd.print(F("einem Lagerfeuer"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 155;
  }
  if ( box == 155 ) {
    lcd.clear();
    lcd.print(F("Willst du..."));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 155 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 156;
      }
      if ( sensorValue1 > 749 ) {
        box = 158;
      }
    }
  }
  if ( box == 156 ) {
    lcd.clear();
    lcd.print(F("hingehen?"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 156 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 157;
      }
      if ( sensorValue1 > 749 ) {
        box = 158;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 159;
      }
    }
  }
  if ( box == 157 ) {
    lcd.clear();
    lcd.print(F("dich"));
    lcd.setCursor(0, 1);
    lcd.print(F("anschleichen?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 157 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 158;
      }
      if ( sensorValue1 > 749 ) {
        box = 156;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 180;
      }
    }
  }
  if ( box == 158 ) {
    lcd.clear();
    lcd.print(F("zurueckgehen?"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 158 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 156;
      }
      if ( sensorValue1 > 749 ) {
        box = 157;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 152;
      }
    }
  }
  if ( box == 159 ) {
    lcd.clear();
    lcd.print(F("Du gehst zu"));
    lcd.setCursor(0, 1);
    lcd.print(F("ihnen hin und"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 160;
  }
  if ( box == 160 ) {
    lcd.clear();
    lcd.print(F("sie greifen"));
    lcd.setCursor(0, 1);
    lcd.print(F("dich an"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 161;
  }
  if ( box == 161 ) {
    lcd.clear();
    lcd.print(F("Was tust"));
    lcd.setCursor(0, 1);
    lcd.print(F("du?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 161 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 164;
      }
      if ( sensorValue1 > 749 ) {
        box = 166;
      }
    }
  }
  if ( box == 162 ) {
    lcd.clear();
    lcd.print(F("Sie toeten"));
    lcd.setCursor(0, 1);
    lcd.print(F("dich"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 104;
  }
  if ( box == 163 ) {
    lcd.clear();
    lcd.print(F("Du besiegst"));
    lcd.setCursor(0, 1);
    lcd.print(F("sie"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 173;
  }
  if ( box == 164 ) {
    lcd.clear();
    lcd.print(F("Angreifen"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 164 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 165;
      }
      if ( sensorValue1 > 749 ) {
        box = 166;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 167;
      }
    }
  }
  if ( box == 165 ) {
    lcd.clear();
    lcd.print(F("Beten"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 165 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 166;
      }
      if ( sensorValue1 > 749 ) {
        box = 164;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 169;
      }
    }
  }
  if ( box == 166 ) {
    lcd.clear();
    lcd.print(F("Fliehen"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 166 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 164;
      }
      if ( sensorValue1 > 749 ) {
        box = 165;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 171;
      }
    }
  }
  if ( box == 167 ) {
    EnemyHealth = 6;
    EnemyDefense = 2;
    EnemyGlaube = 1;
    EnemyAttack = 3;
    box = 168;
  }
  if ( box == 168 ) {
    if ( EnemyAttack - Defense > 0 ) {
      Health -= EnemyAttack - Defense;
      if ( Health < 1 ) {
        box = 162;
      }
    }
    if ( Attack - EnemyDefense > 0 ) {
      EnemyHealth -= Attack - EnemyDefense;
      if ( EnemyHealth < 1 ) {
        box = 163;
      }
    }
  }
  if ( box == 169 ) {
    EnemyHealth = 6;
    EnemyDefense = 2;
    EnemyGlaube = 1;
    EnemyAttack = 3;
    box = 170;
  }
  if ( box == 170 ) {
    if ( EnemyAttack - Defense > 0 ) {
      Health -= EnemyAttack - Defense;
      if ( Health < 1 ) {
        box = 162;
      }
    }
    if ( Glaube - EnemyGlaube > 0 ) {
      EnemyHealth -= Glaube - EnemyGlaube;
      if ( EnemyHealth < 1 ) {
        box = 163;
      }
    }
  }
  if ( box == 171 ) {
    Health -= 2;
    if ( Health < 1 ) {
      box = 162;
    }
    lcd.clear();
    lcd.print(F("Du versuchst"));
    lcd.setCursor(0, 1);
    lcd.print(F("zu fliehen"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 172;
  }
  if ( box == 172 ) {
    lcd.clear();
    lcd.print(F("Sie holen dich"));
    lcd.setCursor(0, 1);
    lcd.print(F("ein"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 161;
  }
  if ( box == 173 ) {
    lcd.clear();
    lcd.print(F("Was tust"));
    lcd.setCursor(0, 1);
    lcd.print(F("du?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 173 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 174;
      }
      if ( sensorValue1 > 749 ) {
        box = 175;
      }
    }
  }
  if ( box == 174 ) {
    lcd.clear();
    lcd.print(F("Ihre Sachen"));
    lcd.setCursor(0, 1);
    lcd.print(F("nehmen"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 174 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 175;
      }
      if ( sensorValue1 > 749 ) {
        box = 175;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 176;
      }
    }
  }
  if ( box == 175 ) {
    lcd.clear();
    lcd.print(F("Ans Lagerfeuer"));
    lcd.setCursor(0, 1);
    lcd.print(F("setzen"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 175 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 174;
      }
      if ( sensorValue1 > 749 ) {
        box = 174;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 178;
      }
    }
  }
  if ( box == 176 ) {
    lcd.clear();
    lcd.print(F("Du findest"));
    lcd.setCursor(0, 1);
    lcd.print(F("einen Helm"));
    Defense += 1;
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 177;
  }
  if ( box == 177 ) {
    lcd.clear();
    lcd.print(F("und"));
    lcd.setCursor(0, 1);
    lcd.print(F("Goldmuenzen"));
    Goldmuenzen += 70;
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 178;
  }
  if ( box == 178 ) {
    lcd.clear();
    lcd.print(F("Du setzt dich"));
    lcd.setCursor(0, 1);
    lcd.print(F("ans Lagerfeuer"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 179;
  }
  if ( box == 179 ) {
    lcd.clear();
    lcd.print(F("Du legst dich"));
    lcd.setCursor(0, 1);
    lcd.print(F("Schlafen"));
    if ( Health < 4 ) {
      Health += 2;
    }
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 218;
  }
  if ( box == 180 ) {
    lcd.clear();
    lcd.print(F("Du schleichst"));
    lcd.setCursor(0, 1);
    lcd.print(F("dich an"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 181;
  }
  if ( box == 181 ) {
    lcd.clear();
    lcd.print(F("Was tust du?"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 181 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 182;
      }
      if ( sensorValue1 > 749 ) {
        box = 183;
      }
    }
  }
  if ( box == 182 ) {
    lcd.clear();
    lcd.print(F("Angreifen"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 182 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 183;
      }
      if ( sensorValue1 > 749 ) {
        box = 183;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 184;
      }
    }
  }
  if ( box == 183 ) {
    lcd.clear();
    lcd.print(F("Zurueckgehen"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 183 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 182;
      }
      if ( sensorValue1 > 749 ) {
        box = 182;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 152;
      }
    }
  }
  if ( box == 184 ) {
    lcd.clear();
    lcd.print(F("Du ueberraschst"));
    lcd.setCursor(0, 1);
    lcd.print(F("die Raueber"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 185;
  }
  if ( box == 185 ) {
    lcd.clear();
    lcd.print(F("Du kannst einen"));
    lcd.setCursor(0, 1);
    lcd.print(F("ueberwaeltigen"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 186;
  }
  if ( box == 186 ) {
    lcd.clear();
    lcd.print(F("Der andere"));
    lcd.setCursor(0, 1);
    lcd.print(F("greift dich an"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 187;
  }
  if ( box == 187 ) {
    lcd.clear();
    lcd.print(F("Was tust du?"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 187 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 188;
      }
      if ( sensorValue1 > 749 ) {
        box = 190;
      }
    }
  }
  if ( box == 188 ) {
    lcd.clear();
    lcd.print(F("Angreifen"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 188 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 189;
      }
      if ( sensorValue1 > 749 ) {
        box = 190;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 195;
      }
    }
  }
  if ( box == 189 ) {
    lcd.clear();
    lcd.print(F("Beten"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 189 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 188;
      }
      if ( sensorValue1 > 749 ) {
        box = 190;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 191;
      }
    }
  }
  if ( box == 190 ) {
    lcd.clear();
    lcd.print(F("Fliehen"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 190 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 188;
      }
      if ( sensorValue1 > 749 ) {
        box = 189;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 197;
      }
    }
  }
  if ( box == 191 ) {
    EnemyHealth = 3;
    EnemyDefense = 2;
    EnemyGlaube = 1;
    EnemyAttack = 3;
    box = 192;
  }
  if ( box == 192 ) {
    if ( EnemyAttack - Defense > 0 ) {
      Health -= EnemyAttack - Defense;
      if ( Health < 1 ) {
        box = 193;
      }
    }
    if ( Glaube - EnemyGlaube > 0 ) {
      EnemyHealth -= Glaube - EnemyGlaube;
      if ( EnemyHealth < 1 ) {
        box = 194;
      }
    }
  }
  if ( box == 193 ) {
    lcd.clear();
    lcd.print(F("Er toetet"));
    lcd.setCursor(0, 1);
    lcd.print(F("dich"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 104;
  }
  if ( box == 194 ) {
    lcd.clear();
    lcd.print(F("Du besiegst"));
    lcd.setCursor(0, 1);
    lcd.print(F("ihn"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 173;
  }
  if ( box == 195 ) {
    EnemyHealth = 3;
    EnemyDefense = 2;
    EnemyGlaube = 1;
    EnemyAttack = 3;
    box = 168;
  }
  if ( box == 196 ) {
    if ( EnemyAttack - Defense > 0 ) {
      Health -= EnemyAttack - Defense;
      if ( Health < 1 ) {
        box = 193;
      }
    }
    if ( Attack - EnemyDefense > 0 ) {
      EnemyHealth -= Attack - EnemyDefense;
      if ( EnemyHealth < 1 ) {
        box = 194;
      }
    }
  }
  if ( box == 197 ) {
    Health -= 1;
    if ( Health < 1 ) {
      box = 193;
    }
    lcd.clear();
    lcd.print(F("Du versuchst"));
    lcd.setCursor(0, 1);
    lcd.print(F("zu fliehen"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 198;
  }
  if ( box == 198 ) {
    lcd.clear();
    lcd.print(F("Er holt dich"));
    lcd.setCursor(0, 1);
    lcd.print(F("ein"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 187;
  }
  if ( box == 199 ) {
    lcd.clear();
    lcd.print(F("Du gehst"));
    lcd.setCursor(0, 1);
    lcd.print(F("nach Sueden"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 200;
  }
  if ( box == 200 ) {
    lcd.clear();
    lcd.print(F("Es wird"));
    lcd.setCursor(0, 1);
    lcd.print(F("Dunkel"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 201;
  }
  if ( box == 201 ) {
    lcd.clear();
    lcd.print(F("Du hoerst"));
    lcd.setCursor(0, 1);
    lcd.print(F("ein Heulen"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 202;
  }
  if ( box == 202 ) {
    lcd.clear();
    lcd.print(F("Du hoerst"));
    lcd.setCursor(0, 1);
    lcd.print(F("ein Heulen"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 203;
  }
  if ( box == 203 ) {
    lcd.clear();
    lcd.print(F("Was tust du?"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 203 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 204;
      }
      if ( sensorValue1 > 749 ) {
        box = 205;
      }
    }
  }
  if ( box == 204 ) {
    lcd.clear();
    lcd.print(F("Hingehen"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 204 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 205;
      }
      if ( sensorValue1 > 749 ) {
        box = 205;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 207;
      }
    }
  }
  if ( box == 205 ) {
    lcd.clear();
    lcd.print(F("Dich davon"));
    lcd.setCursor(0, 1);
    lcd.print(F("entfernen"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 205 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 204;
      }
      if ( sensorValue1 > 749 ) {
        box = 204;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 206;
      }
    }
  }
  if ( box == 206 ) {
    lcd.clear();
    lcd.print(F("Du gehst von"));
    lcd.setCursor(0, 1);
    lcd.print(F("dem Heulen weg"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 207;
  }
  if ( box == 207 ) {
    lcd.clear();
    lcd.print(F("Du bist sehr"));
    lcd.setCursor(0, 1);
    lcd.print(F("Muede und"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 208;
  }
  if ( box == 208 ) {
    lcd.clear();
    lcd.print(F("verlaeufst dich"));
    lcd.setCursor(0, 1);
    lcd.print(F("im Wald"));
    Health -= 1;
    if ( Health < 1 ) {
      box = 210;
    }
    else if ( Health > 0 ) {
      box = 209;
    }
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
  }
  if ( box == 209 ) {
    lcd.clear();
    lcd.print(F("Du schlaefst"));
    lcd.setCursor(0, 1);
    lcd.print(F("irgendwann ein"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 211;
  }
  if ( box == 210 ) {
    lcd.clear();
    lcd.print(F("Du faellst"));
    lcd.setCursor(0, 1);
    lcd.print(F("vor Muedigkeit"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 212;
  }
  if ( box == 211 ) {
    lcd.clear();
    lcd.print(F("und wachst am na"));
    lcd.setCursor(0, 1);
    lcd.print(F("echsten Tag auf"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 213;
  }
  if ( box == 212 ) {
    lcd.clear();
    lcd.print(F("um und faellst"));
    lcd.setCursor(0, 1);
    lcd.print(F("in einen Fluss"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 104;
  }
  if ( box == 213 ) {
    lcd.clear();
    lcd.print(F("Du siehst eine"));
    lcd.setCursor(0, 1);
    lcd.print(F("verlassene Burg"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 231;
  }
  if ( box == 214 ) {
    lcd.clear();
    lcd.print(F("Du gehst"));
    lcd.setCursor(0, 1);
    lcd.print(F("zu ihm"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 215;
  }
  if ( box == 215 ) {
    lcd.clear();
    lcd.print(F("Willst du"));
    lcd.setCursor(0, 1);
    lcd.print(F("etwas kaufen?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 215 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 219;
      }
      if ( sensorValue1 > 749 ) {
        box = 216;
      }
    }
  }
  if ( box == 216 ) {
    lcd.clear();
    lcd.print(F("Willst du"));
    lcd.setCursor(0, 1);
    lcd.print(F("zurueckgehen?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 216 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 23;
      }
      if ( sensorValue1 > 749 ) {
        box = 226;
      }
    }
  }
  if ( box == 217 ) {
    lcd.clear();
    lcd.print(F("Willst du"));
    lcd.setCursor(0, 1);
    lcd.print(F("zurueckgehen?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 217 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 23;
      }
      if ( sensorValue1 > 749 ) {
        box = 34;
      }
    }
  }
  if ( box == 218 ) {
    lcd.clear();
    lcd.print(F("Du wachst spaet"));
    lcd.setCursor(0, 1);
    lcd.print(F("morgens auf"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 213;
  }
  if ( box == 219 ) {
    lcd.clear();
    lcd.print(F("Er bietet"));
    lcd.setCursor(0, 1);
    lcd.print(F("dir..."));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 219 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 220;
      }
      if ( sensorValue1 > 749 ) {
        box = 222;
      }
    }
  }
  if ( box == 220 ) {
    if ( Menge9 > 0 ) {
      lcd.clear();
      lcd.print(F("Schwarzes Pulver"));
      lcd.setCursor(0, 1);
      lcd.print(F("fuer 5 Gold an"));
      while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
        sensorValue1 = analogRead(A0);
      }
      while ( box == 220 ) {
        delay(100);
        sensorValue1 = analogRead(A0);
        if ( sensorValue1 < 261 ) {
          box = 221;
        }
        if ( sensorValue1 > 749 ) {
          box = 223;
        }
        if (digitalRead(pinButton)) {
          delay(100);
          if ( Goldmuenzen < 5 ) {
            box = 224;
          }
          else {
            box = 225;
            Menge9 -= 1;
            Goldmuenzen -= 5;
            Ware += 2;
          }
        }
      }
    }
    else if ( Menge9 < 1 ) {
      box = 221;
    }
  }
  if ( box == 221 ) {
    if ( Menge10 > 0 ) {
      lcd.clear();
      lcd.print(F("Das TOTE BUCH"));
      lcd.setCursor(0, 1);
      lcd.print(F("fuer 100 Gold an"));
      while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
        sensorValue1 = analogRead(A0);
      }
      while ( box == 221 ) {
        delay(100);
        sensorValue1 = analogRead(A0);
        if ( sensorValue1 < 261 ) {
          box = 222;
        }
        if ( sensorValue1 > 749 ) {
          box = 221;
        }
        if (digitalRead(pinButton)) {
          delay(100);
          if ( Goldmuenzen < 100 ) {
            box = 224;
            Goldmuenzen -= 100;
            Glaube += 5;
            Menge10 -= 1;
          }
          else {
            box = 225;
          }
        }
      }
    }
    else if ( Menge10 < 1 ) {
      box = 222;
    }
  }
  if ( box == 222 ) {
    if ( Menge11 > 0 ) {
      lcd.clear();
      lcd.print(F("Ein Easteregg"));
      lcd.setCursor(0, 1);
      lcd.print(F("fuer 0 Gold an"));
      while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
        sensorValue1 = analogRead(A0);
      }
      while ( box == 222 ) {
        delay(100);
        sensorValue1 = analogRead(A0);
        if ( sensorValue1 < 261 ) {
          box = 223;
        }
        if ( sensorValue1 > 749 ) {
          box = 221;
        }
        if (digitalRead(pinButton)) {
          delay(100);
          box = 227;
        }
      }
    }
    else if ( Menge11 < 1 ) {
      box = 223;
      Menge11 -= 1;
    }
  }
  if ( box == 223 ) {
    lcd.clear();
    lcd.print(F("Doch nichts"));
    lcd.setCursor(0, 1);
    lcd.print(F("kaufen"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 223 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 220;
      }
      if ( sensorValue1 > 749 ) {
        box = 222;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 226;
      }
    }
  }
  if ( box == 224 ) {
    lcd.clear();
    lcd.print(F("Du hast nicht"));
    lcd.setCursor(0, 1);
    lcd.print(F("genug Gold"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 225;
  }
  if ( box == 225 ) {
    lcd.clear();
    lcd.print(F("Willst du noch"));
    lcd.setCursor(0, 1);
    lcd.print(F("etwas kaufen?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 225 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 219;
      }
      if ( sensorValue1 > 749 ) {
        box = 226;
      }
    }
  }
  if ( box == 226 ) {
    lcd.clear();
    lcd.print(F("Willst du"));
    lcd.setCursor(0, 1);
    lcd.print(F("zur Burg gehen?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 226 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 21;
      }
      if ( sensorValue1 > 749 ) {
        box = 215;
      }
    }
  }
  if ( box == 227 ) {
    lcd.clear();
    lcd.print(F("Herzlichen"));
    lcd.setCursor(0, 1);
    lcd.print(F("Glueckwunsch!"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 228;
  }
  if ( box == 228 ) {
    lcd.clear();
    lcd.print(F("Du hast das East"));
    lcd.setCursor(0, 1);
    lcd.print(F("eregg gefunden"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 229;
  }
  if ( box == 229 ) {
    lcd.clear();
    lcd.print(F("Willst du eine"));
    lcd.setCursor(0, 1);
    lcd.print(F("Belohnung haben?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 229 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 230;
      }
      if ( sensorValue1 > 749 ) {
        box = 225;
      }
    }
  }
  if ( box == 230 ) {
    lcd.clear();
    lcd.print(F("Du hast etwas"));
    lcd.setCursor(0, 1);
    lcd.print(F("Gold erhalten"));
    Goldmuenzen += 5;
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 225;
  }
}
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
