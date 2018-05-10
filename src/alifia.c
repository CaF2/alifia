/**
	@file
	@author Florian Evaldsson
	
	@section LICENSE
	
	Copyright (c) 2015 Florian Evaldsson <florian.evaldsson@telia.com>


	Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
	
	@section DESCRIPTION

	File containing all the functions
*/

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <locale.h>
#include <math.h>

#include <gnumake.h>
#include "gen/common.h"

int plugin_is_GPL_compatible;

/**
	A+B
*/
char *a_add(const char *nm, unsigned int argc, char **argv)
{
	double a=0, b=0;
/*	char *ap, *bp;*/
	char *result=NULL;
	
	if(argc!=2)
	{
		const char *res="E";
	
		result=gmk_alloc(sizeof(res));
		memcpy(result,res,strlen(res));
		
		return result;
	}
	
/*	printf("REC:: %s %s\n",argv[0],argv[1]);*/
/*	*/
/*	a=strtoll(argv[0],&ap,10);*/
/*	b=strtoll(argv[1],&bp,10);*/
/*	*/
/*	printf("REC:: %lld %lld\n",a,b);*/
/*	*/
/*	//double*/
/*	if(*ap=='.')*/
/*	{*/
/*		long long a2=0, b2=0;*/
/*		char *ap2, *bp2;*/
/*		double ad=0, bd=0;*/
/*		*/
/*		a=strtoll(ap+1,&ap2,10);*/
/*		b=strtoll(ap+1,&bp2,10);*/
/*		*/
/*		int al=ap2-ap;*/
/*		int bl=bp2-bp;*/
/*		*/
/*		printf("yes");*/
/*	}*/
/*	*/
/*	a_asprintf(&result,"%lld",a+b);*/
	
	setlocale (LC_ALL, "C");
	
	a=strtof(argv[0],NULL);
	b=strtof(argv[1],NULL);
	
	printf("%s %f\n",argv[0],a);
	
	a_asprintf(&result,"%f",a+b);
	
	return result;
}

/**
	Will return A-B
*/
char *a_sub(const char *nm, unsigned int argc, char **argv)
{
	double a=0, b=0;
	char *result=NULL;
	
	if(argc!=2)
	{
		const char *res="E";
	
		char *ptr=gmk_alloc(sizeof(res));
		memcpy(ptr,res,strlen(res));
		
		return ptr;
	}
	
	setlocale (LC_ALL, "C");
	
	a=strtof(argv[0],NULL);
	b=strtof(argv[1],NULL);
	
	a_asprintf(&result,"%f",a-b);
	
	return result;
}

/**
	Will return A*B
*/
char *a_mul(const char *nm, unsigned int argc, char **argv)
{
	double a=0, b=0;
	char *result=NULL;
	
	if(argc!=2)
	{
		const char *res="E";
	
		char *ptr=gmk_alloc(sizeof(res));
		memcpy(ptr,res,strlen(res));
		
		return ptr;
	}
	
	setlocale (LC_ALL, "C");
	
	a=strtof(argv[0],NULL);
	b=strtof(argv[1],NULL);
	
	a_asprintf(&result,"%f",a*b);
	
	return result;
}

/**
	Will return A*B
*/
char *a_pow(const char *nm, unsigned int argc, char **argv)
{
	double a=0, b=0;
	char *result=NULL;
	
	if(argc!=2)
	{
		const char *res="E";
	
		char *ptr=gmk_alloc(sizeof(res));
		memcpy(ptr,res,strlen(res));
		
		return ptr;
	}
	
	setlocale (LC_ALL, "C");
	
	a=strtof(argv[0],NULL);
	b=strtof(argv[1],NULL);
	
	a_asprintf(&result,"%f",pow(a,b));
	
	return result;
}

/**
	Logical or.
*/
char *a_or(const char *nm, unsigned int argc, char **argv)
{
	long long a=0, b=0;
	char *result=NULL;
	
	if(argc!=2)
	{
		const char *res="E";
	
		char *ptr=gmk_alloc(sizeof(res));
		memcpy(ptr,res,strlen(res));
		
		return ptr;
	}
	
	setlocale (LC_ALL, "C");
	
	a=strtoll(argv[0],NULL,10);
	b=strtoll(argv[1],NULL,10);
	
	a_asprintf(&result,"%lld",a|b);
	
	return result;
}

/**
	Logical and.
*/
char *a_and(const char *nm, unsigned int argc, char **argv)
{
	long long a=0, b=0;
	char *result=NULL;
	
	if(argc!=2)
	{
		const char *res="E";
	
		char *ptr=gmk_alloc(sizeof(res));
		memcpy(ptr,res,strlen(res));
		
		return ptr;
	}
	
	a=strtoll(argv[0],NULL,10);
	b=strtoll(argv[1],NULL,10);
	
	a_asprintf(&result,"%lld",a&b);
	
	return result;
}

/**
	Logical xor.
*/
char *a_xor(const char *nm, unsigned int argc, char **argv)
{
	long long a=0, b=0;
	char *result=NULL;
	
	if(argc!=2)
	{
		const char *res="E";
	
		char *ptr=gmk_alloc(sizeof(res));
		memcpy(ptr,res,strlen(res));
		
		return ptr;
	}
	
	setlocale (LC_ALL, "C");
	
	a=strtoll(argv[0],NULL,10);
	b=strtoll(argv[1],NULL,10);
	
	a_asprintf(&result,"%lld",a^b);
	
	return result;
}

