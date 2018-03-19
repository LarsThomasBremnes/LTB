
#pragma once

#define LTBInternal(n) __L_T_B_INTERNAL_##n

#define Internal_i64 __int64
#define Internal_u64 unsigned __int64
#define Internal_i32 int
#define Internal_u32 unsigned int
#define Internal_i16 short
#define Internal_u16 unsigned short
#define Internal_i8	 char
#define Internal_u8  unsigned char
#define Internal_f32 float
#define Internal_f64 double

#if defined LTB_Windows

#define LTBAlloc(size) VirtualAlloc(0, (size), MEM_COMMIT, PAGE_READWRITE)

#endif

#ifdef LTB_Prefix
	#define PW(name) LTB_##name
	#define LTB_Mod2(i) ((i) & 1) 

#else 
	// Prefix With
	#define PW(name) name
	#define Mod2(N, SomeNumberThatIsAPowerOfTwoLike2or4or8AndSoOn) ((i) & (SomeNumberThatIsAPowerOfTwoLike2or4or8AndSoOn - 1)) 
#endif

enum {
	LTBInternal(MaxU64) = (0xFFFFFFFFFFFFFFFFULL),
	LTBInternal(MaxU32) = (0xFFFFFFFFUL),
	LTBInternal(MaxU16) = (0xFFFFU),
	LTBInternal(MaxU8)  = (0xFFU)
};


#ifdef LTB_Prefix
	#define LTB_Abs(i)	((i) < 0 ? -(i) : (i))
#else 
	#define Abs(i)		((i) < 0 ? -(i) : (i))
#endif

#if (defined LTB_Types) || (defined LTB_Everything)

	typedef		unsigned	char			PW(u8);
	typedef		signed		char			PW(i8);
	typedef		unsigned	short			PW(u16);
	typedef		signed		short			PW(i16);
	typedef		unsigned	int				PW(u32);
	typedef		signed		int				PW(i32);
	typedef		unsigned	long long		PW(u64);
	typedef		signed		long long		PW(i64);
	typedef					float			PW(f32);
	typedef					double			PW(f64);

	// Vector types
	struct PW(v2i) {
		PW(i64) x;
		PW(i64) y;
	}; typedef struct PW(v2i) PW(v2i);

	struct PW(v3i) {
		PW(i64) x;
		PW(i64) y;
		PW(i64) z;
	}; typedef struct PW(v3i) PW(v3i);

	struct PW(v4i) {
		PW(i64) x;
		PW(i64) y;
		PW(i64) z;
		PW(i64) w;
	}; typedef struct PW(v4i) PW(v4i);

	struct PW(v2u) {
		PW(u64) x;
		PW(u64) y;
	}; typedef struct PW(v2u) PW(v2u);
	
	struct PW(v3u) {
		PW(u64) x;
		PW(u64) y;
		PW(u64) z;
	}; typedef struct PW(v3u) PW(v3u);

	struct PW(v4u) {
		PW(u64) x;
		PW(u64) y;
		PW(u64) z;
		PW(u64) w;
	}; typedef struct PW(v4u) PW(v4u);

	struct PW(v2f64) {
		PW(f64) x;
		PW(f64) y;
	}; typedef struct PW(v2f64) PW(v2f64);

	struct PW(v3f64) {
		PW(f64) x;
		PW(f64) y;
		PW(f64) z;
	}; typedef struct PW(v3f64) PW(v3f64);

	struct PW(v4f64) {
		PW(f64) x;
		PW(f64) y;
		PW(f64) z;
		PW(f64) w;
	}; typedef struct PW(v4f64) PW(v4f64);

	struct PW(v2f32) {
		PW(f32) x;
		PW(f32) y;
	}; typedef struct PW(v2f32) PW(v2f32);

	struct PW(v3f32) {
		PW(f32) x;
		PW(f32) y;
		PW(f32) z;
	}; typedef struct PW(v3f32) PW(v3f32);

	struct PW(v4f32) {
		PW(f32) x;
		PW(f32) y;
		PW(f32) z;
		PW(f32) w;
	}; typedef struct PW(v4f32) PW(v4f32);

	#if (defined LTB_Prefix)
		#define LTB_v2i_size	sizeof(LTB_v2i)
		#define LTB_v3i_size	sizeof(LTB_v3i)
		#define LTB_v4i_size	sizeof(LTB_v4i)
		#define LTB_v2u_size	sizeof(LTB_v2u)
		#define LTB_v3u_size	sizeof(LTB_v3u)
		#define LTB_v4u_size	sizeof(LTB_v4u)
		#define LTB_v2d_size	sizeof(LTB_v2d)
		#define LTB_v3d_size	sizeof(LTB_v3d)
		#define LTB_v4d_size	sizeof(LTB_v4d)
		#define LTB_v2s_size	sizeof(LTB_v2s)
		#define LTB_v3s_size	sizeof(LTB_v3s)
		#define LTB_v4s_size	sizeof(LTB_v4s)
	#else
		#define v2i_size	sizeof(v2i)
		#define v3i_size	sizeof(v3i)
		#define v4i_size	sizeof(v4i)
		#define v2u_size	sizeof(v2u)
		#define v3u_size	sizeof(v3u)
		#define v4u_size	sizeof(v4u)
		#define v2d_size	sizeof(v2f64)
		#define v3d_size	sizeof(v3f64)
		#define v4d_size	sizeof(v4f64)
		#define v2s_size	sizeof(v2f32)
		#define v3s_size	sizeof(v3f32)
		#define v4s_size	sizeof(v4f32)
	#endif

	#define VectorOperationTemplate_AddTo(V2, V3, V4, Operand) \
		PW(V2) PW(AddTo_##V2)(PW(V2) a, PW(Operand) b) {\
			PW(V2) R = {a.x + b, a.y + b};\
			return R;\
		} PW(V3) PW(AddTo_##V3)(PW(V3) a, PW(Operand) b) {\
			PW(V3) R = {a.x + b, a.y + b, a.z + b};\
			return R;\
		} PW(V4) PW(AddTo_##V4)(PW(V4) a, PW(Operand) b) {\
			PW(V4) R = {a.x + b, a.y + b, a.z + b, a.w + b};\
			return R;\
		}

	VectorOperationTemplate_AddTo(v2i, v3i, v4i, i64);
	VectorOperationTemplate_AddTo(v2u, v3u, v4u, u64);
	VectorOperationTemplate_AddTo(v2f64, v3f64, v4f64, f64);
	VectorOperationTemplate_AddTo(v2f32, v3f32, v4f32, f32);
	#undef VectorOperationTemplate_AddTo


	#define VectorOperationTemplate_Add(V2, V3, V4) \
		PW(V2) PW(Add_##V2)(PW(V2) a, PW(V2) b) {\
			PW(V2) R = { a.x + b.x, a.y + b.y};\
			return R; \
		} PW(V3) PW(Add_##V3)(PW(V3) a, PW(V3) b) {\
			PW(V3) R = { a.x + b.x, a.y + b.y, a.z + b.z};\
			return R;\
		} PW(V4) PW(Add_##V4)(PW(V4) a, PW(V4) b) {\
			PW(V4) R = { a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};\
			return R;\
		}

	VectorOperationTemplate_Add(v2i, v3i, v4i);
	VectorOperationTemplate_Add(v2u, v3u, v4u);
	VectorOperationTemplate_Add(v2f64, v3f64, v4f64);
	VectorOperationTemplate_Add(v2f32, v3f32, v4f32);
	#undef VectorOperationTemplate_Add


	#define VectorOperationTemplate_MulBy(V2, V3, V4, Operand) \
		PW(V2) PW(Mul_##V2##_By)(PW(V2) a, PW(Operand) b) {\
			PW(V2) R = {a.x*b, a.y*b}; return R;\
		} PW(V3) PW(Mul_##V3##_By)(PW(V3) a, PW(Operand) b) {\
			PW(V3) R = {a.x*b, a.y*b, a.z*b}; return R;\
		} PW(V4) PW(Mul_##V4##_By)(PW(V4) a, PW(Operand) b) {\
			PW(V4) R = {a.x*b, a.y*b, a.z*b, a.w*b}; return R;\
		}
	
	VectorOperationTemplate_MulBy(v2i, v3i, v4i, i64);
	VectorOperationTemplate_MulBy(v2u, v3u, v4u, u64);
	VectorOperationTemplate_MulBy(v2f64, v3f64, v4f64, f64);
	VectorOperationTemplate_MulBy(v2f32, v3f32, v4f32, f32);
	#undef VectorOperationTemplate_MulBy

	#define VectorOperationTemplate_Mul(V2, V3, V4) \
		PW(V2) PW(Mul_##V2)(PW(V2) a, PW(V2) b) {\
			PW(V2) R = {a.x*b.x, a.y*b.y}; return R;\
		} PW(V3) PW(Mul_##V3)(PW(V3) a, PW(V3) b) {\
			PW(V3) R = {a.x*b.x, a.y*b.y, a.z*b.z}; return R;\
		} PW(V4) PW(Mul_##V4)(PW(V4) a, PW(V4) b) {\
			PW(V4) R = {a.x*b.x, a.y*b.y, a.z*b.z, a.w*b.w}; return R;\
		}

	VectorOperationTemplate_Mul(v2i, v3i, v4i);
	VectorOperationTemplate_Mul(v2u, v3u, v4u);
	VectorOperationTemplate_Mul(v2f64, v3f64, v4f64);
	VectorOperationTemplate_Mul(v2f32, v3f32, v4f32);
	#undef VectorOperationTemplate_Mul

	#define VectorOperationTemplate_Dot(V2, V3, V4, RetType) \
	PW(RetType) PW(Dot_##V2)(PW(V2) a, PW(V2) b) {\
		return (a.x*b.x + a.y*b.y);\
	} PW(RetType) PW(Dot_##V3)(PW(V3) a, PW(V3) b) {\
		return (a.x*b.x + a.y*b.y + a.z*b.z);\
	} PW(RetType) PW(Dot_##V4)(PW(V4) a, PW(V4) b) {\
		return (a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w);\
	}


	VectorOperationTemplate_Dot(v2i, v3i, v4i, i64);
	VectorOperationTemplate_Dot(v2u, v3u, v4u, u64);
	VectorOperationTemplate_Dot(v2f64, v3f64, v4f64, f64);
	VectorOperationTemplate_Dot(v2f32, v3f32, v4f32, f32);
	#undef VectorOperationTemplate_Dot

	#if (defined LTB_MultivarMacros) || (defined LTB_Everything)

		#define Two_i64(x, y) \
		PW(i64) x; \
		PW(i64) y

		#define Three_i64(x, y, z) \
		PW(i64) x; \
		PW(i64) y; \
		PW(i64) z

		#define Four_i64(x, y, z, w) \
		PW(i64) x; \
		PW(i64) y; \
		PW(i64) z; \
		PW(i64) w

		#define Two_u64(x, y) \
		PW(u64) x; \
		PW(u64) y

		#define Three_u64(x, y, z) \
		PW(u64) x; \
		PW(u64) y; \
		PW(u64) z

		#define Four_u64(x, y, z, w) \
		PW(u64) x; \
		PW(u64) y; \
		PW(u64) z; \
		PW(u64) w

		#define Two_f64(x, y) \
		PW(f64) x; \
		PW(f64) y

		#define Three_f64(x, y, z) \
		PW(f64) x; \
		PW(f64) y; \
		PW(f64) z

		#define Four_f64(x, y, z, w) \
		PW(f64) x; \
		PW(f64) y; \
		PW(f64) z; \
		PW(f64) w

		#define Two_f32(x, y) \
		PW(f32) x; \
		PW(f32) y

		#define Three_f32(x, y, z) \
		PW(f32) x; \
		PW(f32) y; \
		PW(f32) z

		#define Four_f32(x, y, z, w) \
		PW(f32) x; \
		PW(f32) y; \
		PW(f32) z; \
		PW(f32) w

	#endif

