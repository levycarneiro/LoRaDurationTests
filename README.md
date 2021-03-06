# LoRaDurationTests

A higher Spreading Factor and lower Bandwidth optime for longer range in LoRa communications, but they come with longer duration time for sending messages (and more energy use). Which begs the question: how much time does it take to send a LoRa message with different parameters?

Tests done with:

- Message = short "Hello" string. Note: the duration will increase with longer messages.
- Library = sandeepmistry's [LoRa Library](https://github.com/sandeepmistry/arduino-LoRa).
- CRC = disabled (library's default).
- Coding rate = 5 (library's default).
- Hardware = Heltec ESP32 LoRa v2 board with SX1276 chip.

| Spreading Factor | Bandwidth (KHz) | Duration (ms) |
| --- | --- | --- |
| 6 | 7.80 | 166 |
| 6 | 10.40 | 124 |
| 6 | 15.60 | 83 |
| 6 | 20.80 | 62 |
| 6 | 31.25 | 41 |
| 6 | 41.70 | 31 |
| 6 | 62.50 | 21 |
| 6 | 125.00 | 10 |
| 6 | 250.00 | 5 |
| 6 | 500.00 | 2 |
| 7 | 7.80 | 495 |
| 7 | 10.40 | 371 |
| 7 | 15.60 | 248 |
| 7 | 20.80 | 186 |
| 7 | 31.25 | 124 |
| 7 | 41.70 | 93 |
| 7 | 62.50 | 62 |
| 7 | 125.00 | 31 |
| 7 | 250.00 | 15 |
| 7 | 500.00 | 8 |
| 8 | 7.80 | 991 |
| 8 | 10.40 | 743 |
| 8 | 15.60 | 495 |
| 8 | 20.80 | 372 |
| 8 | 31.25 | 248 |
| 8 | 41.70 | 186 |
| 8 | 62.50 | 124 |
| 8 | 125.00 | 62 |
| 8 | 250.00 | 31 |
| 8 | 500.00 | 15 |
| 9 | 7.80 | 1982 |
| 9 | 10.40 | 1487 |
| 9 | 15.60 | 991 |
| 9 | 20.80 | 743 |
| 9 | 31.25 | 414 |
| 9 | 41.70 | 310 |
| 9 | 62.50 | 207 |
| 9 | 125.00 | 103 |
| 9 | 250.00 | 52 |
| 9 | 500.00 | 26 |
| 10 | 7.80 | 3309 |
| 10 | 10.40 | 2482 |
| 10 | 15.60 | 1655 |
| 10 | 20.80 | 1241 |
| 10 | 31.25 | 827 |
| 10 | 41.70 | 620 |
| 10 | 62.50 | 414 |
| 10 | 125.00 | 207 |
| 10 | 250.00 | 103 |
| 10 | 500.00 | 52 |
| 11 | 7.80 | 6619 |
| 11 | 10.40 | 4964 |
| 11 | 15.60 | 3309 |
| 11 | 20.80 | 2482 |
| 11 | 31.25 | 1655 |
| 11 | 41.70 | 1241 |
| 11 | 62.50 | 827 |
| 11 | 125.00 | 414 |
| 11 | 250.00 | 207 |
| 11 | 500.00 | 103 |
| 12 | 7.80 | 13238 |
| 12 | 10.40 | 9928 |
| 12 | 15.60 | 6619 |
| 12 | 20.80 | 4964 |
| 12 | 31.25 | 3309 |
| 12 | 41.70 | 2482 |
| 12 | 62.50 | 1655 |
| 12 | 125.00 | 827 |
| 12 | 250.00 | 414 |
| 12 | 500.00 | 207 |
