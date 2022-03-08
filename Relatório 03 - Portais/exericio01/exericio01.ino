void setup(){
  DDRD=0b00001110; // Configurando as PD1,PD2 e PD3 como saída e PD4 como entrada
  DDRB=0b00001110; // Configurando as PB1,PB2 e PB3 como saída e PB4 como entrada

  
}
void loop(){
  PORTB=0x00001110; //Colocando nível lógico alto nas portas PB1,PB2 e PB3
}
