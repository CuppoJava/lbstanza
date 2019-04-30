#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<stdint.h>

//============================================================
//=================== OPCODES ================================
//============================================================

#define SET_OPCODE_LOCAL 0
#define SET_OPCODE_UNSIGNED 1
#define SET_OPCODE_SIGNED 2
#define SET_OPCODE_CODE 3
#define SET_OPCODE_EXTERN 4
#define SET_OPCODE_EXTERN_DEFN 21
#define SET_OPCODE_GLOBAL 5
#define SET_OPCODE_DATA 6
#define SET_OPCODE_CONST 7
#define SET_OPCODE_WIDE 8
#define SET_REG_OPCODE_LOCAL 9
#define SET_REG_OPCODE_UNSIGNED 10
#define SET_REG_OPCODE_SIGNED 11
#define SET_REG_OPCODE_CODE 12
#define SET_REG_OPCODE_EXTERN 13
#define SET_REG_OPCODE_EXTERN_DEFN 25
#define SET_REG_OPCODE_GLOBAL 14
#define SET_REG_OPCODE_DATA 15
#define SET_REG_OPCODE_CONST 16
#define SET_REG_OPCODE_WIDE 17
#define GET_REG_OPCODE 18
#define CALL_OPCODE_LOCAL 19
#define CALL_OPCODE_CODE 20
#define CALL_CLOSURE_OPCODE 22
#define TCALL_OPCODE_LOCAL 23
#define TCALL_OPCODE_CODE 24
#define TCALL_CLOSURE_OPCODE 26
#define CALLC_OPCODE_LOCAL 27
#define CALLC_OPCODE_EXTERN 29
#define CALLC_OPCODE_EXTERN_DEFN 28
#define POP_FRAME_OPCODE 30
#define LIVE_OPCODE 31
#define YIELD_OPCODE 32
#define RETURN_OPCODE 33
#define DUMP_OPCODE 34
#define INT_ADD_OPCODE 35
#define INT_SUB_OPCODE 36
#define INT_MUL_OPCODE 37
#define INT_DIV_OPCODE 38
#define INT_MOD_OPCODE 39
#define INT_AND_OPCODE 40
#define INT_OR_OPCODE 41
#define INT_XOR_OPCODE 42
#define INT_SHL_OPCODE 43
#define INT_SHR_OPCODE 44
#define INT_ASHR_OPCODE 45
#define INT_LT_OPCODE 46
#define INT_GT_OPCODE 47
#define INT_LE_OPCODE 48
#define INT_GE_OPCODE 49
#define EQ_OPCODE_REF_REF 50
#define EQ_OPCODE_REF 51
#define EQ_OPCODE_BYTE 52
#define EQ_OPCODE_INT 53
#define EQ_OPCODE_LONG 54
#define EQ_OPCODE_FLOAT 55
#define EQ_OPCODE_DOUBLE 56
#define NE_OPCODE_REF_REF 57
#define NE_OPCODE_REF 58
#define NE_OPCODE_BYTE 59
#define NE_OPCODE_INT 60
#define NE_OPCODE_LONG 61
#define NE_OPCODE_FLOAT 62
#define NE_OPCODE_DOUBLE 63
#define ADD_OPCODE_BYTE 64
#define ADD_OPCODE_INT 65
#define ADD_OPCODE_LONG 66
#define ADD_OPCODE_FLOAT 67
#define ADD_OPCODE_DOUBLE 68
#define SUB_OPCODE_BYTE 69
#define SUB_OPCODE_INT 70
#define SUB_OPCODE_LONG 71
#define SUB_OPCODE_FLOAT 72
#define SUB_OPCODE_DOUBLE 73
#define MUL_OPCODE_BYTE 74
#define MUL_OPCODE_INT 75
#define MUL_OPCODE_LONG 76
#define MUL_OPCODE_FLOAT 77
#define MUL_OPCODE_DOUBLE 78
#define DIV_OPCODE_BYTE 79
#define DIV_OPCODE_INT 80
#define DIV_OPCODE_LONG 81
#define DIV_OPCODE_FLOAT 82
#define DIV_OPCODE_DOUBLE 83
#define MOD_OPCODE_BYTE 84
#define MOD_OPCODE_INT 85
#define MOD_OPCODE_LONG 86
#define AND_OPCODE_BYTE 87
#define AND_OPCODE_INT 88
#define AND_OPCODE_LONG 89
#define OR_OPCODE_BYTE 90
#define OR_OPCODE_INT 91
#define OR_OPCODE_LONG 92
#define XOR_OPCODE_BYTE 93
#define XOR_OPCODE_INT 94
#define XOR_OPCODE_LONG 95
#define SHL_OPCODE_BYTE 96
#define SHL_OPCODE_INT 97
#define SHL_OPCODE_LONG 98
#define SHR_OPCODE_BYTE 99
#define SHR_OPCODE_INT 100
#define SHR_OPCODE_LONG 101
#define ASHR_OPCODE_INT 103
#define ASHR_OPCODE_LONG 104
#define LT_OPCODE_INT 105
#define LT_OPCODE_LONG 106
#define LT_OPCODE_FLOAT 107
#define LT_OPCODE_DOUBLE 108
#define GT_OPCODE_INT 109
#define GT_OPCODE_LONG 110
#define GT_OPCODE_FLOAT 111
#define GT_OPCODE_DOUBLE 112
#define LE_OPCODE_INT 113
#define LE_OPCODE_LONG 114
#define LE_OPCODE_FLOAT 115
#define LE_OPCODE_DOUBLE 116
#define GE_OPCODE_INT 117
#define GE_OPCODE_LONG 118
#define GE_OPCODE_FLOAT 119
#define GE_OPCODE_DOUBLE 120
#define ULE_OPCODE_BYTE 121
#define ULE_OPCODE_INT 122
#define ULE_OPCODE_LONG 123
#define ULT_OPCODE_BYTE 124
#define ULT_OPCODE_INT 125
#define ULT_OPCODE_LONG 126
#define UGT_OPCODE_BYTE 127
#define UGT_OPCODE_INT 128
#define UGT_OPCODE_LONG 129
#define UGE_OPCODE_BYTE 130
#define UGE_OPCODE_INT 131
#define UGE_OPCODE_LONG 132
#define INT_NOT_OPCODE 133
#define INT_NEG_OPCODE 134
#define NOT_OPCODE_BYTE 135
#define NOT_OPCODE_INT 136
#define NOT_OPCODE_LONG 137
#define NEG_OPCODE_INT 138
#define NEG_OPCODE_LONG 139
#define NEG_OPCODE_FLOAT 140
#define NEG_OPCODE_DOUBLE 141
#define DEREF_OPCODE 142
#define TYPEOF_OPCODE 143
#define JUMP_SET_OPCODE 144
#define GOTO_OPCODE 145
#define CONV_OPCODE_BYTE_FLOAT 146
#define CONV_OPCODE_BYTE_DOUBLE 147
#define CONV_OPCODE_INT_BYTE 148
#define CONV_OPCODE_INT_FLOAT 149
#define CONV_OPCODE_INT_DOUBLE 150
#define CONV_OPCODE_LONG_BYTE 151
#define CONV_OPCODE_LONG_INT 152
#define CONV_OPCODE_LONG_FLOAT 153
#define CONV_OPCODE_LONG_DOUBLE 154
#define CONV_OPCODE_FLOAT_BYTE 155
#define CONV_OPCODE_FLOAT_INT 156
#define CONV_OPCODE_FLOAT_LONG 157
#define CONV_OPCODE_FLOAT_DOUBLE 158
#define CONV_OPCODE_DOUBLE_BYTE 159
#define CONV_OPCODE_DOUBLE_INT 160
#define CONV_OPCODE_DOUBLE_LONG 161
#define CONV_OPCODE_DOUBLE_FLOAT 162
#define DETAG_OPCODE 163
#define TAG_OPCODE_BYTE 164
#define TAG_OPCODE_CHAR 165
#define TAG_OPCODE_INT 166
#define TAG_OPCODE_FLOAT 167
#define STORE_OPCODE_1 168
#define STORE_OPCODE_4 169
#define STORE_OPCODE_8 170
#define STORE_OPCODE_1_VAR_OFFSET 171
#define STORE_OPCODE_4_VAR_OFFSET 172
#define STORE_OPCODE_8_VAR_OFFSET 173
#define LOAD_OPCODE_1 174
#define LOAD_OPCODE_4 175
#define LOAD_OPCODE_8 176
#define LOAD_OPCODE_1_VAR_OFFSET 177
#define LOAD_OPCODE_4_VAR_OFFSET 178
#define LOAD_OPCODE_8_VAR_OFFSET 179
#define RESERVE_OPCODE_LOCAL 180
#define RESERVE_OPCODE_CONST 181
#define ENTER_STACK_OPCODE 182
#define ALLOC_OPCODE_CONST 183
#define ALLOC_OPCODE_LOCAL 184
#define GC_OPCODE 185
#define CLASS_NAME_OPCODE 241
#define PRINT_STACK_TRACE_OPCODE 186
#define FLUSH_VM_OPCODE 188
#define JUMP_INT_LT_OPCODE 192
#define JUMP_INT_GT_OPCODE 193
#define JUMP_INT_LE_OPCODE 194
#define JUMP_INT_GE_OPCODE 195
#define JUMP_EQ_OPCODE_REF 196
#define JUMP_EQ_OPCODE_BYTE 197
#define JUMP_EQ_OPCODE_INT 198
#define JUMP_EQ_OPCODE_LONG 199
#define JUMP_EQ_OPCODE_FLOAT 200
#define JUMP_EQ_OPCODE_DOUBLE 201
#define JUMP_NE_OPCODE_REF 202
#define JUMP_NE_OPCODE_BYTE 203
#define JUMP_NE_OPCODE_INT 204
#define JUMP_NE_OPCODE_LONG 205
#define JUMP_NE_OPCODE_FLOAT 206
#define JUMP_NE_OPCODE_DOUBLE 207
#define JUMP_LT_OPCODE_INT 208
#define JUMP_LT_OPCODE_LONG 209
#define JUMP_LT_OPCODE_FLOAT 210
#define JUMP_LT_OPCODE_DOUBLE 211
#define JUMP_GT_OPCODE_INT 212
#define JUMP_GT_OPCODE_LONG 213
#define JUMP_GT_OPCODE_FLOAT 214
#define JUMP_GT_OPCODE_DOUBLE 215
#define JUMP_LE_OPCODE_INT 216
#define JUMP_LE_OPCODE_LONG 217
#define JUMP_LE_OPCODE_FLOAT 218
#define JUMP_LE_OPCODE_DOUBLE 219
#define JUMP_GE_OPCODE_INT 220
#define JUMP_GE_OPCODE_LONG 221
#define JUMP_GE_OPCODE_FLOAT 222
#define JUMP_GE_OPCODE_DOUBLE 223
#define JUMP_ULE_OPCODE_BYTE 224
#define JUMP_ULE_OPCODE_INT 225
#define JUMP_ULE_OPCODE_LONG 226
#define JUMP_ULT_OPCODE_BYTE 227
#define JUMP_ULT_OPCODE_INT 228
#define JUMP_ULT_OPCODE_LONG 229
#define JUMP_UGT_OPCODE_BYTE 230
#define JUMP_UGT_OPCODE_INT 231
#define JUMP_UGT_OPCODE_LONG 232
#define JUMP_UGE_OPCODE_BYTE 233
#define JUMP_UGE_OPCODE_INT 234
#define JUMP_UGE_OPCODE_LONG 235
#define DISPATCH_OPCODE 236
#define DISPATCH_METHOD_OPCODE 237
#define JUMP_REG_OPCODE 238
#define FNENTRY_OPCODE 239

