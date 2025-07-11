/*=============================================================================
  Copyright (C) 2012 Allied Vision Technologies.  All Rights Reserved.

  Redistribution of this file, in original or modified form, without
  prior written consent of Allied Vision Technologies is prohibited.

-------------------------------------------------------------------------------

  File:        program.cpp

  Description: Main entry point of ListCameras example of VimbaC.

-------------------------------------------------------------------------------

  THIS SOFTWARE IS PROVIDED BY THE AUTHOR "AS IS" AND ANY EXPRESS OR IMPLIED
  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF TITLE,
  NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR  PURPOSE ARE
  DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
  AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
  TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <ListCameras.h>

char genpath[] = "GENICAM_GENTL64_PATH=" BINPATH;

int main( int argc, char* argv[] )
{
    printf( "//////////////////////////////////////\n" );
    printf( "/// Vimba API List Cameras Example ///\n" );
    printf( "//////////////////////////////////////\n\n" );

    if (!getenv("GENICAM_GENTL64_PATH"))
        putenv(genpath);

    if ( 1 < argc )
    {
        printf( "No parameters expected. Execution will not be affected by the provided parameter(s).\n\n" );
    }
    
    ListCameras();
    
    return 0;
}
