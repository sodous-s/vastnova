#ifndef CODEGEN_H
#define CODEGEN_H

#include "vastnova_ast.h"
#include <string>

namespace vastnova {

std::string compileToLLVM(const Program& prog);

} // namespace vastnova

#endif