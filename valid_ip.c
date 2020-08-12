/* valid_ip.c
* To validate IPv4 ip address and port num
* <ip_addr>:<port_num>
*
*  run with command line args <executable> <ip_addr>:<portno>
*
*    Author:Kapil
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define IPADDR 1
#define PORTNUM 2

#define SUCCESS 0
#define FAIL -1

#define MIN_PORTNO 1
#define MAX_PORTNO 65535

int validate_ip_addr(char *ip_addr)
{
    char *split_str;
    int count = 0;
    int temp_ip=0;
    int status = 0;

   /*Separating ipaddr and portno from <ipaddr>:<portno> format*/    
    split_str = strtok(ip_addr,".");

    while (split_str != NULL)
    {
        status = FAIL;

        printf("\nsplit_str:%s", split_str);

        if(count > 3)
            break;

        temp_ip = atoi(split_str);

        if(temp_ip>0 && temp_ip < 256)
        {
            status = SUCCESS;
        }

        split_str = strtok (NULL, ".");
        count++;
 
    }
    printf("\ncount value:%d",count);

    if (count < 4)
        status = FAIL;

    return status;
}


int main(int argc, char** argv)
{
    char *split_str;
    char *ip_addr;
    char *port_num;
    int count = 1;
    int portno = 0;

    if(argc !=2)
    {
        printf("Invalid entry");
        exit(-1);
    }
   /*Separating ipaddr and portno from <ipaddr>:<portno> format*/    
    split_str = strtok(argv[1],":");

    while (split_str != NULL)
    {
        printf("\nsplit_str:%s", split_str);
        switch (count)
        {
            case IPADDR:
                ip_addr = malloc(strlen(split_str)+1);
                strncpy(ip_addr,split_str,strlen(split_str)+1);
                ip_addr[strlen(split_str)]='\0';
            break;

            case PORTNUM:
                port_num = malloc(strlen(split_str)+1);
                strncpy(port_num,split_str,strlen(split_str)+1);
                port_num[strlen(split_str)]='\0';
            break;

            default:
            break;
        }
        split_str = strtok (NULL, ":");
        count++; 
    }

    /* Validation of ip address and port number TODO: IP address is valid*/
    if (port_num == NULL || ip_addr == NULL)
    {
        printf("Incorrect IP addr and port input");
    }
    else
    {
        printf("\nipaddr:%s, port num:%s",ip_addr, port_num);

        portno = atoi(port_num);
        
        if (portno < MIN_PORTNO || portno > MAX_PORTNO)
        {
            printf("\nportnumber invalid");
            exit(-1);
        }
        if(validate_ip_addr(ip_addr) == 0)
        {
            printf("\nip address valid");
        }
        else
        {
            printf("\nip_address invalid");
        }
    }

    free(ip_addr);
    free(port_num);
}
