;data segment
    ; some data
;data ends

;stack segment
    ; stack 
;stack ends

code segment
    assume cs:code ;, ds:data, ss:stacks
start:



    ; codes



    ; return control to the terminal
    mov ah, 4ch
    int 21h

code ends
    end start
