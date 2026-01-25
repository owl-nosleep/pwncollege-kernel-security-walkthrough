#!/bin/sh

gcc attack.c -static -o attack
scp ./attack hacker@dojo.pwn.college:~
