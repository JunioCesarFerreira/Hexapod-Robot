/*
  Primeiro programa de testes projeto Hexapod.
  Objetivo:
           Desenvolver e testar as rotinas de movimento elementar, criação e parametrização
           dos PWMs e limiares de movimento das pernas.
  Descrição do PWM:
           Frequência 50Hz, periodo 20ms;
           Modulação do periodo de nível alto entre 480us e 2600us

  Desenvolvido por Junio Cesar Ferreira (jcf_ssp@hotmail.com)
  Data: 02/05/2014
*/

#include "conversores.h"
/*
// Lcd pinout settings
sbit LCD_RS at RB2_bit;
sbit LCD_EN at RB3_bit;
sbit LCD_D7 at RB7_bit;
sbit LCD_D6 at RB6_bit;
sbit LCD_D5 at RB5_bit;
sbit LCD_D4 at RB4_bit;

// Pin direction
sbit LCD_RS_Direction at TRISB2_bit;
sbit LCD_EN_Direction at TRISB3_bit;
sbit LCD_D7_Direction at TRISB7_bit;
sbit LCD_D6_Direction at TRISB6_bit;
sbit LCD_D5_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB4_bit;
*/
// Definições das saídas de PWM para Servos
#define S11 PORTB.F0
#define S12 PORTB.F1
#define S13 PORTB.F2

#define S21 PORTB.F3
#define S22 PORTB.F4
#define S23 PORTB.F5

#define S31 PORTC.F0
#define S32 PORTC.F1
#define S33 PORTC.F2

#define S41 PORTD.F0
#define S42 PORTD.F1
#define S43 PORTD.F2

#define S51 PORTD.F3
#define S52 PORTD.F4
#define S53 PORTD.F5

#define S61 PORTD.F6
#define S62 PORTD.F7
#define S63 PORTE.F0

#define SetAll   PORTB=PORTB;PORTC=0x07;PORTD=0xFF;S63=1
#define ClearAll PORTB=PORTB;PORTC=0;PORTD=0;S63=0

// Estruturas de controle para pernas
struct legs{
       unsigned short DT1; // coxia joint
       unsigned short DT2; // femur joint
       unsigned short DT3; // tibia joint
};
// Declaração de vetor com todas as pernas
struct legs leg[6];

#define Perna_Direita_frontal  leg[0]


// Bit auxliar do timer 0
bit the_end;                      // Em 0 periodo de nível baixo, 1 semi-periodo de nivel alto
unsigned short pwm_counter=0;       // Contador que modula a largura do PWM

void init_sis();                 // Prototipo de inicialização

