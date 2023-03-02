#include <LiquidCrystal_I2C.h>
int menu = 1;
int saniye = 0;
int dakika = 0;
int saat = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Bu kodu kullanırken ekranda yazı çıkmaz ise 0x27 yerine 0x3f yazınız !!
void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("GITHUB SAYAC");
  lcd.setCursor(0, 1);
  lcd.print("ARDUNIO SAYAC");
  delay(5000);
  lcd.clear();
  Serial.begin(9600);
}

void loop() {
  /*
  Serial.print(menu);
  Serial.print(" ");
  Serial.print(saniye);
  Serial.println("");
  */

  switch (menu) {
    case 1:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Total Sure");
      lcd.setCursor(0, 1);
      lcd.print(saat);
      lcd.print("h:");
      lcd.print(dakika);
      lcd.print("m:");
      lcd.print(saniye);
      lcd.print("s");
      lcd.setCursor(14, 0);
      lcd.print("M1");
      saniye = saniye + 1;
      if (saniye % 5 == 0)
        menu = menu + 1;
      delay(1000);
      break;

    case 2:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Sicaklik:");
      lcd.setCursor(0, 1);
      lcd.print(saat);
      lcd.print("h:");
      lcd.print(dakika);
      lcd.print("m:");
      lcd.print(saniye);
      lcd.print("s");
      lcd.setCursor(14, 0);
      lcd.print("M2");
      saniye = saniye + 1;
      if (saniye % 5 == 0)
        menu = menu + 1;
      delay(1000);
      break;

    default:
      menu = 1;

      if (saniye == 60) {
        dakika = dakika + 1;
        saniye = 0;
        if (dakika == 60) {
          saat = saat + 1;
          dakika = 0;
        }
      }
  }

  lcd.clear();
}
