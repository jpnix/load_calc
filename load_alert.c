#include <stdio.h>
#include <stdlib.h>

void title()
{
    printf ("\033[0;32m");
	printf("\n");
	printf("▄▄▌         ▄▄▄· ·▄▄▄▄       ▄▄·  ▄▄▄· ▄▄▌   ▄▄·\n");
	printf("██•  ▪     ▐█ ▀█ ██▪ ██     ▐█ ▌▪▐█ ▀█ ██•  ▐█ ▌▪\n");
	printf("██▪   ▄█▀▄ ▄█▀▀█ ▐█· ▐█▌    ██ ▄▄▄█▀▀█ ██▪  ██ ▄▄\n");
	printf("▐█▌▐▌▐█▌.▐▌▐█ ▪▐▌██. ██     ▐███▌▐█ ▪▐▌▐█▌▐▌▐███▌\n");
	printf("▐█▌▐▌▐█▌.▐▌▐█ ▪▐▌██. ██     ▐███▌▐█ ▪▐▌▐█▌▐▌▐███▌\n");
	printf(".▀▀▀  ▀█▄▀▪ ▀  ▀ ▀▀▀▀▀•     ·▀▀▀  ▀  ▀ .▀▀▀ ·▀▀▀ \n");
	printf("\n");
	printf("\033[0m");
}

int sys_cores()
{
  FILE *proc;
  char core_val[3];

  proc = popen("/usr/bin/nproc", "r");
  while (fgets(core_val, sizeof(core_val), proc) != NULL) {}
  pclose(proc); 
  int cores = atoi(core_val);
  return cores;
}

int sys_load_avg()
{   
    int c;
	FILE *load_avg_file = fopen("/proc/loadavg","r");
    if(load_avg_file == NULL) 	 
	{ 		   
		printf("/proc/loadavg does not exist on this system\n"); 	   
		return 1; 	 
	} 	 
	else 	 
	{ 	
        printf("\n");
        printf("Current Load average of this system is:\n");	 
		while ((c = getc(load_avg_file)) != EOF) 	     
		putchar(c);
        printf("\n"); 	 
	} 	
	fclose(load_avg_file);
	return 0;
}

int high_load_defs(int num_cores)
{   
    printf ("Total number of system cores is %d\n", num_cores);
    printf ("#################################\n");
    printf ("\n");
    printf ("System Load should alert with a ");
    printf ("\033[0;33m");
    printf ("warning");
    printf("\033[0m");
    printf(" for anything above ");
    printf ("\033[0;33m");
    printf("%.2f %.2f %.2f\n", num_cores - 0.5, num_cores - 0.6, num_cores - 0.7);
    printf("\033[0m");
    printf ("System Load should alert with a "); 
    printf("\033[0;31m");
    printf("critical "); 
    printf("\033[0m");
    printf("for anything above ");
    printf("\033[0;31m");
    printf("%.2f\n", num_cores - 0.2);
    printf("\033[0m");
    printf ("\n");
}

int main()
{
    title();
    sys_load_avg();
    high_load_defs(sys_cores());
    return 0;
}