// *****************************************************************************
// ********************** Rotina de Interrupção ********************************
// *****************************************************************************
void interrupt(){
     // PWM composto por temporizadores 0 e 1
     if (TMR0IF_bit){// Temporiza faixas continuas
        if (the_end){                    // Segunda interrupção pós periodo modulado
           SetAll;                       // Entra em periodo de nível alto
           pwm_counter=0;                // Limpa Contador do próximo
           the_end=0;                    // Abaixa flag de periodo de nível alto
           T0PS0_bit=0;                  // Prescaler = 1:2
           TMR0H=0xFA;                   // Set Timer 0 periodo ~468(us)
           TMR0L=0xFF;
           }else{
                 TMR0IE_bit=0;           // Desativa timer 0
                 TMR0ON_bit=0;
                 T0PS0_bit=1;            // Prescaler = 1:4
                 TMR0H=0x72;             // Set Timer 0 periodo ~17.4(ms)
                 TMR0L=0xFF;
                 TMR1ON_bit=1;           // Ativa timer 1
                 TMR1IE_bit=1;
                 the_end=1;              // Levanta flag
           }
           TMR0IF_bit=0;
     }
     if (TMR1IF_bit){// Temporiza faixa modulavel
        pwm_counter++;
        if (pwm_counter==0){            // Verifica fim de periodo de modulação de largura
           TMR1IE_bit=0;                // Desliga Timer 1
           TMR1ON_bit=0;
           TMR1H=255;                   // Set Timer 1 periodo ~1.84(us) + Tempo de instruções internas
           TMR1L=220;
           TMR1IF_bit=0;                // Limpa flag Interrupt timer 1
           ClearAll;
           TMR0ON_bit=1;                // Ativa timer 0 * Obs.: the_end=1 => Inicio de periodo nível baixo obrigatório.
           TMR0IE_bit=1;
           return;
           }
        // Modulação das larguras
        if (leg[0].DT1==pwm_counter) S11=0;
        if (leg[0].DT2==pwm_counter) S12=0;
        if (leg[0].DT3==pwm_counter) S13=0;
        
        if (leg[1].DT1==pwm_counter) S21=0;
        if (leg[1].DT2==pwm_counter) S22=0;
        if (leg[1].DT3==pwm_counter) S23=0;
        
        if (leg[2].DT1==pwm_counter) S31=0;
        if (leg[2].DT2==pwm_counter) S32=0;
        if (leg[2].DT3==pwm_counter) S33=0;
        
        if (leg[3].DT1==pwm_counter) S41=0;
        if (leg[3].DT2==pwm_counter) S42=0;
        if (leg[3].DT3==pwm_counter) S43=0;
        
        if (leg[4].DT1==pwm_counter) S51=0;
        if (leg[4].DT2==pwm_counter) S52=0;
        if (leg[4].DT3==pwm_counter) S53=0;
        
        if (leg[5].DT1==pwm_counter) S61=0;
        if (leg[5].DT2==pwm_counter) S62=0;
        if (leg[5].DT3==pwm_counter) S63=0;

        // Reconfigura timer 1
        TMR1H=255;                      // Set Timer 1 periodo ~1.84(us) + Tempo de instruções internas
        TMR1L=220;
        TMR1IF_bit=0;
     }
}

const char table1[10][6][3]={
           // Leg[0]     Leg[1] Leg[2] Leg[3] Leg[4] Leg[5]
           // 1 2 3
           {{0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}},
           {{0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}},
           {{0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}},
           {{0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}},
           {{0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}},
           {{0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}},
           {{0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}},
           {{0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}},
           {{0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}},
           {{0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}, {0, 128, 64}}
};

void pause(unsigned short time){
     unsigned short Contador;
     for (Contador=0; Contador<time; Contador++){
         Delay_ms(10);
     }
}

void tab1_run(unsigned short Tempo){
     #define Length 10
     unsigned short index;
     for (index=0;index<Length;index++){
         leg[0].DT1 = table1[index][0][0];
         leg[0].DT2 = table1[index][0][1];
         leg[0].DT3 = table1[index][0][2];
         
         leg[1].DT1 = table1[index][1][0];
         leg[1].DT2 = table1[index][1][1];
         leg[1].DT3 = table1[index][1][2];
         
         leg[2].DT1 = table1[index][2][0];
         leg[2].DT2 = table1[index][2][1];
         leg[2].DT3 = table1[index][2][2];
         
         leg[3].DT1 = table1[index][3][0];
         leg[3].DT2 = table1[index][3][1];
         leg[3].DT3 = table1[index][3][2];
         
         leg[4].DT1 = table1[index][4][0];
         leg[4].DT2 = table1[index][4][1];
         leg[4].DT3 = table1[index][4][2];
         
         leg[5].DT1 = table1[index][5][0];
         leg[5].DT2 = table1[index][5][1];
         leg[5].DT3 = table1[index][5][2];
         
         pause(Tempo);
     }
}

// *****************************************************************************
// ***********************  Rotina de Principal  *******************************
// *****************************************************************************
void main() {
     unsigned short Opt;
     bit command;
     init_sis(); // Rotina de inicialização do sistema
     command=0;
     do{
       // Controle...
       if (command){
          switch (Opt){
                 case 0x01:
                      tab1_run(10);
                      break;
                 default:
                         break;
          }
       }
     
     }while(1);
}



