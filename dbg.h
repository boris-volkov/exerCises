#ifndef __dbg_h__
#define __dbg_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>


#ifdef NDEBUG
#define debug(M, ...)
#else
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n",\
		__FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...) fprintf(stderr, \
		"[ERROR] (%s:%d errno: %s) " M "\n", __FILE__, __LINE__,\
		clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...) fprintf(stderr,\
		"[WARN] (%s:%d: errno: %s) " M "\n",\
		__FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n",\
		__FILE__, __LINE__, ##__VA_ARGS__)

#define check(A, M, ...) if (!(A)) {\
	log_err(M, ##__VA_ARGS__); errno=0; goto error; }

//checks if parts of a function that shouldnt be running, are.
#define sentinel(M, ...) { log_err(M, ##__VA_ARGS__);\
	errno=0; goto error; }

//checks if a pointer is valid
#define check_mem(A) check((A), "Out of memory.")

//doesnt report the error if it is a common one
#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__);\
	errno=0; goto error; }

#endif
