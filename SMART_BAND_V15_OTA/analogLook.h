int clockCenterX=31;
int clockCenterY=31;
void drawDisplay();
void drawMark(int);
void drawMin(int);
void drawHour(int, int);
void battery();

void analog_look(){
  Time1 = get_time();
  if(Time1 > 0)
      Time = Time1;
  hr = (Time % 86400L) / 3600 ;
  mint = (Time  % 3600) / 60;
  //if(counter % 10 == 0){
    tem = temp();
    pm25 = PM25();
    pm10 = PM10();
  //}
  

  drawDisplay();
  drawMin(mint);
  drawHour(hr, mint);
  led.setCursor(67,10);
  led.print(tem);
  led.print("'C");
  led.setCursor(67,24);
  led.print("PM2.5= ");
  led.print(pm25);
  led.setCursor(67,33);
  led.print("PM10= ");
  led.print(pm10);
  weather();
  battery();
  led.display();
}

void drawDisplay()
{
  displayy();
  // Draw Clockface
  for (int i=0; i<2; i++)
  {
    led.drawCircle(clockCenterX, clockCenterY, 31-i, SSD1306_WHITE);
  }
  for (int i=0; i<3; i++)
  {
    led.drawCircle(clockCenterX, clockCenterY, i, SSD1306_WHITE);
  }
  
  // Draw a small mark for every hour
  for (int i=0; i<12; i++)
  {
    drawMark(i);
  }  
}

void drawMark(int h)
{
  float x1, y1, x2, y2;
  
  h=h*30;
  h=h+270;
  
  x1=29*cos(h*0.0175);
  y1=29*sin(h*0.0175);
  x2=26*cos(h*0.0175);
  y2=26*sin(h*0.0175);
  
  led.drawLine(x1+clockCenterX, y1+clockCenterY, x2+clockCenterX, y2+clockCenterY, SSD1306_WHITE);
}

/*void drawSec(int s)
{
  float x1, y1, x2, y2;

  s=s*6;
  s=s+270;
  
  x1=29*cos(s*0.0175);
  y1=29*sin(s*0.0175);
  x2=26*cos(s*0.0175);
  y2=26*sin(s*0.0175);
  
  if ((s % 5) == 0)
    led.clrLine(x1+clockCenterX, y1+clockCenterY, x2+clockCenterX, y2+clockCenterY, SSD1306_WHITE);
  else
    led.drawLine(x1+clockCenterX, y1+clockCenterY, x2+clockCenterX, y2+clockCenterY, SSD1306_WHITE);
}*/

void drawMin(int m)
{
  float x1, y1, x2, y2, x3, y3, x4, y4;

  m=m*6;
  m=m+270;
  
  x1=25*cos(m*0.0175);
  y1=25*sin(m*0.0175);
  x2=3*cos(m*0.0175);
  y2=3*sin(m*0.0175);
  x3=10*cos((m+8)*0.0175);
  y3=10*sin((m+8)*0.0175);
  x4=10*cos((m-8)*0.0175);
  y4=10*sin((m-8)*0.0175);
  
  led.drawLine(x1+clockCenterX, y1+clockCenterY, x3+clockCenterX, y3+clockCenterY, SSD1306_WHITE);
  led.drawLine(x3+clockCenterX, y3+clockCenterY, x2+clockCenterX, y2+clockCenterY, SSD1306_WHITE);
  led.drawLine(x2+clockCenterX, y2+clockCenterY, x4+clockCenterX, y4+clockCenterY, SSD1306_WHITE);
  led.drawLine(x4+clockCenterX, y4+clockCenterY, x1+clockCenterX, y1+clockCenterY, SSD1306_WHITE);
}

void drawHour(int h, int m)
{
  float x1, y1, x2, y2, x3, y3, x4, y4;

  h=(h*30)+(m/2);
  h=h+270;
  
  x1=20*cos(h*0.0175);
  y1=20*sin(h*0.0175);
  x2=3*cos(h*0.0175);
  y2=3*sin(h*0.0175);
  x3=8*cos((h+12)*0.0175);
  y3=8*sin((h+12)*0.0175);
  x4=8*cos((h-12)*0.0175);
  y4=8*sin((h-12)*0.0175);
  
  led.drawLine(x1+clockCenterX, y1+clockCenterY, x3+clockCenterX, y3+clockCenterY, SSD1306_WHITE);
  led.drawLine(x3+clockCenterX, y3+clockCenterY, x2+clockCenterX, y2+clockCenterY, SSD1306_WHITE);
  led.drawLine(x2+clockCenterX, y2+clockCenterY, x4+clockCenterX, y4+clockCenterY, SSD1306_WHITE);
  led.drawLine(x4+clockCenterX, y4+clockCenterY, x1+clockCenterX, y1+clockCenterY, SSD1306_WHITE);
}