#endif


#if (defined LTB_Constants) || (defined LTB_Everything)
	#ifndef __cplusplus
		#ifndef true
			#define true 1ULL
		#endif
		#ifndef false
			#define false 0ULL
		#endif
	#endif


	#define Kilobyte (1ULL << 10)
	#define Megabyte (1ULL << 20)
	#define Gigabyte (1ULL << 30)

	#define PositiveInf32Bit 0x7f800000
	#define NegativeInf32Bit 0xff800000
	#define PositiveInf64Bit 0x7ff0000000000000
	#define NegativeInf64Bit 0xfff0000000000000
	//#define WS_NORMAL 282001408
#endif

#if (defined LTB_Algorithms) || (defined LTB_Everything)
	
	#define XOR(L, R) (!(L) != !(R))
	#define NAND(L, R) !((L) && (R))

	#define Swap(A, B, Temp) \
		(Temp) = (A); \
		(A) = (B); \
		(B) = (Temp);

	int FoldCase(int c) {
		unsigned int x = (unsigned int) c - 'A';
		int d = c + 0x20;
		return (x < 26 ? d : c);
	}

	// Pass the number of elements in the array for 'Size', not the last valid index
	Internal_u64 PW(BinarySearchU64)(Internal_u64* Array, Internal_u64 Size, Internal_u64 Number) {
		Internal_u64 l = Size - 1;
		Internal_u64 i = 0;
		while (Array[i] != Number && Array[l] != Number && l > i) {
			Internal_u64 t = l/2 + i/2;
			if (Array[t] >= Number) {
				l = t;
			} else {
				i = t + 1;
			}
		}
		if (Array[i] == Number) return i;
		else if (Array[l] == Number) return l;
		else return LTBInternal(MaxU64);
	}

	Internal_u64 PW(BinarySearchI64)(Internal_i64* Array, Internal_u64 Size, Internal_i64 Number) {
		Internal_u64 l = Size - 1;
		Internal_u64 i = 0;
		while (Array[i] != Number && Array[l] != Number && l > i) {
			Internal_u64 t = l/2 + i/2;
			if (Array[t] >= Number) {
				l = t;
			} else {
				i = t + 1;
			}
		}
		if (Array[i] == Number) return i;
		else if (Array[l] == Number) return l;
		else return LTBInternal(MaxU64);
	}

	Internal_u64 PW(StablePartition)(Internal_i64* a, Internal_u8* b, Internal_u64 Length) {
		#define RecursionFloor 70
		if (Length > RecursionFloor) {

			Internal_u64 FirstHalf = Length >> 1;
			Internal_u64 SecondHalf = Length - FirstHalf;
			Internal_u64 StartOfFirstPartition = PW(StablePartition)(a, b, FirstHalf);
			Internal_u64 StartOfSecondPartition = PW(StablePartition)(a + FirstHalf, b + FirstHalf, SecondHalf);
			Internal_u64 FirstPartitionLength = FirstHalf - StartOfFirstPartition;

			Internal_i64* Buffer = (Internal_i64*) calloc(StartOfSecondPartition, sizeof(Internal_i64));
			memcpy(Buffer, a + FirstHalf, StartOfSecondPartition*sizeof(Internal_u64));
			memmove(a + FirstHalf + StartOfSecondPartition - FirstPartitionLength, 
					a + StartOfFirstPartition, FirstPartitionLength*sizeof(Internal_u64)
			);
			memmove(a + StartOfFirstPartition, Buffer, StartOfSecondPartition*sizeof(Internal_u64));

			free(Buffer);
			return StartOfFirstPartition + StartOfSecondPartition;
		}
		Internal_i64 Indexes[RecursionFloor] = {0,};
		Internal_u64 k = 0;

		for (Internal_u64 i = 0; i < Length; i++) {
			if (b[i] == 1) {
				Indexes[k++] = i;
			}
		}
		for (Internal_u64 i = 0, j = 0; i < k; i++) {
			Internal_i64 Index = Indexes[j];
			Internal_i64 Temp = a[Index];
			memmove(a + (j + 1), a + j, (Index - j)*sizeof(Internal_i64));
			a[j++] = Temp;
		} 
		return k;
	}




	#ifdef __cplusplus
	template <typename T>
	#else
	#define T Internal_i64
	#endif
	void NthElement(T* A, Internal_u64 Length, Internal_u64 N) {
		N--;
		if (N >= Length) {
			return;
		}
		
		while (1) {
			ReEntry:
			T Element = A[N], Temp;
			Internal_u64 i = N - 1, j = N + 1;

			while (1) {
				while ((i != LTBInternal(MaxU64)) && A[i] < Element) { i--; }
				while ((j != Length    ) && A[j] > Element) { j++; }

				if (i == LTBInternal(MaxU64)) {
					if (j == Length) {
						return;
					} else {
						for (Internal_u64 o = j; o < Length; o++) {
							if (A[o] < A[N]) {
								Swap(A[o], A[N], Temp);
								goto ReEntry;
							}
						}
					}
				} if (j == Length) {
					for (Internal_u64 o = i; o != LTBInternal(MaxU64); o--) {
						if (A[o] > A[N]) {
							Swap(A[o], A[N], Temp);
							goto ReEntry;
						}
					}
				}

				Swap(A[i], A[j], Temp);
			}
		} 
	}
	#undef T



	float rsqrtf32(float number) {
		Internal_u32 i; 
		float x2, y;
		x2 = number * 0.5F;
		y = number; 
		i = *(Internal_u32 *) &y;
		i = 0x5f375a86 - (i >> 1);
		y = *(float *) &i; 
		y = y * (1.5F - (x2 * y * y));
		return y;
	}

	double rsqrtf64(double number) {
		Internal_u64 i; double x2, y;
		x2 = number * 0.5; 
		y = number; 
		i = *(Internal_u64 *) &y;
		i = 0x5fe6eb50c7b537a9 - (i >> 1);
		y = *(double *) &i; 
		y = y * (1.5 - (x2 * y * y));
		return y;
	}


	void PW(ShuffleX64)(Internal_i64* a, Internal_i64 start, Internal_i64 end) {

		#define StepSwapping(StartMod, Step) \
			for (Internal_u64 i = (start + (StartMod)); i < end/2; i += (Step)) { \
				Internal_i64 temp; \
				Swap(a[i], a[end - i - 1], temp); \
			}

		StepSwapping(0, 3);
		StepSwapping(1, 5);
		StepSwapping(2, 7);
		StepSwapping(3, 11);
		StepSwapping(4, 13);
		StepSwapping(5, 17);
		StepSwapping(6, 19);

		for (Internal_i64 i = start; i < end/2; i++) {
			Internal_i64 temp = a[i];
			Internal_i64 half = i + end/2;
			a[i] = a[half];
			a[half] = temp;
			if (i % 2) {
				Internal_i64 third = i + end/3;
				a[half] = a[third];
				a[third] = temp;
			} else {
				Internal_i64 third = i + end/3 + 1;
				temp = a[third];
				a[third] = a[i];
				a[i] = temp;
			}
		}

		#if 1
		Internal_i64 gap = 2;
		Internal_i64 index = 3;
		for (Internal_i64 i = start; i < (end - 5); i++) {
			if (a[i] == (a[i + gap] - gap)) {
				if (i % 2) {
					Internal_i64 temp;
					index += 3;
					if (index == i) index++;
					Swap(a[i], a[index % end], temp);
				} else {
					Internal_i64 temp;
					index += 5;
					if (index == i) index++;
					Swap(a[i], a[index % end], temp);
				}
			}
		}

		gap = 4;
		index = 11;
		for (Internal_i64 i = start; i < (end - 17); i++) {
			if (a[i] == (a[i + gap] - gap)) {
				if (i % 2) {
					Internal_i64 temp;
					index += 13;
					if (index == i) index++;
					Swap(a[i], a[index % end], temp);
				} else {
					Internal_i64 temp;
					index += 17;
					if (index == i) index++;
					Swap(a[i], a[index % end], temp);
				}
			}
		}
		#endif

		#undef StepSwapping
	}

	Internal_i64 PW(IsPowerOfTwo)(Internal_u64 x) {
		return (x != 0) & ((x & (x - 1)) == 0);
	}

	Internal_u64 PW(ExponentiateU64)(Internal_u64 x, Internal_u64 n) {
		Internal_u64 Result = 1;
		while (n) {
			if (n % 2) Result *= x;
			x *= x;
			n >>= 1;
		} return Result;
	}

	#define Bit1  0x1
	#define Bit2  0x2
	#define Bit3  0x4
	#define Bit4  0x8
	#define Bit5  0x10
	#define Bit6  0x20
	#define Bit7  0x40
	#define Bit8  0x80
	#define Bit9  0x100
	#define Bit10 0x200
	#define Bit11 0x400
	#define Bit12 0x800
	#define Bit13 0x1000
	#define Bit14 0x2000
	#define Bit15 0x4000
	#define Bit16 0x8000
	#define Bit17 0x10000
	#define Bit18 0x20000
	#define Bit19 0x40000
	#define Bit20 0x80000
	#define Bit21 0x100000
	#define Bit22 0x200000
	#define Bit23 0x400000
	#define Bit24 0x800000
	#define Bit25 0x1000000
	#define Bit26 0x2000000
	#define Bit27 0x4000000
	#define Bit28 0x8000000
	#define Bit29 0x10000000
	#define Bit30 0x20000000
	#define Bit31 0x40000000
	#define Bit32 0x80000000
	#define Bit33 0x100000000
	#define Bit34 0x200000000
	#define Bit35 0x400000000
	#define Bit36 0x800000000
	#define Bit37 0x1000000000
	#define Bit38 0x2000000000
	#define Bit39 0x4000000000
	#define Bit40 0x8000000000
	#define Bit41 0x10000000000
	#define Bit42 0x20000000000
	#define Bit43 0x40000000000
	#define Bit44 0x80000000000
	#define Bit45 0x100000000000
	#define Bit46 0x200000000000
	#define Bit47 0x400000000000
	#define Bit48 0x800000000000
	#define Bit49 0x1000000000000
	#define Bit50 0x2000000000000
	#define Bit51 0x4000000000000
	#define Bit52 0x8000000000000
	#define Bit53 0x10000000000000
	#define Bit54 0x20000000000000
	#define Bit55 0x40000000000000
	#define Bit56 0x80000000000000
	#define Bit57 0x100000000000000
	#define Bit58 0x200000000000000
	#define Bit59 0x400000000000000
	#define Bit60 0x800000000000000
	#define Bit61 0x1000000000000000
	#define Bit62 0x2000000000000000
	#define Bit63 0x4000000000000000
	#define Bit64 0x8000000000000000

	// Returns the largest bit set to 1, counting the English way rather than the programmer way.
	// That is to say, if you pass 0 you'll get 0 as no bit is set. If you pass 1, you'll get 1 as the
	// 1st bit is set. If you pass (1 << 63) you'll get 64 as the 64th bit is set.
	Internal_u64 PW(Log2U64)(Internal_u64 x) {
		#define FourOfDeez(A, B, C, D) \
			if (x & (1ULL << A)) return (A + 1); \
			if (x & (1ULL << B)) return (B + 1); \
			if (x & (1ULL << C)) return (C + 1); \
			if (x & (1ULL << D)) return (D + 1)
		FourOfDeez(63, 62, 61, 60);
		FourOfDeez(59, 58, 57, 56);
		FourOfDeez(55, 54, 53, 52);
		FourOfDeez(51, 50, 49, 48);
		FourOfDeez(47, 46, 45, 44);
		FourOfDeez(43, 42, 41, 40);
		FourOfDeez(39, 38, 37, 36);
		FourOfDeez(35, 34, 33, 32);
		FourOfDeez(31, 30, 29, 28);
		FourOfDeez(27, 26, 25, 24);
		FourOfDeez(23, 22, 21, 20);
		FourOfDeez(19, 18, 17, 16);
		FourOfDeez(15, 14, 13, 12);
		FourOfDeez(11, 10, 9, 8);
		FourOfDeez(7, 6, 5, 4);
		FourOfDeez(3, 2, 1, 0);
		else return 0;
		#undef FourOfDeez
	}


	
	#if 0
	Internal_u64 PW(Log2U64Precomputed)(Internal_u64 x) {
		if (x & Bit64) return 63;

	}
	#endif
	Internal_u64 PW(SlowLog2U64)(Internal_u64 x) {
		Internal_u64 Log = 0;
		while (x >>= 1) Log++;
		return Log;
	}


	// Greatest common divisor
	Internal_u64 PW(GCD)(Internal_u64 a, Internal_u64 b) {
		Internal_u64 mod = a % b;
		while (mod) {
			a = b;
			b = mod;
			mod = a % b;
		} return b;
	}

	///////// Stringifying an integer /////////

	Internal_u64 PW(U64DigitCount)(Internal_u64 Number) {
		Internal_u64 Digits = 1;
		while (Number /= 10) Digits++;
		return Digits;
	}

	void PW(U64ToString) (Internal_u8* Buffer, Internal_u64 Number) {
		Internal_u64 Digits = PW(U64DigitCount)(Number);
		Internal_u64 i = 0;
		if (Digits == 20) { // If 20 digits, most significant must be 1
			Buffer[i] = '1';
			i++; Digits--;
			Number -= PW(ExponentiateU64)(10, Digits);
		} Internal_u64 a = PW(ExponentiateU64)(10, Digits);
		while (a /= 10) {
			Buffer[i++] = (Internal_u8) ('0' + (Number / a));
			Number -= (Number / a)*a; // subtracts most significant digit
		}
	}

	Internal_u64 PW(StringLength)(Internal_u8* Array) {
		Internal_u64 Result = 0;
		while (*Array++) Result++;
		return Result;
	}


	////////// Arrays //////////

	#define ArrayLength(a) (sizeof((a))/sizeof((a)[0]))

	void PW(ClearArrayU8)(Internal_u8* Array, Internal_u64 Count) {
		for (Internal_u64 j = 0; j < Count; j++) {Array[j] = 0;}
	}

	void PW(ClearArrayU16)(Internal_u16* Array, Internal_u64 Count) {
		for (Internal_u64 j = 0; j < Count; j++) { Array[j] = 0; }
	}

	void PW(ClearArrayU32)(Internal_u32* Array, Internal_u64 Count) {
		for (Internal_u64 j = 0; j < Count; j++) { Array[j] = 0; }
	}

	void PW(ClearArrayU64)(Internal_u64* Array, Internal_u64 Count) {
		for (Internal_u64 j = 0; j < Count; j++) { Array[j] = 0; }
	}

