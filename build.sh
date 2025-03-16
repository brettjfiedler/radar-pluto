#!/bin/bash

# Build the image
docker build -t airband-pluto-dev-container -f docker/Dockerfile . || exit 1

# Extract the binary we built
container_id=$(docker create airband-pluto-dev-container)
echo $container_id
docker cp $container_id:/plutosdr/src/airband airband
docker rm -f $container_id

# Copy our binary to the pluto
#scp airband root@pluto.local:/root && echo "analog"

sshpass -p 'analog' scp airband root@pluto.local:/root
