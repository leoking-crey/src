set(LLVM_LINK_COMPONENTS
  ${LLVM_TARGETS_TO_BUILD}
  Support
  )

# By default MSVC has a 2^16 limit on the number of sections in an object file,
# and this needs more than that.
if (MSVC)
  set_source_files_properties(RecursiveASTVisitorTest.cpp PROPERTIES COMPILE_FLAGS /bigobj)
  set_source_files_properties(RecursiveASTVisitorTestExprVisitor.cpp PROPERTIES COMPILE_FLAGS /bigobj)
endif()

add_clang_unittest(ToolingTests
  ASTSelectionTest.cpp
  CastExprTest.cpp
  CommentHandlerTest.cpp
  CompilationDatabaseTest.cpp
  DiagnosticsYamlTest.cpp
  ExecutionTest.cpp
  FixItTest.cpp
  LexicallyOrderedRecursiveASTVisitorTest.cpp
  LookupTest.cpp
  QualTypeNamesTest.cpp
  RecursiveASTVisitorTest.cpp
  RecursiveASTVisitorTestCallVisitor.cpp
  RecursiveASTVisitorTestDeclVisitor.cpp
  RecursiveASTVisitorTestExprVisitor.cpp
  RecursiveASTVisitorTestTypeLocVisitor.cpp
  RefactoringActionRulesTest.cpp
  RefactoringCallbacksTest.cpp
  RefactoringTest.cpp
  ReplacementsYamlTest.cpp
  RewriterTest.cpp
  ToolingTest.cpp
  )

target_link_libraries(ToolingTests
  PRIVATE
  clangAST
  clangASTMatchers
  clangBasic
  clangFormat
  clangFrontend
  clangLex
  clangRewrite
  clangTooling
  clangToolingCore
  clangToolingRefactor
  )
