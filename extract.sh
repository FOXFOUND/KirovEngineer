#!/bin/bash

gcc -g $1 -o mainapp `pkg-config --cflags --libs gtk+-2.0` -lcurl 
