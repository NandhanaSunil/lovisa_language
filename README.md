# lovisa_language
### Compiler built using LLVM Version : Version 22.1.6


Command to create an LLVM IR: clang++ -S -emit-llvm .\test.cpp
Command to create executable from LLVM IR: clang++ -o test.exe test.ll
or if it does not work, try: clang++ -o test.exe test.ll -Xlinker /entry:main
