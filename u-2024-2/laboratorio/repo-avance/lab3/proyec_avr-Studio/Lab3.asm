;------------- definiciones e includes ------------------------------
;INCLUDE "m1280def.inc" ; Incluir definiciones de Registros para 1280

.INCLUDE "m2560def.inc" ; Incluir definiciones de Registros para 2560

.equ INIT_VALUE = 0 ; Valor inicial R24

;------------- inicializar ------------------------------------------
ldi R24,INIT_VALUE
;------------- implementar ------------------------------------------
;call delay1uS
;call delay1mS
;call delay1S
;call myRand ; Retorna valor en R25
;------------- ciclo principal --------------------------------------

rcall miRetardo

nop


arriba: inc R24
        cpi R24,10
        breq abajo
        out PORTA,R24
        rjmp arriba


abajo: dec R24
        cpi R24,0
        breq arriba
        out PORTA,R24
        rjmp abajo




;creo que es retardo de 103uS

miRetardo: 
	clr r25 ; 
	clr r26 ;
	clr r23	;1 ciclo -> R24 -> R23 
	ldi r23,5 ;-> 1 -> x
	ldi r26, 7
	;--------
	;5 ciclos total
nxt0:
	nop ; ->1x
	nop; 1x
	nop ;1x
	ldi r25, 8 ;1x
	;-------
	;4x
	
nxt1:
	dec r26 ;1zyx
	nop ;1zyx
	nop ;1xyz
	brne nxt1 ; 2xy(z-1)
	;----------
	;3xyz + 2xy(z-1)
	
nxt2:
	ldi r26,7 ;-> 1xy
	nop ; 1xy
	nop ;1xy
	dec r25	;-> 1xy
	brne nxt1 ; 2x(y-1)
	;---------------------
	;4xy + 2x(y-1)

	dec r23 ;x -> 1x
	nop ; 1x
	brne nxt0 ;-> 2(x-1)

	ret ;5 ciclos

	;-------------
	;2x+2(x-1)+5

	;--------------------------
	;7x + 4xy + 5xyz + 12 



retardo1mS:

	; rcall -> 4 ciclos
	clr r25 ; x -> 1
	clr r26 ; y  -> 1
	clr r23 ; z -> 1


	; para un retardo de 1mS es necesario 16,000 ticks 
	; esto porque (1x10^-3)*(16x10^6)  -> 16,000 


	; tomamos nuestra muestra esquelto 

	ldi r25, x
	ldi r26, y 
	nxt0:
		dec r25
		brne nxt0

		nxt1:

			dec r26
			brne nxt1

	
	ret ; -> 5 ciclos














