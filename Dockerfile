# syntax=docker/dockerfile:1
FROM ubuntu:22.04 AS build
WORKDIR /app

RUN apt update && apt install -y \
    build-essential \
    cmake \
    g++

COPY . .

RUN cmake -S . -B build && cmake --build build

FROM ubuntu:22.04 AS release
WORKDIR /app

RUN apt update && apt install -y cmake

COPY --from=build /app/build /app/build

CMD ["ctest", "--test-dir", "build", "--output-on-failure"]
