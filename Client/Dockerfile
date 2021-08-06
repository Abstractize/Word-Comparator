FROM rikorose/gcc-cmake as builder

COPY . /usr/src/app

WORKDIR /usr/src/app

RUN cmake .
RUN cmake --build ./

FROM ubuntu:latest AS runtime

COPY --from=builder /usr/src/app/Client /usr/src/app/

WORKDIR /usr/src/app

CMD ["./Client"]
