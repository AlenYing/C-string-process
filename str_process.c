#include "str_process.h"

int split_c(const char* src, const char sp, char dst[MAX_STR_COUNT][MAX_STR_LEN])
{
	/*
	todo:¿Õ×Ö·ûÎ´Ð´Èë 
	*/
	 // Insert you code here ...
	int n = 1;
	int slen = 0;
	int temp = 0;
	int Isin = 0;
	int i;
	for (i = 0;; i++)
	{
		if (src[i] == '\0') break;
		slen += 1;
	}
	for (i = 0; i < slen; i++)
	{
		if (src[i] == sp)
		{
			temp = 0;
			n += 1;
			continue;
			Isin = 1;
		}
		dst[n - 1][temp] = src[i];
		temp += 1;
		dst[n - 1][temp + 1] = '\0';
	}
	return n;
}

int split_s(const char* src, const char* sp, char dst[MAX_STR_COUNT][MAX_STR_LEN]) 
{
	int i=0;
    int n = 1;
	int slen = 0;
	int sslen = 0;
	int temp = 0;
	int Isin = 0;
	for (i = 0;; i++)
	{
		if (src[i] == '\0') break;
		slen += 1;
	}
	for (i = 0;; i++)
	{
		if (sp[i] == '\0') break;
		sslen += 1;
	}
	for (i = 0; i < slen; i++)
	{
		if (src[i] == sp[0])
		{
			temp = 0;
			n += 1; 
			Isin = 1;
			i += sslen-1;
			continue;
			
		}
		dst[n - 1][temp] = src[i];
		temp += 1;
		dst[n - 1][temp + 1] = '\0';
	}
	return n;
}

  int startswith(const char* str, const char* p)
{
	int plen = 0, slen = 0,i=0;
	for (i = 0;; i++)
	{
		if (str[i] == '\0') break;
		slen += 1;
	}
	for (i = 0;; i++)
	{
		if (p[i] == '\0') break;
		plen += 1;
	}
	for (i = 0; i < plen; i++)
	{
		if (str[i] != p[i]) return 0;
		else return 1;
	}
}

int endswith(const char* str, const char* p) {
  // Insert you code here ...
  int plen = 0, slen = 0,i=0;
	for (i = 0;; i++)
	{
		if (str[i] == '\0') break;
		slen += 1;
	}
	for (i = 0;; i++)
	{
		if (p[i] == '\0') break;
		plen += 1;
	}
	for (i = slen - 1; i >slen-plen-1; i--)
	{
		if (str[i] != p[i + plen - slen]) return 0;
		else return 1;
	}
}

void swapcase(const char* src, char* dst) {
  // Insert you code here ...
  	int slen = 0,i=0;
	for (i = 0;; i++)
	{
		if (src[i] == '\0') break;
		slen += 1;
	}
	for (i = 0; i < slen; i++)
	{
		dst[i] = src[i];
		if (dst[i] >= 'A'&&dst[i] <= 'Z') dst[i] = dst[i] - 'A' + 'a';
		else if (dst[i] >= 'a'&&dst[i] <= 'z') dst[i] = dst[i] - 'a' + 'A';
		dst[i + 1] = '\0';
	}
}

void lstrip(const char* src, char* dst) {
  // Insert you code here ...
  	int slen = 0, scount = 0,i=0;
	for (i = 0;; i++)
	{
		if (src[i] == '\0') break;
		slen += 1;
	}
	for (i = 0;; i++)
	{
		if (src[i] != ' ') break;
		scount += 1;
	} //????????
	for (i = 0; i < slen; i++)
	{
		dst[i] = src[i + scount];
		dst[i + 1] = '\0';
	}
}

void rstrip(const char* src, char* dst) {
  // Insert you code here ...
  int slen = 0, scount = 0,i=0;
	for (i = 0;; i++)
	{
		if (src[i] == '\0') break;
		slen += 1;
	}
	for (i = slen-1;; i--)
	{
		if (src[i] != ' ') break;
		scount += 1;
	} 
	for (i = 0; i < slen; i++)
	{
		dst[i] = src[i];
	}		
	dst[slen - scount] = '\0';
}

