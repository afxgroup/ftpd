#ifndef POLL_H
#define POLL_H

/* Type used for the number of file descriptors.  */
typedef unsigned long int nfds_t;

/* Data structure describing a polling request.  */
struct pollfd
{
    int fd;        /* File descriptor to poll.  */
    short int events;  /* Types of events poller cares about.  */
    short int revents; /* Types of events that actually occurred.  */
};

/* Event types that can be polled for.  These bits may be set in `events'
   to indicate the interesting event types; they will appear in `revents'
   to indicate the status of the file descriptor.  */
#define POLLIN      0x001       /* There is data to read.  */
#define POLLPRI     0x002       /* There is urgent data to read.  */
#define POLLOUT     0x004       /* Writing now will not block.  */
#define POLLRDNORM  0x040       /* Normal data may be read.  */
#define POLLRDBAND  0x080       /* Priority data may be read.  */
#define POLLWRNORM  0x100       /* Writing now will not block.  */
#define POLLWRBAND  0x200       /* Priority data may be written.  */
#define POLLERR     0x008       /* Error condition.  */
#define POLLHUP     0x010       /* Hung up.  */
#define POLLNVAL    0x020       /* Invalid polling request.  */

/* define is in "replace.h" */
int poll(struct pollfd *fds, nfds_t nfds, int timeout);
//#define poll repl_poll

#endif
