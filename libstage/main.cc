/**
  \defgroup stage The Stage standalone robot simulator.

  Here is where I describe the Stage standalone program.
 */

#include <getopt.h>

#include "stage_internal.hh"

/* options descriptor */
static struct option longopts[] = {
	{ "gui",  no_argument,   NULL,  'g' },
	//  { "fast",  no_argument,   NULL,  'f' },
	{ NULL, 0, NULL, 0 }
};

int main( int argc, char* argv[] )
{
	//printf( "%s %s ", PROJECT, VERSION );

	int ch=0, optindex=0;
	bool usegui = true;

	while ((ch = getopt_long(argc, argv, "gf", longopts, &optindex)) != -1)
	{
		switch( ch )
		{
			case 0: // long option given
				printf( "option %s given", longopts[optindex].name );
				break;
			case 'g': 
				usegui = false;
				printf( "[GUI disabled]" );
				break;
			case '?':  
				break;
			default:
				printf("unhandled option %c\n", ch );
		}
	}

	puts("");// end the first start-up line

	// initialize libstage
	Stg::Init( &argc, &argv );

	// arguments at index optindex and later are not options, so they
	// must be world file names


	bool loaded_world_file = false;
	while( optindex < argc )
	{
		if( optindex > 0 )
		{      
			const char* worldfilename = argv[optindex];
			StgWorldGui* world = new StgWorldGui( 400, 300, worldfilename );
			world->Load( worldfilename );
			loaded_world_file = true;
		}
		optindex++;
	}

 	if( loaded_world_file == false ) {
 		// replace this with a loading dialog/window
 		StgWorldGui* world = new StgWorldGui( 400, 300 );
 	}

	
	while(true)
	  StgWorld::UpdateAll();	  
}

