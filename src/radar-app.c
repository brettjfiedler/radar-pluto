
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>
#include <sys/time.h>
#include <signal.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <iio.h>
#include <ad9361.h>
#include "header_test.h"

#define MODES_DEFAULT_RATE         2000000
#define MODES_DEFAULT_FREQ         1090000000
#define MODES_DEFAULT_WIDTH        1000
#define MODES_DEFAULT_HEIGHT       700
#define MODES_ASYNC_BUF_NUMBER     12
#define MODES_DATA_LEN             (16*16384)   /* 256k */
#define MODES_AUTO_GAIN            -100         /* Use automatic gain. */
#define MODES_MAX_GAIN             70       /* Use max available gain. */



/* Structure used to describe an aircraft in iteractive mode. */
struct aircraft {
	uint32_t addr;      /* ICAO address */
	char hexaddr[7];    /* Printable ICAO address */
	char flight[9];     /* Flight number */
	int altitude;       /* Altitude */
	int speed;          /* Velocity computed from EW and NS components. */
	int track;          /* Angle of flight. */
	time_t seen;        /* Time at which the last packet was received. */
	long messages;      /* Number of Mode S messages received. */
	/* Encoded latitude and longitude as extracted by odd and even
	 * CPR encoded messages. */
	int odd_cprlat;
	int odd_cprlon;
	int even_cprlat;
	int even_cprlon;
	double lat, lon;    /* Coordinated obtained from CPR encoded data. */
	long long odd_cprtime, even_cprtime;
	struct aircraft *next; /* Next aircraft in our linked list. */
};

/* Program global state. */
struct {
	/* Internal state */
	pthread_t reader_thread;
	pthread_mutex_t data_mutex;     /* Mutex to synchronize buffer access. */
	pthread_cond_t data_cond;       /* Conditional variable associated. */
	unsigned char *data;            /* Raw IQ samples buffer */
	uint16_t *magnitude;            /* Magnitude vector */
	uint32_t data_len;              /* Buffer length. */
	int fd;                         /* --ifile option file descriptor. */
	int data_ready;                 /* Data ready to be processed. */
	uint32_t *icao_cache;           /* Recently seen ICAO addresses cache. */
	uint16_t *maglut;               /* I/Q -> Magnitude lookup table. */
	int exit;                       /* Exit from the main loop when true. */

	/* PLUTOSDR */
	int dev_index;
	int gain;
	int enable_agc;
	struct iio_context *ctx;
	struct iio_device *dev;
	long long freq;
	struct iio_channel *rx0_i;
	struct iio_channel *rx0_q;
	struct iio_buffer  *rxbuf;
	int stop;

} Modes;

int main(int argc, char **argv) {
	while(1){
		hello_func(13);
		sleep(3);
	}
	
	return 0;
}



