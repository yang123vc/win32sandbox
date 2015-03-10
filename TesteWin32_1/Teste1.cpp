// Simplest Win32 Unicode-aware Example with <vector> and <string>
// Reinaldo Moreira - 2014-12-04

#define WIN32_LEAN_AND_MEAN
#define UNICODE

#include <Windows.h>	  // brings windows shit

#include <vector>		  // c++ standard headers
#include <string>

#ifdef UNICODE 
#define std_string wstring
#else
#define std_string string
#endif

void TestaBoxes(CONST PTCHAR caption)
{
	static unsigned calls = 0 ;
	static std::vector < std::std_string > v ;

	if (calls++)
	{ 
		// C++11 range based for! ~~ modern stuff meets old stuff (win32)
		for ( auto men : v )
			MessageBox (
				NULL ,
				men.c_str() , /* this standard member function will return   */
				caption ,     /*  a constant pointer to char or wchar string  */
				MB_OKCANCEL | MB_ICONASTERISK 
			);

	} else {

#define VECPUSH(vec, text) vec.push_back( TEXT( text ) )
		VECPUSH(v, "My dummy message 1");
		VECPUSH(v, "My dummy message 2");
		VECPUSH(v, "My dummy message 3");
		VECPUSH(v, "My dummy message 4");
		VECPUSH(v, "My dummy message 5");
		VECPUSH(v, "My dummy message 6");
		VECPUSH(v, "My dummy message 7");
#undef VECPUSH	// don't pollute the environment! use the preprocessor wisely!

		// try yourself filling out the vector<> with a for or reading content from a file!

	}

}

// no argument identifiers since we will not use them in this example!
INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	TestaBoxes(TEXT(""));

	// MessageBox expands either to MessageBoxW or MessageBoxA, if #define UNICODE is present or absent, respectively.
	// TEXT("str") Macro Expands to L"str" or "str" if #define UNICODE is present or absent, respectively.
	
	MessageBox(NULL,
		TEXT("Hello Modafocker!\nLets do the fucking thing!"),
		TEXT("Hello Windows!"),
		MB_ICONASTERISK);

	TestaBoxes(TEXT("First time!")); // expected to show MessageBoxes previoulsy populated on first call.

	MessageBox(NULL,
		TEXT("A brief pause"),
		TEXT("Short breaking..."),
		MB_ICONASTERISK);


	TestaBoxes(TEXT("Second time!")); // Expected to show the same messages and not new ones.
}