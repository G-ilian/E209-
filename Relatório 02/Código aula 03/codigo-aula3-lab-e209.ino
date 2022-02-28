#define led_vd_on PORTD |= 0b00000100
#define led_vd_off PORTD &= ~0b00000100
#define led_am_on PORTD |= 0b00001000
#define led_am_off PORTD &= ~0b00001000
#define led_vm_on PORTD |= 0b00010000
#define led_vm_off PORTD &= ~0b00010000

#define liberado 1
#define atencao 2
#define pare 3

unsigned char estado_atual = atencao;

int main(void) {
  DDRD |= 0b00011100; //configura pinos 2, 3 e 4 como saidas

  for (;;) {
    switch (estado_atual) {
      case liberado:
        led_vd_on;
        led_vm_off;
        led_am_off;
        
        estado_atual=atencao;
        _delay_ms(12000);
        break;
      case atencao:
        led_am_on;
        led_vm_off;
        led_vd_off;
        
        estado_atual=pare;
        _delay_ms(3000);
        break;
      case pare:
        led_vm_on;
        led_vd_off;
        led_am_off;
        
        estado_atual=liberado;
        _delay_ms(15000);
        break;

    }
  }
}
