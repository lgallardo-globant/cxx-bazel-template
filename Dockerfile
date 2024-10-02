FROM gcc

ARG TARGETARCH

RUN apt-get update && apt-get install -y \
    curl \
    gnupg \
    unzip \
    bash \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

RUN case "$TARGETARCH" in \
    "amd64") \
    echo "Installing Bazelisk for amd64 ..." && \
    curl -Lo /usr/local/bin/bazel https://github.com/bazelbuild/bazelisk/releases/download/v1.17.0/bazelisk-linux-amd64 && \
    chmod +x /usr/local/bin/bazel ;; \
    "arm64") \
    echo "Installing Bazelisk for arm..." && \
    curl -Lo /usr/local/bin/bazel https://github.com/bazelbuild/bazelisk/releases/download/v1.17.0/bazelisk-linux-arm64 && \
    chmod +x /usr/local/bin/bazel ;; \
    *) \
    echo "Unsupported architecture: $TARGETARCH" && exit 1 ;; \
    esac

RUN bazel --version

WORKDIR /workspace
