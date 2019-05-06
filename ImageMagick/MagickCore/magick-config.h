/*
  Copyright 2012 ImageMagick Studio LLC, a non-profit organization
  dedicated to making software imaging solutions freely available.

  You may not use this file except in compliance with the License.  You may
  obtain a copy of the License at

    https://imagemagick.org/script/license.php

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  MagickConfig not autogenerated (fixed stuff)
*/
#ifndef MAGICKCORE_MAGICK_CONFIG_H
#define MAGICKCORE_MAGICK_CONFIG_H

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

#include "MagickCore/magick-baseconfig.h"

/* Compatibility block */
#if !defined(MAGICKCORE_QUANTUM_DEPTH) && defined(MAGICKCORE_QUANTUM_DEPTH_OBSOLETE_IN_H)
# warning "you should set MAGICKCORE_QUANTUM_DEPTH to sensible default set it to configure time default"
# warning "this is an obsolete behavior please fix your makefile"
# define MAGICKCORE_QUANTUM_DEPTH MAGICKCORE_QUANTUM_DEPTH_OBSOLETE_IN_H
#endif

/* Number of bits in a pixel Quantum (8/16/32/64) */
#ifndef MAGICKCORE_QUANTUM_DEPTH
# error "you should set MAGICKCORE_QUANTUM_DEPTH"
#endif

/* check values */
#if MAGICKCORE_QUANTUM_DEPTH != 8
# if MAGICKCORE_QUANTUM_DEPTH != 16
#  if MAGICKCORE_QUANTUM_DEPTH != 32
#   if MAGICKCORE_QUANTUM_DEPTH != 64
#    error "MAGICKCORE_QUANTUM_DEPTH is not 8/16/32/64 bits"
#   endif
#  endif
# endif
#endif


#if !defined(MAGICKCORE_HDRI_ENABLE) && defined(MAGICKCORE_HDRI_ENABLE_OBSOLETE_IN_H)
# warning "you should set MAGICKCORE_HDRI_ENABLE to sensible default set it to configure time default"
# warning "this is an obsolete behavior please fix yours makefile"
# define MAGICKCORE_HDRI_ENABLE MAGICKCORE_HDRI_ENABLE_OBSOLETE_IN_H
#endif

/* whether HDRI is enable */
#if !defined(MAGICKCORE_HDRI_ENABLE)
# error "you should set MAGICKCORE_HDRI_ENABLE"
#endif

#if MAGICKCORE_HDRI_ENABLE
# define MAGICKCORE_HDRI_SUPPORT 1
#endif

/* Compatibility block */
#if !defined(MAGICKCORE_QUANTUM_DEPTH) && defined(MAGICKCORE_QUANTUM_DEPTH_OBSOLETE_IN_H)
# warning "you should set MAGICKCORE_QUANTUM_DEPTH to sensible default set it to configure time default"
# warning "this is an obsolete behavior please fix yours makefile"
# define MAGICKCORE_QUANTUM_DEPTH MAGICKCORE_QUANTUM_DEPTH_OBSOLETE_IN_H
#endif

/* Number of bits in a pixel Quantum (8/16/32/64) */
#ifndef MAGICKCORE_QUANTUM_DEPTH
# error "you should set MAGICKCORE_QUANTUM_DEPTH"
#endif

/* check values */
#if MAGICKCORE_QUANTUM_DEPTH != 8
# if MAGICKCORE_QUANTUM_DEPTH != 16
#  if MAGICKCORE_QUANTUM_DEPTH != 32
#   if MAGICKCORE_QUANTUM_DEPTH != 64
#    error "MAGICKCORE_QUANTUM_DEPTH is not 8/16/32/64 bits"
#   endif
#  endif
# endif
#endif


#if !defined(MAGICKCORE_HDRI_ENABLE) && defined(MAGICKCORE_HDRI_ENABLE_OBSOLETE_IN_H)
# warning "you should set MAGICKCORE_HDRI_ENABLE to sensible default set it to configure time default"
# warning "this is an obsolete behavior please fix yours makefile"
# define MAGICKCORE_HDRI_ENABLE MAGICKCORE_HDRI_ENABLE_OBSOLETE_IN_H
#endif

/* whether HDRI is enable */
#if !defined(MAGICKCORE_HDRI_ENABLE)
# error "you should set MAGICKCORE_HDRI_ENABLE"
#endif

#if MAGICKCORE_HDRI_ENABLE
# define MAGICKCORE_HDRI_SUPPORT 1
#endif

#if defined __CYGWIN32__ && !defined __CYGWIN__
   /* For backwards compatibility with Cygwin b19 and
      earlier, we define __CYGWIN__ here, so that
      we can rely on checking just for that macro. */
#  define __CYGWIN__  __CYGWIN32__
#endif

/*! stringify */
#define MAGICKCORE_STRING_QUOTE(str) #str
#define MAGICKCORE_STRING_XQUOTE(str) MAGICKCORE_STRING_QUOTE(str)

