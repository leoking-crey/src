// g++ 1.37.1 bug 900428_03

// g++ fails to detect cases where a constructor for a derived class invokes
// (either explicitly or implicitly) a private constructor for a base class.

// cfront 2.0 passes this test.

// keywords: inheritance, private, accessability, constructors

struct struct_0 {
  int struct_0_data_member;

private:
  struct_0 (int, int);
public:
  struct_0 (int);
};

struct_0::struct_0 (int i) { }
struct_0::struct_0 (int, int) { } // ERROR - xref from below

struct struct_1 : public struct_0 {

  struct_1 ();
};

struct_1::struct_1 () : struct_0 (8,9)
{				// ERROR - 
}

struct struct_2 {
  struct_0 struct_2_data_member;

  struct_2 ();
};

// g++ catches the following error (but does so only at the line with the 
// closing curly brace).

struct_2::struct_2 () : struct_2_data_member (8,9)
{				// ERROR - should be up one line
}

int main () { return 0; }
