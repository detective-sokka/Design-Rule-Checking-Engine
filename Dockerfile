FROM debian:trixie-slim

# Install build dependencies
RUN apt-get update && apt-get install -y \
    cmake \
    g++ \
    make \
    wget \
    unzip \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

CMD ["./build.sh"]
