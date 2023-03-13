# ocreeb12

Based off of /sbr/ocreeb-12 [https://github.com/sb-ocr/ocreeb-12]

QMK firmware for controlling with layers and individual addressable LED's

To make the UTF for the KB2040

```sh
qmk compile -kb ocreeb12 -km default
```

This will create a file called ```ocreeb12_default.uf2``` that can be dragged onto the RP-PI when in boot mode.