//============================================================
//===================== READ MACROS ==========================
//============================================================

#define PC_INT() \
  ({unsigned int _x = *(unsigned int*)pc; \
    pc += 4; \
    _x;});

#define PC_LONG() \
  ({uint64_t _x = *(uint64_t*)pc; \
    pc += 8; \
    _x;});

#define DECODE_A_UNSIGNED() \
  int value = W1 >> 8; \
  /*if(iprint) printf("          [%d | %d]\n", opcode, value);*/

#define DECODE_A_SIGNED() \
  int value = (int)W1 >> 8; \
  /*if(iprint) printf("          [%d | %d]\n", opcode, value);*/

#define DECODE_B_UNSIGNED() \
  int x = (W1 >> 8) & 0x3FF; \
  int value = W1 >> 18; \
  /*if(iprint) printf("          [%d | %d | %d]\n", opcode, x, value);*/

#define DECODE_C() \
  int x = (W1 >> 8) & 0x3FF; \
  int y = (W1 >> 22) & 0x3FF; \
  int value = PC_INT(); \
  /*if(iprint) printf("          [%d | %d | %d | %d]\n", opcode, x, y, value);*/

#define DECODE_D() \
  int x = (W1 >> 22) & 0x3FF; \
  long value = PC_LONG(); \
  /*if(iprint) printf("          [%d | _ | %d | %ld]\n", opcode, x, value);*/

#define DECODE_E() \
  unsigned int W2 = PC_INT(); \
  uint64_t W12 = W1 | ((uint64_t)W2 << 32); \
  int x = (int)(W12 >> 8) & 0x3FF;  \
  int y = (int)(W12 >> 18) & 0x3FF; \
  int z = (int)(W12 >> 28) & 0x3FF; \
  int value = (int)((int64_t)W12 >> 38); \
  /*if(iprint) printf("          [%d | %d | %d | %d | %d]\n", opcode, x, y, z, value);*/

#define DECODE_F() \
  unsigned int W2 = PC_INT(); \
  uint64_t W12 = W1 | ((uint64_t)W2 << 32); \
  int x = (int)(W12 >> 8) & 0x3FF;  \
  int y = (int)(W12 >> 18) & 0x3FF; \
  int _n1 = (int)(W12 >> 14); /*Move first bit to 32-bit boundary*/ \
  int n1 = (int)(_n1 >> 14); /*Extend sign-bit*/ \
  int n2 = (int)((int)W2 >> 14); /*Extend sign-bit of first word*/ \
  /*if(iprint) printf("          [%d | %d | %d | %d | %d]\n", opcode, x, y, n1, n2);*/

#define F_JUMP(condition) \
  if(condition){ \
    pc = pc0 + (n1 * 4); \
    continue; \
  } \
  else{ \
    pc = pc0 + (n2 * 4); \
    continue; \
  }

#define DECODE_TGTS() \
  int n = PC_INT(); \
  for(int i=0; i<n; i++){ \
    int tgt = PC_INT(); \
    /*printf("            tgt: %d\n", tgt);*/ \
  }

#define SET_REG(r,v) \
  registers[r] = v    
#define SET_LOCAL(l,v) \
  stack_pointer->slots[l] = v;
#define SET_LOCAL_FLOAT(l,v) \
  float* addr = (float*)&(stack_pointer->slots[l]); \
  *addr = v;
#define SET_LOCAL_DOUBLE(l,v) \
  double* addr = (double*)&(stack_pointer->slots[l]); \
  *addr = v;

#define LOCAL(l) (stack_pointer->slots[l])
#define LOCAL_FLOAT(l) \
  ({float* addr = (float*)&(stack_pointer->slots[l]); \
    *addr;})
#define LOCAL_DOUBLE(l) \
  ({double* addr = (double*)&(stack_pointer->slots[l]); \
    *addr;})

#define PUSH_FRAME(num_locals) \
  stack_pointer = (StackFrame*)((char*)stack_pointer + sizeof(StackFrame) + (num_locals) * 8); \
  stack_pointer->returnpc = (uint64_t)(pc - instructions);

#define POP_FRAME(num_locals) \
  stack_pointer = (StackFrame*)((char*)stack_pointer - sizeof(StackFrame) - (num_locals) * 8);  

#define SAVE_STATE() \
  vms->heap_top = heap_top; \
  vms->current_stack = current_stack; \
  stk->stack_pointer = stack_pointer; 

#define RESTORE_STATE() \
  heap_top = vms->heap_top; \
  heap_limit = vms->heap_limit; \
  current_stack = vms->current_stack; \
  stk = untag_stack(current_stack); \
  stack_pointer = stk->stack_pointer; \
  stack_limit = (char*)(stk->frames) + stk->size;

#define INT_TAG_BITS 0
#define REF_TAG_BITS 1
#define MARKER_TAG_BITS 2
#define BYTE_TAG_BITS 3
#define CHAR_TAG_BITS 4
#define FLOAT_TAG_BITS 5  

#define FALSE_TYPE 0
#define TRUE_TYPE 1
#define BYTE_TYPE 2
#define CHAR_TYPE 3
#define INT_TYPE 4
#define FLOAT_TYPE 5
#define STACK_TYPE 6
#define FN_TYPE 7
#define TYPE_TYPE 8
#define LIVENESS_TRACKER_TYPE 9

#define BOOLREF(x) (((x) << 3) + MARKER_TAG_BITS)

#define SYSTEM_RETURN_STUB -2

//============================================================
//==================== Machine Types =========================
//============================================================

typedef struct{
  //Permanent State
  //Changes in-between each code load
  char* instructions;
  uint64_t* registers;
  uint64_t* global_offsets;
  char* global_mem;
  uint64_t* const_table;
  char* const_mem;
  uint32_t* data_offsets;
  char* data_mem;
  uint64_t* extern_table;
  uint64_t* extern_defn_addresses;
  uint32_t* code_offsets;
  int extend_heap_id;
  int extend_stack_id;
  //Variable State
  //Changes in_between each boundary change
  char* heap;
  char* heap_top;
  char* heap_limit;
  char* free;
  char* free_limit;
  uint64_t current_stack;
  //System state
  uint64_t system_stack;  
  uint64_t* system_registers;
} VMState;

typedef struct{
  uint64_t returnpc;
  uint64_t liveness_map;
  uint64_t slots[];
} StackFrame;

typedef struct{
  uint64_t num_slots;
  uint64_t code;
  uint64_t slots[];
} Function;

typedef struct{
  uint64_t size;
  StackFrame* frames;
  StackFrame* stack_pointer;
  long pc;
} Stack;

