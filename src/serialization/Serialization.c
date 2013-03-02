// Copyright (C) 2013 Randy Gaul
// All rights reserved.
// This code is for illustration purposes to be studied in
// conjunction with online slideshows. Do not use any of
// this code in your project. You must write every character
// in your own projects from scratch. Trust me, you don't
// actually WANT to use any of this code in your project.

#include "Precompiled.h"

void SerializeInt( int a, FILE *fp )
{
  Padding( 0, fp );
  fprintf( fp, "%d\n", a );
}

void SerializeFloat( float a, FILE *fp )
{
  Padding( 0, fp );
  fprintf( fp, "%f\n", a );
}

void SerializeString( string a, FILE *fp )
{
  Padding( 0, fp );
  fprintf( fp, "%s\n", a );
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
  SerializeString( "{", fp );
  ChangePadding( 1 );
}

void CloseBracket( FILE *fp )
{
  SerializeString( "}", fp );
  ChangePadding( -1 );
}
