#ifndef LIBFILEFIND_GLOBAL_H
#define LIBFILEFIND_GLOBAL_H


#if defined(LIBFILEFIND_LIBRARY)
#  define LIBFILEFINDSHARED_EXPORT __declspec(dllexport)
#else
#  define LIBFILEFINDSHARED_EXPORT __declspec(dllimport)
#endif

#endif // LIBFILEFIND_GLOBAL_H
