

void setup() {
  DDRB=0b00000110;
}
void loop() {
  // put your main code here, to run repeatedly:
  PORTB=0b00000010;
  _delay_ms(250);
  PORTB=0b00000000;
  _delay_ms(250);
  PORTB=0b00000100;
  _delay_ms(250);
  PORTB=0b00000000;
  _delay_ms(250);
}
