FROM rikorose/gcc-cmake as builder

RUN apt install libulfius-dev uwsc

COPY . /usr/src/app

WORKDIR /usr/src/app

RUN cmake .
RUN cmake --build ./

FROM ubuntu:latest AS runtime

COPY --from=builder /usr/src/app/Server /usr/src/app/

WORKDIR /usr/src/app

CMD ["./Server"]
