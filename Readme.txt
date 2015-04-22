The language supports only int and bool data types with following features:
1. Golbal data declarations
2. Arithmetic operations
3. Relational opertaions
4. Conditional branching
5. Looping
6. Function call with any number of arguments
7. Recursion

Step 1: The compiler does the syntax analysis and semantic analysis of the code while parsing the code using yacc generated parser (a.l & a.y).
An abstract syntax tree is also generated during parsing.
Step 2: The three address intermediate code generation is done using the Abstract syntax tree generated in Step 1.
Step 3: The generated three address code is given to the parser (code.l & code.y) of three address code for MIPS32 code generation.
Step 4: For simulating MIPS code, spim is used.