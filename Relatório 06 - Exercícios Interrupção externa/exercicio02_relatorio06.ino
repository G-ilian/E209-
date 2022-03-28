ISR(INT0_vect){
// Inverte PD7
PORTD ^= (1 << PD7);
}

ISR(INT1_vect){

PORTD ^= (1 << PD2); // Habilita resistor interno
EICRA ^= (1 << ISC01); // Configura interrupcao por transicao de descida
EIMSK ^= (1 << INT0); // Configura uso do INT0

}

int main (void) {
PORTD |= (1 << PD3); // Habilita resistor interno

EICRA |= (1 << ISC01); // Configura interrupcao por transicao de descida
EIMSK |= (1 << INT1); // Configura uso do INT0
DDRD |= (1 << PD7) | (1 << PD6); // Configura saida

sei(); // Habilita bit de interrupcao global

while(1){
PORTD ^= (1 << PD6);
_delay_ms(500);
}
}
