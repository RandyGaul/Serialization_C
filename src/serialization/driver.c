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
  // Setup an object
  MyObject obj;
  obj.id = "An identifier!";
  obj.rotation = 0.1234f;
  obj.x = 5;
  obj.y = 10;

  // Dump contents of our object
  SERIALIZE( MyObject, obj, stdout );

  // Get some space so that we can place a string in here
  obj.id = (string)malloc( sizeof( char ) * 100 );

  getchar( );

  {
    FILE *fp = fopen( "SerializedMyObject.txt", "r" );
    printf( "Deserializing from SerializedMyObject.txt:\n" );
    printf( "Press enter to deserialize...\n" );
    getchar( );
    DESERIALIZE( MyObject, obj, fp );
    SERIALIZE( MyObject, obj, stdout );
  }

  getchar( );

  free( obj.id );

  return 0;
}
