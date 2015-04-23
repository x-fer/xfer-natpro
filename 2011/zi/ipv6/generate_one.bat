@echo off
ipv6_gen.py %1 -b %2 -r %3 -p %4 -l %5 > ipv6.in.%6
ipv6.exe < ipv6.in.%6 > ipv6.out.%6
