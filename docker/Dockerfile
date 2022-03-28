FROM gcc:latest

WORKDIR /maze

COPY ./src/ ./src
COPY ./maps/ ./maps
WORKDIR ./src
RUN make

ENTRYPOINT ./main ../maps/rect_05.map