void strip(const char* src, char* dst) {
  // Insert you code here ...
  int slen = 0, fscount = 0,bscount = 0,i=0;
	for (i = 0;; i++)
	{
		if (src[i] == '\0') break;
		slen += 1;
	}
	for (i = 0;; i++)
	{
		if (src[i] != ' ') break;
		fscount += 1;
	} 
	for (i = slen - 1;; i--)
	{
		if (src[i] != ' ') break;
		bscount += 1;
	} 
	for (i = 0; i < slen; i++)
	{
		dst[i] = src[i + fscount];
	}
	dst[slen - bscount] = '\0';
}

void replace(const char* src, const char* old_pat, const char* new_pat,
             char* dst, int g) {
  // Insert you code here ...
  //todo:Î´Ð´Èë±»Ìæ»»×Ö·û´®³¤¶È´óÓÚÌæ»»×Ö·ûÇé¿ö£¬ 
  int slen = 0, olen = 0, nlen = 0,i=0;
	for (i = 0;; i++)
	{
		if (new_pat[i] == '\0') break;
		nlen += 1;
	}
	for (i = 0;; i++)
	{
		if (old_pat[i] == '\0') break;
		olen += 1;
	}
	for (i = 0;; i++)
	{
		if (src[i] == '\0') break;
		slen += 1;
	}
	if (g == 1)
	{
		int meetTime = 0,i=0;
		for (i = 0; i < slen; i++)
		{
			dst[i] = src[i];
		}
		for (i = 0; i < slen; i++)
		{
			if (test(old_pat, src, olen, slen, i) == 1)
			{
				int k=0,j=0;
				for (k = slen + meetTime * (nlen - olen); k >i; k--)
				{

					dst[k + (nlen-olen)] = dst[k];
				}
				for (j = 0; j < nlen; j++)
				{
					dst[i + j + meetTime*(nlen -olen)] = new_pat[j];
				}
				meetTime += 1;
			}
		}
		dst[meetTime*(nlen - olen) + slen ] = '\0';
	}
	else if (g == 0)
	{
		int first = 0, i = 0;
		for (i = 0; i < slen; i++)
		{
			if (test(old_pat, src, olen, slen, i) == 1 && first == 0)
			{
				first = 1;
				int j = 0;
				for (j = 0; j < nlen; j++)
				{
					dst[i + j] = new_pat[j];
				}
			}
			dst[i + nlen] = src[i + olen];
		}
	}
}
int test(const char* old_pat, const char* src, int olen, int slen, int i)
{
	int equal = 0;
	if (src[i] == old_pat[0])
	{
		int j = 0;
		for (j = 0; j < olen; j++)
		{
			if (old_pat[j] == src[i + j]) equal = 1;
			else equal = 0;
		}
	}
	return equal;
}

void format(const char* fmt, const int argc, char** args, char* dst) {
  // Insert you code here ...
  	const char flag = '{';
	int addr = 0;
	int flen=0;
	int alen = 0;
	int temp = 0;
	int i=0;
	int FirstMeet = 0;
	for (i = 0;; i++)
	{
		if (fmt[i] == '\0') break;
		flen += 1;
	}
	for (i = 0;; i++)
	{
		if (args[0][i] == '\0') break;
		alen += 1;
	}
	for (i = 0; i < flen; i++)
	{
		if (fmt[i]==flag)
		{
			FirstMeet = 1;
			addr = (int)(fmt[i + 1]-'0');
			if (addr < argc)
			{
				int j=0;
				for (j = 0; j < alen; j++)
				{
					dst[i + j] = args[addr][j];
					temp += 1;
				}
			}
			else dst[i + 1] = fmt[i + 1];
		}
		else 
		{
			if (FirstMeet == 0)
			{
				dst[i + temp] = fmt[i + temp];
				temp = 0;
			}
			else if (FirstMeet == 1)
			{
				dst[i + temp] = fmt[i + temp];
				temp = 1;
			}
		}
	}
}
