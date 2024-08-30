data segment
    ; some data
data ends

stack segment
    ; stack 
stack ends

code segment
    assume cs:code, ds:data, ss:stacks
start:

    ; codes

code ends
    end start
