FROM gcc:latest


WORKDIR /maze
COPY .. ./

WORKDIR /src

RUN make

CMD ["./main"]