#endif


#if (defined LTB_AVL)

	/*
		AVL tree with arrays of keys in the nodes. The basic API is:

		-	AVLInsert()
		-	AVLFind()
		-	AVLDelete()
		
		An important note is that AVLInsert() does not allocate the necessary memory for nodes,
		it instead grabs it from what is intended to be a pre-allocated pool of nodes. That is to say,
		the intention is that you allocate memory for as many nodes as you need before you start inserting
		the keys. This is more efficient than a memory allocation per X inserts, reduced fragmentation and
		is allocator agnostic. The tree struct has two fields related to this: MaxNodeCount and CurNodeCount.
		The first is to be initialized to however many nodes you've allocated for, and the second to 0.
		AVLInsert() and AVLDelete() will adjust CurNodeCount as appropriate, so compare CurNodeCount to MaxNodeCount
		to see when you need to allocate additional memory.

		A comparison macro or function must be defined.
		A macro is better for performance in debug mode, in optimized it doesn't seem to matter much.
		
		A typical prelude to including could be:


		void AVLCompare(type_for_node_key A, type_for_node_key B, int* R);

		#define LTB_AVL
		enum { AVLKeysPerNode = 30 };
		#include <LTB.h>

		void AVLCompare(type_for_node_key A, type_for_node_key B, int* R) {
			if		(A < B) R[0] = AVLComparison_FirstParamIsSmaller;
			else if (A > B) R[0] = AVLComparison_FirstParamIsLarger;
			else			R[0] = AVLComparison_ParamsAreEqual;
		}


		The reason we declare the comparison function ahead of including is because 
		the AVLComparison_XXX identifiers are an enum defined later here. The decision
		was made to not have the user define those enums, because that could be confusing.
		The int* R argument is actually an enum AVLCompareResult, but C doesn't let you
		declare enums ahead of time.

		The amount of keys per node is configurable, but must be at least 3. Performance
		wise anything from 5 to 70 could be fine. Test and measure for your use case.
		The more keys, the more memory efficient you'll be, though the performance
		degrades as the amount of keys exceeds 100.
	*/

	enum { LTBInternal(AVLHeightLimit) = 64 };

	struct PW(node) {
		struct PW(node)* Left;
		struct PW(node)* Right;
		Internal_u64	 KeyCount;
		union {
			type_for_node_key Keys[AVLKeysPerNode];
			struct {
				type_for_node_key Lower;
				type_for_node_key Rest[AVLKeysPerNode - 2];
				type_for_node_key Upper;
			};
		};
		Internal_i16			Balance;
	}; typedef struct PW(node) PW(node);


	struct PW(tree) {
		PW(node)*		Nodes;
		Internal_u64	MaxNodeCount;
		Internal_u64	CurNodeCount;
		PW(node)*		Root;
		Internal_u64	KeyCount;
		Internal_u64	Height;
	};  typedef struct PW(tree) PW(tree);


	void LTBInternal(HandleLeftwardsImbalance)(PW(node)** P);
	void LTBInternal(HandleRightwardsImbalance)(PW(node)** P);


	enum LTBInternal(direction) {
		LTBInternal(D_Left) = -1, LTBInternal(D_Right) = 1
	}; struct PW(node_direction) {
		PW(node)*		Node;
		enum LTBInternal(direction)	Direction;
	}; typedef struct PW(node_direction) PW(node_direction);


	enum PW(AVLCompareResult) {
		 PW(AVLComparison_FirstParamIsSmaller),
		 PW(AVLComparison_FirstParamIsLarger),
		 PW(AVLComparison_ParamsAreEqual),
		 PW(AVLComparison_InvalidResult)
	};

	void PW(AVLInsert)(type_for_node_key Key, PW(tree)* Tree) {
		if (!Tree) {
			return;
		} if (Tree->MaxNodeCount == Tree->CurNodeCount) {
			DebugBreak(); // Need to expand the node array for the tree
		} if (!Tree->Root) {
			Tree->Root = Tree->Nodes + Tree->CurNodeCount++;
			Tree->Root->Lower = Key;
			Tree->Root->KeyCount++;
			Tree->KeyCount++;
			return;
		}

		Tree->KeyCount++;

		PW(node_direction) Previous[10*LTBInternal(AVLHeightLimit)];

		Internal_u64 Height = 0, RetracingIndex = 0;
		PW(node)* Cur = Tree->Root;
		while (Cur) {
			if (Cur->Balance) {
				RetracingIndex = Height;
			} 

			Previous[Height].Node = Cur;
			
			if (Cur->KeyCount < AVLKeysPerNode) {
				//Cur->Keys[Cur->KeyCount++] = Key;

				#ifdef LTB_AVLMacroCompare
				enum PW(AVLCompareResult) R;
				AVLCompare(Key, Cur->Keys[Cur->KeyCount - 1], R);
				#else
				int R;
				AVLCompare(Key, Cur->Keys[Cur->KeyCount - 1], &R);
				#endif

				Internal_u64 i = Cur->KeyCount - 1;
				while 
				(
				R == AVLComparison_FirstParamIsSmaller && 
				i != LTBInternal(MaxU64)
				)
				{
					Cur->Keys[i + 1] = Cur->Keys[i];
					i--;
					#ifdef LTB_AVLMacroCompare
					AVLCompare(Key, Cur->Keys[i], R);
					#else
					AVLCompare(Key, Cur->Keys[i], &R);
					#endif
				}
				Cur->Keys[i + 1] = Key;
				Cur->Upper = Cur->Keys[Cur->KeyCount++];
				return;
			}
			
			#ifdef LTB_AVLMacroCompare
			enum PW(AVLCompareResult) LowerCompare, UpperCompare;
			AVLCompare(Key, Cur->Lower, LowerCompare);
			AVLCompare(Key, Cur->Upper, UpperCompare);
			#else
			int LowerCompare, UpperCompare;
			AVLCompare(Key, Cur->Lower, &LowerCompare);
			AVLCompare(Key, Cur->Upper, &UpperCompare);
			#endif

			if (LowerCompare == PW(AVLComparison_FirstParamIsSmaller)) {
				Previous[Height++].Direction = LTBInternal(D_Left);
				if (Cur->Left) {
					Cur = Cur->Left;
				} else {
					Cur->Left = Tree->Nodes + Tree->CurNodeCount++;
					Cur->Left->Keys[0] = Key;
					Cur->Left->Upper = Key;
					Cur->Left->KeyCount++;
					break;
				}
			} else if (UpperCompare == PW(AVLComparison_FirstParamIsLarger)) {
				Previous[Height++].Direction = LTBInternal(D_Right);
				if (Cur->Right) {
					Cur = Cur->Right;
				} else {
					Cur->Right = Tree->Nodes + Tree->CurNodeCount++;
					Cur->Right->Keys[0] = Key;
					Cur->Right->Upper = Key;
					Cur->Right->KeyCount++;
					break;
				}
			} else {
				Internal_u64 i = 1;
				type_for_node_key Temp;
				#ifdef LTB_AVLMacroCompare
				AVLCompare(Key, Cur->Keys[i], LowerCompare);
				#else
				AVLCompare(Key, Cur->Keys[i], &LowerCompare);
				#endif
				while (LowerCompare == PW(AVLComparison_FirstParamIsLarger)) {
					i++;
					#ifdef LTB_AVLMacroCompare
					AVLCompare(Key, Cur->Keys[i], LowerCompare);
					#else
					AVLCompare(Key, Cur->Keys[i], &LowerCompare);
					#endif
				}

				if (i == 1) {
					Temp = Cur->Lower;
					Cur->Lower = Key;
				} else if (i == (AVLKeysPerNode - 1)) {
					Temp = Cur->Upper;
					Cur->Upper = Key;
				} else {
					if (i < (AVLKeysPerNode / 2)) {
						Temp = Cur->Lower;
						for (Internal_u64 j = 0; j < (i - 1); j++) {
							Cur->Keys[j] = Cur->Keys[j + 1];
						}
						i--;
					} else {
						Temp = Cur->Upper;
						for (Internal_u64 j = AVLKeysPerNode - 1; j > i; j--) {
							Cur->Keys[j] = Cur->Keys[j - 1];
						}
					}
					Cur->Keys[i] = Key;
				}
				Key = Temp;
			}
		}

		PW(node)** NodeThatNeedsBalancing = 0;
		for (Internal_u64 j = RetracingIndex; j < Height; j++) {
			Previous[j].Node->Balance += Previous[j].Direction;
			Internal_i64 B = Previous[j].Node->Balance;

			if (B == -2 || B == 2) {
				if (j == 0) {
					NodeThatNeedsBalancing = &Tree->Root;
				} else {
					if (Previous[j - 1].Direction == LTBInternal(D_Left)) {
						NodeThatNeedsBalancing = &Previous[j - 1].Node->Left;
					} else {
						NodeThatNeedsBalancing = &Previous[j - 1].Node->Right;
					}
				}
			}

		}
		Internal_u64 IncreasedHeight = 0;
		if (Height > Tree->Height) {
			IncreasedHeight = 1;
			Tree->Height = Height;
		}
		if (NodeThatNeedsBalancing) {

			if (NodeThatNeedsBalancing[0]->Balance == -2) {
				LTBInternal(HandleLeftwardsImbalance)(NodeThatNeedsBalancing);
			} else {
				LTBInternal(HandleRightwardsImbalance)(NodeThatNeedsBalancing);
			}

			if (NodeThatNeedsBalancing[0]->KeyCount < AVLKeysPerNode) {
				for (Internal_u64 i = 1; i < AVLKeysPerNode; i++) {
					NodeThatNeedsBalancing[0]->Keys[i] =
						NodeThatNeedsBalancing[0]->Right->Keys[i - 1]
					;
					NodeThatNeedsBalancing[0]->Right->Keys[i - 1] = 0;
				}
				NodeThatNeedsBalancing[0]->Right->Keys[0] = NodeThatNeedsBalancing[0]->Right->Upper;
				NodeThatNeedsBalancing[0]->Right->KeyCount = 1;
				NodeThatNeedsBalancing[0]->KeyCount = AVLKeysPerNode;
			}

			if (IncreasedHeight) {
				Tree->Height--;
			}
		}
	}

	struct PW(AVLFindResult) {
		PW(node)*		Node;
		Internal_u64	Index;
	}; typedef struct PW(AVLFindResult) PW(AVLFindResult);

	PW(AVLFindResult) PW(AVLFind)(type_for_node_key Key, PW(tree)* Tree) {
		#ifdef LTB_AVL_FailQuietly
		if (!Tree || !Tree->Root) {
			return (PW(AVLDeleteResult)) { 0, 0 };
		}
		#endif 

		PW(node)* Cur = Tree->Root;

		while (Cur) {
			#ifdef LTB_AVLMacroCompare
				enum PW(AVLCompareResult) LowerCompare, UpperCompare;
				AVLCompare(Key, Cur->Lower, LowerCompare);
				if (Cur->Upper) {
					AVLCompare(Key, Cur->Upper, UpperCompare);
				} else {
					UpperCompare = PW(AVLComparison_InvalidResult);
				}
			#else
				int LowerCompare, UpperCompare;
				AVLCompare(Key, Cur->Lower, &LowerCompare);
				if (Cur->Upper) {
					AVLCompare(Key, Cur->Upper, &UpperCompare);
				} else {
					UpperCompare = PW(AVLComparison_InvalidResult);
				}
			#endif

			if (LowerCompare == PW(AVLComparison_FirstParamIsSmaller)) {
				Cur = Cur->Left;
			} else if (UpperCompare == PW(AVLComparison_FirstParamIsLarger)) {
				Cur = Cur->Right;
			} else {
				for (Internal_u64 i = 0; i < Cur->KeyCount; i++) {
					#ifdef LTB_AVLMacroCompare
						AVLCompare(Key, Cur->Keys[i], LowerCompare);
					#else
						AVLCompare(Key, Cur->Keys[i], &LowerCompare);
					#endif

					if (LowerCompare == PW(AVLComparison_ParamsAreEqual)) {
						PW(AVLFindResult) R = {Cur, i};
						return R;
					}
				}
				((int*) 0)[0] = 1; // FATAL ERROR
			}
		}

		return (PW(AVLFindResult)) { 0, 0 };
	}

	Internal_u64 LTBInternal(RestoreAVLShapeDeletion)(PW(node)** ParentOfNeedsBalancing, PW(tree)* Tree);

	

	struct PW(AVLDeleteResult) {
		PW(node)*				Node;
		PW(type_for_node_key)	Key;
	}; typedef struct PW(AVLDeleteResult) PW(AVLDeleteResult);

	PW(AVLDeleteResult) PW(AVLDelete)(PW(type_for_node_key) Key, PW(tree)* Tree) {

		#ifdef LTB_AVL_FailQuietly
		if (!Tree || !Tree->Root) {
			return (PW(AVLDeleteResult)) { 0, 0 };
		}
		#endif 

		PW(node)* Cur = Tree->Root;
		Internal_u64 OldRootBalance = Tree->Root->Balance;
		PW(node_direction) Previous[10*LTBInternal(AVLHeightLimit)];// = {0}; // Initializing to 0 is a major perf hit, and not logically necessary. Useful for debugging though.
		Internal_i64 Height = 0;
		Tree->KeyCount--; // Come hell or high water, we will definitely remove that key


		#ifdef LTB_AVLMacroCompare
		enum PW(AVLCompareResult) LowerCompare, UpperCompare;
		AVLCompare(Key, Cur->Lower, LowerCompare);
		AVLCompare(Key, Cur->Upper, UpperCompare);
		#else
		int LowerCompare, UpperCompare;
		AVLCompare(Key, Cur->Lower, &LowerCompare);
		AVLCompare(Key, Cur->Upper, &UpperCompare);
		#endif

		while (Cur) {

			Previous[Height].Node = Cur;

			#ifdef LTB_AVLMacroCompare
			enum PW(AVLCompareResult) LowerCompare, UpperCompare;
			AVLCompare(Key, Cur->Lower, LowerCompare);
			if (Cur->Upper) {
				AVLCompare(Key, Cur->Upper, UpperCompare);
			#else
			int LowerCompare, UpperCompare;
			AVLCompare(Key, Cur->Lower, &LowerCompare);
			if (Cur->Upper) {
				AVLCompare(Key, Cur->Upper, &UpperCompare);
			#endif
			} else {
				UpperCompare = PW(AVLComparison_InvalidResult);
			}

			if (LowerCompare == PW(AVLComparison_FirstParamIsSmaller)) {
				Previous[Height++].Direction = LTBInternal(D_Left);
				Cur = Cur->Left;
			} else if (UpperCompare == PW(AVLComparison_FirstParamIsLarger)) {
				Previous[Height++].Direction = LTBInternal(D_Right);
				Cur = Cur->Right;
			} else {
				for (Internal_u64 i = 0; i < Cur->KeyCount; i++) {
					#ifdef LTB_AVLMacroCompare
					AVLCompare(Key, Cur->Keys[i], LowerCompare);
					#else
					AVLCompare(Key, Cur->Keys[i], &LowerCompare);
					#endif

					if (LowerCompare == PW(AVLComparison_ParamsAreEqual)) {
						if (1 != Cur->KeyCount) {
							PW(AVLDeleteResult) Result = {0};
							Result.Node = Cur;
							Result.Key = Cur->Keys[i];

							#if defined LTB_CRT || defined _INC_STRING
							memcpy(Cur->Keys + i, Cur->Keys + (i + 1), (Cur->KeyCount - i - 1)*sizeof(type_for_node_key));
							#else 
							for (Internal_u64 j = i; j < (Cur->KeyCount - 1); j++) {
								Cur->Keys[j] = Cur->Keys[j + 1];
							}
							#endif

							Cur->Keys[--Cur->KeyCount] = 0;
							Cur->Upper = Cur->Keys[Cur->KeyCount - 1];
							return Result;
						} else {
							Cur->KeyCount--;
							goto NodeNeedsToBeDeleted; // we got some work to do
						}
					}
				}
				((int*) 0)[0] = 1; // FATAL ERROR
			}
		}

		return (PW(AVLDeleteResult)) { 0, 0 };

		NodeNeedsToBeDeleted:

		PW(node)* Prev = Height ? Previous[Height - 1].Node : 0;
		PW(node)* Deleted = 0;
		PW(node)** Node = 0;
		Internal_i64 BalanceAdjustment = 0;
		Node = &Tree->Root;
		if (Prev) {
			Node = &Prev->Right;
			BalanceAdjustment = -1;
			if (Cur == Prev->Left) {
				Node = &Prev->Left;
				BalanceAdjustment = 1;
			}
		}

		Deleted = Node[0];

		
		Internal_u64	HeightOfSubtreeAfterDeleted = Height;
		Internal_u64	RetraceAndRebalance = 0;
		Internal_u64	RetraceAndRebalanceIndex = 0;
		Internal_u64	ParentOfNeedsBalancingIndex = LTBInternal(MaxU64); // Can't be initialized to 0 since the index of the parent node could be 0, in which case we don't know if it's been set to 0 or not
		PW(node)**	ParentOfNeedsBalancing = 0;
		if (!(Node[0]->Left || Node[0]->Right)) {
			Node[0] = 0; // Since the node has no children, we can simply erase it.
			if (Prev) {
				Prev->Balance += BalanceAdjustment;
				if (Prev->Balance > 1 || Prev->Balance < -1) {
					if (Height > 1) {
						ParentOfNeedsBalancing = &Previous[Height - 2].Node;
						ParentOfNeedsBalancingIndex = Height - 2;
					} else {
						ParentOfNeedsBalancing = (PW(node)**) LTBInternal(MaxU64);

					}
				} else if (0 == Prev->Balance) {
					RetraceAndRebalance = 1;
					RetraceAndRebalanceIndex = Height - 2;
				}
			} else {
				Tree->Height = 0;
			}
		} else if (!Node[0]->Left != !Node[0]->Right) {
			PW(node)* T = Node[0]->Right;
			if (Node[0]->Left) {
				T = Node[0]->Left;
			} if (Prev) {
				Prev->Balance += BalanceAdjustment;
				if
				(
				 1 < Prev->Balance ||
				-1 > Prev->Balance
				) 
				{
					if (Height > 1) {
						ParentOfNeedsBalancing = &Previous[Height - 2].Node;
						ParentOfNeedsBalancingIndex = Height - 2;
					} else {
						ParentOfNeedsBalancing = (PW(node)**) LTBInternal(MaxU64);

					}
				} else if (0 == Prev->Balance) {
					RetraceAndRebalance = 1;
					RetraceAndRebalanceIndex = Height - 2;
				}
			} Node[0] = T;
		} else {
			PW(node)* Search, *SearchsPrev;
			if (!Prev) {
				Previous[0].Node = Tree->Root;
				Cur->Balance <= 0 ? Previous[0].Direction = LTBInternal(D_Left) : LTBInternal(D_Right);
				HeightOfSubtreeAfterDeleted++;
			}
			if (Cur->Balance <= 0) {
				Previous[HeightOfSubtreeAfterDeleted].Direction = LTBInternal(D_Right);
				Previous[HeightOfSubtreeAfterDeleted++].Node = Cur->Left;
				Search = Cur->Left;
				SearchsPrev = Cur;
				while (Search->Right) {
					SearchsPrev = Search;
					Search = Search->Right;
					Previous[HeightOfSubtreeAfterDeleted].Direction = LTBInternal(D_Right);
					Previous[HeightOfSubtreeAfterDeleted++].Node = Search;
				}
				if (HeightOfSubtreeAfterDeleted == (Height + 1)) {
					SearchsPrev->Left = Search->Left;
				} else {
					if (HeightOfSubtreeAfterDeleted > 2) {
						SearchsPrev->Right = Search->Left;
					} else {
						SearchsPrev->Left = Search->Left;
					}
				}
				PW(node)* Temp1 = 0, *Temp2 = 0;
				Temp1 = Cur->Right;
				Temp2 = (Cur->Left == Search) ? Search->Left : Cur->Left;
				Node[0] = Search;
				Node[0]->Left = Temp2;
				Node[0]->Right = Temp1;
				if (SearchsPrev != Cur) {
					Search->Balance = Cur->Balance;
					SearchsPrev->Balance--;
					if (SearchsPrev->Balance == 0) {
						if (Search->Left == SearchsPrev) {
							Search->Balance++;
							if (0 == Search->Balance) {
								RetraceAndRebalance = 1;
								RetraceAndRebalanceIndex = Height - 1;
							}
						} else {
							RetraceAndRebalance = 1;
							RetraceAndRebalanceIndex = HeightOfSubtreeAfterDeleted - 2;
						}
					}
				} else {
					Search->Balance = Cur->Balance + 1;
					if (Prev && !Search->Balance) {
						Prev->Balance -= Previous[Height - 1].Direction;
						if
						(
							1 < Prev->Balance ||
						-1 > Prev->Balance
						)
						{
							if (Height >= 2) {
								ParentOfNeedsBalancing = &Previous[Height - 2].Node;
								ParentOfNeedsBalancingIndex = Height - 2;
							} else {
								ParentOfNeedsBalancing = (PW(node)**) LTBInternal(MaxU64);

							}
						} else if (0 == Prev->Balance) {
							RetraceAndRebalance = 1;
							RetraceAndRebalanceIndex = HeightOfSubtreeAfterDeleted - 3;
						}
					}
				}
				Previous[HeightOfSubtreeAfterDeleted - 1].Direction = LTBInternal(D_Left);
			} else if (Cur->Balance > 0) {
				Previous[HeightOfSubtreeAfterDeleted].Direction = LTBInternal(D_Left);
				Previous[HeightOfSubtreeAfterDeleted++].Node = Cur->Right;
				Search = Cur->Right;
				SearchsPrev = Cur;
				while (Search->Left) {
					SearchsPrev = Search;
					Search = Search->Left;
					Previous[HeightOfSubtreeAfterDeleted].Direction = LTBInternal(D_Left);
					Previous[HeightOfSubtreeAfterDeleted++].Node = Search;
				}
				if (HeightOfSubtreeAfterDeleted == (Height + 1)) {
					SearchsPrev->Right = Search->Right;
				} else {
					if (HeightOfSubtreeAfterDeleted > 2) {
						SearchsPrev->Left = Search->Right;
					} else {
						SearchsPrev->Right = Search->Right;
					}
				}
				PW(node)* Temp1 = 0, *Temp2 = 0;
				Temp1 = Cur->Left;
				Temp2 = (Cur->Right == Search) ? Search->Right : Cur->Right;
				Node[0] = Search;
				Node[0]->Left = Temp1;
				Node[0]->Right = Temp2;
				if (SearchsPrev != Cur) {
					Search->Balance = Cur->Balance;
					SearchsPrev->Balance++;
					if (SearchsPrev->Balance == 0) {
						if (SearchsPrev == Search->Right) {
							Search->Balance--;
							if (0 == Search->Balance) {
								RetraceAndRebalance = 1;
								RetraceAndRebalanceIndex = Height - 1;
							}
						} else {
							RetraceAndRebalance = 1;
							RetraceAndRebalanceIndex = HeightOfSubtreeAfterDeleted - 2;
						}
					}
				} else {
					Search->Balance = Cur->Balance - 1;
					if (Prev && !Search->Balance) {
						Prev->Balance -= Previous[Height - 1].Direction; // Previous[Height - 1] == Prev
						if
						(
						 1 < Prev->Balance ||
						-1 > Prev->Balance
						)
						{
							if (Height >= 2) {
								ParentOfNeedsBalancing = &Previous[Height - 2].Node;
								ParentOfNeedsBalancingIndex = Height - 2;
							} else {
								ParentOfNeedsBalancing = (PW(node)**) LTBInternal(MaxU64);

							}
						} else if (0 == Prev->Balance) {
							RetraceAndRebalance = 1;
							RetraceAndRebalanceIndex = HeightOfSubtreeAfterDeleted - 3;
						}
					}
				}
				Previous[HeightOfSubtreeAfterDeleted - 1].Direction = LTBInternal(D_Right);
			}

			if (Prev) {
				for (Internal_u64 i = Height, j = HeightOfSubtreeAfterDeleted - 1; i != j; i++) {
					PW(node_direction) Temp = Previous[i];
					Previous[i] = Previous[j];
					Previous[j] = Temp;
				}
			} else {
				Previous[0] = Previous[--HeightOfSubtreeAfterDeleted];
				if (RetraceAndRebalance) {
					RetraceAndRebalanceIndex--;
				}
			}

			if
			(
			!ParentOfNeedsBalancing		&&
			 1 < SearchsPrev->Balance	||
			-1 > SearchsPrev->Balance
			)
			{
				ParentOfNeedsBalancing = &Previous[HeightOfSubtreeAfterDeleted - 2].Node;
				ParentOfNeedsBalancingIndex = HeightOfSubtreeAfterDeleted - 2;
			}
		}


		Internal_u64 LastIndex = 0xFFFFFFFFFFFFFFFE;
		if (RetraceAndRebalance) {
			WeNeedToDoThisIGuess:

			Internal_i64 i = RetraceAndRebalanceIndex;
			if (LastIndex < 0xFFFFFFFFFFFFFFFE) {
				if (Previous[LastIndex].Node->Balance != 0) {
					i = LTBInternal(MaxU64);
				} else {
					i = LastIndex - 1;
				}
			}
			for (; i >= 0; i--, LastIndex = i) {
				Previous[i].Node->Balance -= Previous[i].Direction;
				if 
				(
				 1 < Previous[i].Node->Balance ||
				-1 > Previous[i].Node->Balance
				)
				{
					if (ParentOfNeedsBalancing) {
						Internal_u64 BalanceFactorOfRotatedNode = LTBInternal(RestoreAVLShapeDeletion)(ParentOfNeedsBalancing, Tree);
					} if (i == 0) {
						ParentOfNeedsBalancing = (PW(node)**) LTBInternal(MaxU64);
						ParentOfNeedsBalancingIndex = LTBInternal(MaxU64);
					} else {
						ParentOfNeedsBalancing = &Previous[i - 1].Node;
						ParentOfNeedsBalancingIndex = i - 1;
					} if (Previous[i].Node->Balance == -2) {
						if (Previous[i].Node->Left->Balance == 0) {
							break; // This is a special case that only happens with deletions. In this case,
									// we need to stop here, because after rotations the node that has taken the
									// unbalanced ones place will definitively not have a balance factor of 0,
									// so we have to stop retracing and rebalancing the subtree here.
									// The opposite is true for when the left/right child of the unbalanced node
									// is not balanced.
						}
					} else {
						if (Previous[i].Node->Right->Balance == 0) {
							break;
						}
					}
				} else if (0 != Previous[i].Node->Balance) {
					break;
				}
			}
		}

		if (ParentOfNeedsBalancing) {
			Internal_u64 BalanceFactorOfRotatedNode = LTBInternal(RestoreAVLShapeDeletion)(ParentOfNeedsBalancing, Tree);
			ParentOfNeedsBalancing = 0;
			if (0 == BalanceFactorOfRotatedNode) {
				if
				(
				1 != HeightOfSubtreeAfterDeleted &&
				ParentOfNeedsBalancingIndex != LTBInternal(MaxU64) &&
				LastIndex != LTBInternal(MaxU64)
				)
				{// don't retrace and rebalance when the only node we've traversed was the root
					RetraceAndRebalanceIndex = ParentOfNeedsBalancingIndex;
					goto WeNeedToDoThisIGuess;
				}
			}
		}

		if (OldRootBalance != 0 && Tree->Root->Balance == 0) {
			Tree->Height--;
		}

		Tree->CurNodeCount--;
		Deleted->Left = 0;
		Deleted->Right = 0;
		Deleted->Balance = 0;

		PW(AVLDeleteResult) Result = {0};
		Result.Node = Deleted;
		Result.Key = Deleted->Lower;
		Deleted->Lower = 0;
		return Result;
	}


	Internal_u64 LTBInternal(RestoreAVLShapeDeletion)(PW(node)** ParentOfNeedsBalancing, PW(tree)* Tree) {
		Internal_u64 BalanceFactor;
		if (ParentOfNeedsBalancing == (node**) LTBInternal(MaxU64)) {
			ParentOfNeedsBalancing = &Tree->Root;
		} else {
			if (
				ParentOfNeedsBalancing[0]->Left->Balance ==  2 ||
				ParentOfNeedsBalancing[0]->Left->Balance == -2
				) {
				ParentOfNeedsBalancing = &ParentOfNeedsBalancing[0]->Left;
			} else {
				ParentOfNeedsBalancing = &ParentOfNeedsBalancing[0]->Right;
			}
		}
		if (ParentOfNeedsBalancing[0]->Balance == -2) {
			if (ParentOfNeedsBalancing[0]->Left->Balance == 0) {
				/****************************************************
				This is something that can only happen with deletions,
				and not with insertions. In this case it's impossible
				to achieve a balance factor of 0, but correct AVL shape
				can be reached with a single rotation.
				*****************************************************/
				BalanceFactor = 1;
				PW(node)* Temp = ParentOfNeedsBalancing[0]->Left;
				ParentOfNeedsBalancing[0]->Left = Temp->Right;
				Temp->Right = ParentOfNeedsBalancing[0];
				ParentOfNeedsBalancing[0] = Temp;
				ParentOfNeedsBalancing[0]->Balance++;
				ParentOfNeedsBalancing[0]->Right->Balance++;

			} else {
				BalanceFactor = 0;
				LTBInternal(HandleLeftwardsImbalance)(ParentOfNeedsBalancing);
			}
		} else {
			if (ParentOfNeedsBalancing[0]->Right->Balance == 0) {
				BalanceFactor = 1;
				PW(node)* Temp = ParentOfNeedsBalancing[0]->Right;
				ParentOfNeedsBalancing[0]->Right = Temp->Left;
				Temp->Left = ParentOfNeedsBalancing[0];
				ParentOfNeedsBalancing[0] = Temp;
				ParentOfNeedsBalancing[0]->Balance--;
				ParentOfNeedsBalancing[0]->Left->Balance--;
			} else {
				BalanceFactor = 0;
				LTBInternal(HandleRightwardsImbalance)(ParentOfNeedsBalancing);
			}
		}
		return BalanceFactor;
	}

	#define Rotate(A, B, P) \
			Temp1 = (P);\
			(P) = (P)->A;\
			Temp2 = (P)->B;\
			(P)->B = Temp1;\
			Temp1->A = Temp2;

	#define RightRotate(P)	Rotate(Left, Right, P)
	#define LeftRotate(P)	Rotate(Right, Left, P)


	void LTBInternal(HandleLeftwardsImbalance)(PW(node)** P) {
		PW(node)* Temp1 = 0, *Temp2 = 0;
		Internal_u64 TwoRotations = 0;
		if (P[0]->Left->Balance > 0) {
			TwoRotations = 1;
			LeftRotate(P[0]->Left);
			if (!(Temp1->Left || Temp1->Right)) {
				Temp1->Balance = 0;
			} else if (Temp1->Left && Temp1->Right) {
				if (P[0]->Left->Balance == 1) { // P->Left is now what used to be P->Left->Right
					Temp1->Balance = -1;
				} else {
					Temp1->Balance = 0;
				}
			} else if (Temp1->Left) {
				Temp1->Balance = -1;
			}
		} RightRotate(P[0]);
		if (!(Temp1->Left || Temp1->Right)) {
			Temp1->Balance = 0;
		} if (Temp1->Left && Temp1->Right) {
			if (P[0]->Balance == -1 && TwoRotations) {
				// this is the balance value of what used to be P->Left->Right before any rotations.
				// it is currently incorrect given the state of the tree after rotation, but at the
				// time it determines the balance factor of Temp1.
				Temp1->Balance = 1;
			} else {
				Temp1->Balance = 0;
			}
		} else if (Temp1->Right) {
			Temp1->Balance = 1;
		} P[0]->Balance = 0;
	}

	void LTBInternal(HandleRightwardsImbalance)(PW(node)** P) {
		PW(node)* Temp1 = 0, *Temp2 = 0;
		Internal_u64 TwoRotations = 0;
		if (P[0]->Right->Balance < 0) {
			TwoRotations = 1;
			RightRotate(P[0]->Right);
			if (!(Temp1->Left || Temp1->Right)) {
				Temp1->Balance = 0;
			} else if (Temp1->Left && Temp1->Right) {
				if (P[0]->Right->Balance == -1) { // P->Left is now what used to be P->Left->Right
					Temp1->Balance = 1;
				} else {
					Temp1->Balance = 0;
				}
			} else if (Temp1->Right) {
				Temp1->Balance = 1;
			}
		} LeftRotate(P[0]);
		if (!(Temp1->Left || Temp1->Right)) {
			Temp1->Balance = 0;
		} if (Temp1->Left && Temp1->Right) {
			if (P[0]->Balance == 1 && TwoRotations) {
				// this is the balance value of what used to be P->Right->Left before any rotations.
				// it is currently incorrect given the state of the tree after rotation, but at the
				// time it determines the balance factor of Temp1.
				Temp1->Balance = -1;
			} else {
				Temp1->Balance = 0;
			}
		} else if (Temp1->Left) {
			Temp1->Balance = -1;
		} P[0]->Balance = 0;
	}


	void LTBInternal(FindHeight)(PW(node)* Node, Internal_i64* Height, Internal_i64 Depth) {
		if (!Node) return;
		if (!Node->Left && !Node->Right) {
			if (Depth > *Height) *Height = Depth;
		} LTBInternal(FindHeight)(Node->Left, Height, Depth + 1);
		LTBInternal(FindHeight)(Node->Right, Height, Depth + 1);
	}

	Internal_u64 PW(FindHeight)(PW(node)* Node) {
		Internal_u64 H = 0;
		LTBInternal(FindHeight)(Node, &H, 0);
		return H;
	}

	enum PW(avl_integrity_failure) {
		PW(AVL_WrongBalance),
			PW(AVL_NotAVLShape),
			PW(AVL_KeysNotSorted),
			PW(AVL_OK)
	};

	struct PW(avl_integrity) {
		PW(node)* Node;
		enum PW(avl_integrity_failure) Failure;
		Internal_i64 ActualBalance;
	}; typedef struct PW(avl_integrity) PW(avl_integrity);


	void LTBInternal(VerifyTree)(PW(node)* Node, PW(avl_integrity)* Integrity) {
		if (Node->Left == Node) {
			DebugBreak();
			int k = 2;
		} if (Node->Right == Node) {
			DebugBreak();
			int k = 2;
		}

		if (Node->Left) {
			LTBInternal(VerifyTree)(Node->Left, Integrity);
		} if (Node->Right) {
			LTBInternal(VerifyTree)(Node->Right, Integrity);
		} if (Integrity->Failure != PW(AVL_OK)) {
			return;
		}

		if (Node->Balance > 1 || Node->Balance < -1) {
			Integrity->Node = Node;
			Integrity->Failure = PW(AVL_NotAVLShape);
			return;
		}

		Internal_i64 RB = 0;
		if (Node->Right) {
			RB = PW(FindHeight)(Node->Right) + 1;
		} Internal_i64 LB = 0;
		if (Node->Left) {
			LB = PW(FindHeight)(Node->Left) + 1;
		}
		Internal_i64 B = RB - LB;
		if (B != Node->Balance) {
			Integrity->Node = Node;
			Integrity->Failure = PW(AVL_WrongBalance);
			Integrity->ActualBalance = B;
		}

		for (Internal_u64 i = 0; i < (Node->KeyCount - 1); i++) {
			if (!(Node->Keys[i] < Node->Keys[i + 1])) {
				Integrity->Node = Node;
				Integrity->Failure = PW(AVL_KeysNotSorted);
			}
		}
	}


	PW(avl_integrity) PW(VerifyTree)(PW(tree) Tree) {
		PW(avl_integrity) Integrity = {0, PW(AVL_OK)};
		if (Tree.Root) {
			LTBInternal(VerifyTree)(Tree.Root, &Integrity);
		}
		return Integrity;
	}
#endif


#if !(defined LTB_MultivarMacros) && !(defined LTB_Everything) 
	#undef PW
#endif


#undef Internal_i64 
#undef Internal_u64 
#undef Internal_i32 
#undef Internal_u32 
#undef Internal_i16 
#undef Internal_u16 
#undef Internal_i8 
#undef Internal_u8 
