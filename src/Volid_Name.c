/* 	Drive volume id serial generator that works with 
	Windows Systernals VolumeID v.2.0
	http://technet.microsoft.com/en-us/sysinternals/bb897436.aspx
	
	- Generates random volume serial number and runs it as a system command
	- Generates random computer name and runs it as a system command
	- If computer name is 'XPPC' then automatically reboot the computer after 10 seconds
	
	tcc -o makeid.exe Volid_Name.c
	
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void rand_volid(char * str, unsigned long len)
{
srand((unsigned int) time(0));	// seed number for rand
   
const char *chars = "01A2B3C4D5E6F789";	//char map for volume id
unsigned int max = strlen( chars );
unsigned long i = 0L;

for ( ; i < len - 2L; ++i ) {
str[ i ] = chars[ rand() % max ];
}
str[ i++ ] = '\n';
str[ i ] = '\0';  
}

void rand_pcName(char * str, unsigned long len)
{
srand((unsigned int) time(0));	// seed number for rand
   
const char *chars = "AEIOUTNRSDLFM";	// char map for pc name
unsigned int max = strlen( chars );
unsigned long i = 0L;

for ( ; i < len - 2L; ++i ) {
str[ i ] = chars[ rand() % max ];
}
str[ i++ ] = '\n';
str[ i ] = '\0';  
}

int main(void)
{
  char aVolid[10];		// volume id random array
  char aCompName[10];		// computer name random array
  rand_volid(aVolid, 10);
  rand_pcName(aCompName, 10);
  printf("volumeid C: %.4s-%.4s \n", aVolid, &aVolid[4]);
  printf("New PC Name: %.8s-PC \n", aCompName);
    
  char cmdVolid[32];	// create array to store volume id command 
  sprintf(cmdVolid, "volumeid C: %.4s-%.4s \n", aVolid, &aVolid[4]);
  system(cmdVolid);	// run the system command stored in the array
  
  char cmdPCname[128];	// create array to store computer name command 
  sprintf(cmdPCname, "wmic computersystem where name=\"%%computername%%\" call rename name=\"%.8s-PC\" \n", aCompName);
  system(cmdPCname);	// run the system command stored in the array 

  char cmdChkName[128];	// checks to see if VMWare computer name is default. If it is, then reboot in 10 seconds
  sprintf(cmdPCname, "if %%computername%%==XPPC (shutdown -r -t 10 -c \"Rebooting in 10 seconds to apply changes\") else (echo .)");
  system(cmdPCname);	// run the system command stored in the array 
  
  return 0;
}
