# logic_assert
A C++ assert that allows for printing variables and reason(s) why it was encountered.

## License
logic_assert uses the UNLICENSE license. Check the file "LICENSE" for more information.

## Usage
logic_assert is fantastic for when the program encounters a situation where no one desires it progresses or recovers. This makes it especially useful for debugging programs, and is personally used for debugging games.


logic_assert works identically to a normal assert, but allows the user to pass a string that
contains the reason(s) why the program could have terminated alongside variables if they are converted and added to the 'reason' string.

##### Example:
```C++
    int a = 5;
    logic_assert(a != 5, { "a should not equal 5, a is <" + std::to_string(a) + ">" });
```

##### Expected Output:
```
Assertion Failed: (a != 5)
{
    Reason: a should not equal 5, a is <5>    
    File: c:/filepath/example/logic_assert.h    
    Line: 10    
}
```

The curly brackets, ({, }), construct a string, and allow the variable 'a' to be printed 
as long as it is converted into a string first.

## Disabling for Release Builds

To remove logic_assert in release builds, #define la_remove_release when the compiler is set to
compile in release (before #include-ing logic_assert.h). Since determining when the compiler is in debug
or release mode can be compiler dependent, it is up to the user. Here is an example of what that would
look like.

##### Example for MSVC2017
```C++
#ifdef _DEBUG // in debug mode

#undef la_remove_release

#else // otherwise, in release mode

#define la_remove_release

#endif // _DEBUG
```
