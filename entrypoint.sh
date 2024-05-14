#!/bin/sh

# Start the flag exchange program with socat to listen on port 9000
socat TCP-LISTEN:9000,reuseaddr,fork EXEC:"./flag_exchange"
