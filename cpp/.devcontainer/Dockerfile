FROM mcr.microsoft.com/devcontainers/base:ubuntu-24.04

RUN apt-get update \
    && apt-get install -y \
        build-essential \
        gdb \
        clang \
        clang-format \
        clang-tidy \
        lldb \
        pkg-config \
    && rm -rf /var/lib/apt/lists/*