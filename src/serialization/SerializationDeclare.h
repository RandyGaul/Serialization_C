// Copyright (C) 2013 Randy Gaul
// All rights reserved.
// This code is for illustration purposes to be studied in
// conjunction with online slideshows. Do not use any of
// this code in your project. You must write every character
// in your own projects from scratch. Trust me, you don't
// actually WANT to use any of this code in your project.

#undef NAME
#undef MEMBER
#undef END

#define NAME( NAME ) \
  void Serialize##NAME( NAME *obj, FILE *fp ); \
  void Deserialize##NAME( NAME *obj, FILE *fp );

#define MEMBER( TYPE, MEMBER )

#define END( NAME )
