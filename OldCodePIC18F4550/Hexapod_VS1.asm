
_clear_txt:

;conversores.h,22 :: 		
;conversores.h,24 :: 		
	MOVLW       32
	MOVWF       _txt+0 
;conversores.h,25 :: 		
	MOVLW       32
	MOVWF       _txt+1 
;conversores.h,26 :: 		
	MOVLW       32
	MOVWF       _txt+2 
;conversores.h,27 :: 		
	MOVLW       32
	MOVWF       _txt+3 
;conversores.h,28 :: 		
	MOVLW       32
	MOVWF       _txt+4 
;conversores.h,29 :: 		
	MOVLW       32
	MOVWF       _txt+5 
;conversores.h,30 :: 		
	MOVLW       32
	MOVWF       _txt+6 
;conversores.h,31 :: 		
	MOVLW       32
	MOVWF       _txt+7 
;conversores.h,32 :: 		
	MOVLW       32
	MOVWF       _txt+8 
;conversores.h,33 :: 		
	MOVLW       32
	MOVWF       _txt+9 
;conversores.h,34 :: 		
	MOVLW       32
	MOVWF       _txt+10 
;conversores.h,35 :: 		
	MOVLW       32
	MOVWF       _txt+11 
;conversores.h,36 :: 		
	MOVLW       32
	MOVWF       _txt+12 
;conversores.h,37 :: 		
	MOVLW       32
	MOVWF       _txt+13 
;conversores.h,38 :: 		
	MOVLW       32
	MOVWF       _txt+14 
;conversores.h,39 :: 		
	MOVLW       32
	MOVWF       _txt+15 
;conversores.h,40 :: 		
	RETURN      0
; end of _clear_txt

_conv_lcd:

;conversores.h,45 :: 		
;conversores.h,54 :: 		
	CLRF        conv_lcd_i_L0+0 
;conversores.h,55 :: 		
	GOTO        L_conv_lcd0
;conversores.h,56 :: 		
L_conv_lcd2:
	MOVLW       _txt+0
	MOVWF       FLOC__conv_lcd+0 
	MOVLW       hi_addr(_txt+0)
	MOVWF       FLOC__conv_lcd+1 
	MOVF        conv_lcd_i_L0+0, 0 
	ADDWF       FLOC__conv_lcd+0, 1 
	MOVLW       0
	BTFSC       conv_lcd_i_L0+0, 7 
	MOVLW       255
	ADDWFC      FLOC__conv_lcd+1, 1 
	MOVLW       16
	MOVWF       R4 
	MOVLW       39
	MOVWF       R5 
	MOVF        FARG_conv_lcd_valor+0, 0 
	MOVWF       R0 
	MOVF        FARG_conv_lcd_valor+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_U+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       48
	ADDWF       R0, 1 
	MOVFF       FLOC__conv_lcd+0, FSR1L
	MOVFF       FLOC__conv_lcd+1, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;conversores.h,57 :: 		
	INCF        conv_lcd_i_L0+0, 1 
;conversores.h,58 :: 		
L_conv_lcd3:
	MOVLW       _txt+0
	MOVWF       FLOC__conv_lcd+0 
	MOVLW       hi_addr(_txt+0)
	MOVWF       FLOC__conv_lcd+1 
	MOVF        conv_lcd_i_L0+0, 0 
	ADDWF       FLOC__conv_lcd+0, 1 
	MOVLW       0
	BTFSC       conv_lcd_i_L0+0, 7 
	MOVLW       255
	ADDWFC      FLOC__conv_lcd+1, 1 
	MOVLW       232
	MOVWF       R4 
	MOVLW       3
	MOVWF       R5 
	MOVF        FARG_conv_lcd_valor+0, 0 
	MOVWF       R0 
	MOVF        FARG_conv_lcd_valor+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_U+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       48
	ADDWF       R0, 1 
	MOVFF       FLOC__conv_lcd+0, FSR1L
	MOVFF       FLOC__conv_lcd+1, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;conversores.h,59 :: 		
	INCF        conv_lcd_i_L0+0, 1 
;conversores.h,60 :: 		
L_conv_lcd4:
	MOVLW       _txt+0
	MOVWF       FLOC__conv_lcd+0 
	MOVLW       hi_addr(_txt+0)
	MOVWF       FLOC__conv_lcd+1 
	MOVF        conv_lcd_i_L0+0, 0 
	ADDWF       FLOC__conv_lcd+0, 1 
	MOVLW       0
	BTFSC       conv_lcd_i_L0+0, 7 
	MOVLW       255
	ADDWFC      FLOC__conv_lcd+1, 1 
	MOVLW       100
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        FARG_conv_lcd_valor+0, 0 
	MOVWF       R0 
	MOVF        FARG_conv_lcd_valor+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_U+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       48
	ADDWF       R0, 1 
	MOVFF       FLOC__conv_lcd+0, FSR1L
	MOVFF       FLOC__conv_lcd+1, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;conversores.h,61 :: 		
	INCF        conv_lcd_i_L0+0, 1 
;conversores.h,62 :: 		
L_conv_lcd5:
	MOVLW       _txt+0
	MOVWF       FLOC__conv_lcd+0 
	MOVLW       hi_addr(_txt+0)
	MOVWF       FLOC__conv_lcd+1 
	MOVF        conv_lcd_i_L0+0, 0 
	ADDWF       FLOC__conv_lcd+0, 1 
	MOVLW       0
	BTFSC       conv_lcd_i_L0+0, 7 
	MOVLW       255
	ADDWFC      FLOC__conv_lcd+1, 1 
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        FARG_conv_lcd_valor+0, 0 
	MOVWF       R0 
	MOVF        FARG_conv_lcd_valor+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_U+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       48
	ADDWF       R0, 1 
	MOVFF       FLOC__conv_lcd+0, FSR1L
	MOVFF       FLOC__conv_lcd+1, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;conversores.h,63 :: 		
	INCF        conv_lcd_i_L0+0, 1 
;conversores.h,64 :: 		
L_conv_lcd6:
	MOVLW       _txt+0
	MOVWF       FLOC__conv_lcd+0 
	MOVLW       hi_addr(_txt+0)
	MOVWF       FLOC__conv_lcd+1 
	MOVF        conv_lcd_i_L0+0, 0 
	ADDWF       FLOC__conv_lcd+0, 1 
	MOVLW       0
	BTFSC       conv_lcd_i_L0+0, 7 
	MOVLW       255
	ADDWFC      FLOC__conv_lcd+1, 1 
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        FARG_conv_lcd_valor+0, 0 
	MOVWF       R0 
	MOVF        FARG_conv_lcd_valor+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       48
	ADDWF       R0, 1 
	MOVFF       FLOC__conv_lcd+0, FSR1L
	MOVFF       FLOC__conv_lcd+1, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;conversores.h,65 :: 		
	INCF        conv_lcd_i_L0+0, 1 
;conversores.h,66 :: 		
L_conv_lcd7:
	MOVLW       _txt+0
	MOVWF       FSR1L 
	MOVLW       hi_addr(_txt+0)
	MOVWF       FSR1H 
	MOVF        conv_lcd_i_L0+0, 0 
	ADDWF       FSR1L, 1 
	MOVLW       0
	BTFSC       conv_lcd_i_L0+0, 7 
	MOVLW       255
	ADDWFC      FSR1H, 1 
	CLRF        POSTINC1+0 
;conversores.h,67 :: 		
	GOTO        L_conv_lcd1
L_conv_lcd0:
	MOVF        FARG_conv_lcd_qtd+0, 0 
	XORLW       5
	BTFSC       STATUS+0, 2 
	GOTO        L_conv_lcd2
	MOVF        FARG_conv_lcd_qtd+0, 0 
	XORLW       4
	BTFSC       STATUS+0, 2 
	GOTO        L_conv_lcd3
	MOVF        FARG_conv_lcd_qtd+0, 0 
	XORLW       3
	BTFSC       STATUS+0, 2 
	GOTO        L_conv_lcd4
	MOVF        FARG_conv_lcd_qtd+0, 0 
	XORLW       2
	BTFSC       STATUS+0, 2 
	GOTO        L_conv_lcd5
	MOVF        FARG_conv_lcd_qtd+0, 0 
	XORLW       1
	BTFSC       STATUS+0, 2 
	GOTO        L_conv_lcd6
	GOTO        L_conv_lcd7