//============================================================
//========================= TRAPS ============================
//============================================================

void call_c_launcher (VMState* vms, int index, uint64_t faddr);
int call_garbage_collector (VMState* vms, uint64_t total_size);
void call_stack_extender (VMState* vms, uint64_t total_size);
void call_print_stack_trace (VMState* vms, uint64_t stack);
int dispatch_branch (VMState* vms, int format);
char* retrieve_class_name (VMState* vms, long id);
void c_trampoline (void* fptr, void* argbuffer, void* retbuffer);

//============================================================
//===================== MAIN LOOP ============================
//============================================================

Stack* untag_stack (uint64_t current_stack){
  return (Stack*)(current_stack - 1 + 8);
}

uint64_t ptr_to_ref (void* p){
  return (uint64_t)p + REF_TAG_BITS;
}

void vmloop (VMState* vms){
  //Pull out local cache
  char* instructions = vms->instructions;
  uint64_t* registers = vms->registers;
  uint64_t* global_offsets = vms->global_offsets;
  char* global_mem = vms->global_mem;
  uint64_t* const_table = vms->const_table;
  char* const_mem = vms->const_mem;
  uint32_t* data_offsets = vms->data_offsets;
  char* data_mem = vms->data_mem;
  uint64_t* extern_table = vms->extern_table;
  uint64_t* extern_defn_addresses = vms->extern_defn_addresses;
  uint32_t* code_offsets = vms->code_offsets;
  //Variable State
  //Changes in_between each boundary change
  char* heap_top = vms->heap_top;
  char* heap_limit = vms->heap_limit;
  uint64_t current_stack = vms->current_stack;
  Stack* stk = untag_stack(current_stack);
  StackFrame* stack_pointer = stk->stack_pointer;
  char* stack_limit = (char*)(stk->frames) + stk->size;
  char* pc = instructions + stk->pc;  

  //Timing
  //uint64_t* timings = (uint64_t*)malloc(255 * sizeof(uint64_t));
  //for(int i=0; i<255; i++) timings[i] = 0;
  //int last_opcode = -1;
  //uint64_t last_time;

  //Repl Loop
  while(1){
    //Save pre-decode PC because jump offsets are relative to
    //pre-decode PC.
    char* pc0 = pc;
    unsigned int W1 = PC_INT();
    int opcode = W1 & 0xFF;

    //uint64_t curtime = current_time_ms();
    //if(last_opcode >= 0)
    //  timings[last_opcode] += curtime - last_time;
    //last_opcode = opcode;
    //last_time = curtime;
    
    switch(opcode){
    case SET_OPCODE_LOCAL : {
      DECODE_C();
      SET_LOCAL(y, LOCAL(value));      
      continue;
    }
    case SET_OPCODE_UNSIGNED : {
      DECODE_C();
      SET_LOCAL(y, (uint64_t)value);      
      continue;
    }
    case SET_OPCODE_SIGNED : {
      DECODE_C();
      SET_LOCAL(y, (int64_t)value);      
      continue;
    }
    case SET_OPCODE_CODE : {
      DECODE_C();
      SET_LOCAL(y, value);
      continue;
    }
    case SET_OPCODE_EXTERN : {
      DECODE_C();
      SET_LOCAL(y, extern_table[value]);
      continue;
    }
    case SET_OPCODE_EXTERN_DEFN : {
      DECODE_C();
      SET_LOCAL(y, extern_defn_addresses[value]);
      continue;
    }
    case SET_OPCODE_GLOBAL : {
      DECODE_C();
      char* address = global_mem + global_offsets[value];
      SET_LOCAL(y, (uint64_t)address);
      continue;
    }
    case SET_OPCODE_DATA : {
      DECODE_C();
      char* address = data_mem + 8 * data_offsets[value];
      SET_LOCAL(y, (uint64_t)address);
      continue;
    }
    case SET_OPCODE_CONST : {
      DECODE_C();
      SET_LOCAL(y, const_table[value]);
      continue;
    }
    case SET_OPCODE_WIDE : {
      DECODE_D();
      SET_LOCAL(x, value);      
      continue;
    }
    case SET_REG_OPCODE_LOCAL : {
      DECODE_C();
      SET_REG(y, LOCAL(value));      
      continue;
    }
    case SET_REG_OPCODE_UNSIGNED : {
      DECODE_C();
      SET_REG(y, (uint64_t)value);   
      continue;
    }
    case SET_REG_OPCODE_SIGNED : {
      DECODE_C();
      SET_REG(y, (int64_t)value); 
      continue;
    }
    case SET_REG_OPCODE_CODE : {
      DECODE_C();
      SET_REG(y, value);
      continue;
    }
    case SET_REG_OPCODE_EXTERN : {
      DECODE_C();
      SET_REG(y, extern_table[value]);
      continue;
    }
    case SET_REG_OPCODE_EXTERN_DEFN : {
      DECODE_C();
      SET_REG(y, extern_defn_addresses[value]);
      continue;
    }
    case SET_REG_OPCODE_GLOBAL : {
      DECODE_C();
      char* address = global_mem + global_offsets[value];
      SET_REG(y, (uint64_t)address);
      continue;
    }
    case SET_REG_OPCODE_DATA : {
      DECODE_C();
      char* address = data_mem + 8 * data_offsets[value];
      SET_REG(y, (uint64_t)address);
      continue;
    }
    case SET_REG_OPCODE_CONST : {
      DECODE_C();
      SET_REG(y, const_table[value]);
      continue;
    }
    case SET_REG_OPCODE_WIDE : {
      DECODE_D();
      SET_REG(x, value);      
      continue;
    }
    case GET_REG_OPCODE : {
      DECODE_B_UNSIGNED();
      SET_LOCAL(x, registers[value]);
      continue;
    }
    case CALL_OPCODE_LOCAL : {
      DECODE_C();
      int num_locals = y;
      uint64_t fid = LOCAL(value);
      uint64_t fpos = (uint64_t)(code_offsets[fid]) * 4;
      PUSH_FRAME(num_locals);
      pc = instructions + fpos;
      continue;
    }
    case CALL_OPCODE_CODE : {
      DECODE_C();
      int num_locals = y;
      uint64_t fid = value;
      uint64_t fpos = (uint64_t)(code_offsets[fid]) * 4;      
      PUSH_FRAME(num_locals);
      pc = instructions + fpos;
      continue;
    }
    case CALL_CLOSURE_OPCODE : {
      DECODE_C();
      int num_locals = y;
      Function* clo = (Function*)(LOCAL(value) - REF_TAG_BITS + 8);
      uint64_t fid = clo->code;
      uint64_t fpos = (uint64_t)(code_offsets[fid]) * 4;
      PUSH_FRAME(num_locals);
      pc = instructions + fpos;
      continue;
    }
    case TCALL_OPCODE_LOCAL : {
      DECODE_C();
      int num_locals = y;
      uint64_t fid = LOCAL(value);
      uint64_t fpos = (uint64_t)(code_offsets[fid]) * 4;
      pc = instructions + fpos;
      continue;
    }
    case TCALL_OPCODE_CODE : {
      DECODE_C();
      int num_locals = y;
      uint64_t fid = value;
      uint64_t fpos = (uint64_t)(code_offsets[fid]) * 4;      
      pc = instructions + fpos;
      continue;
    }
    case TCALL_CLOSURE_OPCODE : {
      DECODE_A_UNSIGNED();
      Function* clo = (Function*)(LOCAL(value) - REF_TAG_BITS + 8);
      uint64_t fid = clo->code;
      uint64_t fpos = (uint64_t)(code_offsets[fid]) * 4;
      pc = instructions + fpos;
      continue;
    }
    case CALLC_OPCODE_LOCAL : {
      DECODE_C();
      void* faddr = (void*)LOCAL(value);
      int num_locals = x;
      PUSH_FRAME(num_locals);
      SAVE_STATE();
      c_trampoline(faddr, registers, registers);      
      RESTORE_STATE();
      pc = instructions + stack_pointer->returnpc;      
      POP_FRAME(num_locals);
      continue;
    }
    case CALLC_OPCODE_EXTERN : {
      DECODE_D();
      void* faddr = (void*)value;
      int num_locals = x;
      PUSH_FRAME(num_locals);
      SAVE_STATE();
      c_trampoline(faddr, registers, registers);      
      RESTORE_STATE();
      pc = instructions + stack_pointer->returnpc;      
      POP_FRAME(num_locals);
      continue;
    }
    case CALLC_OPCODE_EXTERN_DEFN : {
      DECODE_C();
      uint64_t faddr = extern_defn_addresses[value];
      int format = x;
      int num_locals = y;
      PUSH_FRAME(num_locals);
      SAVE_STATE();
      call_c_launcher(vms, format, faddr);
      RESTORE_STATE();
      pc = instructions + stack_pointer->returnpc;      
      POP_FRAME(num_locals);
      continue;
    }
    case POP_FRAME_OPCODE : {
      DECODE_A_UNSIGNED();
      int num_locals = value;
      POP_FRAME(num_locals);
      continue;
    }
    case LIVE_OPCODE : {
      DECODE_A_UNSIGNED();
      stack_pointer->liveness_map = value;
      continue;
    }
    case ENTER_STACK_OPCODE : {
      DECODE_A_UNSIGNED();
      //Save current stack
      stk->stack_pointer = stack_pointer;
      stk->pc = pc - instructions;
      //Load next stack
      current_stack = LOCAL(value);
      stk = untag_stack(current_stack);
      stack_pointer = stk->frames;
      stack_limit = (char*)(stk->frames) + stk->size;
      //Load starting address
      uint64_t fid = stk->pc;
      uint64_t stk_pc = code_offsets[fid] * 4;
      pc = instructions + stk_pc;
      continue;
    }
    case YIELD_OPCODE : {
      DECODE_A_UNSIGNED();
      //Save current stack
      stk->stack_pointer = stack_pointer;
      stk->pc = pc - instructions;
      //Load next stack
      current_stack = LOCAL(value);
      stk = untag_stack(current_stack);
      stack_pointer = stk->stack_pointer;
      stack_limit = (char*)(stk->frames) + stk->size;
      pc = instructions + stk->pc;
      continue;
    }
    case RETURN_OPCODE : {
      DECODE_A_UNSIGNED();
      int64_t retpc = stack_pointer->returnpc;
      if(retpc == SYSTEM_RETURN_STUB){
        //System stack no longer needed
        stk->stack_pointer = 0;
        //Swap stack and registers
        vms->current_stack = vms->system_stack;
        vms->system_stack = current_stack;
        vms->registers = vms->system_registers;
        vms->system_registers = registers;
        //Restore stack state
        current_stack = vms->current_stack;
        stk = untag_stack(current_stack);
        stack_pointer = stk->stack_pointer;
        stack_limit = (char*)(stk->frames) + stk->size;
        registers = vms->registers;
        //Continue where we were
        retpc = stk->pc;
        
        pc = instructions + retpc;
        continue;        
      }      
      else if(retpc < 0){
        //Save registers
        SAVE_STATE();
        //for(int i=0; i<255; i++)
        //  printf("Time of opcode %d = %llu\n", i, timings[i]);
        return;
      }
      else{
        pc = instructions + retpc;
        continue;
      }
    }
    case DUMP_OPCODE : {
      DECODE_A_UNSIGNED();
      int64_t xl = (int64_t)LOCAL(value);
      char xb = (char)xl;
      int xi = (int)xl;        
      float xf = LOCAL_FLOAT(value);
      float xd = LOCAL_DOUBLE(value);
      printf("DUMP LOCAL %d: (byte = %d, int = %d, long = %ld, ptr = %p, float = %f, double = %f)\n",
             value, xb, xi, xl, (void*)xl, xf, xd);
      continue;
    }
    case INT_ADD_OPCODE : {
      DECODE_C();
      SET_LOCAL(x, (int64_t)(LOCAL(y)) + (int64_t)(LOCAL(value)));
      continue;
    }
    case INT_SUB_OPCODE : {
      DECODE_C();
      SET_LOCAL(x, (int64_t)(LOCAL(y)) - (int64_t)(LOCAL(value)));
      continue;
    }
    case INT_MUL_OPCODE : {
      DECODE_C();
      SET_LOCAL(x, ((int64_t)(LOCAL(y)) >> 32L) * (int64_t)(LOCAL(value)));
      continue;
    }
    case INT_DIV_OPCODE : {
      DECODE_C();
      int64_t sy = (int64_t)LOCAL(y);
      int64_t sz = (int64_t)LOCAL(value);
      SET_LOCAL(x, (sy / sz) << 32L);
      continue;
    }
    case INT_MOD_OPCODE : {
      DECODE_C();
      SET_LOCAL(x, (int64_t)(LOCAL(y)) % (int64_t)(LOCAL(value)));
      continue;
    }
    case INT_AND_OPCODE : {
      DECODE_C();
      SET_LOCAL(x, (int64_t)(LOCAL(y)) & (int64_t)(LOCAL(value)));
      continue;
    }
    case INT_OR_OPCODE : {
      DECODE_C();
      SET_LOCAL(x, (int64_t)(LOCAL(y)) | (int64_t)(LOCAL(value)));
      continue;
    }
    case INT_XOR_OPCODE : {
      DECODE_C();
      SET_LOCAL(x, (int64_t)(LOCAL(y)) ^ (int64_t)(LOCAL(value)));
      continue;
    }
    case INT_SHL_OPCODE : {
      DECODE_C();
      int64_t sy = (int64_t)LOCAL(y);
      int64_t sz = (int64_t)LOCAL(value);
      SET_LOCAL(x, sy << (sz >> 32L));
      continue;
    }
    case INT_SHR_OPCODE : {
      DECODE_C();
      uint64_t uy = LOCAL(y);
      int64_t sz = (int64_t)LOCAL(value);
      uint64_t r = uy >> (sz >> 32L);
      SET_LOCAL(x, (r >> 32L) << 32L);
      continue;
    }
    case INT_ASHR_OPCODE : {
      DECODE_C();
      int64_t sy = (int64_t)LOCAL(y);
      int64_t sz = (int64_t)LOCAL(value);
      uint64_t r = sy >> (sz >> 32L);
      SET_LOCAL(x, (r >> 32L) << 32L);
      continue;
    }
    case INT_LT_OPCODE : {
      DECODE_C();
      SET_LOCAL(x, BOOLREF((int64_t)(LOCAL(y)) < (int64_t)(LOCAL(value))));
      continue;
    }
    case INT_GT_OPCODE : {
      DECODE_C();
      SET_LOCAL(x, BOOLREF((int64_t)(LOCAL(y)) > (int64_t)(LOCAL(value))));
      continue;
    }
    case INT_LE_OPCODE : {
      DECODE_C();
      SET_LOCAL(x, BOOLREF((int64_t)(LOCAL(y)) <= (int64_t)(LOCAL(value))));
      continue;
    }
    case INT_GE_OPCODE : {
      DECODE_C();
      SET_LOCAL(x, BOOLREF((int64_t)(LOCAL(y)) >= (int64_t)(LOCAL(value))));
      continue;
    }
    case EQ_OPCODE_REF_REF : {
      DECODE_C();
      SET_LOCAL(x, BOOLREF(LOCAL(y) == LOCAL(value)));
      continue;
    }
    case EQ_OPCODE_REF : {
      DECODE_C();
      SET_LOCAL(x, LOCAL(y) == LOCAL(value));
      continue;
    }
    case EQ_OPCODE_BYTE : {
      DECODE_C();
      SET_LOCAL(x, (uint8_t)LOCAL(y) == (uint8_t)LOCAL(value));
      continue;
    }
    case EQ_OPCODE_INT : {
      DECODE_C();
      SET_LOCAL(x, (int32_t)LOCAL(y) == (int32_t)LOCAL(value));
      continue;
    }
    case EQ_OPCODE_LONG : {
      DECODE_C();
      SET_LOCAL(x, (int64_t)LOCAL(y) == (int64_t)LOCAL(value));
      continue;
    }
    case EQ_OPCODE_FLOAT : {
      DECODE_C();
      SET_LOCAL(x, LOCAL_FLOAT(y) == LOCAL_FLOAT(value));
      continue;
    }
    case EQ_OPCODE_DOUBLE : {
      DECODE_C();
      SET_LOCAL(x, LOCAL_DOUBLE(y) == LOCAL_DOUBLE(value));
      continue;
    }
    case NE_OPCODE_REF_REF : {
      DECODE_C();
      SET_LOCAL(x, BOOLREF(LOCAL(y) != LOCAL(value)));
      continue;
    }
    case NE_OPCODE_REF : {
      DECODE_C();
      SET_LOCAL(x, LOCAL(y) != LOCAL(value));
      continue;
    }
    case NE_OPCODE_BYTE : {
      DECODE_C();
      SET_LOCAL(x, (uint8_t)LOCAL(y) != (uint8_t)LOCAL(value));
      continue;
    }
    case NE_OPCODE_INT : {
      DECODE_C();
      SET_LOCAL(x, (int32_t)LOCAL(y) != (int32_t)LOCAL(value));
      continue;
    }
    case NE_OPCODE_LONG : {
      DECODE_C();
      SET_LOCAL(x, (int64_t)LOCAL(y) != (int64_t)LOCAL(value));
      continue;
    }
    case NE_OPCODE_FLOAT : {
      DECODE_C();
      SET_LOCAL(x, LOCAL_FLOAT(y) != LOCAL_FLOAT(value));
      continue;
    }
    case NE_OPCODE_DOUBLE : {
      DECODE_C();
      SET_LOCAL(x, LOCAL_DOUBLE(y) != LOCAL_DOUBLE(value));
      continue;
    }
    case ADD_OPCODE_BYTE : {
      DECODE_C();
      SET_LOCAL(x, (char)(LOCAL(y)) + (char)(LOCAL(value)));
      continue;
    }
    case ADD_OPCODE_INT : {
      DECODE_C();
      SET_LOCAL(x, (int32_t)(LOCAL(y)) + (int32_t)(LOCAL(value)));
      continue;
    }
    case ADD_OPCODE_LONG : {
      DECODE_C();
      SET_LOCAL(x, (int64_t)(LOCAL(y)) + (int64_t)(LOCAL(value)));
      continue;
    }
    case ADD_OPCODE_FLOAT : {
      DECODE_C();
      SET_LOCAL_FLOAT(x, LOCAL_FLOAT(y) + LOCAL_FLOAT(value));
      continue;
    }
    case ADD_OPCODE_DOUBLE : {
      DECODE_C();
      SET_LOCAL_DOUBLE(x, LOCAL_DOUBLE(y) + LOCAL_DOUBLE(value));
      continue;
    }
    case SUB_OPCODE_BYTE : {
      DECODE_C();
      SET_LOCAL(x, (char)(LOCAL(y)) - (char)(LOCAL(value)));
      continue;
    }
    case SUB_OPCODE_INT : {
      DECODE_C();
      SET_LOCAL(x, (int32_t)(LOCAL(y)) - (int32_t)(LOCAL(value)));
      continue;
    }
    case SUB_OPCODE_LONG : {
      DECODE_C();
      SET_LOCAL(x, (int64_t)(LOCAL(y)) - (int64_t)(LOCAL(value)));
      continue;
    }
    case SUB_OPCODE_FLOAT : {
      DECODE_C();
      SET_LOCAL_FLOAT(x, LOCAL_FLOAT(y) - LOCAL_FLOAT(value));
      continue;
    }
    case SUB_OPCODE_DOUBLE : {
      DECODE_C();
      SET_LOCAL_DOUBLE(x, LOCAL_DOUBLE(y) - LOCAL_DOUBLE(value));
      continue;
    }
    case MUL_OPCODE_BYTE : {
      DECODE_C();
      SET_LOCAL(x, (char)(LOCAL(y)) * (char)(LOCAL(value)));
      continue;
    }
    case MUL_OPCODE_INT : {
      DECODE_C();
      SET_LOCAL(x, (int32_t)(LOCAL(y)) * (int32_t)(LOCAL(value)));
      continue;
    }
    case MUL_OPCODE_LONG : {
      DECODE_C();
      SET_LOCAL(x, (int64_t)(LOCAL(y)) * (int64_t)(LOCAL(value)));
      continue;
    }
    case MUL_OPCODE_FLOAT : {
      DECODE_C();
      SET_LOCAL_FLOAT(x, LOCAL_FLOAT(y) * LOCAL_FLOAT(value));
      continue;
    }
    case MUL_OPCODE_DOUBLE : {
      DECODE_C();
      SET_LOCAL_DOUBLE(x, LOCAL_DOUBLE(y) * LOCAL_DOUBLE(value));
      continue;
    }      
    case DIV_OPCODE_BYTE : {
      DECODE_C();
      SET_LOCAL(x, (char)(LOCAL(y)) / (char)(LOCAL(value)));
      continue;
    }
    case DIV_OPCODE_INT : {
      DECODE_C();
      SET_LOCAL(x, (int32_t)(LOCAL(y)) / (int32_t)(LOCAL(value)));
      continue;
    }
    case DIV_OPCODE_LONG : {
      DECODE_C();
      SET_LOCAL(x, (int64_t)(LOCAL(y)) / (int64_t)(LOCAL(value)));
      continue;
    }
    case DIV_OPCODE_FLOAT : {
      DECODE_C();
      SET_LOCAL_FLOAT(x, LOCAL_FLOAT(y) / LOCAL_FLOAT(value));
      continue;
    }
    case DIV_OPCODE_DOUBLE : {
      DECODE_C();
      SET_LOCAL_DOUBLE(x, LOCAL_DOUBLE(y) / LOCAL_DOUBLE(value));
      continue;
    }            
    case MOD_OPCODE_BYTE : {
      DECODE_C();
      SET_LOCAL(x, (char)(LOCAL(y)) % (char)(LOCAL(value)));
      continue;
    }
    case MOD_OPCODE_INT : {
      DECODE_C();
      SET_LOCAL(x, (int32_t)(LOCAL(y)) % (int32_t)(LOCAL(value)));
      continue;
    }
    case MOD_OPCODE_LONG : {
      DECODE_C();
      SET_LOCAL(x, (int64_t)(LOCAL(y)) % (int64_t)(LOCAL(value)));
      continue;
    }
    case AND_OPCODE_BYTE : {
      DECODE_C();
      SET_LOCAL(x, (char)(LOCAL(y)) & (char)(LOCAL(value)));
      continue;
    }
    case AND_OPCODE_INT : {
      DECODE_C();
      SET_LOCAL(x, (int32_t)(LOCAL(y)) & (int32_t)(LOCAL(value)));
      continue;
    }
    case AND_OPCODE_LONG : {
      DECODE_C();
      SET_LOCAL(x, (int64_t)(LOCAL(y)) & (int64_t)(LOCAL(value)));
      continue;
    }
    case OR_OPCODE_BYTE : {
      DECODE_C();
      SET_LOCAL(x, (char)(LOCAL(y)) | (char)(LOCAL(value)));
      continue;
    }
    case OR_OPCODE_INT : {
      DECODE_C();
      SET_LOCAL(x, (int32_t)(LOCAL(y)) | (int32_t)(LOCAL(value)));
      continue;
    }
    case OR_OPCODE_LONG : {
      DECODE_C();
      SET_LOCAL(x, (int64_t)(LOCAL(y)) | (int64_t)(LOCAL(value)));
      continue;
    }
    case XOR_OPCODE_BYTE : {
      DECODE_C();
      SET_LOCAL(x, (char)(LOCAL(y)) ^ (char)(LOCAL(value)));
      continue;
    }
    case XOR_OPCODE_INT : {
      DECODE_C();
      SET_LOCAL(x, (int32_t)(LOCAL(y)) ^ (int32_t)(LOCAL(value)));
      continue;
    }
    case XOR_OPCODE_LONG : {
      DECODE_C();
      SET_LOCAL(x, (int64_t)(LOCAL(y)) ^ (int64_t)(LOCAL(value)));
      continue;
    }
    case SHL_OPCODE_BYTE : {
      DECODE_C();
      SET_LOCAL(x, (char)(LOCAL(y)) << (char)(LOCAL(value)));
      continue;
    }
    case SHL_OPCODE_INT : {
      DECODE_C();
      SET_LOCAL(x, (int32_t)(LOCAL(y)) << (int32_t)(LOCAL(value)));
      continue;
    }
    case SHL_OPCODE_LONG : {
      DECODE_C();
      SET_LOCAL(x, (int64_t)(LOCAL(y)) << (int64_t)(LOCAL(value)));
      continue;
    }
    case SHR_OPCODE_BYTE : {
      DECODE_C();
      SET_LOCAL(x, (unsigned char)(LOCAL(y)) >> (unsigned char)(LOCAL(value)));
      continue;
    }
    case SHR_OPCODE_INT : {
      DECODE_C();
      SET_LOCAL(x, (uint32_t)(LOCAL(y)) >> (uint32_t)(LOCAL(value)));
      continue;
    }
    case SHR_OPCODE_LONG : {
      DECODE_C();
      SET_LOCAL(x, (uint64_t)(LOCAL(y)) >> (uint64_t)(LOCAL(value)));
      continue;
    }
    case ASHR_OPCODE_INT : {
      DECODE_C();
      SET_LOCAL(x, (int32_t)(LOCAL(y)) >> (int32_t)(LOCAL(value)));
      continue;
    }
    case ASHR_OPCODE_LONG : {
      DECODE_C();
      SET_LOCAL(x, (int64_t)(LOCAL(y)) >> (int64_t)(LOCAL(value)));
      continue;
    }
    case LT_OPCODE_INT : {
      DECODE_C();
      SET_LOCAL(x, (int32_t)(LOCAL(y)) < (int32_t)(LOCAL(value)));
      continue;
    }
    case LT_OPCODE_LONG : {
      DECODE_C();
      SET_LOCAL(x, (int64_t)(LOCAL(y)) < (int64_t)(LOCAL(value)));
      continue;
    }
    case LT_OPCODE_FLOAT : {
      DECODE_C();
      SET_LOCAL(x, LOCAL_FLOAT(y) < LOCAL_FLOAT(value));
      continue;
    }
    case LT_OPCODE_DOUBLE : {
      DECODE_C();
      SET_LOCAL(x, LOCAL_DOUBLE(y) < LOCAL_DOUBLE(value));
      continue;
    }
    case GT_OPCODE_INT : {
      DECODE_C();
      SET_LOCAL(x, (int32_t)(LOCAL(y)) > (int32_t)(LOCAL(value)));
      continue;
    }
    case GT_OPCODE_LONG : {
      DECODE_C();
      SET_LOCAL(x, (int64_t)(LOCAL(y)) > (int64_t)(LOCAL(value)));
      continue;
    }
    case GT_OPCODE_FLOAT : {
      DECODE_C();
      SET_LOCAL(x, LOCAL_FLOAT(y) > LOCAL_FLOAT(value));
      continue;
    }
    case GT_OPCODE_DOUBLE : {
      DECODE_C();
      SET_LOCAL(x, LOCAL_DOUBLE(y) > LOCAL_DOUBLE(value));
      continue;
    }
    case LE_OPCODE_INT : {
      DECODE_C();
      SET_LOCAL(x, (int32_t)(LOCAL(y)) <= (int32_t)(LOCAL(value)));
      continue;
    }
    case LE_OPCODE_LONG : {
      DECODE_C();
      SET_LOCAL(x, (int64_t)(LOCAL(y)) <= (int64_t)(LOCAL(value)));
      continue;
    }
    case LE_OPCODE_FLOAT : {
      DECODE_C();
      SET_LOCAL(x, LOCAL_FLOAT(y) <= LOCAL_FLOAT(value));
      continue;
    }
    case LE_OPCODE_DOUBLE : {
      DECODE_C();
      SET_LOCAL(x, LOCAL_DOUBLE(y) <= LOCAL_DOUBLE(value));
      continue;
    }
    case GE_OPCODE_INT : {
      DECODE_C();
      SET_LOCAL(x, (int32_t)(LOCAL(y)) >= (int32_t)(LOCAL(value)));
      continue;
    }
    case GE_OPCODE_LONG : {
      DECODE_C();
      SET_LOCAL(x, (int64_t)(LOCAL(y)) >= (int64_t)(LOCAL(value)));
      continue;
    }
    case GE_OPCODE_FLOAT : {
      DECODE_C();
      SET_LOCAL(x, LOCAL_FLOAT(y) >= LOCAL_FLOAT(value));
      continue;
    }
    case GE_OPCODE_DOUBLE : {
      DECODE_C();
      SET_LOCAL(x, LOCAL_DOUBLE(y) >= LOCAL_DOUBLE(value));
      continue;
    }

    case ULE_OPCODE_BYTE : {
      DECODE_C();
      SET_LOCAL(x, (uint8_t)(LOCAL(y)) <= (uint8_t)(LOCAL(value)));
      continue;
    }
    case ULE_OPCODE_INT : {
      DECODE_C();
      SET_LOCAL(x, (uint32_t)(LOCAL(y)) <= (uint32_t)(LOCAL(value)));
      continue;
    }
    case ULE_OPCODE_LONG : {
      DECODE_C();
      SET_LOCAL(x, (uint64_t)(LOCAL(y)) <= (uint64_t)(LOCAL(value)));
      continue;
    }
    case ULT_OPCODE_BYTE : {
      DECODE_C();
      SET_LOCAL(x, (uint8_t)(LOCAL(y)) < (uint8_t)(LOCAL(value)));
      continue;
    }
    case ULT_OPCODE_INT : {
      DECODE_C();
      SET_LOCAL(x, (uint32_t)(LOCAL(y)) < (uint32_t)(LOCAL(value)));
      continue;
    }
    case ULT_OPCODE_LONG : {
      DECODE_C();
      SET_LOCAL(x, (uint64_t)(LOCAL(y)) < (uint64_t)(LOCAL(value)));
      continue;
    }
    case UGT_OPCODE_BYTE : {
      DECODE_C();
      SET_LOCAL(x, (uint8_t)(LOCAL(y)) > (uint8_t)(LOCAL(value)));
      continue;
    }
    case UGT_OPCODE_INT : {
      DECODE_C();
      SET_LOCAL(x, (uint32_t)(LOCAL(y)) > (uint32_t)(LOCAL(value)));
      continue;
    }
    case UGT_OPCODE_LONG : {
      DECODE_C();
      SET_LOCAL(x, (uint64_t)(LOCAL(y)) > (uint64_t)(LOCAL(value)));
      continue;
    }
    case UGE_OPCODE_BYTE : {
      DECODE_C();
      SET_LOCAL(x, (uint8_t)(LOCAL(y)) >= (uint8_t)(LOCAL(value)));
      continue;
    }
    case UGE_OPCODE_INT : {
      DECODE_C();
      SET_LOCAL(x, (uint32_t)(LOCAL(y)) >= (uint32_t)(LOCAL(value)));
      continue;
    }
    case UGE_OPCODE_LONG : {
      DECODE_C();
      SET_LOCAL(x, (uint64_t)(LOCAL(y)) >= (uint64_t)(LOCAL(value)));
      continue;
    }      
    case INT_NOT_OPCODE : {
      DECODE_B_UNSIGNED();
      uint64_t y = LOCAL(value);
      SET_LOCAL(x, ((~ y) >> 32L) << 32L);
      continue;
    }
    case INT_NEG_OPCODE : {
      DECODE_B_UNSIGNED();
      int64_t y = LOCAL(value);
      SET_LOCAL(x, - y);
      continue;
    }      
    case NOT_OPCODE_BYTE : {
      DECODE_B_UNSIGNED();
      SET_LOCAL(x, ~ ((uint8_t)LOCAL(value)));
      continue;
    }
    case NOT_OPCODE_INT : {
      DECODE_B_UNSIGNED();
      SET_LOCAL(x, ~ ((uint32_t)LOCAL(value)));
      continue;
    }
    case NOT_OPCODE_LONG : {
      DECODE_B_UNSIGNED();
      SET_LOCAL(x, ~ ((uint64_t)LOCAL(value)));
      continue;
    }
    case NEG_OPCODE_INT : {
      DECODE_B_UNSIGNED();
      SET_LOCAL(x, - ((int32_t)LOCAL(value)));
      continue;
    }
    case NEG_OPCODE_LONG : {
      DECODE_B_UNSIGNED();
      SET_LOCAL(x, - ((int64_t)LOCAL(value)));
      continue;
    }
    case NEG_OPCODE_FLOAT : {
      DECODE_B_UNSIGNED();
      SET_LOCAL_FLOAT(x, - LOCAL_FLOAT(value));      
      continue;
    }
    case NEG_OPCODE_DOUBLE : {
      DECODE_B_UNSIGNED();
      SET_LOCAL_DOUBLE(x, - LOCAL_DOUBLE(value));      
      continue;
    }
    case DEREF_OPCODE : {
      DECODE_B_UNSIGNED();
      SET_LOCAL(x, LOCAL(value) + 8 - REF_TAG_BITS);
      continue;
    }
    case TYPEOF_OPCODE : {
      DECODE_C();
      int format = value;
      int index = dispatch_branch(vms, format);
      SET_LOCAL(x, index);
      continue;
    }
    case JUMP_SET_OPCODE : {
      DECODE_F();
      if(LOCAL(x)){
        pc = pc0 + (n1 * 4);
        continue;
      }
      else{
        pc = pc0 + (n2 * 4);
        continue;
      }
    }
    case GOTO_OPCODE : {
      DECODE_A_SIGNED();
      pc = pc0 + (value * 4);
      continue;
    }
    case CONV_OPCODE_BYTE_FLOAT : {
      DECODE_B_UNSIGNED();
      SET_LOCAL(x, (uint8_t)(LOCAL_FLOAT(value)));
      continue;
    }
    case CONV_OPCODE_BYTE_DOUBLE : {
      DECODE_B_UNSIGNED();
      SET_LOCAL(x, (uint8_t)(LOCAL_DOUBLE(value)));
      continue;
    }
    case CONV_OPCODE_INT_BYTE : {
      DECODE_B_UNSIGNED();
      SET_LOCAL(x, (int32_t)(uint8_t)(LOCAL(value)));
      continue;
    }
    case CONV_OPCODE_INT_FLOAT : {
      DECODE_B_UNSIGNED();
      SET_LOCAL(x, (int32_t)(LOCAL_FLOAT(value)));
      continue;
    }
    case CONV_OPCODE_INT_DOUBLE : {
      DECODE_B_UNSIGNED();
      SET_LOCAL(x, (int32_t)(LOCAL_DOUBLE(value)));
      continue;
    }
    case CONV_OPCODE_LONG_BYTE : {
      DECODE_B_UNSIGNED();
      SET_LOCAL(x, (int64_t)(uint8_t)(LOCAL(value)));
      continue;
    }
    case CONV_OPCODE_LONG_INT : {
      DECODE_B_UNSIGNED();
      SET_LOCAL(x, (int64_t)(int32_t)(LOCAL(value)));
      continue;
    }
    case CONV_OPCODE_LONG_FLOAT : {
      DECODE_B_UNSIGNED();
      SET_LOCAL(x, (int64_t)(LOCAL_FLOAT(value)));
      continue;
    }
    case CONV_OPCODE_LONG_DOUBLE : {
      DECODE_B_UNSIGNED();
      SET_LOCAL(x, (int64_t)(LOCAL_DOUBLE(value)));
      continue;
    }
    case CONV_OPCODE_FLOAT_BYTE : {
      DECODE_B_UNSIGNED();
      SET_LOCAL_FLOAT(x, (uint8_t)(LOCAL(value)));
      continue;
    }
    case CONV_OPCODE_FLOAT_INT : {
      DECODE_B_UNSIGNED();
      SET_LOCAL_FLOAT(x, (int32_t)(LOCAL(value)));
      continue;
    }
    case CONV_OPCODE_FLOAT_LONG : {
      DECODE_B_UNSIGNED();
      SET_LOCAL_FLOAT(x, (int64_t)(LOCAL(value)));
      continue;
    }
    case CONV_OPCODE_FLOAT_DOUBLE : {
      DECODE_B_UNSIGNED();
      SET_LOCAL_FLOAT(x, LOCAL_DOUBLE(value));
      continue;
    }
    case CONV_OPCODE_DOUBLE_BYTE : {
      DECODE_B_UNSIGNED();
      SET_LOCAL_DOUBLE(x, (uint8_t)(LOCAL(value)));
      continue;
    }
    case CONV_OPCODE_DOUBLE_INT : {
      DECODE_B_UNSIGNED();
      SET_LOCAL_DOUBLE(x, (int32_t)(LOCAL(value)));
      continue;
    }
    case CONV_OPCODE_DOUBLE_LONG : {
      DECODE_B_UNSIGNED();
      SET_LOCAL_DOUBLE(x, (int64_t)(LOCAL(value)));
      continue;
    }
    case CONV_OPCODE_DOUBLE_FLOAT : {
      DECODE_B_UNSIGNED();
      SET_LOCAL_DOUBLE(x, LOCAL_FLOAT(value));
      continue;
    }
    case DETAG_OPCODE : {
      DECODE_B_UNSIGNED();
      SET_LOCAL(x, LOCAL(value) >> 32L);
      continue;
    }
    case TAG_OPCODE_BYTE : {
      DECODE_B_UNSIGNED();
      SET_LOCAL(x, ((uint64_t)(uint8_t)(LOCAL(value)) << 32L) + BYTE_TAG_BITS);
      continue;
    }
    case TAG_OPCODE_CHAR : {
      DECODE_B_UNSIGNED();
      SET_LOCAL(x, ((uint64_t)(uint8_t)(LOCAL(value)) << 32L) + CHAR_TAG_BITS);
      continue;
    }
    case TAG_OPCODE_INT : {
      DECODE_B_UNSIGNED();
      SET_LOCAL(x, ((uint64_t)LOCAL(value) << 32L) + INT_TAG_BITS);
      continue;
    }
    case TAG_OPCODE_FLOAT : {
      DECODE_B_UNSIGNED();
      SET_LOCAL(x, ((uint64_t)LOCAL(value) << 32L) + FLOAT_TAG_BITS);
      continue;
    }
    case STORE_OPCODE_1 : {
      DECODE_E();
      char* address = (char*)(LOCAL(x) + value);
      char storeval = (char)(LOCAL(z));
      *address = storeval;
      continue;
    }
    case STORE_OPCODE_4 : {
      DECODE_E();
      int32_t* address = (int32_t*)(LOCAL(x) + value);
      int32_t storeval = (int32_t)(LOCAL(z));
      *address = storeval;     
      continue;
    }
    case STORE_OPCODE_8 : {
      DECODE_E();
      int64_t* address = (int64_t*)(LOCAL(x) + value);
      int64_t storeval = (int64_t)(LOCAL(z));
      *address = storeval;     
      continue;
    }
    case STORE_OPCODE_1_VAR_OFFSET : {
      DECODE_E();
      char* address = (char*)(LOCAL(x) + LOCAL(y) + value);
      char storeval = (char)(LOCAL(z));
      *address = storeval;
      continue;
    }
    case STORE_OPCODE_4_VAR_OFFSET : {
      DECODE_E();
      int32_t* address = (int32_t*)(LOCAL(x) + LOCAL(y) + value);
      int32_t storeval = (int32_t)(LOCAL(z));
      *address = storeval;
      continue;
    }
    case STORE_OPCODE_8_VAR_OFFSET : {
      DECODE_E();
      int64_t* address = (int64_t*)(LOCAL(x) + LOCAL(y) + value);
      int64_t storeval = (int64_t)(LOCAL(z));
      *address = storeval;     
      continue;
    }
    case LOAD_OPCODE_1 : {
      DECODE_E();
      char* address = (char*)(LOCAL(y) + value);
      SET_LOCAL(x, *address);
      continue;
    }
    case LOAD_OPCODE_4 : {
      DECODE_E();
      int32_t* address = (int32_t*)(LOCAL(y) + value);
      SET_LOCAL(x, *address);
      continue;
    }
    case LOAD_OPCODE_8 : {
      DECODE_E();
      int64_t* address = (int64_t*)(LOCAL(y) + value);
      SET_LOCAL(x, *address);
      continue;
    }
    case LOAD_OPCODE_1_VAR_OFFSET : {
      DECODE_E();
      char* address = (char*)(LOCAL(y) + LOCAL(z) + value);
      SET_LOCAL(x, *address);
      continue;
    }
    case LOAD_OPCODE_4_VAR_OFFSET : {
      DECODE_E();
      int32_t* address = (int32_t*)(LOCAL(y) + LOCAL(z) + value);
      SET_LOCAL(x, *address);
      continue;
    }
    case LOAD_OPCODE_8_VAR_OFFSET : {
      DECODE_E();
      int64_t* address = (int64_t*)(LOCAL(y) + LOCAL(z) + value);
      SET_LOCAL(x, *address);
      continue;
    }
    case RESERVE_OPCODE_LOCAL : {
      DECODE_C();
      uint64_t size = 8 + LOCAL(value);
      size = (size + 7) & -8;
      int num_locals = y;
      int offset = x * 4;
      if(heap_top + size <= heap_limit){
        pc = pc0 + offset;
        continue;
      }else{
        SET_REG(0, BOOLREF(0));
        SET_REG(1, 1L);
        SET_REG(2, size);
        uint64_t fpos = (uint64_t)(code_offsets[vms->extend_heap_id]) * 4;
        PUSH_FRAME(num_locals);
        pc = instructions + fpos;
        continue;
      }
    }
    case RESERVE_OPCODE_CONST : {
      DECODE_C();
      uint64_t size = value;
      int num_locals = y;
      int offset = x * 4;
      if(heap_top + size <= heap_limit){
        pc = pc0 + offset;
        continue;
      }else{
        SET_REG(0, BOOLREF(0));
        SET_REG(1, 1L);
        SET_REG(2, size);
        uint64_t fpos = (uint64_t)(code_offsets[vms->extend_heap_id]) * 4;
        PUSH_FRAME(num_locals);
        pc = instructions + fpos;
        continue;
      }
    }
    case ALLOC_OPCODE_CONST : {
      DECODE_C();
      int num_bytes = 8 + y;
      int type = value;
      *(uint64_t*)heap_top = type;
      uint64_t obj = ptr_to_ref(heap_top);
      SET_LOCAL(x, obj);
      heap_top = heap_top + num_bytes;
      continue;
    }
    case ALLOC_OPCODE_LOCAL : {
      DECODE_C();
      uint64_t num_bytes = 8 + LOCAL(y);
      num_bytes = (num_bytes + 7) & -8;
      int type = value;
      *(uint64_t*)heap_top = type;
      uint64_t obj = ptr_to_ref(heap_top);
      SET_LOCAL(x, obj);
      heap_top = heap_top + num_bytes;
      continue;
    }
    case GC_OPCODE : {
      DECODE_B_UNSIGNED();
      //Size to extend
      uint64_t size = LOCAL(value);
      //Call GC
      SAVE_STATE();
      int64_t remaining = call_garbage_collector(vms, size);
      RESTORE_STATE();
      //Return heap remaining
      SET_LOCAL(x, remaining);
      continue;
    }
    case CLASS_NAME_OPCODE : {
      DECODE_B_UNSIGNED();
      long id = (long)LOCAL(value);
      char* name = retrieve_class_name(vms, id);
      SET_LOCAL(x, (uint64_t)name);
      continue;
    }
    case PRINT_STACK_TRACE_OPCODE : {
      DECODE_B_UNSIGNED();
      uint64_t stack = LOCAL(value);
      call_print_stack_trace(vms, stack);
      SET_REG(x, 0);
      continue;
    }
    case FLUSH_VM_OPCODE : {
      DECODE_A_UNSIGNED();
      SAVE_STATE();
      SET_LOCAL(value, (uint64_t)vms);
      continue;
    }
    case JUMP_INT_LT_OPCODE : {
      DECODE_F();
      F_JUMP((int64_t)LOCAL(x) < (int64_t)LOCAL(y));
    }
    case JUMP_INT_GT_OPCODE : {
      DECODE_F();
      F_JUMP((int64_t)LOCAL(x) > (int64_t)LOCAL(y));
    }
    case JUMP_INT_LE_OPCODE : {
      DECODE_F();
      F_JUMP((int64_t)LOCAL(x) <= (int64_t)LOCAL(y));
    }
    case JUMP_INT_GE_OPCODE : {
      DECODE_F();
      F_JUMP((int64_t)LOCAL(x) >= (int64_t)LOCAL(y));
    }      
    case JUMP_EQ_OPCODE_REF : {
      DECODE_F();      
      F_JUMP(LOCAL(x) == LOCAL(y));
    }
    case JUMP_EQ_OPCODE_BYTE : {
      DECODE_F();
      F_JUMP((int8_t)LOCAL(x) == (int8_t)LOCAL(y));
    }
    case JUMP_EQ_OPCODE_INT : {
      DECODE_F();
      F_JUMP((int32_t)LOCAL(x) == (int32_t)LOCAL(y));
    }
    case JUMP_EQ_OPCODE_LONG : {
      DECODE_F();
      F_JUMP((int64_t)LOCAL(x) == (int64_t)LOCAL(y));
    }
    case JUMP_EQ_OPCODE_FLOAT : {
      DECODE_F();
      F_JUMP(LOCAL_FLOAT(x) == LOCAL_FLOAT(y));
    }
    case JUMP_EQ_OPCODE_DOUBLE : {
      DECODE_F();
      F_JUMP(LOCAL_DOUBLE(x) == LOCAL_DOUBLE(y));
    }      
    case JUMP_NE_OPCODE_REF : {
      DECODE_F();      
      F_JUMP(LOCAL(x) != LOCAL(y));
    }
    case JUMP_NE_OPCODE_BYTE : {
      DECODE_F();
      F_JUMP((int8_t)LOCAL(x) != (int8_t)LOCAL(y));
    }
    case JUMP_NE_OPCODE_INT : {
      DECODE_F();
      F_JUMP((int32_t)LOCAL(x) != (int32_t)LOCAL(y));
    }
    case JUMP_NE_OPCODE_LONG : {
      DECODE_F();
      F_JUMP((int64_t)LOCAL(x) != (int64_t)LOCAL(y));
    }
    case JUMP_NE_OPCODE_FLOAT : {
      DECODE_F();
      F_JUMP(LOCAL_FLOAT(x) != LOCAL_FLOAT(y));
    }
    case JUMP_NE_OPCODE_DOUBLE : {
      DECODE_F();
      F_JUMP(LOCAL_DOUBLE(x) != LOCAL_DOUBLE(y));
    }      
    case JUMP_LT_OPCODE_INT : {
      DECODE_F();
      F_JUMP((int32_t)LOCAL(x) < (int32_t)LOCAL(y));
    }
    case JUMP_LT_OPCODE_LONG : {
      DECODE_F();
      F_JUMP((int64_t)LOCAL(x) < (int64_t)LOCAL(y));
    }
    case JUMP_LT_OPCODE_FLOAT : {
      DECODE_F();
      F_JUMP(LOCAL_FLOAT(x) < LOCAL_FLOAT(y));
    }
    case JUMP_LT_OPCODE_DOUBLE : {
      DECODE_F();
      F_JUMP(LOCAL_DOUBLE(x) < LOCAL_DOUBLE(y));
    }
    case JUMP_GT_OPCODE_INT : {
      DECODE_F();
      F_JUMP((int32_t)LOCAL(x) > (int32_t)LOCAL(y));
    }
    case JUMP_GT_OPCODE_LONG : {
      DECODE_F();
      F_JUMP((int64_t)LOCAL(x) > (int64_t)LOCAL(y));
    }
    case JUMP_GT_OPCODE_FLOAT : {
      DECODE_F();
      F_JUMP(LOCAL_FLOAT(x) > LOCAL_FLOAT(y));
    }
    case JUMP_GT_OPCODE_DOUBLE : {
      DECODE_F();
      F_JUMP(LOCAL_DOUBLE(x) > LOCAL_DOUBLE(y));
    }
    case JUMP_LE_OPCODE_INT : {
      DECODE_F();
      F_JUMP((int32_t)LOCAL(x) <= (int32_t)LOCAL(y));
    }
    case JUMP_LE_OPCODE_LONG : {
      DECODE_F();
      F_JUMP((int64_t)LOCAL(x) <= (int64_t)LOCAL(y));
    }
    case JUMP_LE_OPCODE_FLOAT : {
      DECODE_F();
      F_JUMP(LOCAL_FLOAT(x) <= LOCAL_FLOAT(y));
    }
    case JUMP_LE_OPCODE_DOUBLE : {
      DECODE_F();
      F_JUMP(LOCAL_DOUBLE(x) <= LOCAL_DOUBLE(y));
    }
    case JUMP_GE_OPCODE_INT : {
      DECODE_F();
      F_JUMP((int32_t)LOCAL(x) >= (int32_t)LOCAL(y));
    }
    case JUMP_GE_OPCODE_LONG : {
      DECODE_F();
      F_JUMP((int64_t)LOCAL(x) >= (int64_t)LOCAL(y));
    }
    case JUMP_GE_OPCODE_FLOAT : {
      DECODE_F();
      F_JUMP(LOCAL_FLOAT(x) >= LOCAL_FLOAT(y));
    }
    case JUMP_GE_OPCODE_DOUBLE : {
      DECODE_F();
      F_JUMP(LOCAL_DOUBLE(x) >= LOCAL_DOUBLE(y));
    }
    case JUMP_ULE_OPCODE_BYTE : {
      DECODE_F();
      F_JUMP((uint8_t)LOCAL(x) <= (uint8_t)LOCAL(y));
    }
    case JUMP_ULE_OPCODE_INT : {
      DECODE_F();
      F_JUMP((uint32_t)LOCAL(x) <= (uint32_t)LOCAL(y));
    }
    case JUMP_ULE_OPCODE_LONG : {
      DECODE_F();
      F_JUMP((uint64_t)LOCAL(x) <= (uint64_t)LOCAL(y));
    }      
    case JUMP_ULT_OPCODE_BYTE : {
      DECODE_F();
      F_JUMP((uint8_t)LOCAL(x) < (uint8_t)LOCAL(y));
    }
    case JUMP_ULT_OPCODE_INT : {
      DECODE_F();
      F_JUMP((uint32_t)LOCAL(x) < (uint32_t)LOCAL(y));
    }
    case JUMP_ULT_OPCODE_LONG : {
      DECODE_F();
      F_JUMP((uint64_t)LOCAL(x) < (uint64_t)LOCAL(y));
    }      
    case JUMP_UGE_OPCODE_BYTE : {
      DECODE_F();
      F_JUMP((uint8_t)LOCAL(x) >= (uint8_t)LOCAL(y));
    }
    case JUMP_UGE_OPCODE_INT : {
      DECODE_F();
      F_JUMP((uint32_t)LOCAL(x) >= (uint32_t)LOCAL(y));
    }
    case JUMP_UGE_OPCODE_LONG : {
      DECODE_F();
      F_JUMP((uint64_t)LOCAL(x) >= (uint64_t)LOCAL(y));
    }
    case JUMP_UGT_OPCODE_BYTE : {
      DECODE_F();
      F_JUMP((uint8_t)LOCAL(x) > (uint8_t)LOCAL(y));
    }
    case JUMP_UGT_OPCODE_INT : {
      DECODE_F();
      F_JUMP((uint32_t)LOCAL(x) > (uint32_t)LOCAL(y));
    }
    case JUMP_UGT_OPCODE_LONG : {
      DECODE_F();
      F_JUMP((uint64_t)LOCAL(x) > (uint64_t)LOCAL(y));
    }
    case DISPATCH_OPCODE : {
      DECODE_A_UNSIGNED();
      uint32_t* tgts = (uint32_t*)(pc + 4);
      //DECODE_TGTS();
      int format = value;
      int index = dispatch_branch(vms, format);
      int tgt = tgts[index];
      pc = pc0 + (tgt * 4);
      continue;
    }
    case DISPATCH_METHOD_OPCODE : {
      DECODE_A_UNSIGNED();
      uint32_t* tgts = (uint32_t*)(pc + 4);
      //DECODE_TGTS();
      int format = value;
      int index = dispatch_branch(vms, format);
      if(index < 2){
        int tgt = tgts[index];
        pc = pc0 + (tgt * 4);
        continue;
      }else{
        int fid = index - 2;
        uint64_t fpos = (uint64_t)(code_offsets[fid]) * 4;
        pc = instructions + fpos;
        continue;
      }
    }
    case JUMP_REG_OPCODE : {
      DECODE_C();
      int reg = x;
      uint64_t arity = y;
      int offset = value * 4;
      if(registers[reg] == arity){
        pc = pc0 + offset;
        continue;
      }else{
        continue;
      }
    }
    case FNENTRY_OPCODE : {
      DECODE_A_UNSIGNED();
      int frame_size = value * 8 + sizeof(StackFrame);
      int size_required = frame_size + sizeof(StackFrame);
      if((char*)stack_pointer + size_required > stack_limit){
        //Save current stack
        stk->stack_pointer = stack_pointer;
        stk->pc = pc - instructions;
        //Swap stack and registers
        vms->current_stack = vms->system_stack;
        vms->system_stack = current_stack;
        vms->registers = vms->system_registers;
        vms->system_registers = registers;
        //Restore stack state
        current_stack = vms->current_stack;
        stk = untag_stack(current_stack);
        stack_pointer = stk->stack_pointer;
        stack_limit = (char*)(stk->frames) + stk->size;
        registers = vms->registers;
        //Set arguments        
        SET_REG(0, BOOLREF(0));
        SET_REG(1, 1L);
        SET_REG(2, size_required);
        stack_pointer = stk->frames;
        stack_pointer->returnpc = SYSTEM_RETURN_STUB;
        //Jump to stack extender          
        uint64_t fpos = (uint64_t)(code_offsets[vms->extend_stack_id]) * 4;
        pc = instructions + fpos;
        continue;        
      }
      continue;
    }
    }

    //Done    
    printf("Invalid opcode: %d\n", opcode);
    exit(-1);
  }
}
