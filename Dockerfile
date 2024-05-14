# Use an official Ubuntu as a parent image
FROM ubuntu:latest

# Set environment variables to non-interactive for apt-get
ENV DEBIAN_FRONTEND=noninteractive

# Install necessary packages
RUN apt-get update && apt-get install -y \
    gcc \
    libc6-dev \
    make \
    socat

# Copy the C source file and entry point script into the container
COPY flag_exchange.c /usr/src/flag_exchange/
COPY flag.txt /usr/src/flag_exchange/
COPY entrypoint.sh /usr/src/flag_exchange/

# Set the working directory
WORKDIR /usr/src/flag_exchange/

# Compile the C program
RUN gcc -o flag_exchange flag_exchange.c

# Make the entry point script executable
RUN chmod +x entrypoint.sh

# Expose the desired port (e.g., 9000)
EXPOSE 9000

# Run the entry point script
ENTRYPOINT ["./entrypoint.sh"]
