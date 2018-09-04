// mnemonics.c: Intel 8080 assembly mnemonic list definitions
//
// Copyright (c) 2018 Moaz Ashraf
// Licensed under MIT License
// Refer to LICENSE file

#include <stdlib.h>
#include "asm.h"

// unary operators
Oper unaopers[] = {
    {"+", 1}, {"-", 1},
    {"NOT", 2}
};

const int N_UNAOPERS = sizeof unaopers / sizeof(Oper);

// binary operators
Oper binopers[] = {
    {"*", 0}, {"/", 0}, {"MOD", 0}, {"SHR", 0}, {"SHL", 0},
    {"+", 1}, {"-", 1},
    {"AND", 3},
    {"OR", 4}, {"XOR", 4}
};

const int N_BINOPERS = sizeof binopers / sizeof(Oper);

// pseudo-intructions
Pseudo pseudos[] = {
    {0, "DB",    3},
    {0, "DW",    3},
    {0, "DS",    1},
    {0, "ORG",   1},
    {1, "EQU",   1},
    {1, "SET",   1},
    {0, "END",   0},
    {0, "IF",    1},
    {0, "ENDIF", 0},
    {1, "MACRO", 4},
    {0, "ENDM",  0}
};

const int N_PSEUDOS = sizeof pseudos / sizeof(Pseudo);

// hard-coded labels
#define B   0
#define C   1
#define D   2
#define E   3
#define H   4
#define L   5
#define M   6
#define A   7
#define SP  8

