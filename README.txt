// Copyright (C) 2013 Randy Gaul
// All rights reserved.
// This code is for illustration purposes to be studied in
// conjunction with online slideshows. Do not use any of
// this code in your project. You must write every character
// in your own projects from scratch. Trust me, you don't
// actually WANT to use any of this code in your project.

Summary:
A proof of concept for a simple serialization technique. All changes to a structure are automatically propogated into all macro expansions, making for near zero maintenance programming. The format of serialization can be easily changed due to the nature of scanf scansets. Error checking can be implemented with similar macro expansion techniques without much of a hassle.

To Use:
Declare a struct in a header, do not use include protection. Declare struct with the following macros:

_NAME( )
_MEMBER( )
_END( )

Example:

typedef struct SomeStruct
{
  double x;
  string t;
} SomeStruct;

Would be:

_NAME( SomeStruct )
_MEMBER( double, x )
_MEMBER( string, t )
_END( SomeStruct )

Then use this file to fill out macros within:
SerializeDeclare
SerializeDefine
DeclareStruct

See MyObject.c and MyObject.h for a clear example.

Note:
There isn't any robust error checking. Member names and type names can be used to assert that serialization is behaving as intended, as well as to assert that the file format is correct.