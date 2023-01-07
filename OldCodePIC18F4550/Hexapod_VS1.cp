#line 1 "F:/Documents/1 - Projetos/Hexapod/Firmware/Hexapod_VS1.c"
#line 1 "c:/mikroelektronika/mikroc pro for pic/include/conversores.h"
#line 17 "c:/mikroelektronika/mikroc pro for pic/include/conversores.h"
char txt[16];




void clear_txt(){

 txt[0] = ' ';
 txt[1] = ' ';
 txt[2] = ' ';
 txt[3] = ' ';
 txt[4] = ' ';
 txt[5] = ' ';
 txt[6] = ' ';
 txt[7] = ' ';
 txt[8] = ' ';
 txt[9] = ' ';
 txt[10] = ' ';
 txt[11] = ' ';
 txt[12] = ' ';
 txt[13] = ' ';
 txt[14] = ' ';
 txt[15] = ' ';
 }




void conv_lcd(short qtd, unsigned int valor,unsigned char l,unsigned char c){
#line 53 "c:/mikroelektronika/mikroc pro for pic/include/conversores.h"
 short i;
 i=0;
 switch (qtd){
 case 5: txt[i] = ((valor/10000)%10)+0x30;
 i++;
 case 4: txt[i] = ((valor/1000)%10)+0x30;
 i++;
 case 3: txt[i] = ((valor/100)%10)+0x30;
 i++;
 case 2: txt[i] = ((valor/10)%10)+0x30;
 i++;
 case 1: txt[i] = (valor%10)+0x30;
 i++;
 default: txt[i] = 0x00;
 }
 Lcd_Out(l,c,txt);
 }




void conv_txt(short qtd, unsigned int valor){
#line 81 "c:/mikroelektronika/mikroc pro for pic/include/conversores.h"
 short i;
 i=0;
 switch (qtd){
 case 5: txt[i] = ((valor/10000)%10)+0x30;
 i++;
 case 4: txt[i] = ((valor/1000)%10)+0x30;
 i++;
 case 3: txt[i] = ((valor/100)%10)+0x30;
 i++;
 case 2: txt[i] = ((valor/10)%10)+0x30;
 i++;
 case 1: txt[i] = (valor%10)+0x30;
 i++;
 default: txt[i] = 0x00;
 }
 }




void convlng_txt(short qtd,unsigned long valor){
#line 109 "c:/mikroelektronika/mikroc pro for pic/include/conversores.h"
 short i;
 i=0;
 switch (qtd){

 case 10: txt[i] = ((valor/1000000000)%10)+0x30;
 i++;
 case 9: txt[i] = ((valor/100000000)%10)+0x30;
 i++;
 case 8: txt[i] = ((valor/10000000)%10)+0x30;
 i++;
 case 7: txt[i] = ((valor/1000000)%10)+0x30;
 i++;
 case 6: txt[i] = ((valor/100000)%10)+0x30;
 i++;
 case 5: txt[i] = ((valor/10000)%10)+0x30;
 i++;
 case 4: txt[i] = ((valor/1000)%10)+0x30;
 i++;
 case 3: txt[i] = ((valor/100)%10)+0x30;
 i++;
 case 2: txt[i] = ((valor/10)%10)+0x30;
 i++;
 case 1: txt[i] = (valor%10)+0x30;
 i++;
 default: txt[i] = 0x00;
 }
 }

unsigned short conv_dec(unsigned short unidade, unsigned short dezena){
 return (unidade-48)+((dezena-48)*10);
 }




void conv_hex(char l, char c, char i) {
#line 150 "c:/mikroelektronika/mikroc pro for pic/include/conversores.h"
 unsigned char aux_n;

 aux_n = i & 0xF0;
 aux_n = aux_n >> 4;
 aux_n = aux_n + '0';
 if (aux_n>'9') aux_n=aux_n+7;
 Lcd_Chr(l,c,aux_n);

 aux_n = (i & 0x0F) + '0';
 if (aux_n>'9') aux_n=aux_n+7;

 Lcd_Chr_CP(aux_n);

}
#line 64 "F:/Documents/1 - Projetos/Hexapod/Firmware/Hexapod_VS1.c"
struct legs{
 unsigned short DT1;
 unsigned short DT2;
 unsigned short DT3;
};

struct legs leg[6];





bit theend;
unsigned short Cont_pwm=0;

void init_sis();




