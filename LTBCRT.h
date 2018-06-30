#pragma once

#define LTB_CRT

/*
A companion piece to LTB.h, containing some common CRT functions.
*/

typedef unsigned long long size_t;

#ifdef __cplusplus
extern "C" {
#endif

void* memcpy(void* Destination, void const* Source, size_t Size);

void* memset(void* Destination, int Value, size_t Count);

void* memmove(void* Destination, const void* Source, size_t Count);

void* malloc(size_t size);

void* realloc(void* memblock, size_t size);

void* calloc(size_t num, size_t size);

void *_alloca(size_t size);
#ifndef alloca
#define alloca(n) _alloca(n)
#endif

void free(void* memblock);

int printf(const char* format, ...);

int getchar(void);

int rand_s(unsigned int* randomValue);



//int wprintf(const wchar_t *format, ...);


#ifdef __cplusplus
}
#endif



// C++ wrappers
#ifdef LTBCRT_Extra
	#ifdef __cplusplus
	
	namespace LTB {
		template <typename T>
		void MemSet(T* Destination, int Value, size_t Count) {
			memset(Destination, Value, Count*sizeof(T));
		}


		template <typename T>
		void MemMove(T* Destination, T* Source, size_t Count) {
			memmove(Destination, Source, Count*sizeof(T));
		}


		template <typename T>
		T* Malloc(size_t Count) {
			return (T*) malloc(Count*sizeof(T));
		}

	}

	#endif
#endif