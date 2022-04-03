#define temperatura 0b00000010 //PD1
#define pressao 0b00000100 //PD2
#define nivel 0b00001000 // PD3
#define peso 0b00010000 //PD4 

#define LED 0b00000100 //PB2

int temp = PIND & temperatura;
int niv = PIND & nivel;
int ps = PIND & peso;
int pres = PIND & pressao;

int main(void) {
  DDRB |= LED; //Indicando que PD6 será nossa saída do sistema(LED)
  PORTB &= ~(LED); //Indicando que nosso PD6 será saída(LED)
  DDRD = 0b00011110; //Indicando as saídas de pressão, nível, peso e temperatura
  PORTD=0b11100001; //Habilitando pull up na entrada PD1
  
  while (1) {
    if(temp==1){
      PINB |= LED;
      _delay_ms(500);
      PINB &= ~(LED);
      Serial.print("Teste");
    }



  }
}
