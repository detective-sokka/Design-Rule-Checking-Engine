FROM debian:latest

# Install build dependencies
RUN apt-get update && apt-get install -y \
    cmake \
    g++ \
    make 

WORKDIR /app

CMD ["./build.sh"]
