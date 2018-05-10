/**
	@file
	@author Florian Evaldsson
	
	@section LICENSE
	
	Copyright (c) 2015 Florian Evaldsson <florian.evaldsson@telia.com>


	Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
	
	@section DESCRIPTION

	Helpful functions to the main file.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include <gnumake.h>

int a_vasprintf (char **str, const char *fmt, va_list args)
{
	int size = 0;
	va_list tmpa;

	va_copy(tmpa, args);

	size = vsnprintf(NULL, size, fmt, tmpa);

	va_end(tmpa);

	if (size < 0)
	{
		return -1;
	}

	*str = gmk_alloc(size + 1);

	if (NULL == *str)
	{
		return -1;
	}

	size = vsprintf(*str, fmt, args);
	
	return size;
}

int a_asprintf (char **str, const char *fmt, ...)
{
	int size = 0;
	va_list args;

	va_start(args, fmt);

	size = a_vasprintf(str, fmt, args);

	va_end(args);

	return size;
}

char *a_strdup(char *str)
{
	size_t str_len=strlen(str);
	
	size_t total_size=str_len + 1;
	
	char *ret=gmk_alloc(total_size);

	if(ret == NULL)
	{
		return NULL;
	}
	
	strcpy(ret,str);
	
	return ret;
}
