;
; Praktikum1.asm
;
; Created: 15.10.2019 15:06:30
; Author : woutv
;

.include "m8def.inc"	; Prozessordefinitionen laden

.org 0x000		; Reset Vector
	rjmp start
;Rest der Tabelle bleibt ungenutzt


start:
	ldi r16, LOW( RAMEND ) ; laedt den low wert 
	out SPL, r16
	ldi r17, HIGH( RAMEND )
	out SPH, r17

	