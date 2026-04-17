
# README

```json
board_manager:
    additional_urls:
        - http://arduino.esp8266.com/stable/package_esp8266com_index.json
        - https://dl.espressif.com/dl/package_esp32_index.json
        - https://raw.githubusercontent.com/sparkfun/Arduino_Boards/main/IDE_Board_Manager/package_sparkfun_index.json
        - https://sandeepmistry.github.io/arduino-nRF5/package_nRF5_boards_index.json
build_cache:
    compilations_before_purge: 10
    ttl: 720h0m0s
daemon:
    port: "50051"
directories:
    builtin:
        libraries: /home/jeff/.arduino15/libraries
    data: /home/jeff/.arduino15
    downloads: /home/jeff/.arduino15/staging
    user: /home/jeff/Projects/arduino
library:
    enable_unsafe_install: false
locale: en
logging:
    file: ""
    format: text
    level: info
metrics:
    addr: :9090
    enabled: true
output:
    no_color: false
sketch:
    always_export_binaries: false
updater:
    enable_notification: true
```
