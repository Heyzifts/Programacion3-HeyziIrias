class Led{  
public:    
  Led(int _pin){
    pin=_pin;
    pinMode(pin,OUTPUT);
  }
  
  void encenderApagar(bool tipo){
      if(tipo){
      	digitalWrite(pin, HIGH);
      }else{
      	digitalWrite(pin, LOW);
      }
  }
  
  private:
  	int pin;
};


class Pulsador{  
public:  
  Pulsador(int _pin)
  {
    pin=_pin;
    pinMode(pin,INPUT);
  }
  
  int GetEstado()
  {    
    return digitalRead(pin);
  }
  
  private:
  	int pin;
};


class TanqueDeAgua
{
  public:  
  TanqueDeAgua(int _NivelMin, int _NivelMax, int _NivelAct)
  {    
    NivelMinimo = _NivelMin;
    NivelMaximo = _NivelMax;
    NivelActual = _NivelAct;
  }
  
  void SetearNivelMinimo(int nivel)
  {
    NivelMinimo = nivel;
  }
  
  void SetearNivelMaximo(int nivel)
  {
    NivelMaximo = nivel;
  }
  
  int ObtenerNivelMinimo()
  {
    return NivelMinimo;
  }
  
  int ObtenerNivelMaximo()
  {
    return NivelMaximo;
  }
  
  int ObtenerNivelActual()
  {
    return NivelActual;
  }
  
  void IngresoDeAgua()
  {
    if(NivelActual >= NivelMaximo)
    {
      Serial.println("Ya a superado el nivel MAXIMO de agua! PRECAUCION!");
      Led Rojo(7);
      Rojo.encenderApagar(1);
      delay(200);
      Rojo.encenderApagar(0);
    }
    else
    {
      NivelActual++;      
    }    
  }
  
  void ConsumoDeAgua()
  {
    if(NivelActual <= NivelMinimo)
    {
      Serial.println("Ya supero el nivel MINIMO de agua! PRECAUCION!");
      Led Rojo(7);
      Rojo.encenderApagar(1);
      delay(200);
      Rojo.encenderApagar(0);
    }
    else
    {
      NivelActual--;      
    }
  }
  
  private:
  int NivelMinimo = 0;
  int NivelMaximo = 0;
  int NivelActual = 0;
};



Pulsador pulsadorVerNivelActual(6);
Pulsador pulDis(2);
Pulsador pulIncre(4);

int numero1;
int numero2;
String mensaje1 = "Cual es el nivel MINIMO de su tanque?";
String mensaje2 = "Cual es el nivel MAXIMO de su tanque?";

TanqueDeAgua Tanque(1,1,1);



void setup()
{
  Serial.begin(9600);  
  Tanque.SetearNivelMinimo(numero1);
  Tanque.SetearNivelMaximo(numero2);
 
 Serial.println("Porfavor esperar 8 segundos para la segunda pregunta.");
 Serial.println(mensaje1);
  while(Serial.available() != 0){}
     numero1 = Serial.read();
  delay(8000);
 if(numero1=='\n'){}
 else{
  
  Serial.println(mensaje2);
    numero2 = Serial.read();  
 } 
  
  /*
  Serial.println(mensaje1);
  while(Serial.available() != 0){}
     numero1 = Serial.read();
  		delay(10000);
  
  Serial.println(mensaje2);
  while(Serial.available() != 0){
  numero2 = Serial.read();
  }
   */ 
    
}

void loop()
{
  if(pulsadorVerNivelActual.GetEstado() == HIGH)
  {
    delay(200);
    Serial.print("NIVEL ACTUAL ES DE: ");
    Serial.println(Tanque.ObtenerNivelActual());
  }
  
  if(pulIncre.GetEstado() == HIGH)
  {
    delay(200);   
    Tanque.IngresoDeAgua();
  }
  
  if(pulDis.GetEstado() == HIGH)
  {
    delay(200);
    Tanque.ConsumoDeAgua();
  }
  
}