/*  ABI SUFFIX */
#ifndef MAGICKCORE_HDRI_SUPPORT
#define MAGICKCORE_ABI_SUFFIX  "Q" MAGICKCORE_STRING_XQUOTE(MAGICKCORE_QUANTUM_DEPTH)
#else 
#define MAGICKCORE_ABI_SUFFIX "Q" MAGICKCORE_STRING_XQUOTE(MAGICKCORE_QUANTUM_DEPTH) "HDRI"
#endif 

/* some path game */
#if !defined __CYGWIN__
# if defined (_WIN32) || defined (_WIN64) || defined (__MSDOS__) || defined (__DJGPP__) || defined (__OS2__)
   /* Use Windows separators on all _WIN32 defining
      environments, except Cygwin. */
#  define MAGICKCORE_DIR_SEPARATOR_CHAR		'\\'
#  define MAGICKCORE_DIR_SEPARATOR		"\\"
#  define MAGICKCORE_PATH_SEPARATOR_CHAR	';'
#  define MAGICKCORE_PATH_SEPARATOR		";"
# endif
#endif
 
/* posix */
#ifndef MAGICKCORE_DIR_SEPARATOR_CHAR
   /* Assume that not having this is an indicator that all
      are missing. */
#  define MAGICKCORE_DIR_SEPARATOR_CHAR		'/'
#  define MAGICKCORE_DIR_SEPARATOR		"/"
#  define MAGICKCORE_PATH_SEPARATOR_CHAR	':'
#  define MAGICKCORE_PATH_SEPARATOR		":"
#endif /* !DIR_SEPARATOR_CHAR */

# if defined(MAGICKCORE_POSIX_SUPPORT) || defined(__MINGW32__)
 
/* module dir */
#ifndef MAGICKCORE_MODULES_DIRNAME
# define MAGICKCORE_MODULES_DIRNAME MAGICKCORE_MODULES_BASEDIRNAME "-" MAGICKCORE_ABI_SUFFIX
#endif
 
#ifndef MAGICKCORE_MODULES_PATH
#  define MAGICKCORE_MODULES_PATH MAGICKCORE_LIBRARY_PATH MAGICKCORE_DIR_SEPARATOR MAGICKCORE_MODULES_DIRNAME
#endif
 
#ifndef MAGICKCORE_MODULES_RELATIVE_PATH
#define MAGICKCORE_MODULES_RELATIVE_PATH MAGICKCORE_LIBRARY_RELATIVE_PATH MAGICKCORE_DIR_SEPARATOR MAGICKCORE_MODULES_DIRNAME
#endif
 
/* Subdirectory under lib to place ImageMagick coder module files */
#ifndef MAGICKCORE_CODER_PATH
# if defined(vms)
#  define MAGICKCORE_CODER_PATH "sys$login:"
# else
#  define MAGICKCORE_CODER_PATH MAGICKCORE_MODULES_PATH MAGICKCORE_DIR_SEPARATOR MAGICKCORE_CODER_DIRNAME
# endif
#endif
 
#ifndef MAGICKCORE_CODER_RELATIVE_PATH
# define MAGICKCORE_CODER_RELATIVE_PATH MAGICKCORE_MODULES_RELATIVE_PATH MAGICKCORE_DIR_SEPARATOR MAGICKCORE_CODER_DIRNAME
#endif
 
/* subdirectory under lib to place ImageMagick filter module files */
#ifndef MAGICKCORE_FILTER_PATH
# if defined(vms)
#  define MAGICKCORE_FILTER_PATH  "sys$login:"
# else
#  define MAGICKCORE_FILTER_PATH MAGICKCORE_MODULES_PATH MAGICKCORE_DIR_SEPARATOR MAGICKCORE_FILTER_DIRNAME
# endif
#endif
 
#ifndef MAGICKCORE_FILTER_RELATIVE_PATH
# define MAGICKCORE_FILTER_RELATIVE_PATH MAGICKCORE_MODULES_RELATIVE_PATH MAGICKCORE_DIR_SEPARATOR MAGICKCORE_FILTER_DIRNAME
#endif

/* sharearch dir */
#ifndef MAGICKCORE_SHAREARCH_DIRNAME
# define MAGICKCORE_SHAREARCH_DIRNAME MAGICKCORE_SHAREARCH_BASEDIRNAME "-" MAGICKCORE_ABI_SUFFIX
#endif
 
#ifndef MAGICKCORE_SHAREARCH_PATH
#  define MAGICKCORE_SHAREARCH_PATH MAGICKCORE_LIBRARY_PATH MAGICKCORE_DIR_SEPARATOR MAGICKCORE_SHAREARCH_DIRNAME MAGICKCORE_DIR_SEPARATOR
#endif
 
#ifndef MAGICKCORE_SHAREARCH_RELATIVE_PATH
#define MAGICKCORE_SHAREARCH_RELATIVE_PATH MAGICKCORE_LIBRARY_RELATIVE_PATH MAGICKCORE_DIR_SEPARATOR MAGICKCORE_SHAREARCH_DIRNAME
#endif

#endif
 
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif
 
#endif