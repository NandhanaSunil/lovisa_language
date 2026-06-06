/**
 * Lovisa LLVM Executable
 */

#include <string>
#include "./src/lovisa_llvm.h"

int main(int argc, char const *argv[]) {
    std::string program = R"(42)";

    // Compiler instance
    lovisa_LLVM vm;

    vm.exec(program);
    return 0;
}