// instructions
Instr instrs[] = {
    {0x00, 1, 0, "NOP"},
    {0x01, 3, 2, "LXI",  B, -1},
    {0x02, 1, 1, "STAX", B},
    {0x03, 1, 1, "INX",  B},
    {0x04, 1, 1, "INR",  B},
    {0x05, 1, 1, "DCR",  B},
    {0x06, 2, 2, "MVI",  B, -1},
    {0x07, 1, 0, "RLC"},
    // 0x08
    {0x09, 1, 1, "DAD",  B},
    {0x0a, 1, 1, "LDAX", B},
    {0x0b, 1, 1, "DCX",  B},
    {0x0c, 1, 1, "INR",  C},
    {0x0d, 1, 1, "DCR",  C},
    {0x0e, 2, 2, "MVI",  C, -1},
    {0x0f, 1, 0, "RRC"},
    // 0x10
    {0x11, 3, 2, "LXI",  D, -1},
    {0x12, 1, 1, "STAX", D},
    {0x13, 1, 1, "INX",  D},
    {0x14, 1, 1, "INR",  D},
    {0x15, 1, 1, "DCR",  D},
    {0x16, 2, 2, "MVI",  D, -1},
    {0x17, 1, 0, "RAL"},
    // 0x18
    {0x19, 1, 1, "DAD",  D},
    {0x1a, 1, 1, "LDAX", D},
    {0x1b, 1, 1, "DCX",  D},
    {0x1c, 1, 1, "INR",  E},
    {0x1d, 1, 1, "DCR",  E},
    {0x1e, 2, 2, "MVI",  E, -1},
    {0x1f, 1, 0, "RAR"},
    {0x20, 1, 0, "RIM"},
    {0x21, 3, 2, "LXI",  H, -1},
    {0x22, 3, 1, "SHLD", -1},
    {0x23, 1, 1, "INX",  H},
    {0x24, 1, 1, "INR",  H},
    {0x25, 1, 1, "DCR",  H},
    {0x26, 2, 2, "MVI",  H, -1},
    {0x27, 1, 0, "DAA"},
    // 0x28
    {0x29, 1, 1, "DAD",  H},
    {0x2a, 3, 1, "LHLD", -1},
    {0x2b, 1, 1, "DCX",  H},
    {0x2c, 1, 1, "INR",  L},
    {0x2d, 1, 1, "DCR",  L},
    {0x2e, 2, 2, "MVI",  L, -1},
    {0x2f, 1, 0, "CMA"},
    {0x30, 1, 0, "SIM"},
    {0x31, 3, 2, "LXI",  SP, -1},
    {0x32, 3, 1, "STA",  -1},
    {0x33, 1, 1, "INX",  SP},
    {0x34, 1, 1, "INR",  M},
    {0x35, 1, 1, "DCR",  M},
    {0x36, 2, 2, "MVI",  M, -1},
    {0x37, 1, 0, "STC"},
    // 0x38
    {0x39, 1, 1, "DAD",  SP},
    {0x3a, 3, 1, "LDA",  -1},
    {0x3b, 1, 1, "DCX",  SP},
    {0x3c, 1, 1, "INR",  A},
    {0x3d, 1, 1, "DCR",  A},
    {0x3e, 2, 2, "MVI",  A, -1},
    {0x3f, 1, 0, "CMC"},
    {0x40, 1, 2, "MOV",  B, B},
    {0x41, 1, 2, "MOV",  B, C},
    {0x42, 1, 2, "MOV",  B, D},
    {0x43, 1, 2, "MOV",  B, E},
    {0x44, 1, 2, "MOV",  B, H},
    {0x45, 1, 2, "MOV",  B, L},
    {0x46, 1, 2, "MOV",  B, M},
    {0x47, 1, 2, "MOV",  B, A},
    {0x48, 1, 2, "MOV",  C, B},
    {0x49, 1, 2, "MOV",  C, C},
    {0x4a, 1, 2, "MOV",  C, D},
    {0x4b, 1, 2, "MOV",  C, E},
    {0x4c, 1, 2, "MOV",  C, H},
    {0x4d, 1, 2, "MOV",  C, L},
    {0x4e, 1, 2, "MOV",  C, M},
    {0x4f, 1, 2, "MOV",  C, A},
    {0x50, 1, 2, "MOV",  D, B},
    {0x51, 1, 2, "MOV",  D, C},
    {0x52, 1, 2, "MOV",  D, D},
    {0x53, 1, 2, "MOV",  D, E},
    {0x54, 1, 2, "MOV",  D, H},
    {0x55, 1, 2, "MOV",  D, L},
    {0x56, 1, 2, "MOV",  D, M},
    {0x57, 1, 2, "MOV",  D, A},
    {0x58, 1, 2, "MOV",  E, B},
    {0x59, 1, 2, "MOV",  E, C},
    {0x5a, 1, 2, "MOV",  E, D},
    {0x5b, 1, 2, "MOV",  E, E},
    {0x5c, 1, 2, "MOV",  E, H},
    {0x5d, 1, 2, "MOV",  E, L},
    {0x5e, 1, 2, "MOV",  E, M},
    {0x5f, 1, 2, "MOV",  E, A},
    {0x60, 1, 2, "MOV",  H, B},
    {0x61, 1, 2, "MOV",  H, C},
    {0x62, 1, 2, "MOV",  H, D},
    {0x63, 1, 2, "MOV",  H, E},
    {0x64, 1, 2, "MOV",  H, H},
    {0x65, 1, 2, "MOV",  H, L},
    {0x66, 1, 2, "MOV",  H, M},
    {0x67, 1, 2, "MOV",  H, A},
    {0x68, 1, 2, "MOV",  L, B},
    {0x69, 1, 2, "MOV",  L, C},
    {0x6a, 1, 2, "MOV",  L, D},
    {0x6b, 1, 2, "MOV",  L, E},
    {0x6c, 1, 2, "MOV",  L, H},
    {0x6d, 1, 2, "MOV",  L, L},
    {0x6e, 1, 2, "MOV",  L, M},
    {0x6f, 1, 2, "MOV",  L, A},
    {0x70, 1, 2, "MOV",  M, B},
    {0x71, 1, 2, "MOV",  M, C},
    {0x72, 1, 2, "MOV",  M, D},
    {0x73, 1, 2, "MOV",  M, E},
    {0x74, 1, 2, "MOV",  M, H},
    {0x75, 1, 2, "MOV",  M, L},
    {0x76, 1, 0, "HLT"},
    {0x77, 1, 2, "MOV",  M, A},
    {0x78, 1, 2, "MOV",  A, B},
    {0x79, 1, 2, "MOV",  A, C},
    {0x7a, 1, 2, "MOV",  A, D},
    {0x7b, 1, 2, "MOV",  A, E},
    {0x7c, 1, 2, "MOV",  A, H},
    {0x7d, 1, 2, "MOV",  A, L},
    {0x7e, 1, 2, "MOV",  A, M},
    {0x7f, 1, 2, "MOV",  A, A},
    {0x80, 1, 1, "ADD",  B},
    {0x81, 1, 1, "ADD",  C},
    {0x82, 1, 1, "ADD",  D},
    {0x83, 1, 1, "ADD",  E},
    {0x84, 1, 1, "ADD",  H},
    {0x85, 1, 1, "ADD",  L},
    {0x86, 1, 1, "ADD",  M},
    {0x87, 1, 1, "ADD",  A},
    {0x88, 1, 1, "ADC",  B},
    {0x89, 1, 1, "ADC",  C},
    {0x8a, 1, 1, "ADC",  D},
    {0x8b, 1, 1, "ADC",  E},
    {0x8c, 1, 1, "ADC",  H},
    {0x8d, 1, 1, "ADC",  L},
    {0x8e, 1, 1, "ADC",  M},
    {0x8f, 1, 1, "ADC",  A},
    {0x90, 1, 1, "SUB",  B},
    {0x91, 1, 1, "SUB",  D},
    {0x92, 1, 1, "SUB",  C},
    {0x93, 1, 1, "SUB",  E},
    {0x94, 1, 1, "SUB",  H},
    {0x95, 1, 1, "SUB",  L},
    {0x96, 1, 1, "SUB",  M},
    {0x97, 1, 1, "SUB",  A},
    {0x98, 1, 1, "SBB",  B},
    {0x99, 1, 1, "SBB",  D},
    {0x9a, 1, 1, "SBB",  C},
    {0x9b, 1, 1, "SBB",  E},
    {0x9c, 1, 1, "SBB",  H},
    {0x9d, 1, 1, "SBB",  L},
    {0x9e, 1, 1, "SBB",  M},
    {0x9f, 1, 1, "SBB",  A},
    {0xa0, 1, 1, "ANA",  B},
    {0xa1, 1, 1, "ANA",  D},
    {0xa2, 1, 1, "ANA",  C},
    {0xa3, 1, 1, "ANA",  E},
    {0xa4, 1, 1, "ANA",  H},
    {0xa5, 1, 1, "ANA",  L},
    {0xa6, 1, 1, "ANA",  M},
    {0xa7, 1, 1, "ANA",  A},
    {0xa8, 1, 1, "XRA",  B},
    {0xa9, 1, 1, "XRA",  D},
    {0xaa, 1, 1, "XRA",  C},
    {0xab, 1, 1, "XRA",  E},
    {0xac, 1, 1, "XRA",  H},
    {0xad, 1, 1, "XRA",  L},
    {0xae, 1, 1, "XRA",  M},
    {0xaf, 1, 1, "XRA",  A},
    {0xb0, 1, 1, "ORA",  B},
    {0xb1, 1, 1, "ORA",  D},
    {0xb2, 1, 1, "ORA",  C},
    {0xb3, 1, 1, "ORA",  E},
    {0xb4, 1, 1, "ORA",  H},
    {0xb5, 1, 1, "ORA",  L},
    {0xb6, 1, 1, "ORA",  M},
    {0xb7, 1, 1, "ORA",  A},
    {0xb8, 1, 1, "CMP",  B},
    {0xb9, 1, 1, "CMP",  D},
    {0xba, 1, 1, "CMP",  C},
    {0xbb, 1, 1, "CMP",  E},
    {0xbc, 1, 1, "CMP",  H},
    {0xbd, 1, 1, "CMP",  L},
    {0xbe, 1, 1, "CMP",  M},
    {0xbf, 1, 1, "CMP",  A},
    {0xc0, 1, 0, "RNZ"},
    {0xc1, 1, 1, "POP",  B},
    {0xc2, 3, 1, "JNZ", -1},
    {0xc3, 3, 1, "JMP", -1},
    {0xc4, 3, 1, "CNZ", -1},
    {0xc5, 1, 1, "PUSH", B},
    {0Xc6, 2, 1, "ADI", -1},
    {0xc7, 1, 1, "RST",  0},
    {0xc8, 1, 0, "RZ"},
    {0xc9, 1, 0, "RET"},
    {0xca, 3, 1, "JZ",  -1},
    // 0xcb
    {0xcc, 3, 1, "CZ",  -1},
    {0xcd, 3, 1, "CALL",-1},
    {0xce, 2, 1, "ACI", -1},
    {0xcf, 1, 1, "RST",  1}
};

const int N_INSTRS = sizeof instrs / sizeof(Instr);