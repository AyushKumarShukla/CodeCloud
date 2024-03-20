#include "sdkconfig.h"
#include "esp_netif.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_netif.h" //repetition?
#include "protocol_examples_common.h"
#include "esp_event.h"
#include "freertos/task.h"

#include <stdio.h>       // for printf
#include <sys/socket.h>  // for socket
#include <netdb.h>       // for gethostbyname
#include <unistd.h>      // for close
#include <string.h>      // for string manipulation
#include <errno.h>

static const char *TAG = "WHITERAVEN";
static const int ip_protocol = 0;
typedef struct sockaddr SA;

void tcp_socket_self(void)
{
	while(1)
	{
		// socket file descriptor - used by the program to ask the OS for TCP functionality
		int sockfd = socket(AF_INET,SOCK_STREAM,ip_protocol);
		if(sockfd < 0)
		{
			ESP_LOGE(TAG,"Socket Creation Failed: Error: %d",errno);
			return;
		}

		//setting up host information
		const char* hostname = "www.google.com";
		struct hostent *host = gethostbyname(hostname);
		if(host == NULL)
			return;

		//setting up sockaddr structure with server info
		struct sockaddr_in address;
		address.sin_family = AF_INET; // IPv4
		address.sin_port = htons(80); // port
		address.sin_addr.s_addr = *(in_addr_t*)host->h_addr; // server ip address
		
		//establish connection with the server
		int err = connect(sockfd,(SA*)&address,sizeof(address)); // returns 0 on success
		if(err != 0)
		{
			ESP_LOGE(TAG,"Socket Failed To Connect: %d",errno);
			return;
		}

		ESP_LOGI(TAG,"Connected Successfully");

		//create message to be sent to the sever
		char* msg;
		msg = "GET /search?q=OpenAI HTTP/1.1\r\nHost: www.google.com\r\nUser-Agent: ESP32\r\n\r\n";
		//send the message to the server
		send(sockfd,msg,strlen(msg),0);

		//receive response from the server
		char buffer[1024];
		recv(sockfd,buffer,1024,0);
		ESP_LOGI(TAG,"Response Received: %s\r\n",buffer);
		vTaskDelay(pdMS_TO_TICKS(3000));
		
		//shut the socket and close
		if(sockfd != -1)
		{
			ESP_LOGE(TAG,"Shutting Down Socket And Restarting........");
			shutdown(sockfd,0);
			close(sockfd);
		}	
			
	}
}
void app_main(void)
{
	ESP_ERROR_CHECK(nvs_flash_init());
	ESP_ERROR_CHECK(esp_netif_init());
	ESP_ERROR_CHECK(esp_event_loop_create_default());

	//configures network based on a example project given by the IDF
	ESP_ERROR_CHECK(example_connect()); 
	tcp_socket_self();
}
