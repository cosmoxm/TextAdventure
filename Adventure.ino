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
#include "rgb_lcd.h"

rgb_lcd lcd;
int box;
int sensorValue1;
int sensorValue2;
int Goldmuenzen;

void setup() {
  pinMode(pinButton, INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Du bist ein Wand");
  lcd.setCursor(0, 1);
  lcd.print("erer im 11.Jhdt");
  while (!digitalRead(pinButton)) {
    delay(100);
  }
  box = 1;
}

void loop()
{
  if ( box == 1 ) {
    lcd.clear();
    lcd.print("Du bist an einem");
    lcd.setCursor(0, 1);
    lcd.print("Fluss im Wald");
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
    lcd.print("Willst du am Flu");
    lcd.setCursor(0, 1);
    lcd.print("ss entlang gehen");
    sensorValue1 = analogRead(A0);
    sensorValue2 = analogRead(A1);
    while ( sensorValue1 < 261 || sensorValue1 > 749 ) {
      sensorValue1 = analogRead(A0);
    }
    Serial.print("The X and Y coordinate is:");
    Serial.print(sensorValue1, DEC);
    Serial.print(",");
    Serial.println(sensorValue2, DEC);
    Serial.println(" ");
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
    lcd.print("Du bist an");
    lcd.setCursor(0, 1);
    lcd.print("einer Bruecke");
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
    lcd.print("Moechtest du in");
    lcd.setCursor(0, 1);
    lcd.print("den Wald gehen");
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
    lcd.print("Du gehst in");
    lcd.setCursor(0, 1);
    lcd.print("den Wald");
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
    lcd.print("Moechtest du");
    lcd.setCursor(0, 1);
    lcd.print("dich ausruhen");
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
    lcd.print("Du setzt dich");
    lcd.setCursor(0, 1);
    lcd.print("eine Weile hin");
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    lcd.clear();
    lcd.print("Spaeter fuehlst du");
    lcd.setCursor(0, 1);
    lcd.print("dich viel besser");
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
    lcd.print("Willst du");
    lcd.setCursor(0, 1);
    lcd.print("ruebergehen?");
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
    lcd.print("Willst du am Fl");
    lcd.setCursor(0, 1);
    lcd.print("uss entlangehen ");
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
    lcd.print("Du betrittst de");
    lcd.setCursor(0, 1);
    lcd.print("n Dunkel Wald");
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
    lcd.print("Du kommst zu");
    lcd.setCursor(0, 1);
    lcd.print("einem Wasserfall");
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
    lcd.print("Du triffst auf");
    lcd.setCursor(0, 1);
    lcd.print("einen Wanderer");
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
    lcd.print("Du fragst");
    lcd.setCursor(0, 1);
    lcd.print("ihn ob...");

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
    lcd.print("er weis wo die n");
    lcd.setCursor(0, 1);
    lcd.print("aechste Burg ist");
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
    lcd.print("er weis was hint");
    lcd.setCursor(0, 1);
    lcd.print("er dem Fluss ist");
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
    lcd.print("Er zeigt dir");
    lcd.setCursor(0, 1);
    lcd.print("den Weg");
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
    lcd.print("Er zeigt dir");
    lcd.setCursor(0, 1);
    lcd.print("den Weg");
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
    lcd.print("Du kommst zu");
    lcd.setCursor(0, 1);
    lcd.print("einer Burg");
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
    lcd.print("Die Wachen lasse");
    lcd.setCursor(0, 1);
    lcd.print("n dich passieren");
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
    lcd.print("Du gehst");
    lcd.setCursor(0, 1);
    lcd.print("hinein");
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
    lcd.print("Du kommst zur");
    lcd.setCursor(0, 1);
    lcd.print("Burg von");
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
    lcd.print("Kaiser");
    lcd.setCursor(0, 1);
    lcd.print("Friedrich");
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
    lcd.print("Wohin willst");
    lcd.setCursor(0, 1);
    lcd.print("du gehen?");
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
    lcd.print("Norden");
    lcd.setCursor(0, 1);
    lcd.print("");
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
    lcd.print("Du kommst zu");
    lcd.setCursor(0, 1);
    lcd.print("einer Lichtung");
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
    lcd.print("und siehst ");
    lcd.setCursor(0, 1);
    lcd.print("einen Haendler");
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
    lcd.print("Sued-Ost");
    lcd.setCursor(0, 1);
    lcd.print("");
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
    lcd.print("Du hast dich");
    lcd.setCursor(0, 1);
    lcd.print("verlaufen und");
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
    lcd.print("kommst zu");
    lcd.setCursor(0, 1);
    lcd.print("einer Burg");
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
    lcd.print("Westen");
    lcd.setCursor(0, 1);
    lcd.print("");
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
    lcd.print("Du kommst zu");
    lcd.setCursor(0, 1);
    lcd.print("einem Fluss");
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
    lcd.print("mit einer");
    lcd.setCursor(0, 1);
    lcd.print("Brücke");
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
    lcd.print("Er wird ");
    lcd.setCursor(0, 1);
    lcd.print("Ueberfallen");
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
    lcd.print("Moechtest du");
    lcd.setCursor(0, 1);
    lcd.print("ihm helfen");
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
    lcd.print("und hoerst Rufe");
    lcd.setCursor(0, 1);
    lcd.print("aus Norden");
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
    lcd.print("Du hilfst ihm");
    lcd.setCursor(0, 1);
    lcd.print("den Haendler");
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
    lcd.print("zu ueberwael");
    lcd.setCursor(0, 1);
    lcd.print("tigen und er");
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
    lcd.print("schenkt dir 100");
    lcd.setCursor(0, 1);
    lcd.print("Goldstuecke");
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    Goldmuenzen = 100;
    box = 39;
  }
  if ( box == 39 ) {
    lcd.clear();
    lcd.print("Auserdem zeigt");
    lcd.setCursor(0, 1);
    lcd.print("er dir den");
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
    lcd.print("Weg zur ");
    lcd.setCursor(0, 1);
    lcd.print("naechsten Burg");
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
    lcd.print("Du gehst");
    lcd.setCursor(0, 1);
    lcd.print("zur Burg");
    while (digitalRead(pinButton)) {
      delay(100);
    }
    while (!digitalRead(pinButton)) {
      delay(100);
    }
    box = 19;
  }
}
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
