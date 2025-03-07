;/******************************************************************************
; * @copyright SPDX-License-Identifier: Apache-2.0
; * @copyright Copyright (C) 2014 Nuvoton Technology Corp. All rights reserved.
;*****************************************************************************/



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;







Stack_Size      EQU     0x00000400

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000000

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors

__Vectors       DCD     __initial_sp              ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
                DCD     NMI_Handler               ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler

                ; External Interrupts
                                                  ; maximum of 32 External Interrupts are possible
                DCD     BOD_IRQHandler  
                DCD     WDT_IRQHandler  
                DCD     EINT0_IRQHandler
                DCD     EINT1_IRQHandler
                DCD     GPAB_IRQHandler 
                DCD     GPCDEF_IRQHandler
                DCD     Default_Handler 
                DCD     Default_Handler 
                DCD     TMR0_IRQHandler 
                DCD     TMR1_IRQHandler 
                DCD     TMR2_IRQHandler 
                DCD     TMR3_IRQHandler 
                DCD     UART02_IRQHandler
                DCD     UART1_IRQHandler
                DCD     SPI0_IRQHandler 
                DCD     UART3_IRQHandler 
                DCD     UART4_IRQHandler 
                DCD     UART5_IRQHandler 
                DCD     I2C0_IRQHandler 
                DCD     I2C1_IRQHandler 
                DCD     CAN0_IRQHandler 
                DCD     CAN1_IRQHandler
                DCD     PWM0_IRQHandler
                DCD     PWM1_IRQHandler
                DCD     BPWM0_IRQHandler
                DCD     BPWM1_IRQHandler
                DCD     BRAKE0_IRQHandler
                DCD     BRAKE1_IRQHandler
                DCD     PWRWU_IRQHandler
                DCD     ADC_IRQHandler
                DCD     CKD_IRQHandler  
                DCD     RTC_IRQHandler  
                
                
                
                
                
                
                
                AREA    |.text|, CODE, READONLY
                
                
                
; Reset Handler 
                
                ENTRY
                
Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit
                IMPORT  __main

                LDR     R0, =0x50000100
                ; Unlock Register                
                LDR     R1, =0x59
                STR     R1, [R0]
                LDR     R1, =0x16
                STR     R1, [R0]
                LDR     R1, =0x88
                STR     R1, [R0]

                ; Init POR
                LDR     R2, =0x50000024
                LDR     R1, =0x00005AA5
                STR     R1, [R2]

                ; Lock register
                MOVS    R1, #0
                STR     R1, [R0]                
                
                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__main
                BX      R0
                ENDP
                
                
; Dummy Exception Handlers (infinite loops which can be modified)                
                
NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                IMPORT  ProcessHardFault
                EXPORT  HardFault_Handler         [WEAK]
                MOV     R0, LR                 
                MRS     R1, MSP                
                MRS     R2, PSP                
                LDR     R3, =ProcessHardFault 
                BLX     R3                     
                BX      R0                     
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  BOD_IRQHandler            [WEAK]
                EXPORT  WDT_IRQHandler            [WEAK]
                EXPORT  EINT0_IRQHandler          [WEAK]
                EXPORT  EINT1_IRQHandler          [WEAK]
                EXPORT  GPAB_IRQHandler           [WEAK]
                EXPORT  GPCDEF_IRQHandler         [WEAK]
                EXPORT  TMR0_IRQHandler           [WEAK]
                EXPORT  TMR1_IRQHandler           [WEAK]
                EXPORT  TMR2_IRQHandler           [WEAK]
                EXPORT  TMR3_IRQHandler           [WEAK]
                EXPORT  UART02_IRQHandler         [WEAK]
                EXPORT  UART1_IRQHandler          [WEAK]
                EXPORT  SPI0_IRQHandler           [WEAK]
                EXPORT  UART3_IRQHandler          [WEAK]
                EXPORT  UART4_IRQHandler          [WEAK]
                EXPORT  UART5_IRQHandler          [WEAK]
                EXPORT  I2C0_IRQHandler           [WEAK]
                EXPORT  I2C1_IRQHandler           [WEAK]
                EXPORT  CAN0_IRQHandler           [WEAK]
                EXPORT  CAN1_IRQHandler           [WEAK] 
                EXPORT  PWM0_IRQHandler           [WEAK]                               
                EXPORT  PWM1_IRQHandler           [WEAK]
                EXPORT  BPWM0_IRQHandler          [WEAK]
                EXPORT  BPWM1_IRQHandler          [WEAK]
                EXPORT  BRAKE0_IRQHandler         [WEAK]
				EXPORT  BRAKE1_IRQHandler         [WEAK]
                EXPORT  PWRWU_IRQHandler          [WEAK]
                EXPORT  ADC_IRQHandler            [WEAK]
                EXPORT  CKD_IRQHandler            [WEAK]				
                EXPORT  RTC_IRQHandler            [WEAK]
                
BOD_IRQHandler
WDT_IRQHandler
EINT0_IRQHandler
EINT1_IRQHandler
GPAB_IRQHandler
GPCDEF_IRQHandler
TMR0_IRQHandler
TMR1_IRQHandler
TMR2_IRQHandler
TMR3_IRQHandler
UART02_IRQHandler
UART1_IRQHandler
SPI0_IRQHandler
UART3_IRQHandler
UART4_IRQHandler
UART5_IRQHandler
I2C0_IRQHandler
I2C1_IRQHandler
CAN0_IRQHandler
CAN1_IRQHandler
PWM0_IRQHandler
PWM1_IRQHandler
BPWM0_IRQHandler
BPWM1_IRQHandler
BRAKE0_IRQHandler
BRAKE1_IRQHandler
PWRWU_IRQHandler
ADC_IRQHandler
CKD_IRQHandler
RTC_IRQHandler
                B       .
                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB
                
                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit
                
                ELSE
                
                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                LDR     R0, =  Heap_Mem
                LDR     R1, = (Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR

                ALIGN

                ENDIF

;int32_t SH_DoCommand(int32_t n32In_R0, int32_t n32In_R1, int32_t *pn32Out_R0)
SH_DoCommand    PROC
    
                EXPORT      SH_DoCommand
                IMPORT      SH_Return
                    
                BKPT   0xAB                ; Wait ICE or HardFault
                LDR    R3, =SH_Return 
                MOV    R4, lr          
                BLX    R3                  ; Call SH_Return. The return value is in R0
                BX     R4                  ; Return value = R0
                
                ENDP

__PC            PROC
                EXPORT      __PC
                
                MOV     r0, lr
                BLX     lr
                ALIGN
                    
                ENDP
                
                END
