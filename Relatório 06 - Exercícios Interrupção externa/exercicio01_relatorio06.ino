ISR(INT0_vect)
{
  PORTD^=(1<<PD7);//Desliga o PD7
  PORTD|=(1<<PD6);//Liga o PD6
  _delay_ms(200);//Delay de 200 ms
  PORTD&=~(1<<PD6);//Desliga o PD6
}

int main(void){
  DDRD |= (1 << PD7) | (1 << PD6); // Configura saida
  PORTD |= (1 << PD2); // Habilita resistor interno
  
  EICRA |= (1 << ISC01); // Configura interrupcao por transicao de descida
  EIMSK |= (1 << INT0); // Configura uso do INT0
  sei(); // Habilita bit de interrupcao global
  while(1){
    PORTD|=(1<<PD7);
    _delay_ms(2000);
    PORTD&=~(1<<PD7);
    _delay_ms(2000);
  }
}
