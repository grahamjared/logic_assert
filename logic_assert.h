////////////////////////////////////////////////////////////////////////////////////////////////////
// Usage:
// 
// logic_assert works identically to a normal assert, but allows the user to pass a string that
// contains the reason(s) why the program could have terminated. It also allows variables to be
// passed into the error message, as long as they have been converted into a string.
// 
// Example:
//     int a = 5;
//     logic_assert(a != 5, { "a should not equal 5, a is <" + std::to_string(a) + ">" });
//
// Expected Output:
//     Assertion Failed: (a != 5)
//     {
//         Reason: a should not equal 5, a is <5>
//         File: c:/filepath/example/logic_assert.h
//         Line: 10
//     }
// 
// The curly brackets, ({, }), construct a string, and allow the variable 'a' to be printed 
// as long as it is converted into a string first.
//
// To remove logic_assert in RELEASE builds, #define la_remove_release when the compiler is set to
// compile in release (before #include'ing this file). Since determining when the compiler is in debug
// or release mode can be compiler dependent, it is up to the user. Here is an example of what that would
// look like for MSVC2017.
//
// Example: (for msvc2017)
//     #ifdef _DEBUG // in debug mode
//
//     #undef la_remove_release
//
//     #else // otherwise, in release mode
//
//     #define la_remove_release
//
//     #endif // _DEBUG
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <cstdlib>
#include <string>

inline void _logic_assert(const char * expression, const std::string & reason, const char * file, int line)
{
	std::cout
		<< "Assertion Failed: (" << expression << ")\n"
		<< "{\n"
		<< "    Reason: " << reason << "\n"
		<< "    File: " << file << "\n"
		<< "    Line: " << line << "\n"
		<< "}\n";

	std::abort();
}

#ifdef la_remove_release

#define logic_assert(EX, reason) ((void) 0)

#else

#define logic_assert(EX, reason) ((EX) ? (void) 0 : _logic_assert(#EX, reason, __FILE__, __LINE__))

#endif // la_remove_in_release
