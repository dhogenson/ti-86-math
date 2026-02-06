FROM z88dk/z88dk

USER root
RUN apk add --no-cache python3

WORKDIR /app

COPY . .

CMD ["make"]
