The objective of this project was to demonstrate an
understanding of several concepts. Such as shared memory,
semaphores, and threads. This project demonstrates the product
consumer problem, where there is a table with 2 slots, and a
producer places items on it, and the consumer removes them.


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
