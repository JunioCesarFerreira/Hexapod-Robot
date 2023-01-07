/*
  Descrição:
  Este arquivo contém sub-rotinas para auxilio na conversão de variaveis, principalmente para uso de displays Alfanumericos.
  Versão MikroC for PIC v3.2
  Autor: Junio Cesar Ferreira - jcf_ssp@hotmail.com
  
  Nota:
  * Para utilizar as funções relacionadas a display LCD a Library lcd deve estar inclusa na compilação do projeto.
  * Este arquivo deve estar na mesma pasta do projeto à ser compilado ou ser adicionado na criação do projeto.
*/

char txt[16]; /* Este Vetor recebera as conversões em ASCII para escrita
                em display LCD, Além de ser usado pelas rotinas deste arquivo,
                pode ser usado para outras funções no programa, afim de
                economizar memória.
                Obs: Vetor feito para displays de 16 colunas.
                */
                
// -----------------------------------------------------------------------------
// **** Limpa string txt para escrita no display ****
// -----------------------------------------------------------------------------
void clear_txt(){                                                               // *** Rotina clear_txt() ***
// !Carrega txt com espaços.
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
     
// -----------------------------------------------------------------------------
// **** Rotina converte decimal em texto e escreve no no display LCD ****
// -----------------------------------------------------------------------------
void conv_lcd(short qtd, unsigned int valor,unsigned char l,unsigned char c){   // **** Rotina conv_lcd(qtd,valor,linha,conluna) ****
/* Breve descrição:
   Recebe um valor numérico (em ASCII) e escreve no Display LCD.
* qtd: Quantidade de digitos (algarismos) que será convertido o valor. (maximo 5)
* valor: Valor a ser convertido para ASCII com finalidade de escrita em display LCD
* l : Linha do display;
* c : Coluna do display;
*/
         short i;
         i=0;                                                                   // Inicializa indexador
         switch (qtd){                                                          // seleciona quantidade de algarismos a ser convertido
                case 5: txt[i] = ((valor/10000)%10)+0x30;                       // Montagem da string numerica
                        i++;
                case 4: txt[i] = ((valor/1000)%10)+0x30;
                        i++;
                case 3: txt[i] = ((valor/100)%10)+0x30;
                        i++;
                case 2: txt[i] = ((valor/10)%10)+0x30;
                        i++;
                case 1: txt[i] = (valor%10)+0x30;
                        i++;
                default: txt[i] = 0x00;                                         // Finaliza a montagem da string <NULL>
            }
         Lcd_Out(l,c,txt);
         }
         
// -----------------------------------------------------------------------------
// **** Rotina converte texto em decimal 'até 4 digitos' ****
// -----------------------------------------------------------------------------
void conv_txt(short qtd, unsigned int valor){                                   // **** Rotina conv_txt(qtd,valor) ****

/* Breve descrição:
   Recebe um valor numérico à ser escrito (em ASCII) em Display LCD, mas não escreve. Podento o resto do vetor ser alterado antes da escrita.
* qtd: Quantidade de digitos (algarismos) que será convertido o valor. (maximo 5)
* valor: Valor a ser convertido para ASCII com finalidade de escrita em display LCD
*/
         short i;
         i=0;                                                                   // Inicializa indexador
         switch (qtd){                                                          // seleciona quantidade de algarismos a ser convertido
                case 5: txt[i] = ((valor/10000)%10)+0x30;                       // Montagem da string numerica
                        i++;
                case 4: txt[i] = ((valor/1000)%10)+0x30;
                        i++;
                case 3: txt[i] = ((valor/100)%10)+0x30;
                        i++;
                case 2: txt[i] = ((valor/10)%10)+0x30;
                        i++;
                case 1: txt[i] = (valor%10)+0x30;
                        i++;
                default: txt[i] = 0x00;                                         // Finaliza a montagem da string <NULL>
            }
         }
         
// -----------------------------------------------------------------------------
// *** Converte numeros longos em textos ***
// -----------------------------------------------------------------------------
void convlng_txt(short qtd,unsigned long valor){                                // *** Rotina convlng_txt(short qtd,unsigned long valor) ***

/* Breve descrição:
   Recebe um valor numérico com valores extremamente longos à ser escrito (em ASCII) em Display LCD, mas não escreve.
   Podento o resto do vetor ser alterado antes da escrita.
* qtd: Quantidade de digitos (algarismos) que será convertido o valor. (até 10)
* valor: Valor a ser convertido para ASCII com finalidade de escrita em display LCD
*/
         short i;
         i=0;                                                                   // Inicializa indexador
         switch (qtd){                                                          // seleciona quantidade de algarismos a ser convertido
                                                                                // Montagem da string numerica
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
                default: txt[i] = 0x00;                                         // Finaliza a montagem da string <NULL>
            }
         }

unsigned short conv_dec(unsigned short unidade, unsigned short dezena){         // *** Converte ASCII para decimal ***
          return (unidade-48)+((dezena-48)*10);
         }
         
// -----------------------------------------------------------------------------
// *** Converte byte em hexadecimal e escreve no display ****
// -----------------------------------------------------------------------------
void conv_hex(char l, char c, char i) {                                         // *** Converte byte em hexadecimal e escreve no display ****
/* Breve descrição:
   Esta rotina recebe um caracter, e converte o mesmo em dois valores ASCII que representam o valor Hexadecimal,
   para escrita no display LCD.
   * i : Caracter a ser convertido
*/
  unsigned char aux_n;                                                          // Auxiliar de conversão e escrita

  aux_n = i & 0xF0;                                                             // Converte high nibble
  aux_n = aux_n >> 4;
  aux_n = aux_n + '0';
  if (aux_n>'9') aux_n=aux_n+7;
  Lcd_Chr(l,c,aux_n);                                                           // Escreve valor high nibble
  
  aux_n = (i & 0x0F) + '0';                                                     // Converte Low nibble
  if (aux_n>'9') aux_n=aux_n+7;

  Lcd_Chr_CP(aux_n);                                                            // Escreve valor Low nibble

}

