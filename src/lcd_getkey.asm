; lcd_getkey.asm - TI-86 key input routine
;
; Provides:
;   lcd_getkey  - returns raw TI-86 scancode (no ASCII translation)
;   _lcd_getkey - C-compatible alias
;
; ROM routine used:
;   $55AA _getkey   - block until keypress, return scancode in A
;
    MODULE lcd_getkey

    PUBLIC  lcd_getkey
    PUBLIC  _lcd_getkey

    EXTERN  tiei            ; from ti86_crt0: ei + restore alt regs
    EXTERN  tidi            ; from ti86_crt0: di + save alt regs

; ---------------------------------------------------------------------------
; lcd_getkey()
;   No arguments.  Blocks until a keypress is available.
;   Returns the RAW TI-86 scancode (no ASCII translation).
;   Exit:   HL = raw scancode (H=0, L=scancode)
; ---------------------------------------------------------------------------

_lcd_getkey:
lcd_getkey:
    call    tiei            ; enable interrupts (needed by _getkey)
raw_key_loop:
    call    $55AA           ; _getkey - blocks until key, scancode in A
    and     a               ; zero?
    jr      z, raw_key_loop ; retry if 0
    call    tidi            ; disable interrupts
    ld      h, 0
    ld      l, a            ; HL = raw scancode
    ret
