#!/bin/bash

PROJECT_ROOT="$(cd "$(dirname "$0")"; cd ..; pwd)"
source ${PROJECT_ROOT}/config.sh

docker exec -it ${DOCKER_CONTAINER_NAME} /bin/bash
