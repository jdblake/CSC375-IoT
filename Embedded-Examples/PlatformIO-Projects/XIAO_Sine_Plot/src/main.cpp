/*
** Program to display a rotating Sine wave on the XIAO expansion display
*/

#include <Arduino.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define GRAPH_HEIGHT 45
#define GRAPH_WIDTH 120

#define X_ORIGIN 4
#define Y_ORIGIN 60

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int ox , oy ;

void drawAxes() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE, SSD1306_BLACK);
  display.setCursor(35, 4);
  display.println("Sine Plot");
  display.drawFastHLine(X_ORIGIN, Y_ORIGIN, GRAPH_WIDTH, SSD1306_WHITE);
  display.drawFastVLine(X_ORIGIN, Y_ORIGIN - GRAPH_HEIGHT, GRAPH_HEIGHT, SSD1306_WHITE);
  display.display();
}

void drawPoint(int x, double y) {
  int cur_x =  x * GRAPH_WIDTH / 100 + X_ORIGIN;
  int cur_y =  (int)(Y_ORIGIN - (y + 1) * GRAPH_HEIGHT / 2);
  if (x != 0)
    display.drawLine(ox, oy, cur_x, cur_y, SSD1306_WHITE);
  ox = cur_x;
  oy = cur_y;
}

void setup() {

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  
  drawAxes();

  for (int i = 0; i < 100; i++) {
    double v = sin(i/10.0);
    drawPoint(i,v);
  }

  display.display();

}

void loop(void) {

}