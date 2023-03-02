#pragma once
#if defined(__gl_h_) || defined(__GL_H__)
#error gl.h included before glew.h
#endif
#if defined(__glext_h_) || defined(__GLEXT_H_)
#error glext.h included before glew.h
#endif
#if defined(__gl_ATI_h_)
#error glATI.h included before glew.h
#endif