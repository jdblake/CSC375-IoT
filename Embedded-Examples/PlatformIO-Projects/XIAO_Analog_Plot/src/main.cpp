#include <Arduino.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LOGO16_GLCD_HEIGHT  16
#define LOGO16_GLCD_WIDTH   16

void DrawCGraph(Adafruit_SSD1306 &, double, double, double, double, double, double, double, double, double, double, double, double, double, String, boolean &);

// create what ever variables you need
double x, y;

// these are a required variables for the graphing functions
bool Redraw1 = true;
bool Redraw2 = true;
bool Redraw3 = true;
bool Redraw4 = true;
double ox , oy ;

void setup() {
  Serial.begin(115200);
  while (!Serial) ;

  pinMode(LED_BUILTIN, OUTPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
}

//unsigned long OldTime;
//unsigned long counter;

void loop(void) {
  double volt = analogRead(A0) * (3.3 / 1023.0);

  Serial.print("Volt: ");
  Serial.println(volt);

  DrawCGraph(display, x++, volt, 30, 50, 80, 40, 0, 100, 25, 0, 3.3, 10, 0, "Analog Reading", Redraw4);
  if (x > 100) {
    while (1) {}
  }

  delay(1000);

  }

/*
  &display to pass the display object, mainly used if multiple displays are connected to the MCU
  x = x data point
  y = y datapoint
  gx = x graph location (lower left)
  gy = y graph location (lower left)
  w = width of graph
  h = height of graph
  xlo = lower bound of x axis
  xhi = upper bound of x axis
  xinc = division of x axis (distance not count)
  ylo = lower bound of y axis
  yhi = upper bound of y asis
  yinc = division of y axis (distance not count)
  title = title of graph
  &redraw = flag to redraw graph on fist call only
*/

void DrawCGraph(Adafruit_SSD1306 &d, double x, double y, double gx, double gy, double w, double h, double xlo, double xhi, double xinc, double ylo, double yhi, double yinc, double dig, String title, boolean &Redraw) {
  double i;
  double v;
//  int rot, newrot;

  if (Redraw == true) {
    Redraw = false;
    d.setTextSize(1);
    d.setTextColor(SSD1306_WHITE, SSD1306_BLACK);
    d.setCursor(35, 4);
    d.println(title);
//    d.fillRect(0, 0,  127 , 16, SSD1306_WHITE);
//    d.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
//    d.setTextSize(1);
//    d.setCursor(2, 4);
//    d.println(title);
    ox = (x - xlo) * ( w) / (xhi - xlo) + gx;
    oy = (y - ylo) * (gy - h - gy) / (yhi - ylo) + gy;
    // draw y scale
    d.setTextSize(1);
    d.setTextColor(SSD1306_WHITE, SSD1306_BLACK);
    for ( i = ylo; i <= yhi; i += yinc) {
      // compute the transform
      // note my transform funcition is the same as the map function, except the map uses long and we need doubles
      v =  (i - ylo) * (gy - h - gy) / (yhi - ylo) + gy;
      if (i == ylo) {
        d.drawFastHLine(gx - 3, v, w + 3, SSD1306_WHITE);
      }
      else {
        d.drawFastHLine(gx - 3, v, 3, SSD1306_WHITE);
      }
      d.setCursor(gx - 27, v - 3);
      d.println(i, dig);
    }
    // draw x scale
    for (i = xlo; i <= xhi; i += xinc) {
      // compute the transform
      d.setTextSize(1);
      d.setTextColor(SSD1306_WHITE, SSD1306_BLACK);
      v =  (i - xlo) * ( w) / (xhi - xlo) + gx;
      if (i == 0) {
        d.drawFastVLine(v, gy - h, h + 3, SSD1306_WHITE);
      }
      else {
        d.drawFastVLine(v, gy, 3, SSD1306_WHITE);
      }
      d.setCursor(v, gy + 6);
      d.println(i, dig);
    }
  }

  // graph drawn now plot the data
  // the entire plotting code are these few lines...

  x =  (x - xlo) * ( w) / (xhi - xlo) + gx;
  y =  (y - ylo) * (gy - h - gy) / (yhi - ylo) + gy;
  d.drawLine(ox, oy, x, y, SSD1306_WHITE);
  d.drawLine(ox, oy - 1, x, y - 1, SSD1306_WHITE);
  ox = x;
  oy = y;

  // up until now print sends data to a buffer NOT the screen
  // this call sends the data to the screen
  d.display();

}