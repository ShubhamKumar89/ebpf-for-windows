// Copyright (c) Microsoft Corporation
// SPDX-License-Identifier: MIT

// Do not alter this generated file.
// This file was generated from sockops.o

#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>

#include <stdio.h>

#include "bpf2c.h"

#define metadata_table sockops##_metadata_table
extern metadata_table_t metadata_table;

BOOL APIENTRY
DllMain(_In_ HMODULE hModule, unsigned int ul_reason_for_call, _In_ void* lpReserved)
{
    UNREFERENCED_PARAMETER(hModule);
    UNREFERENCED_PARAMETER(lpReserved);
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

void
division_by_zero(uint32_t address)
{
    fprintf(stderr, "Divide by zero at address %d\n", address);
}

#define FIND_METADATA_ENTRTY(NAME, X) \
    if (std::string(NAME) == #X)      \
        return &X;

__declspec(dllexport) metadata_table_t* get_metadata_table() { return &metadata_table; }

#include "bpf2c.h"

static void
_get_hash(_Outptr_result_buffer_maybenull_(*size) const uint8_t** hash, _Out_ size_t* size)
{
    *hash = NULL;
    *size = 0;
}
#pragma data_seg(push, "maps")
static map_entry_t _maps[] = {
    {NULL,
     {
         BPF_MAP_TYPE_HASH, // Type of map.
         44,                // Size in bytes of a map key.
         4,                 // Size in bytes of a map value.
         1,                 // Maximum number of entries allowed in the map.
         0,                 // Inner map index.
         PIN_NONE,          // Pinning type for the map.
         0,                 // Identifier for a map template.
         0,                 // The id of the inner map template.
     },
     "connection_map"},
    {NULL,
     {
         BPF_MAP_TYPE_RINGBUF, // Type of map.
         0,                    // Size in bytes of a map key.
         0,                    // Size in bytes of a map value.
         262144,               // Maximum number of entries allowed in the map.
         0,                    // Inner map index.
         PIN_NONE,             // Pinning type for the map.
         0,                    // Identifier for a map template.
         0,                    // The id of the inner map template.
     },
     "audit_map"},
};
#pragma data_seg(pop)

static void
_get_maps(_Outptr_result_buffer_maybenull_(*count) map_entry_t** maps, _Out_ size_t* count)
{
    *maps = _maps;
    *count = 2;
}

static helper_function_entry_t connection_monitor_helpers[] = {
    {NULL, 1, "helper_id_1"},
    {NULL, 11, "helper_id_11"},
};

static GUID connection_monitor_program_type_guid = {
    0x43fb224d, 0x68f8, 0x46d6, {0xaa, 0x3f, 0xc8, 0x56, 0x51, 0x8c, 0xbb, 0x32}};
static GUID connection_monitor_attach_type_guid = {
    0x837d02cd, 0x3251, 0x4632, {0x8d, 0x94, 0x60, 0xd3, 0xb4, 0x57, 0x69, 0xf2}};
static uint16_t connection_monitor_maps[] = {
    0,
    1,
};

#pragma code_seg(push, "sockops")
static uint64_t
connection_monitor(void* context)
#line 65 "sample/sockops.c"
{
#line 65 "sample/sockops.c"
    // Prologue
#line 65 "sample/sockops.c"
    uint64_t stack[(UBPF_STACK_SIZE + 7) / 8];
#line 65 "sample/sockops.c"
    register uint64_t r0 = 0;
#line 65 "sample/sockops.c"
    register uint64_t r1 = 0;
#line 65 "sample/sockops.c"
    register uint64_t r2 = 0;
#line 65 "sample/sockops.c"
    register uint64_t r3 = 0;
#line 65 "sample/sockops.c"
    register uint64_t r4 = 0;
#line 65 "sample/sockops.c"
    register uint64_t r5 = 0;
#line 65 "sample/sockops.c"
    register uint64_t r6 = 0;
#line 65 "sample/sockops.c"
    register uint64_t r7 = 0;
#line 65 "sample/sockops.c"
    register uint64_t r8 = 0;
#line 65 "sample/sockops.c"
    register uint64_t r9 = 0;
#line 65 "sample/sockops.c"
    register uint64_t r10 = 0;

#line 65 "sample/sockops.c"
    r1 = (uintptr_t)context;
#line 65 "sample/sockops.c"
    r10 = (uintptr_t)((uint8_t*)stack + sizeof(stack));

    // EBPF_OP_MOV64_IMM pc=0 dst=r7 src=r0 offset=0 imm=2
#line 65 "sample/sockops.c"
    r7 = IMMEDIATE(2);
    // EBPF_OP_MOV64_IMM pc=1 dst=r4 src=r0 offset=0 imm=1
#line 65 "sample/sockops.c"
    r4 = IMMEDIATE(1);
    // EBPF_OP_LDXW pc=2 dst=r2 src=r1 offset=0 imm=0
#line 70 "sample/sockops.c"
    r2 = *(uint32_t*)(uintptr_t)(r1 + OFFSET(0));
    // EBPF_OP_JEQ_IMM pc=3 dst=r2 src=r0 offset=8 imm=0
#line 70 "sample/sockops.c"
    if (r2 == IMMEDIATE(0))
#line 70 "sample/sockops.c"
        goto label_2;
        // EBPF_OP_JEQ_IMM pc=4 dst=r2 src=r0 offset=5 imm=2
#line 70 "sample/sockops.c"
    if (r2 == IMMEDIATE(2))
#line 70 "sample/sockops.c"
        goto label_1;
        // EBPF_OP_LDDW pc=5 dst=r6 src=r0 offset=0 imm=-1
#line 70 "sample/sockops.c"
    r6 = (uint64_t)4294967295;
    // EBPF_OP_JNE_IMM pc=7 dst=r2 src=r0 offset=214 imm=1
#line 70 "sample/sockops.c"
    if (r2 != IMMEDIATE(1))
#line 70 "sample/sockops.c"
        goto label_13;
        // EBPF_OP_MOV64_IMM pc=8 dst=r4 src=r0 offset=0 imm=0
#line 70 "sample/sockops.c"
    r4 = IMMEDIATE(0);
    // EBPF_OP_JA pc=9 dst=r0 src=r0 offset=2 imm=0
#line 70 "sample/sockops.c"
    goto label_2;
label_1:
    // EBPF_OP_MOV64_IMM pc=10 dst=r4 src=r0 offset=0 imm=0
#line 70 "sample/sockops.c"
    r4 = IMMEDIATE(0);
    // EBPF_OP_MOV64_IMM pc=11 dst=r7 src=r0 offset=0 imm=0
#line 70 "sample/sockops.c"
    r7 = IMMEDIATE(0);
label_2:
    // EBPF_OP_LDXW pc=12 dst=r2 src=r1 offset=4 imm=0
#line 87 "sample/sockops.c"
    r2 = *(uint32_t*)(uintptr_t)(r1 + OFFSET(4));
    // EBPF_OP_JNE_IMM pc=13 dst=r2 src=r0 offset=51 imm=2
#line 87 "sample/sockops.c"
    if (r2 != IMMEDIATE(2))
#line 87 "sample/sockops.c"
        goto label_7;
        // EBPF_OP_MOV64_IMM pc=14 dst=r6 src=r0 offset=0 imm=0
#line 87 "sample/sockops.c"
    r6 = IMMEDIATE(0);
    // EBPF_OP_STXW pc=15 dst=r10 src=r6 offset=-4 imm=0
#line 22 "sample/sockops.c"
    *(uint32_t*)(uintptr_t)(r10 + OFFSET(-4)) = (uint32_t)r6;
    // EBPF_OP_STXW pc=16 dst=r10 src=r6 offset=-8 imm=0
#line 22 "sample/sockops.c"
    *(uint32_t*)(uintptr_t)(r10 + OFFSET(-8)) = (uint32_t)r6;
    // EBPF_OP_STXW pc=17 dst=r10 src=r6 offset=-12 imm=0
#line 22 "sample/sockops.c"
    *(uint32_t*)(uintptr_t)(r10 + OFFSET(-12)) = (uint32_t)r6;
    // EBPF_OP_STXW pc=18 dst=r10 src=r6 offset=-16 imm=0
#line 22 "sample/sockops.c"
    *(uint32_t*)(uintptr_t)(r10 + OFFSET(-16)) = (uint32_t)r6;
    // EBPF_OP_STXW pc=19 dst=r10 src=r6 offset=-20 imm=0
#line 22 "sample/sockops.c"
    *(uint32_t*)(uintptr_t)(r10 + OFFSET(-20)) = (uint32_t)r6;
    // EBPF_OP_STXW pc=20 dst=r10 src=r6 offset=-24 imm=0
#line 22 "sample/sockops.c"
    *(uint32_t*)(uintptr_t)(r10 + OFFSET(-24)) = (uint32_t)r6;
    // EBPF_OP_STXW pc=21 dst=r10 src=r6 offset=-28 imm=0
#line 22 "sample/sockops.c"
    *(uint32_t*)(uintptr_t)(r10 + OFFSET(-28)) = (uint32_t)r6;
    // EBPF_OP_STXW pc=22 dst=r10 src=r6 offset=-32 imm=0
#line 22 "sample/sockops.c"
    *(uint32_t*)(uintptr_t)(r10 + OFFSET(-32)) = (uint32_t)r6;
    // EBPF_OP_STXW pc=23 dst=r10 src=r6 offset=-36 imm=0
#line 22 "sample/sockops.c"
    *(uint32_t*)(uintptr_t)(r10 + OFFSET(-36)) = (uint32_t)r6;
    // EBPF_OP_STXW pc=24 dst=r10 src=r6 offset=-40 imm=0
#line 22 "sample/sockops.c"
    *(uint32_t*)(uintptr_t)(r10 + OFFSET(-40)) = (uint32_t)r6;
    // EBPF_OP_STXW pc=25 dst=r10 src=r6 offset=-44 imm=0
#line 22 "sample/sockops.c"
    *(uint32_t*)(uintptr_t)(r10 + OFFSET(-44)) = (uint32_t)r6;
    // EBPF_OP_MOV64_IMM pc=26 dst=r2 src=r0 offset=0 imm=28
#line 22 "sample/sockops.c"
    r2 = IMMEDIATE(28);
    // EBPF_OP_MOV64_IMM pc=27 dst=r5 src=r0 offset=0 imm=8
#line 24 "sample/sockops.c"
    r5 = IMMEDIATE(8);
    // EBPF_OP_JNE_IMM pc=28 dst=r4 src=r0 offset=1 imm=0
#line 24 "sample/sockops.c"
    if (r4 != IMMEDIATE(0))
#line 24 "sample/sockops.c"
        goto label_3;
        // EBPF_OP_MOV64_IMM pc=29 dst=r5 src=r0 offset=0 imm=28
#line 24 "sample/sockops.c"
    r5 = IMMEDIATE(28);
label_3:
    // EBPF_OP_MOV64_REG pc=30 dst=r3 src=r1 offset=0 imm=0
#line 24 "sample/sockops.c"
    r3 = r1;
    // EBPF_OP_ADD64_REG pc=31 dst=r3 src=r5 offset=0 imm=0
#line 24 "sample/sockops.c"
    r3 += r5;
    // EBPF_OP_LDXW pc=32 dst=r3 src=r3 offset=0 imm=0
#line 24 "sample/sockops.c"
    r3 = *(uint32_t*)(uintptr_t)(r3 + OFFSET(0));
    // EBPF_OP_STXW pc=33 dst=r10 src=r3 offset=-48 imm=0
#line 24 "sample/sockops.c"
    *(uint32_t*)(uintptr_t)(r10 + OFFSET(-48)) = (uint32_t)r3;
    // EBPF_OP_MOV64_IMM pc=34 dst=r0 src=r0 offset=0 imm=44
#line 24 "sample/sockops.c"
    r0 = IMMEDIATE(44);
    // EBPF_OP_MOV64_IMM pc=35 dst=r3 src=r0 offset=0 imm=24
#line 25 "sample/sockops.c"
    r3 = IMMEDIATE(24);
    // EBPF_OP_JNE_IMM pc=36 dst=r4 src=r0 offset=1 imm=0
#line 25 "sample/sockops.c"
    if (r4 != IMMEDIATE(0))
#line 25 "sample/sockops.c"
        goto label_4;
        // EBPF_OP_MOV64_IMM pc=37 dst=r3 src=r0 offset=0 imm=44
#line 25 "sample/sockops.c"
    r3 = IMMEDIATE(44);
label_4:
    // EBPF_OP_MOV64_REG pc=38 dst=r5 src=r1 offset=0 imm=0
#line 25 "sample/sockops.c"
    r5 = r1;
    // EBPF_OP_ADD64_REG pc=39 dst=r5 src=r3 offset=0 imm=0
#line 25 "sample/sockops.c"
    r5 += r3;
    // EBPF_OP_LDXW pc=40 dst=r3 src=r5 offset=0 imm=0
#line 25 "sample/sockops.c"
    r3 = *(uint32_t*)(uintptr_t)(r5 + OFFSET(0));
    // EBPF_OP_STXH pc=41 dst=r10 src=r3 offset=-32 imm=0
#line 25 "sample/sockops.c"
    *(uint16_t*)(uintptr_t)(r10 + OFFSET(-32)) = (uint16_t)r3;
    // EBPF_OP_JNE_IMM pc=42 dst=r4 src=r0 offset=1 imm=0
#line 27 "sample/sockops.c"
    if (r4 != IMMEDIATE(0))
#line 27 "sample/sockops.c"
        goto label_5;
        // EBPF_OP_MOV64_IMM pc=43 dst=r0 src=r0 offset=0 imm=24
#line 27 "sample/sockops.c"
    r0 = IMMEDIATE(24);
label_5:
    // EBPF_OP_JNE_IMM pc=44 dst=r4 src=r0 offset=1 imm=0
#line 26 "sample/sockops.c"
    if (r4 != IMMEDIATE(0))
#line 26 "sample/sockops.c"
        goto label_6;
        // EBPF_OP_MOV64_IMM pc=45 dst=r2 src=r0 offset=0 imm=8
#line 26 "sample/sockops.c"
    r2 = IMMEDIATE(8);
label_6:
    // EBPF_OP_OR64_REG pc=46 dst=r7 src=r4 offset=0 imm=0
#line 29 "sample/sockops.c"
    r7 |= r4;
    // EBPF_OP_MOV64_REG pc=47 dst=r3 src=r1 offset=0 imm=0
#line 26 "sample/sockops.c"
    r3 = r1;
    // EBPF_OP_ADD64_REG pc=48 dst=r3 src=r2 offset=0 imm=0
#line 26 "sample/sockops.c"
    r3 += r2;
    // EBPF_OP_LDXW pc=49 dst=r2 src=r3 offset=0 imm=0
#line 26 "sample/sockops.c"
    r2 = *(uint32_t*)(uintptr_t)(r3 + OFFSET(0));
    // EBPF_OP_STXW pc=50 dst=r10 src=r2 offset=-28 imm=0
#line 26 "sample/sockops.c"
    *(uint32_t*)(uintptr_t)(r10 + OFFSET(-28)) = (uint32_t)r2;
    // EBPF_OP_MOV64_REG pc=51 dst=r2 src=r1 offset=0 imm=0
#line 27 "sample/sockops.c"
    r2 = r1;
    // EBPF_OP_ADD64_REG pc=52 dst=r2 src=r0 offset=0 imm=0
#line 27 "sample/sockops.c"
    r2 += r0;
    // EBPF_OP_LDXW pc=53 dst=r2 src=r2 offset=0 imm=0
#line 27 "sample/sockops.c"
    r2 = *(uint32_t*)(uintptr_t)(r2 + OFFSET(0));
    // EBPF_OP_STXH pc=54 dst=r10 src=r2 offset=-12 imm=0
#line 27 "sample/sockops.c"
    *(uint16_t*)(uintptr_t)(r10 + OFFSET(-12)) = (uint16_t)r2;
    // EBPF_OP_LDXB pc=55 dst=r1 src=r1 offset=48 imm=0
#line 28 "sample/sockops.c"
    r1 = *(uint8_t*)(uintptr_t)(r1 + OFFSET(48));
    // EBPF_OP_STXB pc=56 dst=r10 src=r7 offset=-4 imm=0
#line 30 "sample/sockops.c"
    *(uint8_t*)(uintptr_t)(r10 + OFFSET(-4)) = (uint8_t)r7;
    // EBPF_OP_STXW pc=57 dst=r10 src=r1 offset=-8 imm=0
#line 28 "sample/sockops.c"
    *(uint32_t*)(uintptr_t)(r10 + OFFSET(-8)) = (uint32_t)r1;
    // EBPF_OP_MOV64_REG pc=58 dst=r2 src=r10 offset=0 imm=0
#line 28 "sample/sockops.c"
    r2 = r10;
    // EBPF_OP_ADD64_IMM pc=59 dst=r2 src=r0 offset=0 imm=-48
#line 29 "sample/sockops.c"
    r2 += IMMEDIATE(-48);
    // EBPF_OP_LDDW pc=60 dst=r1 src=r0 offset=0 imm=0
#line 32 "sample/sockops.c"
    r1 = POINTER(_maps[0].address);
    // EBPF_OP_CALL pc=62 dst=r0 src=r0 offset=0 imm=1
#line 32 "sample/sockops.c"
    r0 = connection_monitor_helpers[0].address
#line 32 "sample/sockops.c"
         (r1, r2, r3, r4, r5);
#line 32 "sample/sockops.c"
    if ((connection_monitor_helpers[0].tail_call) && (r0 == 0))
#line 32 "sample/sockops.c"
        return 0;
        // EBPF_OP_JEQ_IMM pc=63 dst=r0 src=r0 offset=158 imm=0
#line 32 "sample/sockops.c"
    if (r0 == IMMEDIATE(0))
#line 32 "sample/sockops.c"
        goto label_13;
        // EBPF_OP_JA pc=64 dst=r0 src=r0 offset=149 imm=0
#line 32 "sample/sockops.c"
    goto label_12;
label_7:
    // EBPF_OP_STXDW pc=65 dst=r10 src=r7 offset=-56 imm=0
#line 32 "sample/sockops.c"
    *(uint64_t*)(uintptr_t)(r10 + OFFSET(-56)) = (uint64_t)r7;
    // EBPF_OP_MOV64_IMM pc=66 dst=r2 src=r0 offset=0 imm=0
#line 32 "sample/sockops.c"
    r2 = IMMEDIATE(0);
    // EBPF_OP_STXDW pc=67 dst=r10 src=r2 offset=-8 imm=0
#line 47 "sample/sockops.c"
    *(uint64_t*)(uintptr_t)(r10 + OFFSET(-8)) = (uint64_t)r2;
    // EBPF_OP_STXDW pc=68 dst=r10 src=r2 offset=-16 imm=0
#line 47 "sample/sockops.c"
    *(uint64_t*)(uintptr_t)(r10 + OFFSET(-16)) = (uint64_t)r2;
    // EBPF_OP_STXDW pc=69 dst=r10 src=r2 offset=-24 imm=0
#line 47 "sample/sockops.c"
    *(uint64_t*)(uintptr_t)(r10 + OFFSET(-24)) = (uint64_t)r2;
    // EBPF_OP_STXDW pc=70 dst=r10 src=r2 offset=-32 imm=0
#line 47 "sample/sockops.c"
    *(uint64_t*)(uintptr_t)(r10 + OFFSET(-32)) = (uint64_t)r2;
    // EBPF_OP_MOV64_REG pc=71 dst=r3 src=r1 offset=0 imm=0
#line 46 "sample/sockops.c"
    r3 = r1;
    // EBPF_OP_ADD64_IMM pc=72 dst=r3 src=r0 offset=0 imm=28
#line 46 "sample/sockops.c"
    r3 += IMMEDIATE(28);
    // EBPF_OP_STXDW pc=73 dst=r10 src=r1 offset=-80 imm=0
#line 46 "sample/sockops.c"
    *(uint64_t*)(uintptr_t)(r10 + OFFSET(-80)) = (uint64_t)r1;
    // EBPF_OP_MOV64_REG pc=74 dst=r0 src=r1 offset=0 imm=0
#line 46 "sample/sockops.c"
    r0 = r1;
    // EBPF_OP_ADD64_IMM pc=75 dst=r0 src=r0 offset=0 imm=8
#line 46 "sample/sockops.c"
    r0 += IMMEDIATE(8);
    // EBPF_OP_STXDW pc=76 dst=r10 src=r0 offset=-104 imm=0
#line 46 "sample/sockops.c"
    *(uint64_t*)(uintptr_t)(r10 + OFFSET(-104)) = (uint64_t)r0;
    // EBPF_OP_JNE_IMM pc=77 dst=r4 src=r0 offset=1 imm=0
#line 46 "sample/sockops.c"
    if (r4 != IMMEDIATE(0))
#line 46 "sample/sockops.c"
        goto label_8;
        // EBPF_OP_MOV64_REG pc=78 dst=r0 src=r3 offset=0 imm=0
#line 46 "sample/sockops.c"
    r0 = r3;
label_8:
    // EBPF_OP_LDXB pc=79 dst=r2 src=r0 offset=13 imm=0
#line 47 "sample/sockops.c"
    r2 = *(uint8_t*)(uintptr_t)(r0 + OFFSET(13));
    // EBPF_OP_LSH64_IMM pc=80 dst=r2 src=r0 offset=0 imm=8
#line 47 "sample/sockops.c"
    r2 <<= IMMEDIATE(8);
    // EBPF_OP_LDXB pc=81 dst=r1 src=r0 offset=12 imm=0
#line 47 "sample/sockops.c"
    r1 = *(uint8_t*)(uintptr_t)(r0 + OFFSET(12));
    // EBPF_OP_STXDW pc=82 dst=r10 src=r1 offset=-64 imm=0
#line 47 "sample/sockops.c"
    *(uint64_t*)(uintptr_t)(r10 + OFFSET(-64)) = (uint64_t)r1;
    // EBPF_OP_LDXB pc=83 dst=r8 src=r0 offset=15 imm=0
#line 47 "sample/sockops.c"
    r8 = *(uint8_t*)(uintptr_t)(r0 + OFFSET(15));
    // EBPF_OP_LSH64_IMM pc=84 dst=r8 src=r0 offset=0 imm=8
#line 47 "sample/sockops.c"
    r8 <<= IMMEDIATE(8);
    // EBPF_OP_LDXB pc=85 dst=r5 src=r0 offset=14 imm=0
#line 47 "sample/sockops.c"
    r5 = *(uint8_t*)(uintptr_t)(r0 + OFFSET(14));
    // EBPF_OP_OR64_REG pc=86 dst=r8 src=r5 offset=0 imm=0
#line 47 "sample/sockops.c"
    r8 |= r5;
    // EBPF_OP_LDXB pc=87 dst=r6 src=r0 offset=9 imm=0
#line 47 "sample/sockops.c"
    r6 = *(uint8_t*)(uintptr_t)(r0 + OFFSET(9));
    // EBPF_OP_LSH64_IMM pc=88 dst=r6 src=r0 offset=0 imm=8
#line 47 "sample/sockops.c"
    r6 <<= IMMEDIATE(8);
    // EBPF_OP_LDXB pc=89 dst=r1 src=r0 offset=8 imm=0
#line 47 "sample/sockops.c"
    r1 = *(uint8_t*)(uintptr_t)(r0 + OFFSET(8));
    // EBPF_OP_STXDW pc=90 dst=r10 src=r1 offset=-72 imm=0
#line 47 "sample/sockops.c"
    *(uint64_t*)(uintptr_t)(r10 + OFFSET(-72)) = (uint64_t)r1;
    // EBPF_OP_LDXB pc=91 dst=r9 src=r0 offset=11 imm=0
#line 47 "sample/sockops.c"
    r9 = *(uint8_t*)(uintptr_t)(r0 + OFFSET(11));
    // EBPF_OP_LSH64_IMM pc=92 dst=r9 src=r0 offset=0 imm=8
#line 47 "sample/sockops.c"
    r9 <<= IMMEDIATE(8);
    // EBPF_OP_LDXB pc=93 dst=r5 src=r0 offset=10 imm=0
#line 47 "sample/sockops.c"
    r5 = *(uint8_t*)(uintptr_t)(r0 + OFFSET(10));
    // EBPF_OP_OR64_REG pc=94 dst=r9 src=r5 offset=0 imm=0
#line 47 "sample/sockops.c"
    r9 |= r5;
    // EBPF_OP_LDXB pc=95 dst=r5 src=r0 offset=1 imm=0
#line 47 "sample/sockops.c"
    r5 = *(uint8_t*)(uintptr_t)(r0 + OFFSET(1));
    // EBPF_OP_LDXB pc=96 dst=r7 src=r0 offset=0 imm=0
#line 47 "sample/sockops.c"
    r7 = *(uint8_t*)(uintptr_t)(r0 + OFFSET(0));
    // EBPF_OP_STXDW pc=97 dst=r10 src=r7 offset=-88 imm=0
#line 47 "sample/sockops.c"
    *(uint64_t*)(uintptr_t)(r10 + OFFSET(-88)) = (uint64_t)r7;
    // EBPF_OP_LDXB pc=98 dst=r7 src=r0 offset=3 imm=0
#line 47 "sample/sockops.c"
    r7 = *(uint8_t*)(uintptr_t)(r0 + OFFSET(3));
    // EBPF_OP_LDXB pc=99 dst=r1 src=r0 offset=2 imm=0
#line 47 "sample/sockops.c"
    r1 = *(uint8_t*)(uintptr_t)(r0 + OFFSET(2));
    // EBPF_OP_STXDW pc=100 dst=r10 src=r1 offset=-96 imm=0
#line 48 "sample/sockops.c"
    *(uint64_t*)(uintptr_t)(r10 + OFFSET(-96)) = (uint64_t)r1;
    // EBPF_OP_JNE_IMM pc=101 dst=r4 src=r0 offset=1 imm=0
#line 48 "sample/sockops.c"
    if (r4 != IMMEDIATE(0))
#line 48 "sample/sockops.c"
        goto label_9;
        // EBPF_OP_LDXDW pc=102 dst=r3 src=r10 offset=-104 imm=0
#line 48 "sample/sockops.c"
    r3 = *(uint64_t*)(uintptr_t)(r10 + OFFSET(-104));
label_9:
    // EBPF_OP_LDXDW pc=103 dst=r1 src=r10 offset=-64 imm=0
#line 48 "sample/sockops.c"
    r1 = *(uint64_t*)(uintptr_t)(r10 + OFFSET(-64));
    // EBPF_OP_OR64_REG pc=104 dst=r2 src=r1 offset=0 imm=0
#line 48 "sample/sockops.c"
    r2 |= r1;
    // EBPF_OP_LDXDW pc=105 dst=r1 src=r10 offset=-72 imm=0
#line 48 "sample/sockops.c"
    r1 = *(uint64_t*)(uintptr_t)(r10 + OFFSET(-72));
    // EBPF_OP_OR64_REG pc=106 dst=r6 src=r1 offset=0 imm=0
#line 48 "sample/sockops.c"
    r6 |= r1;
    // EBPF_OP_LSH64_IMM pc=107 dst=r9 src=r0 offset=0 imm=16
#line 48 "sample/sockops.c"
    r9 <<= IMMEDIATE(16);
    // EBPF_OP_LSH64_IMM pc=108 dst=r8 src=r0 offset=0 imm=16
#line 48 "sample/sockops.c"
    r8 <<= IMMEDIATE(16);
    // EBPF_OP_LSH64_IMM pc=109 dst=r5 src=r0 offset=0 imm=8
#line 48 "sample/sockops.c"
    r5 <<= IMMEDIATE(8);
    // EBPF_OP_LSH64_IMM pc=110 dst=r7 src=r0 offset=0 imm=8
#line 48 "sample/sockops.c"
    r7 <<= IMMEDIATE(8);
    // EBPF_OP_MOV64_IMM pc=111 dst=r1 src=r0 offset=0 imm=44
#line 48 "sample/sockops.c"
    r1 = IMMEDIATE(44);
    // EBPF_OP_STXDW pc=112 dst=r10 src=r1 offset=-72 imm=0
#line 48 "sample/sockops.c"
    *(uint64_t*)(uintptr_t)(r10 + OFFSET(-72)) = (uint64_t)r1;
    // EBPF_OP_MOV64_IMM pc=113 dst=r1 src=r0 offset=0 imm=24
#line 48 "sample/sockops.c"
    r1 = IMMEDIATE(24);
    // EBPF_OP_STXDW pc=114 dst=r10 src=r1 offset=-64 imm=0
#line 48 "sample/sockops.c"
    *(uint64_t*)(uintptr_t)(r10 + OFFSET(-64)) = (uint64_t)r1;
    // EBPF_OP_JNE_IMM pc=115 dst=r4 src=r0 offset=2 imm=0
#line 48 "sample/sockops.c"
    if (r4 != IMMEDIATE(0))
#line 48 "sample/sockops.c"
        goto label_10;
        // EBPF_OP_MOV64_IMM pc=116 dst=r1 src=r0 offset=0 imm=44
#line 48 "sample/sockops.c"
    r1 = IMMEDIATE(44);
    // EBPF_OP_STXDW pc=117 dst=r10 src=r1 offset=-64 imm=0
#line 48 "sample/sockops.c"
    *(uint64_t*)(uintptr_t)(r10 + OFFSET(-64)) = (uint64_t)r1;
label_10:
    // EBPF_OP_OR64_REG pc=118 dst=r9 src=r6 offset=0 imm=0
#line 48 "sample/sockops.c"
    r9 |= r6;
    // EBPF_OP_OR64_REG pc=119 dst=r8 src=r2 offset=0 imm=0
#line 48 "sample/sockops.c"
    r8 |= r2;
    // EBPF_OP_LDXDW pc=120 dst=r1 src=r10 offset=-88 imm=0
#line 48 "sample/sockops.c"
    r1 = *(uint64_t*)(uintptr_t)(r10 + OFFSET(-88));
    // EBPF_OP_OR64_REG pc=121 dst=r5 src=r1 offset=0 imm=0
#line 48 "sample/sockops.c"
    r5 |= r1;
    // EBPF_OP_LDXDW pc=122 dst=r1 src=r10 offset=-96 imm=0
#line 48 "sample/sockops.c"
    r1 = *(uint64_t*)(uintptr_t)(r10 + OFFSET(-96));
    // EBPF_OP_OR64_REG pc=123 dst=r7 src=r1 offset=0 imm=0
#line 48 "sample/sockops.c"
    r7 |= r1;
    // EBPF_OP_JNE_IMM pc=124 dst=r4 src=r0 offset=2 imm=0
#line 51 "sample/sockops.c"
    if (r4 != IMMEDIATE(0))
#line 51 "sample/sockops.c"
        goto label_11;
        // EBPF_OP_MOV64_IMM pc=125 dst=r1 src=r0 offset=0 imm=24
#line 51 "sample/sockops.c"
    r1 = IMMEDIATE(24);
    // EBPF_OP_STXDW pc=126 dst=r10 src=r1 offset=-72 imm=0
#line 51 "sample/sockops.c"
    *(uint64_t*)(uintptr_t)(r10 + OFFSET(-72)) = (uint64_t)r1;
label_11:
    // EBPF_OP_LDXDW pc=127 dst=r2 src=r10 offset=-56 imm=0
#line 51 "sample/sockops.c"
    r2 = *(uint64_t*)(uintptr_t)(r10 + OFFSET(-56));
    // EBPF_OP_OR64_REG pc=128 dst=r2 src=r4 offset=0 imm=0
#line 53 "sample/sockops.c"
    r2 |= r4;
    // EBPF_OP_STXDW pc=129 dst=r10 src=r2 offset=-56 imm=0
#line 53 "sample/sockops.c"
    *(uint64_t*)(uintptr_t)(r10 + OFFSET(-56)) = (uint64_t)r2;
    // EBPF_OP_LSH64_IMM pc=130 dst=r8 src=r0 offset=0 imm=32
#line 47 "sample/sockops.c"
    r8 <<= IMMEDIATE(32);
    // EBPF_OP_OR64_REG pc=131 dst=r8 src=r9 offset=0 imm=0
#line 47 "sample/sockops.c"
    r8 |= r9;
    // EBPF_OP_STXDW pc=132 dst=r10 src=r8 offset=-40 imm=0
#line 47 "sample/sockops.c"
    *(uint64_t*)(uintptr_t)(r10 + OFFSET(-40)) = (uint64_t)r8;
    // EBPF_OP_LSH64_IMM pc=133 dst=r7 src=r0 offset=0 imm=16
#line 47 "sample/sockops.c"
    r7 <<= IMMEDIATE(16);
    // EBPF_OP_OR64_REG pc=134 dst=r7 src=r5 offset=0 imm=0
#line 47 "sample/sockops.c"
    r7 |= r5;
    // EBPF_OP_LDXB pc=135 dst=r1 src=r0 offset=5 imm=0
#line 47 "sample/sockops.c"
    r1 = *(uint8_t*)(uintptr_t)(r0 + OFFSET(5));
    // EBPF_OP_LSH64_IMM pc=136 dst=r1 src=r0 offset=0 imm=8
#line 47 "sample/sockops.c"
    r1 <<= IMMEDIATE(8);
    // EBPF_OP_LDXB pc=137 dst=r2 src=r0 offset=4 imm=0
#line 47 "sample/sockops.c"
    r2 = *(uint8_t*)(uintptr_t)(r0 + OFFSET(4));
    // EBPF_OP_OR64_REG pc=138 dst=r1 src=r2 offset=0 imm=0
#line 47 "sample/sockops.c"
    r1 |= r2;
    // EBPF_OP_LDXB pc=139 dst=r2 src=r0 offset=6 imm=0
#line 47 "sample/sockops.c"
    r2 = *(uint8_t*)(uintptr_t)(r0 + OFFSET(6));
    // EBPF_OP_LDXB pc=140 dst=r4 src=r0 offset=7 imm=0
#line 47 "sample/sockops.c"
    r4 = *(uint8_t*)(uintptr_t)(r0 + OFFSET(7));
    // EBPF_OP_LSH64_IMM pc=141 dst=r4 src=r0 offset=0 imm=8
#line 47 "sample/sockops.c"
    r4 <<= IMMEDIATE(8);
    // EBPF_OP_OR64_REG pc=142 dst=r4 src=r2 offset=0 imm=0
#line 47 "sample/sockops.c"
    r4 |= r2;
    // EBPF_OP_LSH64_IMM pc=143 dst=r4 src=r0 offset=0 imm=16
#line 47 "sample/sockops.c"
    r4 <<= IMMEDIATE(16);
    // EBPF_OP_OR64_REG pc=144 dst=r4 src=r1 offset=0 imm=0
#line 47 "sample/sockops.c"
    r4 |= r1;
    // EBPF_OP_LSH64_IMM pc=145 dst=r4 src=r0 offset=0 imm=32
#line 47 "sample/sockops.c"
    r4 <<= IMMEDIATE(32);
    // EBPF_OP_OR64_REG pc=146 dst=r4 src=r7 offset=0 imm=0
#line 47 "sample/sockops.c"
    r4 |= r7;
    // EBPF_OP_STXDW pc=147 dst=r10 src=r4 offset=-48 imm=0
#line 47 "sample/sockops.c"
    *(uint64_t*)(uintptr_t)(r10 + OFFSET(-48)) = (uint64_t)r4;
    // EBPF_OP_LDXDW pc=148 dst=r6 src=r10 offset=-80 imm=0
#line 47 "sample/sockops.c"
    r6 = *(uint64_t*)(uintptr_t)(r10 + OFFSET(-80));
    // EBPF_OP_MOV64_REG pc=149 dst=r1 src=r6 offset=0 imm=0
#line 48 "sample/sockops.c"
    r1 = r6;
    // EBPF_OP_LDXDW pc=150 dst=r2 src=r10 offset=-64 imm=0
#line 48 "sample/sockops.c"
    r2 = *(uint64_t*)(uintptr_t)(r10 + OFFSET(-64));
    // EBPF_OP_ADD64_REG pc=151 dst=r1 src=r2 offset=0 imm=0
#line 48 "sample/sockops.c"
    r1 += r2;
    // EBPF_OP_LDXW pc=152 dst=r1 src=r1 offset=0 imm=0
#line 48 "sample/sockops.c"
    r1 = *(uint32_t*)(uintptr_t)(r1 + OFFSET(0));
    // EBPF_OP_STXH pc=153 dst=r10 src=r1 offset=-32 imm=0
#line 48 "sample/sockops.c"
    *(uint16_t*)(uintptr_t)(r10 + OFFSET(-32)) = (uint16_t)r1;
    // EBPF_OP_LDXB pc=154 dst=r4 src=r3 offset=13 imm=0
#line 50 "sample/sockops.c"
    r4 = *(uint8_t*)(uintptr_t)(r3 + OFFSET(13));
    // EBPF_OP_LSH64_IMM pc=155 dst=r4 src=r0 offset=0 imm=8
#line 50 "sample/sockops.c"
    r4 <<= IMMEDIATE(8);
    // EBPF_OP_LDXB pc=156 dst=r1 src=r3 offset=12 imm=0
#line 50 "sample/sockops.c"
    r1 = *(uint8_t*)(uintptr_t)(r3 + OFFSET(12));
    // EBPF_OP_OR64_REG pc=157 dst=r4 src=r1 offset=0 imm=0
#line 50 "sample/sockops.c"
    r4 |= r1;
    // EBPF_OP_LDXB pc=158 dst=r2 src=r3 offset=15 imm=0
#line 50 "sample/sockops.c"
    r2 = *(uint8_t*)(uintptr_t)(r3 + OFFSET(15));
    // EBPF_OP_LSH64_IMM pc=159 dst=r2 src=r0 offset=0 imm=8
#line 50 "sample/sockops.c"
    r2 <<= IMMEDIATE(8);
    // EBPF_OP_LDXB pc=160 dst=r1 src=r3 offset=14 imm=0
#line 50 "sample/sockops.c"
    r1 = *(uint8_t*)(uintptr_t)(r3 + OFFSET(14));
    // EBPF_OP_OR64_REG pc=161 dst=r2 src=r1 offset=0 imm=0
#line 50 "sample/sockops.c"
    r2 |= r1;
    // EBPF_OP_LDXB pc=162 dst=r5 src=r3 offset=1 imm=0
#line 50 "sample/sockops.c"
    r5 = *(uint8_t*)(uintptr_t)(r3 + OFFSET(1));
    // EBPF_OP_LSH64_IMM pc=163 dst=r5 src=r0 offset=0 imm=8
#line 50 "sample/sockops.c"
    r5 <<= IMMEDIATE(8);
    // EBPF_OP_LDXB pc=164 dst=r1 src=r3 offset=0 imm=0
#line 50 "sample/sockops.c"
    r1 = *(uint8_t*)(uintptr_t)(r3 + OFFSET(0));
    // EBPF_OP_OR64_REG pc=165 dst=r5 src=r1 offset=0 imm=0
#line 50 "sample/sockops.c"
    r5 |= r1;
    // EBPF_OP_LDXB pc=166 dst=r1 src=r3 offset=3 imm=0
#line 50 "sample/sockops.c"
    r1 = *(uint8_t*)(uintptr_t)(r3 + OFFSET(3));
    // EBPF_OP_LSH64_IMM pc=167 dst=r1 src=r0 offset=0 imm=8
#line 50 "sample/sockops.c"
    r1 <<= IMMEDIATE(8);
    // EBPF_OP_LDXB pc=168 dst=r0 src=r3 offset=2 imm=0
#line 50 "sample/sockops.c"
    r0 = *(uint8_t*)(uintptr_t)(r3 + OFFSET(2));
    // EBPF_OP_OR64_REG pc=169 dst=r1 src=r0 offset=0 imm=0
#line 50 "sample/sockops.c"
    r1 |= r0;
    // EBPF_OP_LSH64_IMM pc=170 dst=r1 src=r0 offset=0 imm=16
#line 50 "sample/sockops.c"
    r1 <<= IMMEDIATE(16);
    // EBPF_OP_OR64_REG pc=171 dst=r1 src=r5 offset=0 imm=0
#line 50 "sample/sockops.c"
    r1 |= r5;
    // EBPF_OP_LSH64_IMM pc=172 dst=r2 src=r0 offset=0 imm=16
#line 50 "sample/sockops.c"
    r2 <<= IMMEDIATE(16);
    // EBPF_OP_OR64_REG pc=173 dst=r2 src=r4 offset=0 imm=0
#line 50 "sample/sockops.c"
    r2 |= r4;
    // EBPF_OP_LDXB pc=174 dst=r4 src=r3 offset=9 imm=0
#line 50 "sample/sockops.c"
    r4 = *(uint8_t*)(uintptr_t)(r3 + OFFSET(9));
    // EBPF_OP_LSH64_IMM pc=175 dst=r4 src=r0 offset=0 imm=8
#line 50 "sample/sockops.c"
    r4 <<= IMMEDIATE(8);
    // EBPF_OP_LDXB pc=176 dst=r5 src=r3 offset=8 imm=0
#line 50 "sample/sockops.c"
    r5 = *(uint8_t*)(uintptr_t)(r3 + OFFSET(8));
    // EBPF_OP_OR64_REG pc=177 dst=r4 src=r5 offset=0 imm=0
#line 50 "sample/sockops.c"
    r4 |= r5;
    // EBPF_OP_LDXB pc=178 dst=r5 src=r3 offset=11 imm=0
#line 50 "sample/sockops.c"
    r5 = *(uint8_t*)(uintptr_t)(r3 + OFFSET(11));
    // EBPF_OP_LSH64_IMM pc=179 dst=r5 src=r0 offset=0 imm=8
#line 50 "sample/sockops.c"
    r5 <<= IMMEDIATE(8);
    // EBPF_OP_LDXB pc=180 dst=r0 src=r3 offset=10 imm=0
#line 50 "sample/sockops.c"
    r0 = *(uint8_t*)(uintptr_t)(r3 + OFFSET(10));
    // EBPF_OP_OR64_REG pc=181 dst=r5 src=r0 offset=0 imm=0
#line 50 "sample/sockops.c"
    r5 |= r0;
    // EBPF_OP_LSH64_IMM pc=182 dst=r5 src=r0 offset=0 imm=16
#line 50 "sample/sockops.c"
    r5 <<= IMMEDIATE(16);
    // EBPF_OP_OR64_REG pc=183 dst=r5 src=r4 offset=0 imm=0
#line 50 "sample/sockops.c"
    r5 |= r4;
    // EBPF_OP_STXW pc=184 dst=r10 src=r5 offset=-20 imm=0
#line 50 "sample/sockops.c"
    *(uint32_t*)(uintptr_t)(r10 + OFFSET(-20)) = (uint32_t)r5;
    // EBPF_OP_STXW pc=185 dst=r10 src=r2 offset=-16 imm=0
#line 50 "sample/sockops.c"
    *(uint32_t*)(uintptr_t)(r10 + OFFSET(-16)) = (uint32_t)r2;
    // EBPF_OP_STXW pc=186 dst=r10 src=r1 offset=-28 imm=0
#line 50 "sample/sockops.c"
    *(uint32_t*)(uintptr_t)(r10 + OFFSET(-28)) = (uint32_t)r1;
    // EBPF_OP_LDXB pc=187 dst=r1 src=r3 offset=5 imm=0
#line 50 "sample/sockops.c"
    r1 = *(uint8_t*)(uintptr_t)(r3 + OFFSET(5));
    // EBPF_OP_LSH64_IMM pc=188 dst=r1 src=r0 offset=0 imm=8
#line 50 "sample/sockops.c"
    r1 <<= IMMEDIATE(8);
    // EBPF_OP_LDXB pc=189 dst=r2 src=r3 offset=4 imm=0
#line 50 "sample/sockops.c"
    r2 = *(uint8_t*)(uintptr_t)(r3 + OFFSET(4));
    // EBPF_OP_OR64_REG pc=190 dst=r1 src=r2 offset=0 imm=0
#line 50 "sample/sockops.c"
    r1 |= r2;
    // EBPF_OP_LDXB pc=191 dst=r2 src=r3 offset=6 imm=0
#line 50 "sample/sockops.c"
    r2 = *(uint8_t*)(uintptr_t)(r3 + OFFSET(6));
    // EBPF_OP_LDXB pc=192 dst=r3 src=r3 offset=7 imm=0
#line 50 "sample/sockops.c"
    r3 = *(uint8_t*)(uintptr_t)(r3 + OFFSET(7));
    // EBPF_OP_LSH64_IMM pc=193 dst=r3 src=r0 offset=0 imm=8
#line 50 "sample/sockops.c"
    r3 <<= IMMEDIATE(8);
    // EBPF_OP_OR64_REG pc=194 dst=r3 src=r2 offset=0 imm=0
#line 50 "sample/sockops.c"
    r3 |= r2;
    // EBPF_OP_LSH64_IMM pc=195 dst=r3 src=r0 offset=0 imm=16
#line 50 "sample/sockops.c"
    r3 <<= IMMEDIATE(16);
    // EBPF_OP_OR64_REG pc=196 dst=r3 src=r1 offset=0 imm=0
#line 50 "sample/sockops.c"
    r3 |= r1;
    // EBPF_OP_STXW pc=197 dst=r10 src=r3 offset=-24 imm=0
#line 50 "sample/sockops.c"
    *(uint32_t*)(uintptr_t)(r10 + OFFSET(-24)) = (uint32_t)r3;
    // EBPF_OP_MOV64_REG pc=198 dst=r1 src=r6 offset=0 imm=0
#line 51 "sample/sockops.c"
    r1 = r6;
    // EBPF_OP_LDXDW pc=199 dst=r2 src=r10 offset=-72 imm=0
#line 51 "sample/sockops.c"
    r2 = *(uint64_t*)(uintptr_t)(r10 + OFFSET(-72));
    // EBPF_OP_ADD64_REG pc=200 dst=r1 src=r2 offset=0 imm=0
#line 51 "sample/sockops.c"
    r1 += r2;
    // EBPF_OP_LDXW pc=201 dst=r1 src=r1 offset=0 imm=0
#line 51 "sample/sockops.c"
    r1 = *(uint32_t*)(uintptr_t)(r1 + OFFSET(0));
    // EBPF_OP_STXH pc=202 dst=r10 src=r1 offset=-12 imm=0
#line 51 "sample/sockops.c"
    *(uint16_t*)(uintptr_t)(r10 + OFFSET(-12)) = (uint16_t)r1;
    // EBPF_OP_LDXB pc=203 dst=r1 src=r6 offset=48 imm=0
#line 52 "sample/sockops.c"
    r1 = *(uint8_t*)(uintptr_t)(r6 + OFFSET(48));
    // EBPF_OP_LDXDW pc=204 dst=r2 src=r10 offset=-56 imm=0
#line 54 "sample/sockops.c"
    r2 = *(uint64_t*)(uintptr_t)(r10 + OFFSET(-56));
    // EBPF_OP_STXB pc=205 dst=r10 src=r2 offset=-4 imm=0
#line 54 "sample/sockops.c"
    *(uint8_t*)(uintptr_t)(r10 + OFFSET(-4)) = (uint8_t)r2;
    // EBPF_OP_STXW pc=206 dst=r10 src=r1 offset=-8 imm=0
#line 52 "sample/sockops.c"
    *(uint32_t*)(uintptr_t)(r10 + OFFSET(-8)) = (uint32_t)r1;
    // EBPF_OP_MOV64_REG pc=207 dst=r2 src=r10 offset=0 imm=0
#line 52 "sample/sockops.c"
    r2 = r10;
    // EBPF_OP_ADD64_IMM pc=208 dst=r2 src=r0 offset=0 imm=-48
#line 53 "sample/sockops.c"
    r2 += IMMEDIATE(-48);
    // EBPF_OP_LDDW pc=209 dst=r1 src=r0 offset=0 imm=0
#line 56 "sample/sockops.c"
    r1 = POINTER(_maps[0].address);
    // EBPF_OP_CALL pc=211 dst=r0 src=r0 offset=0 imm=1
#line 56 "sample/sockops.c"
    r0 = connection_monitor_helpers[0].address
#line 56 "sample/sockops.c"
         (r1, r2, r3, r4, r5);
#line 56 "sample/sockops.c"
    if ((connection_monitor_helpers[0].tail_call) && (r0 == 0))
#line 56 "sample/sockops.c"
        return 0;
        // EBPF_OP_MOV64_IMM pc=212 dst=r6 src=r0 offset=0 imm=0
#line 56 "sample/sockops.c"
    r6 = IMMEDIATE(0);
    // EBPF_OP_JEQ_IMM pc=213 dst=r0 src=r0 offset=8 imm=0
#line 56 "sample/sockops.c"
    if (r0 == IMMEDIATE(0))
#line 56 "sample/sockops.c"
        goto label_13;
label_12:
    // EBPF_OP_MOV64_REG pc=214 dst=r2 src=r10 offset=0 imm=0
#line 56 "sample/sockops.c"
    r2 = r10;
    // EBPF_OP_ADD64_IMM pc=215 dst=r2 src=r0 offset=0 imm=-48
#line 56 "sample/sockops.c"
    r2 += IMMEDIATE(-48);
    // EBPF_OP_LDDW pc=216 dst=r1 src=r0 offset=0 imm=0
#line 56 "sample/sockops.c"
    r1 = POINTER(_maps[1].address);
    // EBPF_OP_MOV64_IMM pc=218 dst=r3 src=r0 offset=0 imm=48
#line 56 "sample/sockops.c"
    r3 = IMMEDIATE(48);
    // EBPF_OP_MOV64_IMM pc=219 dst=r4 src=r0 offset=0 imm=0
#line 56 "sample/sockops.c"
    r4 = IMMEDIATE(0);
    // EBPF_OP_CALL pc=220 dst=r0 src=r0 offset=0 imm=11
#line 56 "sample/sockops.c"
    r0 = connection_monitor_helpers[1].address
#line 56 "sample/sockops.c"
         (r1, r2, r3, r4, r5);
#line 56 "sample/sockops.c"
    if ((connection_monitor_helpers[1].tail_call) && (r0 == 0))
#line 56 "sample/sockops.c"
        return 0;
        // EBPF_OP_MOV64_REG pc=221 dst=r6 src=r0 offset=0 imm=0
#line 56 "sample/sockops.c"
    r6 = r0;
label_13:
    // EBPF_OP_MOV64_REG pc=222 dst=r0 src=r6 offset=0 imm=0
#line 89 "sample/sockops.c"
    r0 = r6;
    // EBPF_OP_EXIT pc=223 dst=r0 src=r0 offset=0 imm=0
#line 89 "sample/sockops.c"
    return r0;
#line 89 "sample/sockops.c"
}
#pragma code_seg(pop)
#line __LINE__ __FILE__

#pragma data_seg(push, "programs")
static program_entry_t _programs[] = {
    {
        0,
        connection_monitor,
        "sockops",
        "sockops",
        "connection_monitor",
        connection_monitor_maps,
        2,
        connection_monitor_helpers,
        2,
        224,
        &connection_monitor_program_type_guid,
        &connection_monitor_attach_type_guid,
    },
};
#pragma data_seg(pop)

static void
_get_programs(_Outptr_result_buffer_(*count) program_entry_t** programs, _Out_ size_t* count)
{
    *programs = _programs;
    *count = 1;
}

metadata_table_t sockops_metadata_table = {_get_programs, _get_maps, _get_hash};