// *****************************************************************************
// ********************** Rotina de Inicialização ******************************
// *****************************************************************************
void init_sis(){
     unsigned short i;
//------------------- Configurações iniciais dos SFRs --------------------------
     ADCON1 = 0x0C;  // Configura PORTA
     CMCON  = 7;     // Desabilita comparadoress
     // Configura todo I/O como Output
     TRISA = 0x07;
     TRISB = 0;
     TRISC = 0;
     TRISD = 0;
     TRISE = 0;

     LATA = 0;
     LATB = 0;
     LATC = 0;
     LATD = 0;
     LATE = 0;

     PORTA = 0;
     PORTC = 0;
     PORTB = 0;
     PORTD = 0;
     PORTE = 0;

     UCON.B3 = 0;  // Desabilata USB
     UCFG.B3 = 1;
     HLVDEN_bit = 0;
     CVRCON = 0;

     //INTCON bits: GIE/GIEH PEIE/GIEL TMR0IE INT0IE RBIE TMR0IF INT0IF RBIF
     INTCON  = 0b11100000;                                                      // Cofigura chave geral de interrupções e INT0
     //INTCON2 bits: /RBPU INTEDG0 INTEDG1 INTEDG2 — TMR0IP — RBIP
     INTCON2 = 0b11110000;                                                      // Desabilita pull-ups, confg. INTEDGs rising edge
     //INTCON3 bits: INT2IP INT1IP — INT2IE INT1IE — INT2IF INT1IF
     INTCON3 = 0b01000000;

     // PIE1 bits: SPPIE(3) ADIE RCIE TXIE SSPIE CCP1IE TMR2IE TMR1IE
     PIE1 = 0b00000000;
     // PIE2 bits: OSCFIE CMIE USBIE EEIE BCLIE HLVDIE TMR3IE CCP2IE
     PIE2 = 0b00000000;

     // PIR1 bits: SPPIF(3) ADIF RCIF TXIF SSPIF CCP1IF TMR2IF TMR1IF
     PIR1 = 0;
     // PIR2 bits: OSCFIF CMIF USBIF EEIF BCLIF HLVDIF TMR3IF CCP2IF
     PIR2 = 0;

     // IPR1 bits: SPPIP(1) ADIP RCIP TXIP SSPIP CCP1IP TMR2IP TMR1IP
     IPR1 = 0b00000000;

     // IPR2 bits: OSCFIP CMIP USBIP EEIP BCLIP HLVDIP TMR3IP CCP2IP
     IPR2 = 0b00000000;

     // T0CON bits: TMR0ON T08BIT T0CS T0SE PSA T0PS2 T0PS1 T0PS0
     T0CON = 0b10000000;
     // T1CON bits: RD16 T1RUN T1CKPS1 T1CKPS0 T1OSCEN T1SYNC TMR1CS TMR1ON
     T1CON = 0b10000001;

     //Lcd_Init();
     //Lcd_Cmd(0x0C);Lcd_Cmd(1);

     // Inicializa servos -> Verificar posição inicial...
     for (i=0;i<6;i++){
         leg[i].DT1=128;
         leg[i].DT2=128;
         leg[i].DT3=128;
         }
}

/*      // Código de testes retirado do main em 30/06/15
        Lcd_Out(1,1,">\\Fase 1 Hexapod");
        Lcd_Out(2,1,"DT1:");
        Lcd_Out(3,1,"DT2:");
        Lcd_Out(4,1,"DT3:");

        aux2 = ADC_Read(0);
        leg[4].DT1=aux2>>2;
        conv_lcd(3,leg[4].DT1,2,5);
        Delay_us(100);
        aux2 = ADC_Read(1);
        leg[4].DT2=aux2>>2;
        conv_lcd(3,leg[4].DT2,3,5);
        Delay_us(100);
        aux2 = ADC_Read(2);
        leg[4].DT3=aux2>>2;
        conv_lcd(3,leg[4].DT3,4,5);
        Delay_us(100);
        */

