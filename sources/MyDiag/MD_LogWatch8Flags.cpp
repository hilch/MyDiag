/*

https://github.com/hilch/MyDiag

Helper Library for ACOPOStrak diagnosis

MIT License

Copyright (c) 2022 https://github.com/hilch

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "MyDiag.h"
#ifdef __cplusplus
	};
#endif

#include <bur/plctypes.h>
#include <cstring>
#include <cstdio>

#include <cctype>
#include <algorithm>


#define STARTUP 0
#define CHECK_SIGNAL 10
#define W_DONE 20
#define ERROR 9999

/* Write status of 8 flags variable into log */
void MD_LogWatch8Flags(struct MD_LogWatch8Flags* inst)
{
	if( inst->Enable ){
		for(;;){
			switch( inst->step ){
				case STARTUP: /* startup */
				inst->Busy = false;
				inst->Valid = false;
				inst->Error = false;
				inst->ErrorID = 0;
				std::memset( &inst->fbLogWrite, 0, sizeof(inst->fbLogWrite) );
				std::strcpy( (char*) inst->fbLogWrite.Name, (char*) inst->LogName );
				MD_LogWrite( &inst->fbLogWrite ); /* reset fb */
				inst->signalOld = ~inst->Signal; /* force writing when fb is enabled */
				inst->step = CHECK_SIGNAL;
				continue; /* save one cycle */
	
	
				case CHECK_SIGNAL: /* check signal */
				inst->Valid = true;
				if( inst->Signal != inst->signalOld){
					std::strcpy( (char*) inst->fbLogWrite.ObjectID, (char*) inst->SignalName );
					std::strcpy( (char*) inst->fbLogWrite.Ascii, "" );
					for( int n = 7; n>=0 ; --n ){
						if( inst->Flag[n][0] ){  /* flag used ? */
							char f[sizeof(inst->Flag[0])];
							bool bit = !!(inst->Signal & 1<<n);
							bool bitOld = !!(inst->signalOld & 1<<n);
	
							std::memset( (void*) &f, 0, sizeof(f) );
							/* use upper case letters for TRUE and lower case for FALSE */
							if( bit ) {
								std::transform( &inst->Flag[n][0], &inst->Flag[n][8], f, std::toupper );
							}
							else {
								std::transform( &inst->Flag[n][0], &inst->Flag[n][8], f, std::tolower );
							}
							/* add a star '*' as prefix if flag was changed */
							if( bit != bitOld ){
								std::strcat( (char*) inst->fbLogWrite.Ascii, "*" );
							}
							else {
								std::strcat( (char*) inst->fbLogWrite.Ascii, " " );
							}
							std::strcat( (char*) inst->fbLogWrite.Ascii, f );
							std::strcat( (char*) inst->fbLogWrite.Ascii, " " );
						}
					}
					inst->signalOld = inst->Signal;
					inst->fbLogWrite.EventID = inst->EventID;
					inst->fbLogWrite.Execute = true;
					inst->Valid = false;
					inst->Busy = true;
					MD_LogWrite( &inst->fbLogWrite );
					inst->step = W_DONE;
				}			
				break;
	
	
				case W_DONE:
				if( inst->fbLogWrite.Done ){
					inst->Busy = false;
					inst->Error = false;
					inst->Valid = true;
					inst->fbLogWrite.Execute = 0; /* reset fb */
					MD_LogWrite( &inst->fbLogWrite );
					inst->step = CHECK_SIGNAL;
					continue; /* save one cycle */
				}
				else if( inst->fbLogWrite.Error ){
					inst->Busy = false;
					inst->Valid = false;
					inst->Error = true;
					inst->ErrorID = inst->fbLogWrite.ErrorID;
					inst->fbLogWrite.Execute = 0; /* reset fb */
					MD_LogWrite( &inst->fbLogWrite );
					inst->step = ERROR;				
				}
				else {
					MD_LogWrite( &inst->fbLogWrite );
				}
				break;
				
	
				case ERROR: /* error */
				break;
	
			}
			break; /* leave endless loop */
		} /* end for(;;) */
	}
	else {
		inst->Busy = false;
		inst->Valid = false;
		inst->ErrorID = 0;
		inst->Error = false;
		inst->step = STARTUP;
	}
}
