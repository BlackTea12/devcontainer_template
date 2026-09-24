ARG UBUNTU_VERSION=24.04
FROM mcr.microsoft.com/devcontainers/base:ubuntu-${UBUNTU_VERSION}

ARG ROS_DISTRO=jazzy
ENV ROS_DISTRO=${ROS_DISTRO}

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        curl \
        gnupg \
        software-properties-common \
    && add-apt-repository -y universe \
    && curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key \
        -o /usr/share/keyrings/ros-archive-keyring.gpg \
    && echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo ${UBUNTU_CODENAME}) main" \
        > /etc/apt/sources.list.d/ros2.list \
    && apt-get update \
    && apt-get install -y \
        ros-${ROS_DISTRO}-desktop \
        ros-dev-tools \
        build-essential \
        gdb \
        clang \
        clang-format \
        clang-tidy \
        lldb \
        pkg-config \
        mesa-utils \
        x11-apps \
    && rosdep init \
    && rm -rf /var/lib/apt/lists/*

RUN echo "source /opt/ros/${ROS_DISTRO}/setup.bash" >> /root/.bashrc
