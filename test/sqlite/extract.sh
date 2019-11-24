#!/bin/bash

gcc -g $1 -o mainapp `pkg-config --cflags --libs glib-2.0` -lsqlite3

