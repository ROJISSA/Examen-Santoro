#include "MKL25Z4.h"
#include "eval.h"
#include "Delay.h"
char puerto;
int i, contdig1 = 0, contdig2 = 0, displaySelect[2] = {0, 1};
int pinesEntrada[8], pinesSalida[4];
void init_eval(int que_pin_inicial, char port){
    puerto = port;
    SIM -> SCGC5 |= SIM_SCGC5_PORTA_MASK;
        for(i=0; i<sizeof(pinesEntrada); i++){
            int pinesEntrada[i]= que_pin_inicial + i;
            PORT(puerto) -> PCR[pinesEntrada[i]] = PORT_PC(puerto)_MUX(0);
        }
}
int leer_pines1(){
    for(i=0; i<(sizeof(pinesEntrada)/2); i++){
        estado = (PT(puerto) -> PDIR &(1(pinesEntrada[i])));
        contdig1 = (contdig1 * 10) + estado;  
    }
    if (contdig1 == 0){
        return = 0;
    }else if(contdig1 == 1){
        return = 1;
    }else if(contdig1 == 10){
        return = 2;
    }else if(contdig1 == 11){
        return = 3;
    }else if(contdig1 == 100){
        return = 4;
    }else if(contdig1 == 101){
        return = 5;
    }else if(contdig1 == 110){
        return = 6;
    }else if(contdig1 == 111){
        return = 7;
    }else if(contdig1 == 1000){
        return = 8;
    }else if(contdig1 == 1001){
        return = 9;
    }else if(contdig1 == 1010){
        return = 10;
    }else if(contdig1 == 1011){
        return = 11;
    }else if(contdig1 == 1100){
        return = 12;
    }else if(contdig1 == 1101){
        return = 13;
    }else if(contdig1 == 1110){
        return = 14;
    }else if(contdig1 == 1111){
        return = 15;
    }
    
}
int leer_pines2(){
    for(i=4; i<(sizeof(pinesEntrada)); i++){
        estado = (PT(puerto) -> PDIR &(1(pinesEntrada[i])));
        contdig2 = (contdig2 * 10) + estado;
    }
    if (contdig2 == 0){
        return = 0;
    }else if(contdig2 == 1){
        return = 1;
    }else if(contdig2 == 10){
        return = 2;
    }else if(contdig2 == 11){
        return = 3;
    }else if(contdig2 == 100){
        return = 4;
    }else if(contdig2 == 101){
        return = 5;
    }else if(contdig2 == 110){
        return = 6;
    }else if(contdig2 == 111){
        return = 7;
    }else if(contdig2 == 1000){
        return = 8;
    }else if(contdig2 == 1001){
        return = 9;
    }else if(contdig2 == 1010){
        return = 10;
    }else if(contdig2 == 1011){
        return = 11;
    }else if(contdig2 == 1100){
        return = 12;
    }else if(contdig2 == 1101){
        return = 13;
    }else if(contdig2 == 1110){
        return = 14;
    }else if(contdig2 == 1111){
        return = 15;
    }
}
int calculos(int dig1, char sumaoresta, int dig2){
    if(sumaoresta == '+'){
        return dig1+dig2;
    }else if(sumaoresta == '-'){
        return dig1-dig2;
    }
}
int bcd(int c){
        if(c == 0){
            PT(puerto) -> PSOR = (0  << displaySelect[1]);
            PT(puerto) -> PSOR = (1u << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[3]);
            PT(puerto) -> PSOR = (0  << pinesSalida[4]);
        }
        if(c == 1){
            PT(puerto) -> PSOR = (0  << displaySelect[1]);
            PT(puerto) -> PSOR = (1u << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[3]);
            PT(puerto) -> PSOR = (1u << pinesSalida[4]);
        }
        if(c == 2){
            PT(puerto) -> PSOR = (0  << displaySelect[1]);
            PT(puerto) -> PSOR = (1u << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[3]);
            PT(puerto) -> PSOR = (0  << pinesSalida[4]);
        }
        if(c == 3){
            PT(puerto) -> PSOR = (0  << displaySelect[1]);
            PT(puerto) -> PSOR = (1u << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[3]);
            PT(puerto) -> PSOR = (1u << pinesSalida[4]);
        }
        if(c == 4){
            PT(puerto) -> PSOR = (0  << displaySelect[1]);
            PT(puerto) -> PSOR = (1u << displaySelect[2]);
            PT(puerto) -> PSOR = (0 << pinesSalida[1]);
            PT(puerto) -> PSOR = (1u << pinesSalida[2]);
            PT(puerto) -> PSOR = (0 << pinesSalida[3]);
            PT(puerto) -> PSOR = (0 << pinesSalida[4]);
        }
        if(c == 5){
            PT(puerto) -> PSOR = (0  << displaySelect[1]);
            PT(puerto) -> PSOR = (1u << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (1u << pinesSalida[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[3]);
            PT(puerto) -> PSOR = (1u << pinesSalida[4]);
        }
        if(c == 6){
            PT(puerto) -> PSOR = (0  << displaySelect[1]);
            PT(puerto) -> PSOR = (1u << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (1u << pinesSalida[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[3]);
            PT(puerto) -> PSOR = (0  << pinesSalida[4]);
        }
        if(c == 7){
            PT(puerto) -> PSOR = (0  << displaySelect[1]);
            PT(puerto) -> PSOR = (1u << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (1u << pinesSalida[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[3]);
            PT(puerto) -> PSOR = (1u << pinesSalida[4]);
        }
        if(c == 8){
            PT(puerto) -> PSOR = (0  << displaySelect[1]);
            PT(puerto) -> PSOR = (1u << displaySelect[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[3]);
            PT(puerto) -> PSOR = (0  << pinesSalida[4]);
        }
        if(c == 9){
            PT(puerto) -> PSOR = (0  << displaySelect[1]);
            PT(puerto) -> PSOR = (1u << displaySelect[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[1]);
            PT(puerto) -> PSOR = (0 << pinesSalida[2]);
            PT(puerto) -> PSOR = (0 << pinesSalida[3]);
            PT(puerto) -> PSOR = (1u << pinesSalida[4]);
        }
        if(c == 10){
            while(1){
                PT(puerto)-> PSOR = (1u << displaySelect[1]);
                PT(puerto) -> PSOR = (0  << displaySelect[2]);
                PT(puerto) -> PSOR = (0  << pinesSalida[1]);
                PT(puerto) -> PSOR = (0  << pinesSalida[2]);
                PT(puerto) -> PSOR = (0  << pinesSalida[3]);
                PT(puerto) -> PSOR = (1u << pinesSalida[4]);
                delay_ms(30);
                PT(puerto) -> PSOR = (0  << displaySelect[1]);
                PT(puerto) -> PSOR = (1u << displaySelect[2]);
                PT(puerto) -> PSOR = (1u << pinesSalida[1]);
                PT(puerto) -> PSOR = (0  << pinesSalida[2]);
                PT(puerto) -> PSOR = (1u << pinesSalida[3]);
                PT(puerto) -> PSOR = (0  << pinesSalida[4]);
            }
        }
        if(c == 11){
            while(1){
                PT(puerto) -> PSOR = (1u << displaySelect[1]);
                PT(puerto) -> PSOR = (0  << displaySelect[2]);
                PT(puerto) -> PSOR = (0  << pinesSalida[1]);
                PT(puerto) -> PSOR = (0  << pinesSalida[2]);
                PT(puerto) -> PSOR = (0  << pinesSalida[3]);
                PT(puerto) -> PSOR = (1u << pinesSalida[4]);
                delay_ms(30);
                PT(puerto) -> PSOR = (0  << displaySelect[1]);
                PT(puerto) -> PSOR = (1u << displaySelect[2]);
                PT(puerto) -> PSOR = (1u << pinesSalida[1]);
                PT(puerto) -> PSOR = (0  << pinesSalida[2]);
                PT(puerto) -> PSOR = (1u << pinesSalida[3]);
                PT(puerto) -> PSOR = (1u << pinesSalida[4]);
            }
        }
        if(c == 12){
            while(1){
                PT(puerto) -> PSOR = (1u << displaySelect[1]);
                PT(puerto) -> PSOR = (0  << displaySelect[2]);
                PT(puerto) -> PSOR = (0  << pinesSalida[1]);
                PT(puerto) -> PSOR = (0  << pinesSalida[2]);
                PT(puerto) -> PSOR = (0  << pinesSalida[3]);
                PT(puerto) -> PSOR = (1u << pinesSalida[4]);
                delay_ms(30);
                PT(puerto) -> PSOR = (0  << displaySelect[1]);
                PT(puerto) -> PSOR = (1u << displaySelect[2]);
                PT(puerto) -> PSOR = (1u << pinesSalida[1]);
                PT(puerto) -> PSOR = (1u << pinesSalida[2]);
                PT(puerto) -> PSOR = (0  << pinesSalida[3]);
                PT(puerto) -> PSOR = (0  << pinesSalida[4]);
            }
        }
        if(c == 13){
            while(1){
                PT(puerto) -> PSOR = (1u << displaySelect[1]);
                PT(puerto) -> PSOR = (0  << displaySelect[2]);
                PT(puerto) -> PSOR = (0  << pinesSalida[1]);
                PT(puerto) -> PSOR = (0  << pinesSalida[2]);
                PT(puerto) -> PSOR = (0  << pinesSalida[3]);
                PT(puerto) -> PSOR = (1u << pinesSalida[4]);
                delay_ms(30);
                PT(puerto) -> PSOR = (0  << displaySelect[1]);
                PT(puerto) -> PSOR = (1u << displaySelect[2]);
                PT(puerto) -> PSOR = (1u << pinesSalida[1]);
                PT(puerto) -> PSOR = (1u << pinesSalida[2]);
                PT(puerto) -> PSOR = (0  << pinesSalida[3]);
                PT(puerto) -> PSOR = (1u << pinesSalida[4]);
            }
        }
        if(c == 14){
            while(1){
                PT(puerto) -> PSOR = (1u << displaySelect[1]);
                PT(puerto) -> PSOR = (0  << displaySelect[2]);
                PT(puerto) -> PSOR = (0  << pinesSalida[1]);
                PT(puerto) -> PSOR = (0  << pinesSalida[2]);
                PT(puerto) -> PSOR = (0  << pinesSalida[3]);
                PT(puerto) -> PSOR = (1u << pinesSalida[4]);
                delay_ms(30);
                PT(puerto) -> PSOR = (0  << displaySelect[1]);
                PT(puerto) -> PSOR = (1u << displaySelect[2]);
                PT(puerto) -> PSOR = (1u << pinesSalida[1]);
                PT(puerto) -> PSOR = (1u << pinesSalida[2]);
                PT(puerto) -> PSOR = (1u << pinesSalida[3]);
                PT(puerto) -> PSOR = (0  << pinesSalida[4]);
            }
        }
        if(c == 15){
            while(1){
                PT(puerto) -> PSOR = (1u << displaySelect[1]);
                PT(puerto) -> PSOR = (0  << displaySelect[2]);
                PT(puerto) -> PSOR = (0  << pinesSalida[1]);
                PT(puerto) -> PSOR = (0  << pinesSalida[2]);
                PT(puerto) -> PSOR = (0  << pinesSalida[3]);
                PT(puerto) -> PSOR = (1u << pinesSalida[4]);
                delay_ms(30);
                PT(puerto) -> PSOR = (0  << displaySelect[1]);
                PT(puerto) -> PSOR = (1u << displaySelect[2]);
                PT(puerto) -> PSOR = (1u << pinesSalida[1]);
                PT(puerto) -> PSOR = (1u << pinesSalida[2]);
                PT(puerto) -> PSOR = (1u << pinesSalida[3]);
                PT(puerto) -> PSOR = (1u << pinesSalida[4]);
            }
        }
    if(c == 16){
        while(1){
            PT(puerto) -> PSOR = (1u << displaySelect[1]);
            PT(puerto) -> PSOR = (0  << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[3]);
            PT(puerto) -> PSOR = (1u << pinesSalida[4]);
            delay_ms(30);
            PT(puerto) -> PSOR = (0  << displaySelect[1]);
            PT(puerto) -> PSOR = (1u << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (1u << pinesSalida[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[3]);
            PT(puerto) -> PSOR = (0  << pinesSalida[4]);
        }
        
    }
    if(c == 17){
        while(1){
            PT(puerto) -> PSOR = (1u << displaySelect[1]);
            PT(puerto) -> PSOR = (0  << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[3]);
            PT(puerto) -> PSOR = (1u << pinesSalida[4]);
            delay_ms(30);
            PT(puerto) -> PSOR = (0  << displaySelect[1]);
            PT(puerto) -> PSOR = (1u << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (1u << pinesSalida[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[3]);
            PT(puerto) -> PSOR = (1u << pinesSalida[4]);
        }
    }
    if(c == 18){
        while(1){
            PT(puerto) -> PSOR = (1u << displaySelect[1]);
            PT(puerto) -> PSOR = (0  << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[3]);
            PT(puerto) -> PSOR = (1u << pinesSalida[4]);
            delay_ms(30);
            PT(puerto) -> PSOR = (0  << displaySelect[1]);
            PT(puerto) -> PSOR = (1u << displaySelect[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[3]);
            PT(puerto) -> PSOR = (0  << pinesSalida[4]);
        }
    }
    if(c == 19){
        while(1){
            PT(puerto) -> PSOR = (1u << displaySelect[1]);
            PT(puerto) -> PSOR = (0  << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[3]);
            PT(puerto) -> PSOR = (1u << pinesSalida[4]);
            delay_ms(30);
            PT(puerto) -> PSOR = (0  << displaySelect[1]);
            PT(puerto) -> PSOR = (1u << displaySelect[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[3]);
            PT(puerto) -> PSOR = (0  << pinesSalida[4]);
        }
    }
    if(c == 20){
        while(1){
            PT(puerto) -> PSOR = (1u << displaySelect[1]);
            PT(puerto) -> PSOR = (0  << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[3]);
            PT(puerto) -> PSOR = (0  << pinesSalida[4]);
            delay_ms(30);
            PT(puerto) -> PSOR = (0  << displaySelect[1]);
            PT(puerto) -> PSOR = (1u << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[3]);
            PT(puerto) -> PSOR = (0  << pinesSalida[4]);
        }
    }
    if(c == 21){
        while(1){
            PT(puerto) -> PSOR = (1u << displaySelect[1]);
            PT(puerto) -> PSOR = (0  << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[3]);
            PT(puerto) -> PSOR = (0  << pinesSalida[4]);
            delay_ms(30);
            PT(puerto) -> PSOR = (0  << displaySelect[1]);
            PT(puerto) -> PSOR = (1u << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[3]);
            PT(puerto) -> PSOR = (1u << pinesSalida[4]);
        }
    }
    if(c == 22){
        while(1){
            PT(puerto) -> PSOR = (1u << displaySelect[1]);
            PT(puerto) -> PSOR = (0  << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[3]);
            PT(puerto) -> PSOR = (0  << pinesSalida[4]);
            delay_ms(30);
            PT(puerto) -> PSOR = (0  << displaySelect[1]);
            PT(puerto) -> PSOR = (1u << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[3]);
            PT(puerto) -> PSOR = (0  << pinesSalida[4]);
        }
    }
    if(c == 23){
        while(1){
            PT(puerto) -> PSOR = (1u << displaySelect[1]);
            PT(puerto) -> PSOR = (0  << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[3]);
            PT(puerto) -> PSOR = (0  << pinesSalida[4]);
            delay_ms(30);
            PT(puerto) -> PSOR = (0  << displaySelect[1]);
            PT(puerto) -> PSOR = (1u << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[3]);
            PT(puerto) -> PSOR = (1u << pinesSalida[4]);
        }
    }
    if(c == 24){
        while(1){
            PT(puerto) -> PSOR = (1u << displaySelect[1]);
            PT(puerto) -> PSOR = (0  << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[3]);
            PT(puerto) -> PSOR = (0  << pinesSalida[4]);
            delay_ms(30);
            PT(puerto) -> PSOR = (0  << displaySelect[1]);
            PT(puerto) -> PSOR = (1u << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (1u << pinesSalida[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[3]);
            PT(puerto) -> PSOR = (0  << pinesSalida[4]);
        }
    }
    if(c == 25){
        while(1){
            PT(puerto) -> PSOR = (1u << displaySelect[1]);
            PT(puerto) -> PSOR = (0  << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[3]);
            PT(puerto) -> PSOR = (0  << pinesSalida[4]);
            delay_ms(30);
            PT(puerto) -> PSOR = (0  << displaySelect[1]);
            PT(puerto) -> PSOR = (1u << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (1u << pinesSalida[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[3]);
            PT(puerto) -> PSOR = (1u << pinesSalida[4]);
        }
    }
    if(c == 26){
        while(1){
            PT(puerto) -> PSOR = (1u << displaySelect[1]);
            PT(puerto) -> PSOR = (0  << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[3]);
            PT(puerto) -> PSOR = (0  << pinesSalida[4]);
            delay_ms(30);
            PT(puerto) -> PSOR = (0  << displaySelect[1]);
            PT(puerto) -> PSOR = (1u << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (1u << pinesSalida[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[3]);
            PT(puerto) -> PSOR = (0  << pinesSalida[4]);
        }
    }
    if(c == 27){
        while(1){
            PT(puerto) -> PSOR = (1u << displaySelect[1]);
            PT(puerto) -> PSOR = (0  << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[3]);
            PT(puerto) -> PSOR = (0  << pinesSalida[4]);
            delay_ms(30);
            PT(puerto) -> PSOR = (0  << displaySelect[1]);
            PT(puerto) -> PSOR = (1u << displaySelect[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[1]);
            PT(puerto) -> PSOR = (1u << pinesSalida[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[3]);
            PT(puerto) -> PSOR = (1u << pinesSalida[4]);
        }
    }
    if(c == 28){
        while(1){
            PT(puerto) -> PSOR = (1u << displaySelect[1]);
            PT(puerto) -> PSOR = (0  << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[3]);
            PT(puerto) -> PSOR = (0  << pinesSalida[4]);
            delay_ms(30);
            PT(puerto) -> PSOR = (0  << displaySelect[1]);
            PT(puerto) -> PSOR = (1u << displaySelect[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[3]);
            PT(puerto) -> PSOR = (0  << pinesSalida[4]);
        }
    }
    if(c == 29){
        while(1){
            PT(puerto) -> PSOR = (1u << displaySelect[1]);
            PT(puerto) -> PSOR = (0  << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[3]);
            PT(puerto) -> PSOR = (0  << pinesSalida[4]);
            delay_ms(30);
            PT(puerto) -> PSOR = (0  << displaySelect[1]);
            PT(puerto) -> PSOR = (1u << displaySelect[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[3]);
            PT(puerto) -> PSOR = (1u << pinesSalida[4]);
        }
    }
    if(c == 30){
        while(1){
            PT(puerto) -> PSOR = (1u << displaySelect[1]);
            PT(puerto) -> PSOR = (0  << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (1u << pinesSalida[3]);
            PT(puerto) -> PSOR = (1u << pinesSalida[4]);
            delay_ms(30);
            PT(puerto) -> PSOR = (0  << displaySelect[1]);
            PT(puerto) -> PSOR = (1u << displaySelect[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[1]);
            PT(puerto) -> PSOR = (0  << pinesSalida[2]);
            PT(puerto) -> PSOR = (0  << pinesSalida[3]);
            PT(puerto) -> PSOR = (0  << pinesSalida[4]);
        }
    }
}
