// Copyright (C) 2013 Randy Gaul
// All rights reserved.
// This code is for illustration purposes to be studied in
// conjunction with online slideshows. Do not use any of
// this code in your project. You must write every character
// in your own projects from scratch. Trust me, you don't
// actually WANT to use any of this code in your project.

#include "Precompiled.h"

//Generalized format specifier:
//  %*[flags] [width] [.precision] specifier
//  See: http://www.randygaul.net/2013/02/07/fscanf-power/
// 
//The most important are:
//  *         - Negation; read in the following specifier but assign to nothing
//  specifier - Specifies what sort of data to read from file
// 
//Specific specifiers:
//  []  - Scanset; Reads in any character specified between the brackets,
//                 until a character not specified is read
//  [^] - Negation scanset; Reads in any characters until one specified
//                          within the brackets is read

void Serializeint( int a, FILE *fp )
{
  fprintf( fp, "%d\n", a );
}

void Serializefloat( float a, FILE *fp )
{
  fprintf( fp, "%f\n", a );
}

void Serializestring( string a, FILE *fp )
{
  fprintf( fp, "\"%s\"\n", a );
}

void Serializechar( char a, FILE *fp )
{
  fprintf( fp, "%c\n", a );
}

void SerializeType( const char *type, FILE *fp )
{
  Padding( 0, fp );
  fprintf( fp, "%s\n", type );
}

void SerializeMember( const char *member, FILE *fp )
{
  Padding( 0, fp );
  fprintf( fp, "%s = ", member );
}

void Deserializeint( int *a, FILE *fp )
{
  fscanf( fp, "%*[^=]= %d", a );
}

void Deserializefloat( float *a, FILE *fp )
{
  fscanf( fp, "%*[^=]= %f", a );
}

void Deserializestring( string *a, FILE *fp )
{
  fscanf( fp, "%*[^=]= \"%[^\"]\"", *a ); // :)
}

void DeserializerEatCloseBracket( FILE *fp )
{
  fscanf( fp, "%*[^{]{" );
}

void PlacePads( int pad_count, FILE *fp )
{
  int i = 0;

  while(i < pad_count)
  {
    fprintf( fp, "  " );
    ++i;
  }
}

void ChangePadding( int level )
{
  Padding( level, NULL );
}

void Padding( int increment, FILE *fp )
{
  static int pad_level = 0;
  pad_level += increment;

  if(fp)
    PlacePads( pad_level, fp );
}

void OpenBracket( FILE *fp )
{
  Serializechar( '{', fp );
  ChangePadding( 1 );
}

void CloseBracket( FILE *fp )
{
  ChangePadding( -1 );
  Serializechar( '}', fp );
}
