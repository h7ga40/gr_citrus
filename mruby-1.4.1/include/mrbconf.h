/*
** mrbconf.h - mruby core configuration
**
** See Copyright Notice in mruby.h
*/

#ifndef MRUBYCONF_H
#define MRUBYCONF_H

#include <limits.h>
#include <stdint.h>

/* architecture selection: */
/* specify -DMRB_32BIT or -DMRB_64BIT to override */
#if !defined(MRB_32BIT) && !defined(MRB_64BIT)
#if UINT64_MAX == SIZE_MAX
#define MRB_64BIT
#else
#define MRB_32BIT
#endif
#endif

#if defined(MRB_32BIT) && defined(MRB_64BIT)
#error Cannot build for 32 and 64 bit architecture at the same time
#endif

/* configuration options: */
/* add -DMRB_USE_FLOAT to use float instead of double for floating point numbers */
//#define MRB_USE_FLOAT

/* exclude floating point numbers */
//#define MRB_WITHOUT_FLOAT

/* add -DMRB_METHOD_CACHE to use method cache to improve performance */
//#define MRB_METHOD_CACHE
/* size of the method cache (need to be the power of 2) */
//#define MRB_METHOD_CACHE_SIZE (1<<7)

/* add -DMRB_METHOD_TABLE_INLINE to reduce the size of method table */
/* MRB_METHOD_TABLE_INLINE requires LSB of function pointers to be zero */
/* you might need to specify --falign-functions=n (where n>1) */
//#define MRB_METHOD_TABLE_INLINE

/* add -DMRB_INT16 to use 16bit integer for mrb_int; conflict with MRB_INT64 */
//#define MRB_INT16

/* add -DMRB_INT64 to use 64bit integer for mrb_int; conflict with MRB_INT16 */
//#define MRB_INT64

/* if no specific integer type is chosen */
#if !defined(MRB_INT16) && !defined(MRB_INT32) && !defined(MRB_INT64)
# if defined(MRB_64BIT) && !defined(MRB_NAN_BOXING)
/* Use 64bit integers on 64bit architecture (without MRB_NAN_BOXING) */
#  define MRB_INT64
# else
/* Otherwise use 32bit integers */
#  define MRB_INT32
# endif
#endif

/* represent mrb_value in boxed double; conflict with MRB_USE_FLOAT and MRB_WITHOUT_FLOAT */
//#define MRB_NAN_BOXING

/* define on big endian machines; used by MRB_NAN_BOXING */
//#define MRB_ENDIAN_BIG

/* represent mrb_value as a word (natural unit of data for the processor) */
//#define MRB_WORD_BOXING

/* string class to handle UTF-8 encoding */
#define MRB_UTF8_STRING

/* argv max size in mrb_funcall */
//#define MRB_FUNCALL_ARGC_MAX 16
#define MRB_FUNCALL_ARGC_MAX 8

/* number of object per heap page */
//#define MRB_HEAP_PAGE_SIZE 1024
#define MRB_HEAP_PAGE_SIZE 24

/* if _etext and _edata available, mruby can reduce memory used by symbols */
//#define MRB_USE_ETEXT_EDATA

/* do not use __init_array_start to determine readonly data section;
   effective only when MRB_USE_ETEXT_EDATA is defined */
//#define MRB_NO_INIT_ARRAY_START

/* turn off generational GC by default */
//#define MRB_GC_TURN_OFF_GENERATIONAL

/* default size of khash table bucket */
//#define KHASH_DEFAULT_SIZE 32
#define KHASH_DEFAULT_SIZE 8

/* allocated memory address alignment */
//#define POOL_ALIGNMENT 4

/* page size of memory pool */
//#define POOL_PAGE_SIZE 16000
#define POOL_PAGE_SIZE 256

/* initial minimum size for string buffer */
//#define MRB_STR_BUF_MIN_SIZE 128
#define MRB_STR_BUF_MIN_SIZE 20

/* arena size */
//#define MRB_GC_ARENA_SIZE 100

/* fixed size GC arena */
//#define MRB_GC_FIXED_ARENA
#define MRB_GC_FIXED_ARENA

/* state atexit stack size */
//#define MRB_FIXED_STATE_ATEXIT_STACK_SIZE 5

/* fixed size state atexit stack */
//#define MRB_FIXED_STATE_ATEXIT_STACK

/* -DMRB_DISABLE_XXXX to drop following features */
//#define MRB_DISABLE_STDIO	/* use of stdio */

/* -DMRB_ENABLE_XXXX to enable following features */
//#define MRB_ENABLE_DEBUG_HOOK	/* hooks for debugger */

/* end of configuration */

/* define MRB_DISABLE_XXXX from DISABLE_XXX (for compatibility) */
#ifdef DISABLE_STDIO
#define MRB_DISABLE_STDIO
#endif

/* define MRB_ENABLE_XXXX from ENABLE_XXX (for compatibility) */
#ifdef ENABLE_DEBUG
#define MRB_ENABLE_DEBUG_HOOK
#endif

#ifndef MRB_DISABLE_STDIO
# include <stdio.h>
#endif

#ifndef FALSE
# define FALSE 0
#endif

#ifndef TRUE
# define TRUE 1
#endif

#ifdef MRB_ENABLE_DEBUG_HOOK
#include <stdlib.h>

void clearerr_rd(FILE* stream);
int feof_rd(FILE* stream);
int fflush_rd(FILE* stream);
int getc_rd(FILE* stream);
size_t fread_rd(void *buffer, size_t size, size_t count, FILE *stream);
int putc_rd(int character, FILE* stream);
int fputs_rd(char const* buffer, FILE* stream);
int fprintf_rd(FILE* const stream, char const* const format, ...);
size_t fwrite_rd(void const* buffer, size_t elementSize, size_t elementCount, FILE* stream);
void abort_rd(void);

#define clearerr clearerr_rd
#define feof feof_rd
#define fflush fflush_rd
#define getc getc_rd
#define fgetc getc_rd
#define fread fread_rd
#define putc putc_rd
#define fputc putc_rd
#define fputs fputs_rd
#define puts(...) fputs_rd(__VA_ARGS__, stdout)
#define fprintf fprintf_rd
#define printf(...) fprintf_rd(stdout, __VA_ARGS__)
#define fwrite fwrite_rd
#define abort abort_rd
#endif

#endif  /* MRUBYCONF_H */
