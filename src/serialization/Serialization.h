// Copyright (C) 2013 Randy Gaul
// All rights reserved.
// This code is for illustration purposes to be studied in
// conjunction with online slideshows. Do not use any of
// this code in your project. You must write every character
// in your own projects from scratch. Trust me, you don't
// actually WANT to use any of this code in your project.

#pragma once

typedef char * string;

#define SERIALIZE( TYPE, OBJ, FP ) \
  Serialize##TYPE( &OBJ, FP )

#define DESERIALIZE( TYPE, OBJ, FP ) \
  Deserialize##TYPE( &OBJ, FP )

void Serializeint( int a, FILE *fp );
void Serializefloat( float a, FILE *fp );
void Serializestring( string a, FILE *fp );
void Serializechar( char a, FILE *fp );
void SerializeType( const char *type, FILE *fp );
void SerializeMember( const char *member, FILE *fp );

void Deserializeint( int *a, FILE *fp );
void Deserializefloat( float *a, FILE *fp );
void Deserializestring( string *a, FILE *fp );
void DeserializerEatCloseBracket( FILE *fp );

void ChangePadding( int level );
void Padding( int increment, FILE *fp );
void OpenBracket( FILE *fp );
void CloseBracket( FILE *fp );
