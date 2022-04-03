int main(){

  DDRB = 0b00001110; //Definindo PB1(led amarelo), PB2(led azul) e PB3(led verde) como saídas
  PORTB &= ~((1 << PB1) & (1 << PB2) & (1 << PB3)); //Definindo PB1, PB2 e PB3 começando desligados
  PORTD = 0b00001110; //Definindo PD1, PD2 e PD3 com pull-up ativo
  int P_total = 0; //Usado para definir o limite máximo de HP usado no sistema
  bool bot1 = false; //Verifica se o botão 1 foi apertado
  bool bot2 = false; //Verifica se o botão 2 foi apertado
  bool bot3 = false; //Verifica se o botão 3 foi apertado
  bool ok = false; //Variável auxiliar usada para garantir que o botão 1 será desligado primeiro

  while(1){

    //Botão 1 pressionado
    if((PIND & (1 << PD1)) == 0){
      
      if(bot1){
        
        PORTB &= ~(1 << PB1);
        _delay_ms(200);
        P_total -= 30;
        bot1 = false;
      }

      else{
        PORTB |= (1 << PB1);
        _delay_ms(200);
        P_total += 30;
        bot1 = true;
      }
    }

    //Botão 2 pressionado
    if((PIND & (1 << PD2)) == 0){

      if(bot2){
        
        PORTB &= ~(1 << PB2);
        _delay_ms(200);
        P_total -= 50;
        bot2 = false;
      } 

       else{
        PORTB |= (1 << PB2);
        _delay_ms(200);
        P_total += 50;
        bot2 = true;
        ok = true;
      }
    }

    //Botão 3 pressionado
    if((PIND & (1 << PD3)) == 0){
      if(bot3){
        
        PORTB &= ~(1 << PB3);
        _delay_ms(200);
        P_total -= 70;
        bot3 = false;
      }  

      else{
        PORTB |= (1 << PB3);
        _delay_ms(200);
        P_total += 70;
        bot3 = true;
      }   
    }

    //Verifica se o botão 1 foi apertado
    if(P_total > 90 && ok == false){
      
      PORTB &= ~(1 << PB1);
      P_total -= 30;
      bot1 = false;
      ok = true;
      _delay_ms(200);
   }

   //Verifica se o led 1 foi desligado. Se sim, desliga o led 2
   if(P_total > 90 && ok == true){
      
      PORTB &= ~(1 << PB2);
      P_total -= 50;
      _delay_ms(200);
      bot2 = false;
      ok = false;
    }

    if(P_total > 90 && ok == false){
      
      PORTB &= ~(1 << PB1);
      P_total -= 30;
      _delay_ms(200);
      bot2 = false;
      ok = false;
    }
  } 
}
