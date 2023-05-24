double dewPoint(double celsius, double humidity)      //calculo del punto de rocio
{
        double A0= 373.15/(273.15 + celsius);
        double SUM = -7.90298 * (A0-1);
        SUM += 5.02808 * log10(A0);
        SUM += -1.3816e-7 * (pow(10, (11.344*(1-1/A0)))-1) ;
        SUM += 8.1328e-3 * (pow(10,(-3.49149*(A0-1)))-1) ;
        SUM += log10(1013.246);
        double VP = pow(10, SUM-3) * humidity;
        double T = log(VP/0.61078);   // temp var
        return (241.88 * T) / (17.558-T);
}

double dewPointFast(double celsius, double humidity)
{
        double a = 17.271;
        double b = 237.7;
        double temp = (a * celsius) / (b + celsius) + log(humidity/100);
        double Td = (b * temp) / (a - temp);
        return Td;
}

#include <DHT.h>
#include <LiquidCrystal.h>



#define DHTPIN 13
#define DHTTYPE DHT11

LiquidCrystal lcd(6,7,9,10,11,12);

int count=0;

DHT dht(DHTPIN, DHTTYPE);

String respuesta;
void setup()
{
  // set up the LCD's number of columns and rows:
  Serial.begin(9600);
  Serial.println("Inicializando el sensor: DHT11");
  Serial.println("Lectura de humedad y temperatura y postprocesado");
  Serial.println("Daniel Velasco");
  
  lcd.begin(16,2);
  dht.begin();
  
  lcd.setCursor(0,0);
  lcd.print(" Inicializando ");
  lcd.setCursor(0,1);
  lcd.print(" Velasco ");
  
  Serial.println();
  Serial.println("Numero medida,Humedad (%),Temperatura (ºC),Punto de rocio (ºC),Sensacion termica (ºC)");
  delay(2000);
}

void loop()
{
  lcd.clear();

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float hic = dht.computeHeatIndex(t, h, false);

  

  Serial.print(count);
  Serial.print(','); 
  Serial.print(h);
  Serial.print(',');
  Serial.print(t);
  Serial.print(',');
  Serial.print((float)dewPoint(t,h), 2);
  Serial.print(',');
  Serial.print(hic);

  Serial.print('\n');

  lcd.setCursor(0,0);
  lcd.print("Hum  (%) ");
  lcd.print(h);

  lcd.setCursor(0,1);
  lcd.print("Temp (C) ");
  lcd.print(t);

  count=count+1;
  delay(6000);   //una muestra por minuto

}
