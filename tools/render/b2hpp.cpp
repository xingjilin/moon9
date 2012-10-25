// - rlyeh

#include <moon9/string/string.hpp>
#include <moon9/io/file.hpp>

int main( int argc, char **argv )
{
	moon9::strings args( argc, argv );

	if( args.size() < 2 )
		return 0;

	moon9::file file( args[1] );

	if( !file.size() )
		return 0;

	moon9::string data = file.read();
	moon9::string filename = moon9::string( file.name() ).lowercase().replace(".","_").replace("-","_");

	std::cout << moon9::string(
		"// generated by b2hpp\n"
		"#pragma once\n"
		"\n"
		"namespace \1\n"
		"{\n"
		"\textern const size_t size;\n"
		"\textern const unsigned char data[];\n"
		"}\n"
		"\n",
		filename );

	return 0;
}