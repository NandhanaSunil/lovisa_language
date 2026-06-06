/**
 * Lovisa to LLVM IR Compiler
 */

#ifndef lovisa_llvm_h
#define lovisa_llvm_h

#include <string>

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

class lovisa_LLVM{
    public:
    lovisa_llvm() {
        module_init();
    }
    /**
     * Executes a program.
     */
    void exec(const std::string& program){
        // 1. Parse the program
        // auto ast = parser->parse(program);

        // 2. Compile to LLVM IR:
        // compile(ast);

        // print generated code
        module->print(llvm::outs(), nullptr);

        // 3. Save module IR to file:
        save_module_to_file("./out.ll");

    }

    private:
    /**
     * Initialize the module.
     */
    void module_init() {
        ctx = std::make_unique<llvm::LLVMContext>();
        module = std::make_unique<llvm::Module>("lovisa_LLVM", *ctx);
        builder = std::make_unique<llvm:IRBuilder<>>(*ctx);
    }

    /**
     * Saves IR to file.
     */
    void save_module_to_file(const std::string& file_name){
        std::error_code errorCode;
        llvm::raw_fd_ostream outLL(file_name, errorCode);
        module->print(outLL, nullptr);
    }
    /**
     * Global LLVM context.
     * It owns and manages the core "global" data of LLVM's core
     * infrastructure, including the type and constant unique tables.
     */
    std::unique_ptr<llvm::LLVMContext> ctx;
    
    /**
     * LLVM Module
     * A module instance is used to store all the information related 
     * to an LLVM Module. Module is the top level container of all other
     * LLVM IR objects.
     */
    std::unique_ptr<llvm::Module> module;

    /**
     * IR Builder
     * Provide a uniform API for creating instructions and inserting
     * them into a basic block
     */
    std::unique_ptr<llvm::IRBuilder<>> builder;
};

#endif