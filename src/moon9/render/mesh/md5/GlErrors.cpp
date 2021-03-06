/* -*- c++ -*- */
/////////////////////////////////////////////////////////////////////////////
//
// GlErrors.cpp  -- Copyright (c) 2006-2007 David Henry
// last modification: jan. 24, 2007
//
// This code is licenced under the MIT license.
//
// This software is provided "as is" without express or implied
// warranties. You may freely copy and compile this source into
// applications you distribute provided that the copyright text
// below is included in the resulting source code.
//
// OpenGL error management.
//
/////////////////////////////////////////////////////////////////////////////

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

#include "GlErrors.h"

using std::cerr;
using std::endl;


// -------------------------------------------------------------------------
// checkOpenGLErrors
//
// Print the last OpenGL error code.  @file is the filename where the
// function has been called, @line is the line number.  You should use
// this function like this:
//  checkOpenGLErrors (__FILE__, __LINE__);
// -------------------------------------------------------------------------

GLenum
checkOpenGLErrors (const char *file, int line)
{
  GLenum errCode = glGetError ();

  if (errCode != GL_NO_ERROR)
    cerr << "(GL) " << file << " (" << line << "): "
	 << gluErrorString (errCode) << endl;

  return errCode;
}
