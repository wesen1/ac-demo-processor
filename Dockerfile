FROM debian:buster-slim as builder
RUN apt-get update && \
    apt-get install -y make gcc g++ clang && \
    apt-get install -y libsdl-image1.2-dev libsdl1.2-dev zlib1g-dev libogg-dev libvorbis-dev libopenal-dev libcurl4-openssl-dev libcjson-dev
COPY ./source /source
RUN cd /source/src && \
    make client


FROM debian:buster-slim
COPY --from=builder /source/src/ac_client /ac-demo-processor/ac-demo-processor
RUN apt-get update && \
    apt-get install -y libsdl1.2debian libsdl-image1.2 zlib1g libogg0 libvorbis0a libopenal1 libcurl4 && \
    apt-get install -y libgl1 libvorbisfile3 libcjson1
WORKDIR /ac-demo-processor
ENTRYPOINT [ "./ac-demo-processor" ]