L_conv_lcd1:
;conversores.h,68 :: 		
	MOVF        FARG_conv_lcd_l+0, 0 
	MOVWF       FARG_Lcd_Out_row+0 
	MOVF        FARG_conv_lcd_c+0, 0 
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       _txt+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(_txt+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;conversores.h,69 :: 		
	RETURN      0
; end of _conv_lcd

_conv_txt:

;conversores.h,74 :: 		
;conversores.h,82 :: 		
	CLRF        conv_txt_i_L0+0 
;conversores.h,83 :: 		
	GOTO        L_conv_txt8
;conversores.h,84 :: 		
L_conv_txt10:
	MOVLW       _txt+0
	MOVWF       FLOC__conv_txt+0 
	MOVLW       hi_addr(_txt+0)
	MOVWF       FLOC__conv_txt+1 
	MOVF        conv_txt_i_L0+0, 0 
	ADDWF       FLOC__conv_txt+0, 1 
	MOVLW       0
	BTFSC       conv_txt_i_L0+0, 7 
	MOVLW       255
	ADDWFC      FLOC__conv_txt+1, 1 
	MOVLW       16
	MOVWF       R4 
	MOVLW       39
	MOVWF       R5 
	MOVF        FARG_conv_txt_valor+0, 0 
	MOVWF       R0 
	MOVF        FARG_conv_txt_valor+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_U+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       48
	ADDWF       R0, 1 
	MOVFF       FLOC__conv_txt+0, FSR1L
	MOVFF       FLOC__conv_txt+1, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;conversores.h,85 :: 		
	INCF        conv_txt_i_L0+0, 1 
;conversores.h,86 :: 		
L_conv_txt11:
	MOVLW       _txt+0
	MOVWF       FLOC__conv_txt+0 
	MOVLW       hi_addr(_txt+0)
	MOVWF       FLOC__conv_txt+1 
	MOVF        conv_txt_i_L0+0, 0 
	ADDWF       FLOC__conv_txt+0, 1 
	MOVLW       0
	BTFSC       conv_txt_i_L0+0, 7 
	MOVLW       255
	ADDWFC      FLOC__conv_txt+1, 1 
	MOVLW       232
	MOVWF       R4 
	MOVLW       3
	MOVWF       R5 
	MOVF        FARG_conv_txt_valor+0, 0 
	MOVWF       R0 
	MOVF        FARG_conv_txt_valor+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_U+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       48
	ADDWF       R0, 1 
	MOVFF       FLOC__conv_txt+0, FSR1L
	MOVFF       FLOC__conv_txt+1, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;conversores.h,87 :: 		
	INCF        conv_txt_i_L0+0, 1 
;conversores.h,88 :: 		
L_conv_txt12:
	MOVLW       _txt+0
	MOVWF       FLOC__conv_txt+0 
	MOVLW       hi_addr(_txt+0)
	MOVWF       FLOC__conv_txt+1 
	MOVF        conv_txt_i_L0+0, 0 
	ADDWF       FLOC__conv_txt+0, 1 
	MOVLW       0
	BTFSC       conv_txt_i_L0+0, 7 
	MOVLW       255
	ADDWFC      FLOC__conv_txt+1, 1 
	MOVLW       100
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        FARG_conv_txt_valor+0, 0 
	MOVWF       R0 
	MOVF        FARG_conv_txt_valor+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_U+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       48
	ADDWF       R0, 1 
	MOVFF       FLOC__conv_txt+0, FSR1L
	MOVFF       FLOC__conv_txt+1, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;conversores.h,89 :: 		
	INCF        conv_txt_i_L0+0, 1 
;conversores.h,90 :: 		
L_conv_txt13:
	MOVLW       _txt+0
	MOVWF       FLOC__conv_txt+0 
	MOVLW       hi_addr(_txt+0)
	MOVWF       FLOC__conv_txt+1 
	MOVF        conv_txt_i_L0+0, 0 
	ADDWF       FLOC__conv_txt+0, 1 
	MOVLW       0
	BTFSC       conv_txt_i_L0+0, 7 
	MOVLW       255
	ADDWFC      FLOC__conv_txt+1, 1 
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        FARG_conv_txt_valor+0, 0 
	MOVWF       R0 
	MOVF        FARG_conv_txt_valor+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_U+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       48
	ADDWF       R0, 1 
	MOVFF       FLOC__conv_txt+0, FSR1L
	MOVFF       FLOC__conv_txt+1, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;conversores.h,91 :: 		
	INCF        conv_txt_i_L0+0, 1 
;conversores.h,92 :: 		
L_conv_txt14:
	MOVLW       _txt+0
	MOVWF       FLOC__conv_txt+0 
	MOVLW       hi_addr(_txt+0)
	MOVWF       FLOC__conv_txt+1 
	MOVF        conv_txt_i_L0+0, 0 
	ADDWF       FLOC__conv_txt+0, 1 
	MOVLW       0
	BTFSC       conv_txt_i_L0+0, 7 
	MOVLW       255
	ADDWFC      FLOC__conv_txt+1, 1 
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        FARG_conv_txt_valor+0, 0 
	MOVWF       R0 
	MOVF        FARG_conv_txt_valor+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       48
	ADDWF       R0, 1 
	MOVFF       FLOC__conv_txt+0, FSR1L
	MOVFF       FLOC__conv_txt+1, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;conversores.h,93 :: 		
	INCF        conv_txt_i_L0+0, 1 
;conversores.h,94 :: 		
L_conv_txt15:
	MOVLW       _txt+0
	MOVWF       FSR1L 
	MOVLW       hi_addr(_txt+0)
	MOVWF       FSR1H 
	MOVF        conv_txt_i_L0+0, 0 
	ADDWF       FSR1L, 1 
	MOVLW       0
	BTFSC       conv_txt_i_L0+0, 7 
	MOVLW       255
	ADDWFC      FSR1H, 1 
	CLRF        POSTINC1+0 
;conversores.h,95 :: 		
	GOTO        L_conv_txt9
L_conv_txt8:
	MOVF        FARG_conv_txt_qtd+0, 0 
	XORLW       5
	BTFSC       STATUS+0, 2 
	GOTO        L_conv_txt10
	MOVF        FARG_conv_txt_qtd+0, 0 
	XORLW       4
	BTFSC       STATUS+0, 2 
	GOTO        L_conv_txt11
	MOVF        FARG_conv_txt_qtd+0, 0 
	XORLW       3
	BTFSC       STATUS+0, 2 
	GOTO        L_conv_txt12
	MOVF        FARG_conv_txt_qtd+0, 0 
	XORLW       2
	BTFSC       STATUS+0, 2 
	GOTO        L_conv_txt13
	MOVF        FARG_conv_txt_qtd+0, 0 
	XORLW       1
	BTFSC       STATUS+0, 2 
	GOTO        L_conv_txt14
	GOTO        L_conv_txt15
L_conv_txt9:
;conversores.h,96 :: 		
	RETURN      0
; end of _conv_txt

_convlng_txt:

;conversores.h,101 :: 		
;conversores.h,110 :: 		
	CLRF        convlng_txt_i_L0+0 
;conversores.h,111 :: 		
	GOTO        L_convlng_txt16
;conversores.h,113 :: 		
L_convlng_txt18:
	MOVLW       _txt+0
	MOVWF       FLOC__convlng_txt+0 
	MOVLW       hi_addr(_txt+0)
	MOVWF       FLOC__convlng_txt+1 
	MOVF        convlng_txt_i_L0+0, 0 
	ADDWF       FLOC__convlng_txt+0, 1 
	MOVLW       0
	BTFSC       convlng_txt_i_L0+0, 7 
	MOVLW       255
	ADDWFC      FLOC__convlng_txt+1, 1 
	MOVLW       0
	MOVWF       R4 
	MOVLW       202
	MOVWF       R5 
	MOVLW       154
	MOVWF       R6 
	MOVLW       59
	MOVWF       R7 
	MOVF        FARG_convlng_txt_valor+0, 0 
	MOVWF       R0 
	MOVF        FARG_convlng_txt_valor+1, 0 
	MOVWF       R1 
	MOVF        FARG_convlng_txt_valor+2, 0 
	MOVWF       R2 
	MOVF        FARG_convlng_txt_valor+3, 0 
	MOVWF       R3 
	CALL        _Div_32x32_U+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	CALL        _Div_32x32_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVF        R10, 0 
	MOVWF       R2 
	MOVF        R11, 0 
	MOVWF       R3 
	MOVLW       48
	ADDWF       R0, 1 
	MOVFF       FLOC__convlng_txt+0, FSR1L
	MOVFF       FLOC__convlng_txt+1, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;conversores.h,114 :: 		
	INCF        convlng_txt_i_L0+0, 1 
;conversores.h,115 :: 		
L_convlng_txt19:
	MOVLW       _txt+0
	MOVWF       FLOC__convlng_txt+0 
	MOVLW       hi_addr(_txt+0)
	MOVWF       FLOC__convlng_txt+1 
	MOVF        convlng_txt_i_L0+0, 0 
	ADDWF       FLOC__convlng_txt+0, 1 
	MOVLW       0
	BTFSC       convlng_txt_i_L0+0, 7 
	MOVLW       255
	ADDWFC      FLOC__convlng_txt+1, 1 
	MOVLW       0
	MOVWF       R4 
	MOVLW       225
	MOVWF       R5 
	MOVLW       245
	MOVWF       R6 
	MOVLW       5
	MOVWF       R7 
	MOVF        FARG_convlng_txt_valor+0, 0 
	MOVWF       R0 
	MOVF        FARG_convlng_txt_valor+1, 0 
	MOVWF       R1 
	MOVF        FARG_convlng_txt_valor+2, 0 
	MOVWF       R2 
	MOVF        FARG_convlng_txt_valor+3, 0 
	MOVWF       R3 
	CALL        _Div_32x32_U+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	CALL        _Div_32x32_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVF        R10, 0 
	MOVWF       R2 
	MOVF        R11, 0 
	MOVWF       R3 
	MOVLW       48
	ADDWF       R0, 1 
	MOVFF       FLOC__convlng_txt+0, FSR1L
	MOVFF       FLOC__convlng_txt+1, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;conversores.h,116 :: 		
	INCF        convlng_txt_i_L0+0, 1 
;conversores.h,117 :: 		
L_convlng_txt20:
	MOVLW       _txt+0
	MOVWF       FLOC__convlng_txt+0 
	MOVLW       hi_addr(_txt+0)
	MOVWF       FLOC__convlng_txt+1 
	MOVF        convlng_txt_i_L0+0, 0 
	ADDWF       FLOC__convlng_txt+0, 1 
	MOVLW       0
	BTFSC       convlng_txt_i_L0+0, 7 
	MOVLW       255
	ADDWFC      FLOC__convlng_txt+1, 1 
	MOVLW       128
	MOVWF       R4 
	MOVLW       150
	MOVWF       R5 
	MOVLW       152
	MOVWF       R6 
	MOVLW       0
	MOVWF       R7 
	MOVF        FARG_convlng_txt_valor+0, 0 
	MOVWF       R0 
	MOVF        FARG_convlng_txt_valor+1, 0 
	MOVWF       R1 
	MOVF        FARG_convlng_txt_valor+2, 0 
	MOVWF       R2 
	MOVF        FARG_convlng_txt_valor+3, 0 
	MOVWF       R3 
	CALL        _Div_32x32_U+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	CALL        _Div_32x32_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVF        R10, 0 
	MOVWF       R2 
	MOVF        R11, 0 
	MOVWF       R3 
	MOVLW       48
	ADDWF       R0, 1 
	MOVFF       FLOC__convlng_txt+0, FSR1L
	MOVFF       FLOC__convlng_txt+1, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;conversores.h,118 :: 		
	INCF        convlng_txt_i_L0+0, 1 
;conversores.h,119 :: 		
L_convlng_txt21:
	MOVLW       _txt+0
	MOVWF       FLOC__convlng_txt+0 
	MOVLW       hi_addr(_txt+0)
	MOVWF       FLOC__convlng_txt+1 
	MOVF        convlng_txt_i_L0+0, 0 
	ADDWF       FLOC__convlng_txt+0, 1 
	MOVLW       0
	BTFSC       convlng_txt_i_L0+0, 7 
	MOVLW       255
	ADDWFC      FLOC__convlng_txt+1, 1 
	MOVLW       64
	MOVWF       R4 
	MOVLW       66
	MOVWF       R5 
	MOVLW       15
	MOVWF       R6 
	MOVLW       0
	MOVWF       R7 
	MOVF        FARG_convlng_txt_valor+0, 0 
	MOVWF       R0 
	MOVF        FARG_convlng_txt_valor+1, 0 
	MOVWF       R1 
	MOVF        FARG_convlng_txt_valor+2, 0 
	MOVWF       R2 
	MOVF        FARG_convlng_txt_valor+3, 0 
	MOVWF       R3 
	CALL        _Div_32x32_U+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	CALL        _Div_32x32_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVF        R10, 0 
	MOVWF       R2 
	MOVF        R11, 0 
	MOVWF       R3 
	MOVLW       48
	ADDWF       R0, 1 
	MOVFF       FLOC__convlng_txt+0, FSR1L
	MOVFF       FLOC__convlng_txt+1, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;conversores.h,120 :: 		
	INCF        convlng_txt_i_L0+0, 1 
;conversores.h,121 :: 		
L_convlng_txt22:
	MOVLW       _txt+0
	MOVWF       FLOC__convlng_txt+0 
	MOVLW       hi_addr(_txt+0)
	MOVWF       FLOC__convlng_txt+1 
	MOVF        convlng_txt_i_L0+0, 0 
	ADDWF       FLOC__convlng_txt+0, 1 
	MOVLW       0
	BTFSC       convlng_txt_i_L0+0, 7 
	MOVLW       255
	ADDWFC      FLOC__convlng_txt+1, 1 
	MOVLW       160
	MOVWF       R4 
	MOVLW       134
	MOVWF       R5 
	MOVLW       1
	MOVWF       R6 
	MOVLW       0
	MOVWF       R7 
	MOVF        FARG_convlng_txt_valor+0, 0 
	MOVWF       R0 
	MOVF        FARG_convlng_txt_valor+1, 0 
	MOVWF       R1 
	MOVF        FARG_convlng_txt_valor+2, 0 
	MOVWF       R2 
	MOVF        FARG_convlng_txt_valor+3, 0 
	MOVWF       R3 
	CALL        _Div_32x32_U+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	CALL        _Div_32x32_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVF        R10, 0 
	MOVWF       R2 
	MOVF        R11, 0 
	MOVWF       R3 
	MOVLW       48
	ADDWF       R0, 1 
	MOVFF       FLOC__convlng_txt+0, FSR1L
	MOVFF       FLOC__convlng_txt+1, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;conversores.h,122 :: 		
	INCF        convlng_txt_i_L0+0, 1 
;conversores.h,123 :: 		
L_convlng_txt23:
	MOVLW       _txt+0
	MOVWF       FLOC__convlng_txt+0 
	MOVLW       hi_addr(_txt+0)
	MOVWF       FLOC__convlng_txt+1 
	MOVF        convlng_txt_i_L0+0, 0 
	ADDWF       FLOC__convlng_txt+0, 1 
	MOVLW       0
	BTFSC       convlng_txt_i_L0+0, 7 
	MOVLW       255
	ADDWFC      FLOC__convlng_txt+1, 1 
	MOVLW       16
	MOVWF       R4 
	MOVLW       39
	MOVWF       R5 
	MOVLW       0
	MOVWF       R6 
	MOVWF       R7 
	MOVF        FARG_convlng_txt_valor+0, 0 
	MOVWF       R0 
	MOVF        FARG_convlng_txt_valor+1, 0 
	MOVWF       R1 
	MOVF        FARG_convlng_txt_valor+2, 0 
	MOVWF       R2 
	MOVF        FARG_convlng_txt_valor+3, 0 
	MOVWF       R3 
	CALL        _Div_32x32_U+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	CALL        _Div_32x32_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVF        R10, 0 
	MOVWF       R2 
	MOVF        R11, 0 
	MOVWF       R3 
	MOVLW       48
	ADDWF       R0, 1 
	MOVFF       FLOC__convlng_txt+0, FSR1L
	MOVFF       FLOC__convlng_txt+1, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;conversores.h,124 :: 		
	INCF        convlng_txt_i_L0+0, 1 
;conversores.h,125 :: 		
L_convlng_txt24:
	MOVLW       _txt+0
	MOVWF       FLOC__convlng_txt+0 
	MOVLW       hi_addr(_txt+0)
	MOVWF       FLOC__convlng_txt+1 
	MOVF        convlng_txt_i_L0+0, 0 
	ADDWF       FLOC__convlng_txt+0, 1 
	MOVLW       0
	BTFSC       convlng_txt_i_L0+0, 7 
	MOVLW       255
	ADDWFC      FLOC__convlng_txt+1, 1 
	MOVLW       232
	MOVWF       R4 
	MOVLW       3
	MOVWF       R5 
	MOVLW       0
	MOVWF       R6 
	MOVWF       R7 
	MOVF        FARG_convlng_txt_valor+0, 0 
	MOVWF       R0 
	MOVF        FARG_convlng_txt_valor+1, 0 
	MOVWF       R1 
	MOVF        FARG_convlng_txt_valor+2, 0 
	MOVWF       R2 
	MOVF        FARG_convlng_txt_valor+3, 0 
	MOVWF       R3 
	CALL        _Div_32x32_U+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	CALL        _Div_32x32_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVF        R10, 0 
	MOVWF       R2 
	MOVF        R11, 0 
	MOVWF       R3 
	MOVLW       48
	ADDWF       R0, 1 
	MOVFF       FLOC__convlng_txt+0, FSR1L
	MOVFF       FLOC__convlng_txt+1, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;conversores.h,126 :: 		
	INCF        convlng_txt_i_L0+0, 1 
;conversores.h,127 :: 		
L_convlng_txt25:
	MOVLW       _txt+0
	MOVWF       FLOC__convlng_txt+0 
	MOVLW       hi_addr(_txt+0)
	MOVWF       FLOC__convlng_txt+1 
	MOVF        convlng_txt_i_L0+0, 0 
	ADDWF       FLOC__convlng_txt+0, 1 
	MOVLW       0
	BTFSC       convlng_txt_i_L0+0, 7 
	MOVLW       255
	ADDWFC      FLOC__convlng_txt+1, 1 
	MOVLW       100
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	MOVF        FARG_convlng_txt_valor+0, 0 
	MOVWF       R0 
	MOVF        FARG_convlng_txt_valor+1, 0 
	MOVWF       R1 
	MOVF        FARG_convlng_txt_valor+2, 0 
	MOVWF       R2 
	MOVF        FARG_convlng_txt_valor+3, 0 
	MOVWF       R3 
	CALL        _Div_32x32_U+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	CALL        _Div_32x32_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVF        R10, 0 
	MOVWF       R2 
	MOVF        R11, 0 
	MOVWF       R3 
	MOVLW       48
	ADDWF       R0, 1 
	MOVFF       FLOC__convlng_txt+0, FSR1L
	MOVFF       FLOC__convlng_txt+1, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;conversores.h,128 :: 		
	INCF        convlng_txt_i_L0+0, 1 
;conversores.h,129 :: 		
L_convlng_txt26:
	MOVLW       _txt+0
	MOVWF       FLOC__convlng_txt+0 
	MOVLW       hi_addr(_txt+0)
	MOVWF       FLOC__convlng_txt+1 
	MOVF        convlng_txt_i_L0+0, 0 
	ADDWF       FLOC__convlng_txt+0, 1 
	MOVLW       0
	BTFSC       convlng_txt_i_L0+0, 7 
	MOVLW       255
	ADDWFC      FLOC__convlng_txt+1, 1 
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	MOVF        FARG_convlng_txt_valor+0, 0 
	MOVWF       R0 
	MOVF        FARG_convlng_txt_valor+1, 0 
	MOVWF       R1 
	MOVF        FARG_convlng_txt_valor+2, 0 
	MOVWF       R2 
	MOVF        FARG_convlng_txt_valor+3, 0 
	MOVWF       R3 
	CALL        _Div_32x32_U+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	CALL        _Div_32x32_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVF        R10, 0 
	MOVWF       R2 
	MOVF        R11, 0 
	MOVWF       R3 
	MOVLW       48
	ADDWF       R0, 1 
	MOVFF       FLOC__convlng_txt+0, FSR1L
	MOVFF       FLOC__convlng_txt+1, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;conversores.h,130 :: 		
	INCF        convlng_txt_i_L0+0, 1 
;conversores.h,131 :: 		
L_convlng_txt27:
	MOVLW       _txt+0
	MOVWF       FLOC__convlng_txt+0 
	MOVLW       hi_addr(_txt+0)
	MOVWF       FLOC__convlng_txt+1 
	MOVF        convlng_txt_i_L0+0, 0 
	ADDWF       FLOC__convlng_txt+0, 1 
	MOVLW       0
	BTFSC       convlng_txt_i_L0+0, 7 
	MOVLW       255
	ADDWFC      FLOC__convlng_txt+1, 1 
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	MOVF        FARG_convlng_txt_valor+0, 0 
	MOVWF       R0 
	MOVF        FARG_convlng_txt_valor+1, 0 
	MOVWF       R1 
	MOVF        FARG_convlng_txt_valor+2, 0 
	MOVWF       R2 
	MOVF        FARG_convlng_txt_valor+3, 0 
	MOVWF       R3 
	CALL        _Div_32x32_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVF        R10, 0 
	MOVWF       R2 
	MOVF        R11, 0 
	MOVWF       R3 
	MOVLW       48
	ADDWF       R0, 1 
	MOVFF       FLOC__convlng_txt+0, FSR1L
	MOVFF       FLOC__convlng_txt+1, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;conversores.h,132 :: 		
	INCF        convlng_txt_i_L0+0, 1 
;conversores.h,133 :: 		
L_convlng_txt28:
	MOVLW       _txt+0
	MOVWF       FSR1L 
	MOVLW       hi_addr(_txt+0)
	MOVWF       FSR1H 
	MOVF        convlng_txt_i_L0+0, 0 
	ADDWF       FSR1L, 1 
	MOVLW       0
	BTFSC       convlng_txt_i_L0+0, 7 
	MOVLW       255
	ADDWFC      FSR1H, 1 
	CLRF        POSTINC1+0 
;conversores.h,134 :: 		
	GOTO        L_convlng_txt17
L_convlng_txt16:
	MOVF        FARG_convlng_txt_qtd+0, 0 
	XORLW       10
	BTFSC       STATUS+0, 2 
	GOTO        L_convlng_txt18
	MOVF        FARG_convlng_txt_qtd+0, 0 
	XORLW       9
	BTFSC       STATUS+0, 2 
	GOTO        L_convlng_txt19
	MOVF        FARG_convlng_txt_qtd+0, 0 
	XORLW       8
	BTFSC       STATUS+0, 2 
	GOTO        L_convlng_txt20
	MOVF        FARG_convlng_txt_qtd+0, 0 
	XORLW       7
	BTFSC       STATUS+0, 2 
	GOTO        L_convlng_txt21
	MOVF        FARG_convlng_txt_qtd+0, 0 
	XORLW       6
	BTFSC       STATUS+0, 2 
	GOTO        L_convlng_txt22
	MOVF        FARG_convlng_txt_qtd+0, 0 
	XORLW       5
	BTFSC       STATUS+0, 2 
	GOTO        L_convlng_txt23
	MOVF        FARG_convlng_txt_qtd+0, 0 
	XORLW       4
	BTFSC       STATUS+0, 2 
	GOTO        L_convlng_txt24
	MOVF        FARG_convlng_txt_qtd+0, 0 
	XORLW       3
	BTFSC       STATUS+0, 2 
	GOTO        L_convlng_txt25
	MOVF        FARG_convlng_txt_qtd+0, 0 
	XORLW       2
	BTFSC       STATUS+0, 2 
	GOTO        L_convlng_txt26
	MOVF        FARG_convlng_txt_qtd+0, 0 
	XORLW       1
	BTFSC       STATUS+0, 2 
	GOTO        L_convlng_txt27
	GOTO        L_convlng_txt28
L_convlng_txt17:
;conversores.h,135 :: 		
	RETURN      0
; end of _convlng_txt

_conv_dec:

;conversores.h,137 :: 		
;conversores.h,138 :: 		
	MOVLW       48
	SUBWF       FARG_conv_dec_unidade+0, 0 
	MOVWF       FLOC__conv_dec+0 
	MOVLW       48
	SUBWF       FARG_conv_dec_dezena+0, 0 
	MOVWF       R0 
	MOVLW       10
	MULWF       R0 
	MOVF        PRODL+0, 0 
	MOVWF       R0 
	MOVF        FLOC__conv_dec+0, 0 
	ADDWF       R0, 1 
;conversores.h,139 :: 		
	RETURN      0
; end of _conv_dec

_conv_hex:

;conversores.h,144 :: 		
;conversores.h,152 :: 		
	MOVLW       240
	ANDWF       FARG_conv_hex_i+0, 0 
	MOVWF       R2 
	MOVF        R2, 0 
	MOVWF       conv_hex_aux_n_L0+0 
;conversores.h,153 :: 		
	MOVF        R2, 0 
	MOVWF       R0 
	RRCF        R0, 1 
	BCF         R0, 7 
	RRCF        R0, 1 
	BCF         R0, 7 
	RRCF        R0, 1 
	BCF         R0, 7 
	RRCF        R0, 1 
	BCF         R0, 7 
	MOVF        R0, 0 
	MOVWF       conv_hex_aux_n_L0+0 
;conversores.h,154 :: 		
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       R1 
	MOVF        R1, 0 
	MOVWF       conv_hex_aux_n_L0+0 
;conversores.h,155 :: 		
	MOVF        R1, 0 
	SUBLW       57
	BTFSC       STATUS+0, 0 
	GOTO        L_conv_hex29
	MOVLW       7
	ADDWF       conv_hex_aux_n_L0+0, 1 
L_conv_hex29:
;conversores.h,156 :: 		
	MOVF        FARG_conv_hex_l+0, 0 
	MOVWF       FARG_Lcd_Chr_row+0 
	MOVF        FARG_conv_hex_c+0, 0 
	MOVWF       FARG_Lcd_Chr_column+0 
	MOVF        conv_hex_aux_n_L0+0, 0 
	MOVWF       FARG_Lcd_Chr_out_char+0 
	CALL        _Lcd_Chr+0, 0
;conversores.h,158 :: 		
	MOVLW       15
	ANDWF       FARG_conv_hex_i+0, 0 
	MOVWF       R0 
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       R1 
	MOVF        R1, 0 
	MOVWF       conv_hex_aux_n_L0+0 
;conversores.h,159 :: 		
	MOVF        R1, 0 
	SUBLW       57
	BTFSC       STATUS+0, 0 
	GOTO        L_conv_hex30
	MOVLW       7
	ADDWF       conv_hex_aux_n_L0+0, 1 
L_conv_hex30:
;conversores.h,161 :: 		
	MOVF        conv_hex_aux_n_L0+0, 0 
	MOVWF       FARG_Lcd_Chr_CP_out_char+0 
	CALL        _Lcd_Chr_CP+0, 0
;conversores.h,163 :: 		
	RETURN      0
; end of _conv_hex

_interrupt:

;Hexapod_VS1.c,84 :: 		void interrupt(){
;Hexapod_VS1.c,86 :: 		if (TMR0IF_bit){// Temporiza faixas continuas
	BTFSS       TMR0IF_bit+0, 2 
	GOTO        L_interrupt31
;Hexapod_VS1.c,87 :: 		if (theend){                     // Segunda interrupção pós periodo modulado
	BTFSS       _theend+0, BitPos(_theend+0) 
	GOTO        L_interrupt32
;Hexapod_VS1.c,88 :: 		SetAll;                       // Entra em periodo de nível alto
	MOVLW       7
	MOVWF       PORTC+0 
	MOVLW       255
	MOVWF       PORTD+0 
	BSF         PORTE+0, 0 
;Hexapod_VS1.c,89 :: 		Cont_pwm=0;                   // Limpa Contador do próximo
	CLRF        _Cont_pwm+0 
;Hexapod_VS1.c,90 :: 		theend=0;                     // Abaixa flag de periodo de nível alto
	BCF         _theend+0, BitPos(_theend+0) 
;Hexapod_VS1.c,91 :: 		T0PS0_bit=0;                  // Prescaler = 1:2
	BCF         T0PS0_bit+0, 0 
;Hexapod_VS1.c,92 :: 		TMR0H=0xFA;                   // Set Timer 0 periodo ~468(us)
	MOVLW       250
	MOVWF       TMR0H+0 
;Hexapod_VS1.c,93 :: 		TMR0L=0xFF;
	MOVLW       255
	MOVWF       TMR0L+0 
;Hexapod_VS1.c,94 :: 		}else{
	GOTO        L_interrupt33
L_interrupt32:
;Hexapod_VS1.c,95 :: 		TMR0IE_bit=0;           // Desativa timer 0
	BCF         TMR0IE_bit+0, 5 
;Hexapod_VS1.c,96 :: 		TMR0ON_bit=0;
	BCF         TMR0ON_bit+0, 7 
;Hexapod_VS1.c,97 :: 		T0PS0_bit=1;            // Prescaler = 1:4
	BSF         T0PS0_bit+0, 0 
;Hexapod_VS1.c,98 :: 		TMR0H=0x72;             // Set Timer 0 periodo ~17.4(ms)
	MOVLW       114
	MOVWF       TMR0H+0 
;Hexapod_VS1.c,99 :: 		TMR0L=0xFF;
	MOVLW       255
	MOVWF       TMR0L+0 
;Hexapod_VS1.c,100 :: 		TMR1ON_bit=1;           // Ativa timer 1
	BSF         TMR1ON_bit+0, 0 
;Hexapod_VS1.c,101 :: 		TMR1IE_bit=1;
	BSF         TMR1IE_bit+0, 0 
;Hexapod_VS1.c,102 :: 		theend=1;               // Levanta flag
	BSF         _theend+0, BitPos(_theend+0) 
;Hexapod_VS1.c,103 :: 		}
L_interrupt33:
;Hexapod_VS1.c,104 :: 		TMR0IF_bit=0;
	BCF         TMR0IF_bit+0, 2 
;Hexapod_VS1.c,105 :: 		}
L_interrupt31:
;Hexapod_VS1.c,106 :: 		if (TMR1IF_bit){// Temporiza faixa modulavel
	BTFSS       TMR1IF_bit+0, 0 
	GOTO        L_interrupt34
;Hexapod_VS1.c,107 :: 		Cont_pwm++;
	INCF        _Cont_pwm+0, 1 
;Hexapod_VS1.c,108 :: 		if (Cont_pwm==0){               // Verifica fim de periodo de modulação de largura
	MOVF        _Cont_pwm+0, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_interrupt35
;Hexapod_VS1.c,109 :: 		TMR1IE_bit=0;                // Desliga Timer 1
	BCF         TMR1IE_bit+0, 0 
;Hexapod_VS1.c,110 :: 		TMR1ON_bit=0;
	BCF         TMR1ON_bit+0, 0 
;Hexapod_VS1.c,111 :: 		TMR1H=255;                   // Set Timer 1 periodo ~1.84(us) + Tempo de instruções internas
	MOVLW       255
	MOVWF       TMR1H+0 
;Hexapod_VS1.c,112 :: 		TMR1L=220;
	MOVLW       220
	MOVWF       TMR1L+0 
;Hexapod_VS1.c,113 :: 		TMR1IF_bit=0;                // Limpa flag Interrupt timer 1
	BCF         TMR1IF_bit+0, 0 
;Hexapod_VS1.c,114 :: 		ClearAll;
	CLRF        PORTC+0 
	CLRF        PORTD+0 
	BCF         PORTE+0, 0 
;Hexapod_VS1.c,115 :: 		TMR0ON_bit=1;                // Ativa timer 0 * Obs.: theend=1 => Inicio de periodo nível baixo obrigatório.
	BSF         TMR0ON_bit+0, 7 
;Hexapod_VS1.c,116 :: 		TMR0IE_bit=1;
	BSF         TMR0IE_bit+0, 5 
;Hexapod_VS1.c,117 :: 		return;
	GOTO        L__interrupt72
;Hexapod_VS1.c,118 :: 		}
L_interrupt35:
;Hexapod_VS1.c,120 :: 		if (leg[0].DT1==Cont_pwm) S11=0;
	MOVF        _leg+0, 0 
	XORWF       _Cont_pwm+0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L_interrupt36
	BCF         PORTB+0, 0 
L_interrupt36:
;Hexapod_VS1.c,121 :: 		if (leg[0].DT2==Cont_pwm) S12=0;
	MOVF        _leg+1, 0 
	XORWF       _Cont_pwm+0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L_interrupt37
	BCF         PORTB+0, 1 
L_interrupt37:
;Hexapod_VS1.c,122 :: 		if (leg[0].DT3==Cont_pwm) S13=0;
	MOVF        _leg+2, 0 
	XORWF       _Cont_pwm+0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L_interrupt38
	BCF         PORTB+0, 2 
L_interrupt38:
;Hexapod_VS1.c,124 :: 		if (leg[1].DT1==Cont_pwm) S21=0;
	MOVF        _leg+3, 0 
	XORWF       _Cont_pwm+0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L_interrupt39
	BCF         PORTB+0, 3 
L_interrupt39:
;Hexapod_VS1.c,125 :: 		if (leg[1].DT2==Cont_pwm) S22=0;
	MOVF        _leg+4, 0 
	XORWF       _Cont_pwm+0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L_interrupt40
	BCF         PORTB+0, 4 
L_interrupt40:
;Hexapod_VS1.c,126 :: 		if (leg[1].DT3==Cont_pwm) S23=0;
	MOVF        _leg+5, 0 
	XORWF       _Cont_pwm+0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L_interrupt41
	BCF         PORTB+0, 5 
L_interrupt41:
;Hexapod_VS1.c,128 :: 		if (leg[2].DT1==Cont_pwm) S31=0;
	MOVF        _leg+6, 0 
	XORWF       _Cont_pwm+0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L_interrupt42
	BCF         PORTC+0, 0 
L_interrupt42:
;Hexapod_VS1.c,129 :: 		if (leg[2].DT2==Cont_pwm) S32=0;
	MOVF        _leg+7, 0 
	XORWF       _Cont_pwm+0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L_interrupt43
	BCF         PORTC+0, 1 
L_interrupt43:
;Hexapod_VS1.c,130 :: 		if (leg[2].DT3==Cont_pwm) S33=0;
	MOVF        _leg+8, 0 
	XORWF       _Cont_pwm+0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L_interrupt44
	BCF         PORTC+0, 2 
L_interrupt44:
;Hexapod_VS1.c,132 :: 		if (leg[3].DT1==Cont_pwm) S41=0;
	MOVF        _leg+9, 0 
	XORWF       _Cont_pwm+0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L_interrupt45
	BCF         PORTD+0, 0 
L_interrupt45:
;Hexapod_VS1.c,133 :: 		if (leg[3].DT2==Cont_pwm) S42=0;
	MOVF        _leg+10, 0 
	XORWF       _Cont_pwm+0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L_interrupt46
	BCF         PORTD+0, 1 
L_interrupt46:
;Hexapod_VS1.c,134 :: 		if (leg[3].DT3==Cont_pwm) S43=0;
	MOVF        _leg+11, 0 
	XORWF       _Cont_pwm+0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L_interrupt47
	BCF         PORTD+0, 2 
L_interrupt47:
;Hexapod_VS1.c,136 :: 		if (leg[4].DT1==Cont_pwm) S51=0;
	MOVF        _leg+12, 0 
	XORWF       _Cont_pwm+0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L_interrupt48
	BCF         PORTD+0, 3 
L_interrupt48:
;Hexapod_VS1.c,137 :: 		if (leg[4].DT2==Cont_pwm) S52=0;
	MOVF        _leg+13, 0 
	XORWF       _Cont_pwm+0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L_interrupt49
	BCF         PORTD+0, 4 
L_interrupt49:
;Hexapod_VS1.c,138 :: 		if (leg[4].DT3==Cont_pwm) S53=0;
	MOVF        _leg+14, 0 
	XORWF       _Cont_pwm+0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L_interrupt50
	BCF         PORTD+0, 5 
L_interrupt50:
;Hexapod_VS1.c,140 :: 		if (leg[5].DT1==Cont_pwm) S61=0;
	MOVF        _leg+15, 0 
	XORWF       _Cont_pwm+0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L_interrupt51
	BCF         PORTD+0, 6 
L_interrupt51:
;Hexapod_VS1.c,141 :: 		if (leg[5].DT2==Cont_pwm) S62=0;
	MOVF        _leg+16, 0 
	XORWF       _Cont_pwm+0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L_interrupt52
	BCF         PORTD+0, 7 
L_interrupt52:
;Hexapod_VS1.c,142 :: 		if (leg[5].DT3==Cont_pwm) S63=0;
	MOVF        _leg+17, 0 
	XORWF       _Cont_pwm+0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L_interrupt53
	BCF         PORTE+0, 0 
L_interrupt53:
;Hexapod_VS1.c,145 :: 		TMR1H=255;                      // Set Timer 1 periodo ~1.84(us) + Tempo de instruções internas
	MOVLW       255
	MOVWF       TMR1H+0 
;Hexapod_VS1.c,146 :: 		TMR1L=220;
	MOVLW       220
	MOVWF       TMR1L+0 
;Hexapod_VS1.c,147 :: 		TMR1IF_bit=0;
	BCF         TMR1IF_bit+0, 0 
;Hexapod_VS1.c,148 :: 		}
L_interrupt34:
;Hexapod_VS1.c,149 :: 		}
L__interrupt72:
	RETFIE      1
; end of _interrupt

_Pausa:

;Hexapod_VS1.c,166 :: 		void Pausa(unsigned short time){
;Hexapod_VS1.c,168 :: 		for (Contador=0; Contador<time; Contador++){
	CLRF        R1 
L_Pausa54:
	MOVF        FARG_Pausa_time+0, 0 
	SUBWF       R1, 0 
	BTFSC       STATUS+0, 0 
	GOTO        L_Pausa55
;Hexapod_VS1.c,169 :: 		Delay_ms(10);
	MOVLW       65
	MOVWF       R12, 0
	MOVLW       238
	MOVWF       R13, 0
L_Pausa57:
	DECFSZ      R13, 1, 0
	BRA         L_Pausa57
	DECFSZ      R12, 1, 0
	BRA         L_Pausa57
	NOP
;Hexapod_VS1.c,168 :: 		for (Contador=0; Contador<time; Contador++){
	INCF        R1, 1 
;Hexapod_VS1.c,170 :: 		}
	GOTO        L_Pausa54
L_Pausa55:
;Hexapod_VS1.c,171 :: 		}
	RETURN      0
; end of _Pausa

_Executa_Tabela1:

;Hexapod_VS1.c,173 :: 		void Executa_Tabela1(unsigned short Tempo){
;Hexapod_VS1.c,176 :: 		for (Indexador=0;Indexador<Length;Indexador++){
	CLRF        Executa_Tabela1_Indexador_L0+0 
L_Executa_Tabela158:
	MOVLW       10
	SUBWF       Executa_Tabela1_Indexador_L0+0, 0 
	BTFSC       STATUS+0, 0 
	GOTO        L_Executa_Tabela159
;Hexapod_VS1.c,177 :: 		leg[0].DT1 = Tab1[Indexador][0][0];
	MOVF        Executa_Tabela1_Indexador_L0+0, 0 
	MOVWF       R0 
	MOVLW       0
	MOVWF       R1 
	MOVWF       R2 
	MOVWF       R3 
	MOVLW       18
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	CALL        _Mul_32x32_U+0, 0
	MOVLW       _Tab1+0
	ADDWF       R0, 0 
	MOVWF       R4 
	MOVLW       hi_addr(_Tab1+0)
	ADDWFC      R1, 0 
	MOVWF       R5 
	MOVLW       higher_addr(_Tab1+0)
	ADDWFC      R2, 0 
	MOVWF       R6 
	MOVF        R4, 0 
	MOVWF       TBLPTRL 
	MOVF        R5, 0 
	MOVWF       TBLPTRH 
	MOVF        R6, 0 
	MOVWF       TBLPTRU 
	TBLRD*+
	MOVFF       TABLAT+0, R0
	MOVF        R0, 0 
	MOVWF       _leg+0 
;Hexapod_VS1.c,178 :: 		leg[0].DT2 = Tab1[Indexador][0][1];
	MOVLW       1
	ADDWF       R4, 0 
	MOVWF       TBLPTRL 
	MOVLW       0
	ADDWFC      R5, 0 
	MOVWF       TBLPTRH 
	MOVLW       0
	ADDWFC      R6, 0 
	MOVWF       TBLPTRU 
	TBLRD*+
	MOVFF       TABLAT+0, R0
	MOVF        R0, 0 
	MOVWF       _leg+1 
;Hexapod_VS1.c,179 :: 		leg[0].DT3 = Tab1[Indexador][0][2];
	MOVLW       2
	ADDWF       R4, 0 
	MOVWF       TBLPTRL 
	MOVLW       0
	ADDWFC      R5, 0 
	MOVWF       TBLPTRH 
	MOVLW       0
	ADDWFC      R6, 0 
	MOVWF       TBLPTRU 
	TBLRD*+
	MOVFF       TABLAT+0, R0
	MOVF        R0, 0 
	MOVWF       _leg+2 
;Hexapod_VS1.c,181 :: 		leg[1].DT1 = Tab1[Indexador][1][0];
	MOVLW       3
	ADDWF       R4, 0 
	MOVWF       TBLPTRL 
	MOVLW       0
	ADDWFC      R5, 0 
	MOVWF       TBLPTRH 
	MOVLW       0
	ADDWFC      R6, 0 
	MOVWF       TBLPTRU 
	TBLRD*+
	MOVFF       TABLAT+0, R0
	MOVF        R0, 0 
	MOVWF       _leg+3 
;Hexapod_VS1.c,182 :: 		leg[1].DT2 = Tab1[Indexador][1][1];
	MOVLW       3
	ADDWF       R4, 0 
	MOVWF       R0 
	MOVLW       0
	ADDWFC      R5, 0 
	MOVWF       R1 
	MOVLW       0
	ADDWFC      R6, 0 
	MOVWF       R2 
	MOVLW       1
	ADDWF       R0, 0 
	MOVWF       TBLPTRL 
	MOVLW       0
	ADDWFC      R1, 0 
	MOVWF       TBLPTRH 
	MOVLW       0
	ADDWFC      R2, 0 
	MOVWF       TBLPTRU 
	TBLRD*+
	MOVFF       TABLAT+0, R0
	MOVF        R0, 0 
	MOVWF       _leg+4 
;Hexapod_VS1.c,183 :: 		leg[1].DT3 = Tab1[Indexador][1][2];
	MOVLW       3
	ADDWF       R4, 0 
	MOVWF       R0 
	MOVLW       0
	ADDWFC      R5, 0 
	MOVWF       R1 
	MOVLW       0
	ADDWFC      R6, 0 
	MOVWF       R2 
	MOVLW       2
	ADDWF       R0, 0 
	MOVWF       TBLPTRL 
	MOVLW       0
	ADDWFC      R1, 0 
	MOVWF       TBLPTRH 
	MOVLW       0
	ADDWFC      R2, 0 
	MOVWF       TBLPTRU 
	TBLRD*+
	MOVFF       TABLAT+0, R0
	MOVF        R0, 0 
	MOVWF       _leg+5 
;Hexapod_VS1.c,185 :: 		leg[2].DT1 = Tab1[Indexador][2][0];
	MOVLW       6
	ADDWF       R4, 0 
	MOVWF       TBLPTRL 
	MOVLW       0
	ADDWFC      R5, 0 
	MOVWF       TBLPTRH 
	MOVLW       0
	ADDWFC      R6, 0 
	MOVWF       TBLPTRU 
	TBLRD*+
	MOVFF       TABLAT+0, R0
	MOVF        R0, 0 
	MOVWF       _leg+6 
;Hexapod_VS1.c,186 :: 		leg[2].DT2 = Tab1[Indexador][2][1];
	MOVLW       6
	ADDWF       R4, 0 
	MOVWF       R0 
	MOVLW       0
	ADDWFC      R5, 0 
	MOVWF       R1 
	MOVLW       0
	ADDWFC      R6, 0 
	MOVWF       R2 
	MOVLW       1
	ADDWF       R0, 0 
	MOVWF       TBLPTRL 
	MOVLW       0
	ADDWFC      R1, 0 
	MOVWF       TBLPTRH 
	MOVLW       0
	ADDWFC      R2, 0 
	MOVWF       TBLPTRU 
	TBLRD*+
	MOVFF       TABLAT+0, R0
	MOVF        R0, 0 
	MOVWF       _leg+7 
;Hexapod_VS1.c,187 :: 		leg[2].DT3 = Tab1[Indexador][2][2];
	MOVLW       6
	ADDWF       R4, 0 
	MOVWF       R0 
	MOVLW       0
	ADDWFC      R5, 0 
	MOVWF       R1 
	MOVLW       0
	ADDWFC      R6, 0 
	MOVWF       R2 
	MOVLW       2
	ADDWF       R0, 0 
	MOVWF       TBLPTRL 
	MOVLW       0
	ADDWFC      R1, 0 
	MOVWF       TBLPTRH 
	MOVLW       0
	ADDWFC      R2, 0 
	MOVWF       TBLPTRU 
	TBLRD*+
	MOVFF       TABLAT+0, R0
	MOVF        R0, 0 
	MOVWF       _leg+8 
;Hexapod_VS1.c,189 :: 		leg[3].DT1 = Tab1[Indexador][3][0];
	MOVLW       9
	ADDWF       R4, 0 
	MOVWF       TBLPTRL 
	MOVLW       0
	ADDWFC      R5, 0 
	MOVWF       TBLPTRH 
	MOVLW       0
	ADDWFC      R6, 0 
	MOVWF       TBLPTRU 
	TBLRD*+
	MOVFF       TABLAT+0, R0
	MOVF        R0, 0 
	MOVWF       _leg+9 
;Hexapod_VS1.c,190 :: 		leg[3].DT2 = Tab1[Indexador][3][1];
	MOVLW       9
	ADDWF       R4, 0 
	MOVWF       R0 
	MOVLW       0
	ADDWFC      R5, 0 
	MOVWF       R1 
	MOVLW       0
	ADDWFC      R6, 0 
	MOVWF       R2 
	MOVLW       1
	ADDWF       R0, 0 
	MOVWF       TBLPTRL 
	MOVLW       0
	ADDWFC      R1, 0 
	MOVWF       TBLPTRH 
	MOVLW       0
	ADDWFC      R2, 0 
	MOVWF       TBLPTRU 
	TBLRD*+
	MOVFF       TABLAT+0, R0
	MOVF        R0, 0 
	MOVWF       _leg+10 
;Hexapod_VS1.c,191 :: 		leg[3].DT3 = Tab1[Indexador][3][2];
	MOVLW       9
	ADDWF       R4, 0 
	MOVWF       R0 
	MOVLW       0
	ADDWFC      R5, 0 
	MOVWF       R1 
	MOVLW       0
	ADDWFC      R6, 0 
	MOVWF       R2 
	MOVLW       2
	ADDWF       R0, 0 
	MOVWF       TBLPTRL 
	MOVLW       0
	ADDWFC      R1, 0 
	MOVWF       TBLPTRH 
	MOVLW       0
	ADDWFC      R2, 0 
	MOVWF       TBLPTRU 
	TBLRD*+
	MOVFF       TABLAT+0, R0
	MOVF        R0, 0 
	MOVWF       _leg+11 
;Hexapod_VS1.c,193 :: 		leg[4].DT1 = Tab1[Indexador][4][0];
	MOVLW       12
	ADDWF       R4, 0 
	MOVWF       TBLPTRL 
	MOVLW       0
	ADDWFC      R5, 0 
	MOVWF       TBLPTRH 
	MOVLW       0
	ADDWFC      R6, 0 
	MOVWF       TBLPTRU 
	TBLRD*+
	MOVFF       TABLAT+0, R0
	MOVF        R0, 0 
	MOVWF       _leg+12 
;Hexapod_VS1.c,194 :: 		leg[4].DT2 = Tab1[Indexador][4][1];
	MOVLW       12
	ADDWF       R4, 0 
	MOVWF       R0 
	MOVLW       0
	ADDWFC      R5, 0 
	MOVWF       R1 
	MOVLW       0
	ADDWFC      R6, 0 
	MOVWF       R2 
	MOVLW       1
	ADDWF       R0, 0 
	MOVWF       TBLPTRL 
	MOVLW       0
	ADDWFC      R1, 0 
	MOVWF       TBLPTRH 
	MOVLW       0
	ADDWFC      R2, 0 
	MOVWF       TBLPTRU 
	TBLRD*+
	MOVFF       TABLAT+0, R0
	MOVF        R0, 0 
	MOVWF       _leg+13 
;Hexapod_VS1.c,195 :: 		leg[4].DT3 = Tab1[Indexador][4][2];
	MOVLW       12
	ADDWF       R4, 0 
	MOVWF       R0 
	MOVLW       0
	ADDWFC      R5, 0 
	MOVWF       R1 
	MOVLW       0
	ADDWFC      R6, 0 
	MOVWF       R2 
	MOVLW       2
	ADDWF       R0, 0 
	MOVWF       TBLPTRL 
	MOVLW       0
	ADDWFC      R1, 0 
	MOVWF       TBLPTRH 
	MOVLW       0
	ADDWFC      R2, 0 
	MOVWF       TBLPTRU 
	TBLRD*+
	MOVFF       TABLAT+0, R0
	MOVF        R0, 0 
	MOVWF       _leg+14 
;Hexapod_VS1.c,197 :: 		leg[5].DT1 = Tab1[Indexador][5][0];
	MOVLW       15
	ADDWF       R4, 0 
	MOVWF       TBLPTRL 
	MOVLW       0
	ADDWFC      R5, 0 
	MOVWF       TBLPTRH 
	MOVLW       0
	ADDWFC      R6, 0 
	MOVWF       TBLPTRU 
	TBLRD*+
	MOVFF       TABLAT+0, R0
	MOVF        R0, 0 
	MOVWF       _leg+15 
;Hexapod_VS1.c,198 :: 		leg[5].DT2 = Tab1[Indexador][5][1];
	MOVLW       15
	ADDWF       R4, 0 
	MOVWF       R0 
	MOVLW       0
	ADDWFC      R5, 0 
	MOVWF       R1 
	MOVLW       0
	ADDWFC      R6, 0 
	MOVWF       R2 
	MOVLW       1
	ADDWF       R0, 0 
	MOVWF       TBLPTRL 
	MOVLW       0
	ADDWFC      R1, 0 
	MOVWF       TBLPTRH 
	MOVLW       0
	ADDWFC      R2, 0 
	MOVWF       TBLPTRU 
	TBLRD*+
	MOVFF       TABLAT+0, R0
	MOVF        R0, 0 
	MOVWF       _leg+16 
;Hexapod_VS1.c,199 :: 		leg[5].DT3 = Tab1[Indexador][5][2];
	MOVLW       15
	ADDWF       R4, 0 
	MOVWF       R0 
	MOVLW       0
	ADDWFC      R5, 0 
	MOVWF       R1 
	MOVLW       0
	ADDWFC      R6, 0 
	MOVWF       R2 
	MOVLW       2
	ADDWF       R0, 0 
	MOVWF       TBLPTRL 
	MOVLW       0
	ADDWFC      R1, 0 
	MOVWF       TBLPTRH 
	MOVLW       0
	ADDWFC      R2, 0 
	MOVWF       TBLPTRU 
	TBLRD*+
	MOVFF       TABLAT+0, R0
	MOVF        R0, 0 
	MOVWF       _leg+17 
;Hexapod_VS1.c,201 :: 		Pausa(Tempo);
	MOVF        FARG_Executa_Tabela1_Tempo+0, 0 
	MOVWF       FARG_Pausa_time+0 
	CALL        _Pausa+0, 0
;Hexapod_VS1.c,176 :: 		for (Indexador=0;Indexador<Length;Indexador++){
	INCF        Executa_Tabela1_Indexador_L0+0, 1 
;Hexapod_VS1.c,202 :: 		}
	GOTO        L_Executa_Tabela158
L_Executa_Tabela159:
;Hexapod_VS1.c,203 :: 		}
	RETURN      0
; end of _Executa_Tabela1

_main:

;Hexapod_VS1.c,208 :: 		void main() {
;Hexapod_VS1.c,211 :: 		init_sis(); // Rotina de inicialização do sistema
	CALL        _init_sis+0, 0
;Hexapod_VS1.c,212 :: 		Cmd_rec=0;
	BCF         main_Cmd_rec_L0+0, BitPos(main_Cmd_rec_L0+0) 
;Hexapod_VS1.c,213 :: 		do{
L_main61:
;Hexapod_VS1.c,215 :: 		if (Cmd_rec){
	BTFSS       main_Cmd_rec_L0+0, BitPos(main_Cmd_rec_L0+0) 
	GOTO        L_main64
;Hexapod_VS1.c,216 :: 		switch (Opt){
	GOTO        L_main65
;Hexapod_VS1.c,217 :: 		case 0x01:
L_main67:
;Hexapod_VS1.c,218 :: 		Executa_Tabela1(10);
	MOVLW       10
	MOVWF       FARG_Executa_Tabela1_Tempo+0 
	CALL        _Executa_Tabela1+0, 0
;Hexapod_VS1.c,219 :: 		break;
	GOTO        L_main66
;Hexapod_VS1.c,220 :: 		default:
L_main68:
;Hexapod_VS1.c,221 :: 		break;
	GOTO        L_main66
;Hexapod_VS1.c,222 :: 		}
L_main65:
	MOVF        main_Opt_L0+0, 0 
	XORLW       1
	BTFSC       STATUS+0, 2 
	GOTO        L_main67
	GOTO        L_main68
L_main66:
;Hexapod_VS1.c,223 :: 		}
L_main64:
;Hexapod_VS1.c,225 :: 		}while(1);
	GOTO        L_main61
;Hexapod_VS1.c,226 :: 		}
	GOTO        $+0
; end of _main

_init_sis:

;Hexapod_VS1.c,233 :: 		void init_sis(){
;Hexapod_VS1.c,236 :: 		ADCON1 = 0x0C;  // Configura PORTA
	MOVLW       12
	MOVWF       ADCON1+0 
;Hexapod_VS1.c,237 :: 		CMCON  = 7;     // Desabilita comparadoress
	MOVLW       7
	MOVWF       CMCON+0 
;Hexapod_VS1.c,239 :: 		TRISA = 0x07;
	MOVLW       7
	MOVWF       TRISA+0 
;Hexapod_VS1.c,240 :: 		TRISB = 0;
	CLRF        TRISB+0 
;Hexapod_VS1.c,241 :: 		TRISC = 0;
	CLRF        TRISC+0 
;Hexapod_VS1.c,242 :: 		TRISD = 0;
	CLRF        TRISD+0 
;Hexapod_VS1.c,243 :: 		TRISE = 0;
	CLRF        TRISE+0 
;Hexapod_VS1.c,245 :: 		LATA = 0;
	CLRF        LATA+0 
;Hexapod_VS1.c,246 :: 		LATB = 0;
	CLRF        LATB+0 
;Hexapod_VS1.c,247 :: 		LATC = 0;
	CLRF        LATC+0 
;Hexapod_VS1.c,248 :: 		LATD = 0;
	CLRF        LATD+0 
;Hexapod_VS1.c,249 :: 		LATE = 0;
	CLRF        LATE+0 
;Hexapod_VS1.c,251 :: 		PORTA = 0;
	CLRF        PORTA+0 
;Hexapod_VS1.c,252 :: 		PORTC = 0;
	CLRF        PORTC+0 
;Hexapod_VS1.c,253 :: 		PORTB = 0;
	CLRF        PORTB+0 
;Hexapod_VS1.c,254 :: 		PORTD = 0;
	CLRF        PORTD+0 
;Hexapod_VS1.c,255 :: 		PORTE = 0;
	CLRF        PORTE+0 
;Hexapod_VS1.c,257 :: 		UCON.B3 = 0;  // Desabilata USB
	BCF         UCON+0, 3 
;Hexapod_VS1.c,258 :: 		UCFG.B3 = 1;
	BSF         UCFG+0, 3 
;Hexapod_VS1.c,259 :: 		HLVDEN_bit = 0;
	BCF         HLVDEN_bit+0, 4 
;Hexapod_VS1.c,260 :: 		CVRCON = 0;
	CLRF        CVRCON+0 
;Hexapod_VS1.c,263 :: 		INTCON  = 0b11100000;                                                      // Cofigura chave geral de interrupções e INT0
	MOVLW       224
	MOVWF       INTCON+0 
;Hexapod_VS1.c,265 :: 		INTCON2 = 0b11110000;                                                      // Desabilita pull-ups, confg. INTEDGs rising edge
	MOVLW       240
	MOVWF       INTCON2+0 
;Hexapod_VS1.c,267 :: 		INTCON3 = 0b01000000;
	MOVLW       64
	MOVWF       INTCON3+0 
;Hexapod_VS1.c,270 :: 		PIE1 = 0b00000000;
	CLRF        PIE1+0 
;Hexapod_VS1.c,272 :: 		PIE2 = 0b00000000;
	CLRF        PIE2+0 
;Hexapod_VS1.c,275 :: 		PIR1 = 0;
	CLRF        PIR1+0 
;Hexapod_VS1.c,277 :: 		PIR2 = 0;
	CLRF        PIR2+0 
;Hexapod_VS1.c,280 :: 		IPR1 = 0b00000000;
	CLRF        IPR1+0 
;Hexapod_VS1.c,283 :: 		IPR2 = 0b00000000;
	CLRF        IPR2+0 
;Hexapod_VS1.c,286 :: 		T0CON = 0b10000000;
	MOVLW       128
	MOVWF       T0CON+0 
;Hexapod_VS1.c,288 :: 		T1CON = 0b10000001;
	MOVLW       129
	MOVWF       T1CON+0 
;Hexapod_VS1.c,294 :: 		for (i=0;i<6;i++){
	CLRF        init_sis_i_L0+0 
L_init_sis69:
	MOVLW       6
	SUBWF       init_sis_i_L0+0, 0 
	BTFSC       STATUS+0, 0 
	GOTO        L_init_sis70
;Hexapod_VS1.c,295 :: 		leg[i].DT1=128;
	MOVF        init_sis_i_L0+0, 0 
	MOVWF       R0 
	MOVLW       0
	MOVWF       R1 
	MOVLW       3
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Mul_16x16_U+0, 0
	MOVLW       _leg+0
	ADDWF       R0, 0 
	MOVWF       FSR1L 
	MOVLW       hi_addr(_leg+0)
	ADDWFC      R1, 0 
	MOVWF       FSR1H 
	MOVLW       128
	MOVWF       POSTINC1+0 
;Hexapod_VS1.c,296 :: 		leg[i].DT2=128;
	MOVF        init_sis_i_L0+0, 0 
	MOVWF       R0 
	MOVLW       0
	MOVWF       R1 
	MOVLW       3
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Mul_16x16_U+0, 0
	MOVLW       _leg+0
	ADDWF       R0, 1 
	MOVLW       hi_addr(_leg+0)
	ADDWFC      R1, 1 
	MOVLW       1
	ADDWF       R0, 0 
	MOVWF       FSR1L 
	MOVLW       0
	ADDWFC      R1, 0 
	MOVWF       FSR1H 
	MOVLW       128
	MOVWF       POSTINC1+0 
;Hexapod_VS1.c,297 :: 		leg[i].DT3=128;
	MOVF        init_sis_i_L0+0, 0 
	MOVWF       R0 
	MOVLW       0
	MOVWF       R1 
	MOVLW       3
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Mul_16x16_U+0, 0
	MOVLW       _leg+0
	ADDWF       R0, 1 
	MOVLW       hi_addr(_leg+0)
	ADDWFC      R1, 1 
	MOVLW       2
	ADDWF       R0, 0 
	MOVWF       FSR1L 
	MOVLW       0
	ADDWFC      R1, 0 
	MOVWF       FSR1H 
	MOVLW       128
	MOVWF       POSTINC1+0 
;Hexapod_VS1.c,294 :: 		for (i=0;i<6;i++){
	INCF        init_sis_i_L0+0, 1 
;Hexapod_VS1.c,298 :: 		}
	GOTO        L_init_sis69
L_init_sis70:
;Hexapod_VS1.c,299 :: 		}
	RETURN      0
; end of _init_sis
