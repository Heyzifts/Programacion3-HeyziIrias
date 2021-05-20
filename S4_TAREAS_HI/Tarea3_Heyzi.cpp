//CLASE LED CODIGO REUTILIZADO
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

//CLASE PARA LOS PULSADORES
class Pulsadores{  
public:  
  Pulsadores(int _pin)
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

//Posicion pin de Luces
Led LuzRojo(4);
Led LuzVerde(5);

//Posicion pin Pulsadores Incrementar y Decrementar
Pulsadores PulsadordeIncrementar(2);
Pulsadores PulsadordeDisminuir(3);

// DECLARACION DE VARIABLE CONTADOR QUE NOS AYUDARA A INCREMENTAR Y DECREMENTAR
byte Cont = 0;


void setup()
{
   Serial.begin(9600);
}

void loop()
{
  //LO QUE SALDRA EN EL MONITOR LO DECLARAMOS ASI:
  Serial.println(Cont);  
  
  //UTILIZAMOS IF PARA INDICAR LO QUE PASARA:
  if(PulsadordeIncrementar.GetEstado() == HIGH)
  {
    delay(1000);
    Cont++;
    LuzVerde.encenderApagar(1);
    LuzVerde.encenderApagar(0);
  }
  
  if(PulsadordeDisminuir.GetEstado() == HIGH)
  {
    delay(1000);
   Cont--;
   LuzRojo.encenderApagar(1);
   LuzRojo.encenderApagar(0);
  }
}
