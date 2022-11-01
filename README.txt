

Commands to run code:
    gcc producer.c -pthread -lrt -o producer

    gcc consumer.c -pthread -lrt -o consumer

    ./producer & ./consumer




Example output:
Consuming
Producing
Table slot number 1 is filled
Consuming
Producing
Table slot number 1 is filled
Consuming
Table slot number 1 empty
Producing
Table slot number 1 is filled
Consuming
Table slot number 1 empty
Producing
Table slot number 1 is filled
Consuming
Table slot number 1 empty
Producing
Table slot number 1 is filled