/**
	Logical mod.
*/
char *a_mod(const char *nm, unsigned int argc, char **argv)
{
	long long a=0, b=0;
	char *result=NULL;
	
	if(argc!=2)
	{
		const char *res="E";
	
		char *ptr=gmk_alloc(sizeof(res));
		memcpy(ptr,res,strlen(res));
		
		return ptr;
	}
	
	a=strtoll(argv[0],NULL,10);
	b=strtoll(argv[1],NULL,10);
	
	a_asprintf(&result,"%lld",a%b);
	
	return result;
}

/**
	Logical to float.
*/
char *a_tof(const char *nm, unsigned int argc, char **argv)
{
	long long a=0;
	char *result=NULL;
	
	if(argc!=1)
	{
		const char *res="E";
	
		char *ptr=gmk_alloc(sizeof(res));
		memcpy(ptr,res,strlen(res));
		
		return ptr;
	}
	
	setlocale (LC_ALL, "C");
	
	a=strtof(argv[0],NULL);
	
	a_asprintf(&result,"%f",(double)a);
	
	return result;
}

/**
	Logical to float.
*/
char *a_toi(const char *nm, unsigned int argc, char **argv)
{
	long long a=0;
	char *result=NULL;
	
	if(argc!=1)
	{
		const char *res="E";
	
		char *ptr=gmk_alloc(sizeof(res));
		memcpy(ptr,res,strlen(res));
		
		return ptr;
	}
	
	setlocale (LC_ALL, "C");
	
	a=strtof(argv[0],NULL);
	
	a_asprintf(&result,"%lld",(long long)a);
	
	return result;
}

/**
	Check if file is compiled, will return @arg1
	
	@arg0
		Path to the makefile (with/without makefile name)
	@arg1
		Path relative that makefile (or target in the makefile to check)
*/
char *a_check_target(const char *nm, unsigned int argc, char **argv)
{
	char *dir=argv[0];
	char *file=argv[1];

/*	printf("FILE:: %s %s\n",dir,file);*/

	int number, statval;
	int child_pid;
/*	printf("%d: I'm the parent !\n", getpid());*/
	child_pid = fork();
	if(child_pid == -1)
	{ 
		printf("could not fork! \n");
		return NULL;
	}
	else if(child_pid == 0)
	{
		FILE *silentfd = fopen("/dev/null","w");
		dup2(fileno(silentfd), STDOUT_FILENO);
		dup2(fileno(silentfd), STDERR_FILENO);
	
		char *params[] = {"/usr/bin/make", "-q", "-C" , dir, file, NULL};
	
		execv("/usr/bin/make",params);
	}
	else
	{
/*		printf("PID %d: waiting for child\n", getpid());*/
		if(waitpid(child_pid, &statval, 0) == -1)
		{
			printf("wait PID failed!\n");
			
			return NULL;
		}
		
		if(WIFEXITED(statval))
		{
			int exitcode=WEXITSTATUS(statval);
		
/*			printf("Child's exit code %d\n", exitcode);*/
			
			if(exitcode==1)
			{
				return a_strdup(argv[1]);
			}
			else
			{
				return a_strdup("");
			}
		}
		else
		{
			printf("Child did not terminate with exit\n");
		}
	}
	return NULL;
}

/**
	Get root directory
	
	@arg0
		Path to a recognizer of the directory, like:
		./.git
		Will iterate upwards until it finds something called .git,
		if it doesnt find anything, returns NOTHING
*/
char *a_get_root_dir(const char *nm, unsigned int argc, char **argv)
{
	char *curr_dir=NULL;
	size_t curr_dir_size=0;
	char *filename=NULL;
	
	FILE *data_stream=open_memstream(&curr_dir,&curr_dir_size);
	
	int found_dir=0;
	
	fprintf(data_stream,"./");
	
	while(found_dir==0)
	{
		fflush(data_stream);
		
		a_asprintf(&filename,"%s%s",curr_dir,argv[0]);
		
		found_dir = access( filename, F_OK ) != -1;
		
		if(found_dir==0)
		{
			free(filename);
			
			char *real_path = realpath( curr_dir, NULL );
			
			if(strcmp(real_path,"/")==0)
			{
				free(real_path);
				return strdup("");
			}
			
			free(real_path);
			
			fprintf(data_stream,"../");
		}
	}
	
	free(filename);
	
	return curr_dir;
}

/**
	Get abs root directory
	
	@arg0
		Path to a recognizer of the directory, like:
		./.git
		Will iterate upwards until it finds something called .git,
		if it doesnt find anything, returns NOTHING
*/
char *a_get_abs_root_dir(const char *nm, unsigned int argc, char **argv)
{
	char *path=a_get_root_dir(nm,argc,argv);
	
	char *real_path = realpath( path, NULL );
	
	free(path);
	
	return real_path;
}

int alifia_gmk_setup ()
{
	/* Register the function with make name "mk-temp".  */
	gmk_add_function ("aadd", a_add, 2, 2, 1);
	gmk_add_function ("asub", a_sub, 2, 2, 1);
	gmk_add_function ("amul", a_mul, 2, 2, 1);
	gmk_add_function ("apow", a_pow, 2, 2, 1);
	
	gmk_add_function ("aor", a_or, 2, 2, 1);
	gmk_add_function ("aand", a_and, 2, 2, 1);
	gmk_add_function ("axor", a_xor, 2, 2, 1);
	gmk_add_function ("amod", a_mod, 2, 2, 1);
	
	gmk_add_function ("atof", a_tof, 1, 1, 1);
	gmk_add_function ("atoi", a_toi, 1, 1, 1);
	
	gmk_add_function ("actarget", a_check_target, 2, 2, 1);
	gmk_add_function ("agetroot", a_get_root_dir, 1, 1, 1);
	gmk_add_function ("agetabsroot", a_get_abs_root_dir, 1, 1, 1);
	return 1;
}

