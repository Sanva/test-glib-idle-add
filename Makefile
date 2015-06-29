
CC = gcc

CFLAGS = -Wall			 	\
	-DG_DISABLE_DEPRECATED 	 	\
	-DGDK_DISABLE_DEPRECATED 	\
	-DGDK_PIXBUF_DISABLE_DEPRECATED \
	-DGTK_DISABLE_DEPRECATED

all: test test-glib-idle-add

test: test.c
	$(CC) test.c -o test $(DEPRECTATED) `pkg-config gtk+-3.0 --cflags --libs`

test-glib-idle-add: test-glib-idle-add.cs
	mcs -pkg:gtk-sharp-3.0 -pkg:gdk-sharp-3.0 test-glib-idle-add.cs

clean: 
	rm -f *.o test
