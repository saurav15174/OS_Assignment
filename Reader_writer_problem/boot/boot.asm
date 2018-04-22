bits 16 ;
org 0x7c00 ;


jmp main ;


Message db "Hello world!", 0x0
MessageB db "saurav 2015174", 0x0
AnyKey db "Press any key to reboot",0x0;

Println:
    lodsb ;Load string
    or al,al
    jz complete 
    mov ah,0x0e
    int 0x10 ;BIOS Interrupt 0x10
    jmp Println ;Loop
complete:
    call PrintNwL

    PrintNwL:
    mov al,0 ;null terminator '\0'
    stosb    ; Store string

    mov ah, 0x0E
    mov al, 0x0D
    int 0x10
    mov al, 0x0A
    int 0x10
    ret

Reboot:
    mov si, AnyKey
    call Println
    call GetPressedKey

    db 0x0ea
    dw 0x0000
    dw 0xffff
    GetPressedKey:
    mov ah, 0
    int 0x16   ;
    ret

    main:
    cli ; Clear interrupts
    ;Setup stack segments
    mov ax,cs
    mov ds,ax
    mov es,ax
    mov ss,ax
    sti ;Enable interrupts

    ;Print the first characters
    mov si, Message
    call Println

    mov si,MessageB
    call Println

    call PrintNwL
    call PrintNwL

    call Reboot

    times 510 - ($-$$) db 0 ;
    dw 0xAA55