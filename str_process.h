// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Please DO NOT modify this header file!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#ifndef STR_PROCESS_H
#define STR_PROCESS_H

#ifndef MAX_STR_LEN
#define MAX_STR_LEN 101
#endif

#ifndef MAX_STR_COUNT
#define MAX_STR_COUNT 10
#endif

int split_c(const char* src, const char sp, char dst[MAX_STR_COUNT][MAX_STR_LEN]);

int split_s(const char* src, const char* sp, char dst[MAX_STR_COUNT][MAX_STR_LEN]);

int startswith(const char* str, const char* p);

int endswith(const char* str, const char* p);

void swapcase(const char* src, char* dst);

void lstrip(const char* src, char* dst);

void rstrip(const char* src, char* dst);

void strip(const char* src, char* dst);

void replace(const char* src, const char* old_pat, const char* new_pat,
             char* dst, int g);
int test(const char* old_pat, const char* src, int olen, int slen,int i);

void format(const char* fmt, const int argc, char** args, char* dst);

#endif // STR_PROCESS_H
