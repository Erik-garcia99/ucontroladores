/******************************************************************************
Prac 2 - AVR ASM OpCode Decoder
*******************************************************************************/

#include <stdio.h>
#include <inttypes.h>

//                                  31
// 0X0F - 0xEF -> 0000 11 11 - 1110 1111 ->  ADD 30,R31

// 0x10 - 0x0F -> 0001 00 00 - 0000 1111 -> CPSE  r0,r15

// 0x21 - 0x2F -> 0010 00 01 - 0010 1111 -> AND r18 ,r15, TST R15,R15

const uint8_t flash_mem[] = {0x0F, 0xEF, 0x10, 0x0F, 0x21, 0x2F, 0x3F, 0xEF, 0x32, 0x02, 0x00, 0x00};
const uint16_t inst16_table[] = {
    {0x0}, // NOP
    {0x0F}

};

enum
{
    e_NOP,
    e_ADD,
};

// Op Code struct
typedef union
{
    uint16_t op16; // e.g.: watchdog
    struct
    {
        uint16_t op4 : 4;
        uint16_t d5 : 5;
        uint16_t op7 : 7;
    } type1; // e.g: LSR
    struct
    {
        uint16_t r4 : 4;
        uint16_t d5 : 5;
        uint16_t r1 : 1;
        uint16_t op6 : 6;
    } type2; // e.g.: MOV,MUL,ADC,ADD,AND,CPC
    // TO-DO: Add more types as needed

} Op_Code_t;

int main()
{
    Op_Code_t *instruction;
    printf("- Practica 2: AVR OpCode -\n");
    // Decode the instructions by cycling through the array
    for (uint8_t idx = 0; idx < sizeof(flash_mem); idx += 2)
    {
        instruction = (Op_Code_t *)&flash_mem[idx];
        if (instruction->op16 == inst16_table[e_NOP])
        {
            printf("NOP\n");
        }
        else
        {
            printf("unknown\n");
        }
    }

    printf("\n\n");
    for (uint8_t idx = 0; idx < sizeof(flash_mem); idx += 2)
    {
        if (instruction->op16 == inst16_table[e_ADD])
        {
            printf("ADD r30, r31");
        }
        else
        {
            printf("unknown\n");
        }
    }
    return 0;
}