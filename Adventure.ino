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
int Goldmuenzen;
int Defense;
int Attack;
int Health;
int Menge1;
int Menge2;
int Menge3;
int Menge4;
int Menge5;
int Menge6;
int Truhe1;
int Gift;
int Ware;              // Schnaps usw. zum Verkaufen
int EnemyHealth;
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
  Truhe1 = 1;
  Health = 5;
  Gift = 0;
  Ware = 0;
  Goldmuenzen = 15;
  while (!digitalRead(pinButton)) {
    delay(100);
  }
  box = 1;
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
    Truhe1 = 1;
    Health = 5;
    Gift = 0;
    Ware = 0;
    Goldmuenzen = 15;
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
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 33;
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
    lcd.print(F("Brücke"));
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
        box = 6;
      }
    }
  }
  if ( box == 36 ) {
    lcd.clear();
    lcd.print(F("und hoerst Rufe"));
    lcd.setCursor(0, 1);
    lcd.print(F("aus Norden"));
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
    lcd.print(F("den Haendler"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 37;
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
        box = 61;
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
    lcd.print(F("Zurueck in"));
    lcd.setCursor(0, 1);
    lcd.print(F("den Wald"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 61  ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 45;
      }
      if ( sensorValue1 > 749 ) {
        box = 47;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 62;
      }
    }
  }
  if ( box == 62 ) {
    lcd.clear();
    lcd.print(F("Du gehst zurueck"));
    lcd.setCursor(0, 1);
    lcd.print(F("in den Wald"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box =  126;
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
    lcd.print(F("es verkaufen?"));
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
    lcd.print(F("Du verkaufst ihm"));
    lcd.setCursor(0, 1);
    lcd.print(F("und"));
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
        box = 85;
      }
      if ( sensorValue1 > 749 ) {
        box = 88;
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
        box = 118;
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
        box = 114;
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
        box = 103;
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
    box = 107;
  }
  if ( box == 107 ) {
    if ( 3 - Defense > 0 ) {
      Health -= 3 - Defense;
      if ( Health < 1 ) {
        box = 103;
      }
    }
    if ( Attack - 1 > 0 ) {
      EnemyHealth -= Attack - 1;
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
    if ( Truhe1 == 1 ) {
      lcd.clear();
      lcd.print(F("findest eine"));
      lcd.setCursor(0, 1);
      lcd.print(F("Schatztruhe"));
      Truhe1 = 0;
      while (digitalRead(pinButton)) {
        delay(100);
      }
      while (!digitalRead(pinButton)) {
        delay(100);
      }
      box = 110;
    }
    else if ( Truhe1 == 0 ) {
      lcd.clear();
      lcd.print(F("findest eine lee"));
      lcd.setCursor(0, 1);
      lcd.print(F("re Schatztruhe"));
      while (digitalRead(pinButton)) {
        delay(100);
      }
      while (!digitalRead(pinButton)) {
        delay(100);
      }
      box = 11;
    }
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
    box = 113;
  }
  if ( box == 113 ) {
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
    box = 84;
  }
  if ( box == 114 ) {
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
    box = 115;
  }
  if ( box == 115 ) {
    lcd.clear();
    lcd.print(F("Wohin willst"));
    lcd.setCursor(0, 1);
    lcd.print(F("du gehen?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 115 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 116;
      }
      if ( sensorValue1 > 749 ) {
        box = 117;
      }
    }
  }
  if ( box == 116 ) {
    lcd.clear();
    lcd.print(F("Nach rechts"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 116 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 117;
      }
      if ( sensorValue1 > 749 ) {
        box = 117;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 118;
      }
    }
  }
  if ( box == 117 ) {
    lcd.clear();
    lcd.print(F("Nach links"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 117 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 116;
      }
      if ( sensorValue1 > 749 ) {
        box = 116;
      }
      if (digitalRead(pinButton)) {
        delay(100);
        box = 83;
      }
    }
  }
  if ( box == 118 ) {
    lcd.clear();
    lcd.print(F("Der Boden wird"));
    lcd.setCursor(0, 1);
    lcd.print(F("schlammig"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 119;
  }
  if ( box == 119 ) {
    lcd.clear();
    lcd.print(F("Moechtest du"));
    lcd.setCursor(0, 1);
    lcd.print(F("weitergehen?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 119 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 120;
      }
      if ( sensorValue1 > 749 ) {
        box = 121;
      }
    }
  }
  if ( box == 120 ) {
    lcd.clear();
    lcd.print(F("Du versinkst"));
    lcd.setCursor(0, 1);
    lcd.print(F(""));
    Health -= 1;
    if ( Health < 1 ) {
      box = 104;
    }
    else if ( Health > 0 ) {
      box = 122;
    }
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
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
        box = 114;
      }
      if ( sensorValue1 > 749 ) {
        box = 119;
      }
    }
  }
  if ( box == 122 ) {
    lcd.clear();
    lcd.print(F("Willst du"));
    lcd.setCursor(0, 1);
    lcd.print(F("weitergehen?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 122 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 124;
      }
      if ( sensorValue1 > 749 ) {
        box = 123;
      }
    }
  }
  if ( box == 123 ) {
    lcd.clear();
    lcd.print(F("Willst du"));
    lcd.setCursor(0, 1);
    lcd.print(F("zurueckgehen?"));
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    while ( box == 123 ) {
      delay(100);
      sensorValue1 = analogRead(A0);
      if ( sensorValue1 < 261 ) {
        box = 114;
      }
      if ( sensorValue1 > 749 ) {
        box = 122;
      }
    }
  }
  if ( box == 124 ) {
    lcd.clear();
    lcd.print(F("Der Boden wird"));
    lcd.setCursor(0, 1);
    lcd.print(F("fester"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 125;
  }
  if ( box == 125 ) {
    lcd.clear();
    lcd.print(F("Du betrittst"));
    lcd.setCursor(0, 1);
    lcd.print(F("den Wald"));
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 126;
  }
}
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
