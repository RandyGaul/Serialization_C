// Copyright (C) 2013 Randy Gaul
// All rights reserved.
// This code is for illustration purposes to be studied in
// conjunction with online slideshows. Do not use any of
// this code in your project. You must write every character
// in your own projects from scratch. Trust me, you don't
// actually WANT to use any of this code in your project.

#include "Precompiled.h"
#include "MyObject.h"

int main( void )
{
  MyObject obj;
  obj.id = "An id!";
  obj.rotation = 0.1234f;
  obj.x = 5;
  obj.y = 10;

  SerializeMyObject( &obj, stdout );

  getchar( );

  return 0;
}
