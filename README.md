# LTB
A C library for algorithms, data structures, and general purpose usefulness. Designed to be C std lib agnostic and you-only-get-what-you-ask-for. #include the modules that you want. "LTB_" prefix optional, #define LTB_Prefix.

Content:
  - LTB_Types: integer types named as uXX or iXX where XX is the amount of bits (u8 and not u08 in the case of single byte int). 2D, 3D                  and 4D vectors of 64-bit signed and unsigned integer types and 32 and 64-bit floating point. With functions for arithmetic. 
  - LTB_Algorithms: A collection of typical CS algorithms, such as GCD, binary search, nth element, exponentiation of integers, etc.
                    Aims to be at feature parity with <algorithm>?
  - LTB_AVL: AVL tree built to be more performant than libavl. 3x better insertion all around, slightly worse search for perfectly sorted              input, up to 2.5x faster search for randomized input, 1.7x to 3x faster deletion.
  
