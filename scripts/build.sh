#!/bin/bash

set -e

PROJECT_ROOT="$(cd "$(dirname "$0")"; cd ..; pwd)"
source "${PROJECT_ROOT}/config.sh"

docker build -f "${PROJECT_ROOT}/Dockerfile" -t ${DOCKER_IMAGE_NAME} .
