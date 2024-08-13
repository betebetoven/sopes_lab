#!/bin/bash

# Number of containers to create
NUM_CONTAINERS=10

# Loop to create containers
for i in $(seq 1 $NUM_CONTAINERS)
do
  # Generate a random name for the container
  CONTAINER_NAME=$(openssl rand -hex 3)
  
  # Run a container with the alpine image
  docker run -d --name "container_$CONTAINER_NAME" alpine sleep 3600

  # Print the name of the container that was created
  echo "Created container: container_$CONTAINER_NAME"
done
