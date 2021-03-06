/*
 * PuTTY version numbering
 */

/*
 * The difficult part of deciding what goes in these version strings
 * is done in Buildscr, and then written into version.h. All we have
 * to do here is to drop it into variables of the right names.
 */

#include "version.h"

#ifdef PERSOPORT
#include <string.h>
char ver[] = "Custom build" ;
char sshver[] = "PuTTY-KiTTY\0                        " ;

void set_sshver( const char * vers ) { strcpy( sshver, vers ) ; }
#else
char ver[] = TEXTVER;
char sshver[] = SSHVER;
#endif

/*
 * SSH local version string MUST be under 40 characters. Here's a
 * compile time assertion to verify this.
 */
enum { vorpal_sword = 1 / (sizeof(sshver) <= 40) };