void interrupt(){

 if (TMR0IF_bit){
 if (theend){
  PORTB=PORTB;PORTC=0x07;PORTD=0xFF; PORTE.F0 =1 ;
 Cont_pwm=0;
 theend=0;
 T0PS0_bit=0;
 TMR0H=0xFA;
 TMR0L=0xFF;
 }else{
 TMR0IE_bit=0;
 TMR0ON_bit=0;
 T0PS0_bit=1;
 TMR0H=0x72;
 TMR0L=0xFF;
 TMR1ON_bit=1;
 TMR1IE_bit=1;
 theend=1;
 }
 TMR0IF_bit=0;
 }
 if (TMR1IF_bit){
 Cont_pwm++;
 if (Cont_pwm==0){
 TMR1IE_bit=0;
 TMR1ON_bit=0;
 TMR1H=255;
 TMR1L=220;
 TMR1IF_bit=0;
  PORTB=PORTB;PORTC=0;PORTD=0; PORTE.F0 =0 ;
 TMR0ON_bit=1;
 TMR0IE_bit=1;
 return;
 }

 if (leg[0].DT1==Cont_pwm)  PORTB.F0 =0;
 if (leg[0].DT2==Cont_pwm)  PORTB.F1 =0;
 if (leg[0].DT3==Cont_pwm)  PORTB.F2 =0;

 if (leg[1].DT1==Cont_pwm)  PORTB.F3 =0;
 if (leg[1].DT2==Cont_pwm)  PORTB.F4 =0;
 if (leg[1].DT3==Cont_pwm)  PORTB.F5 =0;

 if (leg[2].DT1==Cont_pwm)  PORTC.F0 =0;
 if (leg[2].DT2==Cont_pwm)  PORTC.F1 =0;
 if (leg[2].DT3==Cont_pwm)  PORTC.F2 =0;

 if (leg[3].DT1==Cont_pwm)  PORTD.F0 =0;
 if (leg[3].DT2==Cont_pwm)  PORTD.F1 =0;
 if (leg[3].DT3==Cont_pwm)  PORTD.F2 =0;

 if (leg[4].DT1==Cont_pwm)  PORTD.F3 =0;
 if (leg[4].DT2==Cont_pwm)  PORTD.F4 =0;
 if (leg[4].DT3==Cont_pwm)  PORTD.F5 =0;

 if (leg[5].DT1==Cont_pwm)  PORTD.F6 =0;
 if (leg[5].DT2==Cont_pwm)  PORTD.F7 =0;
 if (leg[5].DT3==Cont_pwm)  PORTE.F0 =0;


 TMR1H=255;
 TMR1L=220;
 TMR1IF_bit=0;
 }
}

const char Tab1[10][6][3]={


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

void Pausa(unsigned short time){
 unsigned short Contador;
 for (Contador=0; Contador<time; Contador++){
 Delay_ms(10);
 }
}

void Executa_Tabela1(unsigned short Tempo){

 unsigned short Indexador;
 for (Indexador=0;Indexador< 10 ;Indexador++){
 leg[0].DT1 = Tab1[Indexador][0][0];
 leg[0].DT2 = Tab1[Indexador][0][1];
 leg[0].DT3 = Tab1[Indexador][0][2];

 leg[1].DT1 = Tab1[Indexador][1][0];
 leg[1].DT2 = Tab1[Indexador][1][1];
 leg[1].DT3 = Tab1[Indexador][1][2];

 leg[2].DT1 = Tab1[Indexador][2][0];
 leg[2].DT2 = Tab1[Indexador][2][1];
 leg[2].DT3 = Tab1[Indexador][2][2];

 leg[3].DT1 = Tab1[Indexador][3][0];
 leg[3].DT2 = Tab1[Indexador][3][1];
 leg[3].DT3 = Tab1[Indexador][3][2];

 leg[4].DT1 = Tab1[Indexador][4][0];
 leg[4].DT2 = Tab1[Indexador][4][1];
 leg[4].DT3 = Tab1[Indexador][4][2];

 leg[5].DT1 = Tab1[Indexador][5][0];
 leg[5].DT2 = Tab1[Indexador][5][1];
 leg[5].DT3 = Tab1[Indexador][5][2];

 Pausa(Tempo);
 }
}




void main() {
 unsigned short Opt;
 bit Cmd_rec;
 init_sis();
 Cmd_rec=0;
 do{

 if (Cmd_rec){
 switch (Opt){
 case 0x01:
 Executa_Tabela1(10);
 break;
 default:
 break;
 }
 }

 }while(1);
}






void init_sis(){
 unsigned short i;

 ADCON1 = 0x0C;
 CMCON = 7;

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

 UCON.B3 = 0;
 UCFG.B3 = 1;
 HLVDEN_bit = 0;
 CVRCON = 0;


 INTCON = 0b11100000;

 INTCON2 = 0b11110000;

 INTCON3 = 0b01000000;


 PIE1 = 0b00000000;

 PIE2 = 0b00000000;


 PIR1 = 0;

 PIR2 = 0;


 IPR1 = 0b00000000;


 IPR2 = 0b00000000;


 T0CON = 0b10000000;

 T1CON = 0b10000001;





 for (i=0;i<6;i++){
 leg[i].DT1=128;
 leg[i].DT2=128;
 leg[i].DT3=128;
 }
}
