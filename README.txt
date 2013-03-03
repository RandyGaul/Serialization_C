// Copyright (C) 2013 Randy Gaul
// All rights reserved.
// This code is for illustration purposes to be studied in
// conjunction with online slideshows. Do not use any of
// this code in your project. You must write every character
// in your own projects from scratch. Trust me, you don't
// actually WANT to use any of this code in your project.

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